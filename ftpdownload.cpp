#include "ftpdownload.h"

FTPDownload::FTPDownload(QStringList data) : data(data)
{
    mutex.lock();
    _working = false;
    _abort = false;

    id = this->data.at(0);
    host = this->data.at(1);
    port = this->data.at(2);
    user = this->data.at(3);
    pass = this->data.at(4);

    if(user.isEmpty())
    {
        user = "anonymous";
    }

    if(pass.isEmpty())
    {
        pass = "sfdl@sauger.pro";
    }

    dir = this->data.at(5);
    dlpath = this->data.at(6);
    dlfile = this->data.at(7);
    tableRow = this->data.at(8).toInt();

    _tableRow = this->data.at(8).toInt();
    _id = this->data.at(0);

    QString proxyHost = this->data.at(9);
    QString proxyPort = this->data.at(10);
    QString proxyUser = this->data.at(11);
    QString proxyPass = this->data.at(12);
    if (this->data.size() > 13)
    {
        expectedSize = this->data.at(13).toLongLong();
    }

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
    mutex.unlock();
}

FTPDownload::~FTPDownload()
{
    if(_abort == false)
    {
        delete ftp;
        delete file;
    }
}

void FTPDownload::abort()
{
    mutex.lock();
    _abort = true;
    _working = false;
    if(ftp)
    {
        ftp->abort();
    }
    mutex.unlock();
}

void FTPDownload::finishedDownload()
{
    mutex.lock();
    _working = false;
    mutex.unlock();
}

void FTPDownload::process()
{
    emit statusUpdateFile(id, _tableRow, tr("Wird geladen ..."), 1);

    mutex.lock();
    _working = true;
    mutex.unlock();

    ftp = new FtpClient(this);
    connect(ftp, &FtpClient::dataTransferProgress, this, &FTPDownload::updateProgress);

    file = new QFile(this);
    // make sure paths are working cross platform
    file->setFileName(QDir::toNativeSeparators(QDir::cleanPath(dlpath + "/" + dlfile)));

    QString err;
    if(!proxy.hostName().isEmpty() && proxy.port() > 0)
    {
        ftp->setProxy(proxy);
    }
    else
    {
        ftp->setProxy(QNetworkProxy::NoProxy);
    }

    if(!ftp->connectToHost(host, port.toInt(), &err))
    {
        QString msg = tr("Verbindung fehlgeschlagen: ") + err;
        emit statusUpdateFile(id, _tableRow, msg, 2);
        emit error(id + ": " + msg);
        _working = false;
        emit finished();
        return;
    }
    if(!ftp->login(user, pass, &err))
    {
        QString msg = tr("Login fehlgeschlagen: ") + err;
        emit statusUpdateFile(id, _tableRow, msg, 2);
        emit error(id + ": " + msg);
        _working = false;
        emit finished();
        return;
    }
    if(!dir.isEmpty())
    {
        if(!ftp->cwd(dir, &err))
        {
            QString msg = tr("Verzeichnis nicht gefunden: ") + err;
            emit statusUpdateFile(id, _tableRow, msg, 2);
            emit error(id + ": " + msg);
            _working = false;
            emit finished();
            return;
        }
    }

    emit statusUpdateFile(id, _tableRow, tr("Download läuft ..."), 1);

    qint64 resumeFrom = 0;
    if(file->exists())
    {
        resumeFrom = file->size();
    }

    if(resumeFrom > 0)
    {
        if(!file->open(QIODevice::Append))
        {
            QString msg = tr("Kann Datei nicht öffnen (Append)");
            emit statusUpdateFile(id, _tableRow, msg, 3);
            emit error(id + ": " + msg);
            _working = false;
            emit finished();
            return;
        }
    }
    else
    {
        if(!file->open(QIODevice::WriteOnly))
        {
            QString msg = tr("Kann Datei nicht öffnen (Write)");
            emit statusUpdateFile(id, _tableRow, msg, 3);
            emit error(id + ": " + msg);
            _working = false;
            emit finished();
            return;
        }
    }

    qint64 totalSize = 0;
    if(!ftp->retr(dlfile, file, resumeFrom, &totalSize, &err))
    {
        mutex.lock();
        bool wasAborted = _abort;
        mutex.unlock();

        if (wasAborted)
        {
            emit statusUpdateFile(id, _tableRow, tr("Download abgebrochen"), 9);
        }
        else
        {
            QString msg = tr("Download fehlgeschlagen: ") + err;
            emit statusUpdateFile(id, _tableRow, msg, 3);
            emit error(id + ": " + msg);
        }
        _working = false;
        emit finished();
        return;
    }

    emit statusUpdateFile(id, _tableRow, tr("Fertig!"), 10);

    file->flush();
    file->close();

    _working = false;
    emit finished();
}

void FTPDownload::updateProgress(qint64 read, qint64 total)
{
    if(_working && !_abort)
    {
        if (total <= 0)
        {
            if (expectedSize > 0)
            {
                total = expectedSize;
            }
            else
            {
                total = read;
            }
        }
        emit doProgress(id, _tableRow, read, total, false, false);
    }
}
