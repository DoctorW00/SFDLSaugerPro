#ifndef UNRAR_H
#define UNRAR_H

#include <QObject>
#include <QProcess>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#ifdef QT_DEBUG
    #include <QDebug>
#endif

class UnRAR : public QObject
{
    Q_OBJECT

public:
    explicit UnRAR(QStringList data);
    ~UnRAR();

signals:
    void finished();
    void updateUnRarProgress(QString id, QString fileName, int progress);

public slots:
    void startUnRAR();

private slots:
    void ReadOut();
    void ReadErr();

private:
    QProcess *p;
    QStringList data;

    QString id;
    QString file;     // file to extract
    QString destPath; // extract destination

    QString unar;     // unrar location
    QString command;  // unrar command(s)

    QString fileName; // current extracting
    int progress;

};

#endif // UNRAR_H
