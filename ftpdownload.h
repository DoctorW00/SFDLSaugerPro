#ifndef FTPDOWNLOAD_H
#define FTPDOWNLOAD_H

#include <QObject>
#include <QMutex>
#include <QtFtp/QFtp>
#include <QFile>
#include <QDir>
#include <QTcpSocket>
#include <QEventLoop>
#include <QNetworkProxy>

#ifdef QT_DEBUG
    #include <QDebug>
#endif

#include <QElapsedTimer>
#include <QThread>
#include "settings.h"

class ThrottledFile : public QFile
{
public:
    ThrottledFile(qint64 bytesPerSecond = 0)
        : m_bytesPerSecond(bytesPerSecond), m_bytesWrittenInWindow(0)
    {
        m_timer.start();
    }

    void setSpeedLimit(qint64 bytesPerSecond)
    {
        m_bytesPerSecond = bytesPerSecond;
    }

protected:
    qint64 writeData(const char *data, qint64 len) override
    {
        m_bytesPerSecond = Settings::_globalSpeedLimitBytes;

        if(m_bytesPerSecond <= 0)
        {
            return QFile::writeData(data, len);
        }

        qint64 written = 0;
        qint64 chunkSize = 4096;

        while(written < len)
        {
            qint64 toWrite = qMin(chunkSize, len - written);
            qint64 result = QFile::writeData(data + written, toWrite);

            if(result <= 0) return written > 0 ? written : result;

            written += result;
            m_bytesWrittenInWindow += result;

            qint64 elapsed = m_timer.elapsed();
            if(elapsed > 0)
            {
                qint64 allowedBytes = (m_bytesPerSecond * elapsed) / 1000;

                if(m_bytesWrittenInWindow > allowedBytes)
                {
                    qint64 expectedTime = (m_bytesWrittenInWindow * 1000) / m_bytesPerSecond;
                    qint64 sleepTime = expectedTime - elapsed;

                    if(sleepTime > 0)
                    {
                        QThread::msleep(static_cast<unsigned long>(sleepTime));
                    }
                }
            }

            if (m_timer.elapsed() > 1000)
            {
                m_timer.restart();
                m_bytesWrittenInWindow = 0;
            }
        }

        return written;
    }

private:
    qint64 m_bytesPerSecond;
    qint64 m_bytesWrittenInWindow;
    QElapsedTimer m_timer;
};

class FTPDownload : public QObject
{
    Q_OBJECT

public:
    FTPDownload(QStringList data);
    ~FTPDownload();
    bool _abort;
    bool _working;
    int _tableRow = -1;
    QString _id;

    // chunk downloads
    int m_chunkIndex;
    bool m_isChunked = false;
    bool m_isMasterChunk = false;
    qint64 m_chunkStart = 0;
    qint64 m_chunkEnd = 0;
    qint64 m_totalSize = 0;
    bool m_remove_file = false;

public slots:
    void process();
    void abort();

private slots:
    void isDone(bool);
    void updateProgress(qint64, qint64);
    void finishedDownload();

signals:
    void finished();
    void error(QString err);
    void statusUpdateFile(QString id, int tableRow, QString statusMsg, int status);
    void doProgress(QString id, int tableRow, qint64 read, qint64 total, bool overwriteTime, bool firstUpdate);
    void doChunkProgress(QString tabID, int nRow, int chunkIndex, qint64 chunkRead, qint64 totalSize);
    void sendLogText(QString txt);

private:
    QFtp *ftp;
    QStringList data;
    // QFile *file;
    ThrottledFile *file;
    QEventLoop *ftpLoop;
    QMutex mutex;
    QString id;
    QString host;
    QString port;
    QString user;
    QString pass;
    QString dir;
    QString dlpath;
    QString dlfile;
    int tableRow;
    QNetworkProxy proxy;
    bool downloadFinished = false;
    bool downloadTimeouted = false;

};

#endif // FTPDOWNLOAD_H
