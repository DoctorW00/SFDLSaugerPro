#include "webserver.h"
#include <QUrl>
#include <QFileInfo>
#include <QBuffer>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

WebServerWorker::WebServerWorker(QString host, int port, QObject *parent) : QObject(parent), m_host(host), m_port(port) {}
WebServerWorker::~WebServerWorker() { stop(); }

void WebServerWorker::process()
{
    svr.set_payload_max_length(5 * 1024 * 1024);
    svr.set_read_timeout(5, 0);

    svr.Get("/", [](const httplib::Request& /*req*/, httplib::Response& res) {
        QFile htmlFile(":/html/index.html");
        QFile imgFile(":/gfx/icon.png");

        if(htmlFile.open(QIODevice::ReadOnly))
        {
            QString htmlContent = QString::fromUtf8(htmlFile.readAll());

            if(imgFile.open(QIODevice::ReadOnly))
            {
                QByteArray imageData = imgFile.readAll();
                QString base64Image = "data:image/png;base64," + imageData.toBase64();

                htmlContent.replace("%%LOGO_BASE64%%", base64Image);
            }

            res.status = 200;
            res.set_content(htmlContent.toStdString(), "text/html; charset=utf-8");
        }
        else
        {
            res.status = 404;
            res.set_content(tr("Seite nicht gefunden!").toStdString(), "text/plain");
        }
    });

    svr.Post("/xml-api", [this](const httplib::Request& req, httplib::Response& res) {
        if(!req.body.empty())
        {
            QString fileName = "unnamed.sfdl";

            if(req.has_header("X-File-Name"))
            {
                QString rawName = QString::fromStdString(req.get_header_value("X-File-Name"));
                fileName = QUrl::fromPercentEncoding(rawName.toUtf8());
                fileName = QString::fromStdString(httplib::sanitize_filename(fileName.toStdString()));
                if(fileName.isEmpty()) fileName = "unnamed.sfdl";
            }

            if(!fileName.toLower().endsWith(".sfdl"))
            {
                res.status = 415; // 415 = unsupported media type
                res.set_content(tr("Ungültiges Dateiformat. Nur .sfdl erlaubt.").toStdString(), "text/plain");
                return;
            }

            emit xmlReceived(QString::fromStdString(req.body), fileName);

            res.status = 200;
            res.set_content(tr("Datei erfolgreich verarbeitet").toStdString(), "text/plain");
        }
        else
        {
            res.status = 400;
            res.set_content(tr("Datei war leer oder beschädigt").toStdString(), "text/plain");
        }
    });

    svr.Get("/api/logs", [this](const httplib::Request&, httplib::Response& res) {
        QJsonArray jsonArray;

        {
            QMutexLocker locker(&m_logMutex);
            for(const QString &log : m_logEntries)
            {
                jsonArray.append(log);
            }
        }

        QJsonDocument doc(jsonArray);
        res.status = 200;
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content(doc.toJson(QJsonDocument::Compact).toStdString(), "application/json");
    });

    auto deliverIcon = [](const httplib::Request&, httplib::Response& res) {
        QFile imgFile(":/gfx/icon.png");
        if(imgFile.open(QIODevice::ReadOnly))
        {
            res.set_content(imgFile.readAll().toStdString(), "image/png");
        }
        else
        {
            res.status = 404;
        }
    };

    svr.Get("/favicon.ico", deliverIcon);
    svr.Get("/apple-touch-icon.png", deliverIcon);

    svr.set_error_handler([](const httplib::Request& req, httplib::Response& res) {
        auto fmt = "<p>Error Status: <span style='color:red;'>%d</span></p>";
        char buf[BUFSIZ];
        snprintf(buf, sizeof(buf), fmt, res.status);
        res.set_content(buf, "text/html");
    });

    QString niceHost = "localhost";
    if(m_host != "0.0.0.0")
    {
        niceHost = m_host;
    }

    svr.set_exception_handler([](const httplib::Request& req, httplib::Response& res, std::exception_ptr ep) {
        auto fmt = "<h1>Error 500</h1><p>%s</p>";
        char buf[BUFSIZ];
        try {
            std::rethrow_exception(ep);
        } catch (std::exception &e) {
            snprintf(buf, sizeof(buf), fmt, e.what());
        } catch (...) {
            snprintf(buf, sizeof(buf), fmt, "Unknown Exception");
        }
        res.set_content(buf, "text/html");
        res.status = httplib::StatusCode::InternalServerError_500;
    });

    emit sendLogText(tr("Webserver gestartet <a href=\"http://%1:%2" "/\">http://%1:%2/</a>").arg(niceHost, QString::number(m_port)));
    std::string hostStr = m_host.toStdString();
    int port = m_port;
    std::thread([this, hostStr, port]() {
        if(!svr.listen(hostStr.c_str(), port))
        {
            emit sendLogText(tr("FEHLER: Port %1 belegt.").arg(QString::number(port)));
        }
        emit sendLogText(tr("Webserver wurde beendet."));
        emit finished();
    }).detach();

}

void WebServerWorker::stop()
{
    if(svr.is_running())
    {
        svr.stop();
    }
}

void WebServerWorker::addLogText(QString txt)
{
    QMutexLocker locker(&m_logMutex);
    m_logEntries.append(txt);
    while(m_logEntries.size() > 100)
    {
        m_logEntries.removeFirst();
    }
}
