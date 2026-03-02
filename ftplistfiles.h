#ifndef FTPLISTFILES_H
#define FTPLISTFILES_H

#include "ftpclient.h"
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
    FtpClient *ftp = nullptr;
    bool connected = false;
    QString baseIP;
    int basePort;
    QString baseUser;
    QString basePass;
    QString basePath;
    QStringList pathList;
    QStringList fileList;
    QString baseSFDL;
    QNetworkProxy proxy;
    QString lastCdPath;
    QString proxyHostValue;
    QString proxyPortValue;
    QString proxyUserValue;
    QString proxyPassValue;

public slots:
    void ftpList(QString ip, int port, QString user, QString pass, QString path,
                            QString proxyHost, QString proxyPort, QString proxyUser, QString proxyPass, QStringList data);

private slots:
    void getFTPIndex(QString ip, int port, QString user, QString pass, QString path);

signals:
    void sendWarning(QString label, QString text);
    void sendLogText(QString text);
    void sendFTPData(QStringList data, QStringList files);
};

#endif // FTPLISTFILES_H
