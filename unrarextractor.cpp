#include "unrarextractor.h"
#include "dll.hpp"
#include "rar.hpp"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QCoreApplication>
#include <QMetaObject>
#include <QThread>
#include <QTimer>

#ifdef Q_OS_WIN
#include <windows.h>
#endif

#ifndef ROADF_UNICODE
#define ROADF_UNICODE 0x0002
#endif

#ifndef ERAR_END_OF_ARCHIVE
#define ERAR_END_OF_ARCHIVE 10
#endif

UnrarExtractor::UnrarExtractor(QStringList data) : data(data)
{
    id = this->data.at(0);
    RARfile = this->data.at(1);
    DestPath = this->data.at(2);
}

UnrarExtractor::~UnrarExtractor(){}

void UnrarExtractor::startUnRAR()
{
    extractArchive(RARfile, DestPath);
}

bool UnrarExtractor::extractArchive(const QString& rarPath, const QString& targetDir)
{
    QString nativeRarPath = QDir::toNativeSeparators(rarPath);
    QString nativeTargetDir = QDir::toNativeSeparators(targetDir);

    RAROpenArchiveDataEx listArchiveData;
    memset(&listArchiveData, 0, sizeof(listArchiveData));

#ifdef Q_OS_WIN
    std::wstring wListPath = nativeRarPath.toStdWString();
    listArchiveData.ArcNameW = const_cast<wchar_t*>(wListPath.c_str());
    listArchiveData.Flags = ROADF_UNICODE;
#else
    QByteArray listPathLocal = QFile::encodeName(nativeRarPath);
    listArchiveData.ArcName = const_cast<char*>(listPathLocal.constData());
#endif

    listArchiveData.OpenMode = RAR_OM_LIST;
    listArchiveData.Callback = UnrarExtractor::unrarCallback;
    listArchiveData.UserData = reinterpret_cast<LPARAM>(this);

    HANDLE hArcList = RAROpenArchiveEx(&listArchiveData);
    if(listArchiveData.OpenResult != ERAR_SUCCESS)
    {
        emit error(tr("Konnte RAR nicht für die Berechnung der Größe öffnen!"));
        return false;
    }

    RARHeaderDataEx listHeader;
    memset(&listHeader, 0, sizeof(listHeader));
    totalBytes = 0;

    while(RARReadHeaderEx(hArcList, &listHeader) == ERAR_SUCCESS)
    {
        quint64 fileSize = static_cast<quint64>(listHeader.UnpSize) + (static_cast<quint64>(listHeader.UnpSizeHigh) << 32);
        totalBytes += fileSize;
        RARProcessFile(hArcList, RAR_SKIP, nullptr, nullptr);
    }
    RARCloseArchive(hArcList);

    RAROpenArchiveDataEx archiveData;
    memset(&archiveData, 0, sizeof(archiveData));

#ifdef Q_OS_WIN
    std::wstring wPath = nativeRarPath.toStdWString();
    archiveData.ArcNameW = const_cast<wchar_t*>(wPath.c_str());
    archiveData.Flags = ROADF_UNICODE;
#else
    QByteArray rarPathLocal = QFile::encodeName(nativeRarPath);
    archiveData.ArcName = const_cast<char*>(rarPathLocal.constData());
#endif

    archiveData.OpenMode = RAR_OM_EXTRACT;
    archiveData.Callback = UnrarExtractor::unrarCallback;
    archiveData.UserData = reinterpret_cast<LPARAM>(this);

    HANDLE hArc = RAROpenArchiveEx(&archiveData);

    if(archiveData.OpenResult != ERAR_SUCCESS)
    {
        emit error(QString(tr("Archive Fehler: %1")).arg(archiveData.OpenResult));
        return false;
    }

    RARSetCallback(hArc, UnrarExtractor::unrarCallback, reinterpret_cast<LPARAM>(this));

    int result;
    RARHeaderDataEx header;
    memset(&header, 0, sizeof(header));
    cumulativeBytes = 0;

    QByteArray targetDirLocal = QFile::encodeName(nativeTargetDir);

    while((result = RARReadHeaderEx(hArc, &header)) == ERAR_SUCCESS)
    {
#ifdef Q_OS_WIN
        currentFileName = QString::fromWCharArray(header.FileNameW);
#else
        currentFileName = QString::fromLocal8Bit(header.FileName);
#endif
        currentFileTotalBytes = static_cast<quint64>(header.UnpSize) + (static_cast<quint64>(header.UnpSizeHigh) << 32);
        currentFileProcessedBytes = 0;

        int processResult = RARProcessFile(hArc, RAR_EXTRACT, const_cast<char*>(targetDirLocal.constData()), nullptr);
        QThread::msleep(10);

        if(processResult != ERAR_SUCCESS)
        {
            RARCloseArchive(hArc);
            emit error(QString(tr("UnRAR auspacken error: %1")).arg(processResult));
            return false;
        }

        currentFileName.clear();
        currentFileTotalBytes = 0;
    }

    RARCloseArchive(hArc);

    if(result != ERAR_END_OF_ARCHIVE)
    {
        emit error(QString(tr("UnRAR Archive Fehler: %1")).arg(result));
        return false;
    }

    emit finished();
    return true;
}

void UnrarExtractor::handleProgressUpdate()
{
    int progress = 0;
    if(totalBytes > 0)
    {
        progress = static_cast<int>((static_cast<double>(cumulativeBytes) / totalBytes * 100));
    }
    emit updateUnRarProgress(id, currentFileName, progress);
}

/*
int CALLBACK UnrarExtractor::unrarCallback(UINT msg, LPARAM userData, LPARAM p1, LPARAM p2)
{
    auto extractor = reinterpret_cast<UnrarExtractor*>(userData);
    if(extractor == nullptr)
    {
        return -1;
    }

    switch(msg)
    {
    case UCM_PROCESSDATA:
        p1;
        extractor->currentFileProcessedBytes += p2;
        extractor->cumulativeBytes += p2;

        QMetaObject::invokeMethod(
            extractor,
            "handleProgressUpdate",
            Qt::QueuedConnection
            );

        QCoreApplication::processEvents();
        break;

    case UCM_NEEDPASSWORD:
        emit extractor->error(tr("Passwortgeschützte RAR Dateien werden nicht unterstützt!"));
        return -1;

    case UCM_CHANGEVOLUMEW:
    case UCM_CHANGEVOLUME:
        return 1;
    }

    return 0;
}
*/

int UnrarExtractor::unrarCallback(UINT msg, LPARAM userData, LPARAM p1, LPARAM p2)
{
    auto extractor = reinterpret_cast<UnrarExtractor*>(userData);
    if (!extractor) return -1;

    switch (msg)
    {
    case UCM_PROCESSDATA:
        extractor->currentFileProcessedBytes += p2;
        extractor->cumulativeBytes += p2;

        {
            QMutexLocker locker(&extractor->mutex);

            int progress = 0;
            if (extractor->currentFileTotalBytes > 0) {
                progress = static_cast<int>(
                    (extractor->currentFileProcessedBytes * 100) / extractor->currentFileTotalBytes
                    );
            }

            emit extractor->updateUnRarProgress(
                extractor->id,
                extractor->currentFileName,
                progress
                );
        }
        break;

    case UCM_NEEDPASSWORD:
        emit extractor->error(QObject::tr("Passwortgeschützte RAR Dateien werden nicht unterstützt!"));
        return -1;

    case UCM_CHANGEVOLUMEW:
    case UCM_CHANGEVOLUME:
        return 1;
    }

    return 0;
}

