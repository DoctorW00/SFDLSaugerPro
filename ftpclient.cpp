#include "ftpclient.h"

#include <QRegularExpression>

FtpClient::FtpClient(QObject *parent)
    : QObject(parent),
      controlSocket(new QTcpSocket(this))
{
}

void FtpClient::setProxy(const QNetworkProxy& proxy)
{
    this->proxy = proxy;
    if (controlSocket)
    {
        controlSocket->setProxy(proxy);
    }
}

void FtpClient::setTimeoutMs(int timeoutMs)
{
    this->timeoutMs = timeoutMs;
}

bool FtpClient::isConnected() const
{
    return controlSocket && controlSocket->state() == QAbstractSocket::ConnectedState;
}

bool FtpClient::connectToHost(const QString& host, int port, QString* error)
{
    aborted = false;
    controlHost = host;
    if (!controlSocket)
    {
        if (error) *error = tr("Kein Control-Socket verfügbar");
        return false;
    }

    controlSocket->abort();
    controlSocket->setProxy(proxy);
    controlSocket->connectToHost(host, port);
    if (!controlSocket->waitForConnected(timeoutMs))
    {
        if (error) *error = controlSocket->errorString();
        return false;
    }

    int code = 0;
    QStringList lines;
    if (!readResponse(&code, &lines, error))
    {
        return false;
    }

    if (code != 220)
    {
        if (error) *error = lines.join("\n");
        return false;
    }

    return true;
}

bool FtpClient::login(const QString& user, const QString& pass, QString* error)
{
    int code = 0;
    QStringList lines;
    if (!sendCommand(QStringLiteral("USER %1").arg(user), &code, &lines, error))
    {
        return false;
    }

    if (code == 230)
    {
        return true;
    }

    if (code != 331)
    {
        if (error) *error = lines.join("\n");
        return false;
    }

    if (!sendCommand(QStringLiteral("PASS %1").arg(pass), &code, &lines, error))
    {
        return false;
    }

    if (code != 230)
    {
        if (error) *error = lines.join("\n");
        return false;
    }

    return true;
}

bool FtpClient::cwd(const QString& path, QString* error)
{
    int code = 0;
    QStringList lines;
    if (!sendCommand(QStringLiteral("CWD %1").arg(path), &code, &lines, error))
    {
        return false;
    }

    if (code != 250)
    {
        if (error) *error = lines.join("\n");
        return false;
    }
    return true;
}

bool FtpClient::list(const QString& path, QStringList* lines, QString* error)
{
    QTcpSocket* dataSocket = nullptr;
    if (!openPassiveDataSocket(dataSocket, error))
    {
        return false;
    }

    int code = 0;
    QStringList response;
    const QString cmd = path.isEmpty() ? QStringLiteral("LIST") : QStringLiteral("LIST %1").arg(path);
    if (!sendCommand(cmd, &code, &response, error))
    {
        dataSocket->close();
        dataSocket->deleteLater();
        return false;
    }

    if (code != 150 && code != 125)
    {
        if (error) *error = response.join("\n");
        dataSocket->close();
        dataSocket->deleteLater();
        return false;
    }

    QByteArray data;
    QElapsedTimer timer;
    timer.start();
    while (!aborted)
    {
        if (dataSocket->bytesAvailable() > 0)
        {
            data += dataSocket->readAll();
            timer.restart();
            continue;
        }
        if (dataSocket->state() == QAbstractSocket::UnconnectedState)
        {
            break;
        }
        if (!dataSocket->waitForReadyRead(500))
        {
            if (timer.elapsed() > timeoutMs)
            {
                if (error) *error = tr("Daten-Timeout beim LIST");
                dataSocket->abort();
                dataSocket->deleteLater();
                return false;
            }
        }
    }

    dataSocket->close();
    dataSocket->deleteLater();

    const QList<QByteArray> rawLines = data.split('\n');
    if (lines)
    {
        lines->clear();
        for (const QByteArray& rawLine : rawLines)
        {
            QString line = QString::fromUtf8(rawLine).trimmed();
            if (!line.isEmpty())
            {
                lines->append(line);
            }
        }
    }

    if (!readResponse(&code, &response, error))
    {
        return false;
    }
    if (code != 226 && code != 250)
    {
        if (error) *error = response.join("\n");
        return false;
    }

    return true;
}

bool FtpClient::size(const QString& path, qint64* size, QString* error)
{
    int code = 0;
    QStringList response;
    if (!sendCommand(QStringLiteral("SIZE %1").arg(path), &code, &response, error))
    {
        return false;
    }

    if (code != 213)
    {
        if (error) *error = response.join("\n");
        return false;
    }

    if (size)
    {
        QRegularExpression re(QStringLiteral("^(\\d{3})\\s+(\\d+)"));
        QRegularExpressionMatch match = re.match(response.value(0));
        if (match.hasMatch())
        {
            *size = match.captured(2).toLongLong();
        }
        else
        {
            *size = 0;
        }
    }

    return true;
}

bool FtpClient::retr(const QString& path, QFile* file, qint64 resumeFrom, qint64* totalSize, QString* error)
{
    if (!file || !file->isOpen())
    {
        if (error) *error = tr("Datei ist nicht geöffnet");
        return false;
    }

    int code = 0;
    QStringList response;
    if (!sendCommand(QStringLiteral("TYPE I"), &code, &response, error))
    {
        return false;
    }
    if (code != 200 && code != 250)
    {
        if (error) *error = response.join("\n");
        return false;
    }

    qint64 serverSize = 0;
    if (totalSize)
    {
        size(path, &serverSize, nullptr);
        *totalSize = serverSize;
    }

    if (resumeFrom > 0)
    {
        if (!sendCommand(QStringLiteral("REST %1").arg(resumeFrom), &code, &response, error))
        {
            return false;
        }
        if (code != 350)
        {
            if (error) *error = response.join("\n");
            return false;
        }
    }

    QTcpSocket* dataSocket = nullptr;
    if (!openPassiveDataSocket(dataSocket, error))
    {
        return false;
    }

    if (!sendCommand(QStringLiteral("RETR %1").arg(path), &code, &response, error))
    {
        dataSocket->close();
        dataSocket->setParent(nullptr);
        dataSocket->deleteLater();
        return false;
    }

    if (code != 150 && code != 125)
    {
        if (error) *error = response.join("\n");
        dataSocket->close();
        dataSocket->setParent(nullptr);
        dataSocket->deleteLater();
        return false;
    }

    qint64 bytesRead = resumeFrom;
    emit dataTransferProgress(bytesRead, serverSize > 0 ? serverSize : bytesRead);

    QElapsedTimer timer;
    timer.start();
    const int noDataTimeoutMs = 15000;
    while (!aborted)
    {
        if (dataSocket->bytesAvailable() > 0)
        {
            QByteArray chunk = dataSocket->readAll();
            if (chunk.isEmpty())
            {
                continue;
            }
            if (file->write(chunk) < 0)
            {
                if (error) *error = tr("Fehler beim Schreiben in die Datei");
                dataSocket->abort();
                dataSocket->setParent(nullptr);
                dataSocket->deleteLater();
                return false;
            }
            bytesRead += chunk.size();
            emit dataTransferProgress(bytesRead, serverSize);
            timer.restart();
            continue;
        }
        if (dataSocket->state() == QAbstractSocket::UnconnectedState)
        {
            break;
        }
        if (!dataSocket->waitForReadyRead(500))
        {
            if (timer.elapsed() > noDataTimeoutMs)
            {
                if (error) *error = tr("Keine Daten empfangen – prüfen Sie Firewall/NAT (PASV)");
                dataSocket->abort();
                dataSocket->setParent(nullptr);
                dataSocket->deleteLater();
                return false;
            }
        }
    }

    emit dataTransferProgress(bytesRead, serverSize > 0 ? serverSize : bytesRead);

    dataSocket->close();
    dataSocket->setParent(nullptr);
    dataSocket->deleteLater();

    if (!readResponse(&code, &response, error))
    {
        return false;
    }
    if (code != 226 && code != 250)
    {
        if (error) *error = response.join("\n");
        return false;
    }

    return true;
}

void FtpClient::quit()
{
    int code = 0;
    QStringList response;
    sendCommand(QStringLiteral("QUIT"), &code, &response, nullptr);
    if (controlSocket)
    {
        controlSocket->disconnectFromHost();
    }
}

void FtpClient::abort()
{
    aborted = true;
    if (controlSocket)
    {
        controlSocket->abort();
    }
}

bool FtpClient::sendCommand(const QString& cmd, int* code, QStringList* lines, QString* error)
{
    if (!controlSocket || controlSocket->state() != QAbstractSocket::ConnectedState)
    {
        if (error) *error = tr("Keine Verbindung zum FTP-Server");
        return false;
    }

    QByteArray data = cmd.toUtf8();
    data.append("\r\n");
    if (controlSocket->write(data) < 0)
    {
        if (error) *error = controlSocket->errorString();
        return false;
    }
    if (!controlSocket->waitForBytesWritten(timeoutMs))
    {
        if (error) *error = controlSocket->errorString();
        return false;
    }

    return readResponse(code, lines, error);
}

bool FtpClient::readResponse(int* code, QStringList* lines, QString* error)
{
    if (!controlSocket)
    {
        if (error) *error = tr("Kein Control-Socket verfügbar");
        return false;
    }

    QStringList responseLines;
    int responseCode = 0;
    bool multiline = false;
    int multilineCode = 0;

    QElapsedTimer timer;
    timer.start();

    while (!aborted)
    {
        if (!controlSocket->canReadLine())
        {
            if (!controlSocket->waitForReadyRead(500))
            {
                if (timer.elapsed() > timeoutMs)
                {
                    if (error) *error = tr("Timeout beim Lesen der FTP-Antwort");
                    return false;
                }
                continue;
            }
        }

        QByteArray rawLine = controlSocket->readLine();
        QString line = QString::fromUtf8(rawLine).trimmed();
        if (line.isEmpty())
        {
            continue;
        }
        responseLines.append(line);
        timer.restart();

        if (line.length() < 3)
        {
            continue;
        }

        bool ok = false;
        int c = line.left(3).toInt(&ok);
        if (!ok)
        {
            continue;
        }

        if (responseCode == 0)
        {
            responseCode = c;
            if (line.length() > 3 && line.at(3) == '-')
            {
                multiline = true;
                multilineCode = c;
                continue;
            }
            if (line.length() > 3 && line.at(3) == ' ')
            {
                break;
            }
        }
        else if (multiline && c == multilineCode && line.length() > 3 && line.at(3) == ' ')
        {
            break;
        }
        else if (!multiline && line.length() > 3 && line.at(3) == ' ')
        {
            break;
        }
    }

    if (code) *code = responseCode;
    if (lines) *lines = responseLines;

    return true;
}

bool FtpClient::openPassiveDataSocket(QTcpSocket*& dataSocket, QString* error)
{
    if (openEpsvDataSocket(dataSocket, error))
        return true;

    int code = 0;
    QStringList response;
    if (!sendCommand(QStringLiteral("PASV"), &code, &response, error))
    {
        return false;
    }
    if (code != 227)
    {
        if (error) *error = response.join("\n");
        return false;
    }

    QString resp = response.value(0);
    QRegularExpression re(QStringLiteral("\\((\\d+),(\\d+),(\\d+),(\\d+),(\\d+),(\\d+)\\)"));
    QRegularExpressionMatch match = re.match(resp);
    if (!match.hasMatch())
    {
        if (error) *error = tr("Konnte PASV-Antwort nicht parsen: %1").arg(resp);
        return false;
    }

    QString pasvHost = QString("%1.%2.%3.%4")
        .arg(match.captured(1))
        .arg(match.captured(2))
        .arg(match.captured(3))
        .arg(match.captured(4));
    int p1 = match.captured(5).toInt();
    int p2 = match.captured(6).toInt();
    int port = (p1 * 256) + p2;

    QString host = pasvHost;
    if (isPrivateAddress(pasvHost) && !controlHost.isEmpty())
        host = controlHost;

    dataSocket = new QTcpSocket(this);
    dataSocket->setProxy(proxy);
    dataSocket->connectToHost(host, port);
    if (!dataSocket->waitForConnected(timeoutMs))
    {
        if (error) *error = dataSocket->errorString();
        dataSocket->deleteLater();
        dataSocket = nullptr;
        return false;
    }

    return true;
}

bool FtpClient::openEpsvDataSocket(QTcpSocket*& dataSocket, QString* error)
{
    int code = 0;
    QStringList response;
    if (!sendCommand(QStringLiteral("EPSV"), &code, &response, error))
    {
        return false;
    }
    if (code != 229)
    {
        return false;
    }

    QString resp = response.value(0);
    QRegularExpression re(QStringLiteral("\\|\\|\\|(\\d+)\\|"));
    QRegularExpressionMatch match = re.match(resp);
    if (!match.hasMatch())
    {
        return false;
    }

    int port = match.captured(1).toInt();
    QString host = controlSocket ? controlSocket->peerAddress().toString() : QString();
    if (host.startsWith(QLatin1String("::ffff:")))
        host = host.mid(7);

    dataSocket = new QTcpSocket(this);
    dataSocket->setProxy(proxy);
    dataSocket->connectToHost(host, port);
    if (!dataSocket->waitForConnected(timeoutMs))
    {
        if (error) *error = dataSocket->errorString();
        dataSocket->deleteLater();
        dataSocket = nullptr;
        return false;
    }

    return true;
}

bool FtpClient::isPrivateAddress(const QString& ip) const
{
    QRegularExpression re(QStringLiteral("^(\\d+)\\.(\\d+)\\.(\\d+)\\.(\\d+)$"));
    QRegularExpressionMatch m = re.match(ip.trimmed());
    if (!m.hasMatch()) return false;
    int a = m.captured(1).toInt();
    int b = m.captured(2).toInt();
    if (a == 10) return true;
    if (a == 172 && b >= 16 && b <= 31) return true;
    if (a == 192 && b == 168) return true;
    return false;
}

bool FtpClient::waitForSocketReady(QTcpSocket* socket, int timeoutMs, QString* error)
{
    if (!socket)
    {
        if (error) *error = tr("Kein Socket verfügbar");
        return false;
    }
    if (socket->bytesAvailable() > 0)
    {
        return true;
    }
    if (!socket->waitForReadyRead(timeoutMs))
    {
        if (error) *error = socket->errorString();
        return false;
    }
    return true;
}
