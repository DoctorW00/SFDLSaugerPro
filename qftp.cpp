/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtNetwork module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 3.0 requirements
** will be met: http://www.gnu.org/copyleft/gpl.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qftp.h"
#include <QAbstractSocket>
#include <QHostAddress>
#include <QDateTime>
#include <utility>

#ifndef QT_NO_FTP

// Qt 5/6 compatibility for socket error enums
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#define QFTP_HOST_NOT_FOUND QAbstractSocket::HostNotFoundError
#define QFTP_CONNECTION_REFUSED QAbstractSocket::ConnectionRefusedError
#define QFTP_SOCKET_TIMEOUT QAbstractSocket::SocketTimeoutError
#else
#define QFTP_HOST_NOT_FOUND QTcpSocket::HostNotFoundError
#define QFTP_CONNECTION_REFUSED QTcpSocket::ConnectionRefusedError
#define QFTP_SOCKET_TIMEOUT QTcpSocket::SocketTimeoutError
#endif

// Qt 5/6 compatibility for socket error signal
#if QT_VERSION >= QT_VERSION_CHECK(5, 15, 0)
#define QFTP_SOCKET_ERROR_SIGNAL &QAbstractSocket::errorOccurred
#else
#define QFTP_SOCKET_ERROR_SIGNAL QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error)
#endif

#include <QCoreApplication>
#include <QTcpSocket>
#include <QStringList>
#include <QRegularExpression>
#include <QTimer>
#include <QFileInfo>
#include <QHash>
#include <QTcpServer>
#include <QLocale>
#include <atomic>

QT_BEGIN_NAMESPACE

/*
    Decodes text received from an FTP server. UTF-8 is preferred (RFC 2640);
    if the bytes are not valid UTF-8 they are interpreted as Latin-1 so that
    legacy servers still show readable names. *invalidUtf8 reports the fallback.
*/
static QString _q_decodeFtpText(const QByteArray &ba, bool *invalidUtf8 = nullptr)
{
    const QString utf8 = QString::fromUtf8(ba);
    const bool bad = utf8.contains(QChar(QChar::ReplacementCharacter));
    if (invalidUtf8)
        *invalidUtf8 = bad;
    return bad ? QString::fromLatin1(ba) : utf8;
}

class QFtpPI;

/*
    The QFtpDTP (DTP = Data Transfer Process) controls all client side
    data transfer between the client and server.
*/
class QFtpDTP : public QObject
{
    Q_OBJECT

public:
    enum ConnectState {
        CsHostFound,
        CsConnected,
        CsClosed,
        CsHostNotFound,
        CsConnectionRefused
    };

    QFtpDTP(QFtpPI *p, QObject *parent = nullptr);

    void setData(QByteArray *ba);
    void setDevice(QIODevice *dev);
    void writeData();
    void setBytesTotal(qint64 bytes);

    bool hasError() const;
    QString errorMessage() const;
    void clearError();

    void connectToHost(const QString &host, quint16 port);
    int setupListener(const QHostAddress &address);
    void waitForConnection();

    QTcpSocket::SocketState state() const;
    qint64 bytesAvailable() const;
    qint64 read(char *data, qint64 maxlen);
    QByteArray readAll();

    void abortConnection();

    void setTimeouts(int connectMs, int transferMs);

    static bool parseDir(const QByteArray &buffer, const QString &userName, QUrlInfo *info,
                         bool *invalidUtf8 = nullptr);

public slots:
    void dataReadyRead();

signals:
    void listInfo(const QUrlInfo&);
    void readyRead();
    void dataTransferProgress(qint64, qint64);
    void connectState(int);

private slots:
    void socketConnected();
    void socketReadyRead();
    void socketError(QAbstractSocket::SocketError);
    void socketConnectionClosed();
    void socketBytesWritten(qint64);
    void setupSocket();
    void onTimeout();

private:
    void clearData();

    QTcpSocket *socket;
    QTcpServer listener;

    QFtpPI *pi;
    QString err;
    qint64 bytesDone;
    qint64 bytesTotal;
    bool callWriteData;

    union {
        QByteArray *ba;
        QIODevice *dev;
    } data;
    bool is_ba;

    QByteArray bytesFromSocket;

    QTimer timeoutTimer;
    int connectTimeoutMs = 30000;
    int transferTimeoutMs = 60000;
};

/*
    The QFtpPI (Protocol Interpreter) handles the FTP command channel.
*/
class QFtpPI : public QObject
{
    Q_OBJECT

public:
    QFtpPI(QObject *parent = nullptr);

    void connectToHost(const QString &host, quint16 port);

    bool sendCommands(const QStringList &cmds);
    bool sendCommand(const QString &cmd) { return sendCommands(QStringList(cmd)); }

    void clearPendingCommands();
    void abort();

    QString currentCommand() const { return currentCmd; }

    bool rawCommand;
    bool transferConnectionExtended;
    bool latin1Server;   // server sends non-UTF-8 text -> send commands as Latin-1

    void setTimeouts(int connectMs, int transferMs);

    QFtpDTP dtp;

signals:
    void connectState(int);
    void finished(const QString&);
    void error(int, const QString&);
    void rawFtpReply(int, const QString&);

private slots:
    void hostFound();
    void connected();
    void connectionClosed();
    void delayedCloseFinished();
    void readyRead();
    void socketError(QAbstractSocket::SocketError);
    void dtpConnectState(int);
    void onTimeout();

private:
    enum State {
        Begin,
        Idle,
        Waiting,
        Success,
        Failure
    };

    enum AbortState {
        None,
        AbortStarted,
        WaitForAbortToFinish
    };

    bool processReply();
    bool startNextCmd();

    QTcpSocket commandSocket;
    QString replyText;
    char replyCode[3];
    State state;
    AbortState abortState;
    QStringList pendingCommands;
    QString currentCmd;

    bool waitForDtpToConnect;
    bool waitForDtpToClose;

    QByteArray bytesFromSocket;

    QTimer timeoutTimer;
    int connectTimeoutMs = 30000;
    int transferTimeoutMs = 60000;

    friend class QFtpDTP;
};

/*
    Represents a single FTP command in the queue.
*/
class QFtpCommand
{
public:
    QFtpCommand(QFtp::Command cmd, QStringList raw, const QByteArray &ba);
    QFtpCommand(QFtp::Command cmd, QStringList raw, QIODevice *dev = nullptr);
    ~QFtpCommand();

    int id;
    QFtp::Command command;
    QStringList rawCmds;

    union {
        QByteArray *ba;
        QIODevice *dev;
    } data;
    bool is_ba;
    qint64 restartOffset = 0;   // > 0: resume (REST) at this byte offset

private:
    static std::atomic<int> idCounter;
};

std::atomic<int> QFtpCommand::idCounter{1};

QFtpCommand::QFtpCommand(QFtp::Command cmd, QStringList raw, const QByteArray &ba)
    : command(cmd), rawCmds(std::move(raw)), is_ba(true)
{
    id = idCounter.fetch_add(1);
    data.ba = new QByteArray(ba);
}

QFtpCommand::QFtpCommand(QFtp::Command cmd, QStringList raw, QIODevice *dev)
    : command(cmd), rawCmds(std::move(raw)), is_ba(false)
{
    id = idCounter.fetch_add(1);
    data.dev = dev;
}

QFtpCommand::~QFtpCommand()
{
    if (is_ba)
        delete data.ba;
}

/*
    QFtpDTP implementation
*/
QFtpDTP::QFtpDTP(QFtpPI *p, QObject *parent) :
    QObject(parent),
    socket(nullptr),
    listener(this),
    pi(p),
    callWriteData(false)
{
    clearData();
    listener.setObjectName(QStringLiteral("QFtpDTP active state server"));
    connect(&listener, &QTcpServer::newConnection, this, &QFtpDTP::setupSocket);

    timeoutTimer.setSingleShot(true);
    connect(&timeoutTimer, &QTimer::timeout, this, &QFtpDTP::onTimeout);
}

void QFtpDTP::setData(QByteArray *ba)
{
    is_ba = true;
    data.ba = ba;
}

void QFtpDTP::setDevice(QIODevice *dev)
{
    is_ba = false;
    data.dev = dev;
}

void QFtpDTP::setBytesTotal(qint64 bytes)
{
    bytesTotal = bytes;
    bytesDone = 0;
    emit dataTransferProgress(bytesDone, bytesTotal);
}

void QFtpDTP::connectToHost(const QString &host, quint16 port)
{
    err.clear();
    bytesFromSocket.clear();

    if (socket) {
        delete socket;
        socket = nullptr;
    }
    socket = new QTcpSocket(this);
#ifndef QT_NO_BEARERMANAGEMENT
    socket->setProperty("_q_networksession", property("_q_networksession"));
#endif
    socket->setObjectName(QStringLiteral("QFtpDTP Passive state socket"));
    connect(socket, &QTcpSocket::connected, this, &QFtpDTP::socketConnected);
    connect(socket, &QTcpSocket::readyRead, this, &QFtpDTP::socketReadyRead);
    connect(socket, QFTP_SOCKET_ERROR_SIGNAL, this, &QFtpDTP::socketError);
    connect(socket, &QTcpSocket::disconnected, this, &QFtpDTP::socketConnectionClosed);
    connect(socket, &QTcpSocket::bytesWritten, this, &QFtpDTP::socketBytesWritten);
    socket->connectToHost(host, port);

    if (connectTimeoutMs > 0)
        timeoutTimer.start(connectTimeoutMs);
}

int QFtpDTP::setupListener(const QHostAddress &address)
{
#ifndef QT_NO_BEARERMANAGEMENT
    listener.setProperty("_q_networksession", property("_q_networksession"));
#endif
    if (!listener.isListening() && !listener.listen(address, 0))
        return -1;
    return listener.serverPort();
}

void QFtpDTP::waitForConnection()
{
    if (listener.isListening())
        listener.waitForNewConnection();
}

QTcpSocket::SocketState QFtpDTP::state() const
{
    return socket ? socket->state() : QTcpSocket::UnconnectedState;
}

qint64 QFtpDTP::bytesAvailable() const
{
    if (!socket || socket->state() != QTcpSocket::ConnectedState)
        return bytesFromSocket.size();
    return socket->bytesAvailable();
}

qint64 QFtpDTP::read(char *data, qint64 maxlen)
{
    qint64 read;
    if (socket && socket->state() == QTcpSocket::ConnectedState) {
        read = socket->read(data, maxlen);
    } else {
        read = qMin(maxlen, static_cast<qint64>(bytesFromSocket.size()));
        memcpy(data, bytesFromSocket.data(), read);
        bytesFromSocket.remove(0, read);
    }

    bytesDone += read;
    return read;
}

QByteArray QFtpDTP::readAll()
{
    QByteArray tmp;
    if (socket && socket->state() == QTcpSocket::ConnectedState) {
        tmp = socket->readAll();
        bytesDone += tmp.size();
    } else {
        tmp = bytesFromSocket;
        bytesFromSocket.clear();
    }
    return tmp;
}

void QFtpDTP::writeData()
{
    if (!socket)
        return;

    if (is_ba) {
        if (data.ba->size() == 0)
            emit dataTransferProgress(0, bytesTotal);
        else
            socket->write(data.ba->data(), data.ba->size());

        socket->close();
        clearData();
    } else if (data.dev) {
        callWriteData = false;
        const qint64 blockSize = 16 * 1024;
        char buf[16 * 1024];
        qint64 read = data.dev->read(buf, blockSize);

        if (read > 0) {
            socket->write(buf, read);
        } else if (read == -1 || (!data.dev->isSequential() && data.dev->atEnd())) {
            if (bytesDone == 0 && socket->bytesToWrite() == 0)
                emit dataTransferProgress(0, bytesTotal);
            socket->close();
            clearData();
        }

        callWriteData = data.dev != nullptr;
    }
}

void QFtpDTP::dataReadyRead()
{
    writeData();
}

inline bool QFtpDTP::hasError() const { return !err.isNull(); }
inline QString QFtpDTP::errorMessage() const { return err; }
inline void QFtpDTP::clearError() { err.clear(); }

void QFtpDTP::abortConnection()
{
    timeoutTimer.stop();
    callWriteData = false;
    clearData();
    if (socket)
        socket->abort();
}

static void _q_fixupDateTime(QDateTime *dateTime)
{
    const int futureTolerance = 86400;
    if (dateTime->secsTo(QDateTime::currentDateTime()) < -futureTolerance) {
        const QDate d = dateTime->date();
        QDate previous(d.year() - 1, d.month(), d.day());
        if (!previous.isValid())
            previous = QDate(d.year() - 1, d.month(), 28);
        dateTime->setDate(previous);
    }
}

static void _q_parseUnixDir(const QStringList &tokens, const QString &userName, QUrlInfo *info)
{
    if (tokens.size() != 8)
        return;

    char first = tokens.at(1).at(0).toLatin1();
    if (first == 'd') {
        info->setDir(true);
        info->setFile(false);
        info->setSymLink(false);
    } else if (first == '-') {
        info->setDir(false);
        info->setFile(true);
        info->setSymLink(false);
    } else if (first == 'l') {
        info->setDir(true);
        info->setFile(false);
        info->setSymLink(true);
    }

    QString name = tokens.at(7);
    if (info->isSymLink()) {
        int linkPos = name.indexOf(QStringLiteral(" ->"));
        if (linkPos != -1)
            name.resize(linkPos);
    }
    info->setName(name);

    info->setOwner(tokens.at(3));
    info->setGroup(tokens.at(4));
    info->setSize(tokens.at(5).toLongLong());

    QStringList formats;
    formats << QStringLiteral("MMM dd  yyyy") << QStringLiteral("MMM dd hh:mm")
            << QStringLiteral("MMM  d  yyyy") << QStringLiteral("MMM  d hh:mm")
            << QStringLiteral("MMM  d yyyy") << QStringLiteral("MMM dd yyyy");

    QString dateString = tokens.at(6);
    dateString[0] = dateString[0].toUpper();

    QDateTime dateTime;
    int n = 0;
#ifndef QT_NO_DATESTRING
    do {
        dateTime = QLocale::c().toDateTime(dateString, formats.at(n++));
    } while (n < formats.size() && !dateTime.isValid());
#endif

    if (n == 2 || n == 4) {
        dateTime.setDate(QDate(QDate::currentDate().year(),
                               dateTime.date().month(),
                               dateTime.date().day()));
        _q_fixupDateTime(&dateTime);
    }
    if (dateTime.isValid())
        info->setLastModified(dateTime);

    int permissions = 0;
    QString p = tokens.at(2);
    permissions |= (p[0] == 'r' ? QUrlInfo::ReadOwner : 0);
    permissions |= (p[1] == 'w' ? QUrlInfo::WriteOwner : 0);
    permissions |= (p[2] == 'x' ? QUrlInfo::ExeOwner : 0);
    permissions |= (p[3] == 'r' ? QUrlInfo::ReadGroup : 0);
    permissions |= (p[4] == 'w' ? QUrlInfo::WriteGroup : 0);
    permissions |= (p[5] == 'x' ? QUrlInfo::ExeGroup : 0);
    permissions |= (p[6] == 'r' ? QUrlInfo::ReadOther : 0);
    permissions |= (p[7] == 'w' ? QUrlInfo::WriteOther : 0);
    permissions |= (p[8] == 'x' ? QUrlInfo::ExeOther : 0);
    info->setPermissions(permissions);

    bool isOwner = info->owner() == userName;
    info->setReadable((permissions & QUrlInfo::ReadOther) || ((permissions & QUrlInfo::ReadOwner) && isOwner));
    info->setWritable((permissions & QUrlInfo::WriteOther) || ((permissions & QUrlInfo::WriteOwner) && isOwner));
}

static void _q_parseDosDir(const QStringList &tokens, const QString &userName, QUrlInfo *info)
{
    if (tokens.size() != 4)
        return;

    Q_UNUSED(userName);

    QString name = tokens.at(3);
    info->setName(name);
    info->setSymLink(name.toLower().endsWith(QStringLiteral(".lnk")));

    if (tokens.at(2) == QStringLiteral("<DIR>")) {
        info->setFile(false);
        info->setDir(true);
    } else {
        info->setFile(true);
        info->setDir(false);
        info->setSize(tokens.at(2).toLongLong());
    }

    int permissions = QUrlInfo::ReadOwner | QUrlInfo::WriteOwner
                      | QUrlInfo::ReadGroup | QUrlInfo::WriteGroup
                      | QUrlInfo::ReadOther | QUrlInfo::WriteOther;
    QString ext;
    int extIndex = name.lastIndexOf('.');
    if (extIndex != -1)
        ext = name.mid(extIndex + 1);
    if (ext == "exe" || ext == "bat" || ext == "com")
        permissions |= QUrlInfo::ExeOwner | QUrlInfo::ExeGroup | QUrlInfo::ExeOther;
    info->setPermissions(permissions);

    info->setReadable(true);
    info->setWritable(info->isFile());

    QDateTime dateTime;
#ifndef QT_NO_DATESTRING
    dateTime = QLocale::c().toDateTime(tokens.at(1), QStringLiteral("MM-dd-yy  hh:mmAP"));
    if (dateTime.date().year() < 1971) {
        dateTime.setDate(QDate(dateTime.date().year() + 100,
                               dateTime.date().month(),
                               dateTime.date().day()));
    }
#endif

    info->setLastModified(dateTime);
}

bool QFtpDTP::parseDir(const QByteArray &buffer, const QString &userName, QUrlInfo *info,
                       bool *invalidUtf8)
{
    if (invalidUtf8)
        *invalidUtf8 = false;
    if (buffer.isEmpty())
        return false;

    QString bufferStr = _q_decodeFtpText(buffer, invalidUtf8).trimmed();

    // Unix style FTP servers - using QRegularExpression for Qt 5/6
    static const QRegularExpression unixPattern(
        "^([\\-dl])([a-zA-Z\\-]{9,9})\\s+\\d+\\s+(\\S*)\\s+"
        "(\\S*)\\s+(\\d+)\\s+(\\S+\\s+\\S+\\s+\\S+)\\s+(\\S.*)");
    QRegularExpressionMatch unixMatch = unixPattern.match(bufferStr);
    if (unixMatch.hasMatch()) {
        _q_parseUnixDir(unixMatch.capturedTexts(), userName, info);
        return true;
    }

    // DOS style FTP servers
    static const QRegularExpression dosPattern(
        "^(\\d\\d-\\d\\d-\\d\\d\\d?\\d?\\ \\ \\d\\d:\\d\\d[AP]M)\\s+"
        "(<DIR>|\\d+)\\s+(\\S.*)$");
    QRegularExpressionMatch dosMatch = dosPattern.match(bufferStr);
    if (dosMatch.hasMatch()) {
        _q_parseDosDir(dosMatch.capturedTexts(), userName, info);
        return true;
    }

    return false;
}

void QFtpDTP::socketConnected()
{
    if (transferTimeoutMs > 0)
        timeoutTimer.start(transferTimeoutMs);
    else
        timeoutTimer.stop();

    bytesDone = 0;
    emit connectState(QFtpDTP::CsConnected);
}

void QFtpDTP::socketReadyRead()
{
    if (!socket)
        return;

    if (transferTimeoutMs > 0)
        timeoutTimer.start(transferTimeoutMs);

    if (pi->currentCommand().isEmpty()) {
        socket->close();
        emit connectState(QFtpDTP::CsClosed);
        return;
    }

    if (pi->abortState == QFtpPI::AbortStarted) {
        socket->readAll();
        return;
    }

    if (pi->currentCommand().startsWith(QStringLiteral("LIST"))) {
        while (socket->canReadLine()) {
            QUrlInfo i;
            QByteArray line = socket->readLine();
            bool invalidUtf8 = false;
            if (parseDir(line, QString(), &i, &invalidUtf8)) {
                emit listInfo(i);
            } else if (line.endsWith("No such file or directory\r\n")) {
                err = _q_decodeFtpText(line);
            }
            if (invalidUtf8)
                pi->latin1Server = true;
        }
    } else {
        if (!is_ba && data.dev) {
            do {
                QByteArray ba;
                ba.resize(socket->bytesAvailable());
                qint64 bytesRead = socket->read(ba.data(), ba.size());
                if (bytesRead < 0)
                    return;
                ba.resize(bytesRead);
                bytesDone += bytesRead;

                if (data.dev) {
                    const qint64 written = data.dev->write(ba);
                    if (written != ba.size()) {
                        // e.g. disk full: do not silently lose data, abort the transfer
                        err = QStringLiteral("Writing received data to the local device failed");
                        socket->abort();
                        return;
                    }
                }
                emit dataTransferProgress(bytesDone, bytesTotal);
            } while (socket->bytesAvailable());
        } else {
            emit dataTransferProgress(bytesDone + socket->bytesAvailable(), bytesTotal);
            emit readyRead();
        }
    }
}

void QFtpDTP::socketError(QAbstractSocket::SocketError e)
{
    timeoutTimer.stop();
    if (e == QFTP_HOST_NOT_FOUND) {
        emit connectState(QFtpDTP::CsHostNotFound);
    } else if (e == QFTP_CONNECTION_REFUSED) {
        emit connectState(QFtpDTP::CsConnectionRefused);
    }
}

void QFtpDTP::socketConnectionClosed()
{
    timeoutTimer.stop();
    if (!is_ba && data.dev) {
        clearData();
    }

    bytesFromSocket = socket->readAll();
    emit connectState(QFtpDTP::CsClosed);
}

void QFtpDTP::socketBytesWritten(qint64 bytes)
{
    if (transferTimeoutMs > 0)
        timeoutTimer.start(transferTimeoutMs);

    bytesDone += bytes;
    emit dataTransferProgress(bytesDone, bytesTotal);
    if (callWriteData)
        writeData();
}

void QFtpDTP::setupSocket()
{
    err.clear();
    socket = listener.nextPendingConnection();
    socket->setObjectName(QStringLiteral("QFtpDTP Active state socket"));
    connect(socket, &QTcpSocket::connected, this, &QFtpDTP::socketConnected);
    connect(socket, &QTcpSocket::readyRead, this, &QFtpDTP::socketReadyRead);
    connect(socket, QFTP_SOCKET_ERROR_SIGNAL, this, &QFtpDTP::socketError);
    connect(socket, &QTcpSocket::disconnected, this, &QFtpDTP::socketConnectionClosed);
    connect(socket, &QTcpSocket::bytesWritten, this, &QFtpDTP::socketBytesWritten);

    if (transferTimeoutMs > 0)
        timeoutTimer.start(transferTimeoutMs);
    else
        timeoutTimer.stop();

    listener.close();
}

void QFtpDTP::clearData()
{
    is_ba = false;
    data.dev = nullptr;
}

void QFtpDTP::setTimeouts(int connectMs, int transferMs)
{
    connectTimeoutMs = connectMs;
    transferTimeoutMs = transferMs;
    if (connectMs <= 0 && transferMs <= 0)
        timeoutTimer.stop();
}

void QFtpDTP::onTimeout()
{
    err = tr("Data transfer timed out");
    abortConnection();
    emit connectState(CsClosed);
}

/*
    QFtpPI implementation
*/
QFtpPI::QFtpPI(QObject *parent) :
    QObject(parent),
    rawCommand(false),
    transferConnectionExtended(true),
    latin1Server(false),
    dtp(this),
    state(Begin), abortState(None),
    currentCmd(QString()),
    waitForDtpToConnect(false),
    waitForDtpToClose(false)
{
    timeoutTimer.setSingleShot(true);
    connect(&timeoutTimer, &QTimer::timeout, this, &QFtpPI::onTimeout);

    commandSocket.setObjectName(QStringLiteral("QFtpPI_socket"));
    connect(&commandSocket, &QTcpSocket::hostFound, this, &QFtpPI::hostFound);
    connect(&commandSocket, &QTcpSocket::connected, this, &QFtpPI::connected);
    connect(&commandSocket, &QTcpSocket::disconnected, this, &QFtpPI::connectionClosed);
    connect(&commandSocket, &QTcpSocket::readyRead, this, &QFtpPI::readyRead);
    connect(&commandSocket, QFTP_SOCKET_ERROR_SIGNAL, this, &QFtpPI::socketError);
    connect(&dtp, &QFtpDTP::connectState, this, &QFtpPI::dtpConnectState);
}

void QFtpPI::setTimeouts(int connectMs, int transferMs)
{
    connectTimeoutMs = connectMs;
    transferTimeoutMs = transferMs;
    if (connectMs <= 0 && transferMs <= 0)
        timeoutTimer.stop();
    dtp.setTimeouts(connectMs, transferMs);
}

void QFtpPI::onTimeout()
{
    commandSocket.abort();
    dtp.abortConnection();
    emit connectState(QFtp::Unconnected);
    emit error(QFtp::Timeout, QObject::tr("Connection timed out"));
}

void QFtpPI::connectToHost(const QString &host, quint16 port)
{
    latin1Server = false;
    emit connectState(QFtp::HostLookup);
#ifndef QT_NO_BEARERMANAGEMENT
    commandSocket.setProperty("_q_networksession", property("_q_networksession"));
    dtp.setProperty("_q_networksession", property("_q_networksession"));
#endif
    commandSocket.connectToHost(host, port);

    if (connectTimeoutMs > 0)
        timeoutTimer.start(connectTimeoutMs);
}

bool QFtpPI::sendCommands(const QStringList &cmds)
{
    if (!pendingCommands.isEmpty())
        return false;

    if (commandSocket.state() != QTcpSocket::ConnectedState || state != Idle) {
        emit error(QFtp::NotConnected, QObject::tr("Not connected"));
        return true;
    }

    pendingCommands = cmds;
    startNextCmd();
    return true;
}

void QFtpPI::clearPendingCommands()
{
    timeoutTimer.stop();
    pendingCommands.clear();
    dtp.abortConnection();
    currentCmd.clear();
    state = Idle;
}

void QFtpPI::abort()
{
    pendingCommands.clear();

    if (abortState != None)
        return;

    abortState = AbortStarted;
    commandSocket.write("ABOR\r\n", 6);

    if (currentCmd.startsWith(QStringLiteral("STOR ")))
        dtp.abortConnection();
}

void QFtpPI::hostFound()
{
    emit connectState(QFtp::Connecting);
}

void QFtpPI::connected()
{
    timeoutTimer.stop();
    state = Begin;
    commandSocket.setSocketOption(QAbstractSocket::LowDelayOption, 1);
    emit connectState(QFtp::Connected);
}

void QFtpPI::connectionClosed()
{
    timeoutTimer.stop();
    commandSocket.close();
    emit connectState(QFtp::Unconnected);
}

void QFtpPI::delayedCloseFinished()
{
    emit connectState(QFtp::Unconnected);
}

void QFtpPI::socketError(QAbstractSocket::SocketError e)
{
    timeoutTimer.stop();
    if (e == QFTP_HOST_NOT_FOUND) {
        emit connectState(QFtp::Unconnected);
        emit error(QFtp::HostNotFound,
                   QObject::tr("Host %1 not found").arg(commandSocket.peerName()));
    } else if (e == QFTP_CONNECTION_REFUSED) {
        emit connectState(QFtp::Unconnected);
        emit error(QFtp::ConnectionRefused,
                   QObject::tr("Connection refused to host %1").arg(commandSocket.peerName()));
    } else if (e == QFTP_SOCKET_TIMEOUT) {
        emit connectState(QFtp::Unconnected);
        emit error(QFtp::Timeout,
                   QObject::tr("Connection timed out to host %1").arg(commandSocket.peerName()));
    }
}

void QFtpPI::readyRead()
{
    if (waitForDtpToClose)
        return;

    auto readReplyLine = [this]() -> QString {
        bool invalidUtf8 = false;
        const QString s = _q_decodeFtpText(commandSocket.readLine(), &invalidUtf8);
        if (invalidUtf8)
            latin1Server = true;
        return s;
    };

    while (commandSocket.canReadLine()) {
        QString line = readReplyLine();
        if (replyText.isEmpty()) {
            if (line.length() < 3)
                return;
            const int lowerLimit[3] = {1,0,0};
            const int upperLimit[3] = {5,5,9};
            for (int i=0; i<3; i++) {
                replyCode[i] = line[i].digitValue();
                if (replyCode[i]<lowerLimit[i] || replyCode[i]>upperLimit[i])
                    return;
            }
        }
        // Qt6: QString::operator[] must not be used to grow a string
        QString endOfMultiLine;
        for (int i = 0; i < 3; ++i)
            endOfMultiLine += QLatin1Char(static_cast<char>('0' + replyCode[i]));
        endOfMultiLine += QLatin1Char(' ');
        QString lineCont(endOfMultiLine);
        lineCont[3] = QLatin1Char('-');
        QString lineLeft4 = line.left(4);

        while (lineLeft4 != endOfMultiLine) {
            if (lineLeft4 == lineCont)
                replyText += line.mid(4);
            else
                replyText += line;
            if (!commandSocket.canReadLine())
                return;
            line = readReplyLine();
            lineLeft4 = line.left(4);
        }
        replyText += line.mid(4);
        if (replyText.endsWith("\r\n"))
            replyText.chop(2);

        if (processReply())
            replyText.clear();
    }
}

bool QFtpPI::processReply()
{
    int replyCodeInt = 100*replyCode[0] + 10*replyCode[1] + replyCode[2];

    // Process 226 replies only when data connection is really closed
    if (replyCodeInt == 226 || (replyCodeInt == 250 && currentCmd.startsWith(QStringLiteral("RETR")))) {
        if (dtp.state() != QTcpSocket::UnconnectedState) {
            waitForDtpToClose = true;
            return false;
        }
    }

    switch (abortState) {
    case AbortStarted:
        abortState = WaitForAbortToFinish;
        break;
    case WaitForAbortToFinish:
        abortState = None;
        return true;
    default:
        break;
    }

    // State transition table based on RFC 959
    static const State table[5] = {
        Waiting, Success, Idle, Failure, Failure
    };
    switch (state) {
    case Begin:
        if (replyCode[0] == 1) {
            return true;
        } else if (replyCode[0] == 2) {
            state = Idle;
            emit finished(QObject::tr("Connected to host %1").arg(commandSocket.peerName()));
            break;
        }
        return true;
    case Waiting:
        if (static_cast<signed char>(replyCode[0]) < 0 || replyCode[0] > 5)
            state = Failure;
        else if (replyCodeInt == 202)
            state = Failure;
        else
            state = table[replyCode[0] - 1];
        break;
    default:
        return true;
    }

    // Special handling for specific reply codes
    emit rawFtpReply(replyCodeInt, replyText);
    if (rawCommand) {
        rawCommand = false;
    } else if (replyCodeInt == 227) {
        // Passive mode response: parse port and use command socket's peer IP (prevents FTP bounce & NAT issues)
        QRegularExpression addrPortPattern("(\\d+),(\\d+),(\\d+),(\\d+),(\\d+),(\\d+)");
        QRegularExpressionMatch match = addrPortPattern.match(replyText);
        if (match.hasMatch()) {
            quint16 port = (match.captured(5).toUInt() << 8) + match.captured(6).toUInt();
            if (port > 0) {
                waitForDtpToConnect = true;
                dtp.connectToHost(commandSocket.peerAddress().toString(), port);
            }
        }
    } else if (replyCodeInt == 229) {
        // Extended passive mode response
        int portPos = replyText.indexOf('(');
        if (portPos != -1 && portPos + 1 < replyText.length()) {
            ++portPos;
            QChar delimiter = replyText.at(portPos);
            QStringList epsvParameters = replyText.mid(portPos).split(delimiter);
            if (epsvParameters.size() > 3) {
                bool ok = false;
                quint16 port = epsvParameters.at(3).toUShort(&ok);
                if (ok && port > 0) {
                    waitForDtpToConnect = true;
                    dtp.connectToHost(commandSocket.peerAddress().toString(), port);
                }
            }
        }
    } else if (replyCodeInt == 230) {
        // User logged in - skip PASS command if already authenticated
        if (currentCmd.startsWith(QStringLiteral("USER ")) && pendingCommands.count() > 0 &&
            pendingCommands.first().startsWith(QStringLiteral("PASS "))) {
            pendingCommands.pop_front();
        }
        emit connectState(QFtp::LoggedIn);
    } else if (replyCodeInt == 213) {
        // File size response
        if (currentCmd.startsWith(QStringLiteral("SIZE ")))
            dtp.setBytesTotal(replyText.simplified().toLongLong());
    } else if (replyCode[0] == 1 && currentCmd.startsWith(QStringLiteral("STOR "))) {
        dtp.waitForConnection();
        dtp.writeData();
    }

    // React to new state
    switch (state) {
    case Begin:
        break;
    case Success:
        state = Idle;
        Q_FALLTHROUGH();
    case Idle:
        if (dtp.hasError()) {
            const QFtp::Error errCode = dtp.errorMessage().contains(QStringLiteral("timed out"), Qt::CaseInsensitive)
                                            ? QFtp::Timeout
                                            : QFtp::UnknownError;
            emit error(QFtp::UnknownError, dtp.errorMessage());
            dtp.clearError();
        }
        startNextCmd();
        break;
    case Waiting:
        break;
    case Failure:
        // Fall back from EPSV/EPRT to PASV/PORT on failure
        if (currentCmd.startsWith(QStringLiteral("EPSV"))) {
            transferConnectionExtended = false;
            pendingCommands.prepend(QStringLiteral("PASV\r\n"));
        } else if (currentCmd.startsWith(QStringLiteral("EPRT"))) {
            transferConnectionExtended = false;
            pendingCommands.prepend(QStringLiteral("PORT\r\n"));
        } else {
            emit error(QFtp::UnknownError, dtp.hasError() ? dtp.errorMessage() : replyText);
            dtp.clearError();
        }
        if (state != Waiting) {
            state = Idle;
            startNextCmd();
        }
        break;
    }

    return true;
}

bool QFtpPI::startNextCmd()
{
    if (waitForDtpToConnect)
        return true;

    if (pendingCommands.isEmpty()) {
        currentCmd.clear();
        emit finished(replyText);
        return false;
    }
    currentCmd = pendingCommands.first();

    // Handle PORT/PASV commands with IPv4/IPv6 support
    QHostAddress address = commandSocket.localAddress();
    if (currentCmd.startsWith(QStringLiteral("PORT"))) {
        if ((address.protocol() == QTcpSocket::IPv6Protocol) && transferConnectionExtended) {
            int port = dtp.setupListener(address);
            currentCmd = QStringLiteral("EPRT |");
            currentCmd += (address.protocol() == QTcpSocket::IPv4Protocol) ? '1' : '2';
            currentCmd += '|' + address.toString() + '|' + QString::number(port) + '|';
        } else if (address.protocol() == QTcpSocket::IPv4Protocol) {
            int port = dtp.setupListener(address);
            QString portArg;
            quint32 ip = address.toIPv4Address();
            portArg += QString::number((ip & 0xff000000) >> 24);
            portArg += ',' + QString::number((ip & 0xff0000) >> 16);
            portArg += ',' + QString::number((ip & 0xff00) >> 8);
            portArg += ',' + QString::number(ip & 0xff);
            portArg += ',' + QString::number((port & 0xff00) >> 8);
            portArg += ',' + QString::number(port & 0xff);

            currentCmd = QStringLiteral("PORT ") + portArg;
        } else {
            return false;
        }
        currentCmd += "\r\n";
    } else if (currentCmd.startsWith(QStringLiteral("PASV"))) {
        if ((address.protocol() == QTcpSocket::IPv6Protocol) && transferConnectionExtended)
            currentCmd = QStringLiteral("EPSV\r\n");
    }

    pendingCommands.pop_front();
    state = Waiting;
    commandSocket.write(latin1Server ? currentCmd.toLatin1() : currentCmd.toUtf8());
    return true;
}

void QFtpPI::dtpConnectState(int s)
{
    switch (s) {
    case QFtpDTP::CsClosed:
        if (waitForDtpToClose) {
            if (processReply())
                replyText.clear();
            else
                return;
        }
        waitForDtpToClose = false;
        readyRead();
        return;
    case QFtpDTP::CsConnected:
        waitForDtpToConnect = false;
        startNextCmd();
        return;
    case QFtpDTP::CsHostNotFound:
    case QFtpDTP::CsConnectionRefused:
        emit error(QFtp::ConnectionRefused,
                   QObject::tr("Connection refused for data connection"));
        startNextCmd();
        return;
    default:
        return;
    }
}

/*
    QFtpPrivate - main implementation class
*/
class QFtpPrivate
{
    Q_DECLARE_PUBLIC(QFtp)
public:
    inline QFtpPrivate(QFtp *owner) : close_waitForStateChange(false), state(QFtp::Unconnected),
        transferMode(QFtp::Passive), error(QFtp::NoError), q_ptr(owner),
        connectTimeout(30000), transferTimeout(60000), lastResponseCode(0) { }

    ~QFtpPrivate() { while (!pending.isEmpty()) delete pending.takeFirst(); }

    void _q_startNextCommand();
    void _q_piFinished(const QString&);
    void _q_piError(int, const QString&);
    void _q_piConnectState(int);
    void _q_piFtpReply(int, const QString&);

    int addCommand(QFtpCommand *cmd);

    QFtpPI pi;
    QList<QFtpCommand *> pending;
    bool close_waitForStateChange;
    QFtp::State state;
    QFtp::TransferMode transferMode;
    QFtp::Error error;
    QString errorString;

    QString host;
    quint16 port = 0;
    QString proxyHost;
    quint16 proxyPort = 0;
    QFtp *q_ptr;

    // Modern features: timeouts and response tracking
    int connectTimeout;
    int transferTimeout;
    int lastResponseCode;
    QString lastResponseText;
};

int QFtpPrivate::addCommand(QFtpCommand *cmd)
{
    pending.append(cmd);

    if (pending.count() == 1) {
        QTimer::singleShot(0, q_func(), [this]() { _q_startNextCommand(); });
    }
    return cmd->id;
}

/*
    Helper to prevent FTP command injection via CR/LF
*/
static QString _q_sanitizeFtpArg(QString arg)
{
    arg.remove(QLatin1Char('\r'));
    arg.remove(QLatin1Char('\n'));
    return arg;
}

/*
    QFtp public API implementation
*/
QFtp::QFtp(QObject *parent)
    : QObject(parent), d(new QFtpPrivate(this))
{
    d->errorString = tr("Unknown error");

    connect(&d->pi, &QFtpPI::connectState, this, [this](int state) {
        d->_q_piConnectState(state);
    });
    connect(&d->pi, &QFtpPI::finished, this, [this](const QString& text) {
        d->_q_piFinished(text);
    });
    connect(&d->pi, &QFtpPI::error, this, [this](int code, const QString& text) {
        d->_q_piError(code, text);
    });
    connect(&d->pi, &QFtpPI::rawFtpReply, this, [this](int code, const QString& text) {
        d->_q_piFtpReply(code, text);
    });

    connect(&d->pi.dtp, &QFtpDTP::readyRead, this, &QFtp::readyRead);
    connect(&d->pi.dtp, &QFtpDTP::dataTransferProgress, this, &QFtp::dataTransferProgress);
    connect(&d->pi.dtp, &QFtpDTP::listInfo, this, &QFtp::listInfo);
}

void QFtp::setConnectTimeout(int milliseconds)
{
    d->connectTimeout = milliseconds;
    d->pi.setTimeouts(d->connectTimeout, d->transferTimeout);
}

int QFtp::connectTimeout() const
{
    return d->connectTimeout;
}

void QFtp::setTransferTimeout(int milliseconds)
{
    d->transferTimeout = milliseconds;
    d->pi.setTimeouts(d->connectTimeout, d->transferTimeout);
}

int QFtp::transferTimeout() const
{
    return d->transferTimeout;
}

int QFtp::lastResponseCode() const
{
    return d->lastResponseCode;
}

QString QFtp::lastResponseText() const
{
    return d->lastResponseText;
}

int QFtp::connectToHost(const QString &host, quint16 port)
{
    QStringList cmds;
    cmds << _q_sanitizeFtpArg(host);
    cmds << QString::number((uint)port);
    int id = d->addCommand(new QFtpCommand(ConnectToHost, cmds));
    d->pi.transferConnectionExtended = true;
    return id;
}

int QFtp::login(const QString &user, const QString &password)
{
    QStringList cmds;
    cmds << (QStringLiteral("USER ") + (user.isNull() ? QStringLiteral("anonymous") : _q_sanitizeFtpArg(user)) + "\r\n");
    cmds << (QStringLiteral("PASS ") + (password.isNull() ? QStringLiteral("anonymous@") : _q_sanitizeFtpArg(password)) + "\r\n");
    return d->addCommand(new QFtpCommand(Login, cmds));
}

int QFtp::close()
{
    return d->addCommand(new QFtpCommand(Close, QStringList(QStringLiteral("QUIT\r\n"))));
}

int QFtp::setTransferMode(TransferMode mode)
{
    int id = d->addCommand(new QFtpCommand(SetTransferMode, QStringList()));
    d->pi.transferConnectionExtended = true;
    d->transferMode = mode;
    return id;
}

int QFtp::setProxy(const QString &host, quint16 port)
{
    QStringList args;
    args << _q_sanitizeFtpArg(host) << QString::number(port);
    return d->addCommand(new QFtpCommand(SetProxy, args));
}

int QFtp::list(const QString &dir)
{
    QStringList cmds;
    cmds << QStringLiteral("TYPE A\r\n");
    cmds << (d->transferMode == Passive ? QStringLiteral("PASV\r\n") : QStringLiteral("PORT\r\n"));
    if (dir.isEmpty())
        cmds << QStringLiteral("LIST\r\n");
    else
        cmds << (QStringLiteral("LIST ") + _q_sanitizeFtpArg(dir) + "\r\n");
    return d->addCommand(new QFtpCommand(List, cmds));
}

int QFtp::cd(const QString &dir)
{
    return d->addCommand(new QFtpCommand(Cd, QStringList(QStringLiteral("CWD ") + _q_sanitizeFtpArg(dir) + "\r\n")));
}

int QFtp::get(const QString &file, QIODevice *dev, TransferType type, qint64 restartOffset)
{
    QString safeFile = _q_sanitizeFtpArg(file);
    QStringList cmds;
    if (type == Binary)
        cmds << QStringLiteral("TYPE I\r\n");
    else
        cmds << QStringLiteral("TYPE A\r\n");
    cmds << (QStringLiteral("SIZE ") + safeFile + "\r\n");
    cmds << (d->transferMode == Passive ? QStringLiteral("PASV\r\n") : QStringLiteral("PORT\r\n"));
    if (restartOffset > 0)
        cmds << (QStringLiteral("REST ") + QString::number(restartOffset) + "\r\n");
    cmds << (QStringLiteral("RETR ") + safeFile + "\r\n");
    QFtpCommand *cmd = new QFtpCommand(Get, cmds, dev);
    cmd->restartOffset = qMax<qint64>(0, restartOffset);
    return d->addCommand(cmd);
}

int QFtp::put(const QByteArray &data, const QString &file, TransferType type, qint64 restartOffset)
{
    // For in-memory data resuming simply means sending the remaining part
    const qint64 offset = (restartOffset > 0 && restartOffset <= data.size()) ? restartOffset : 0;
    const QByteArray payload = offset > 0 ? data.mid(static_cast<int>(offset)) : data;
    QStringList cmds;
    if (type == Binary)
        cmds << QStringLiteral("TYPE I\r\n");
    else
        cmds << QStringLiteral("TYPE A\r\n");
    cmds << (d->transferMode == Passive ? QStringLiteral("PASV\r\n") : QStringLiteral("PORT\r\n"));
    cmds << (QStringLiteral("ALLO ") + QString::number(payload.size()) + "\r\n");
    if (offset > 0)
        cmds << (QStringLiteral("REST ") + QString::number(offset) + "\r\n");
    cmds << (QStringLiteral("STOR ") + _q_sanitizeFtpArg(file) + "\r\n");
    return d->addCommand(new QFtpCommand(Put, cmds, payload));
}

int QFtp::put(QIODevice *dev, const QString &file, TransferType type, qint64 restartOffset)
{
    // Resuming needs a seekable device
    const qint64 offset = (restartOffset > 0 && dev && !dev->isSequential()) ? restartOffset : 0;
    QStringList cmds;
    if (type == Binary)
        cmds << QStringLiteral("TYPE I\r\n");
    else
        cmds << QStringLiteral("TYPE A\r\n");
    cmds << (d->transferMode == Passive ? QStringLiteral("PASV\r\n") : QStringLiteral("PORT\r\n"));
    if (!dev->isSequential())
        cmds << (QStringLiteral("ALLO ") + QString::number(qMax<qint64>(0, dev->size() - offset)) + "\r\n");
    if (offset > 0)
        cmds << (QStringLiteral("REST ") + QString::number(offset) + "\r\n");
    cmds << (QStringLiteral("STOR ") + _q_sanitizeFtpArg(file) + "\r\n");
    QFtpCommand *cmd = new QFtpCommand(Put, cmds, dev);
    cmd->restartOffset = offset;
    return d->addCommand(cmd);
}

int QFtp::remove(const QString &file)
{
    return d->addCommand(new QFtpCommand(Remove, QStringList(QStringLiteral("DELE ") + _q_sanitizeFtpArg(file) + "\r\n")));
}

int QFtp::mkdir(const QString &dir)
{
    return d->addCommand(new QFtpCommand(Mkdir, QStringList(QStringLiteral("MKD ") + _q_sanitizeFtpArg(dir) + "\r\n")));
}

int QFtp::rmdir(const QString &dir)
{
    return d->addCommand(new QFtpCommand(Rmdir, QStringList(QStringLiteral("RMD ") + _q_sanitizeFtpArg(dir) + "\r\n")));
}

int QFtp::rename(const QString &oldname, const QString &newname)
{
    QStringList cmds;
    cmds << (QStringLiteral("RNFR ") + _q_sanitizeFtpArg(oldname) + "\r\n");
    cmds << (QStringLiteral("RNTO ") + _q_sanitizeFtpArg(newname) + "\r\n");
    return d->addCommand(new QFtpCommand(Rename, cmds));
}

int QFtp::rawCommand(const QString &command)
{
    QString cmd = _q_sanitizeFtpArg(command).trimmed() + "\r\n";
    return d->addCommand(new QFtpCommand(RawCommand, QStringList(cmd)));
}

qint64 QFtp::bytesAvailable() const
{
    return d->pi.dtp.bytesAvailable();
}

qint64 QFtp::read(char *data, qint64 maxlen)
{
    return d->pi.dtp.read(data, maxlen);
}

QByteArray QFtp::readAll()
{
    return d->pi.dtp.readAll();
}

void QFtp::abort()
{
    if (d->pending.isEmpty())
        return;

    clearPendingCommands();
    d->pi.abort();
}

int QFtp::currentId() const
{
    if (d->pending.isEmpty())
        return 0;
    return d->pending.first()->id;
}

QFtp::Command QFtp::currentCommand() const
{
    if (d->pending.isEmpty())
        return None;
    return d->pending.first()->command;
}

QIODevice* QFtp::currentDevice() const
{
    if (d->pending.isEmpty())
        return nullptr;
    QFtpCommand *c = d->pending.first();
    if (c->is_ba)
        return nullptr;
    return c->data.dev;
}

bool QFtp::hasPendingCommands() const
{
    return d->pending.count() > 1;
}

void QFtp::clearPendingCommands()
{
    while (d->pending.count() > 1)
        delete d->pending.takeLast();
}

QFtp::State QFtp::state() const
{
    return d->state;
}

QFtp::Error QFtp::error() const
{
    return d->error;
}

QString QFtp::errorString() const
{
    return d->errorString;
}

void QFtpPrivate::_q_startNextCommand()
{
    Q_Q(QFtp);
    if (pending.isEmpty())
        return;
    QFtpCommand *c = pending.first();

    error = QFtp::NoError;
    errorString = QT_TRANSLATE_NOOP("QFtp", "Unknown error");

    if (q->bytesAvailable())
        q->readAll();
    emit q->commandStarted(c->id);

    // Proxy support
    if (c->command == QFtp::Login && !proxyHost.isEmpty()) {
        QString loginString = c->rawCmds.first().trimmed();
        loginString += '@' + host;
        if (port && port != 21)
            loginString += ':' + QString::number(port);
        loginString += "\r\n";
        c->rawCmds[0] = loginString;
    }

    if (c->command == QFtp::SetTransferMode) {
        _q_piFinished(QStringLiteral("Transfer mode set"));
    } else if (c->command == QFtp::SetProxy) {
        proxyHost = c->rawCmds[0];
        proxyPort = c->rawCmds[1].toUInt();
        c->rawCmds.clear();
        _q_piFinished(QStringLiteral("Proxy set to ") + proxyHost + ':' + QString::number(proxyPort));
    } else if (c->command == QFtp::ConnectToHost) {
#ifndef QT_NO_BEARERMANAGEMENT
        pi.setProperty("_q_networksession", q->property("_q_networksession"));
#endif
        if (!proxyHost.isEmpty()) {
            host = c->rawCmds[0];
            port = c->rawCmds[1].toUInt();
            pi.connectToHost(proxyHost, proxyPort);
        } else {
            pi.connectToHost(c->rawCmds[0], c->rawCmds[1].toUInt());
        }
    } else {
        if (c->command == QFtp::Put) {
            if (c->is_ba) {
                pi.dtp.setData(c->data.ba);
                pi.dtp.setBytesTotal(c->data.ba->size());
            } else if (c->data.dev && (c->data.dev->isOpen() || c->data.dev->open(QIODevice::ReadOnly))) {
                pi.dtp.setDevice(c->data.dev);
                if (c->data.dev->isSequential()) {
                    pi.dtp.setBytesTotal(0);
                    QObject::connect(c->data.dev, &QIODevice::readyRead, &pi.dtp, &QFtpDTP::dataReadyRead);
                    QObject::connect(c->data.dev, &QIODevice::readChannelFinished, &pi.dtp, &QFtpDTP::dataReadyRead);
                } else {
                    if (c->restartOffset > 0 && !c->data.dev->seek(c->restartOffset)) {
                        _q_piError(QFtp::UnknownError,
                                   QStringLiteral("Cannot seek local device to restart offset"));
                        return;
                    }
                    pi.dtp.setBytesTotal(c->data.dev->size());
                }
            }
        } else if (c->command == QFtp::Get) {
            if (!c->is_ba && c->data.dev) {
                pi.dtp.setDevice(c->data.dev);
            }
        } else if (c->command == QFtp::Close) {
            state = QFtp::Closing;
            emit q->stateChanged(state);
        }
        pi.sendCommands(c->rawCmds);
    }
}

void QFtpPrivate::_q_piFinished(const QString&)
{
    if (pending.isEmpty())
        return;
    QFtpCommand *c = pending.first();

    if (c->command == QFtp::Close) {
        if (state != QFtp::Unconnected) {
            close_waitForStateChange = true;
            return;
        }
    }
    emit q_func()->commandFinished(c->id, false);
    pending.removeFirst();

    delete c;

    if (pending.isEmpty()) {
        emit q_func()->done(false);
    } else {
        _q_startNextCommand();
    }
}

void QFtpPrivate::_q_piError(int errorCode, const QString &text)
{
    Q_Q(QFtp);

    if (pending.isEmpty()) {
        qWarning("QFtpPrivate::_q_piError was called without pending command!");
        return;
    }

    QFtpCommand *c = pending.first();

    // Non-fatal errors for SIZE, ALLO and OPTS UTF8 commands
    if (c->command == QFtp::Get && pi.currentCommand().startsWith(QStringLiteral("SIZE "))) {
        pi.dtp.setBytesTotal(0);
        return;
    } else if (c->command == QFtp::Put && pi.currentCommand().startsWith(QStringLiteral("ALLO "))) {
        return;
    } else if (c->command == QFtp::RawCommand && pi.currentCommand().startsWith(QStringLiteral("OPTS UTF8"))) {
        pending.removeFirst();
        delete c;
        if (pending.isEmpty())
            emit q->done(false);
        else
            _q_startNextCommand();
        return;
    }

    error = static_cast<QFtp::Error>(errorCode);
    switch (q->currentCommand()) {
    case QFtp::ConnectToHost:
        errorString = QString::fromLatin1(QT_TRANSLATE_NOOP("QFtp", "Connecting to host failed:\n%1")).arg(text);
        break;
    case QFtp::Login:
        errorString = QString::fromLatin1(QT_TRANSLATE_NOOP("QFtp", "Login failed:\n%1")).arg(text);
        break;
    case QFtp::List:
        errorString = QString::fromLatin1(QT_TRANSLATE_NOOP("QFtp", "Listing directory failed:\n%1")).arg(text);
        break;
    case QFtp::Cd:
        errorString = QString::fromLatin1(QT_TRANSLATE_NOOP("QFtp", "Changing directory failed:\n%1")).arg(text);
        break;
    case QFtp::Get:
        errorString = QString::fromLatin1(QT_TRANSLATE_NOOP("QFtp", "Downloading file failed:\n%1")).arg(text);
        break;
    case QFtp::Put:
        errorString = QString::fromLatin1(QT_TRANSLATE_NOOP("QFtp", "Uploading file failed:\n%1")).arg(text);
        break;
    case QFtp::Remove:
        errorString = QString::fromLatin1(QT_TRANSLATE_NOOP("QFtp", "Removing file failed:\n%1")).arg(text);
        break;
    case QFtp::Mkdir:
        errorString = QString::fromLatin1(QT_TRANSLATE_NOOP("QFtp", "Creating directory failed:\n%1")).arg(text);
        break;
    case QFtp::Rmdir:
        errorString = QString::fromLatin1(QT_TRANSLATE_NOOP("QFtp", "Removing directory failed:\n%1")).arg(text);
        break;
    default:
        errorString = text;
        break;
    }

    pi.clearPendingCommands();
    q->clearPendingCommands();
    emit q->commandFinished(c->id, true);

    pending.removeFirst();
    delete c;
    if (pending.isEmpty())
        emit q->done(true);
    else
        _q_startNextCommand();
}

void QFtpPrivate::_q_piConnectState(int connectState)
{
    state = static_cast<QFtp::State>(connectState);
    emit q_func()->stateChanged(state);
    if (close_waitForStateChange) {
        close_waitForStateChange = false;
        _q_piFinished(QT_TRANSLATE_NOOP("QFtp", "Connection closed"));
    }
}

void QFtpPrivate::_q_piFtpReply(int code, const QString &text)
{
    lastResponseCode = code;
    lastResponseText = text;

    if (q_func()->currentCommand() == QFtp::RawCommand) {
        pi.rawCommand = true;
        emit q_func()->rawCommandReply(code, text);
    }

    // Emit detailed response signal for all commands
    emit q_func()->ftpResponse(code, text);
}

QFtp::~QFtp()
{
    abort();
    close();
}

QT_END_NAMESPACE

#include "qftp.moc"

#endif // QT_NO_FTP
