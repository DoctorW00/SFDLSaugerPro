#ifndef SFDLSAUGER_H
#define SFDLSAUGER_H

#include "data.h"
#include "ftpdownload.h"
#include "livelogs.h"
#include "about.h"
#include "settings.h"
#include "chatirc.h"
#include "notificationclient.h"
#include "webserver.h"
#include "taskbarprogressmanager.h"
#include "filewatcher.h"
#include <QSoundEffect>

inline void registerMetaTypes()
{
    qRegisterMetaType<gsIrcServerInfo>();
    qRegisterMetaType<gsSocks5ProxyInfo>();
}

#include "crc32.h"
#include "unrar.h"
#include "unrarextractor.h"

#include <QMainWindow>
#include <QtWidgets>
#include <QObject>
#include <QInputDialog>
#include <QRegularExpression>
#include <QThread>
#include <QDesktopWidget>

#include <QMenu>
#include <QAction>
#include <QMouseEvent>

#include "FileOrganizer.h"

#ifdef QT_DEBUG
    #include <QDebug>
#endif

// after download task manager
enum class ProcessStep {
    Idle,
    SpeedReport,
    SendNotifications,
    CrcCheck,
    SfvCheck,
    Unrar,
    UnrarAutoDeleteFiles,
    SysCommands,
    ChkAllDownloads,
    Finished
};
struct TabControl {
    ProcessStep currentStep = ProcessStep::Idle;
    bool isPaused = false;
    bool isStopped = false;
    void setNextStep(ProcessStep nextStep) {
        currentStep = nextStep;
    }
};
extern QMap<QString, TabControl> m_tabWorkflows;

// crc32 threads
struct CrcTask {
    QString id;
    int row;
    QString filePath;
};

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
    void showLogMenu(const QPoint &pos);
    void openLogsDialog();
    int addTab(QString tabText);
    void chkSFDLData(QStringList data, QStringList files);
    void getSFDLData(QStringList data, QStringList files);
    void on_tabWidget_tabCloseRequested(int index);
    void MsgWarning(QString label, QString text);
    QString bytes2Human(float filesize);
    QString seconds_to_DHMS(int duration);
    void quitApp();
    void on_action_ffnen_triggered();
    void on_actionBeenden_triggered();
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
    QString returnSubPath(QString fullPath, QString splitter);
    QString removeDuplicateSlashes(QString path);
    void openIRCDialog();
    void on_actionIRC_Chat_triggered();

    // ftp downloads
    void startDownloadButton();
    void swapStartStopButton(QString id);
    void disableStartStopButton(QString id);
    void startDownload(QString tabID);
    void stopDownload();
    bool allDownloadsDone(QString id);
    void chkAllTabDownloadsAreDone();
    void createSpeedreport(QString id);
    QStringList dirFromFilePath(QString filePath);
    void updateDownloadProgress(QString tabID, int nRow, qint64 read, qint64 total, bool overwriteTime, bool firstUpdate);
    void updateDownloadFileStatus(QString tabID, int nRow, QString statusMsg, int status);
    void downloadError(QString error);
    void updateChunkedDownloadProgress(QString tabID, int nRow, int chunkIndex, qint64 chunkRead, qint64 totalSize);

    // after download task manager
    void runNextStep(const QString& tabID);

    // crc32 & sfv
    void crc32Check(QString id);
    void updateCRC32(QString id, int nRow, QString crc32Data);
    void sfvCheck(QString id);
    void processNextCrcTask();
    void stopAllCrcThreads(QString id = ""); // id = tabID

    // unrar
    void unrarFiles(QString id);
    void processNextUnrarJob(QString id);
    void unrarProgressUpdate(QString id, QString fileName, int progress);
    void unrarDeleteFiles(QString id);

    // ftp clients
    void openInFileZilla();
    void openInFTPRushV2();
    void openInWinSCP();
    void openInFlashFXP();

    // Strukturreformator Button
    void on_actionStrukturreformator_triggered();

    // webserver
    void startWebServer();
    void stopWebServer();
    void handleIncomingSFDL(QString xmlContent, QString fileName);

    // filewatcher
    void startFileWatching();
    void stopFileWatching();
    void updateFileWatching(const QString &newPath, int newInterval);

    // notifications
    void sendNotifications(QString id);

    // system commands
    void startSystemCommands(QString id); // id = tabID

    // shutdown
    void shutdownPC();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *e) override;
    void dropEvent(QDropEvent *e) override;
    void closeEvent(QCloseEvent *e) override;
    void changeEvent(QEvent *event) override;

signals:
    void logAdded(const QString& htmlLine);
    void doubleClicked();
    void webServerStatusChanged(bool running);
    void webLogAdded(QString htmlLine);

private:
    Ui::SFDLSauger *ui;
    QTextEdit *logsText;
    QList<SFDL> sfdlData;
    int maxTabTextLength = 32;
    QFont defaultFont;
    QWidget *widget;
    QSystemTrayIcon *icon;
    int g_sessionID = 0;
    LiveLogs *logsWindow;
    About *infoWindow;
    Settings *settingsWindow;
    chatIRC *ircChatWindow;
    qint64 g_lastProgressUpdate;

    // ftp downloads
    QList<FTPDownload*> g_Worker;
    int g_runningDownloads = 0;
    int g_maxDownloads = 10;
    QMap<QString, int> g_tabDownloads;

    // crc32 threads
    // QList<Crc32*> g_CRC32Worker;
    int g_runningCRC32 = 0;
    int g_maxCRC32 = 4;

    QQueue<CrcTask> m_crcQueue;
    QList<QPointer<Crc32>> m_activeWorker;
    QList<QPointer<QThread>> m_activeThreads;

    // unrar threads
    QList<UnRAR*> g_UnRARWorker;
    QList<UnrarExtractor*> g_UnRARExtractor;

    // sfv check timer
    QList<QTimer*> g_SFVTimer;

    // sounds
    QSoundEffect *finishSound;

    // notifications
    NotificationClient *m_notifier;

    // webserver
    QThread* webWorkerThread = nullptr;
    WebServerWorker *wwworker = nullptr;

    // filewatcher
    QThread *m_watcherThread = nullptr;
    FileWatcher *m_watcher = nullptr;

    // sys commands
    QSet<QString> m_activeCommandIds;

    // (task-bar)icon progress
    TaskbarProgressManager *m_taskbarProgress;

};

#endif // SFDLSAUGER_H
