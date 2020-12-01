#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QStorageInfo>
#include <QRegExp>
#include <QSettings>
#include <QCloseEvent>
#include <QStringList>

#ifdef QT_DEBUG
    #include <QDebug>
#endif

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

    // config
    QString _downloadPath;
    bool _crc32Check;
    bool _sfvCheck;
    QString _unrarPath;
    bool _unrarAutoEtract;
    bool _unrarAutoDelete;
    QStringList _sfdlPasswords;
    QString _ftpProxyHost;
    QString _ftpProxyPort;
    QString _ftpProxyUser;
    QString _ftpProxyPass;

private slots:
    QString bytes2Human(float filesize);
    void loadSettings();
    void saveSettings();
    void crc32sfvCheckBoxes();
    void unrarCheckBoxes();
    void closeEvent(QCloseEvent *e);
    void on_button_openDownloadPath_clicked();
    void on_btn_new_password_clicked();
    void on_line_new_password_returnPressed();
    void on_btn_del_password_clicked();
    void on_button_openUnrarPath_clicked();

private:
    Ui::Settings *ui;

};

#endif // SETTINGS_H
