#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QNetworkProxy>
#include <QFile>
#include <QElapsedTimer>

class FtpClient : public QObject
{
    Q_OBJECT

public:
    explicit FtpClient(QObject *parent = nullptr);

    void setProxy(const QNetworkProxy& proxy);
    void setTimeoutMs(int timeoutMs);
    bool isConnected() const;

    bool connectToHost(const QString& host, int port, QString* error = nullptr);
    bool login(const QString& user, const QString& pass, QString* error = nullptr);
    bool cwd(const QString& path, QString* error = nullptr);
    bool list(const QString& path, QStringList* lines, QString* error = nullptr);
    bool size(const QString& path, qint64* size, QString* error = nullptr);
    bool retr(const QString& path, QFile* file, qint64 resumeFrom, qint64* totalSize, QString* error = nullptr);
    void quit();
    void abort();

signals:
    void dataTransferProgress(qint64 read, qint64 total);

private:
    bool sendCommand(const QString& cmd, int* code, QStringList* lines, QString* error = nullptr);
    bool readResponse(int* code, QStringList* lines, QString* error = nullptr);
    bool openPassiveDataSocket(QTcpSocket*& dataSocket, QString* error = nullptr);
    bool openEpsvDataSocket(QTcpSocket*& dataSocket, QString* error = nullptr);
    bool waitForSocketReady(QTcpSocket* socket, int timeoutMs, QString* error);

    bool isPrivateAddress(const QString& ip) const;
    QString controlHost;
    QTcpSocket* controlSocket = nullptr;
    QNetworkProxy proxy = QNetworkProxy::NoProxy;
    int timeoutMs = 15000;
    bool aborted = false;
};

#endif // FTPCLIENT_H
