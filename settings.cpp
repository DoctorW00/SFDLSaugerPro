#include "settings.h"
#include "notificationclient.h"
#include "ui_settings.h"
#include <QNetworkInterface>
#include <QHostAddress>
#include <QProcess>
#include <QUuid>
#ifdef Q_OS_MAC
#include <QStyleFactory>
#endif
#include <QDebug>

std::atomic<qint64> Settings::_globalSpeedLimitBytes{0};

Settings::Settings(QWidget *parent) : QDialog(parent), ui(new Ui::Settings)
{
    ui->setupUi(this);

    ui->bar_openDownloadPath->setHidden(1);
    ui->chk_sfv->setDisabled(1);
    // ui->chk_unrar->setDisabled(1);
    ui->chk_unrar_del->setDisabled(1);

    ui->toolBox->setStyleSheet("QToolBox::tab { font-weight: bold; background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E1E1E1, stop: 0.4 #DDDDDD, stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3); }");

    // translations
    m_translator = new QTranslator(qApp);
    QDir i18nDir(":/i18n");
    QStringList qmFiles = i18nDir.entryList(QStringList() << "*.qm");
    qmFiles.sort(Qt::CaseInsensitive);
    ui->combo_language->blockSignals(true);
    for(const QString &fileName : qAsConst(qmFiles))
    {
        QString base = fileName.left(fileName.lastIndexOf('.'));
        QString localeCode = base.section('_', 1);
        QLocale loc(localeCode);

        QString uiName = QString("%1 (%2)").arg(QLocale::languageToString(loc.language()), loc.nativeLanguageName());
        ui->combo_language->addItem(uiName, fileName);
    }
    ui->combo_language->blockSignals(false);

    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    ui->box_webserver_list_ip->addItem("0.0.0.0");
    ui->box_webserver_list_ip->addItem("127.0.0.1");
    for(int nIter = 0; nIter < list.count(); nIter++)
    {
        const QHostAddress &address = list.at(nIter);
        if(address.protocol() == QAbstractSocket::IPv4Protocol && !address.isLoopback())
        {
            ui->box_webserver_list_ip->addItem(address.toString());
        }
    }
    ui->box_webserver_list_ip->model()->sort(0, Qt::AscendingOrder);
    connect(ui->box_webserver_list_ip, &QComboBox::textActivated, this, &Settings::onIpChanged);

    // speedlimit
    ui->spin_speedlimit->setMinimum(0);
    ui->spin_speedlimit->setMaximum(2000000);
    ui->spin_speedlimit->setAccelerated(true);
    ui->spin_speedlimit->setSingleStep(100);

    loadSettings();

    // chunks
    connect(ui->chk_download_useChunks, &QCheckBox::toggled, [=](bool checked) {
        if(!checked)
        {
            ui->chk_download_useChunks->setChecked(false);
            _download_useChunks = false;
        }
        else
        {
            ui->chk_download_useChunks->setChecked(true);
            _download_useChunks = true;
        }
    });

    connect(ui->chk_crc32, SIGNAL(stateChanged(int)), this, SLOT(crc32sfvCheckBoxes()));
    connect(ui->chk_sfv, SIGNAL(stateChanged(int)), this, SLOT(crc32sfvCheckBoxes()));

    connect(ui->chk_use_internal_unrar, SIGNAL(stateChanged(int)), this, SLOT(unrarCheckBoxes()));
    connect(ui->chk_unrar, SIGNAL(stateChanged(int)), this, SLOT(unrarCheckBoxes()));
    connect(ui->chk_unrar_del, SIGNAL(stateChanged(int)), this, SLOT(unrarCheckBoxes()));

    ui->line_proxy_port->setValidator(new QRegularExpressionValidator(QRegularExpression("^(1|[1-9][0-9]{0,3}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$")));

    testSound = new QSoundEffect(this);
    testSound->setSource(QUrl::fromLocalFile(":/snd/done.wav"));
    testSound->setVolume(0.9f);

    // this->setStyleSheet("QLineEdit, QCheckBox, QComboBox { font-size: 12px; }");
    this->setStyleSheet("QLineEdit, QCheckBox, QComboBox { "
                        "font-size: 12px; "
                        "font-family: 'Segoe UI', 'Microsoft YaHei', 'Arial Unicode MS', 'sans-serif'; }");


    // notification placeholder
    QString placeholderStyle = "QLineEdit::placeholder { color: rgba(0, 0, 0, 100); font-style: italic; }";
    ui->line_sendfrom_name->setPlaceholderText("Absendername");
    ui->line_sendfrom_email->setPlaceholderText("name@mail.com");
    ui->line_sendfrom_name->setStyleSheet(placeholderStyle);
    ui->line_sendto_name->setPlaceholderText("Empfängername");
    ui->line_sendto_email->setPlaceholderText("empfaenger@mail.com");
    ui->line_sendto_email->setStyleSheet(placeholderStyle);

    ui->line_smtp_port->setValidator(new QRegularExpressionValidator(QRegularExpression("^(1|[1-9][0-9]{0,3}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$")));

    // webserver
    ui->button_webserver_start->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->line_webserver_port->setValidator(new QRegularExpressionValidator(QRegularExpression("^(1|[1-9][0-9]{0,3}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$")));

    QRegularExpression rx("^[1-9][0-9]{0,2}$");
    QRegularExpressionValidator* rev = new QRegularExpressionValidator(rx, this);
    ui->line_fileWatcher_interval->setValidator(rev);

    connect(ui->chk_send_notifications, &QCheckBox::toggled, [=](bool checked) {
        if(!checked)
        {
            ui->chk_email_send->setChecked(false);
        }
        ui->chk_email_send->setEnabled(checked);
    });
    connect(ui->chk_email_send, &QCheckBox::toggled, ui->button_email_test, &QPushButton::setEnabled);
    ui->button_email_test->setEnabled(ui->chk_email_send->isChecked());
    connect(ui->chk_send_notifications, &QCheckBox::toggled, [=](bool checked) {
        if(!checked)
        {
            ui->chk_pushover_send->setChecked(false);
        }
        ui->chk_pushover_send->setEnabled(checked);
    });
    connect(ui->chk_pushover_send, &QCheckBox::toggled, ui->button_pushover_test, &QPushButton::setEnabled);
    ui->button_pushover_test->setEnabled(ui->chk_pushover_send->isChecked());
    connect(ui->chk_send_notifications, &QCheckBox::toggled, [=](bool checked) {
        if(!checked)
        {
            ui->chk_pushsafer_send->setChecked(false);
        }
        ui->chk_pushsafer_send->setEnabled(checked);
    });
    connect(ui->chk_pushsafer_send, &QCheckBox::toggled, ui->button_pushsafer_test, &QPushButton::setEnabled);
    ui->button_pushsafer_test->setEnabled(ui->chk_pushsafer_send->isChecked());
    bool isMasterChecked = ui->chk_send_notifications->isChecked();
    ui->chk_email_send->setEnabled(isMasterChecked);
    ui->chk_pushover_send->setEnabled(isMasterChecked);
    ui->chk_pushsafer_send->setEnabled(isMasterChecked);

    // move sfdl file
    connect(ui->chk_sfdl_move_file, &QCheckBox::toggled, [=](bool checked) {
        if(!checked)
        {
            ui->chk_sfdl_move_file->setChecked(false);
            _sfdl_move_file_to_download = false;
        }
        else
        {
            ui->chk_sfdl_move_file->setChecked(true);
            _sfdl_move_file_to_download = true;
        }
    });

    // shut down pc
    connect(ui->chk_shutdown_pc, &QCheckBox::toggled, [=](bool checked) {
        if(!checked)
        {
            ui->chk_shutdown_pc->setChecked(false);
            _shutdown_pc = false;
        }
        else
        {
            ui->chk_shutdown_pc->setChecked(true);
            _shutdown_pc = true;
        }
    });

    // button to add download path
    // to windows defender exclusions
    #if defined(Q_OS_WIN)
        ui->button_windows_defender->show();
        ui->button_windows_defender->setEnabled(true);
        ui->label_windows_defender->show();
    #else
        ui->button_windows_defender->hide();
        ui->button_windows_defender->setEnabled(false);
        ui->label_windows_defender->hide();
    #endif

    // system commands
    ui->list_commands->setDragDropMode(QAbstractItemView::InternalMove);
    ui->list_commands->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->list_commands->setDefaultDropAction(Qt::MoveAction);
    connect(ui->list_commands, &QListWidget::currentRowChanged, this, &Settings::on_list_commands_currentRowChanged);

}

Settings::~Settings()
{
    saveSettings();
    delete ui;
}

void Settings::closeEvent(QCloseEvent *e)
{
    e->ignore();
    saveSettings();
    e->accept();
}

void Settings::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
    QWidget::changeEvent(event);
}

// load settings from file
void Settings::loadSettings()
{
    QSettings config(QSettings::IniFormat, QSettings::UserScope, "SFDLSaugerPro", "config");

    config.beginGroup("main");
    _devMode = config.value("devMode", false).toBool();
    _max_downloads = config.value("max_downloads", 3).toInt();
    _download_useChunks = config.value("download_useChunks", false).toBool();
    ui->chk_download_useChunks->setChecked(_download_useChunks);
    _sfdl_move_file_to_download = config.value("sfdl_move_file_to_download", false).toBool();
    ui->chk_sfdl_move_file->setChecked(_sfdl_move_file_to_download);
    _shutdown_pc = config.value("shutdown_pc", false).toBool();
    ui->chk_shutdown_pc->setChecked(_shutdown_pc);
    _downloadPath = config.value("downloadPath").toString();
    ui->line_openDownloadPath->setText(_downloadPath);
    _speedLimitKB = config.value("speedlimit", 0).toLongLong();
    _globalSpeedLimitBytes = _speedLimitKB * 1024;
    ui->spin_speedlimit->setMaximum(2000000);
    ui->spin_speedlimit->setValue(static_cast<int>(_speedLimitKB));
    _lastSFDLpath = config.value("lastSFDLpath").toString();

    if(!_downloadPath.isEmpty())
    {
        QFileInfo path(_downloadPath);
        QStorageInfo storage(_downloadPath);

        if(!_downloadPath.endsWith("/"))
        {
            _downloadPath = _downloadPath + "/";
        }

        QFile testFile(_downloadPath + ".test_write");
        bool canWrite = false;
        if(testFile.open(QIODevice::WriteOnly))
        {
            canWrite = true;
            testFile.close();
            testFile.remove();
        }

        if(canWrite)
        {
            ui->line_openDownloadPath->setText(_downloadPath);

            qlonglong bytesAvailable = storage.bytesAvailable()/1000/1000; // free space
            qlonglong bytesTotal = storage.bytesTotal()/1000/1000; // total space
            qlonglong progress = bytesTotal - bytesAvailable;

            ui->bar_openDownloadPath->setVisible(1);
            ui->bar_openDownloadPath->setAlignment(Qt::AlignCenter);
            ui->bar_openDownloadPath->setMaximum(bytesTotal);
            ui->bar_openDownloadPath->setMinimum(0);
            ui->bar_openDownloadPath->setValue(progress);
            #ifdef Q_OS_MAC
            ui->bar_openDownloadPath->setStyle(QStyleFactory::create("Fusion"));
            #endif
            ui->bar_openDownloadPath->setFormat(storage.displayName() + " (" + storage.fileSystemType() + ") " + bytes2Human(storage.bytesAvailable()) + tr(" von ") + bytes2Human(storage.bytesTotal()) + tr(" verfügbar"));    
        }
        else
        {
            ui->line_openDownloadPath->setText("");
        }

        ui->chk_flatDownloads->setChecked(config.value("flatDownloads").toBool());
    }
    config.endGroup();

    config.beginGroup("ftpclients");
    _ex_path_filezilla = config.value("ex_path_filezilla").toString();
    _ex_path_ftprush_v2 = config.value("ex_path_ftprush_v2").toString();
    _ex_path_winscp = config.value("ex_path_winscp").toString();
    _ex_path_flashfxp = config.value("ex_path_flashfxp").toString();
    config.endGroup();

    config.beginGroup("crc32");
    _crc32Check = config.value("crc32Check").toBool();
    ui->chk_crc32->setChecked(_crc32Check);
    _sfvCheck = config.value("sfvCheck").toBool();
    ui->chk_sfv->setChecked(_sfvCheck);

    if(_crc32Check)
    {
        ui->chk_sfv->setEnabled(1);
    }
    else
    {
        ui->chk_sfv->setDisabled(1);
        ui->chk_sfv->setChecked(0);
    }
    config.endGroup();

    config.beginGroup("unrar");
    if(config.contains("unar_use_internal"))
    {
        _unrar_user_internal = config.value("unar_use_internal").toBool();
    }
    ui->chk_use_internal_unrar->setChecked(_unrar_user_internal);
    if(_unrar_user_internal)
    {
        ui->line_unrar_path->setDisabled(true);
        ui->button_openUnrarPath->setDisabled(true);
    }
    else
    {
        ui->line_unrar_path->setDisabled(false);
        ui->button_openUnrarPath->setDisabled(false);
    }
    _unrarPath = config.value("unrarPath").toString();
    ui->line_unrar_path->setText(_unrarPath);
    _unrarAutoEtract = config.value("unrarAutoEtract").toBool();
    ui->chk_unrar->setChecked(_unrarAutoEtract);
    _unrarAutoDelete = config.value("unrarAutoDelete").toBool();
    ui->chk_unrar_del->setChecked(_unrarAutoDelete);
    if(_unrarAutoEtract)
    {
        ui->chk_unrar_del->setEnabled(1);
    }
    else
    {
        ui->chk_unrar_del->setDisabled(1);
        ui->chk_unrar_del->setChecked(0);
    }
    config.endGroup();

    config.beginGroup("sfdl");
    _sfdlPasswords = config.value("sfdlPasswords").toStringList();
    _sfdlPasswords.prepend("mlcboard.com");
    _sfdlPasswords.removeDuplicates();
    ui->list_sfdl_passwords->addItems(_sfdlPasswords);

    _excludeFilesFromDownload = config.value("downloadExceptions").toStringList();
    _excludeFilesFromDownload.removeDuplicates();
    ui->list_exceptions->addItems(_excludeFilesFromDownload);
    config.endGroup();

    config.beginGroup("ftpproxy");
    _ftpProxyHost = config.value("ftpProxyHost").toString();
    ui->line_proxy_host->setText(_ftpProxyHost);
    _ftpProxyPort = config.value("ftpProxyPort").toString();
    ui->line_proxy_port->setText(_ftpProxyPort);
    _ftpProxyUser = config.value("ftpProxyUser").toString();
    ui->line_proxy_user->setText(_ftpProxyUser);
    _ftpProxyPass = config.value("ftpProxyPass").toString();
    ui->line_proxy_pass->setText(_ftpProxyPass);
    config.endGroup();

    config.beginGroup("sounds");
    _play_sound_finish = config.value("playFinishSound").toBool();
    ui->chk_sound_finish->setChecked(_play_sound_finish);
    config.endGroup();

    config.beginGroup("filewatcher");
    _filewatcher = config.value("filewatcher").toBool();
    ui->chk_fileWatcher->setChecked(_filewatcher);
    _filewatcher_path = config.value("filewatcher_path").toString();
    if(_filewatcher_path.isEmpty()) { _filewatcher_path = _downloadPath; }
    ui->line_fileWatcher_path->setText(_filewatcher_path);
    _filewatcher_interval = config.value("filewatcher_interval").toString();
    if(_filewatcher_interval.isEmpty()) { _filewatcher_interval = "2"; }
    ui->line_fileWatcher_interval->setText(_filewatcher_interval);
    config.endGroup();

    config.beginGroup("autodownloads");
    _auto_downloads = config.value("auto_downloads").toBool();
    ui->chk_auto_downloads->setChecked(_auto_downloads);
    config.endGroup();

    config.beginGroup("notifications");
    _send_notifications = config.value("send_notifications").toBool();
    ui->chk_send_notifications->setChecked(_send_notifications);

    _send_email = config.value("send_email").toBool();
    ui->chk_email_send->setChecked(_send_email);
    _email_sender_name = config.value("email_sender_name").toString();
    ui->line_sendfrom_name->setText(_email_sender_name);
    _email_sender_mailadress = config.value("email_sende_mailadress").toString();
    ui->line_sendfrom_email->setText(_email_sender_mailadress);
    _email_rcv_name = config.value("email_rcv_name").toString();
    ui->line_sendto_name->setText(_email_rcv_name);
    _email_rcv_mailadress = config.value("email_rcv_mailadress").toString();
    ui->line_sendto_email->setText(_email_rcv_mailadress);
    _email_host = config.value("email_host").toString();
    ui->line_smtp_host->setText(_email_host);
    _email_port = config.value("email_port").toString();
    ui->line_smtp_port->setText(_email_port);
    _email_username = config.value("email_username").toString();
    ui->line_smtp_username->setText(_email_username);
    _email_password = config.value("email_password").toString();
    ui->line_smtp_password->setText(_email_password);

    _send_pushover = config.value("send_pushover").toBool();
    ui->chk_pushover_send->setChecked(_send_pushover);
    _pushover_token = config.value("pushover_token").toString();
    ui->line_pushover_token->setText(_pushover_token);
    _pushover_user = config.value("pushover_user").toString();
    ui->line_pushover_user->setText(_pushover_user);

    _send_pushsafer = config.value("send_pushsafer").toBool();
    ui->chk_pushsafer_send->setChecked(_send_pushsafer);
    _pushsafer_token = config.value("pushsafer_token").toString();
    ui->line_pushsafer_token->setText(_pushsafer_token);
    config.endGroup();

    config.beginGroup("webserver");
    _webserver_host = config.value("webserver_host").toString();
    if(_webserver_host.isEmpty()) { _webserver_host = "0.0.0.0"; }
    int index = ui->box_webserver_list_ip->findText(_webserver_host);
    if (index != -1) { ui->box_webserver_list_ip->setCurrentIndex(index); }
    _webserver_port = config.value("webserver_port").toString();
    if(_webserver_port.isEmpty()) { _webserver_port = "8080"; }
    ui->line_webserver_port->setText(_webserver_port);
    _webserver_upload_path = config.value("webserver_upload_path").toString();
    if(_webserver_upload_path.isEmpty()) { _webserver_upload_path = _downloadPath; }
    ui->line_webserver_upload_path->setText(_webserver_upload_path);
    _webserver_autostart = config.value("webserver_autostart").toBool();
    ui->chk_webserver_start_autostart->setChecked(_webserver_autostart);
    config.endGroup();

    config.beginGroup("translations");
    _translation = config.value("translation").toString();
    if(_translation.isEmpty())
    {
        QString systemLocale = QLocale::system().name();
        qDebug() << "systemLocale: " << systemLocale;
        changeLanguage(systemLocale);
    }
    else
    {
        changeLanguage(_translation);
    }
    config.endGroup();

    // sys commands
    myCommandList.clear();
    int size = config.beginReadArray("syscommands/CustomCommands");
    for(int i = 0; i < size; ++i)
    {
        config.setArrayIndex(i);

        CustomCommand cmd;
        cmd.id          = config.value("id").toString();
        cmd.name        = config.value("name").toString();
        cmd.commandLine = config.value("commandLine").toString();
        cmd.enabled     = config.value("enabled", true).toBool();

        myCommandList.append(cmd);
    }
    config.endArray();
    updateListWidget();

}

// save settings to file
void Settings::saveSettings()
{
    QSettings config(QSettings::IniFormat, QSettings::UserScope, "SFDLSaugerPro", "config");

    config.beginGroup("main");
    config.setValue("devMode", _devMode);
    config.setValue("max_downloads", _max_downloads);
    config.setValue("download_useChunks", ui->chk_download_useChunks->checkState());
    config.setValue("sfdl_move_file_to_download", ui->chk_sfdl_move_file->checkState());
    config.setValue("shutdown_pc", ui->chk_shutdown_pc->checkState());
    config.setValue("downloadPath", ui->line_openDownloadPath->text());
    _downloadPath = ui->line_openDownloadPath->text();
    config.setValue("flatDownloads", ui->chk_flatDownloads->checkState());
    _flatDownloads = ui->chk_flatDownloads->checkState();
    _speedLimitKB = ui->spin_speedlimit->value();
    config.setValue("speedlimit", _speedLimitKB);
    config.setValue("lastSFDLpath", _lastSFDLpath);
    config.endGroup();

    config.beginGroup("ftpclients");
    config.setValue("ex_path_filezilla", _ex_path_filezilla);
    config.setValue("ex_path_ftprush_v2", _ex_path_ftprush_v2);
    config.setValue("ex_path_winscp", _ex_path_winscp);
    config.setValue("ex_path_flashfxp", _ex_path_flashfxp);
    config.endGroup();

    config.beginGroup("crc32");
    config.setValue("crc32Check", ui->chk_crc32->isChecked());
    _crc32Check = ui->chk_crc32->isChecked();
    config.setValue("sfvCheck", ui->chk_sfv->isChecked());
    _sfvCheck = ui->chk_sfv->isChecked();
    config.endGroup();

    config.beginGroup("unrar");
    config.setValue("unar_use_internal", ui->chk_use_internal_unrar->isChecked());
    _unrar_user_internal = ui->chk_use_internal_unrar->isChecked();
    if(_unrar_user_internal)
    {
        ui->line_unrar_path->setDisabled(true);
        ui->button_openUnrarPath->setDisabled(true);
    }
    else
    {
        ui->line_unrar_path->setDisabled(false);
        ui->button_openUnrarPath->setDisabled(false);
    }
    config.setValue("unrarPath", ui->line_unrar_path->text());
    _unrarPath = ui->line_unrar_path->text();
    config.setValue("unrarAutoEtract", ui->chk_unrar->isChecked());
    _unrarAutoEtract = ui->chk_unrar->isChecked();
    config.setValue("unrarAutoDelete", ui->chk_unrar_del->isChecked());
    _unrarAutoDelete = ui->chk_unrar_del->isChecked();
    config.endGroup();

    // save passwords
    QStringList passwords = QStringList();
    for(int i = 0; i < ui->list_sfdl_passwords->count(); i++)
    {
        passwords.append(ui->list_sfdl_passwords->item(i)->text());
    }
    config.beginGroup("sfdl");
    passwords.prepend("mlcboard.com");
    passwords.removeDuplicates();
    config.setValue("sfdlPasswords", passwords);
    _sfdlPasswords = passwords;

    // save download exceptions
    QStringList exceptions = QStringList();
    for(int i = 0; i < ui->list_exceptions->count(); i++)
    {
        exceptions.append(ui->list_exceptions->item(i)->text());
    }
    exceptions.removeDuplicates();
    config.setValue("downloadExceptions", exceptions);
    _excludeFilesFromDownload = exceptions;
    config.endGroup();

    config.beginGroup("ftpproxy");
    config.setValue("ftpProxyHost", ui->line_proxy_host->text());
    _ftpProxyHost = ui->line_proxy_host->text();
    config.setValue("ftpProxyPort", ui->line_proxy_port->text());
    _ftpProxyPort = ui->line_proxy_port->text();
    config.setValue("ftpProxyUser", ui->line_proxy_user->text());
    _ftpProxyUser = ui->line_proxy_user->text();
    config.setValue("ftpProxyPass", ui->line_proxy_pass->text());
    _ftpProxyPass = ui->line_proxy_pass->text();
    config.endGroup();

    config.beginGroup("sounds");
    config.setValue("playFinishSound", ui->chk_sound_finish->isChecked());
    _play_sound_finish = ui->chk_sound_finish->isChecked();
    config.endGroup();

    config.beginGroup("filewatcher");
    config.setValue("filewatcher", ui->chk_fileWatcher->isChecked());
    _filewatcher = ui->chk_fileWatcher->isChecked();
    config.setValue("filewatcher_path", ui->line_fileWatcher_path->text());
    _filewatcher_path = ui->line_fileWatcher_path->text();
    config.setValue("_filewatcher_interval", ui->line_fileWatcher_interval->text());
    _filewatcher_interval = ui->line_fileWatcher_interval->text();
    config.endGroup();

    config.beginGroup("autodownloads");
    config.setValue("auto_downloads", ui->chk_auto_downloads->isChecked());
    _auto_downloads = ui->chk_auto_downloads->isChecked();
    config.endGroup();

    config.beginGroup("notifications");
    config.setValue("send_notifications", ui->chk_send_notifications->isChecked());

    config.setValue("send_email", ui->chk_email_send->isChecked());
    config.setValue("email_sender_name", ui->line_sendfrom_name->text());
    config.setValue("email_sender_mailadress", ui->line_sendfrom_email->text());
    config.setValue("email_rcv_name", ui->line_sendto_name->text());
    config.setValue("email_rcv_mailadress", ui->line_sendto_email->text());
    config.setValue("email_host", ui->line_smtp_host->text());
    config.setValue("email_port", ui->line_smtp_port->text());
    config.setValue("email_username", ui->line_smtp_username->text());
    config.setValue("email_password", ui->line_smtp_password->text());

    config.setValue("send_pushover", ui->chk_pushover_send->isChecked());
    config.setValue("pushover_token", ui->line_pushover_token->text());
    config.setValue("pushover_user", ui->line_pushover_user->text());

    config.setValue("send_pushsafer", ui->chk_pushsafer_send->isChecked());
    config.setValue("pushsafer_token", ui->line_pushsafer_token->text());
    config.endGroup();

    config.beginGroup("webserver");
    config.setValue("webserver_host", _webserver_host);
    config.setValue("webserver_port", ui->line_webserver_port->text());
    config.setValue("webserver_upload_path", ui->line_webserver_upload_path->text());
    config.setValue("webserver_autostart", ui->chk_webserver_start_autostart->isChecked());
    config.endGroup();

    config.beginGroup("translations");
    config.setValue("translation", _translation);
    config.endGroup();

    // sys commands
    syncGuiToVector();
    config.remove("syscommands/CustomCommands");
    config.beginWriteArray("syscommands/CustomCommands");

    for(int i = 0; i < myCommandList.size(); ++i)
    {
        config.setArrayIndex(i);
        config.setValue("id",          myCommandList[i].id);
        config.setValue("name",        myCommandList[i].name);
        config.setValue("commandLine", myCommandList[i].commandLine);
        config.setValue("enabled",     myCommandList[i].enabled);
    }
    config.endArray();
}

QString Settings::bytes2Human(float filesize)
{
    float num = filesize;

    QStringList list;
    list << "KiB" << "MiB" << "GiB" << "TiB";

    QStringListIterator i(list);
    QString unit("bytes");

    while(num >= 1024.0 && i.hasNext())
    {
        unit = i.next();
        num /= 1024.0;
    }
    return QString().setNum(num,'f',2) + " " + unit;
}

void Settings::crc32sfvCheckBoxes()
{
    if(ui->chk_crc32->isChecked())
    {
        ui->chk_sfv->setEnabled(1);
    }
    else
    {
        ui->chk_sfv->setDisabled(1);
        ui->chk_sfv->setChecked(0);
    }

    if(ui->chk_sfv->isChecked())
    {
        ui->chk_crc32->setChecked(1);
    }

    saveSettings();
}

void Settings::unrarCheckBoxes()
{
    if(ui->chk_unrar->isChecked())
    {
        ui->chk_unrar_del->setEnabled(1);
    }
    else
    {
        ui->chk_unrar_del->setDisabled(1);
        ui->chk_unrar_del->setChecked(0);
    }

    if(ui->chk_unrar_del->isChecked())
    {
        ui->chk_unrar->setChecked(1);
    }

    saveSettings();
}

// open download path
void Settings::on_button_openDownloadPath_clicked()
{
    // user home path
    QString home;
    if(_downloadPath.isEmpty())
    {
        home = QStandardPaths::locate(QStandardPaths::DownloadLocation, QString(), QStandardPaths::LocateDirectory);
    }
    else
    {
        home = _downloadPath;
    }

    // select new download path
    QString downloadPath = QFileDialog::getExistingDirectory(this, tr("Wo sollen Downloads gespeichert werden?"), home, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if(!downloadPath.isEmpty())
    {
        // QFileInfo path(downloadPath);
        QStorageInfo storage(downloadPath);

        QStringList errorReasons;

        if(!downloadPath.endsWith("/"))
        {
            downloadPath = downloadPath + "/";
        }

        QFile testFile(downloadPath + ".test_write");
        bool canWrite = false;
        if(testFile.open(QIODevice::WriteOnly))
        {
            canWrite = true;
            testFile.close();
            testFile.remove();
        }

        if(!canWrite)
        {
            errorReasons << tr("Das Verzeichnis ist nicht beschreibbar.");
        }

        if (errorReasons.isEmpty())
        {
            ui->line_openDownloadPath->setText(downloadPath);

            qlonglong bytesAvailable = storage.bytesAvailable()/1000/1000; // free space
            qlonglong bytesTotal = storage.bytesTotal()/1000/1000; // total space
            qlonglong progress = bytesTotal - bytesAvailable;

            ui->bar_openDownloadPath->setVisible(1);
            ui->bar_openDownloadPath->setAlignment(Qt::AlignCenter);
            ui->bar_openDownloadPath->setMaximum(bytesTotal);
            ui->bar_openDownloadPath->setMinimum(0);
            ui->bar_openDownloadPath->setValue(progress);
            ui->bar_openDownloadPath->setFormat(storage.displayName() + " (" + storage.fileSystemType() + ") " + bytes2Human(storage.bytesAvailable()) + tr(" von ") + bytes2Human(storage.bytesTotal()) + tr(" verfügbar"));

            saveSettings();
        }
        else
        {
            QString errorMessage = errorReasons.join("\n");
            QMessageBox::warning(this, tr("Ungültiger Speicherpfad"), tr("Der Pfad\n\n") + downloadPath + tr("\n\nist ungültig! Grund: \n") + errorMessage);
        }
    }
}

bool Settings::checkForExisting(QListWidget *listWidget, QString entry)
{
    for(QListWidgetItem *item : listWidget->findItems("", Qt::MatchContains))
    {
        if(entry == item->text())
        {
            return true;
        }
    }

    return false;
}

// add new password
void Settings::on_btn_new_password_clicked()
{
    QString newPassword = ui->line_new_password->text();

    if(!newPassword.isEmpty())
    {
        if(checkForExisting(ui->list_sfdl_passwords, newPassword))
        {
            QMessageBox::critical(this, tr("Fehler"), tr("Passwort bereits vorhanden!"), QMessageBox::Ok);
        }
        else
        {
            ui->list_sfdl_passwords->addItem(newPassword);
            ui->line_new_password->clear();
            saveSettings();
        }
    }
}

// on enter new password add new password
void Settings::on_line_new_password_returnPressed()
{
    on_btn_new_password_clicked();
}

// remove password from list
void Settings::on_btn_del_password_clicked()
{
    QList<QListWidgetItem*> items = ui->list_sfdl_passwords->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        if(item->text() != "mlcboard.com")
        {
            delete ui->list_sfdl_passwords->takeItem(ui->list_sfdl_passwords->row(item));
        }
    }

    saveSettings();
}

void Settings::on_button_openUnrarPath_clicked()
{
    // user home path
    QString home = QCoreApplication::applicationFilePath();

    QString unrarExtension = "UnRAR";

    #if defined(Q_OS_WIN)
        unrarExtension = "UnRAR (*.exe)";
    #endif

    // select unrar executable
    QString unrarPath = QFileDialog::getOpenFileName(this, tr("Wo befindet sich UnRAR?"), home, unrarExtension);


    QFileInfo unrar(unrarPath);
    if(unrar.exists() && unrar.isFile())
    {
        ui->line_unrar_path->setText(unrarPath);

        saveSettings();
    }
}

void Settings::on_line_new_exception_returnPressed()
{
    on_btn_new_exception_clicked();
}

void Settings::on_btn_new_exception_clicked()
{
    QString newExeption = ui->line_new_exception->text();

    if(!newExeption.isEmpty())
    {
        if(checkForExisting(ui->list_exceptions, newExeption))
        {
            QMessageBox::critical(this, tr("Fehler"), tr("Ausnahme bereits in der Liste!"), QMessageBox::Ok);
        }
        else
        {
            ui->list_exceptions->addItem(newExeption);
            ui->line_new_exception->clear();
            saveSettings();
        }
    }
}

void Settings::on_btn_del_exception_clicked()
{
    QList<QListWidgetItem*> items = ui->list_exceptions->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->list_exceptions->takeItem(ui->list_exceptions->row(item));
    }

    saveSettings();
}

void Settings::on_button_test_sound_clicked()
{
    testSound->play();
}

void Settings::on_button_email_test_clicked()
{
    saveSettings();

    if(m_notification)
    {
        m_notification->sendMessage(NotificationClient::Email, tr("SFDLSaugerPro - Test"), tr("Testnachricht ..."));
    }
}

void Settings::on_button_pushover_test_clicked()
{
    saveSettings();

    if(m_notification)
    {
        m_notification->sendMessage(NotificationClient::Pushover, tr("SFDLSaugerPro - Test"), tr("Testnachricht ..."));
    }
}

void Settings::on_button_pushsafer_test_clicked()
{
    saveSettings();

    if(m_notification)
    {
        m_notification->sendMessage(NotificationClient::Pushsafer, tr("SFDLSaugerPro - Test"), tr("Testnachricht ..."));
    }
}

void Settings::on_button_webserver_start_clicked()
{
    if(_webserver_host.isEmpty())
    {
        _webserver_host = "0.0.0.0";
    }
    QHostAddress addr;
    bool isValid = addr.setAddress(_webserver_host) && addr.protocol() == QAbstractSocket::IPv4Protocol;
    if(!isValid)
    {
        _webserver_host = "0.0.0.0";
    }

    _webserver_port = ui->line_webserver_port->text().trimmed();
    if(_webserver_port.isEmpty())
    {
        _webserver_port = "8080";
    }

    emit webserverStartStop();
}

void Settings::on_button_webserver_path_clicked()
{
    QString sfdlUploadPath = QFileDialog::getExistingDirectory(this, tr("Wo sollen die SFDL Dateien vom Webserver gespeichert werden?"), _webserver_upload_path, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if(!sfdlUploadPath.isEmpty())
    {
        _webserver_upload_path = sfdlUploadPath;
        ui->line_webserver_upload_path->setText(_webserver_upload_path);
    }
    else
    {
        QMessageBox::warning(this, tr("Ungültiger Pfad"), tr("Pfad kann nicht zum Speichern von SFDL Dateien genuzt werden!"));
    }
}

void Settings::onIpChanged(const QString &newIp)
{
    _webserver_host = newIp;
}


void Settings::updateButtonText(bool running)
{
    ui->box_webserver_list_ip->setEnabled(!running);

    if(running)
    {
        ui->button_webserver_start->setText(tr("Webserver stoppen"));
        ui->button_webserver_start->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    }
    else
    {
        ui->button_webserver_start->setText(tr("Webserver starten"));
        ui->button_webserver_start->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}

void Settings::on_combo_language_currentIndexChanged(int index)
{
    QString fileName = ui->combo_language->currentData().toString();

    if(m_translator->load(":/i18n/" + fileName))
    {
        qApp->installTranslator(m_translator);

        QString base = fileName.left(fileName.lastIndexOf('.'));
        QString localeCode = base.section('_', 1);
        _translation = localeCode;
    }
}

void Settings::changeLanguage(QString localeCode)
{
    QDir i18nDir(":/i18n");
    QStringList matches = i18nDir.entryList(QStringList() << "*" + localeCode + ".qm");

    if(matches.isEmpty() && localeCode.length() >= 2)
    {
        QString shortCode = localeCode.left(2);
        matches = i18nDir.entryList(QStringList() << "*" + shortCode + ".qm");
    }

    if(!matches.isEmpty())
    {
        QString foundFile = matches.first();
        if(m_translator->load(":/i18n/" + foundFile))
        {
            qApp->installTranslator(m_translator);

            _translation = localeCode;

            int index = ui->combo_language->findData(foundFile);
            if(index != -1)
            {
                ui->combo_language->blockSignals(true);
                ui->combo_language->setCurrentIndex(index);
                ui->combo_language->blockSignals(false);
            }
        }
    }
    else
    {
        QMessageBox::critical(this, tr("Fehler"), localeCode + tr(" - Keine passende Sprachdatei gefunden!"), QMessageBox::Ok);
    }
}

void Settings::on_button_fileWatcher_clicked()
{
    QString fileWatcherPath = QFileDialog::getExistingDirectory(this, tr("Welcher Ordner soll auf neue SFDL überwacht werden?"), _filewatcher_path, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if(!fileWatcherPath.isEmpty())
    {
        _filewatcher_path = fileWatcherPath;
        ui->line_fileWatcher_path->setText(_filewatcher_path);
    }
    else
    {
        QMessageBox::warning(this, tr("Ungültiger Pfad"), tr("Pfad kann nicht auf neue SFDL Dateien überwacht werden!"));
    }
}

void Settings::on_chk_fileWatcher_stateChanged(int arg1)
{
    if(ui->chk_fileWatcher->isChecked())
    {
        _filewatcher = true;
        int fileWatcherTimer = _filewatcher_interval.toInt() * 1000;
        emit requestSettingsUpdate(_filewatcher_path, fileWatcherTimer);
        emit requestStartMonitoring();
        QString fileUrl = QUrl::fromLocalFile(_filewatcher_path).toString();
        QString link = QString("<a href=\"%1\" style=\"color: #4CAF50;\">%1</a>").arg(fileUrl);
        emit sendLogText(tr("[SFDL] ") + link + tr(" wird auf neue SFDL Dateien (alle ") + _filewatcher_interval +  tr(" Sekunden) überwacht!"));
    }
    else
    {
        _filewatcher = false;
        emit requestStopMonitoring();
        emit sendLogText(tr("[SFDL] Überwachung ist aus ..."));
    }
}


void Settings::on_chk_webserver_start_autostart_stateChanged(int arg1)
{
    _webserver_autostart = ui->chk_webserver_start_autostart->isChecked();
}


void Settings::on_chk_auto_downloads_stateChanged(int arg1)
{
    _auto_downloads = ui->chk_auto_downloads->isChecked();
}

// on windows
// add download path to defender exclusions
void Settings::on_button_windows_defender_clicked()
{
    if(!_downloadPath.isEmpty())
    {
        QString nativePath = QDir::toNativeSeparators(_downloadPath);
        QString psCommand = QString(
                                "$p = '%1'; "
                                "if ((Get-MpPreference).ExclusionPath -notcontains $p) { "
                                "  Start-Process powershell -Verb RunAs -ArgumentList \"-Command Add-MpPreference -ExclusionPath '%1'\" "
                                "}"
                                ).arg(nativePath);

        QProcess::startDetached("powershell", QStringList() << "-NoProfile" << "-WindowStyle" << "Hidden" << "-Command" << psCommand);
    }
}

// sys commands -->
void Settings::updateListWidget()
{
    ui->list_commands->clear();

    for(const auto& cmd : qAsConst(myCommandList))
    {
        QListWidgetItem* item = new QListWidgetItem(cmd.name, ui->list_commands);
        item->setData(Qt::UserRole, cmd.id);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
        item->setCheckState(cmd.enabled ? Qt::Checked : Qt::Unchecked);
    }
}

void Settings::syncGuiToVector()
{
    QVector<CustomCommand> updatedList;

    for(int i = 0; i < ui->list_commands->count(); ++i)
    {
        QListWidgetItem* item = ui->list_commands->item(i);
        QString id = item->data(Qt::UserRole).toString();

        for(const auto& oldCmd : qAsConst(myCommandList))
        {
            if(oldCmd.id == id)
            {
                CustomCommand updatedCmd = oldCmd;
                updatedCmd.enabled = (item->checkState() == Qt::Checked);
                updatedList.append(updatedCmd);

                break;
            }
        }
    }
    myCommandList = updatedList;
}

void Settings::on_button_command_add_clicked()
{
    QString name = ui->line_command_name->text().trimmed();
    QString command = ui->line_command_cmd->text().trimmed();

    if(name.isEmpty() || command.isEmpty())
    {
        return;
    }

    CustomCommand cmd;
    cmd.id = QUuid::createUuid().toString();
    cmd.name = name;
    cmd.commandLine = command;
    cmd.enabled = true;

    myCommandList.append(cmd);
    updateListWidget();

    ui->line_command_name->clear();
    ui->line_command_cmd->clear();
}

void Settings::on_button_command_remove_clicked()
{
    int currentRow = ui->list_commands->currentRow();
    if(currentRow < 0) return;

    QListWidgetItem* item = ui->list_commands->item(currentRow);
    QString idToDelete = item->data(Qt::UserRole).toString();

    for(int i = 0; i < myCommandList.size(); ++i)
    {
        if(myCommandList[i].id == idToDelete)
        {
            myCommandList.removeAt(i);
            break;
        }
    }

    delete ui->list_commands->takeItem(currentRow);

    ui->line_command_name->clear();
    ui->line_command_cmd->clear();
}

void Settings::on_list_commands_currentRowChanged(int currentRow)
{
    if(currentRow < 0) return;

    QListWidgetItem* item = ui->list_commands->item(currentRow);
    QString currentId = item->data(Qt::UserRole).toString();

    for(const auto& cmd : qAsConst(myCommandList))
    {
        if(cmd.id == currentId)
        {
            ui->line_command_name->blockSignals(true);
            ui->line_command_cmd->blockSignals(true);
            ui->line_command_name->setText(cmd.name);
            ui->line_command_cmd->setText(cmd.commandLine);
            ui->line_command_name->blockSignals(false);
            ui->line_command_cmd->blockSignals(false);
            break;
        }
    }
}

void Settings::on_line_command_cmd_textChanged(const QString &text)
{
    int currentRow = ui->list_commands->currentRow();
    if(currentRow < 0) return;

    QListWidgetItem* item = ui->list_commands->item(currentRow);
    QString currentId = item->data(Qt::UserRole).toString();

    for(int i = 0; i < myCommandList.size(); ++i)
    {
        if(myCommandList[i].id == currentId)
        {
            myCommandList[i].commandLine = text;

            break;
        }
    }
}

void Settings::on_line_command_name_textChanged(const QString &text) {
    int currentRow = ui->list_commands->currentRow();
    if(currentRow < 0) return;

    QListWidgetItem* item = ui->list_commands->item(currentRow);
    QString currentId = item->data(Qt::UserRole).toString();

    for(int i = 0; i < myCommandList.size(); ++i)
    {
        if(myCommandList[i].id == currentId)
        {
            myCommandList[i].name = text;
            break;
        }
    }
    item->setText(text);
}
// <-- sys commands

void Settings::on_spin_speedlimit_valueChanged(int arg1)
{
    _speedLimitKB = static_cast<qint64>(arg1) * 1024;
    _globalSpeedLimitBytes = _speedLimitKB * 1024;

    if(arg1 == 0)
    {
        ui->lbl_speed_info->setText(tr("Der Download nutzt die maximale Bandbreite deiner Leitung."));
    }
    else
    {
        double mbitSec = static_cast<double>(arg1) * 8.0;

        QString infoText;

        if(mbitSec >= 1000.0)
        {
            double gbitSec = mbitSec / 1000.0;
            infoText = QString::number(arg1) + tr(" (= ca. %1 Gbit/s)").arg(QString::number(gbitSec, 'f', 2));
        }
        else
        {
            infoText = QString::number(arg1) + tr(" (= ca. %1 Mbit/s)").arg(QString::number(mbitSec, 'f', 0));
        }

        ui->lbl_speed_info->setText(infoText);
    }
}



