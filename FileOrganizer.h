#include <QObject>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>
#include <QDebug>

class FileOrganizer : public QObject
{
    Q_OBJECT

public:
    explicit FileOrganizer(const QString& workPath, const QString& title, QObject* parent = nullptr)
        : QObject(parent), m_workPath(workPath), m_title(title) {}

    bool reorganizeFiles()
    {
        QString srrApiUrl = QString("https://api.srrdb.com/v1/details/%1").arg(m_title);

        QNetworkAccessManager manager;
        QNetworkRequest request((QUrl(srrApiUrl)));
        QNetworkReply* reply = manager.get(request);

        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        if(reply->error() != QNetworkReply::NoError)
        {
            qDebug() << "API request failed:" << reply->errorString();
            reply->deleteLater();
            return false;
        }

        QByteArray jsonData = reply->readAll();
        reply->deleteLater();

        QJsonDocument doc = QJsonDocument::fromJson(jsonData);
        if(doc.isNull())
        {
            qDebug() << "Invalid JSON response";
            return false;
        }

        QJsonObject root = doc.object();
        QJsonArray archivedFiles = root.value("archived-files").toArray();
        if(archivedFiles.isEmpty())
        {
            qDebug() << "No archived-files found in JSON";
            return false;
        }

        QMap<QString, bool> expectedPaths;
        for(const QJsonValue& val : archivedFiles)
        {
            QJsonObject fileObj = val.toObject();
            QString name = fileObj.value("name").toString().replace("\\", "/");
            qint64 size = fileObj.value("size").toVariant().toLongLong();
            expectedPaths.insert(name, size == 0);
        }

        QDir workDir(m_workPath);
        QStringList currentFiles = workDir.entryList(QDir::Files | QDir::NoDotAndDotDot);

        for(auto it = expectedPaths.constBegin(); it != expectedPaths.constEnd(); ++it)
        {
            if(!it.value())
            {
                QString fileName = QFileInfo(it.key()).fileName();
                if(!currentFiles.contains(fileName))
                {
                    QString fullPath = workDir.absoluteFilePath(it.key());
                    QFileInfo check_file(fullPath);
                    if(!check_file.exists() && !check_file.isFile())
                    {
                        qDebug() << "Missing file: " << fileName;
                        return false;
                    }
                }
            }
        }

        for(const QString& path : expectedPaths.keys())
        {
            QString fullPath = workDir.absoluteFilePath(path);

            if(expectedPaths[path])
            {
                QDir dir(fullPath);
                if(!dir.exists() && !workDir.mkpath(path))
                {
                    qDebug() << "Failed to create directory: " << path;
                    return false;
                }
            }
            else
            {
                QString baseName = QFileInfo(path).fileName();
                QString srcPath = workDir.absoluteFilePath(baseName);

                // src and dest = same
                if(QFileInfo(srcPath) == QFileInfo(fullPath))
                {
                    continue;
                }

                // file already in position
                QFileInfo check_file(fullPath);
                if(check_file.exists() && check_file.isFile())
                {
                    continue;
                }

                // move file to dest
                if(!QFile::rename(srcPath, fullPath))
                {
                    qDebug() << "Failed to move file: " << path
                             << "(from" << srcPath << "to" << fullPath << ")";
                    return false;
                }
            }
        }

        return true;
    }

private:
    QString m_workPath;
    QString m_title;
};
