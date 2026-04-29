#include "ftplistfiles.h"

FTPListFiles::FTPListFiles(QObject *parent) : QObject(parent) {}

// ftp action
void FTPListFiles::setFTP()
{
    loop = new QEventLoop();

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(ftpTimeout()));

    ftp = new QFtp();
    ftp->setTransferMode(QFtp::Passive);

    connect(ftp, SIGNAL(listInfo(QUrlInfo)), this, SLOT(doListInfo(QUrlInfo)));
    connect(ftp, SIGNAL(done(bool)), this, SLOT(isDone(bool)));
    connect(ftp, SIGNAL(commandStarted(int)), this, SLOT(ftpCommandStarted(int)));
    connect(ftp, SIGNAL(commandFinished(int,bool)), this, SLOT(ftpCommandFinished(int,bool)));
    connect(ftp, SIGNAL(rawCommandReply(int,QString)), this, SLOT(ftpRawCommandReply(int,QString)));
    connect(ftp, SIGNAL(stateChanged(int)), this, SLOT(ftpstateChanged(int)));
}

void FTPListFiles::ftpTimeout()
{
    if(timer->isActive())
    {
        timer->stop();
    }

    if(loop->isRunning())
    {
        loop->exit(0);
    }

    ftp->abort();
    ftp->close();
    ftp->deleteLater();

    emit sendLogText(tr("<font color=\"red\">[") + baseSFDL + tr("] FTP Timeout! Keine Verbindung zum Server.</font>"));
    emit sendWarning(tr("FTP Timeout"), "[" + baseSFDL + "] FTP Timeout! Keine Verbindung zum Server.");

    delete ftp;
    delete loop;
    delete timer;
    setFTP();
}

void FTPListFiles::ftpstateChanged(int state)
{
#ifdef QT_DEBUG
    qDebug() << "ftpstateChanged: " << state;
#endif
}

void FTPListFiles::ftpRawCommandReply(int code, const QString & cmd)
{
#ifdef QT_DEBUG
    qDebug() << "ftpRawCommandReply: " << code << cmd;
#endif
}

void FTPListFiles::ftpCommandStarted(int id)
{
#ifdef QT_DEBUG
    if(id == 0)
    {
        #ifdef QT_DEBUG
            qDebug() << "ftp commandStarted (Unconnected) id: " << id;
        #endif
    }

    if(id == 1)
    {
        #ifdef QT_DEBUG
            qDebug() << "ftp commandStarted (HostLookup) id: " << id;
        #endif
    }

    if(id == 2)
    {
        #ifdef QT_DEBUG
            qDebug() << "ftp commandStarted (Connecting) id: " << id;
        #endif
    }

    if(id == 3)
    {
        #ifdef QT_DEBUG
            qDebug() << "ftp commandStarted (Connected) id: " << id;
        #endif
    }

    if(id == 4)
    {
        #ifdef QT_DEBUG
            qDebug() << "ftp commandStarted (LoggedIn) id: " << id;
        #endif
    }

    if(id == 5)
    {
        #ifdef QT_DEBUG
            qDebug() << "ftp commandStarted (Closing) id: " << id;
        #endif
    }
#endif
}

void FTPListFiles::ftpCommandFinished(int commandId, bool error)
{
    QString commandName;
    QString extraInfo;
    QFtp::Command cmd = ftp->currentCommand();

    switch(cmd)
    {
        case QFtp::None:            commandName = "None"; break;
        case QFtp::SetTransferMode: commandName = "SetTransferMode"; break;
        case QFtp::SetProxy:        commandName = "SetProxy"; break;
        case QFtp::ConnectToHost:   commandName = "ConnectToHost"; break;
        case QFtp::Login:           commandName = "Login"; break;
        case QFtp::Close:           commandName = "Close"; break;
        case QFtp::List:            commandName = "List"; break;
        case QFtp::Cd:
        {
            commandName = "Cd";
            extraInfo = " nach " + lastCdPath;
            break;
        }
        case QFtp::Get:             commandName = "Get"; break;
        case QFtp::Put:             commandName = "Put"; break;
        case QFtp::Remove:          commandName = "Remove"; break;
        case QFtp::Mkdir:           commandName = "Mkdir"; break;
        case QFtp::Rmdir:           commandName = "Rmdir"; break;
        case QFtp::Rename:          commandName = "Rename"; break;
        case QFtp::RawCommand:      commandName = "RawCommand"; break;
        default:                    commandName = "Unbekannter Befehl (" + QString::number(cmd) + ")"; break;
    }

    #ifdef QT_DEBUG
    if(error)
    {
        emit sendLogText(tr("<font color=\"red\">[") + baseSFDL + tr("] FTP-Fehler bei %1 (ID %2): %3</font>")
                             .arg(commandName)
                             .arg(commandId)
                             .arg(ftp->errorString()));
    }
    else
    {
        emit sendLogText(baseSFDL + tr(": %1 erfolgreich (ID %2)").arg(commandName).arg(commandId));
    }
    #endif
}

void FTPListFiles::ftpList(QString ip, int port, QString user, QString pass, QString path,
                                  QString proxyHost, QString proxyPort, QString proxyUser, QString proxyPass, QStringList data)
{
    // set proxy
    if(!proxyHost.isEmpty() && !proxyPort.isEmpty())
    {
        proxy.setType(QNetworkProxy::Socks5Proxy);

        proxy.setHostName(proxyHost);
        proxy.setPort(proxyPort.toInt());

        if(!proxyUser.isEmpty() && !proxyPass.isEmpty())
        {
            proxy.setUser(proxyUser);
            proxy.setPassword(proxyPass);
        }

        QNetworkProxy::setApplicationProxy(proxy);
    }

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

    lastCdPath = path;

    pathList.clear();

    getFTPIndex(baseIP, basePort, baseUser, basePass, basePath);

    emit sendFTPData(data, fileList);
}

void FTPListFiles::getFTPIndex(QString ip, int port, QString user, QString pass, QString path)
{
    basePath = path;
    emit sendLogText(baseSFDL + tr(": Lade Inhalt von Pfad: ") + basePath);

    setFTP();

    timer->setSingleShot(true);
    timer->start(30000);

    loop->connect(ftp, SIGNAL(done(bool)), loop, SLOT(quit()));

    ftp->connectToHost(ip, port);
    ftp->login(user, pass);
    if(!path.isEmpty())
    {
        lastCdPath = path;
        ftp->cd(path);
    }
    ftp->list();

    loop->exec();

    ftp->close();
    delete ftp;
    delete timer;
    delete loop;
    ftp = nullptr;
    timer = nullptr;
    loop = nullptr;

    while(!pathList.isEmpty())
    {
        QString getPath = pathList.takeFirst();
        getFTPIndex(baseIP, basePort, baseUser, basePass, getPath);
    }
}

void FTPListFiles::doListInfo(const QUrlInfo& info)
{
    if(info.isFile())
    {
        #ifdef QT_DEBUG
            qDebug() << "isFile: " << info.name() + "|" + QString::number(info.size());
        #endif

        if(basePath.endsWith("/"))
        {
            fileList.append(basePath + info.name() + "|" + QString::number(info.size()));
            emit sendLogText(baseSFDL + ": " + basePath + info.name() + " [" + QString::number(info.size()) + "]");
        }
        else
        {
            fileList.append(basePath + "/" + info.name() + "|" + QString::number(info.size()));
            emit sendLogText(baseSFDL + ": " + basePath + "/" + info.name() + " [" + QString::number(info.size()) + "]");
        }
    }

    if(info.isDir() && info.name() != "." && info.name() != "..")
    {
        #ifdef QT_DEBUG
            qDebug() << "isDir: " << info.name();
        #endif

        if(basePath.endsWith("/"))
        {
            pathList.append(basePath + info.name());
            emit sendLogText(baseSFDL + ": " + basePath + info.name() + " [Verzeichnis]");
        }
        else
        {
            pathList.append(basePath + "/" + info.name());
            emit sendLogText(baseSFDL + ": " + basePath + "/" + info.name() + " [Verzeichnis]");
        }
    }
}

void FTPListFiles::isDone(bool)
{
    if(timer->isActive())
    {
        timer->stop();
    }

    if(ftp->error())
    {
        #ifdef QT_DEBUG
            qDebug() << "FTP Error: " << ftp->error();
            qDebug() << "FTP ErrorString: " << ftp->errorString();
        #endif

        emit sendLogText(tr("<font color=\"red\">[") + baseSFDL + tr("] FTP Fehler: ") + ftp->errorString() + "</font>");
        emit sendWarning(tr("FTP Fehler"), "[" + baseSFDL + "] " + ftp->errorString());
    }
    else
    {
        #ifdef QT_DEBUG
            qDebug() << "Alle FTP Operationen ohne Fehler beendet!";
        #endif
    }
}
