#ifndef SFDLSAUGER_H
#define SFDLSAUGER_H

#include "sfdl.h"
#include "data.h"
#include "ftplistfiles.h"
#include "ftpdownload.h"
#include "about.h"
#include "settings.h"
#include "crc32.h"
#include "unrar.h"

#include <QMainWindow>
#include <QtWidgets>
#include <QObject>
#include <QInputDialog>
#include <QHostAddress>
#include <QRegExp>
#include <QThread>
#include <QDesktopWidget>

#ifdef QT_DEBUG
    #include <QDebug>
#endif

namespace Ui
{
    class SFDLSauger;
}

class SFDLSauger : public QMainWindow
{
    Q_OBJECT

public:
    explicit SFDLSauger(QWidget *parent = 0);
    ~SFDLSauger();

public slots:
    void loadSFDL(QString file);
    void loadSFDLConsol(int instanceId, QByteArray message);

private slots:
    void addLogText(QString txt);
    int addTab(QString tabText);
    void chkSFDLData(QStringList data, QStringList files);
    void getSFDLData(QStringList data, QStringList files);
    void on_tabWidget_tabCloseRequested(int index);
    void MsgWarning(QString label, QString text);
    QString bytes2Human(float filesize);
    QString seconds_to_DHMS(int duration);
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);
    void closeEvent(QCloseEvent *e);
    void quitApp();
    void on_action_ffnen_triggered();
    void on_actionBeenden_triggered();
    void tabSelected();
    void on_actionLogs_anzeigen_triggered();
    void on_actionEinstellungen_triggered();
    void on_action_ber_triggered();
    void devModeSwitch();
    QString checkSameDownloads(QString name);
    void fileTableDoubleClicked(int row, int column);
    void openCloseSFDLTable();
    void openFileExplorer();
    void chkForExisitingFiles(QString id);
    void updateTotalDownloadSize(QString id);
    void tblItemChanged(QTableWidgetItem *item);
    void changeCHKBOX(QString id, bool lock);
    void saveWindowStatus();
    void loadWindowStatus();

    // ftp downloads
    void startDownloadButton();
    void swapStartStopButton(QString id);
    void disableStartStopButton(QString id);
    void startDownload(QString tabID);
    void stopDownload();
    bool allDownloadsDone(QString id);
    void createSpeedreport(QString id);
    void crc32Check(QString id);
    void updateCRC32(QString id, int nRow, QString crc32Data);
    void sfvCheck(QString id);
    QStringList dirFromFilePath(QString filePath);
    void updateDownloadProgress(QString tabID, int nRow, qint64 read, qint64 total, bool overwriteTime, bool firstUpdate);
    void updateDownloadFileStatus(QString tabID, int nRow, QString statusMsg, int status);
    void downloadError(QString error);

    // unrar
    void unrarFiles(QString id);
    void unrarProgressUpdate(QString id, QString fileName, int progress);
    void unrarDeleteFiles(QString id);

    // ftp clients
    void openInFileZilla();

private:
    Ui::SFDLSauger *ui;
    QList<SFDL> sfdlData;
    int maxTabTextLength = 32;
    QFont defaultFont;
    QWidget *widget;
    bool devMode = false;
    QSystemTrayIcon *icon;
    int g_sessionID = 0;
    About *infoWindow;
    Settings *settingsWindow;
    qint64 g_lastProgressUpdate;

    // ftp downloads
    QList<QThread*> g_Threads;
    QList<FTPDownload*> g_Worker;
    int g_runningDownloads = 0;
    int g_maxDownloads = 10;
    QMap<QString, int> g_tabDownloads;

    // ftp clients
    QString g_FILEZILLA;

    // global settings
    /*
    QString g_downloadRootPath;
    bool g_crc32Check;
    bool g_sfvCheck;
    QString g_unrarPath;
    bool g_unrarAutoEtract;
    bool g_unrarAutoDelete;
    QStringList g_sfdlPasswords;
    QString g_ftpProxyHost;
    QString g_ftpProxyPort;
    QString g_ftpProxyUser;
    QString g_ftpProxyPass;
    */
};

#endif // SFDLSAUGER_H
