#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QObject>
#include <QString>
#include <QMutex>
#include <QStringList>
#include "httplib.h"

class WebServerWorker : public QObject
{
    Q_OBJECT

public:
    WebServerWorker(QString host = "0.0.0.0", int port = 8080, QObject *parent = nullptr);
    ~WebServerWorker();

public slots:
    void process();
    void stop();
    void addLogText(QString txt);

signals:
    void xmlReceived(QString content, QString fileName);
    void finished();
    void sendLogText(QString txt);

private:
    httplib::Server svr;
    QString m_host;
    int m_port;
    QStringList m_logEntries;
    QMutex m_logMutex;

};
#endif
