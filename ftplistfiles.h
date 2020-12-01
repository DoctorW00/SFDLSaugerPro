#ifndef FTPLISTFILES_H
#define FTPLISTFILES_H

#include <QTimer>
#include <QEventLoop>
#include <QtFtp/QFtp>
#include <QNetworkProxy>

#ifdef QT_DEBUG
    #include <QDebug>
#endif

class FTPListFiles : public QObject
{
    Q_OBJECT

public:
    explicit FTPListFiles(QObject *parent = nullptr);

private:
    QFtp *ftp;
    QTimer *timer;
    QEventLoop *loop;
    QString baseIP;
    int basePort;
    QString baseUser;
    QString basePass;
    QString basePath;
    QStringList pathList;
    QStringList fileList;
    QString baseSFDL;
    QNetworkProxy proxy;

public slots:
    QStringList ftpList(QString ip, int port, QString user, QString pass, QString path, QString SFDL,
                        QString proxyHost, QString proxyPort, QString proxyUser, QString proxyPass);

private slots:
    void setFTP();
    void ftpTimeout();
    void ftpRawCommandReply(int code, const QString & cmd);
    void ftpCommandStarted(int id);
    void ftpCommandFinished(int, bool error);
    void ftpstateChanged(int state);
    void doListInfo(const QUrlInfo& info);
    void isDone(bool);
    void getFTPIndex(QString ip, int port, QString user, QString pass, QString path);

signals:
    void sendWarning(QString label, QString text);
    void sendLogText(QString text);
};

#endif // FTPLISTFILES_H
