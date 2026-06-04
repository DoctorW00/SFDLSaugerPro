#ifndef SETTINGS_H
#define SETTINGS_H

#include "commandworker.h"
#include <QDialog>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QStorageInfo>
#include <QSettings>
#include <QCloseEvent>
#include <QStringList>
#include <QListWidget>
#include <QSoundEffect>
#include <QTranslator>
#include <QVector>
#include <atomic> // NOLINT

#ifdef QT_DEBUG
    #include <QDebug>
#endif

class NotificationClient;

namespace Ui
{
    class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

    static std::atomic<qint64> _globalSpeedLimitBytes;

    void setNotificationSystem(NotificationClient *n) { m_notification = n; }

    // config
    QString _lastSFDLpath;
    bool _devMode = false;
    int _max_downloads = 3;
    QString _downloadPath;
    bool _flatDownloads = false;
    bool _crc32Check;
    bool _sfvCheck;
    bool _unrar_user_internal = true;
    QString _unrarPath;
    bool _unrarAutoEtract;
    bool _unrarAutoDelete;
    QStringList _sfdlPasswords;
    QString _ftpProxyHost;
    QString _ftpProxyPort;
    QString _ftpProxyUser;
    QString _ftpProxyPass;
    QStringList _excludeFilesFromDownload;
    bool _play_sound_finish = false;
    bool _sfdl_move_file_to_download = false;
    bool _shutdown_pc = false;
    qint64 _speedLimitKB = 0;

    // external ftp clients
    QString _ex_path_filezilla;
    QString _ex_path_ftprush_v2;
    QString _ex_path_winscp;
    QString _ex_path_flashfxp;

    // notifications
    bool _send_notifications = false;

    // email
    bool _send_email = false;
    QString _email_sender_name;
    QString _email_sender_mailadress;
    QString _email_rcv_name;
    QString _email_rcv_mailadress;
    QString _email_host;
    QString _email_port = "465";
    QString _email_username;
    QString _email_password;

    // pushover
    bool _send_pushover = false;
    QString _pushover_token;
    QString _pushover_user;

    // pushsafer
    bool _send_pushsafer = false;
    QString _pushsafer_token;

    // webserver
    bool _webserver_autostart = false;
    QString _webserver_host = "0.0.0.0";
    QString _webserver_port = "8080";
    QString _webserver_upload_path;

    // filewatcher
    bool _filewatcher = false;
    QString _filewatcher_path;
    QString _filewatcher_interval = "2";

    // translations
    QString _translation = "de";

    // auto downloads
    bool _auto_downloads = false;

    // chunk downloads
    bool _download_useChunks = false;

    // system commands
    QVector<CustomCommand> getCustomCommands() {
        syncGuiToVector();
        return myCommandList;
    }

public slots:
    void updateButtonText(bool running);
    void changeLanguage(QString localeCode);

private slots:
    QString bytes2Human(float filesize);
    void loadSettings();
    void saveSettings();
    void crc32sfvCheckBoxes();
    void unrarCheckBoxes();
    void on_button_openDownloadPath_clicked();
    void on_btn_new_password_clicked();
    void on_line_new_password_returnPressed();
    void on_btn_del_password_clicked();
    void on_button_openUnrarPath_clicked();
    void on_btn_new_exception_clicked();
    void on_btn_del_exception_clicked();
    void on_line_new_exception_returnPressed();
    bool checkForExisting(QListWidget *listWidget, QString entry);
    void on_button_test_sound_clicked();
    void on_button_email_test_clicked();
    void on_button_pushover_test_clicked();
    void on_button_pushsafer_test_clicked();
    void on_button_webserver_start_clicked();
    void on_combo_language_currentIndexChanged(int index);
    void on_button_fileWatcher_clicked();
    void on_chk_fileWatcher_stateChanged(int arg1);
    void on_chk_webserver_start_autostart_stateChanged(int arg1);
    void on_chk_auto_downloads_stateChanged(int arg1);
    void on_button_webserver_path_clicked();
    void onIpChanged(const QString &newIp);
    void on_button_windows_defender_clicked();
    void on_button_command_add_clicked();
    void on_button_command_remove_clicked();
    void on_list_commands_currentRowChanged(int currentRow);
    void on_line_command_cmd_textChanged(const QString &text);
    void on_line_command_name_textChanged(const QString &text);
    void on_spin_speedlimit_valueChanged(int arg1);

protected:
    void closeEvent(QCloseEvent *e) override;
    void changeEvent(QEvent *event) override;

signals:
    void sendLogText(QString txt);
    void requestStartMonitoring();
    void requestStopMonitoring();
    void requestSettingsUpdate(QString path, int interval);
    void webserverStartStop();

private:
    Ui::Settings *ui;
    QSoundEffect *testSound;
    NotificationClient *m_notification = nullptr;
    QTranslator *m_translator;
    QVector<CustomCommand> myCommandList;
    void updateListWidget();
    void syncGuiToVector();

};

#endif // SETTINGS_H
