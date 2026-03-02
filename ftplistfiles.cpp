#include "ftplistfiles.h"

#include <QRegularExpression>

FTPListFiles::FTPListFiles(QObject *parent) : QObject(parent) {}

static bool parseListLine(const QString& line, bool* isDir, QString* name, qint64* size)
{
    QRegularExpression re1(QStringLiteral("^([dl-])[rwx-]{9}\\s+\\d+\\s+\\S+\\s+\\S+\\s+(\\d+)\\s+\\w+\\s+\\d+\\s+[\\d:]+\\s+(.+)$"));
    QRegularExpression re2(QStringLiteral("^([dl-])[rwx-]{9}\\s+\\d+\\s+\\S+\\s+\\S+\\s+(\\d+)\\s+\\w+\\s+\\d+\\s+\\d+\\s+(.+)$"));

    QRegularExpressionMatch match = re1.match(line);
    if (!match.hasMatch())
    {
        match = re2.match(line);
    }
    if (match.hasMatch())
    {
        if (isDir) *isDir = (match.captured(1) == "d");
        if (size) *size = match.captured(2).toLongLong();
        if (name) *name = match.captured(3).trimmed();
        return true;
    }

    QString trimmed = line.trimmed();
    if (trimmed.isEmpty())
    {
        return false;
    }
    QStringList parts = trimmed.split(' ', Qt::SkipEmptyParts);
    if (parts.isEmpty())
    {
        return false;
    }
    if (isDir) *isDir = trimmed.startsWith('d');
    if (name) *name = parts.last();
    if (size) *size = 0;
    return true;
}

void FTPListFiles::ftpList(QString ip, int port, QString user, QString pass, QString path,
                                  QString proxyHost, QString proxyPort, QString proxyUser, QString proxyPass, QStringList data)
{
    if(user.isEmpty())
    {
        user = "anonymous";
    }

    if(pass.isEmpty())
    {
        pass = "anonymous@sfdlsauger.test";
    }

    if(path.isEmpty())
    {
        path = "/";
    }

    baseIP = ip;
    basePort = port;
    baseUser = user;
    basePass = pass;
    basePath = path;
    proxyHostValue = proxyHost;
    proxyPortValue = proxyPort;
    proxyUserValue = proxyUser;
    proxyPassValue = proxyPass;
    // baseSFDL = SFDL;

    lastCdPath = path;

    pathList.clear();
    fileList.clear();

    if(!ftp)
    {
        ftp = new FtpClient(this);
    }

    getFTPIndex(baseIP, basePort, baseUser, basePass, basePath);

    // return fileList;

    emit sendFTPData(data, fileList);

    if(ftp)
    {
        ftp->quit();
    }
}

void FTPListFiles::getFTPIndex(QString ip, int port, QString user, QString pass, QString path)
{
    basePath = path;

    emit sendLogText(baseSFDL + tr(": Lade Inhalt von Pfad: ") + basePath);

    if(!ftp)
    {
        emit sendWarning(tr("FTP Fehler"), tr("FTP Client nicht initialisiert"));
        return;
    }

    // set proxy
    if(!proxyHostValue.isEmpty() && !proxyPortValue.isEmpty())
    {
        proxy.setType(QNetworkProxy::Socks5Proxy);
        proxy.setHostName(proxyHostValue);
        proxy.setPort(proxyPortValue.toInt());
        if(!proxyUserValue.isEmpty() && !proxyPassValue.isEmpty())
        {
            proxy.setUser(proxyUserValue);
            proxy.setPassword(proxyPassValue);
        }
    }
    else
    {
        proxy = QNetworkProxy::NoProxy;
    }
    ftp->setProxy(proxy);

    QString err;
    if(!connected)
    {
        if(!ftp->connectToHost(ip, port, &err))
        {
            emit sendLogText(tr("<font color=\"red\">[") + baseSFDL + tr("] FTP Fehler: ") + err + "</font>");
            emit sendWarning(tr("FTP Fehler"), "[" + baseSFDL + "] " + err);
            return;
        }
        if(!ftp->login(user, pass, &err))
        {
            emit sendLogText(tr("<font color=\"red\">[") + baseSFDL + tr("] FTP Fehler: ") + err + "</font>");
            emit sendWarning(tr("FTP Fehler"), "[" + baseSFDL + "] " + err);
            return;
        }
        connected = true;
    }

    if(!path.isEmpty())
    {
        lastCdPath = path;
        if(!ftp->cwd(path, &err))
        {
            emit sendLogText(tr("<font color=\"red\">[") + baseSFDL + tr("] FTP Fehler: ") + err + "</font>");
            emit sendWarning(tr("FTP Fehler"), "[" + baseSFDL + "] " + err);
            return;
        }
    }

    QStringList lines;
    if(!ftp->list(QString(), &lines, &err))
    {
        emit sendLogText(tr("<font color=\"red\">[") + baseSFDL + tr("] FTP Fehler: ") + err + "</font>");
        emit sendWarning(tr("FTP Fehler"), "[" + baseSFDL + "] " + err);
        return;
    }

    for (const QString& line : lines)
    {
        bool isDir = false;
        QString name;
        qint64 size = 0;
        if (!parseListLine(line, &isDir, &name, &size))
        {
            continue;
        }
        if (name == "." || name == "..")
        {
            continue;
        }

        if (isDir)
        {
            if(basePath.endsWith("/"))
            {
                pathList.append(basePath + name);
                emit sendLogText(baseSFDL + ": " + basePath + name + " [Verzeichnis]");
            }
            else
            {
                pathList.append(basePath + "/" + name);
                emit sendLogText(baseSFDL + ": " + basePath + "/" + name + " [Verzeichnis]");
            }
        }
        else
        {
            if(basePath.endsWith("/"))
            {
                fileList.append(basePath + name + "|" + QString::number(size));
                emit sendLogText(baseSFDL + ": " + basePath + name + " [" + QString::number(size) + "]");
            }
            else
            {
                fileList.append(basePath + "/" + name + "|" + QString::number(size));
                emit sendLogText(baseSFDL + ": " + basePath + "/" + name + " [" + QString::number(size) + "]");
            }
        }
    }

    if(!pathList.isEmpty())
    {
        const QStringList pending = pathList;
        pathList.clear();
        for(const QString& getPath : pending)
        {
#ifdef QT_DEBUG
            qDebug() << "pathList: " << getPath;
#endif
            getFTPIndex(baseIP, basePort, baseUser, basePass, getPath);
        }
    }
}
