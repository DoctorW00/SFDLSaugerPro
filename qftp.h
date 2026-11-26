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
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QFTP_H
#define QFTP_H

#include <QtCore/qglobal.h>
#include <QtCore/qstring.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qobject.h>
#include <QtCore/qiodevice.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qdatetime.h>

// Qt5: QUrlInfo = QtNetwork, Qt6: replacement
#include "qurlinfo_compat.h"

QT_BEGIN_NAMESPACE

class QFtpPrivate;

class QFtp : public QObject
{
    Q_OBJECT

public:
    explicit QFtp(QObject *parent = nullptr);
    virtual ~QFtp();

    enum State {
        Unconnected,
        HostLookup,
        Connecting,
        Connected,
        LoggedIn,
        Closing
    };
    Q_ENUM(State)

    enum Error {
        NoError,
        UnknownError,
        HostNotFound,
        ConnectionRefused,
        NotConnected,
        Timeout,
        AuthenticationFailed,
        FileNotFound,
        PermissionDenied,
        TransferAborted
    };
    Q_ENUM(Error)

    enum Command {
        None,
        SetTransferMode,
        SetProxy,
        ConnectToHost,
        Login,
        Close,
        List,
        Cd,
        Get,
        Put,
        Remove,
        Mkdir,
        Rmdir,
        Rename,
        RawCommand
    };
    Q_ENUM(Command)

    enum TransferMode {
        Active,
        Passive
    };
    Q_ENUM(TransferMode)

    enum TransferType {
        Binary,
        Ascii
    };
    Q_ENUM(TransferType)

    // Modern convenience methods
    void setConnectTimeout(int milliseconds);
    int connectTimeout() const;

    void setTransferTimeout(int milliseconds);
    int transferTimeout() const;

    bool isConnected() const { return state() == Connected || state() == LoggedIn; }
    bool isLoggedIn() const { return state() == LoggedIn; }

    // Legacy API (kept for compatibility)
    int setProxy(const QString &host, quint16 port);
    int connectToHost(const QString &host, quint16 port = 21);
    int login(const QString &user = QString(), const QString &password = QString());
    int close();
    int setTransferMode(TransferMode mode);
    int list(const QString &dir = QString());
    int cd(const QString &dir);
    // restartOffset > 0 resumes a transfer (FTP "REST" command):
    //  get(): the server starts sending at that byte. Open the local device in append
    //         mode (or seek it to restartOffset) before calling.
    //  put(): the local device is seeked to restartOffset and the server is told to
    //         continue there. If the server does not support REST the command fails.
    // Progress: dataTransferProgress() counts only the bytes transferred in this
    // session, the total is the complete file size.
    int get(const QString &file, QIODevice *dev = nullptr, TransferType type = Binary,
            qint64 restartOffset = 0);
    int put(const QByteArray &data, const QString &file, TransferType type = Binary,
            qint64 restartOffset = 0);
    int put(QIODevice *dev, const QString &file, TransferType type = Binary,
            qint64 restartOffset = 0);
    int remove(const QString &file);
    int mkdir(const QString &dir);
    int rmdir(const QString &dir);
    int rename(const QString &oldname, const QString &newname);

    int rawCommand(const QString &command);

    qint64 bytesAvailable() const;
    qint64 read(char *data, qint64 maxlen);
    QByteArray readAll();

    int currentId() const;
    QIODevice* currentDevice() const;
    Command currentCommand() const;
    bool hasPendingCommands() const;
    void clearPendingCommands();

    State state() const;

    Error error() const;
    QString errorString() const;
    
    // New: detailed server response info
    int lastResponseCode() const;
    QString lastResponseText() const;

public Q_SLOTS:
    void abort();

Q_SIGNALS:
    void stateChanged(int);
    void listInfo(const QUrlInfo&);
    void readyRead();
    void dataTransferProgress(qint64, qint64);
    void rawCommandReply(int, const QString&);

    void commandStarted(int);
    void commandFinished(int, bool);
    void done(bool);
    
    // New: detailed response signal
    void ftpResponse(int code, const QString &text);

private:
    Q_DISABLE_COPY(QFtp)
    QScopedPointer<QFtpPrivate> d;
};

QT_END_NAMESPACE

#endif // QFTP_H
