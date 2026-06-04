#include "ftpdownload.h"
#include <QTimer>

FTPDownload::FTPDownload(QStringList data) : data(data)
{
    mutex.lock();
    _working = false;
    _abort = false;

    downloadFinished = false;
    downloadTimeouted = false;

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
    }
    mutex.unlock();
}

FTPDownload::~FTPDownload()
{
    if(file)
    {
        if(file->isOpen())
        {
            file->close();
        }
        delete file;
    }
}

void FTPDownload::abort()
{
    QMutexLocker locker(&mutex);
    if (_abort) return;

    _abort = true;
    _working = false;

    if(ftp)
    {
        ftp->abort();
    }

    if(ftpLoop && ftpLoop->isRunning())
    {
        ftpLoop->quit();
    }
}

void FTPDownload::finishedDownload()
{
    mutex.lock();
    _working = false;
    mutex.unlock();
}

void FTPDownload::process()
{    
    if(!proxy.hostName().isEmpty() && proxy.port() > 0)
    {
        QNetworkProxy::setApplicationProxy(proxy);
    }

    if(!m_isChunked || m_isMasterChunk)
    {
        emit statusUpdateFile(id, _tableRow, tr("Wird geladen ..."), 1);
    }

    mutex.lock();
    _working = true;
    mutex.unlock();

    ftpLoop = new QEventLoop();
    ftp = new QFtp();

    connect(ftp, SIGNAL(done(bool)), this, SLOT(isDone(bool)));
    connect(ftp, SIGNAL(dataTransferProgress(qint64,qint64)), this, SLOT(updateProgress(qint64, qint64)));

    connect(ftp, &QFtp::done, ftpLoop, &QEventLoop::quit);

    // file = new QFile();
    file = new ThrottledFile();
    file->setFileName(QDir::toNativeSeparators(QDir::cleanPath(dlpath + "/" + dlfile)));

    bool openSuccess = false;

    if(m_isChunked)
    {
        if(file->open(QIODevice::ReadWrite))
        {
            emit sendLogText(tr("[%1] Lade Chunk %2 bis %3").arg(QFileInfo(*file).fileName(), QString::number(m_chunkStart), QString::number(m_chunkEnd)));

            openSuccess = true;
            ftp->m_fileSize = m_chunkStart;
            if(!file->seek(m_chunkStart))
            {
                emit statusUpdateFile(id, _tableRow, tr("Fehler: Seek fehlgeschlagen"), 3);
                emit finished();

                ftp->deleteLater();
                file->deleteLater();
                ftpLoop->deleteLater();
                return;
            }
        }
    }
    else
    {
        if(file->size() > 0)
        {
            if(file->open(QIODevice::Append) && file->isWritable())
            {
                openSuccess = true;
                ftp->m_fileSize = file->size();
            }
        }
        else
        {
            if(file->open(QIODevice::WriteOnly) && file->isWritable())
            {
                openSuccess = true;
                ftp->m_fileSize = 0;
            }
        }
    }

    if(openSuccess)
    {
        ftp->connectToHost(host, port.toInt());
        ftp->login(user, pass);
        ftp->cd(dir);
        ftp->setTransferMode(QFtp::Passive);
        ftp->get(dlfile, file);

        QTimer timeoutTimer;
        timeoutTimer.setSingleShot(true);

        connect(&timeoutTimer, &QTimer::timeout, ftpLoop, [this]() {
            downloadTimeouted = true;
            ftpLoop->quit();
        });

        connect(ftp, &QFtp::dataTransferProgress, &timeoutTimer, [&timeoutTimer](qint64 bytes, qint64 total) {
            Q_UNUSED(bytes);
            Q_UNUSED(total);
            timeoutTimer.start(30000);
        });

        timeoutTimer.start(30000);
        ftpLoop->exec();
        timeoutTimer.stop();
    }

    if(ftp)
    {
        ftp->blockSignals(true);
    }

    mutex.lock();
    bool userAborted = _abort;
    mutex.unlock();

    if(!downloadFinished)
    {
        if(userAborted)
        {
            emit statusUpdateFile(id, _tableRow, tr("User Abbruch!"), 9);
            downloadFinished = true;
        }
        else
        {
            isDone(true);
        }
    }

    if(ftp)
    {
        ftp->blockSignals(true);
        ftp->clearPendingCommands();
        ftp->close();
        ftp->abort();
        ftp->deleteLater();
        ftp = nullptr;
    }

    if(file)
    {
        if(file->isOpen())
        {
            file->flush();
            file->close();
        }
        file->deleteLater();
        file = nullptr;
    }

    if(ftpLoop)
    {
        ftpLoop->deleteLater();
        ftpLoop = nullptr;
    }

    mutex.lock();
    _working = false;
    mutex.unlock();

    emit finished();
}

void FTPDownload::isDone(bool)
{
    if(downloadFinished) return;
    downloadFinished = true;

    mutex.lock();
    bool userAborted = _abort;
    mutex.unlock();

    if(userAborted)
    {
        emit statusUpdateFile(id, _tableRow, tr("User Abbruch!"), 9);
    }
    else if(ftp && ftp->error())
    {
        /*
        QFtp::NoError           0	No error occurred.
        QFtp::HostNotFound      2	The host name lookup failed.
        QFtp::ConnectionRefused	3	The server refused the connection.
        QFtp::NotConnected      4	Tried to send a command, but there is no connection to a server.
        QFtp::UnknownError      1	An error other than those specified above occurred.
        */

        if(ftp->error() == 1)
        {
            emit statusUpdateFile(id, _tableRow, tr("Unbekannter Fehler: ") + ftp->errorString(), 3);
        }
        else if(ftp->error() == 2)
        {
            emit statusUpdateFile(id, _tableRow, tr("Host nicht gefunden: ") + ftp->errorString(), 2);
        }
        else if(ftp->error() == 3)
        {
            emit statusUpdateFile(id, _tableRow, tr("Verbindung verweigert: ") + ftp->errorString(), 2);
        }
        else if(ftp->error() == 4)
        {
            emit statusUpdateFile(id, _tableRow, tr("Nicht verbunden: ") + ftp->errorString(), 2);
        }
        else
        {
            emit statusUpdateFile(id, _tableRow, tr("FTP Fehler!"), 2);
        }
    }
    else if(downloadTimeouted)
    {
        emit statusUpdateFile(id, _tableRow, tr("FTP Timeout!"), 2);
    }
    else
    {
        if(!m_isChunked)
        {
            emit statusUpdateFile(id, _tableRow, tr("Fertig!"), 10);
        }
        else
        {
            emit sendLogText(tr("[%1] Chunk %2 bis %3 fertig geladen!").arg(QFileInfo(*file).fileName(), QString::number(m_chunkStart), QString::number(m_chunkEnd)));
        }
    }

    if(file->isOpen())
    {
        file->flush();
        file->close();
    }

    mutex.lock();
    _working = false;
    mutex.unlock();
}

void FTPDownload::updateProgress(qint64 read, qint64 total)
{
    mutex.lock();
    bool aborted = _abort;
    bool working = _working;
    mutex.unlock();

    if(!working || aborted || read <= 0) return;

    if(m_isChunked)
    {
        emit doChunkProgress(id, _tableRow, m_chunkIndex, read, m_totalSize);

        qint64 currentAbsPos = m_chunkStart + read;
        if(m_chunkEnd > 0 && currentAbsPos >= m_chunkEnd)
        {
            mutex.lock();
            _working = false;
            mutex.unlock();

            if(ftp)
            {
                ftp->clearPendingCommands();
                ftp->abort();
            }

            if(ftpLoop && ftpLoop->isRunning())
            {
                ftpLoop->quit();
            }
        }
    }
    else
    {
        if(total > 0 && read >= total && !downloadFinished)
        {
            mutex.lock();
            bool finalAbortCheck = _abort;
            mutex.unlock();

            if(!finalAbortCheck)
            {
                isDone(true);
                return;
            }
        }

        emit doProgress(id, _tableRow, read, total, false, false);
    }
}





