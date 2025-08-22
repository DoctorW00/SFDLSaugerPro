#include "sfdlsauger.h"
#include "ui_sfdlsauger.h"

SFDLSauger::SFDLSauger(QWidget *parent) : QMainWindow(parent), ui(new Ui::SFDLSauger)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    loadWindowStatus();

    ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
    addLogText("SFDLSauger Pro v" + QString(APP_VERSION) + tr(" geladen und bereit!"));

    // menubar css
    ui->menuBar->setStyleSheet("QMenuBar { background: #a2a2a2 url(:/gfx/menubg.png) repeat-x; color: #f1f1f1; } QMenuBar::item:selected { color: black; }");

    if(QSystemTrayIcon::isSystemTrayAvailable())
    {
        icon = new QSystemTrayIcon(this);
        icon->setIcon(QIcon(":/gfx/icon.png"));
        icon->setToolTip(tr("SFDLSauger Pro"));
        icon->show();

        auto menu = new QMenu(this);
        icon->setContextMenu(menu);

        auto quitAction = new QAction(tr("Beenden"), this);
        quitAction->setIcon(QIcon(":/gfx/quit.png"));
        connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
        menu->addAction(quitAction);
    }

    // set shortcuts
    QShortcut *keyDevMode = new QShortcut(this);
    keyDevMode->setKey(Qt::CTRL + Qt::ALT + Qt::Key_D);
    connect(keyDevMode, SIGNAL(activated()), this, SLOT(devModeSwitch()));

    // initialize classes
    infoWindow = new About(this);
    settingsWindow = new Settings(this);

    // set global settings
    devMode = false;
}

SFDLSauger::~SFDLSauger()
{
    saveWindowStatus();

    delete ui;
}

void SFDLSauger::saveWindowStatus()
{
    QSettings config(QSettings::IniFormat, QSettings::UserScope, "SFDLSaugerPro", "config");
    config.beginGroup("window");
    config.setValue("position", this->geometry());
    config.setValue("maximized", this->isMaximized());
    config.endGroup();
}

void SFDLSauger::loadWindowStatus()
{
    QSettings config(QSettings::IniFormat, QSettings::UserScope, "SFDLSaugerPro", "config");

    QDesktopWidget *desktop = QApplication::desktop();

    int screenWidth, width;
    int screenHeight, height;
    int x, y;
    QSize windowSize;

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    windowSize = size();
    width = windowSize.width();
    height = windowSize.height();

    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;
    y -= 30;

    config.beginGroup("window");

    QVariant maximized = config.value("maximized").value<QString >();

    if(maximized.toString() == "true")
    {
        this->showMaximized();
    }
    else
    {
        QRect thisRect = config.value("position", QRect(QPoint(x,y),QSize(1024,768))).toRect();
        setGeometry(thisRect);
    }
    config.endGroup();
}

void SFDLSauger::devModeSwitch()
{
    if(devMode)
    {
        devMode = false;
        MsgWarning(tr("SFDLSauger Pro"), tr("Pro Modus deaktiviert!"));
    }
    else
    {
        devMode = true;
        MsgWarning(tr("SFDLSauger Pro"), tr("Pro Modus aktiviert!"));
    }
}

void SFDLSauger::addLogText(QString txt)
{
    QString datum = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss");

    ui->textEdit->moveCursor(QTextCursor::End);
    ui->textEdit->insertHtml("<font color=\"grey\">[" + datum + "]</font> " + txt + "<br />");
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
}

// open path in os file explorer
void SFDLSauger::openFileExplorer()
{

    QString id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());
    QString path = settingsWindow->_downloadPath + id;

    QDir pahtDir(path);
    if(pahtDir.exists())
    {
        QDesktopServices::openUrl(QUrl(path));
    }
    else
    {
        MsgWarning(id, "[" + path + tr("] Existiert (noch) nicht!"));
    }
}

void SFDLSauger::swapStartStopButton(QString id)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QToolBar *widget2 = widget1->findChild<QToolBar *>("toolbar");

    QToolButton *widget3 = widget2->findChild<QToolButton *>("toolStart");
    QToolButton *widget4 = widget2->findChild<QToolButton *>("toolStop");

    if(widget3->isEnabled())
    {
        widget3->setDisabled(1);
        widget4->setEnabled(1);
    }
    else
    {
        widget3->setEnabled(1);
        widget4->setDisabled(1);
    }
}

void SFDLSauger::disableStartStopButton(QString id)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QToolBar *widget2 = widget1->findChild<QToolBar *>("toolbar");

    QToolButton *widget3 = widget2->findChild<QToolButton *>("toolStart");
    QToolButton *widget4 = widget2->findChild<QToolButton *>("toolStop");

    widget3->setDisabled(1);
    widget4->setDisabled(1);
}

void SFDLSauger::startDownloadButton()
{
    QString id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());

    addLogText(id + tr(": Starte Download ..."));

    swapStartStopButton(id);
    changeCHKBOX(id, true);
    startDownload(id);
}

void SFDLSauger::MsgWarning(QString label, QString text)
{
    QMessageBox::warning(this, label, text);
}

QString SFDLSauger::seconds_to_DHMS(int duration)
{
    QString res;
    int seconds = (int) (duration % 60);
    duration /= 60;
    int minutes = (int) (duration % 60);
    duration /= 60;
    int hours = (int) (duration % 24);
    int days = (int) (duration / 24);
    if((hours == 0)&&(days == 0)&&(minutes == 0))
    {
        return res.sprintf("%02ds", seconds);
    }
    else if((hours == 0)&&(days == 0))
    {
        return res.sprintf("%02dm %02ds", minutes, seconds);
    }
    else if (days == 0)
    {
        return res.sprintf("%02dh %02dm %02ds", hours, minutes, seconds);
    }
    else
    {
        return res.sprintf("%ddt %02dh %02dm %02ds", days, hours, minutes, seconds);
    }
}

QString SFDLSauger::bytes2Human(float filesize)
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

void SFDLSauger::dragEnterEvent(QDragEnterEvent *e)
{
    if(e->mimeData()->hasUrls())
    {
        e->acceptProposedAction();
    }
}

void SFDLSauger::dropEvent(QDropEvent *e)
{
    foreach(const QUrl &url, e->mimeData()->urls())
    {
        QString fileName = url.toLocalFile();
        loadSFDL(fileName);
    }
}

void SFDLSauger::closeEvent(QCloseEvent *e)
{
    e->ignore();
    quitApp();
}

void SFDLSauger::quitApp()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("SFDLSauger Pro"), tr("SFDLSauger Pro wirklich beenden?"), QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        qApp->quit();
    }
}

void SFDLSauger::loadSFDL(QString file)
{
    addLogText(file + tr(" wird verarbeitet!"));

    auto sfdlFile = new sfdl();
    auto thread = new QThread;

    // connect(sfdlFile, SIGNAL(sendSFDLData(QStringList,QStringList)), this, SLOT(getSFDLData(QStringList,QStringList)));
    connect(sfdlFile, SIGNAL(sendSFDLData(QStringList,QStringList)), this, SLOT(chkSFDLData(QStringList,QStringList)));
    connect(sfdlFile, SIGNAL(sendWarning(QString,QString)), this, SLOT(MsgWarning(QString,QString)));
    connect(sfdlFile, SIGNAL(sendLogText(QString)), this, SLOT(addLogText(QString)));
    connect(thread, SIGNAL(started()), sfdlFile, SLOT(readSFDL()));
    connect(thread, SIGNAL(finished()), thread, SLOT(quit()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    // sfdlFile->readSFDL(file);
    sfdlFile->setSFDL(file, settingsWindow->_sfdlPasswords);
    sfdlFile->moveToThread(thread);

    thread->start();
}

void SFDLSauger::loadSFDLConsol(int instanceId, QByteArray message)
{
    instanceId;

    QString argument = message;
    QStringList arguments = argument.split("|");
    arguments.removeFirst();                      // remove app
    arguments.removeAll(QString(""));             // remove empty

    foreach(QString s, arguments)
    {
        QFileInfo chkFile(s);
        if(chkFile.exists())
        {
            loadSFDL(s);
        }
    }

}

void SFDLSauger::chkSFDLData(QStringList data, QStringList files)
{
    if(!files.count())
    {
        addLogText(data.at(1).split("|").at(1) + tr(": Lade FTP-Inhaltsverzeichnis ..."));

        auto listFTP = new FTPListFiles;
        auto thread = new QThread;

        connect(listFTP, SIGNAL(sendWarning(QString,QString)), this, SLOT(MsgWarning(QString,QString)));
        connect(listFTP, SIGNAL(sendLogText(QString)), this, SLOT(addLogText(QString)));
        connect(listFTP, SIGNAL(sendFTPData(QStringList,QStringList)), this, SLOT(getSFDLData(QStringList,QStringList)));

        listFTP->ftpList(data.at(7).split("|").at(1),           // host
                         data.at(8).split("|").at(1).toInt(),   // port
                         data.at(9).split("|").at(1),           // user
                         data.at(10).split("|").at(1),          // pass
                         data.at(21).split("|").at(1),          // path
                         settingsWindow->_ftpProxyHost,
                         settingsWindow->_ftpProxyPort,
                         settingsWindow->_ftpProxyUser,
                         settingsWindow->_ftpProxyPass,
                         data
                         );

        listFTP->moveToThread(thread);
        thread->start();
    }
    else
    {
        getSFDLData(data, files);
    }
}

void SFDLSauger::getSFDLData(QStringList data, QStringList files)
{
    if(data.count() == 0)
    {
        #ifdef QT_DEBUG
            qDebug() << "getSFDLData: Empty data";
        #endif
        return;
    }

    // add new tab and get id
    QString tabName;
    tabName = data.at(1).split("|").at(1);
    tabName = checkSameDownloads(tabName);

    g_tabDownloads.insert(tabName, 0); // set active download to zero for this tab
    int dataid = addTab(tabName); // add new tab

    QTableWidget *status_tbl = NULL;
    QTableWidget *data_tbl = NULL;
    QTableWidget *file_tbl = NULL;
    QWidget *widget = ui->tabWidget->widget(dataid);

    QList<QTableWidget *> allTableWidgets = widget->findChildren<QTableWidget *>();

    // if(allTableWidgets.count() != 1)
    if(allTableWidgets.count() != 3)
    {
        return;
    }

    // status table
    status_tbl = allTableWidgets[2];
    // status_tbl->setColumnCount(17);
    status_tbl->setColumnCount(18);
    status_tbl->setRowCount(1);
    status_tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
    status_tbl->setSelectionMode(QAbstractItemView::NoSelection);
    status_tbl->setSelectionBehavior(QAbstractItemView::SelectItems);
    status_tbl->setShowGrid(true);
    // status_tbl->horizontalHeader()->hide();
    status_tbl->verticalHeader()->hide();
    status_tbl->setAlternatingRowColors(false);
    // data_tbl->setColumnWidth(0, 200);
    // status_tbl->setFixedHeight(30);
    // status_tbl->setMinimumHeight(30);
    status_tbl->setMaximumHeight(55);
    // status_tbl->setRowHeight(0, 30);
    // status_tbl->setWordWrap(1);

    QStringList statusList;
    statusList.push_back(tr("ID"));
    statusList.push_back(tr("Download"));
    statusList.push_back(tr("Host"));
    statusList.push_back(tr("Port"));
    statusList.push_back(tr("User"));
    statusList.push_back(tr("Pass"));
    statusList.push_back(tr("Bytes"));
    statusList.push_back(tr("Größe"));
    statusList.push_back(tr("Bytes geladen"));
    statusList.push_back(tr("Geladen"));
    statusList.push_back(tr("Status"));
    statusList.push_back(tr("Status ID"));
    statusList.push_back(tr("Time Start"));
    statusList.push_back(tr("Time Last"));
    statusList.push_back(tr("Speed"));
    statusList.push_back(tr("Zeit"));
    statusList.push_back(tr("Time Stop"));
    statusList.push_back(tr("RESUME"));

    status_tbl->setHorizontalHeaderLabels(statusList);

    // add sessionid
    QFont statusFONT(defaultFont.defaultFamily(), 10, QFont::Normal);

    // ID
    QTableWidgetItem *SESSIONID = new QTableWidgetItem(QString::number(g_sessionID));
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 0, SESSIONID);
    g_sessionID++;

    // Download
    QTableWidgetItem *DOWNLOADNAME = new QTableWidgetItem(tabName);
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 1, DOWNLOADNAME);

    // Host
    QTableWidgetItem *SRV_HOST = new QTableWidgetItem(data.at(7).split("|").at(1));
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 2, SRV_HOST);

    // Port
    QTableWidgetItem *SRV_PORT = new QTableWidgetItem(data.at(8).split("|").at(1));
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 3, SRV_PORT);

    // User
    QTableWidgetItem *SRV_USER = new QTableWidgetItem(data.at(9).split("|").at(1));
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 4, SRV_USER);

    // Pass
    QTableWidgetItem *SRV_PASS = new QTableWidgetItem(data.at(10).split("|").at(1));
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 5, SRV_PASS);

    // Bytes
    QTableWidgetItem *DOWNLOADEDBYTES = new QTableWidgetItem("0");
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 8, DOWNLOADEDBYTES);

    // Größe
    QTableWidgetItem *DOWNLOADEDHUMAN = new QTableWidgetItem(bytes2Human(0));
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 9, DOWNLOADEDHUMAN);

    // Bytes geladen
    QTableWidgetItem *BYTESLOADED = new QTableWidgetItem("0");
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 10, BYTESLOADED);

    // Geladen
    QTableWidgetItem *HUMANLOADED = new QTableWidgetItem(bytes2Human(0));
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 11, HUMANLOADED);

    // Status
    QTableWidgetItem *STATUSMSG = new QTableWidgetItem(tr("Bereit!"));
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 12, STATUSMSG);

    // Status ID
    QTableWidgetItem *STATUSID = new QTableWidgetItem("0");
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 13, STATUSID);

    // Time Start
    QTableWidgetItem *TIME_START = new QTableWidgetItem("0");
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 14, TIME_START);

    // Time Last
    QTableWidgetItem *TIME_LAST = new QTableWidgetItem("0");
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 15, TIME_LAST);

    // Time Stop
    QTableWidgetItem *TIME_STOP = new QTableWidgetItem("0");
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 16, TIME_STOP);

    // Donwload Resume
    QTableWidgetItem *RESUME = new QTableWidgetItem("0");
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 17, RESUME);

    status_tbl->resizeColumnToContents(1);
    status_tbl->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    status_tbl->horizontalScrollBar()->setDisabled(1);
    status_tbl->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    status_tbl->setHidden(1);

    if(devMode)
    {
        #ifdef QT_DEBUG
        status_tbl->setVisible(1);
        #endif
    }

    // data table
    int dataColumCount = 2;
    int dataRowCount = data.count();

    data_tbl = allTableWidgets[1];
    data_tbl->setColumnCount(dataColumCount);
    data_tbl->setRowCount(dataRowCount +1);
    data_tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
    data_tbl->setSelectionMode(QAbstractItemView::SingleSelection);
    data_tbl->setSelectionBehavior(QAbstractItemView::SelectRows);
    data_tbl->setShowGrid(false);
    data_tbl->horizontalHeader()->hide();
    data_tbl->verticalHeader()->hide();
    data_tbl->setAlternatingRowColors(true);
    data_tbl->setColumnWidth(21, 45);

    // set data_tbl data
    for(int i = 0; i < dataRowCount; i++)
    {
        QFont labelFont(defaultFont.defaultFamily(), 10, QFont::Bold);
        QString dataInfo = data.at(i).split("|").at(0);

        QTableWidgetItem *LABEL = new QTableWidgetItem(dataInfo);
        LABEL->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        LABEL->setFont(labelFont);
        data_tbl->setItem(i, 0, LABEL);

        QFont dataFont(defaultFont.defaultFamily(), 10, QFont::Normal);

        QString dataContent;
        dataContent = data.at(i).split("|").at(1);

        QTableWidgetItem *DATA = new QTableWidgetItem(dataContent);
        DATA->setFont(dataFont);
        data_tbl->setItem(i, 1, DATA);
    }

    data_tbl->resizeColumnToContents(0);
    data_tbl->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    // hide content from non dev users
    if(!devMode)
    {
        data_tbl->hideRow(7);
        data_tbl->hideRow(8);
        data_tbl->hideRow(9);
        data_tbl->hideRow(10);
        data_tbl->hideRow(21);
    }

    // file table
    // int fileColumCount = 15;
    int fileColumCount = 16;

    file_tbl = allTableWidgets[0];
    file_tbl->setColumnCount(fileColumCount);
    file_tbl->setRowCount(files.count());
    //file_tbl->horizontalHeader()->hide();
    file_tbl->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    file_tbl->verticalHeader()->hide();
    file_tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
    file_tbl->setSelectionMode(QAbstractItemView::SingleSelection);
    file_tbl->setSelectionBehavior(QAbstractItemView::SelectRows);

    QStringList headerList;
    headerList.push_back(tr(""));                     // chkbox
    headerList.push_back(tr("FTP Pfad"));             // full file path on ftp server
    headerList.push_back(tr("Datei"));                // clean file path - relativ
    headerList.push_back(tr("in Bytes"));
    headerList.push_back(tr("Größe"));
    headerList.push_back(tr(""));                     // progress bar
    headerList.push_back(tr("Status"));               // status message
    headerList.push_back(tr(""));                     // status id
    headerList.push_back(tr("Zeit Start"));           // time donload started
    headerList.push_back(tr("Zeit Last"));            // time last update
    headerList.push_back(tr("Geschwindigkeit"));      // speed /s
    headerList.push_back(tr("Zeit"));                 // total time counter
    headerList.push_back(tr(""));                     // last download progress update
    headerList.push_back(tr("CRC32"));                // crc32
    headerList.push_back(tr("SFV"));                  // sfv check icon
    headerList.push_back(tr("RESUME"));               // resume download
    file_tbl->setHorizontalHeaderLabels(headerList);

    connect(file_tbl, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(fileTableDoubleClicked(int,int)));

    qlonglong totalDownloadSize = 0;
    file_tbl->setDisabled(1); // disable until all finished

    // set files_tbl data
    bool fileError = false;
    for(int i = 0; i < files.count(); i++)
    {
        QString filePathSplit = files.at(i).split("|").at(0);
        qint16 pos = filePathSplit.lastIndexOf(QChar('/'));
        QString f3 = filePathSplit.mid(pos);

        if(f3.startsWith("/")) // remove first slash
        {
            f3.remove(0, 1);
        }

        // exldude files from download
        bool exludeFile = false;
        QStringList excludeFiles = settingsWindow->_excludeFilesFromDownload;
        for(int i = 0; i < excludeFiles.size(); i++)
        {
            QRegularExpression regex(QRegularExpression::escape(excludeFiles.at(i)), QRegularExpression::CaseInsensitiveOption);
            QRegularExpressionMatch match = regex.match(f3);

            if(match.hasMatch())
            {
                exludeFile = true;
                break;
            }
        }

        // QFont filelFont("Times", 10, QFont::Normal);
        QFont filelFont(defaultFont.defaultFamily(), 10, QFont::Normal);

        QTableWidgetItem *CHKBOX = new QTableWidgetItem();
        if(exludeFile)
        {
            CHKBOX->setCheckState(Qt::Unchecked); // exclude download
        }
        else
        {
            CHKBOX->setCheckState(Qt::Checked);
        }
        CHKBOX->setTextAlignment(Qt::AlignCenter);
        file_tbl->setItem(i, 0, CHKBOX);

        QTableWidgetItem *FULLFILEPATH = new QTableWidgetItem(files.at(i).split("|").at(0));
        FULLFILEPATH->setFont(filelFont);
        file_tbl->setItem(i, 1, FULLFILEPATH);

        // clean file name + sub file structure
        if(tabName != data.at(1).split("|").at(1))
        {

            fileError = true;
            addLogText("<font color=\"red\">" + tabName + tr(": Datei / Pfaderkenntung nicht möglich. Pfad unterscheidet sich vom Titel. (1)</font>"));
            break;
        }

        QTableWidgetItem *FILE = new QTableWidgetItem(f3);
        FILE->setFont(filelFont);
        file_tbl->setItem(i, 2, FILE);

        QFont sizeFont(defaultFont.defaultFamily(), 10, QFont::Normal);

        totalDownloadSize += files.at(i).split("|").at(1).toLongLong();

        QTableWidgetItem *SIZE = new QTableWidgetItem(files.at(i).split("|").at(1));
        SIZE->setFont(sizeFont);
        file_tbl->setItem(i, 3, SIZE);

        QTableWidgetItem *SIZEHUMAN = new QTableWidgetItem(bytes2Human(files.at(i).split("|").at(1).toLongLong()));
        SIZE->setFont(sizeFont);
        file_tbl->setItem(i, 4, SIZEHUMAN);

        QProgressBar *PROGBAR = new QProgressBar();
        PROGBAR->setMinimum(0);
        PROGBAR->setMaximum(100);
        PROGBAR->setValue(0);
        PROGBAR->setTextVisible(1);
        PROGBAR->setStyleSheet("QProgressBar { border: 1px solid #420000; margin: 1px; border-radius: 5px; text-align: center; } QProgressBar::chunk { background-color: #c52222; width: 1px; margin: 0px; }");

        PROGBAR->setObjectName("pbarIn_" + QString::number(i));
        file_tbl->setCellWidget(i, 5, PROGBAR);

        QTableWidgetItem *STATUSMSG = new QTableWidgetItem(tr("Ready!"));
        STATUSMSG->setFont(filelFont);
        file_tbl->setItem(i, 6, STATUSMSG);

        QTableWidgetItem *STATUS = new QTableWidgetItem("0");
        STATUS->setFont(filelFont);
        file_tbl->setItem(i, 7, STATUS);

        QTableWidgetItem *TIME_START = new QTableWidgetItem("0");
        TIME_START->setFont(filelFont);
        file_tbl->setItem(i, 8, TIME_START);

        QTableWidgetItem *TIME_LAST = new QTableWidgetItem("0");
        TIME_LAST->setFont(filelFont);
        file_tbl->setItem(i, 9, TIME_LAST);

        QTableWidgetItem *MB_SECONDS = new QTableWidgetItem(bytes2Human(0));
        MB_SECONDS->setFont(filelFont);
        file_tbl->setItem(i, 10, MB_SECONDS);

        QTableWidgetItem *TOTAL_TIME = new QTableWidgetItem(seconds_to_DHMS(0));
        TOTAL_TIME->setFont(filelFont);
        TOTAL_TIME->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        file_tbl->setItem(i, 11, TOTAL_TIME);

        QTableWidgetItem *LAST_READ = new QTableWidgetItem("0");
        LAST_READ->setFont(filelFont);
        file_tbl->setItem(i, 12, LAST_READ);

        QTableWidgetItem *FILE_CRC32 = new QTableWidgetItem("");
        QFont crc32lFont("Monospace", 10, QFont::Normal);
        crc32lFont.setStyleHint(QFont::TypeWriter);
        FILE_CRC32->setFont(crc32lFont);
        FILE_CRC32->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        file_tbl->setItem(i, 13, FILE_CRC32);

        QTableWidgetItem *FILE_SFV = new QTableWidgetItem("");
        // FILE_SFV->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
        FILE_SFV->setTextAlignment(Qt::AlignHCenter | Qt::AlignCenter);
        file_tbl->setItem(i, 14, FILE_SFV);

        QTableWidgetItem *RESUME = new QTableWidgetItem("0");
        TIME_LAST->setFont(filelFont);
        file_tbl->setItem(i, 15, RESUME);
    }

    // connect after data populated
    connect(file_tbl, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(tblItemChanged(QTableWidgetItem*)));

    // add total download size to status table
    QTableWidgetItem *DLSIZEBYTES = new QTableWidgetItem(QString::number(totalDownloadSize));
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 6, DLSIZEBYTES);

    // total download size human
    QTableWidgetItem *DLSIZEHUMAN = new QTableWidgetItem(bytes2Human(totalDownloadSize));
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 7, DLSIZEHUMAN);

    // add total download size to data table
    QFont labelFont2(defaultFont.defaultFamily(), 10, QFont::Bold);
    QTableWidgetItem *downloadSIZE1 = new QTableWidgetItem("TotalDownloadSize");
    downloadSIZE1->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    downloadSIZE1->setFont(labelFont2);
    data_tbl->setItem(data_tbl->rowCount() -1, 0, downloadSIZE1);

    QFont dataFont2(defaultFont.defaultFamily(), 10, QFont::Normal);
    QTableWidgetItem *downloadSIZE2 = new QTableWidgetItem(QString::number(totalDownloadSize) + " [" + bytes2Human(totalDownloadSize) + "]");
    downloadSIZE2->setFont(dataFont2);
    data_tbl->setItem(data_tbl->rowCount() -1, 1, downloadSIZE2);

    file_tbl->setShowGrid(0);
    file_tbl->setAlternatingRowColors(1);
    file_tbl->setColumnWidth(0, 10);
    file_tbl->setColumnWidth(11, 55);
    file_tbl->setColumnWidth(14, 16); // sfv check icon table
    file_tbl->resizeColumnToContents(2);
    file_tbl->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    status_tbl->resizeColumnToContents(1);
    status_tbl->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    // hide content from non dev users
    file_tbl->hideColumn(1);
    file_tbl->hideColumn(3);
    file_tbl->hideColumn(7);
    file_tbl->hideColumn(8);
    file_tbl->hideColumn(9);
    file_tbl->hideColumn(12);
    file_tbl->hideColumn(13);
    file_tbl->hideColumn(14);
    file_tbl->hideColumn(15);

    if(devMode)
    {
        #ifdef QT_DEBUG
        file_tbl->showColumn(1);
        file_tbl->showColumn(3);
        file_tbl->showColumn(7);
        file_tbl->showColumn(8);
        file_tbl->showColumn(9);
        file_tbl->showColumn(12);
        file_tbl->showColumn(13);
        file_tbl->showColumn(14);
        file_tbl->showColumn(15);
        #endif
    }

    chkForExisitingFiles(tabName);

    // enable table if the download got files
    QWidget *thisWidget = ui->tabWidget->findChild<QWidget *>(tabName);
    QLabel *statusLabel = thisWidget->findChild<QLabel *>("mStatusText");

    if(fileError)
    {
        file_tbl->clear();
        file_tbl->setRowCount(0);
        statusLabel->setText(tr("Fehler! Bitte Logs konsultieren ..."));
        return;
    }

    if(files.count())
    {
        file_tbl->setEnabled(1);

        thisWidget->setEnabled(1);
        statusLabel->setText(tr("Bereit!"));
    }
    else
    {
        statusLabel->setText(tr("Fehler! Bitte Logs konsultieren ..."));
    }

    // focus on new tab
    ui->tabWidget->setCurrentIndex(dataid);
}

void SFDLSauger::fileTableDoubleClicked(int row, int column)
{
    QString id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());

    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget3 = widget1->findChild<QTableWidget *>("files");

    // if download is running
    auto flags = widget3->item(0, 0)->flags();
    if(flags.testFlag(Qt::ItemIsUserCheckable) == false)
    {
        return;
    }

    if(column == 0)
    {
        for(int i = 0; i < widget3->rowCount(); i++)
        {
            if(widget3->item(i, 0)->checkState() == Qt::Checked)
            {
                widget3->item(i, 0)->setCheckState(Qt::Unchecked);
            }
            else
            {
                widget3->item(i, 0)->setCheckState(Qt::Checked);
            }
        }
    }
    else
    {
        if(widget3->item(row, 0)->checkState() == Qt::Checked)
        {
            widget3->item(row, 0)->setCheckState(Qt::Unchecked);
        }
        else
        {
            widget3->item(row, 0)->setCheckState(Qt::Checked);
        }
    }

    updateTotalDownloadSize(id);
}

void SFDLSauger::updateTotalDownloadSize(QString id)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("status");
    QTableWidget *widget3 = widget1->findChild<QTableWidget *>("files");

    qlonglong newTotalDownloadSize = 0;

    for(int i = 0; i < widget3->rowCount(); i++)
    {
        if(widget3->item(i, 0)->checkState() == Qt::Checked)
        {
            newTotalDownloadSize += widget3->item(i, 3)->text().toLongLong();
        }
    }

    widget2->item(0, 6)->setText(QString::number(newTotalDownloadSize));
    widget2->item(0, 7)->setText(bytes2Human(newTotalDownloadSize));
}

void SFDLSauger::tblItemChanged(QTableWidgetItem *item)
{
    item;

    QString id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());
    updateTotalDownloadSize(id);
}

void SFDLSauger::changeCHKBOX(QString id, bool lock)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget3 = widget1->findChild<QTableWidget *>("files");

    for(int i = 0; i < widget3->rowCount(); i++)
    {
        if(lock)
        {
            widget3->item(i, 0)->setFlags(widget3->item(i, 0)->flags() & ~Qt::ItemIsUserCheckable);
        }
        else
        {
            widget3->item(i, 0)->setFlags(widget3->item(i, 0)->flags() | Qt::ItemIsUserCheckable);
        }
    }
}

void SFDLSauger::tabSelected()
{
    #ifdef QT_DEBUG
        qDebug() << "TabSelected: " << ui->tabWidget->currentIndex();
    #endif
}

int SFDLSauger::addTab(QString tabText)
{   
    // QWidget *widget = new QWidget;
    widget = new QWidget;
    widget->setObjectName(tabText);
    // widget->setStyleSheet("background: #e2e2e2;");
    // widget->setStyleSheet("background: #FFFFFF;");

    QGridLayout *layout = new QGridLayout;
    QSplitter *splitter = new QSplitter(widget);
    // splitter->setOrientation(Qt::Horizontal);
    splitter->setOrientation(Qt::Vertical);
    splitter->setChildrenCollapsible(false);

    QString setTabText;
    // QString cleanTabText = tabText.split("|").at(1);
    QString cleanTabText = tabText;

    if(cleanTabText.length() > maxTabTextLength)
    {
        setTabText = cleanTabText.left(maxTabTextLength) + "...";
    }
    else
    {
        setTabText = cleanTabText;
    }

    // ui->tabWidget->setElideMode(Qt::ElideMiddle);
    ui->tabWidget->setElideMode(Qt::ElideNone);

    int id = ui->tabWidget->addTab(widget, setTabText);
    ui->tabWidget->setTabToolTip(id, cleanTabText);

    QFont releaseFont(defaultFont.defaultFamily(), 11, QFont::Bold);
    QLabel *rlsText = new QLabel();
    rlsText->setFont(releaseFont);
    rlsText->setText(tabText);
    rlsText->setStyleSheet("background: #ffffeb; border: 1px solid #f0f0f0; padding: 3px;");
    layout->addWidget(rlsText);

    // add tool bar
    QToolBar *tbar = new QToolBar();
    tbar->setObjectName("toolbar");
    tbar->setFloatable(0);
    tbar->setMovable(0);
    tbar->setOrientation(Qt::Horizontal);
    tbar->setIconSize(QSize(30,30));
    tbar->setStyleSheet("background: #f0f0f0;");

    // add start button
    QAction *btnStart = tbar->addAction(tr("Start Download"), [](bool) {});
    QToolButton *toolStart = dynamic_cast<QToolButton*>(tbar->widgetForAction(btnStart));
    toolStart->setObjectName("toolStart");
    toolStart->setIcon(QIcon(":/gfx/start.png"));
    toolStart->setCursor(Qt::PointingHandCursor);
    connect(btnStart, SIGNAL(triggered(bool)), this, SLOT(startDownloadButton()));

    // add stop button
    QAction *btnStop = tbar->addAction(tr("Stop Download"), [](bool) {});
    QToolButton *toolStop = dynamic_cast<QToolButton*>(tbar->widgetForAction(btnStop));
    toolStop->setObjectName("toolStop");
    toolStop->setIcon(QIcon(":/gfx/stop.png"));
    toolStop->setCursor(Qt::PointingHandCursor);
    toolStop->setDisabled(1);
    connect(btnStop, SIGNAL(triggered(bool)), this, SLOT(stopDownload()));

    // add open folder button
    QAction *btnFolder = tbar->addAction(tr("Downloadpfad öffnen"), [](bool) {});
    QToolButton *toolFolder = dynamic_cast<QToolButton*>(tbar->widgetForAction(btnFolder));
    toolFolder->setIcon(QIcon(":/gfx/folder.png"));
    toolFolder->setCursor(Qt::PointingHandCursor);
    connect(btnFolder, SIGNAL(triggered(bool)), this, SLOT(openFileExplorer()));

    // add open sfdl info button
    QAction *btnInfo = tbar->addAction(tr("SFDL Info"), [](bool) {});
    QToolButton *sfdlInfo = dynamic_cast<QToolButton*>(tbar->widgetForAction(btnInfo));
    sfdlInfo->setIcon(QIcon(":/gfx/info.png"));
    sfdlInfo->setCursor(Qt::PointingHandCursor);
    connect(btnInfo, SIGNAL(triggered(bool)), this, SLOT(openCloseSFDLTable()));

    tbar->addSeparator();

    // add filezilla button
    QAction *btnFileZilla = tbar->addAction(tr("Mit FileZilla öffnen"), [](bool) {});
    QToolButton *toolFileZilla = dynamic_cast<QToolButton*>(tbar->widgetForAction(btnFileZilla));
    toolFileZilla->setIcon(QIcon(":/gfx/filezilla.png"));
    toolFileZilla->setCursor(Qt::PointingHandCursor);
    connect(btnFileZilla, SIGNAL(triggered(bool)), this, SLOT(openInFileZilla()));

    // add ftprush button
    QAction *btnFtpRush = tbar->addAction(tr("Mit FTP Rush öffnen"), [](bool) {});
    QToolButton *toolFtpRush = dynamic_cast<QToolButton*>(tbar->widgetForAction(btnFtpRush));
    toolFtpRush->setIcon(QIcon(":/gfx/ftprush.png"));
    toolFtpRush->setCursor(Qt::PointingHandCursor);

    // add flashfxp button
    QAction *btnFlashFXP = tbar->addAction(tr("Mit FlashFXP öffnen"), [](bool) {});
    QToolButton *toolFlashFXP = dynamic_cast<QToolButton*>(tbar->widgetForAction(btnFlashFXP));
    toolFlashFXP->setIcon(QIcon(":/gfx/flashfxp.png"));
    toolFlashFXP->setCursor(Qt::PointingHandCursor);

    // add winscp button
    QAction *btnWinSCP = tbar->addAction(tr("Mit WinSCP öffnen"), [](bool) {});
    QToolButton *toolWinSCP = dynamic_cast<QToolButton*>(tbar->widgetForAction(btnWinSCP));
    toolWinSCP->setIcon(QIcon(":/gfx/winscp.png"));
    toolWinSCP->setCursor(Qt::PointingHandCursor);
    // connect(btnWinSCP, SIGNAL(triggered(bool)), this, SLOT(sfvCheckX()));
    // connect(btnWinSCP, SIGNAL(triggered(bool)), this, SLOT(unrarFilesX()));

    // only on windows
    #if defined(Q_OS_WIN)
        toolFtpRush->setEnabled(1);
        toolFlashFXP->setEnabled(1);
        toolWinSCP->setEnabled(1);
    #else
        toolFtpRush->setDisabled(1);
        toolFlashFXP->setDisabled(1);
        toolWinSCP->setDisabled(1);
    #endif

    if(!devMode)
    {
        toolFileZilla->setDisabled(1);
        toolFtpRush->setDisabled(1);
        toolFlashFXP->setDisabled(1);
        toolWinSCP->setDisabled(1);
    }

    tbar->addSeparator();

    QFont MAXTHREADSDownloadFont(defaultFont.defaultFamily(), 10, QFont::Bold);
    QSpinBox *MAXTHREADS = new QSpinBox();
    MAXTHREADS->setObjectName("maxdownloads");
    MAXTHREADS->setMinimum(1);
    MAXTHREADS->setMaximum(10);
    MAXTHREADS->setSingleStep(1);
    MAXTHREADS->setValue(3);
    MAXTHREADS->setFixedHeight(30);
    MAXTHREADS->setFixedWidth(50);
    MAXTHREADS->setFont(MAXTHREADSDownloadFont);
    MAXTHREADS->setAlignment(Qt::AlignCenter);
    MAXTHREADS->setToolTip(tr("Maximun Download Threads"));
    connect(MAXTHREADS, SIGNAL(valueChanged(int)), this, SLOT(startDownloadButton()));
    tbar->addWidget(MAXTHREADS);

    if(!devMode)
    {
        MAXTHREADS->setDisabled(1);
    }

    QProgressBar *PROGBAR = new QProgressBar();
    PROGBAR->setObjectName("mProgBar");
    PROGBAR->setMinimum(0);
    PROGBAR->setMaximum(100);
    PROGBAR->setValue(0);
    PROGBAR->setTextVisible(1);
    PROGBAR->setStyleSheet("QProgressBar { background: white; height: 30px; margin: 0 5px 0 5px; border: 1px solid #420000; border-radius: 5px; text-align: center; } QProgressBar::chunk { background-color: #c52222; width: 1px; margin: 0px; }");
    PROGBAR->setFixedWidth(150);
    tbar->addWidget(PROGBAR);

    QFont totalDownloadFont(defaultFont.defaultFamily(), 10, QFont::Bold);
    QLabel *totalDownloadText = new QLabel();
    totalDownloadText->setObjectName("mStatusText");
    totalDownloadText->setFont(totalDownloadFont);
    totalDownloadText->setText(tr("Wird geladen ..."));
    totalDownloadText->setStyleSheet("height: 30px; padding: 3px;");
    totalDownloadText->setMinimumWidth(320);
    tbar->addWidget(totalDownloadText);

    tbar->show();

    QTableWidget *status = new QTableWidget();
    status->setObjectName("status");

    QTableWidget *data = new QTableWidget();
    data->setObjectName("data");

    QTableWidget *files = new QTableWidget();
    files->setObjectName("files");

    layout->addWidget(tbar);
    // layout->addWidget(PROUNRAR);
    layout->addWidget(status);
    splitter->addWidget(data);
    splitter->addWidget(files);
    layout->addWidget(splitter);
    widget->setLayout(layout);

    widget->setDisabled(1);

    return id;
}

// toggle button to open and close the SFDL info table
void SFDLSauger::openCloseSFDLTable()
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex()));
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("data");

    if(widget2->isHidden())
    {
        widget2->setHidden(0);
    }
    else
    {
        widget2->setHidden(1);
    }
}

// check if the same download is already present and
// if so add / increase by number
QString SFDLSauger::checkSameDownloads(QString name)
{
    int dblEntry = 0;

    for(int i = 0; i < ui->tabWidget->count(); i++)
    {
        QString id = ui->tabWidget->tabToolTip(i);
        /*
        if(id.split(QRegExp("\\([0-9]+\\)")).at(0) == name)
        {
            dblEntry++;
        }
        */
        if(id.split(QRegularExpression("\\([0-9]+\\)")).at(0) == name)
        {
            dblEntry++;
        }
    }

    if(dblEntry)
    {
        name = name + "(" + QString::number(dblEntry) + ")";
    }

    return name;
}

// clean path and file from file full path
QStringList SFDLSauger::dirFromFilePath(QString filePath)
{
    QRegularExpression regex("[/\\\\]");
    QStringList pathParts = filePath.split(regex);
    QString fileName = pathParts.last();
    QString cleanPath = filePath.left(filePath.length() - fileName.length());

    QStringList result;
    result.append(cleanPath);
    result.append(fileName);

    return result;
}

// stop all downloads in tab
void SFDLSauger::stopDownload()
{
    int tabIndex = ui->tabWidget->currentIndex();
    QString id = ui->tabWidget->tabToolTip(tabIndex);

    foreach(FTPDownload* w, g_Worker)
    {
        if(w->_working && id == w->_id && w->thread()->isRunning())
        {
            updateDownloadFileStatus(id, w->_tableRow, tr("User Abbruch!"), 9);

            w->ftp->abort();
            w->ftp->thread()->quit();
            w->ftp->thread()->wait();
            w->ftp->deleteLater();
            w->abort();
            w->thread()->quit();
            w->thread()->wait();
            w->deleteLater();
        }
    }

    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(ui->tabWidget->tabToolTip(tabIndex));

    // status table
    // qint64 timestamp = QDateTime::currentDateTime().toTime_t();
    QTableWidget *wStatus = widget1->findChild<QTableWidget *>("status");

    qlonglong t_startTime = wStatus->item(0, 12)->text().toLongLong();
    qlonglong t_lastTime = wStatus->item(0, 13)->text().toLongLong();
    qlonglong t_stopTime = wStatus->item(0, 16)->text().toLongLong();
    qlonglong t_updateTime = 0;

    if(t_stopTime)
    {
        t_updateTime = (t_lastTime - t_startTime) + t_updateTime;
    }
    else
    {
        t_updateTime = t_lastTime - t_startTime;
    }

    wStatus->item(0, 16)->setText(QString::number(t_updateTime));

    QToolBar *widget2 = widget1->findChild<QToolBar *>("toolbar");

    QToolButton *widget3 = widget2->findChild<QToolButton *>("toolStart");
    widget3->setEnabled(1);

    QToolButton *widget4 = widget2->findChild<QToolButton *>("toolStop");
    widget4->setDisabled(1);

    // update file resume data
    qint64 totalResume = 0;
    QTableWidget *widget5 = widget1->findChild<QTableWidget *>("files");
    for(int i = 0; i < widget5->rowCount(); i++)
    {
        qint64 resumeData = widget5->item(i, 12)->text().toLongLong();

        if(widget5->item(i, 0)->checkState() == Qt::Checked && widget5->item(i, 7)->text().toInt() != 10)
        {
            widget5->item(i, 15)->setText(QString::number(resumeData));
        }

        totalResume += resumeData;
    }

    if(totalResume)
    {
        QTableWidget *widget6 = widget1->findChild<QTableWidget *>("status");
        widget6->item(0, 17)->setText(QString::number(totalResume));
    }

    changeCHKBOX(id, false);

    // set ative download for this tab/id/sfdl
    g_tabDownloads[id] = 0;
}

void SFDLSauger::downloadError(QString error)
{
    addLogText(tr("<font color=\"red\">[") + error + tr("] Allgemeiner FTP Download Fehler!</font>"));
    MsgWarning(tr("Download Fehler"), "[" + error + tr("] Allgemeiner FTP Download Fehler!"));
}

// start download in tab
void SFDLSauger::startDownload(QString tabID = "")
{
    if(g_runningDownloads < g_maxDownloads)
    {
        QString id;

        if(tabID.isEmpty())
        {
            id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());
        }
        else
        {
            id = tabID;
        }

        QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
        QTableWidget *widget2 = widget1->findChild<QTableWidget *>("data");

        QString host = widget2->item(7, 1)->text();   // host
        QString port = widget2->item(8, 1)->text();   // port
        QString user = widget2->item(9, 1)->text();   // user
        QString pass = widget2->item(10, 1)->text();  // pass

        QTableWidget *widget3 = widget1->findChild<QTableWidget *>("files");

        for(int i = 0; i < widget3->rowCount(); i++)
        {
            if(g_runningDownloads >= g_maxDownloads)
            {
                break;
            }

            // set ative download for this tab/id/sfdl
            int activeDownload = g_tabDownloads[id];

            QToolBar *widget4 = widget1->findChild<QToolBar *>("toolbar");
            QSpinBox *widget5 = widget4->findChild<QSpinBox *>("maxdownloads");

            if(activeDownload >= widget5->value())
            {
                break;
            }

            // if(widget3->item(i, 0)->checkState() == Qt::Checked && widget3->item(i, 7)->text().toInt() == 0 || widget3->item(i, 7)->text().toInt() == 9)
            if(widget3->item(i, 0)->checkState() == Qt::Checked &&
                    widget3->item(i, 7)->text().toInt() == 0 ||
                    widget3->item(i, 7)->text().toInt() == 9 ||
                    widget3->item(i, 7)->text().toInt() == 3 // unknown error (ftp)
                    )
            {
                // set local download path
                QString fullDownloadPath = settingsWindow->_downloadPath + id;
                if(!fullDownloadPath.endsWith("/"))
                {
                    fullDownloadPath = settingsWindow->_downloadPath + id + "/";
                }

                QString fileRelativ = widget3->item(i, 2)->text();
                QString fileSubPath = dirFromFilePath(fileRelativ).at(0);

                if(!fileSubPath.isEmpty())
                {
                    if(fileSubPath.endsWith("/"))
                    {
                       fullDownloadPath = fullDownloadPath + fileSubPath;
                    }
                    else
                    {
                        fullDownloadPath = fullDownloadPath + fileSubPath + "/";
                    }
                }

                // create local download path (if needed)
                QDir dir;
                if(!dir.mkpath(fullDownloadPath))
                {
                    MsgWarning(tr("Download Pfad"), id + ": " + tr("Konnte den Downloadpfad auf dem (lokalen) Datenträger nicht erstellen! [") + fullDownloadPath + "]");
                    break;
                }

                QStringList downloadList;
                downloadList.append(id);                                                  // tab id
                downloadList.append(host);
                downloadList.append(port);
                downloadList.append(user);
                downloadList.append(pass);
                downloadList.append(dirFromFilePath(widget3->item(i, 1)->text()).at(0));  // ftp dir
                downloadList.append(fullDownloadPath);                                    // download path
                downloadList.append(dirFromFilePath(widget3->item(i, 1)->text()).at(1));  // file fulll path
                downloadList.append(QString::number(i));                                  // rowCount
                downloadList.append(settingsWindow->_ftpProxyHost);
                downloadList.append(settingsWindow->_ftpProxyPort);
                downloadList.append(settingsWindow->_ftpProxyUser);
                downloadList.append(settingsWindow->_ftpProxyPass);

                auto thread = new QThread;
                auto worker = new FTPDownload(downloadList);
                worker->moveToThread(thread);
                g_Worker.append(worker);

                connect(worker, SIGNAL(doProgress(QString,int,qint64,qint64,bool,bool)), this, SLOT(updateDownloadProgress(QString,int,qint64,qint64,bool,bool)));
                connect(worker, SIGNAL(statusUpdateFile(QString,int,QString,int)), this, SLOT(updateDownloadFileStatus(QString,int,QString,int)));
                connect(worker, SIGNAL(error(QString)), this, SLOT(downloadError(QString)));
                connect(thread, SIGNAL(started()), worker, SLOT(process()));
                connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
                connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
                connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

                thread->start();

                g_runningDownloads++;
                activeDownload += 1;
                g_tabDownloads[id] = activeDownload;

            }
        }
    }
}

// update progress on downloads
void SFDLSauger::updateDownloadProgress(QString tabID, int nRow, qint64 read, qint64 total, bool overwriteTime = false, bool firstUpdate = false)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(tabID);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

    qint64 resume = widget2->item(0, 15)->text().toLongLong();
    if(resume && !firstUpdate)
    {
        read += resume;
    }

    qint64 lastUpdateTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
    if((lastUpdateTime - g_lastProgressUpdate) >= 250 || total <= read || overwriteTime)
    {
        g_lastProgressUpdate = lastUpdateTime;

        int progress;

        // divide by zero?
        if(total < 100)
        {
           progress = 100;
        }
        else
        {
            progress = read/(total/100);
        }

        // txt files on *nix systems vs windows real size issue
        if(progress > 100)
        {
            progress = 100;
        }

        // progressbar update
        QProgressBar *PROGBAR = widget2->findChild<QProgressBar *>("pbarIn_" + QString::number(nRow));
        PROGBAR->setValue(progress);

        // update file time and speed
        qint64 timestamp = QDateTime::currentDateTime().toTime_t();
        qint64 start_time = widget2->item(nRow, 8)->text().toInt();
        qint64 last_time = widget2->item(nRow, 9)->text().toInt();
        qint64 zeit = 0;
        qint64 mbSec = 0;

        if(!start_time)
        {
            widget2->item(nRow, 8)->setText(QString::number(timestamp)); // start time
            widget2->item(nRow, 9)->setText(QString::number(timestamp)); // last time
        }
        else
        {
            widget2->item(nRow, 9)->setText(QString::number(timestamp)); // last time

            zeit = timestamp - start_time;
            if(!zeit)
            {
                zeit = 1;
            }

            if(!last_time)
            {
                last_time = 1;
            }

            if(resume && !firstUpdate)
            {
                mbSec = (read - resume)/zeit;
            }
            else
            {
                mbSec = read/zeit;
            }
        }

        if(overwriteTime)
        {
            mbSec = 0;
            zeit = 0;
        }

        widget2->item(nRow, 10)->setText(bytes2Human(mbSec) + "/s");
        widget2->item(nRow, 11)->setText(seconds_to_DHMS(zeit));

        qlonglong lastReadData = widget2->item(nRow, 12)->text().toLongLong(); // get last read data

        widget2->item(nRow, 12)->setText(QString::number(read));

        // status table
        QTableWidget *widget3 = widget1->findChild<QTableWidget *>("status");

        // qlonglong fileSize = total;                                     // actual total file size
        qlonglong t_totalSize = widget3->item(0, 6)->text().toLongLong();  // total download size (all files)
        qlonglong t_sizeLoaded = widget3->item(0, 8)->text().toLongLong(); // total download (all files) yet loaded

        t_sizeLoaded += (read - lastReadData);

        if(firstUpdate)
        {
            t_sizeLoaded += read;
        }

        qlonglong t_startTime = widget3->item(0, 12)->text().toLongLong();
        qlonglong t_lastTime = widget3->item(0, 13)->text().toLongLong();
        qlonglong t_stopTime = widget3->item(0, 16)->text().toLongLong();

        qlonglong t_zeit = 0;
        qlonglong t_mbSec = 0;

        if(!t_startTime)
        {
            widget3->item(0, 12)->setText(QString::number(timestamp)); // start time
            widget3->item(0, 13)->setText(QString::number(timestamp)); // last time
        }
        else
        {
            widget3->item(0, 13)->setText(QString::number(timestamp)); // last time

            if(t_stopTime)
            {
                t_zeit = t_stopTime;

                widget3->item(0, 16)->setText("0");
                widget3->item(0, 12)->setText(QString::number(timestamp - t_stopTime)); // start time
            }
            else
            {
                t_zeit = timestamp - t_startTime;
            }

            if(!t_zeit)
            {
                t_zeit = 1;
            }

            if(!t_lastTime)
            {
                t_lastTime = 1;
            }

            t_mbSec = t_sizeLoaded/t_zeit;
        }

        if(overwriteTime)
        {
            t_mbSec = 0;
            t_zeit = 0;
        }

        widget3->item(0, 8)->setText(QString::number(t_sizeLoaded));
        widget3->item(0, 9)->setText(bytes2Human(t_sizeLoaded));
        widget3->item(0, 14)->setText(bytes2Human(t_mbSec) + "/s");
        widget3->item(0, 15)->setText(seconds_to_DHMS(t_zeit));

        // set main progress bar
        qlonglong totalProgress = t_sizeLoaded/(t_totalSize/100);
        QProgressBar *mProgBar = widget1->findChild<QProgressBar *>("mProgBar");
        mProgBar->setValue(totalProgress);

        QLabel *statusLabel = widget1->findChild<QLabel *>("mStatusText");
        statusLabel->setText(bytes2Human(t_sizeLoaded) + tr(" von ") + bytes2Human(t_totalSize) + tr(" geladen. (") + bytes2Human(t_mbSec) + "/s | " + seconds_to_DHMS(t_zeit) + ")");
    }
}

// update file status
void SFDLSauger::updateDownloadFileStatus(QString tabID, int nRow, QString statusMsg, int status)
{
    // QString id = ui->tabWidget->tabToolTip(tabID);
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(tabID);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

    widget2->item(nRow, 6)->setText(statusMsg);
    widget2->item(nRow, 7)->setText(QString::number(status));

    // abort
    if(status == 9)
    {
        g_runningDownloads--;

        // set ative download for this tab/id/sfdl
        int activeDownload = g_tabDownloads[tabID];
        activeDownload -= 1;
        g_tabDownloads[tabID] = activeDownload;

        // update status table
        QTableWidget *widget4 = widget1->findChild<QTableWidget *>("status");
        widget4->item(0, 10)->setText(statusMsg);
        widget4->item(0, 11)->setText(QString::number(status));
    }

    // done
    if(status == 10)
    {
        g_runningDownloads--;

        // set ative download for this tab/id/sfdl
        int activeDownload = g_tabDownloads[tabID];
        activeDownload -= 1;
        g_tabDownloads[tabID] = activeDownload;

        // checks if all downloads are done
        // and create a speedreport
        if(allDownloadsDone(tabID) == true)
        {
            // swapStartStopButton(tabID);
            disableStartStopButton(tabID);

            // create new speedreport
            createSpeedreport(tabID);

            if(settingsWindow->_crc32Check)
            {
                crc32Check(tabID);

                if(settingsWindow->_sfvCheck)
                {
                    sfvCheck(tabID);
                }
            }

            if(settingsWindow->_unrarAutoEtract)
            {
                unrarFiles(tabID);
            }

            return;
        }

        // start next download
        startDownload(tabID);
    }
}

// returns true if all downloads in a tab are done
bool SFDLSauger::allDownloadsDone(QString id)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

    for(int i = 0; i < widget2->rowCount() + 1; i++)
    {
        if(widget2->item(i, 0))
        {
            if(widget2->item(i, 0)->checkState() == Qt::Checked && widget2->item(i, 7)->text().toInt() != 10)
            {
                return false;
            }
        }
    }

    return true;
}

// create speed report file
void SFDLSauger::createSpeedreport(QString id)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("status");
    QTableWidget *widget3 = widget1->findChild<QTableWidget *>("data");
    QTableWidget *widget4 = widget1->findChild<QTableWidget *>("files");

    // count loaded files
    int totalFileCount = 0;
    for(int i = 0; i < widget4->rowCount(); i++)
    {
        // enable checkbox again
        widget4->item(i, 0)->setFlags(widget4->item(i, 0)->flags() | Qt::ItemIsUserCheckable);

        if(widget4->item(i, 0)->checkState() == Qt::Checked && widget4->item(i, 7)->text().toInt() == 10)
        {
            totalFileCount++;
        }
    }

    QString upper = widget3->item(2, 1)->text();
    QString sizeLoaded = widget2->item(0, 9)->text();
    QString mbSec = widget2->item(0, 14)->text();
    QString zeit = widget2->item(0, 15)->text();

    QString speedreport = settingsWindow->_downloadPath + id + "/speedreport.txt";
    QString datum = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss");

    QFile speedreportFile(speedreport);
    if(speedreportFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        speedreportFile.write("[B]SFDLSauger Pro v");
        speedreportFile.write(QString(APP_VERSION).toStdString().c_str());
        speedreportFile.write(" Speedreport[/B] (");
        speedreportFile.write(datum.toStdString().c_str());
        speedreportFile.write(")\n[HR][/HR]\n");
        speedreportFile.write("[B]Name:[/B] ");
        speedreportFile.write(id.toStdString().c_str());
        speedreportFile.write("\n");
        speedreportFile.write("[B]Uploader:[/B] ");
        speedreportFile.write(upper.toStdString().c_str());
        speedreportFile.write("\n\n");
        speedreportFile.write("[B]Bericht:[/B] ");
        speedreportFile.write(QString::number(totalFileCount).toStdString().c_str());
        speedreportFile.write(" Dateien (");
        speedreportFile.write(sizeLoaded.toStdString().c_str());
        speedreportFile.write("), mit durchschnittlich ");
        speedreportFile.write(mbSec.toStdString().c_str());
        speedreportFile.write(" in ");
        speedreportFile.write(zeit.toStdString().c_str());
        speedreportFile.write(" geladen!\n\n");
        speedreportFile.write("[B]Kommentar:[/B] Besten Dank!\n");
    }
    speedreportFile.close();
    QDesktopServices::openUrl(QUrl(speedreport, QUrl::TolerantMode));
}

// crc32 check
void SFDLSauger::crc32Check(QString id = "")
{
    if(g_runningCRC32 < g_maxCRC32)
    {
        if(id.isEmpty())
        {
            id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());
        }

        QString path = settingsWindow->_downloadPath + id + "/";

        QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
        QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

        widget2->showColumn(13);

        for(int i = 0; i < widget2->rowCount() + 1; i++)
        {
            if(g_runningCRC32 >= g_maxCRC32)
            {
                break;
            }

            if(widget2->item(i, 0))
            {
                if(widget2->item(i, 0)->checkState() == Qt::Checked
                        && widget2->item(i, 7)->text().toInt() == 10
                        && widget2->item(i, 13)->text().isEmpty())
                {
                    auto thread = new QThread;

                    QStringList data;
                    data.append(id);
                    data.append(QString::number(i));
                    data.append(path + widget2->item(i, 2)->text());

                    auto worker = new Crc32(data);
                    worker->moveToThread(thread);
                    g_CRC32Worker.append(worker);

                    connect(worker, SIGNAL(updateCRC32data(QString,int,QString)), this, SLOT(updateCRC32(QString,int,QString)));
                    connect(thread, SIGNAL(started()), worker, SLOT(calculateFromFile()));
                    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
                    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
                    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

                    thread->start();

                    g_runningCRC32++;
                }
            }
        }
    }
}

// update CRC32 data in files table
void SFDLSauger::updateCRC32(QString id, int nRow, QString crc32Data)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

    widget2->item(nRow, 13)->setText(crc32Data);

    g_runningCRC32--;
    crc32Check(id);
}

void SFDLSauger::sfvCheck(QString id)
{
    QString tPath = settingsWindow->_downloadPath + id + "/";

    QDir sfvPath(tPath);

    QStringList fileList = sfvPath.entryList();
    // int index = fileList.indexOf(QRegExp("([a-zA-Z0-9\\s_\\.\\-\\(\\):])+(.sfv)$"));
    int index = fileList.indexOf(QRegularExpression("([a-zA-Z0-9\\s_\\.\\-\\(\\):])+(.sfv)$"));

    if(!fileList.count())
    {
        return;
    }

    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

    // check if crc32 is done
    for(int j = 0; j < widget2->rowCount(); j++)
    {
        if(widget2->item(j, 13)->text().isEmpty())
        {
            // QTimer::singleShot(5000, this, std::bind(&SFDLSauger::sfvCheck,this,id));
            auto timer = new QTimer(this);
            timer->setObjectName(id);
            timer->singleShot(1000, this, std::bind(&SFDLSauger::sfvCheck,this,id));
            g_SFVTimer.append(timer);

            return;
        }
    }

    QIcon icon1(":/gfx/chk.png");
    QIcon icon2(":/gfx/warning2.png");
    QRegularExpression re("^([^;].+) ([0-9a-zA-Z]{8})$");

    QFile inputFile(tPath + fileList.at(index));
    if(inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        widget2->showColumn(14);

        QTextStream in(&inputFile);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            if(!line.startsWith(";"))
            {
                QRegularExpressionMatch match = re.match(line);

                if(match.hasMatch())
                {
                    for(int k = 0; k < widget2->rowCount(); k++)
                    {
                        if(widget2->item(k, 2)->text() == match.captured(1))
                        {
                            if(widget2->item(k, 13)->text() == match.captured(2))
                            {
                                widget2->item(k, 14)->setIcon(icon1);
                                widget2->item(k, 14)->setToolTip(match.captured(2));
                            }
                            else
                            {
                                widget2->item(k, 14)->setIcon(icon2);
                                widget2->item(k, 14)->setToolTip(match.captured(2));
                            }
                        }
                    }
                }
            }
        }

        inputFile.close();
    }
}

// checks the drive for exisiting files
void SFDLSauger::chkForExisitingFiles(QString id = "")
{
    if(id.isEmpty())
    {
        id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());
    }

    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

    QDir pathCHK(settingsWindow->_downloadPath + id);
    if(!pathCHK.exists())
    {
        return;
    }

    qint64 totalResume = 0;

    for(int i = 0; i < widget2->rowCount() + 1; i++)
    {
        if(widget2->item(i, 2))
        {
            QFileInfo chkFile(settingsWindow->_downloadPath + id + "/" + widget2->item(i, 2)->text());
            if(chkFile.exists() && chkFile.isFile())
            {
                qint64 currentFileSize = chkFile.size();
                qint64 totalFileSize = widget2->item(i, 3)->text().toLongLong();

                totalResume += currentFileSize;

                if(currentFileSize >= totalFileSize)
                {
                    widget2->item(i, 6)->setText(tr("Fertig!"));
                    widget2->item(i, 7)->setText(QString::number(10));

                    widget2->item(i, 12)->setText(QString::number(currentFileSize));
                    updateDownloadProgress(id, i, totalFileSize, totalFileSize, true, true);
                }
                else
                {
                    widget2->item(i, 6)->setText(tr("User Abbruch!"));
                    widget2->item(i, 7)->setText(QString::number(9));

                    QTableWidgetItem *RESUME = new QTableWidgetItem(QString::number(currentFileSize));
                    widget2->setItem(i, 15, RESUME);

                    widget2->item(i, 12)->setText(QString::number(currentFileSize));
                    updateDownloadProgress(id, i, currentFileSize, totalFileSize, true, true);
                }
            }
        }
    }

    QTableWidget *widget4 = widget1->findChild<QTableWidget *>("status");
    widget4->item(0, 17)->setText(QString::number(totalResume));

    if(allDownloadsDone(id) == true)
    {
        disableStartStopButton(id);
    }
}

// delete rar files
void SFDLSauger::unrarDeleteFiles(QString id)
{
    // find rar files to delete
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QLabel *statusLabel = widget1->findChild<QLabel *>("mStatusText");
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

    statusLabel->setText(tr("Entferne RAR Dateien ..."));

    for(int i = 0; i < widget2->rowCount() + 1; i++)
    {
        if(widget2->item(i, 2))
        {
            QStringList tFile = widget2->item(i, 2)->text().split("/");

            // check if file is in sub-dir (extract only main dir)
            if(tFile.count() == 1)
            {
                QRegularExpression rarMatch("(part[0-9]+.rar|.r[0-9]+|.rar)$");
                QRegularExpressionMatch match = rarMatch.match(tFile.at(0));

                if(match.hasMatch())
                {
                    QString datei = tFile.at(0);
                    statusLabel->setText(tr("Entferne: ") + datei);

                    QFile::remove(settingsWindow->_downloadPath + id + "/" + datei);
                }
            }
        }
    }

    statusLabel->setText(tr("Alle RAR Dateien entfernt!"));
}

// unrar files
void SFDLSauger::unrarFiles(QString id)
{
    QString file = QString();

    // find correct file
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

    for(int i = 0; i < widget2->rowCount() + 1; i++)
    {
        if(widget2->item(i, 2))
        {
            QStringList tFile = widget2->item(i, 2)->text().split("/");

            // check if file is in sub-dir (extract only main dir)
            if(tFile.count() == 1)
            {
                QRegularExpression rarMatch("(part[1].rar|[^part2-99999].rar|.+.rar)$");
                QRegularExpressionMatch match = rarMatch.match(tFile.at(0));

                if(match.hasMatch())
                {
                    file = tFile.at(0);

                    break;
                }
            }
        }
    }

    QString path = settingsWindow->_downloadPath + id + "/";

    if(settingsWindow->_unrar_user_internal)
    {
        if(id.isEmpty() || path.isEmpty() || file.isEmpty())
        {
            addLogText(tr("<font color=\"red\">[") + id + tr("] UnRAR: Keine RAR Datei(en) zum auspacken gefunden!</font>"));
            return;
        }

        QFileInfo fCHK(path + file);
        if(!fCHK.exists() || !fCHK.isFile())
        {
            addLogText(tr("<font color=\"red\">[") + id + tr("] UnRAR Fehler: Die Datei [") + file + tr("] konnte im Pfad [") + path + tr("] nicht gefunden werden.</font>"));
            MsgWarning(tr("UnRAR Fehler"), "[" + id + tr("] UnRAR Fehler: Die Datei [") + file + tr("] konnte im Pfad [") + path + tr("] nicht gefunden werden."));

            return;
        }

        auto thread = new QThread;

        QStringList data;
        data.append(id);
        data.append(path + file);
        data.append(path);

        auto worker = new UnrarExtractor(data);
        worker->moveToThread(thread);
        g_UnRARExtractor.append(worker);

        connect(worker, SIGNAL(updateUnRarProgress(QString,QString,int)), this, SLOT(unrarProgressUpdate(QString,QString,int)));
        connect(thread, SIGNAL(started()), worker, SLOT(startUnRAR()));
        connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
        connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

        connect(worker, &UnrarExtractor::error, this, [this](const QString& message) {
            MsgWarning(tr("UnRAR Fehler"), tr("UnRAR Fehler: ") + message);
        });

        thread->start();
    }
    else
    {
        QString unrar = settingsWindow->_unrarPath;

        if(id.isEmpty() || unrar.isEmpty() || path.isEmpty() || file.isEmpty())
        {
            addLogText(tr("<font color=\"red\">[") + id + tr("] UnRAR: Keine RAR Datei(en) zum auspacken gefunden!</font>"));
            // MsgWarning(tr("UnRAR Fehler"), "[" + id + tr("] UnRAR: Keine RAR Datei(en) zum auspacken gefunden!"));

            return;
        }

        QFileInfo fCHK(path + file);
        if(!fCHK.exists() || !fCHK.isFile())
        {
            addLogText(tr("<font color=\"red\">[") + id + tr("] UnRAR Fehler: Die Datei [") + file + tr("] konnte im Pfad [") + path + tr("] nicht gefunden werden.</font>"));
            MsgWarning(tr("UnRAR Fehler"), "[" + id + tr("] UnRAR Fehler: Die Datei [") + file + tr("] konnte im Pfad [") + path + tr("] nicht gefunden werden."));

            return;
        }

        auto thread = new QThread;

        QStringList data;
        data.append(id);
        data.append(unrar);
        data.append(path + file);
        data.append(path);

        auto worker = new UnRAR(data);
        worker->moveToThread(thread);
        g_UnRARWorker.append(worker);

        connect(worker, SIGNAL(updateUnRarProgress(QString,QString,int)), this, SLOT(unrarProgressUpdate(QString,QString,int)));
        connect(thread, SIGNAL(started()), worker, SLOT(startUnRAR()));
        connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
        connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

        thread->start();
    }
}

void SFDLSauger::unrarProgressUpdate(QString id, QString fileName, int progress)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);

    // set main progress bar
    QProgressBar *mProgBar = widget1->findChild<QProgressBar *>("mProgBar");
    mProgBar->setValue(progress);

    QLabel *statusLabel = widget1->findChild<QLabel *>("mStatusText");

    if(progress == 100)
    {
        statusLabel->setText(tr("UnRAR erfolgreich abgeschlossen!"));

        if(settingsWindow->_unrarAutoDelete == true)
        {
            unrarDeleteFiles(id);
        }
    }
    else
    {
        statusLabel->setText(tr("UnRAR Datei: ") + fileName);
    }

    addLogText(id + tr(": UnRAR Datei: ") + fileName + " - " + QString::number(progress) + "%");
}

// close tab and remove download
void SFDLSauger::on_tabWidget_tabCloseRequested(int index)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(ui->tabWidget->tabToolTip(index));
    QLabel *statusLabel = widget1->findChild<QLabel *>("mStatusText");

    if(widget1->isEnabled() == false && statusLabel->text() != "Fehler! Bitte Logs konsultieren ...")
    {
        addLogText("<font color=\"red\">" + widget1->objectName() + tr(": Einlesen der Daten nicht abgeschlossen! Entfernen erst nach Abschluß möglich.</font>"));
        return;
    }

    // remove tab
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, ui->tabWidget->tabToolTip(index), tr("Download wirklich entfernen?"), QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        stopDownload();

        QString id = ui->tabWidget->tabToolTip(index);

        // stop running crc32 threads for this id
        // ... some strange bug ...
        /*
        foreach(Crc32* c, g_CRC32Worker)
        {
            if(id == c->_id && c->thread()->isRunning())
            {
                c->thread()->quit();
                c->thread()->wait();
                c->deleteLater();
            }
        }
        */

        // stop sfv check timers
        foreach(QTimer* t, g_SFVTimer)
        {
            if(id == t->objectName() && t->isActive())
            {
                t->stop();
                t->deleteLater();
            }
        }

        // stop unrar threads for this id
        // there should be only one for this id but you never know
        foreach(UnRAR* u, g_UnRARWorker)
        {
            if(id == u->id && u->thread()->isRunning())
            {
                u->thread()->quit();
                u->thread()->wait();
                u->deleteLater();
            }
        }

        foreach(UnrarExtractor* u, g_UnRARExtractor)
        {
            if(id == u->id && u->thread()->isRunning())
            {
                u->thread()->quit();
                u->thread()->wait();
                u->deleteLater();
            }
        }

        widget1->deleteLater();
        ui->tabWidget->removeTab(index);
    }
}

// open new sfdl file dialogue
void SFDLSauger::on_action_ffnen_triggered()
{
    QFileDialog dialog(this);
    dialog.setDirectory(qApp->applicationDirPath());
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter(tr("SFDL (*.sfdl)"));

    QStringList fileNames;

    if(dialog.exec())
    {
        fileNames = dialog.selectedFiles();
    }

    if(fileNames.count())
    {
        foreach (QString file, fileNames)
        {
            loadSFDL(file);
        }
    }
}

// on quit app
void SFDLSauger::on_actionBeenden_triggered()
{
    quitApp();
}

// show / hide logs
void SFDLSauger::on_actionLogs_anzeigen_triggered()
{
    if(ui->textEdit->isHidden())
    {
        ui->textEdit->setHidden(0);
    }
    else
    {
        ui->textEdit->setHidden(1);
    }
}

// open download in filezilla
void SFDLSauger::openInFileZilla()
{
    QString id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("data");

    QString t_host = widget2->item(7,1)->text();
    QString t_port = widget2->item(8,1)->text();
    QString t_user = widget2->item(9,1)->text();
    QString t_pass = widget2->item(10,1)->text();
    QString t_path = widget2->item(21,1)->text();

    qDebug() << "openInFileZilla rowCount: " << widget2->rowCount();

    if(!t_host.isEmpty())
    {
        if(g_FILEZILLA.isEmpty())
        {
            QString fZILLA;
            fZILLA = QFileDialog::getOpenFileName(this, "FileZilla", "", tr("FileZilla (filezilla.exe)"));

            if(!fZILLA.isEmpty())
            {
                g_FILEZILLA = fZILLA;
            }
        }

        if(!g_FILEZILLA.isEmpty())
        {
            if(t_path.isEmpty() || widget2->rowCount() != 23)
            {
                QProcess::startDetached("\"" + g_FILEZILLA + "\" \"ftp://" + t_user + ":" + t_pass + "@" + t_host + ":" + t_port + "\"");
            }
            else
            {
                QProcess::startDetached("\"" + g_FILEZILLA + "\" \"ftp://" + t_user + ":" + t_pass + "@" + t_host + ":" + t_port + t_path + "\"");
            }
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Open FileZilla"), tr("Can't open FileZilla! No Server selected!"));
    }
}

// open about window
void SFDLSauger::on_action_ber_triggered()
{   
    infoWindow->setWindowTitle(tr("Über ") + QString(APP_PRODUCT));
    infoWindow->setWindowFlags(infoWindow->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    infoWindow->setSizeGripEnabled(false);
    infoWindow->setFixedSize(QSize(400, 320));
    if(infoWindow->_mediaPlayer == false)
    {
        infoWindow->playMedia();
    }
    infoWindow->show();
}

// open settings window
void SFDLSauger::on_actionEinstellungen_triggered()
{
    settingsWindow->setWindowTitle(tr("Einstellungen"));
    settingsWindow->setWindowIcon(QIcon(":/gfx/gear.png"));
    settingsWindow->setWindowFlags(settingsWindow->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    settingsWindow->setSizeGripEnabled(false);
    settingsWindow->setFixedSize(QSize(700, 500));
    settingsWindow->show();
}
