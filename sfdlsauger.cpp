#include "sfdl.h"
#include "ftplistfiles.h"
#include "sfdlsauger.h"
#include "ui_sfdlsauger.h"
#include "commandworker.h"

QMap<QString, TabControl> m_tabWorkflows;

SFDLSauger::SFDLSauger(QWidget *parent) : QMainWindow(parent), ui(new Ui::SFDLSauger)
{
    qRegisterMetaType<QString>("QString");
    ui->setupUi(this);
    setAcceptDrops(true);
    loadWindowStatus();

    // initialize classes
    logsWindow = new LiveLogs();
    infoWindow = new About(this);
    settingsWindow = new Settings(this);
    connect(settingsWindow, SIGNAL(sendLogText(QString)), this, SLOT(addLogText(QString)));

    // filewatcher
    connect(settingsWindow, &Settings::requestStartMonitoring, this, &SFDLSauger::startFileWatching);
    connect(settingsWindow, &Settings::requestStopMonitoring, this, &SFDLSauger::stopFileWatching);
    connect(settingsWindow, &Settings::requestSettingsUpdate, this, &SFDLSauger::updateFileWatching);

    // webserver
    connect(settingsWindow, SIGNAL(webserverStartStop()), this, SLOT(stopWebServer()));
    connect(this, SIGNAL(webServerStatusChanged(bool)), settingsWindow, SLOT(updateButtonText(bool)));

    // sounds
    finishSound = new QSoundEffect(this);
    finishSound->setSource(QUrl::fromLocalFile(":/snd/done.wav"));
    finishSound->setVolume(0.9f);

    // irc chat
    ircChatWindow = new chatIRC();
    ircChatWindow->setWindowTitle("IRC Chat");
    ircChatWindow->setObjectName("IRCChat");
    ircChatWindow->setWindowFlags(ircChatWindow->windowFlags() & ~Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    ircChatWindow->setSizeGripEnabled(true);
    connect(ircChatWindow, SIGNAL(sendLogText(QString)), this, SLOT(addLogText(QString)));

    // logs
    ui->textEdit->installEventFilter(this);
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setTextInteractionFlags(Qt::NoTextInteraction);
    ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
    ui->textEdit->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->textEdit->viewport()->setCursor(Qt::ArrowCursor);
    ui->textEdit->setUndoRedoEnabled(false);
    ui->textEdit->document()->setUndoRedoEnabled(false);
    ui->textEdit->setAcceptDrops(false);
    ui->textEdit->setMouseTracking(true);
    ui->textEdit->viewport()->setMouseTracking(true);
    connect(ui->textEdit, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showLogMenu(QPoint)));
    connect(this, &SFDLSauger::logAdded, logsWindow, &LiveLogs::addLogText);
    connect(logsWindow, SIGNAL(sendLogText(QString)), this, SLOT(addLogText(QString)));

    logsText = new QTextEdit();
    logsText->setReadOnly(true);
    logsText->setAcceptDrops(false);
    logsText->setTextInteractionFlags(Qt::NoTextInteraction);
    addLogText("SFDLSauger Pro v" + QString(APP_VERSION) + tr(" geladen und bereit!"));

    // notifications
    m_notifier = new NotificationClient(settingsWindow, this);
    connect(m_notifier, SIGNAL(sendLogText(QString)), this, SLOT(addLogText(QString)));
    settingsWindow->setNotificationSystem(m_notifier);

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
    if(settingsWindow->_devMode) { addLogText(tr("<b><i>Pro Modus aktiv!</i></b>")); }

    // task-bar icon progress
    m_taskbarProgress = new TaskbarProgressManager(this);

    // filewatcher
    // auto load new sfdl files
    if(settingsWindow->_filewatcher == true && !settingsWindow->_filewatcher_path.isEmpty())
    {
        startFileWatching();
        QString fileUrl = QUrl::fromLocalFile(settingsWindow->_filewatcher_path).toString();
        QString link = QString("<a href=\"%1\" style=\"color: #4CAF50;\">%1</a>").arg(fileUrl);
        addLogText(tr("[SFDL] ") + link + tr(" wird auf neue SFDL Dateien (alle ") + settingsWindow->_filewatcher_interval +  tr(" Sekunden) überwacht!"));
    }

    // webserver autostart
    if(settingsWindow->_webserver_autostart)
    {
        startWebServer();
    }
}

SFDLSauger::~SFDLSauger()
{
    saveWindowStatus();

    if(logsWindow)
    {
        delete logsWindow;
    }
    if(ircChatWindow)
    {
        delete ircChatWindow;
    }
    if(logsText)
    {
        delete logsText;
    }
    if(m_watcherThread)
    {
        stopFileWatching();
    }

    stopAllCrcThreads();

    delete ui;
}

void SFDLSauger::saveWindowStatus()
{
    QSettings config(QSettings::IniFormat, QSettings::UserScope, "SFDLSaugerPro", "config");
    config.beginGroup("window");
    config.setValue("position", this->geometry());
    config.setValue("maximized", this->isMaximized());
    config.setValue("hidelogs", ui->textEdit->isHidden());
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

    bool hideLogs = config.value("hidelogs").toBool();
    if(hideLogs)
    {
        ui->textEdit->setHidden(hideLogs);
        ui->actionLogs_anzeigen->setChecked(0);
    }

    config.endGroup();
}

void SFDLSauger::devModeSwitch()
{
    if(settingsWindow->_devMode)
    {
        settingsWindow->_devMode = false;
        MsgWarning("SFDLSauger Pro", tr("Pro Modus deaktiviert!"));
    }
    else
    {
        settingsWindow->_devMode = true;
        MsgWarning("SFDLSauger Pro", tr("Pro Modus aktiviert!"));
    }
}

void SFDLSauger::addLogText(QString txt)
{
    QString dateNtime = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss");
    QString htmlLine = "<font color=\"grey\">[" + dateNtime + "]</font> " + txt + "<br />";

    logsText->moveCursor(QTextCursor::End);
    logsText->insertHtml(htmlLine);

    ui->textEdit->moveCursor(QTextCursor::End);
    ui->textEdit->insertHtml(htmlLine);

    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());

    emit logAdded(htmlLine);
    emit webLogAdded(htmlLine);
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
        MsgWarning(id, "[" + path + "] " + tr("Existiert (noch) nicht!"));
    }
}

void SFDLSauger::swapStartStopButton(QString id)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QToolBar *widget2 = widget1->findChild<QToolBar *>("toolbar");

    QToolButton *btn = widget2->findChild<QToolButton *>("toolStart");
    if(btn)
    {
        QAction *act = btn->defaultAction();
        bool running = !act->property("isRunning").toBool();

        if(running)
        {
            act->setProperty("isRunning", true);
            act->setIcon(QIcon(":/gfx/stop.png"));
            act->setToolTip(tr("Stop Download"));
        }
        else
        {
            act->setProperty("isRunning", false);
            act->setIcon(QIcon(":/gfx/start.png"));
            act->setToolTip(tr("Start Download"));
        }
    }
}

void SFDLSauger::disableStartStopButton(QString id)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QToolBar *widget2 = widget1->findChild<QToolBar *>("toolbar");
    QToolButton *widget3 = widget2->findChild<QToolButton *>("toolStart");
    widget3->setDisabled(1);
}

void SFDLSauger::startDownloadButton()
{
    QString id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());

    if(g_tabDownloads[id] > 0)
    {
        stopDownload();
        swapStartStopButton(id);
        return;
    }

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
    int seconds = duration % 60;
    duration /= 60;
    int minutes = duration % 60;
    duration /= 60;
    int hours = duration % 24;
    int days = duration / 24;

    if (days == 0 && hours == 0 && minutes == 0)
    {
        return QString("%1s").arg(seconds, 2, 10, QChar('0'));
    }
    else if (days == 0 && hours == 0)
    {
        return QString("%1m %2s").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    }
    else if (days == 0)
    {
        return QString("%1h %2m %3s").arg(hours, 2, 10, QChar('0'))
            .arg(minutes, 2, 10, QChar('0'))
            .arg(seconds, 2, 10, QChar('0'));
    }
    else
    {
        return QString("%1d %2h %3m %4s").arg(days)
            .arg(hours, 2, 10, QChar('0'))
            .arg(minutes, 2, 10, QChar('0'))
            .arg(seconds, 2, 10, QChar('0'));
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
    reply = QMessageBox::question(this, "SFDLSauger Pro", "SFDLSauger Pro " + tr("wirklich beenden?"), QMessageBox::Yes | QMessageBox::No);

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

    sfdlFile->setSFDL(file, settingsWindow->_sfdlPasswords);
    sfdlFile->moveToThread(thread);

    connect(sfdlFile, SIGNAL(sendSFDLData(QStringList,QStringList)), this, SLOT(chkSFDLData(QStringList,QStringList)));
    connect(sfdlFile, SIGNAL(sendWarning(QString,QString)), this, SLOT(MsgWarning(QString,QString)));
    connect(sfdlFile, SIGNAL(sendLogText(QString)), this, SLOT(addLogText(QString)));
    connect(thread, &QThread::started, sfdlFile, &sfdl::readSFDL);
    connect(sfdlFile, &sfdl::finished, thread, &QThread::quit);
    connect(sfdlFile, &QObject::destroyed, thread, &QObject::deleteLater);
    connect(thread, &QThread::finished, sfdlFile, &QObject::deleteLater);

    thread->start();
}

void SFDLSauger::loadSFDLConsol(int instanceId, QByteArray message)
{
    Q_UNUSED(instanceId);

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
    // status_tbl->setColumnCount(18);
    status_tbl->setColumnCount(19);
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
    statusList.push_back(tr("SFDFullPath"));

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

    // SFDL file full path
    QTableWidgetItem *SFDLFULLPATH = new QTableWidgetItem(data.at(0).split("|").at(1));
    status_tbl->setFont(statusFONT);
    status_tbl->setItem(0, 18, SFDLFULLPATH);

    status_tbl->resizeColumnToContents(1);
    status_tbl->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    status_tbl->horizontalScrollBar()->setDisabled(1);
    status_tbl->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    status_tbl->setHidden(1);

    if(settingsWindow->_devMode)
    {
        #ifdef QT_DEBUG
        status_tbl->setHidden(0);
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
    if(!settingsWindow->_devMode)
    {
        data_tbl->hideRow(7);
        data_tbl->hideRow(8);
        data_tbl->hideRow(9);
        data_tbl->hideRow(10);
        data_tbl->hideRow(21);
    }

    data_tbl->setHidden(1);

    // file table
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

        QString dlFileNameWithSub = files.at(i).split("|").at(0);
        dlFileNameWithSub = removeDuplicateSlashes(returnSubPath(dlFileNameWithSub, tabName));
        if(dlFileNameWithSub.isEmpty()) { dlFileNameWithSub = f3; } // fallback
        QTableWidgetItem *FILE = new QTableWidgetItem(dlFileNameWithSub);
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

    if(settingsWindow->_devMode)
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
        addLogText(tabName + tr(": Fehler beim Einlesen der SFDL Datei!"));
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
        addLogText(tabName + tr(": Fehler beim Einlesen der SFDL Datei!"));
    }

    // focus on new tab
    ui->tabWidget->setCurrentIndex(dataid);

    // start download if auto downloads is enabled
    if(settingsWindow->_auto_downloads && file_tbl->isEnabled())
    {
        startDownloadButton();
    }
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
    Q_UNUSED(item);

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
    btnStart->setProperty("isRunning", false);
    connect(btnStart, SIGNAL(triggered(bool)), this, SLOT(startDownloadButton()));

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
    QAction *btnFtpRush = tbar->addAction(tr("Mit FTPRush V2 öffnen"), [](bool) {});
    QToolButton *toolFtpRush = dynamic_cast<QToolButton*>(tbar->widgetForAction(btnFtpRush));
    toolFtpRush->setIcon(QIcon(":/gfx/ftprush.png"));
    toolFtpRush->setCursor(Qt::PointingHandCursor);
    connect(btnFtpRush, SIGNAL(triggered(bool)), this, SLOT(openInFTPRushV2()));

    // add winscp button
    QAction *btnWinSCP = tbar->addAction(tr("Mit WinSCP öffnen"), [](bool) {});
    QToolButton *toolWinSCP = dynamic_cast<QToolButton*>(tbar->widgetForAction(btnWinSCP));
    toolWinSCP->setIcon(QIcon(":/gfx/winscp.png"));
    toolWinSCP->setCursor(Qt::PointingHandCursor);
    connect(btnWinSCP, SIGNAL(triggered(bool)), this, SLOT(openInWinSCP()));

    // add flashfxp button
    QAction *btnFlashFXP = tbar->addAction(tr("Mit FlashFXP öffnen"), [](bool) {});
    QToolButton *toolFlashFXP = dynamic_cast<QToolButton*>(tbar->widgetForAction(btnFlashFXP));
    toolFlashFXP->setIcon(QIcon(":/gfx/flashfxp.png"));
    toolFlashFXP->setCursor(Qt::PointingHandCursor);
    connect(btnFlashFXP, SIGNAL(triggered(bool)), this, SLOT(openInFlashFXP()));

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

    if(!settingsWindow->_devMode)
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
    // MAXTHREADS->setMaximum(10);
    MAXTHREADS->setSingleStep(1);
    int setMaxDownloads = settingsWindow->_max_downloads;
    if(setMaxDownloads <= 0) { setMaxDownloads = 3; }
    MAXTHREADS->setValue(setMaxDownloads);
    MAXTHREADS->setFixedHeight(30);
    MAXTHREADS->setFixedWidth(50);
    MAXTHREADS->setFont(MAXTHREADSDownloadFont);
    MAXTHREADS->setAlignment(Qt::AlignCenter);
    MAXTHREADS->setToolTip(tr("Maximun Download Threads"));
    connect(MAXTHREADS, QOverload<int>::of(&QSpinBox::valueChanged), [this](int value) {
        g_maxDownloads = value;
        settingsWindow->_max_downloads = g_maxDownloads;
    });
    tbar->addWidget(MAXTHREADS);

    if(!settingsWindow->_devMode)
    {
        MAXTHREADS->setMaximum(3);
    }
    else
    {
        MAXTHREADS->setMaximum(10);
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

QString SFDLSauger::returnSubPath(QString fullPath, QString splitter)
{
    QStringList parts = fullPath.split('/', Qt::SkipEmptyParts);

    int index = parts.indexOf(splitter);

    if(index == -1)
    {
        return QString();
    }

    QStringList subparts = parts.mid(index + 1);
    if(subparts.isEmpty())
    {
        return QString();
    }

    return '/' + subparts.join('/');
}

QString SFDLSauger::removeDuplicateSlashes(QString path)
{
    QStringList parts = path.split('/', Qt::SkipEmptyParts);
    return parts.join('/');
}

// start download in tab
void SFDLSauger::startDownload(QString tabID)
{
    if(g_runningDownloads >= g_maxDownloads) return;

    QString id = tabID.isEmpty() ? ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex()) : tabID;
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("data");
    QTableWidget *widget3 = widget1->findChild<QTableWidget *>("files");

    QString host = widget2->item(7, 1)->text();
    QString port = widget2->item(8, 1)->text();
    QString user = widget2->item(9, 1)->text();
    QString pass = widget2->item(10, 1)->text();

    for(int i = 0; i < widget3->rowCount(); i++)
    {
        int globalFree = g_maxDownloads - g_runningDownloads;
        if(globalFree <= 0) break;

        QToolBar *widget4 = widget1->findChild<QToolBar *>("toolbar");
        QSpinBox *widget5 = widget4->findChild<QSpinBox *>("maxdownloads");

        int activeDownload = g_tabDownloads[id];
        int tabFree = widget5->value() - activeDownload;
        if(tabFree <= 0) break;

        int fileStatus = widget3->item(i, 7)->text().toInt();

        if((widget3->item(i, 0)->checkState() == Qt::Checked && fileStatus == 0)
        || (widget3->item(i, 0)->checkState() == Qt::Checked && fileStatus == 3)
        || (widget3->item(i, 0)->checkState() == Qt::Checked && fileStatus == 9)
        )
        {
            QString fullDownloadPath = settingsWindow->_downloadPath + id;
            if(!fullDownloadPath.endsWith("/")) fullDownloadPath += "/";

            QString ftpDir = dirFromFilePath(widget3->item(i, 1)->text()).at(0);
            QString fileName = dirFromFilePath(widget3->item(i, 1)->text()).at(1);
            QString subPath = returnSubPath(ftpDir, id);

            if(settingsWindow->_flatDownloads)
            {
                fullDownloadPath = QDir::toNativeSeparators(QDir::cleanPath(fullDownloadPath));
            }
            else
            {
                fullDownloadPath = QDir::toNativeSeparators(QDir::cleanPath(fullDownloadPath + "/" + subPath));
            }
            QDir dir;
            if(!dir.mkpath(fullDownloadPath)) continue;

            qint64 fileSize = widget3->item(i, 3)->text().toLongLong();

            int chunksToUse = 1;
            if(settingsWindow->_download_useChunks)
            {
                const qint64 minChunkSize = 100 * 1024 * 1024;
                const int maxChunksPerFile = 5;

                if(fileSize > minChunkSize)
                {
                    chunksToUse = qMin((int)(fileSize / minChunkSize), globalFree);
                    chunksToUse = qMin(chunksToUse, tabFree);
                    chunksToUse = qMin(chunksToUse, maxChunksPerFile);
                    if(chunksToUse < 1) chunksToUse = 1;
                }
            }

            // save chunk count
            widget3->item(i, 7)->setData(Qt::UserRole, chunksToUse);

            QString fullFilePath = QDir::toNativeSeparators(fullDownloadPath + "/" + fileName);

            // pre allocating file space
            if(chunksToUse > 1)
            {
                QFile f(fullFilePath);
                if(f.open(QIODevice::WriteOnly))
                {
                    f.resize(fileSize);
                    f.close();
                }
            }

            qint64 currentOffset = 0;
            qint64 step = (chunksToUse > 1) ? (fileSize / chunksToUse) : fileSize;

            for(int c = 0; c < chunksToUse; ++c)
            {
                QStringList downloadList;
                downloadList << id << host << port << user << pass << ftpDir
                             << fullDownloadPath << fileName << QString::number(i)
                             << settingsWindow->_ftpProxyHost << settingsWindow->_ftpProxyPort
                             << settingsWindow->_ftpProxyUser << settingsWindow->_ftpProxyPass;

                auto thread = new QThread;
                auto worker = new FTPDownload(downloadList);

                worker->m_isChunked = (chunksToUse > 1);
                worker->m_isMasterChunk = (c == 0);
                worker->m_chunkStart = currentOffset;
                worker->m_chunkEnd = (c == chunksToUse - 1) ? fileSize : (currentOffset + step);
                worker->m_totalSize = fileSize;
                worker->m_chunkIndex = c;

                worker->moveToThread(thread);
                g_Worker.append(worker);

                connect(worker, SIGNAL(doProgress(QString,int,qint64,qint64,bool,bool)), this, SLOT(updateDownloadProgress(QString,int,qint64,qint64,bool,bool)));
                connect(worker, SIGNAL(statusUpdateFile(QString,int,QString,int)), this, SLOT(updateDownloadFileStatus(QString,int,QString,int)));
                connect(worker, SIGNAL(error(QString)), this, SLOT(downloadError(QString)));
                connect(worker, SIGNAL(sendLogText(QString)), this, SLOT(addLogText(QString)));
                connect(worker, SIGNAL(doChunkProgress(QString,int,int,qint64,qint64)), this, SLOT(updateChunkedDownloadProgress(QString,int,int,qint64,qint64)));
                connect(thread, SIGNAL(started()), worker, SLOT(process()));
                connect(worker, SIGNAL(finished()), thread, SLOT(quit()));

                thread->start();

                g_runningDownloads++;
                updateDownloadFileStatus(tabID, i, tr("Wird geladen ..."), 1);
                currentOffset = worker->m_chunkEnd;
            }

            g_tabDownloads[id] += chunksToUse;
            addLogText(tr("Lade: ") + fileName + (chunksToUse > 1 ? QString(" [%1 Chunks]").arg(chunksToUse) : ""));
        }
    }
}

void SFDLSauger::stopDownload()
{
    int tabIndex = ui->tabWidget->currentIndex();
    QString id = ui->tabWidget->tabToolTip(tabIndex);

    addLogText(id + tr(": Download abgebrochen!"));

    bool isChuckedDownload = false;

    QMutableListIterator<FTPDownload*> it(g_Worker);
    while(it.hasNext())
    {
        FTPDownload* w = it.next();

        if(!w)
        {
            it.remove();
            continue;
        }

        if(id == w->_id)
        {
            disconnect(w, nullptr, this, nullptr);

            if(w->thread() && w->thread()->isRunning())
            {
                if(w->_working)
                {
                    if(w->m_isChunked)
                    {
                        isChuckedDownload = true;
                    }

                    QMetaObject::invokeMethod(w, "abort", Qt::QueuedConnection);

                    updateDownloadFileStatus(id, w->_tableRow, tr("User Abbruch!"), 9);
                    QThread* t = w->thread();
                    t->quit();
                    w->deleteLater();
                }

                QThread* t = w->thread();
                connect(t, &QThread::finished, t, &QThread::deleteLater);
                t->quit();
            }

            w->deleteLater();
            it.remove();

            if (g_runningDownloads > 0)
            {
                g_runningDownloads--;
            }
        }
        else if(!w->_working)
        {
            w->deleteLater();
            it.remove();
        }
    }

    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(ui->tabWidget->tabToolTip(tabIndex));
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

    qint64 totalResume = 0;
    QTableWidget *widget5 = widget1->findChild<QTableWidget *>("files");

    for(int i = 0; i < widget5->rowCount(); i++)
    {
        if(isChuckedDownload)
        {
            int currentStatus = widget5->item(i, 7)->text().toInt();

            if(currentStatus == 9)
            {
                QString fimeName = widget5->item(i, 2)->text();
                QString donloadPath = QDir::cleanPath(settingsWindow->_downloadPath + "/" + id + "/" + fimeName);
                QString fullFilePath = QDir::toNativeSeparators(donloadPath);

                QTimer::singleShot(1500, this, [this, id, fullFilePath, fimeName]() {
                    if (QFile::exists(fullFilePath))
                    {
                        if (QFile::remove(fullFilePath))
                        {
                            addLogText(id + tr(": Datei gelöscht (Chunk-Download abgebrochen): ") + fimeName);
                        }
                        else
                        {
                            addLogText(id + tr(": FEHLER: Datei konnte nicht gelöscht werden: ") + fimeName);
                        }
                    }
                });
            }
        }
        else
        {
            QString fimeName = widget5->item(i, 2)->text();
            QString donloadPath = QDir::cleanPath(settingsWindow->_downloadPath + "/" + id + "/" + fimeName);
            QFileInfo fileInfo(QDir::toNativeSeparators(donloadPath));

            qint64 actualSizeOnDisk = 0;
            if(fileInfo.exists())
            {
                actualSizeOnDisk = fileInfo.size();
            }

            if(widget5->item(i, 0)->checkState() == Qt::Checked && widget5->item(i, 7)->text().toInt() != 10)
            {
                widget5->item(i, 15)->setText(QString::number(actualSizeOnDisk));
            }

            totalResume += actualSizeOnDisk;
        }
    }

    if(totalResume)
    {
        QTableWidget *widget6 = widget1->findChild<QTableWidget *>("status");
        widget6->item(0, 17)->setText(QString::number(totalResume));
    }

    changeCHKBOX(id, false);

    g_tabDownloads[id] = 0;
}

void SFDLSauger::downloadError(QString error)
{
    addLogText(tr("<font color=\"red\">[") + error + tr("] Allgemeiner FTP Download Fehler!</font>"));
    MsgWarning(tr("Download Fehler"), "[" + error + tr("] Allgemeiner FTP Download Fehler!"));
}

// update progress on downloads
void SFDLSauger::updateDownloadProgress(QString tabID, int nRow, qint64 read, qint64 total, bool overwriteTime = false, bool firstUpdate = false)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(tabID);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

    qint64 resume = widget2->item(nRow, 15)->text().toLongLong();
    if(resume && !firstUpdate)
    {
        read += resume;
    }

    qint64 currentMSecs = QDateTime::currentMSecsSinceEpoch();

    if((currentMSecs - g_lastProgressUpdate) >= 250 || total <= read || overwriteTime)
    {
        g_lastProgressUpdate = currentMSecs;

        int progress = 0;
        if (total > 0)
        {
            progress = static_cast<int>((read * 100) / total);
        }

        if (overwriteTime && progress >= 100)
        {
            QProgressBar *PROGBAR = widget2->findChild<QProgressBar *>("pbarIn_" + QString::number(nRow));
            if(PROGBAR) progress = PROGBAR->value();
        }
        else
        {
            if(progress > 100) progress = 100;
            if(progress < 0) progress = 0;
        }

        QProgressBar *PROGBAR = widget2->findChild<QProgressBar *>("pbarIn_" + QString::number(nRow));
        if(PROGBAR) PROGBAR->setValue(progress);

        qint64 start_time_ms = widget2->item(nRow, 8)->text().toLongLong();
        qint64 zeit_s = 0;
        qint64 mbSec = 0;

        if(start_time_ms == 0)
        {
            widget2->item(nRow, 8)->setText(QString::number(currentMSecs));
            widget2->item(nRow, 9)->setText(QString::number(currentMSecs));
        }
        else
        {
            widget2->item(nRow, 9)->setText(QString::number(currentMSecs));

            qint64 diff_ms = currentMSecs - start_time_ms;
            zeit_s = diff_ms / 1000;

            if(diff_ms < 1) diff_ms = 1;

            qint64 bytesSinceStart = (resume && !firstUpdate) ? (read - resume) : read;
            mbSec = (bytesSinceStart * 1000) / diff_ms;
        }

        if(overwriteTime) { mbSec = 0; zeit_s = 0; }

        widget2->item(nRow, 10)->setText(bytes2Human(mbSec) + "/s");
        widget2->item(nRow, 11)->setText(seconds_to_DHMS(zeit_s));

        qlonglong lastReadData = widget2->item(nRow, 12)->text().toLongLong();
        widget2->item(nRow, 12)->setText(QString::number(read));

        QTableWidget *widget3 = widget1->findChild<QTableWidget *>("status");
        qlonglong t_totalSize = widget3->item(0, 6)->text().toLongLong();
        qlonglong t_sizeLoaded = widget3->item(0, 8)->text().toLongLong();

        t_sizeLoaded += (read - lastReadData);
        if(firstUpdate) t_sizeLoaded += read;

        qlonglong t_startTime_ms = widget3->item(0, 12)->text().toLongLong();
        qlonglong t_stopTime_ms = widget3->item(0, 16)->text().toLongLong();
        qint64 t_zeit_s = 0;
        qint64 t_mbSec = 0;

        if(t_startTime_ms == 0)
        {
            widget3->item(0, 12)->setText(QString::number(currentMSecs));
            widget3->item(0, 13)->setText(QString::number(currentMSecs));
        }
        else
        {
            widget3->item(0, 13)->setText(QString::number(currentMSecs));
            qint64 t_diff_ms = currentMSecs - t_startTime_ms;

            if(t_stopTime_ms > 0)
            {
                t_diff_ms = t_stopTime_ms;
                widget3->item(0, 16)->setText("0");
                widget3->item(0, 12)->setText(QString::number(currentMSecs - t_stopTime_ms));
            }

            if(t_diff_ms < 1) t_diff_ms = 1;
            t_zeit_s = t_diff_ms / 1000;
            t_mbSec = (t_sizeLoaded * 1000) / t_diff_ms;
        }

        if(overwriteTime) { t_mbSec = 0; t_zeit_s = 0; }

        widget3->item(0, 8)->setText(QString::number(t_sizeLoaded));
        widget3->item(0, 9)->setText(bytes2Human(t_sizeLoaded));
        widget3->item(0, 14)->setText(bytes2Human(t_mbSec) + "/s");
        widget3->item(0, 15)->setText(seconds_to_DHMS(t_zeit_s));

        if(t_totalSize > 0)
        {
            qlonglong totalProgress = (t_sizeLoaded * 100) / t_totalSize;
            widget1->findChild<QProgressBar *>("mProgBar")->setValue(static_cast<int>(totalProgress));

            // update task-bar icon
            int targetTabIndex = ui->tabWidget->indexOf(widget1);
            if(targetTabIndex == ui->tabWidget->currentIndex())
            {
                if(totalProgress > 0 && totalProgress < 100)
                {
                    m_taskbarProgress->setProgress(totalProgress);
                }
                else
                {
                    m_taskbarProgress->clearProgress();
                }
            }
        }

        QLabel *statusLabel = widget1->findChild<QLabel *>("mStatusText");
        statusLabel->setText(bytes2Human(t_sizeLoaded) + tr(" von ") + bytes2Human(t_totalSize) + tr(" geladen. (") + bytes2Human(t_mbSec) + "/s | " + seconds_to_DHMS(t_zeit_s) + ")");
    }
}

void SFDLSauger::updateChunkedDownloadProgress(QString tabID, int nRow, int chunkIndex, qint64 chunkRead, qint64 totalSize)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(tabID);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");
    QTableWidgetItem *item = widget2->item(nRow, 12);

    QVariantList chunkList = item->data(Qt::UserRole).toList();

    QTableWidgetItem *chunkItem = widget2->item(nRow, 7);
    if(!chunkItem) return;

    int totalChunks = chunkItem->data(Qt::UserRole).toInt();
    while(chunkList.size() < totalChunks)
    {
        chunkList.append(0);
    }

    qint64 expectedChunkSize = totalSize / totalChunks;

    if(chunkIndex >= 0 && chunkIndex < chunkList.size())
    {
        qint64 previousRead = chunkList[chunkIndex].toLongLong();
        chunkList[chunkIndex] = chunkRead;

        if(previousRead < expectedChunkSize && chunkRead >= expectedChunkSize)
        {
            int remainingChunks = chunkItem->data(Qt::UserRole).toInt();

            if(remainingChunks > 0)
            {
                remainingChunks--;
                chunkItem->setData(Qt::UserRole, remainingChunks);
                chunkItem->setText(QString::number(remainingChunks));
            }
        }
    }

    item->setData(Qt::UserRole, chunkList);

    qint64 totalReadForFile = 0;
    for(const QVariant &val : qAsConst(chunkList))
    {
        totalReadForFile += val.toLongLong();
    }

    updateDownloadProgress(tabID, nRow, totalReadForFile, totalSize, false, false);

    if(totalSize > 0 && totalReadForFile >= totalSize)
    {
        item->setData(Qt::UserRole, QVariant());

        chunkItem->setData(Qt::UserRole, 0);
        chunkItem->setText("0");

        updateDownloadFileStatus(tabID, nRow, "Fertig", 10);
    }
}

void SFDLSauger::updateDownloadFileStatus(QString tabID, int nRow, QString statusMsg, int status)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(tabID);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

    int remainingChunks = widget2->item(nRow, 7)->data(Qt::UserRole).toInt();

    if(status == 9 || status == 10)
    {
        g_runningDownloads--;
        g_tabDownloads[tabID]--;
    }

    if(status == 10)
    {
        if(remainingChunks > 1)
        {
            remainingChunks--;
            widget2->item(nRow, 7)->setData(Qt::UserRole, remainingChunks);
            startDownload(tabID);
            return;
        }
        widget2->item(nRow, 7)->setData(Qt::UserRole, 0);
    }
    else if(status == 9)
    {
        widget2->item(nRow, 7)->setData(Qt::UserRole, 0);
    }

    widget2->item(nRow, 6)->setText(statusMsg);
    widget2->item(nRow, 6)->setToolTip(statusMsg);
    widget2->item(nRow, 7)->setText(QString::number(status));

    if(status == 9)
    {
        QTableWidget *widget4 = widget1->findChild<QTableWidget *>("status");
        widget4->item(0, 10)->setText(statusMsg);
        widget4->item(0, 11)->setText(QString::number(status));
    }

    if(status == 10)
    {
        QString fileName = widget2->item(nRow, 2)->text();
        addLogText(fileName + tr(": Fertig!"));

        QProgressBar *PROGBAR = widget2->findChild<QProgressBar *>("pbarIn_" + QString::number(nRow));
        if(PROGBAR) PROGBAR->setValue(100);

        if(allDownloadsDone(tabID) == true)
        {
            disableStartStopButton(tabID);
            widget1->findChild<QProgressBar *>("mProgBar")->setValue(100);

            if(settingsWindow->_sfdl_move_file_to_download)
            {
                QTableWidget *widget4 = widget1->findChild<QTableWidget *>("status");
                QString sfdl_src = QDir::cleanPath(widget4->item(0, 18)->text());
                QString dest_path = QDir::cleanPath(settingsWindow->_downloadPath + "/" + tabID + "/");
                QString dest_filepath = QDir::toNativeSeparators(QDir(dest_path).filePath(QFileInfo(sfdl_src).fileName()));

                if(QFile::rename(sfdl_src, dest_filepath))
                {
                    addLogText(tabID + tr(": SFDL Datei in den Download-Pfad verschoben."));
                }
                else
                {
                    addLogText(tabID + tr(": FEHLER: Konnte SFDL Datei nicht in den Download-Pfad verschieben!"));
                }
            }

            runNextStep(tabID);
            return;
        }

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

// send notifications
void SFDLSauger::sendNotifications(QString id)
{
    if(settingsWindow->_send_notifications)
    {
        QString n_title = "SFDLSauger Pro";
        QString n_text = id + tr(" - Download beendet!");

        if(settingsWindow->_send_pushover)
        {
            m_notifier->sendMessage(NotificationClient::Pushover, n_title, n_text);
        }

        if(settingsWindow->_send_pushsafer)
        {
            m_notifier->sendMessage(NotificationClient::Pushsafer, n_title, n_text);
        }

        if(settingsWindow->_send_email)
        {
            m_notifier->sendMessage(NotificationClient::Email, n_title, n_text);
        }
    }

    runNextStep(id);
}

// start sys commands
void SFDLSauger::startSystemCommands(QString id)
{
    if(m_activeCommandIds.contains(id))
    {
        runNextStep(id);

        return;
    }
    m_activeCommandIds.insert(id);
    QThread* thread = new QThread();
    QString cleanDLPath = QDir::toNativeSeparators(QDir::cleanPath(settingsWindow->_downloadPath + "/" + id));
    CommandWorker* worker = new CommandWorker(settingsWindow->getCustomCommands(), cleanDLPath);
    worker->moveToThread(thread);
    connect(thread, &QThread::started, worker, &CommandWorker::startExecution);
    connect(worker, &CommandWorker::commandStarted, this, [this](QString name){
        addLogText(tr("Starte Befehl: ") + name);
    });
    connect(worker, &CommandWorker::logOutput, this, [this](QString output){
        addLogText(tr("Konsole: ") + output.trimmed());
    });
    connect(worker, &CommandWorker::allCommandsFinished, this, [this, id](bool executed){
        m_activeCommandIds.remove(id);
        if(executed)
        {
            addLogText(QString("[%1] ").arg(id) + tr("Alle Systembefehle abgearbeitet."));
        }
    });
    connect(worker, &CommandWorker::allCommandsFinished, this, [thread](bool executed){
        Q_UNUSED(executed);
        thread->quit();
    });
    connect(worker, &CommandWorker::allCommandsFinished, this, [worker](bool executed){
        Q_UNUSED(executed);
        worker->deleteLater();
    });
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    thread->start();

    runNextStep(id);
}

// check if all the tabs are done
void SFDLSauger::chkAllTabDownloadsAreDone()
{
    bool allDone = false;
    for(int i = 0; i < ui->tabWidget->count(); ++i)
    {
        QString tabID = ui->tabWidget->tabToolTip(i);
        if(!tabID.isEmpty())
        {
            if(allDownloadsDone(tabID))
            {
                allDone = true;
            }
            else
            {
                allDone = false;
            }
        }
    }

    // shut down pc
    if(allDone && settingsWindow->_shutdown_pc)
    {
        shutdownPC();
    }
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
    QStringList fileList;
    for(int i = 0; i < widget4->rowCount(); i++)
    {
        // enable checkbox again
        widget4->item(i, 0)->setFlags(widget4->item(i, 0)->flags() | Qt::ItemIsUserCheckable);

        if(widget4->item(i, 0)->checkState() == Qt::Checked && widget4->item(i, 7)->text().toInt() == 10)
        {
            totalFileCount++;

            fileList.append(widget4->item(i, 2)->text() + " [" + widget4->item(i, 4)->text() + "]");
        }
    }

    QString upper = widget3->item(2, 1)->text();
    QString sizeLoaded = widget2->item(0, 9)->text();
    QString mbSec = widget2->item(0, 14)->text();
    if(mbSec.startsWith('0')) { mbSec.remove(0, 1); }
    QString zeit = widget2->item(0, 15)->text();

    QString speedreport = settingsWindow->_downloadPath + id + "/speedreport.txt";
    QString datum = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss");

    QFile speedreportFile(speedreport);
    if(speedreportFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        speedreportFile.write("[B]SFDLSauger Pro v");
        speedreportFile.write(QString(APP_VERSION).toUtf8());
        speedreportFile.write(" Speedreport[/B] (");
        speedreportFile.write(datum.toUtf8());
        speedreportFile.write(")\n[HR][/HR]\n");
        speedreportFile.write("[B]Name:[/B] ");
        speedreportFile.write(id.toUtf8());
        speedreportFile.write("\n");
        speedreportFile.write("[B]Uploader:[/B] ");
        speedreportFile.write(upper.toUtf8());
        speedreportFile.write("\n");
        speedreportFile.write(tr("[B]Bericht:[/B] ").toUtf8());
        speedreportFile.write(QString::number(totalFileCount).toUtf8());
        speedreportFile.write(tr(" Dateien (").toUtf8());
        speedreportFile.write(sizeLoaded.toUtf8());
        speedreportFile.write(tr("), mit durchschnittlich ").toUtf8());
        speedreportFile.write(mbSec.toUtf8());
        speedreportFile.write(tr(" in ").toUtf8());
        speedreportFile.write(zeit.toUtf8());
        speedreportFile.write(tr(" geladen!\n").toUtf8());
        speedreportFile.write(tr("[B]Dateien:[/B]\n").toUtf8());
        for(const QString &fileName : fileList)
        {
            speedreportFile.write(fileName.toUtf8() + "\n");
        }
        speedreportFile.write("\n");
        speedreportFile.write(tr("[B]Kommentar:[/B] Besten Dank!\n").toUtf8());
    }
    speedreportFile.close();
    QDesktopServices::openUrl(QUrl(speedreport, QUrl::TolerantMode));

    runNextStep(id);
}

void SFDLSauger::crc32Check(QString id)
{
    if(id.isEmpty())
    {
        id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());
    }

    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    if (!widget1) return;

    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");
    if (!widget2) return;

    QString path = settingsWindow->_downloadPath + id + "/";
    widget2->showColumn(13);

    for(int i = 0; i < widget2->rowCount(); i++)
    {
        if(widget2->item(i, 0) &&
            widget2->item(i, 0)->checkState() == Qt::Checked &&
            widget2->item(i, 7)->text().toInt() == 10 &&
            widget2->item(i, 13)->text().isEmpty())
        {
            CrcTask task;
            task.id = id;
            task.row = i;
            task.filePath = path + widget2->item(i, 2)->text();
            m_crcQueue.enqueue(task);
        }
    }

    while(g_runningCRC32 < g_maxCRC32 && !m_crcQueue.isEmpty())
    {
        processNextCrcTask();
    }
}

void SFDLSauger::processNextCrcTask()
{
    if(m_crcQueue.isEmpty() || g_runningCRC32 >= g_maxCRC32)
    {
        return;
    }

    CrcTask task = m_crcQueue.dequeue();
    g_runningCRC32++;

    auto thread = new QThread(this);
    thread->setProperty("tabId", task.id);

    QString fileName = QFileInfo(task.filePath).fileName();
    addLogText("[" + task.id + "] CRC32: " + fileName + tr(" - start!"));

    QStringList data = { task.id, QString::number(task.row), task.filePath };
    auto worker = new Crc32(data);

    worker->moveToThread(thread);

    m_activeWorker.append(worker);
    m_activeThreads.append(thread);

    connect(thread, &QThread::started, worker, &Crc32::calculateFromFile);
    connect(worker, &Crc32::updateCRC32data, this, &SFDLSauger::updateCRC32);
    connect(worker, &Crc32::finished, thread, &QThread::quit);

    connect(thread, &QThread::finished, this, [this, worker, thread, task]() {
        m_activeWorker.removeOne(worker);
        m_activeThreads.removeOne(thread);
        g_runningCRC32--;

        QString fileName = QFileInfo(task.filePath).fileName();
        addLogText("[" + task.id + "] CRC32: " + fileName + tr(" - fertig!"));

        worker->deleteLater();
        thread->deleteLater();

        processNextCrcTask();

        bool queueHasItemsForThisTab = false;
        for(const CrcTask& queuedTask : qAsConst(m_crcQueue))
        {
            if (queuedTask.id == task.id) {
                queueHasItemsForThisTab = true;
                break;
            }
        }

        bool threadsRunningForThisTab = false;
        for(const auto& activeThread : qAsConst(m_activeThreads))
        {
            if(activeThread && activeThread->property("tabId").toString() == task.id)
            {
                threadsRunningForThisTab = true;
                break;
            }
        }

        if(!queueHasItemsForThisTab && !threadsRunningForThisTab)
        {
            runNextStep(task.id);
        }

        worker->deleteLater();
        thread->deleteLater();

    }, Qt::QueuedConnection);

    thread->start();
}

void SFDLSauger::stopAllCrcThreads(QString id)
{
    if(id.isEmpty())
    {
        m_crcQueue.clear();
    }
    else
    {
        QQueue<CrcTask> remainingTasks;
        while(!m_crcQueue.isEmpty())
        {
            CrcTask task = m_crcQueue.dequeue();

            if(task.id != id)
            {
                remainingTasks.enqueue(task);
            }
        }
        m_crcQueue = remainingTasks;
    }

    for(int i = m_activeThreads.size() - 1; i >= 0; --i)
    {
        auto thread = m_activeThreads.at(i);

        if(thread)
        {
            QString threadTabId = thread->property("tabId").toString();

            if(id.isEmpty() || threadTabId == id)
            {
                thread->quit();
                thread->wait();
            }
        }
    }

    if(id.isEmpty())
    {
        m_activeWorker.clear();
        m_activeThreads.clear();
        g_runningCRC32 = 0;
    }
}

// update CRC32 data in files table
void SFDLSauger::updateCRC32(QString id, int nRow, QString crc32Data)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    if (!widget1) return;

    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");
    if (!widget2) return;

    if(widget2->item(nRow, 13))
    {
        widget2->item(nRow, 13)->setText(crc32Data);
    }
    else
    {
        auto item = new QTableWidgetItem(crc32Data);
        widget2->setItem(nRow, 13, item);
    }
}

void SFDLSauger::sfvCheck(QString id)
{
    QString basePath = QDir::toNativeSeparators(QDir::cleanPath(settingsWindow->_downloadPath + "/" + id + "/"));

    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

    for(int j = 0; j < widget2->rowCount(); j++)
    {
        if(widget2->item(j, 13) && widget2->item(j, 13)->text().isEmpty())
        {
            QTimer::singleShot(1000, this, [this, id]() {
                sfvCheck(id);
            });
            return;
        }
    }

    QIcon icon1(":/gfx/chk.png");
    QIcon icon2(":/gfx/warning2.png");

    QRegularExpression re("^([^;].+) ([0-9a-zA-Z]{8})$");
    widget2->showColumn(14);

    QHash<QString, QMap<QString, QString>> sfvCache;

    for(int k = 0; k < widget2->rowCount(); k++)
    {
        if(!widget2->item(k, 2) || !widget2->item(k, 13) || !widget2->item(k, 14))
        {
            continue;
        }

        QString relativeFilePath = widget2->item(k, 2)->text().trimmed();
        if(relativeFilePath.isEmpty())
        {
            continue;
        }

        QFileInfo fileInfo(QDir::toNativeSeparators(QDir::cleanPath(basePath + "/" + relativeFilePath)));
        QString absoluteDir = fileInfo.absolutePath() + "/";
        QString pureFileName = fileInfo.fileName();

        QDir dir(absoluteDir);
        QStringList sfvList = dir.entryList(QStringList() << "*.sfv", QDir::Files);

        if(sfvList.isEmpty())
        {
            continue;
        }

        QString sfvFilePath = absoluteDir + sfvList.first();

        if(!sfvCache.contains(sfvFilePath))
        {
            QMap<QString, QString> currentSfvData;
            QFile inputFile(sfvFilePath);

            if(inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream in(&inputFile);
                while(!in.atEnd())
                {
                    QString line = in.readLine().trimmed();
                    if(line.isEmpty() || line.startsWith(";"))
                        continue;

                    QRegularExpressionMatch match = re.match(line);
                    if(match.hasMatch())
                    {
                        QString sfvFileName = match.captured(1).trimmed().toLower();
                        QString sfvCrc = match.captured(2).toUpper().trimmed();
                        currentSfvData.insert(sfvFileName, sfvCrc);
                    }
                }
                inputFile.close();
            }
            sfvCache.insert(sfvFilePath, currentSfvData);
        }

        QMap<QString, QString> sfvData = sfvCache.value(sfvFilePath);

        if(sfvData.contains(pureFileName.toLower()))
        {
            QString expectedSfvCrc = sfvData.value(pureFileName.toLower());
            QString calculatedCrc = widget2->item(k, 13)->text().toUpper().trimmed();

            if(calculatedCrc == expectedSfvCrc)
            {
                widget2->item(k, 14)->setIcon(icon1);
                widget2->item(k, 14)->setToolTip(expectedSfvCrc);
            }
            else
            {
                widget2->item(k, 14)->setIcon(icon2);
                widget2->item(k, 14)->setToolTip(expectedSfvCrc);
            }
        }
    }

    addLogText(tr("[") + id + tr("] SFV-Prüfung abgeschlossen!"));
    runNextStep(id);
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
    if(!settingsWindow->_unrarAutoDelete)
    {
        runNextStep(id);
        return;
    }

    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    if(!widget1)
    {
        runNextStep(id);
        return;
    }
    QLabel *statusLabel = widget1->findChild<QLabel *>("mStatusText");
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");
    if(!widget2)
    {
        runNextStep(id);
        return;
    }

    statusLabel->setText(tr("Entferne RAR Dateien ..."));

    int fileRemoveCounter = 0;
    QString basePath = QDir::toNativeSeparators(QDir::cleanPath(settingsWindow->_downloadPath + "/" + id + "/"));

    QRegularExpression rarMatch("(part[0-9]+.rar|.[a-z][0-9]+|.rar)$", QRegularExpression::CaseInsensitiveOption);

    for(int i = 0; i < widget2->rowCount(); i++)
    {
        if(widget2->item(i, 2))
        {
            QString rawPath = widget2->item(i, 2)->text();
            QStringList tFile = rawPath.split("/");
            QString fileName = tFile.last();

            QRegularExpressionMatch match = rarMatch.match(fileName);

            if(match.hasMatch())
            {
                QString fullFilePath = QDir::toNativeSeparators(QDir::cleanPath(basePath + "/" + rawPath));

                statusLabel->setText(tr("Entferne: ") + fileName);
                addLogText(tr("Entferne Datei: ") + rawPath);

                if(QFile::exists(fullFilePath))
                {
                    if(QFile::remove(fullFilePath))
                    {
                        fileRemoveCounter++;
                    }
                    else
                    {
                        addLogText(tr("<font color=\"red\">Fehler beim Löschen von: %1</font>").arg(rawPath));
                    }
                }
            }
        }
    }

    if(fileRemoveCounter > 0)
    {
        statusLabel->setText(QString::number(fileRemoveCounter) + tr(" RAR Dateien entfernt!"));
        addLogText(QString::number(fileRemoveCounter) + tr(" RAR Dateien entfernt!"));
    }
    else
    {
        statusLabel->setText(tr("Keine RAR Dateien zum Löschen gefunden."));
    }

    runNextStep(id);
}

// unrar files
void SFDLSauger::unrarFiles(QString id)
{
    struct UnrarJob {
        QString relativeFile;
        QString fullPath;
        QString extractPath;
    };

    QList<UnrarJob> jobs;
    QString basePath = QDir::toNativeSeparators(QDir::cleanPath(settingsWindow->_downloadPath + "/" + id + "/"));

    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("files");

    QRegularExpression rarMatch("(part[1].rar|[^part2-99999].rar|.+.rar)$", QRegularExpression::CaseInsensitiveOption);

    for(int i = 0; i < widget2->rowCount(); i++)
    {
        if(widget2->item(i, 2))
        {
            QString rawPath = widget2->item(i, 2)->text();
            QStringList tFile = rawPath.split("/");
            QString fileName = tFile.last();

            QRegularExpressionMatch match = rarMatch.match(fileName);
            if(match.hasMatch())
            {
                QString fullFilePath = QDir::toNativeSeparators(QDir::cleanPath(basePath + "/" + rawPath));
                QFileInfo fCHK(fullFilePath);
                if (fCHK.exists() && fCHK.isFile())
                {
                    UnrarJob job;
                    job.relativeFile = rawPath;
                    job.fullPath = fullFilePath;
                    job.extractPath = QDir::toNativeSeparators(fCHK.absolutePath() + "/");
                    jobs.append(job);
                }
            }
        }
    }

    if(jobs.isEmpty())
    {
        addLogText(tr("<font color=\"red\">[") + id + tr("] UnRAR: Keine RAR Datei(en) zum auspacken gefunden!</font>"));
        m_tabWorkflows[id].currentStep = ProcessStep::SysCommands; // skip remove rar files
        runNextStep(id);
        return;
    }

    QVariantList fullPathsVariant, extractPathsVariant;
    for(const auto& job : jobs)
    {
        fullPathsVariant.append(job.fullPath);
        extractPathsVariant.append(job.extractPath);
    }
    widget1->setProperty("unrar_queue_files", fullPathsVariant);
    widget1->setProperty("unrar_queue_paths", extractPathsVariant);

    processNextUnrarJob(id);
}

void SFDLSauger::processNextUnrarJob(QString id)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    if (!widget1) return;

    QVariantList fullPaths = widget1->property("unrar_queue_files").toList();
    QVariantList extractPaths = widget1->property("unrar_queue_paths").toList();

    // if empty = all done
    if(fullPaths.isEmpty())
    {
        // set progress (always) to 100% if done
        QProgressBar *mProgBar = widget1->findChild<QProgressBar *>("mProgBar");
        mProgBar->setValue(100);

        addLogText(tr("<font color=\"green\">[") + id + tr("] Alle UnRAR-Aufträge erfolgreich abgeschlossen!</font>"));
        runNextStep(id);
        return;
    }

    QString currentFile = fullPaths.takeFirst().toString();
    QString currentPath = extractPaths.takeFirst().toString();

    widget1->setProperty("unrar_queue_files", fullPaths);
    widget1->setProperty("unrar_queue_paths", extractPaths);

    if(!QFile::exists(currentFile))
    {
        addLogText(tr("<font color=\"red\">[") + id + tr("] UnRAR Fehler: Datei nicht mehr vorhanden: ") + currentFile + "</font>");
        QMetaObject::invokeMethod(this, [this, id]() { processNextUnrarJob(id); }, Qt::QueuedConnection);
        return;
    }

    if(settingsWindow->_unrar_user_internal)
    {
        auto thread = new QThread;
        QStringList data = { id, currentFile, currentPath };
        auto worker = new UnrarExtractor(data);
        worker->moveToThread(thread);
        g_UnRARExtractor.append(worker);

        connect(worker, &UnrarExtractor::updateUnRarProgress, this, &SFDLSauger::unrarProgressUpdate, Qt::QueuedConnection);
        connect(thread, &QThread::started, worker, &UnrarExtractor::startUnRAR);
        connect(worker, &UnrarExtractor::finished, thread, &QThread::quit);
        connect(worker, &UnrarExtractor::finished, worker, &UnrarExtractor::deleteLater);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);
        connect(worker, &UnrarExtractor::error, this, [this, id](const QString& message) {
            addLogText(tr("<font color=\"red\">[%1] UnRAR Fehler: %2</font>").arg(id, message));
            m_tabWorkflows[id].currentStep = ProcessStep::SysCommands;
            runNextStep(id);
        }, Qt::QueuedConnection);
        connect(worker, &UnrarExtractor::finished, this, [this, id]() {
            processNextUnrarJob(id);
        }, Qt::QueuedConnection);

        thread->start();
    }
    // external unrar
    else if(!settingsWindow->_unrarPath.isEmpty())
    {
        if(!QFileInfo::exists(settingsWindow->_unrarPath))
        {
            addLogText(tr("<font color=\"red\">Externes UnRAR in [%1] konnte nicht gefunden werden!</font>").arg(settingsWindow->_unrarPath));
            m_tabWorkflows[id].currentStep = ProcessStep::SysCommands;
            runNextStep(id);
            return;
        }

        auto thread = new QThread;
        QString unrar = settingsWindow->_unrarPath;
        QStringList data = { id, unrar, currentFile, currentPath };

        auto worker = new UnRAR(data);
        worker->moveToThread(thread);
        g_UnRARWorker.append(worker);

        connect(worker, &UnRAR::updateUnRarProgress, this, &SFDLSauger::unrarProgressUpdate, Qt::QueuedConnection);
        connect(thread, &QThread::started, worker, &UnRAR::startUnRAR);
        connect(worker, &UnRAR::finished, thread, &QThread::quit);
        connect(worker, &UnRAR::error, thread, &QThread::quit);
        connect(worker, &UnRAR::finished, worker, &UnRAR::deleteLater);
        connect(worker, &UnRAR::error, worker, &UnRAR::deleteLater);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);
        connect(worker, &UnRAR::error, this, [this, id](const QString& message) {
            addLogText(tr("<font color=\"red\">[%1] Externer UnRAR Fehler: %2</font>").arg(id, message));
            m_tabWorkflows[id].currentStep = ProcessStep::SysCommands;
            runNextStep(id);
        }, Qt::QueuedConnection);
        connect(worker, &UnRAR::finished, this, [this, id]() {
            processNextUnrarJob(id);
        }, Qt::QueuedConnection);

        thread->start();
    }
    // no unrar
    else
    {
        m_tabWorkflows[id].currentStep = ProcessStep::SysCommands;
        runNextStep(id);
    }
}

void SFDLSauger::unrarProgressUpdate(QString id, QString fileName, int progress)
{
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);

    // set main progress bar
    QProgressBar *mProgBar = widget1->findChild<QProgressBar *>("mProgBar");
    mProgBar->setValue(progress);
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

        stopAllCrcThreads(id);

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
    QString useDirPath = "";
    if(!settingsWindow->_lastSFDLpath.isEmpty())
    {
        useDirPath = settingsWindow->_lastSFDLpath;
    }
    else
    {
        useDirPath = qApp->applicationDirPath();
    }

    QFileDialog dialog(this);
    dialog.setDirectory(useDirPath);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter(tr("SFDL (*.sfdl)"));

    QStringList fileNames;

    if(dialog.exec())
    {
        fileNames = dialog.selectedFiles();
    }

    if(fileNames.count())
    {
        QFileInfo fileInfo(fileNames.first());
        settingsWindow->_lastSFDLpath = fileInfo.absolutePath();

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

    if(!t_host.isEmpty())
    {
        if(settingsWindow->_ex_path_filezilla.isEmpty())
        {
            QString ftpClientPath;

            #ifdef Q_OS_WIN
                ftpClientPath = QFileDialog::getOpenFileName(this, "FileZilla", "", "FileZilla (filezilla.exe)");
            #else
                ftpClientPath = QFileDialog::getOpenFileName(this, "FileZilla", "", "FileZilla (filezilla)");
            #endif

            if(!ftpClientPath.isEmpty())
            {
                settingsWindow->_ex_path_filezilla = ftpClientPath;
            }
        }

        if(!settingsWindow->_ex_path_filezilla.isEmpty())
        {
            QString program = settingsWindow->_ex_path_filezilla;
            QStringList arguments;

            if(t_path.isEmpty() || widget2->rowCount() != 23)
            {
                arguments << "ftp://" + t_user + ":" + t_pass + "@" + t_host + ":" + t_port;
            }
            else
            {
                arguments << "ftp://" + t_user + ":" + t_pass + "@" + t_host + ":" + t_port + t_path;
            }

            QProcess::startDetached(program, arguments);
        }
    }
    else
    {
        QMessageBox::warning(this, "FileZilla", tr("Kann FileZilla nicht öffnen. Kein Server ausgwählt!"));
    }
}

// open in winscp
void SFDLSauger::openInWinSCP()
{
    QString id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("data");

    QString t_host = widget2->item(7,1)->text();
    QString t_port = widget2->item(8,1)->text();
    QString t_user = widget2->item(9,1)->text();
    QString t_pass = widget2->item(10,1)->text();
    QString t_path = widget2->item(21,1)->text();

    if(!t_host.isEmpty())
    {
        if(settingsWindow->_ex_path_winscp.isEmpty())
        {
            QString ftpClientPath;

            ftpClientPath = QFileDialog::getOpenFileName(this, "WinSCP", "", "WinSCP (WinSCP.exe)");

            if(!ftpClientPath.isEmpty())
            {
                settingsWindow->_ex_path_winscp = ftpClientPath;
            }
        }

        if(!settingsWindow->_ex_path_winscp.isEmpty())
        {
            QString program = settingsWindow->_ex_path_winscp;
            QStringList arguments;

            if(t_path.isEmpty() || widget2->rowCount() != 23)
            {
                arguments << "ftp://" + t_user + ":" + t_pass + "@" + t_host + ":" + t_port;
            }
            else
            {
                arguments << "ftp://" + t_user + ":" + t_pass + "@" + t_host + ":" + t_port + t_path;
            }

            QProcess::startDetached(program, arguments);
        }
    }
    else
    {
        QMessageBox::warning(this, "WinSCP", tr("Kann WinSCP nicht öffnen. Kein Server ausgwählt!"));
    }
}

// open in ftprush
void SFDLSauger::openInFTPRushV2()
{
    QString id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("data");

    QString t_host = widget2->item(7,1)->text();
    QString t_port = widget2->item(8,1)->text();
    QString t_user = widget2->item(9,1)->text();
    QString t_pass = widget2->item(10,1)->text();
    QString t_path = widget2->item(21,1)->text();

    if(!t_host.isEmpty())
    {
        if(settingsWindow->_ex_path_ftprush_v2.isEmpty())
        {
            QString ftpClientPath;

            ftpClientPath = QFileDialog::getOpenFileName(this, "FTPRush V2", "", "FTPRush (ftprush.exe)");

            if(!ftpClientPath.isEmpty())
            {
                settingsWindow->_ex_path_ftprush_v2 = ftpClientPath;
            }
        }

        if(!settingsWindow->_ex_path_ftprush_v2.isEmpty())
        {
            QString program = settingsWindow->_ex_path_ftprush_v2;
            QStringList arguments;

            if(t_path.isEmpty() || widget2->rowCount() != 23)
            {
                arguments << "-c ftp://" + t_user + ":" + t_pass + "@" + t_host + ":" + t_port;
            }
            else
            {
                arguments << "-c ftp://" + t_user + ":" + t_pass + "@" + t_host + ":" + t_port + t_path;
            }

            QProcess::startDetached(program, arguments);
        }
    }
    else
    {
        QMessageBox::warning(this, "FTPRush v2", tr("Kann FTPRush v2 nicht öffnen. Kein Server ausgwählt!"));
    }
}

// open in flashfxp
void SFDLSauger::openInFlashFXP()
{
    QString id = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());
    QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(id);
    QTableWidget *widget2 = widget1->findChild<QTableWidget *>("data");

    QString t_host = widget2->item(7,1)->text();
    QString t_port = widget2->item(8,1)->text();
    QString t_user = widget2->item(9,1)->text();
    QString t_pass = widget2->item(10,1)->text();
    QString t_path = widget2->item(21,1)->text();

    if(!t_host.isEmpty())
    {
        if(settingsWindow->_ex_path_flashfxp.isEmpty())
        {
            QString ftpClientPath;

            ftpClientPath = QFileDialog::getOpenFileName(this, "FlashFXP", "", "FlashFXP (FlashFXP.exe)");

            if(!ftpClientPath.isEmpty())
            {
                settingsWindow->_ex_path_flashfxp = ftpClientPath;
            }
        }

        if(!settingsWindow->_ex_path_flashfxp.isEmpty())
        {
            QString program = settingsWindow->_ex_path_flashfxp;
            QStringList arguments;

            if(t_path.isEmpty() || widget2->rowCount() != 23)
            {
                arguments << "ftp://" + t_user + ":" + t_pass + "@" + t_host + ":" + t_port;
            }
            else
            {
                arguments << "ftp://" + t_user + ":" + t_pass + "@" + t_host + ":" + t_port + t_path;
            }

            QProcess::startDetached(program, arguments);
        }
    }
    else
    {
        QMessageBox::warning(this, "FlashFXP", tr("Kann FlashFXP nicht öffnen. Kein Server ausgwählt!"));
    }
}

// open about window
void SFDLSauger::on_action_ber_triggered()
{   
    infoWindow->setWindowTitle(tr("Über ") + QString(APP_PRODUCT));
    infoWindow->setWindowFlags(infoWindow->windowFlags() & ~Qt::WindowContextHelpButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    infoWindow->setSizeGripEnabled(false);
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

bool SFDLSauger::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->textEdit || obj == ui->textEdit->viewport())
    {
        if(event->type() == QEvent::MouseMove)
        {
            QMouseEvent *me = static_cast<QMouseEvent*>(event);
            if(!ui->textEdit->anchorAt(me->pos()).isEmpty())
            {
                ui->textEdit->viewport()->setCursor(Qt::PointingHandCursor);
            }
            else
            {
                ui->textEdit->viewport()->setCursor(Qt::ArrowCursor);
            }
        }

        if(event->type() == QEvent::MouseButtonDblClick)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                QTimer::singleShot(0, this, &SFDLSauger::openLogsDialog);
                return true;
            }
        }

        if(event->type() == QEvent::MouseButtonRelease)
        {
            QMouseEvent *me = static_cast<QMouseEvent*>(event);
            QString link = ui->textEdit->anchorAt(me->pos());

            if(!link.isEmpty())
            {
                if(event->type() == QEvent::MouseButtonRelease)
                {
                    QDesktopServices::openUrl(QUrl(link));
                }
                return true;
            }
        }
    }

    return QMainWindow::eventFilter(obj, event);
}

void SFDLSauger::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
    QWidget::changeEvent(event);
}

void SFDLSauger::showLogMenu(const QPoint &pos)
{
    if(logsWindow && logsWindow->isVisible())
    {
        return;
    }

    QMenu menu(this);
    auto *action = menu.addAction(QIcon(":/gfx/log.png"), tr("Logs öffnen"));
    connect(action, &QAction::triggered, this, &SFDLSauger::openLogsDialog);
    menu.exec(ui->textEdit->mapToGlobal(pos));
}

void SFDLSauger::openLogsDialog()
{
    if(logsWindow)
    {
        if(logsWindow->isVisible())
        {
            logsWindow->raise();
            logsWindow->activateWindow();
            return;
        }
    }
    else
    {
        logsWindow = new LiveLogs(this);
    }

    logsWindow->setWindowTitle("Logs");
    logsWindow->setObjectName("LogsWindow");
    logsWindow->setWindowFlags(logsWindow->windowFlags() & ~Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    logsWindow->setSizeGripEnabled(true);
    logsWindow->show();
}

void SFDLSauger::openIRCDialog()
{
    if(ircChatWindow)
    {
        if(ircChatWindow->isVisible())
        {
            ircChatWindow->raise();
            ircChatWindow->activateWindow();
            return;
        }
    }
    else
    {
        ircChatWindow = new chatIRC(this);
    }

    ircChatWindow->setWindowTitle("IRC Chat (" + QString(APP_PRODUCT) + " v" + QString(APP_VERSION) + ")");
    ircChatWindow->setObjectName("IrcChat");
    ircChatWindow->setWindowFlags(ircChatWindow->windowFlags() & ~Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    ircChatWindow->setSizeGripEnabled(true);
    ircChatWindow->show();
}

void SFDLSauger::on_actionIRC_Chat_triggered()
{
    openIRCDialog();
}

void SFDLSauger::on_actionStrukturreformator_triggered()
{
    QString home = QStandardPaths::locate(QStandardPaths::DownloadLocation, QString(), QStandardPaths::LocateDirectory);

    // get data from active tab
    QWidget *activeWidget = ui->tabWidget->currentWidget();
    if(activeWidget)
    {
        QString id = activeWidget->objectName();
        QString currentDir = settingsWindow->_downloadPath + "/" + id;
        if(QDir(currentDir).exists())
        {
            home = currentDir;
        }
    }

    QString reformatorPath = QFileDialog::getExistingDirectory(this, tr("Welcher Pfad soll restrukturiert werden?"), home, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if(!reformatorPath.isEmpty())
    {
        QString release = QDir(reformatorPath).dirName();

        addLogText(tr(": Starte Strukturreformator: Release: " ) + release + tr(", Pfad: ") + reformatorPath);

        FileOrganizer organizer(reformatorPath, release);

        if(organizer.reorganizeFiles())
        {
            addLogText(tr(": Alles erfolgreich neu sortiert!"));
        }
        else
        {
            addLogText("<font color=\"red\">" + tr(": Fehler beim Neuordnen der Dateien!</font>"));
        }
    }
}

void SFDLSauger::startWebServer()
{
    if(webWorkerThread && webWorkerThread->isRunning()) return;

    webWorkerThread = new QThread;
    wwworker = new WebServerWorker(settingsWindow->_webserver_host,
                                   settingsWindow->_webserver_port.toInt()
                                   );
    wwworker->moveToThread(webWorkerThread);

    connect(webWorkerThread, &QThread::started, wwworker, &WebServerWorker::process);
    connect(wwworker, &WebServerWorker::finished, webWorkerThread, &QThread::quit);
    connect(wwworker, &WebServerWorker::xmlReceived, this, &SFDLSauger::handleIncomingSFDL);
    connect(wwworker, &WebServerWorker::sendLogText, this, &SFDLSauger::addLogText);
    connect(wwworker, &WebServerWorker::finished, wwworker, &WebServerWorker::deleteLater);
    connect(webWorkerThread, &QThread::finished, webWorkerThread, &QThread::deleteLater);

    connect(this, &SFDLSauger::webLogAdded, wwworker, &WebServerWorker::addLogText);

    // get log archive on webserver (re)start
    QString allText = ui->textEdit->toPlainText();
    QStringList lines = allText.split('\n', Qt::SkipEmptyParts);
    QRegularExpression re("^\\[\\d{2}-\\d{2}-\\d{4} \\d{2}:\\d{2}:\\d{2}\\]");
    for(const QString &rawLine : qAsConst(lines))
    {
        QString trimmedLine = rawLine.trimmed();
        if(trimmedLine.isEmpty()) continue;

        QRegularExpressionMatch match = re.match(trimmedLine);

        if(match.hasMatch())
        {
            QString timestamp = match.captured(0);
            QString message = trimmedLine.mid(timestamp.length());
            QString reconstructedHtml = "<font color=\"grey\">" + timestamp + "</font>" + message + "<br />";
            emit webLogAdded(reconstructedHtml);
        }
        else
        {
            emit webLogAdded(trimmedLine + "<br />");
        }
    }

    webWorkerThread->start();

    emit webServerStatusChanged(true);
}

void SFDLSauger::stopWebServer()
{
    if(wwworker)
    {
        wwworker->stop();
        webWorkerThread->quit();
        webWorkerThread->wait();

        wwworker = nullptr;
        webWorkerThread = nullptr;

        emit webServerStatusChanged(false);
    }
    else
    {
        startWebServer();
        emit webServerStatusChanged(true);
    }
}

void SFDLSauger::handleIncomingSFDL(QString xmlContent, QString fileName)
{
    QString path = settingsWindow->_webserver_upload_path;
    QDir dir;
    if(!dir.exists(path))
    {
        if(!dir.mkpath(path))
        {
            addLogText(tr("Webserver: Pfad zum Speichern der SFDL Datei konnte nicht erstellt werden: ") + path);
        }
    }

    fileName = QDir::toNativeSeparators(QDir::cleanPath(path + "/" + fileName));

    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out.setCodec("UTF-8");
        out << xmlContent;
        file.close();

        addLogText(tr("Webserver: SFDL Datei erfolgreich gespeichert: ") + fileName);
    }
    else
    {
        addLogText(tr("Webserver Fehler: Konnte Datei nicht schreiben: ") + file.errorString());
    }
}

void SFDLSauger::startFileWatching()
{
    if (m_watcherThread) return;

    m_watcherThread = new QThread(this);
    m_watcher = new FileWatcher();
    m_watcher->moveToThread(m_watcherThread);

    connect(m_watcherThread, &QThread::finished, m_watcher, &QObject::deleteLater);
    connect(m_watcher, &FileWatcher::fileDetected, this, &SFDLSauger::loadSFDL);

    m_watcherThread->start();

    int fileWatcherTimer = settingsWindow->_filewatcher_interval.toInt() * 1000;

    QMetaObject::invokeMethod(m_watcher, "start",
                              Q_ARG(QString, settingsWindow->_filewatcher_path),
                              Q_ARG(QString, ".sfdl"),
                              Q_ARG(int, fileWatcherTimer));
}

void SFDLSauger::stopFileWatching()
{
    if (!m_watcherThread) return;

    QMetaObject::invokeMethod(m_watcher, "stop");

    m_watcherThread->quit();
    if(!m_watcherThread->wait(3000))
    {
        m_watcherThread->terminate();
    }

    m_watcherThread->deleteLater();
    m_watcherThread = nullptr;
    m_watcher = nullptr;
}

void SFDLSauger::updateFileWatching(const QString &newPath, int newInterval)
{
    if(m_watcher)
    {
        QMetaObject::invokeMethod(m_watcher, "setPath", Q_ARG(QString, newPath));
        QMetaObject::invokeMethod(m_watcher, "setInterval", Q_ARG(int, newInterval));
    }
}

void SFDLSauger::shutdownPC()
{
    QString program;
    QStringList arguments;

    // windows
#if defined(Q_OS_WIN)
    program = "shutdown";
    arguments << "/s" << "/t" << "0";

    // linux
#elif defined(Q_OS_LINUX)
    program = "systemctl";
    arguments << "poweroff";

    // mac
#elif defined(Q_OS_MAC)
    program = "osascript";
    arguments << "-e" << "tell app \"System Events\" to shut down";
#endif

    bool success = QProcess::startDetached(program, arguments);
    if(!success)
    {
        addLogText(tr("Fehler: Shutdown-Befehl konnte nicht gestartet werden."));
    }
}

// after download task manager
void SFDLSauger::runNextStep(const QString& tabID)
{
    if(!m_tabWorkflows.contains(tabID))
    {
        m_tabWorkflows[tabID] = TabControl();
    }

    TabControl& control = m_tabWorkflows[tabID];

    if(control.isStopped)
    {
        control.currentStep = ProcessStep::Idle;
        m_tabWorkflows.remove(tabID);
        return;
    }

    if(control.isPaused)
    {
        return;
    }

    switch(control.currentStep)
    {
    case ProcessStep::Idle:
        if(settingsWindow->_play_sound_finish)
        {
            finishSound->play();
        }
        control.currentStep = ProcessStep::SpeedReport;
        runNextStep(tabID);
        break;

    case ProcessStep::SpeedReport:
        control.currentStep = ProcessStep::SendNotifications;
        createSpeedreport(tabID);
        break;

    case ProcessStep::SendNotifications:
        control.currentStep = ProcessStep::CrcCheck;
        sendNotifications(tabID);
        break;

    case ProcessStep::CrcCheck:
        if(settingsWindow->_crc32Check)
        {
            control.currentStep = ProcessStep::SfvCheck;
            crc32Check(tabID);
        }
        else
        {
            control.currentStep = ProcessStep::Unrar;
            runNextStep(tabID);
        }
        break;

    case ProcessStep::SfvCheck:
        if(settingsWindow->_crc32Check && settingsWindow->_sfvCheck)
        {
            control.currentStep = ProcessStep::Unrar;
            sfvCheck(tabID);
        }
        else
        {
            control.currentStep = ProcessStep::Unrar;
            runNextStep(tabID);
        }
        break;

    case ProcessStep::Unrar:
        if(settingsWindow->_unrarAutoEtract)
        {
            control.currentStep = ProcessStep::UnrarAutoDeleteFiles;
            unrarFiles(tabID);
        }
        else
        {
            control.currentStep = ProcessStep::SysCommands;
            runNextStep(tabID);
        }
        break;

    case ProcessStep::UnrarAutoDeleteFiles:
        control.currentStep = ProcessStep::SysCommands;

        if(settingsWindow->_unrarAutoEtract && settingsWindow->_unrarAutoDelete)
        {
            unrarDeleteFiles(tabID);
        }
        else
        {
            runNextStep(tabID);
        }
        break;

    case ProcessStep::SysCommands:
        control.currentStep = ProcessStep::ChkAllDownloads;
        startSystemCommands(tabID);
        break;

    case ProcessStep::ChkAllDownloads:
        control.currentStep = ProcessStep::Finished;
        chkAllTabDownloadsAreDone();
        break;

    case ProcessStep::Finished:
        addLogText(tabID + tr(": Alles fertig!"));

        QWidget *widget1 = ui->tabWidget->findChild<QWidget *>(tabID);
        QLabel *statusLabel = widget1->findChild<QLabel *>("mStatusText");
        statusLabel->setText(tr("Alles fertig!"));

        m_tabWorkflows.remove(tabID);
        break;
    }
}

