#include "filewatcher.h"
#include <QFileInfoList>

FileWatcher::FileWatcher(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &FileWatcher::checkFolder);
}

void FileWatcher::start(const QString &path, const QString &extension, int intervalMs)
{
    m_watchPath = path;
    m_extension = extension;

    m_knownFiles.clear();
    QDir dir(m_watchPath);
    for(const QFileInfo &info : dir.entryInfoList({ "*" + m_extension }, QDir::Files))
    {
        m_knownFiles.insert(info.absoluteFilePath());
    }

    m_timer->start(intervalMs);
    emit statusChanged(true);
}

void FileWatcher::stop()
{
    m_timer->stop();
    emit statusChanged(false);
}

void FileWatcher::setInterval(int ms)
{
    if (m_timer->isActive()) m_timer->start(ms);
    else m_timer->setInterval(ms);
}

void FileWatcher::setPath(const QString &path)
{
    m_watchPath = path;
    m_knownFiles.clear();
}

void FileWatcher::checkFolder()
{
    QDir dir(m_watchPath);
    if (!dir.exists()) return;

    QFileInfoList currentFiles = dir.entryInfoList({ "*" + m_extension }, QDir::Files);
    for(const QFileInfo &fileInfo : qAsConst(currentFiles))
    {
        QString fullPath = fileInfo.absoluteFilePath();
        if(!m_knownFiles.contains(fullPath))
        {
            m_knownFiles.insert(fullPath);
            emit fileDetected(fullPath);
        }
    }
}
