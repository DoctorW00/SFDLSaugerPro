#ifndef UNRAREXTRACTOR_H
#define UNRAREXTRACTOR_H

#include <QObject>
#include <QString>
#include <QFileInfo>
#include <QMutex>

#ifdef Q_OS_WIN
#include <windows.h>
#else
typedef unsigned int UINT;
typedef long LPARAM;
#endif

class UnrarExtractor : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(UnrarExtractor)

public:
    explicit UnrarExtractor(QStringList data);
    ~UnrarExtractor();
    QString id;

public slots:
    void startUnRAR();

private slots:
    bool extractArchive(const QString& rarPath, const QString& targetDir);
    void handleProgressUpdate();

signals:
    void finished();
    void updateUnRarProgress(QString id, QString fileName, int progress);
    void error(const QString& message);

private:
    static int unrarCallback(UINT msg, LPARAM userData, LPARAM p1, LPARAM p2);
    quint64 totalBytes = 0;
    quint64 cumulativeBytes = 0;
    QString currentFileName;
    quint64 currentFileTotalBytes = 0;
    quint64 currentFileProcessedBytes = 0;
    QString RARfile;
    QString DestPath;
    QMutex mutex;
    QStringList data;
};

#endif // UNRAREXTRACTOR_H
