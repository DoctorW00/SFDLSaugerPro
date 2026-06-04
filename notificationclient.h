#ifndef NOTIFICATIONCLIENT_H
#define NOTIFICATIONCLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QUrl>
#include <QSslSocket>

class Settings;

class NotificationClient : public QObject
{
    Q_OBJECT

public:
    explicit NotificationClient(Settings *settings, QObject *parent = nullptr);
    ~NotificationClient();
    enum Service { Pushsafer, Pushover, Email };
    void sendMessage(Service service, const QString &title, const QString &message);

signals:
    void sendLogText(QString text);

private slots:
    void onReplyFinished(QNetworkReply *reply);
    void sendEmail(const QString &title, const QString &message);

private:
    QNetworkAccessManager *m_manager;
    Settings *m_settings;

};

#endif
