#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QString>
#include <QSet>
#include <QTimer>
#include <QDir>

class FileWatcher : public QObject {
    Q_OBJECT
public:
    explicit FileWatcher(QObject *parent = nullptr);

signals:
    void fileDetected(const QString &filePath);
    void statusChanged(bool running);

public slots:
    void start(const QString &path, const QString &extension, int intervalMs = 2000);
    void stop();
    void setInterval(int ms);
    void setPath(const QString &path);

private slots:
    void checkFolder();

private:
    QString m_watchPath;
    QString m_extension;
    QTimer *m_timer;
    QSet<QString> m_knownFiles;
};

#endif
