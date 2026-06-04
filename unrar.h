#ifndef UNRAR_H
#define UNRAR_H

#include <QObject>
#include <QProcess>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QMutex>

#ifdef QT_DEBUG
    #include <QDebug>
#endif

class UnRAR : public QObject
{
    Q_OBJECT

public:
    explicit UnRAR(QStringList data);
    ~UnRAR();
    QString id;

signals:
    void finished();
    void updateUnRarProgress(QString id, QString fileName, int progress);
    void error(const QString& message);

public slots:
    void startUnRAR();

private slots:
    void ReadOut();

private:
    QProcess *p;
    QStringList data;

    QString m_program;
    QStringList m_arguments;

    QString file;     // file to extract
    QString destPath; // extract destination

    QString unar;     // unrar location
    QString command;  // unrar command(s)

    QString fileName; // current extracting
    int progress;

    QMutex mutex;

};

#endif // UNRAR_H
