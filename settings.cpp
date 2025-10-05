#include "settings.h"
#include "ui_settings.h"

#include <QDebug>

Settings::Settings(QWidget *parent) : QDialog(parent), ui(new Ui::Settings)
{
    ui->setupUi(this);

    ui->bar_openDownloadPath->setHidden(1);
    ui->chk_sfv->setDisabled(1);
    // ui->chk_unrar->setDisabled(1);
    ui->chk_unrar_del->setDisabled(1);

    ui->toolBox->setStyleSheet("QToolBox::tab { font-weight: bold; background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E1E1E1, stop: 0.4 #DDDDDD, stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3); }");

    loadSettings();

    connect(ui->chk_crc32, SIGNAL(stateChanged(int)), this, SLOT(crc32sfvCheckBoxes()));
    connect(ui->chk_sfv, SIGNAL(stateChanged(int)), this, SLOT(crc32sfvCheckBoxes()));

    connect(ui->chk_use_internal_unrar, SIGNAL(stateChanged(int)), this, SLOT(unrarCheckBoxes()));
    connect(ui->chk_unrar, SIGNAL(stateChanged(int)), this, SLOT(unrarCheckBoxes()));
    connect(ui->chk_unrar_del, SIGNAL(stateChanged(int)), this, SLOT(unrarCheckBoxes()));

    ui->line_proxy_port->setValidator(new QRegExpValidator(QRegExp("^(1|[1-9][0-9]{0,3}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$")));
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

// load settings from file
void Settings::loadSettings()
{
    QSettings config(QSettings::IniFormat, QSettings::UserScope, "SFDLSaugerPro", "config");

    config.beginGroup("main");
    _downloadPath = config.value("downloadPath").toString();
    ui->line_openDownloadPath->setText(_downloadPath);

    if(!_downloadPath.isEmpty())
    {
        QFileInfo path(_downloadPath);
        QStorageInfo storage(_downloadPath);

        if(!storage.isReadOnly() && path.exists() && path.isDir() && path.isWritable())
        {
            if(!_downloadPath.endsWith("/"))
            {
                _downloadPath = _downloadPath + "/";
            }

            ui->line_openDownloadPath->setText(_downloadPath);

            qlonglong bytesAvailable = storage.bytesAvailable()/1000/1000; // free space
            qlonglong bytesTotal = storage.bytesTotal()/1000/1000; // total space
            qlonglong progress = bytesTotal - bytesAvailable;

            ui->bar_openDownloadPath->setVisible(1);
            ui->bar_openDownloadPath->setAlignment(Qt::AlignCenter);
            ui->bar_openDownloadPath->setMaximum(bytesTotal);
            ui->bar_openDownloadPath->setMinimum(0);
            ui->bar_openDownloadPath->setValue(progress);
            ui->bar_openDownloadPath->setFormat(storage.displayName() + " (" + storage.fileSystemType() + ") " + bytes2Human(storage.bytesAvailable()) + tr(" von ") + bytes2Human(storage.bytesTotal()) + tr(" verfügbar"));
        }
        else
        {
            ui->line_openDownloadPath->setText("");
        }
    }
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

}

// save settings to file
void Settings::saveSettings()
{
    QSettings config(QSettings::IniFormat, QSettings::UserScope, "SFDLSaugerPro", "config");

    config.beginGroup("main");
    config.setValue("downloadPath", ui->line_openDownloadPath->text());
    _downloadPath = ui->line_openDownloadPath->text();
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
        home = QStandardPaths::locate(QStandardPaths::HomeLocation, QString(), QStandardPaths::LocateDirectory);
    }
    else
    {
        home = _downloadPath;
    }

    // select new download path
    QString downloadPath = QFileDialog::getExistingDirectory(this, tr("Wo sollen Downloads gespeichert werden?"), home, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if(!downloadPath.isEmpty())
    {
        QFileInfo path(downloadPath);
        QStorageInfo storage(downloadPath);

        QStringList errorReasons;
        if(storage.isReadOnly())
        {
            errorReasons << tr("Das Verzeichnis ist schreibgeschützt.");
        }
        if(!path.exists())
        {
            errorReasons << tr("Das Verzeichnis existiert nicht.");
        }
        if(!path.isDir())
        {
            errorReasons << tr("Die Auswahl ist kein Verzeichnis.");
        }
        if(!path.isWritable())
        {
            errorReasons << tr("Das Verzeichnis ist nicht beschreibbar.");
        }

        if (errorReasons.isEmpty())
        {
            if (!downloadPath.endsWith("/"))
            {
                downloadPath = downloadPath + "/";
            }

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


