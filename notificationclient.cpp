#include "notificationclient.h"
#include "settings.h"

NotificationClient::NotificationClient(Settings *settings, QObject *parent) : QObject(parent), m_settings(settings)
{
    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, &QNetworkAccessManager::finished, this, &NotificationClient::onReplyFinished);
}

NotificationClient::~NotificationClient() {}

void NotificationClient::sendMessage(Service service, const QString &title, const QString &message)
{
    QUrl url;
    QUrlQuery params;

    if(service == Pushover)
    {
        url = QUrl("https://api.pushover.net/1/messages.json");
        params.addQueryItem("token", m_settings->_pushover_token.trimmed());
        params.addQueryItem("user", m_settings->_pushover_user.trimmed());
        params.addQueryItem("title", title);
        params.addQueryItem("message", message);
    }

    if(service == Pushsafer)
    {
        url = QUrl("https://www.pushsafer.com/api");
        params.addQueryItem("k", m_settings->_pushsafer_token.trimmed());
        params.addQueryItem("t", title);
        params.addQueryItem("m", message);
    }

    if(service == Email)
    {
        sendEmail(title, message);
        return;
    }

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    m_manager->post(request, params.query(QUrl::FullyEncoded).toUtf8());
}

void NotificationClient::onReplyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        emit sendLogText("Notification OK: Nachricht gesendet.");
    }
    else
    {
        QByteArray errorData = reply->readAll();
        emit sendLogText("Notification Error: " + reply->errorString() + " Details: " + errorData);
    }
    reply->deleteLater();
}

void NotificationClient::sendEmail(const QString &title, const QString &message)
{
    QString host = m_settings->_email_host.trimmed();
    int port = m_settings->_email_port.toInt();
    QString user = m_settings->_email_username.trimmed();
    QString pass = m_settings->_email_password.trimmed();
    QString receiver = m_settings->_email_rcv_mailadress.trimmed();

    QSslSocket *socket = new QSslSocket(this);

    auto getResponse = [&]() -> QByteArray {
        if (!socket->waitForReadyRead(5000)) return QByteArray();
        QByteArray response = socket->readAll();
        emit sendLogText("SMTP Server: " + response.trimmed());
        return response;
    };

    auto sendAndCheck = [&](const QByteArray &cmd, const QByteArray &expectedCode) -> bool {
        socket->write(cmd + "\r\n");
        if (!socket->waitForBytesWritten(2000)) return false;
        QByteArray res = getResponse();
        return res.startsWith(expectedCode);
    };

    socket->connectToHostEncrypted(host, port);
    if(!socket->waitForEncrypted(5000))
    {
        emit sendLogText("SMTP Error: SSL Verbindung fehlgeschlagen: " + socket->errorString());
        socket->deleteLater();
        return;
    }

    if(!getResponse().startsWith("220"))
    {
        emit sendLogText("SMTP Error: Server meldet sich nicht korrekt.");
        socket->abort();
        socket->deleteLater();
        return;
    }

    if(!sendAndCheck("EHLO localhost", "250"))
    {
        emit sendLogText("SMTP Error: EHLO fehlgeschlagen.");
        goto cleanup;
    }

    if(!sendAndCheck("AUTH LOGIN", "334"))
    {
        emit sendLogText("SMTP Error: AUTH LOGIN nicht unterstützt.");
        goto cleanup;
    }

    if(!sendAndCheck(user.toUtf8().toBase64(), "334"))
    {
        emit sendLogText("SMTP Error: Benutzername abgelehnt.");
        goto cleanup;
    }

    if (!sendAndCheck(pass.toUtf8().toBase64(), "235")) {
        emit sendLogText("SMTP Error: Login fehlgeschlagen (Bad Login).");
        goto cleanup;
    }


    sendAndCheck("MAIL FROM:<" + user.toUtf8() + ">", "250");
    sendAndCheck("RCPT TO:<" + receiver.toUtf8() + ">", "250");

    if(!sendAndCheck("DATA", "354"))
    {
        emit sendLogText("SMTP Error: DATA Kommando abgelehnt.");
        goto cleanup;
    }
    else
    {
        QByteArray content;
        content += "From: " + user.toUtf8() + "\r\n";
        content += "To: " + receiver.toUtf8() + "\r\n";
        content += "Subject: " + title.toUtf8() + "\r\n";
        content += "\r\n";
        content += message.toUtf8() + "\r\n.\r\n";

        if(!sendAndCheck(content, "250"))
        {
            emit sendLogText("SMTP Error: E-Mail Inhalt abgelehnt.");
            goto cleanup;
        }
    }

    sendAndCheck("QUIT", "221");
    emit sendLogText("Notification OK: Email an " + receiver + " gesendet.");

cleanup:
    socket->disconnectFromHost();
    socket->deleteLater();
}

