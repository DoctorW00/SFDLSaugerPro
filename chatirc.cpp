#include "chatirc.h"
#include "ui_chatirc.h"
#include <QScrollBar>
#include <QShortcut>
#include <QRegularExpressionValidator>
#include <QSettings>
#include <QMessageBox>
#include <QInputDialog>
#include <QTimer>
#include <QSslSocket>
#include <IrcTextFormat>
#include <IrcConnection>
#include <Irc>

chatIRC::chatIRC(QWidget *parent) : QDialog(parent), ui(new Ui::chatIRC)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/gfx/irc.png"));

    loadIRCLayout();


    connect(ui->selectIRCServer, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &chatIRC::on_selectIRCServer_currentIndexChanged);
    connect(ui->selectIRCProxy, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &chatIRC::on_selectIRCProxy_currentIndexChanged);
    connect(ui->buttonSetup, &QPushButton::clicked, this, &chatIRC::createSetupDialog);

    setupServerComboBox();
    setupProxyComboBox();

    disableChatUi();
    ui->buttonSetup->setDisabled(false);
    ui->ircConnectButton->setDisabled(true);

    QRegularExpression rx("^[a-zA-Z0-9\\-\\|\\^\\_\\{\\}\\[\\]]+$");
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(rx, this);

    ui->lineNickName->setValidator(validator);
    ui->lineUserName->setValidator(validator);
    ui->lineRealName->setValidator(validator);

    connection = new IrcConnection(this);
    connect(connection, &IrcConnection::socketError, this, [this](QAbstractSocket::SocketError error)
    {
        auto* socket = connection->socket();
        QString errMsg = QString("[IRC SOCKET ERROR] %1: %2").arg(error).arg(socket ? socket->errorString() : "<no socket>");
        appendDebugMessage(errMsg);
        if(ircServer_UseSSL && error == QAbstractSocket::RemoteHostClosedError)
        {
            appendDebugMessage(tr("[HINWEIS] SSL/TLS: Prüfe, ob OpenSSL-DLLs vorhanden sind (libssl-1_1-x64.dll und libcrypto-1_1-x64.dll) oder ob der Port korrekt ist."));
        }
    });
    connect(connection, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(connection, SIGNAL(connecting()), this, SLOT(onConnecting()));
    connect(connection, SIGNAL(disconnected()), this, SLOT(onDisconnected()));

    proxySocket = new QTcpSocket(connection);

    createParser();
    // createConnection();
    createCompleter();
    createUserList();
    createBufferList();

    ui->ircConnectButton->setEnabled(true);
}

chatIRC::~chatIRC()
{
    if(connection)
    {
        if(connection->isActive())
        {
            connection->quit(connection->realName());
            connection->close();
        }
    }

    delete ui;
}

/*
const QVector<gsIrcServerInfo>& chatIRC::predefinedServers()
{
    static const QVector<gsIrcServerInfo> servers{
        { "MLC IRC (SSL)", "irc.mlc.to", 6697, true, "MLC_User", "MLC_Lover", "MLC_Liebhaber", "", "#mlcboard" }
    };
    return servers;
}

const QVector<gsSocks5ProxyInfo>& chatIRC::predefinedProxies()
{
    static const QVector<gsSocks5ProxyInfo> proxies{
        { "Tor (localhost 9050)", "127.0.0.1", 9050, "", "" },
        { "Tor (localhost 9150)", "127.0.0.1", 9150, "", "" }
    };
    return proxies;
}
*/

const QVector<gsIrcServerInfo>& chatIRC::predefinedServers()
{
    static const QVector<gsIrcServerInfo> servers{
        gsIrcServerInfo("MLC IRC (SSL)", "irc.mlc.to", 6697, true, "MLC_User", "MLC_Lover", "MLC_Liebhaber", "", "#mlcboard")
    };
    return servers;
}

const QVector<gsSocks5ProxyInfo>& chatIRC::predefinedProxies()
{
    static const QVector<gsSocks5ProxyInfo> proxies{
        gsSocks5ProxyInfo("Tor (localhost 9050)", "127.0.0.1", 9050, "", ""),
        gsSocks5ProxyInfo("Tor (localhost 9150)", "127.0.0.1", 9150, "", "")
    };
    return proxies;
}

void chatIRC::loadIRCLayout()
{
    ui->inputEdit->setFocus();

    connect(ui->inputEdit, &QLineEdit::textChanged, this, [=](const QString &text)
    {
        ui->buttonChatSend->setEnabled(!text.trimmed().isEmpty());
        ui->buttonChatSend->setStyleSheet(text.trimmed().isEmpty() ? "background:#353535;" : "background:#00b16a;");
    });

    ui->chatBrowser->document()->setDefaultStyleSheet(
        "body { line-height: 1.5; } "
        ".nick { font-weight: bold; color: #88c0ff; }"
        );
}

void chatIRC::setupServerComboBox()
{
    ui->selectIRCServer->clear();

    for(const auto& srv : predefinedServers())
    {
        ui->selectIRCServer->addItem(srv.displayName, QVariant::fromValue(srv));
    }

    QVector<gsIrcServerInfo> custom;
    QVector<gsSocks5ProxyInfo> dummy;
    loadCustomServers(custom, dummy);
    for(const auto& srv : custom)
    {
        ui->selectIRCServer->addItem(srv.displayName, QVariant::fromValue(srv));
    }

    ui->selectIRCServer->setCurrentIndex(0);
    updateNickUserRealFromCurrentServer();
}

void chatIRC::setupProxyComboBox()
{
    gsSocks5ProxyInfo currentProxy;
    int currentIdx = ui->selectIRCProxy->currentIndex();
    if(currentIdx >= 0)
    {
        currentProxy = ui->selectIRCProxy->itemData(currentIdx).value<gsSocks5ProxyInfo>();
    }

    ui->selectIRCProxy->blockSignals(true);
    ui->selectIRCProxy->clear();

    gsSocks5ProxyInfo direct;
    direct.displayName = tr("Direct (kein Proxy)");
    direct.host.clear();
    direct.port = 0;
    ui->selectIRCProxy->addItem(direct.displayName, QVariant::fromValue(direct));

    for(const auto& p : predefinedProxies())
    {
        ui->selectIRCProxy->addItem(p.displayName + " (vordefiniert)", QVariant::fromValue(p));
    }

    QVector<gsIrcServerInfo> dummyServers;
    QVector<gsSocks5ProxyInfo> customProxies;
    loadCustomServers(dummyServers, customProxies);
    for(const auto& p : customProxies)
    {
        ui->selectIRCProxy->addItem(p.displayName, QVariant::fromValue(p));
    }

    int newIndex = 0;  // Default: Direct
    for (int i = 0; i < ui->selectIRCProxy->count(); ++i) {
        gsSocks5ProxyInfo p = ui->selectIRCProxy->itemData(i).value<gsSocks5ProxyInfo>();
        if (p.displayName == currentProxy.displayName &&
            p.host == currentProxy.host &&
            p.port == currentProxy.port &&
            p.user == currentProxy.user &&
            p.password == currentProxy.password)
        {
            newIndex = i;
            break;
        }
    }

    ui->selectIRCProxy->setCurrentIndex(newIndex);
    ui->selectIRCProxy->blockSignals(false);

    on_selectIRCProxy_currentIndexChanged(newIndex);
}

void chatIRC::on_selectIRCServer_currentIndexChanged(int index)
{
    if (index < 0) return;

    updateNickUserRealFromCurrentServer();

    gsIrcServerInfo srv = ui->selectIRCServer->itemData(index).value<gsIrcServerInfo>();

    ircServer_DisplayName = srv.displayName;
    ircServer_Host        = srv.hostname;
    ircServer_Port        = srv.port;
    ircServer_Room        = srv.defaultChannel;
    ircServer_UserName    = srv.user;
    ircServer_NickName    = srv.nick;
    ircServer_RealName    = srv.real;
    ircServer_Password    = srv.password;
    ircServer_UseSSL      = srv.ssl;

    /*
    qDebug() << "IRC Server:";
    qDebug() << "  DisplayName:" << ircServer_DisplayName;
    qDebug() << "  Hostname:"    << ircServer_Host;
    qDebug() << "  Port:"        << ircServer_Port;
    qDebug() << "  Room:"        << ircServer_Room;
    qDebug() << "  Nick:"        << ircServer_NickName;
    qDebug() << "  Realname:"    << ircServer_RealName;
    qDebug() << "  Password:"    << ircServer_Password;
    qDebug() << "  SSL:"         << ircServer_UseSSL;
    */
}

void chatIRC::on_selectIRCProxy_currentIndexChanged(int index)
{
    if(index < 0) return;

    gsSocks5ProxyInfo proxy = ui->selectIRCProxy->itemData(index).value<gsSocks5ProxyInfo>();

    ircServer_ProxyName = proxy.displayName;
    ircServer_ProxyHost = proxy.host;
    ircServer_ProxyPort = proxy.port;
    ircServer_ProxyUser = proxy.user;
    ircServer_ProxyPass = proxy.password;

    ircServer_UseProxy = false;
    if(ircServer_ProxyHost.length() && ircServer_ProxyPort)
    {
        ircServer_UseProxy = true;
    }

    /*
    qDebug() << "IRC Proxy:";
    qDebug() << "  DisplayName 2:" << ircServer_ProxyName;
    qDebug() << "  Hostname:"    << ircServer_ProxyHost;
    qDebug() << "  Port:"        << ircServer_ProxyPort;
    qDebug() << "  User:"        << ircServer_ProxyUser;
    qDebug() << "  Pass:"        << ircServer_ProxyPass;
    qDebug() << "  UseProxy:"    << ircServer_UseProxy;
    */
}

void chatIRC::saveCustomServers(const QVector<gsIrcServerInfo>& servers, const QVector<gsSocks5ProxyInfo>& proxies)
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "SFDLSaugerPro", "irc_data");

    settings.remove("CustomIrcServers");
    settings.remove("CustomSocks5Proxies");

    settings.beginWriteArray("CustomIrcServers");
    for(int i = 0; i < servers.size(); ++i)
    {
        settings.setArrayIndex(i);
        const auto& s = servers[i];
        settings.setValue("displayName",       s.displayName);
        settings.setValue("hostname",          s.hostname);
        settings.setValue("port",              s.port);
        settings.setValue("ssl",               s.ssl);
        settings.setValue("nick",              s.nick);
        settings.setValue("user",              s.user);
        settings.setValue("real",              s.real);
        settings.setValue("password",          s.password);
        settings.setValue("defaultChannel",    s.defaultChannel);
    }
    settings.endArray();

    settings.beginWriteArray("CustomSocks5Proxies");
    for (int i = 0; i < proxies.size(); ++i) {
        settings.setArrayIndex(i);
        const auto& p = proxies[i];
        settings.setValue("displayName", p.displayName);
        settings.setValue("host",        p.host);
        settings.setValue("port",        p.port);
        settings.setValue("user",        p.user);
        settings.setValue("password",    p.password);
    }
    settings.endArray();

    settings.sync();
}

void chatIRC::loadCustomServers(QVector<gsIrcServerInfo>& servers, QVector<gsSocks5ProxyInfo>& proxies)
{
    servers.clear();
    proxies.clear();

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "SFDLSaugerPro", "irc_data");

    int serverSize = settings.beginReadArray("CustomIrcServers");
    for(int i = 0; i < serverSize; ++i)
    {
        settings.setArrayIndex(i);
        gsIrcServerInfo s;
        s.displayName    = settings.value("displayName").toString();
        s.hostname       = settings.value("hostname").toString();
        s.port           = settings.value("port", 6667).toInt();
        s.ssl            = settings.value("ssl", false).toBool();
        s.nick           = settings.value("nick", "MyNick").toString();
        s.user           = settings.value("user", "user").toString();
        s.real           = settings.value("real", "Real Name").toString();
        s.password       = settings.value("password").toString();
        s.defaultChannel = settings.value("defaultChannel").toString();

        if (!s.displayName.isEmpty() && !s.hostname.isEmpty())
        {
            servers.append(s);
        }
    }
    settings.endArray();

    int proxySize = settings.beginReadArray("CustomSocks5Proxies");
    for(int i = 0; i < proxySize; ++i)
    {
        settings.setArrayIndex(i);
        gsSocks5ProxyInfo p;
        p.displayName = settings.value("displayName").toString();
        p.host        = settings.value("host").toString();
        p.port        = settings.value("port", 1080).toInt();
        p.user        = settings.value("user").toString();
        p.password    = settings.value("password").toString();

        if(!p.displayName.isEmpty())
        {
            proxies.append(p);
        }
    }
    settings.endArray();
}

QVector<gsIrcServerInfo> chatIRC::getAllServers()
{
    QVector<gsIrcServerInfo> all = predefinedServers();

    QVector<gsIrcServerInfo> custom;
    QVector<gsSocks5ProxyInfo> dummy;
    loadCustomServers(custom, dummy);

    all.append(custom);
    return all;
}

QVector<gsSocks5ProxyInfo> chatIRC::getAllProxies()
{
    QVector<gsSocks5ProxyInfo> all = predefinedProxies();

    QVector<gsIrcServerInfo> dummy;
    QVector<gsSocks5ProxyInfo> custom;
    loadCustomServers(dummy, custom);

    all.append(custom);
    return all;
}

void chatIRC::onConnected()
{
    enableChatUi();

    if(ircServer_Room.length())
    {
        connection->sendCommand(IrcCommand::createJoin(ircServer_Room));
    }

    ui->chatBrowser->append(IrcMessageFormatter::formatMessage(QStringLiteral("! Connected to %1.")).arg(ircServer_DisplayName));
    ui->chatBrowser->append(IrcMessageFormatter::formatMessage(QStringLiteral("! Joining %1...")).arg(ircServer_Room));
}

void chatIRC::onConnecting()
{
    ui->chatBrowser->append(IrcMessageFormatter::formatMessage(QStringLiteral("! Connecting %1...")).arg(ircServer_DisplayName));
}

void chatIRC::onDisconnected()
{
    disableChatUi();

    ui->ircConnectButton->setText(tr("Verbinden"));
    ui->splitter_2->setSizes({100, 1});

    ui->chatBrowser->append(IrcMessageFormatter::formatMessage(QStringLiteral("! Disconnected from %1.")).arg(ircServer_DisplayName));
}

void chatIRC::closeEvent(QCloseEvent *event)
{
    if (connection && connection->isActive())
    {
        connection->quit(connection->realName());
        connection->close();
    }
    QDialog::closeEvent(event);
}

void chatIRC::onTextEdited()
{
    ui->inputEdit->setStyleSheet(QString());
}

void chatIRC::onTextEntered()
{
    if(connection)
    {
        if(!connection->isActive())
        {
            ui->inputEdit->clear();
            return;
        }
    }
    else
    {
        ui->inputEdit->clear();
        return;
    }

    QString input = ui->inputEdit->text();
    IrcCommand* command = parser->parse(input);
    if(command)
    {
        connection->sendCommand(command);

        if(command->type() == IrcCommand::Message || command->type() == IrcCommand::CtcpAction) {
            IrcMessage* msg = command->toMessage(connection->nickName(), connection);
            receiveMessage(msg);
            msg->deleteLater();
        }

        ui->inputEdit->clear();
        ui->inputEdit->setFocus();

    }else if(input.length() > 1)
    {
        QString error;
        QString command = ui->inputEdit->text().mid(1).split(QStringLiteral(" "), Qt::SkipEmptyParts).value(0).toUpper();
        if(parser->commands().contains(command))
        {
            error = tr("[ERROR] Syntax: %1").arg(parser->syntax(command).replace(QLatin1String("<"), QLatin1String("&lt;")).replace(QLatin1String(">"), QLatin1String("&gt;")));
        }
        else
        {
            error = tr("[ERROR] Unknown command: %1").arg(command);
        }
        ui->chatBrowser->append(IrcMessageFormatter::formatMessage(error));
        ui->inputEdit->setStyleSheet(QStringLiteral("background: salmon"));
    }
}

void chatIRC::onCompletion()
{
    completer->complete(ui->inputEdit->text(), ui->inputEdit->cursorPosition());
}

void chatIRC::onCompleted(const QString& text, int cursor)
{
    ui->inputEdit->setText(text);
    ui->inputEdit->setCursorPosition(cursor);
}

void chatIRC::onBufferAdded(IrcBuffer* buffer)
{
    connect(buffer, SIGNAL(messageReceived(IrcMessage*)), this, SLOT(receiveMessage(IrcMessage*)));
    QTextDocument* document = new QTextDocument(buffer);
    documents.insert(buffer, document);
    IrcUserModel* userModel = new IrcUserModel(buffer);
    userModel->setSortMethod(Irc::SortByTitle);
    userModels.insert(buffer, userModel);

    int idx = bufferModel->buffers().indexOf(buffer);
    if(idx != -1)
    {
        ui->bufferView->setCurrentIndex(bufferModel->index(idx));
    }
}

void chatIRC::onBufferRemoved(IrcBuffer* buffer)
{
    delete userModels.take(buffer);
    delete documents.take(buffer);
}

void chatIRC::onBufferActivated(const QModelIndex& index)
{
    IrcBuffer* buffer = index.data(Irc::BufferRole).value<IrcBuffer*>();
    ui->chatBrowser->setDocument(documents.value(buffer));
    ui->chatBrowser->verticalScrollBar()->triggerAction(QScrollBar::SliderToMaximum);
    ui->userList->setModel(userModels.value(buffer));
    completer->setBuffer(buffer);

    if(buffer)
    {
        parser->setTarget(buffer->title());
    }
}

void chatIRC::onUserActivated(const QModelIndex& index)
{
    IrcUser* user = index.data(Irc::UserRole).value<IrcUser*>();
    if(user)
    {
        IrcBuffer* buffer = bufferModel->add(user->name());
        int idx = bufferModel->buffers().indexOf(buffer);
        if (idx != -1)
        {
            ui->bufferView->setCurrentIndex(bufferModel->index(idx));
        }
    }
}

static void appendHtml(QTextDocument* document, const QString& html)
{
    QTextCursor cursor(document);
    cursor.beginEditBlock();
    cursor.movePosition(QTextCursor::End);
    if(!document->isEmpty())
    {
        cursor.insertBlock();
    }
    cursor.insertHtml(html);
    cursor.endEditBlock();
}

void chatIRC::receiveMessage(IrcMessage* message)
{
    // raw debug
    QString raw;
    if(!message->prefix().isEmpty())
    {
        raw += ":" + message->prefix() + " ";
    }
    raw += message->command();
    for(const QString& p : message->parameters())
    {
        raw += " " + p;
    }
    qDebug().noquote() << "[IRC RAW]" << raw;

    IrcBuffer* buffer = qobject_cast<IrcBuffer*>(sender());
    if(!buffer)
    {
        buffer = ui->bufferView->currentIndex().data(Irc::BufferRole).value<IrcBuffer*>();
    }

    QTextDocument* document = documents.value(buffer);
    if(document)
    {
        QString html = IrcMessageFormatter::formatMessage(message);
        if(!html.isEmpty())
        {
            if(document == ui->chatBrowser->document())
            {
                ui->chatBrowser->append(html);
            }
            else
            {
                appendHtml(document, html);
            }
        }
    }
}

void chatIRC::createCompleter()
{
    completer = new IrcCompleter(this);
    completer->setParser(parser);
    connect(completer, SIGNAL(completed(QString,int)), this, SLOT(onCompleted(QString,int)));

    QShortcut* shortcut = new QShortcut(Qt::Key_Tab, this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(onCompletion()));
}

void chatIRC::createUserList()
{
    ui->userList->setFocusPolicy(Qt::NoFocus);
    connect(ui->userList, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onUserActivated(QModelIndex)));
}

void chatIRC::createBufferList()
{
    bufferModel = new IrcBufferModel(connection);
    connect(bufferModel, SIGNAL(added(IrcBuffer*)), this, SLOT(onBufferAdded(IrcBuffer*)));
    connect(bufferModel, SIGNAL(removed(IrcBuffer*)), this, SLOT(onBufferRemoved(IrcBuffer*)));

    ui->bufferView->setFocusPolicy(Qt::NoFocus);
    ui->bufferView->setModel(bufferModel);

    connect(bufferModel, SIGNAL(channelsChanged(QStringList)), parser, SLOT(setChannels(QStringList)));
    connect(ui->bufferView->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(onBufferActivated(QModelIndex)));

    IrcBuffer* serverBuffer = bufferModel->add(connection->host());

    connect(bufferModel, SIGNAL(messageIgnored(IrcMessage*)), serverBuffer, SLOT(receiveMessage(IrcMessage*)));
}

void chatIRC::createParser()
{
    parser = new IrcCommandParser(this);
    parser->setTolerant(true);
    parser->setTriggers(QStringList("/"));
    parser->addCommand(IrcCommand::Join, QStringLiteral("JOIN <#channel> (<key>)"));
    parser->addCommand(IrcCommand::CtcpAction, QStringLiteral("ME [target] <message...>"));
    parser->addCommand(IrcCommand::Mode, QStringLiteral("MODE (<channel/user>) (<mode>) (<arg>)"));
    parser->addCommand(IrcCommand::Nick, QStringLiteral("NICK <nick>"));
    parser->addCommand(IrcCommand::Part, QStringLiteral("PART (<#channel>) (<message...>)"));
}

bool chatIRC::createConnection()
{
    /*
    qDebug() << "IRC Con:";
    qDebug() << "  DisplayName:" << ircServer_DisplayName;
    qDebug() << "  Hostname:"    << ircServer_Host;
    qDebug() << "  Port:"        << ircServer_Port;
    qDebug() << "  Room:"        << ircServer_Room;
    qDebug() << "  NickName:"    << ircServer_NickName;
    qDebug() << "  RealName:"    << ircServer_RealName;
    qDebug() << "  UserName:"    << ircServer_UserName;
    qDebug() << "  Password:"    << ircServer_Password;
    qDebug() << "  SSL:"         << ircServer_UseSSL;
    qDebug() << "  -------------------------------------- ";
    qDebug() << "  DisplayName:" << ircServer_ProxyName;
    qDebug() << "  Hostname:"    << ircServer_ProxyHost;
    qDebug() << "  Port:"        << ircServer_ProxyPort;
    qDebug() << "  User:"        << ircServer_ProxyUser;
    qDebug() << "  Pass:"        << ircServer_ProxyPass;
    qDebug() << "  UseProxy:"    << ircServer_UseProxy;
    */

    if(connection->isActive())
    {
        connection->quit(connection->realName());
        connection->close();
    }

    // connection->setReconnectDelay(10);

    if(ircServer_UseProxy)
    {
        proxySocket->setProxy(QNetworkProxy(QNetworkProxy::Socks5Proxy,
                                       ircServer_ProxyHost,
                                       ircServer_ProxyPort,
                                       ircServer_ProxyUser,
                                       ircServer_ProxyPass
                                       ));
    }
    else
    {
        proxySocket->setProxy(QNetworkProxy::NoProxy);
    }

    connection->setSocket(proxySocket);

    connection->setHost(ircServer_Host);

    if(ircServer_UseSSL && !QSslSocket::supportsSsl())
    {
        appendDebugMessage(tr("[SSL] Diese Qt-Installation hat keine SSL-Unterstützung oder OpenSSL fehlt."));
        appendDebugMessage(tr("[SSL] Bitte OpenSSL 1.1 DLLs neben der EXE platzieren: libssl-1_1-x64.dll + libcrypto-1_1-x64.dll."));
        return false;
    }

    connection->setSecure(ircServer_UseSSL);

    int port = ircServer_Port;
    if(ircServer_UseSSL && port == 6667)
    {
        port = 6697;
    }
    else if(!ircServer_UseSSL && port == 6697)
    {
        port = 6667;
    }
    connection->setPort(port);

    QString nick = ui->lineNickName->text().trimmed();
    QString user = ui->lineUserName->text().trimmed();
    QString real = ui->lineRealName->text().trimmed();

    if(nick.isEmpty()) nick = ircServer_NickName;
    if(user.isEmpty()) user = ircServer_UserName;
    if(real.isEmpty()) real = ircServer_RealName;

    if(nick.isEmpty())
    {
        nick = QString("SFDLUser%1").arg(QRandomGenerator::global()->bounded(10000));
    }
    if(user.isEmpty()) user = nick;
    if(real.isEmpty()) real = nick;

    connection->setUserName(user);
    connection->setNickName(nick);
    connection->setRealName(real);

    if(ircServer_Password.length())
    {
        connection->setSaslMechanism("PLAIN");
        connection->setPassword(ircServer_Password);
    }

    connection->open();
    return true;

    /*
    if(ircServer_Room.length())
    {
        connection->sendCommand(IrcCommand::createJoin(ircServer_Room));
    }
    */
}

void chatIRC::on_inputEdit_returnPressed()
{
    onTextEntered();
}

void chatIRC::on_buttonChatSend_pressed()
{
    onTextEntered();
}

void chatIRC::disableChatUi()
{
    ui->bufferView->setDisabled(true);
    ui->chatBrowser->setDisabled(true);
    ui->userList->setDisabled(true);
    ui->inputEdit->setDisabled(true);
    ui->buttonChatSend->setDisabled(true);
    ui->splitter->setDisabled(true);
}

void chatIRC::enableChatUi()
{
    ui->bufferView->setEnabled(true);
    ui->chatBrowser->setEnabled(true);
    ui->userList->setEnabled(true);
    ui->inputEdit->setEnabled(true);
    ui->buttonChatSend->setEnabled(true);
    ui->splitter->setEnabled(true);
}

void chatIRC::connectButtonHandling()
{
    if(connection->isActive())
    {
        ui->ircConnectButton->setText(tr("Verbinden"));

        connection->quit(connection->realName());
        connection->close();

        ui->splitter_2->setSizes({100, 1});
    }
    else
    {
        ui->ircConnectButton->setText(tr("Trennen"));
        if(!createConnection())
        {
            ui->ircConnectButton->setText(tr("Verbinden"));
            ui->splitter_2->setSizes({100, 1});
            return;
        }

        ui->splitter_2->setCollapsible(0, false);
        ui->splitter_2->setSizes({100, 1});
    }
}

void chatIRC::on_ircConnectButton_pressed()
{
    connectButtonHandling();
}

void chatIRC::createSetupDialog()
{
    if(setupDialog)
    {
        setupDialog->deleteLater();
        setupDialog = nullptr;
    }

    comboServers = nullptr;
    comboProxies = nullptr;

    editDisplayName = nullptr;
    editHostname = nullptr;
    editNick = nullptr;
    editUser = nullptr;
    editReal = nullptr;
    editPass = nullptr;
    editDefaultChannel = nullptr;

    spinPort = nullptr;
    checkSsl = nullptr;

    editProxyDisplayName = nullptr;
    editProxyHost = nullptr;
    editProxyUser = nullptr;
    editProxyPassword = nullptr;
    spinProxyPort = nullptr;

    btnAddServer = nullptr;
    btnUpdateServer = nullptr;
    btnDeleteServer = nullptr;
    btnAddProxy = nullptr;
    btnUpdateProxy = nullptr;
    btnDeleteProxy = nullptr;

    setupDialog = new QDialog(this);
    setupDialog->setAttribute(Qt::WA_DeleteOnClose);
    setupDialog->setWindowTitle(tr("IRC Server & Proxy Setup"));
    setupDialog->resize(800, 700);

    auto* layout = new QVBoxLayout(setupDialog);

    auto* gbServer = new QGroupBox(tr("IRC Server"), setupDialog);
    auto* gridServer = new QGridLayout(gbServer);
    int row = 0;

    gridServer->addWidget(new QLabel(tr("Vorhandene Server:")), row, 0);
    comboServers = new QComboBox;
    gridServer->addWidget(comboServers, row++, 1, 1, 3);

    gridServer->addWidget(new QLabel(tr("Anzeigename:")), row, 0);
    editDisplayName = new QLineEdit;    gridServer->addWidget(editDisplayName, row++, 1, 1, 3);

    gridServer->addWidget(new QLabel(tr("Hostname:")), row, 0);
    editHostname = new QLineEdit;       gridServer->addWidget(editHostname, row++, 1, 1, 3);

    gridServer->addWidget(new QLabel(tr("Port:")), row, 0);
    spinPort = new QSpinBox; spinPort->setRange(1, 65535); spinPort->setValue(6667);
    gridServer->addWidget(spinPort, row++, 1);

    checkSsl = new QCheckBox(tr("SSL/TLS"));
    gridServer->addWidget(checkSsl, row++, 1);

    gridServer->addWidget(new QLabel(tr("Nickname:")), row, 0);
    editNick = new QLineEdit;
    gridServer->addWidget(editNick, row++, 1, 1, 3);

    gridServer->addWidget(new QLabel(tr("Username:")), row, 0);
    editUser = new QLineEdit;
    gridServer->addWidget(editUser, row++, 1, 1, 3);

    gridServer->addWidget(new QLabel(tr("Real Name:")), row, 0);
    editReal = new QLineEdit;
    gridServer->addWidget(editReal, row++, 1, 1, 3);

    gridServer->addWidget(new QLabel(tr("Passwort:")), row, 0);
    editPass = new QLineEdit;
    editPass->setEchoMode(QLineEdit::Password);
    gridServer->addWidget(editPass, row++, 1, 1, 3);

    gridServer->addWidget(new QLabel(tr("Default Channel:")), row, 0);
    editDefaultChannel = new QLineEdit;
    gridServer->addWidget(editDefaultChannel, row++, 1, 1, 3);

    auto* btnLayoutServer = new QHBoxLayout;
    btnAddServer    = new QPushButton(tr("Hinzufügen"));
    btnUpdateServer = new QPushButton(tr("Aktualisieren"));
    btnDeleteServer = new QPushButton(tr("Löschen"));
    btnLayoutServer->addWidget(btnAddServer);
    btnLayoutServer->addWidget(btnUpdateServer);
    btnLayoutServer->addWidget(btnDeleteServer);
    gridServer->addLayout(btnLayoutServer, row++, 0, 1, 4);

    layout->addWidget(gbServer);

    auto* gbProxy = new QGroupBox(tr("SOCKS5 Proxy"), setupDialog);
    auto* gridProxy = new QGridLayout(gbProxy);
    row = 0;

    gridProxy->addWidget(new QLabel(tr("Vorhandene Proxys:")), row, 0);
    comboProxies = new QComboBox;
    gridProxy->addWidget(comboProxies, row++, 1, 1, 3);

    gridProxy->addWidget(new QLabel(tr("Anzeigename:")), row, 0);
    editProxyDisplayName = new QLineEdit;
    gridProxy->addWidget(editProxyDisplayName, row++, 1, 1, 3);

    gridProxy->addWidget(new QLabel(tr("Host:")), row, 0);
    editProxyHost = new QLineEdit;
    gridProxy->addWidget(editProxyHost, row++, 1, 1, 3);

    gridProxy->addWidget(new QLabel(tr("Port:")), row, 0);
    spinProxyPort = new QSpinBox;
    spinProxyPort->setRange(0, 65535);
    gridProxy->addWidget(spinProxyPort, row++, 1);

    gridProxy->addWidget(new QLabel(tr("User:")), row, 0);
    editProxyUser = new QLineEdit;
    gridProxy->addWidget(editProxyUser, row++, 1, 1, 3);

    gridProxy->addWidget(new QLabel(tr("Passwort:")), row, 0);
    editProxyPassword = new QLineEdit;
    editProxyPassword->setEchoMode(QLineEdit::Password);
    gridProxy->addWidget(editProxyPassword, row++, 1, 1, 3);

    auto* btnLayoutProxy = new QHBoxLayout;
    btnAddProxy    = new QPushButton(tr("Hinzufügen"));
    btnUpdateProxy = new QPushButton(tr("Aktualisieren"));
    btnDeleteProxy = new QPushButton(tr("Löschen"));
    btnLayoutProxy->addWidget(btnAddProxy);
    btnLayoutProxy->addWidget(btnUpdateProxy);
    btnLayoutProxy->addWidget(btnDeleteProxy);
    gridProxy->addLayout(btnLayoutProxy, row++, 0, 1, 4);

    layout->addWidget(gbProxy);

    auto* btnClose = new QPushButton(tr("Schließen"));
    connect(btnClose, &QPushButton::clicked, setupDialog, &QDialog::accept);
    layout->addWidget(btnClose, 0, Qt::AlignRight);

    connect(comboServers, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &chatIRC::loadCurrentServerIntoFields);
    connect(comboProxies, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &chatIRC::loadCurrentProxyIntoFields);

    connect(btnAddServer,    &QPushButton::clicked, this, &chatIRC::on_btnAddServer_clicked);
    connect(btnUpdateServer, &QPushButton::clicked, this, &chatIRC::on_btnUpdateServer_clicked);
    connect(btnDeleteServer, &QPushButton::clicked, this, &chatIRC::on_btnDeleteServer_clicked);

    connect(btnAddProxy,     &QPushButton::clicked, this, &chatIRC::on_btnAddProxy_clicked);
    connect(btnUpdateProxy,  &QPushButton::clicked, this, &chatIRC::on_btnUpdateProxy_clicked);
    connect(btnDeleteProxy,  &QPushButton::clicked, this, &chatIRC::on_btnDeleteProxy_clicked);

    refreshServerCombo();
    refreshProxyCombo();

    setupDialog->show();
}

void chatIRC::refreshServerCombo()
{
    comboServers->clear();
    for(const auto& s : predefinedServers())
    {
        comboServers->addItem(s.displayName + " (vordefiniert)", QVariant::fromValue(s));
    }
    QVector<gsIrcServerInfo> custom;
    QVector<gsSocks5ProxyInfo> dummy;
    loadCustomServers(custom, dummy);
    for(const auto& s : custom)
    {
        comboServers->addItem(s.displayName, QVariant::fromValue(s));
    }
}

void chatIRC::refreshProxyCombo()
{
    comboProxies->clear();
    for(const auto& p : predefinedProxies())
    {
        comboProxies->addItem(p.displayName + " (vordefiniert)", QVariant::fromValue(p));
    }
    QVector<gsIrcServerInfo> dummy;
    QVector<gsSocks5ProxyInfo> custom;
    loadCustomServers(dummy, custom);
    for(const auto& p : custom)
    {
        comboProxies->addItem(p.displayName, QVariant::fromValue(p));
    }
}

void chatIRC::loadCurrentServerIntoFields()
{
    int idx = comboServers->currentIndex();
    if (idx < 0) return;
    gsIrcServerInfo srv = comboServers->itemData(idx).value<gsIrcServerInfo>();

    bool isPredefined = (idx < predefinedServers().size());
    btnUpdateServer->setEnabled(!isPredefined);
    btnDeleteServer->setEnabled(!isPredefined);

    editDisplayName->setText(srv.displayName);
    editHostname->setText(srv.hostname);
    spinPort->setValue(srv.port);
    checkSsl->setChecked(srv.ssl);
    editNick->setText(srv.nick);
    editUser->setText(srv.user);
    editReal->setText(srv.real);
    editPass->setText(srv.password);
    editDefaultChannel->setText(srv.defaultChannel);
}

void chatIRC::loadCurrentProxyIntoFields()
{
    int idx = comboProxies->currentIndex();
    if (idx < 0) return;
    gsSocks5ProxyInfo p = comboProxies->itemData(idx).value<gsSocks5ProxyInfo>();

    bool isPredefined = (idx < predefinedProxies().size());
    btnUpdateProxy->setEnabled(!isPredefined);
    btnDeleteProxy->setEnabled(!isPredefined);

    editProxyDisplayName->setText(p.displayName);
    editProxyHost->setText(p.host);
    spinProxyPort->setValue(p.port);
    editProxyUser->setText(p.user);
    editProxyPassword->setText(p.password);
}

void chatIRC::on_btnAddServer_clicked()
{
    gsIrcServerInfo srv;
    srv.displayName     = editDisplayName->text().trimmed();
    srv.hostname        = editHostname->text().trimmed();
    srv.port            = spinPort->value();
    srv.ssl             = checkSsl->isChecked();
    srv.nick            = editNick->text().trimmed();
    srv.user            = editUser->text().trimmed();
    srv.real            = editReal->text().trimmed();
    srv.defaultChannel  = editDefaultChannel->text().trimmed();

    if(srv.displayName.isEmpty() || srv.hostname.isEmpty())
    {
        QMessageBox::warning(this, tr("Fehler"), tr("Anzeigename und Hostname dürfen nicht leer sein!"));
        return;
    }

    QVector<gsIrcServerInfo> custom;
    QVector<gsSocks5ProxyInfo> dummy;
    loadCustomServers(custom, dummy);
    custom.append(srv);
    saveCustomServers(custom, dummy);

    refreshServerCombo();
    comboServers->setCurrentIndex(comboServers->count()-1);
    setupServerComboBox();
}

void chatIRC::on_btnUpdateServer_clicked()
{
    int idx = comboServers->currentIndex();
    if (idx < predefinedServers().size()) return;

    gsIrcServerInfo srv = comboServers->itemData(idx).value<gsIrcServerInfo>();
    srv.displayName     = editDisplayName->text().trimmed();
    srv.hostname        = editHostname->text().trimmed();
    srv.port            = spinPort->value();
    srv.ssl             = checkSsl->isChecked();
    srv.nick            = editNick->text().trimmed();
    srv.user            = editUser->text().trimmed();
    srv.real            = editReal->text().trimmed();
    srv.password        = editPass->text().trimmed();
    srv.defaultChannel  = editDefaultChannel->text().trimmed();

    if(srv.displayName.isEmpty() || srv.hostname.isEmpty())
    {
        QMessageBox::warning(this, tr("Fehler"), tr("Anzeigename und Hostname dürfen nicht leer sein!"));
        return;
    }

    QVector<gsIrcServerInfo> custom;
    QVector<gsSocks5ProxyInfo> dummy;
    loadCustomServers(custom, dummy);
    int customIdx = idx - predefinedServers().size();
    custom[customIdx] = srv;
    saveCustomServers(custom, dummy);

    refreshServerCombo();
    comboServers->setCurrentIndex(idx);
    setupServerComboBox();
}

void chatIRC::on_btnDeleteServer_clicked()
{
    int idx = comboServers->currentIndex();
    if (idx < predefinedServers().size()) return;

    if(QMessageBox::question(this, tr("Löschen?"), tr("Diesen Server wirklich löschen?")) != QMessageBox::Yes)
    {
        return;
    }

    QVector<gsIrcServerInfo> custom;
    QVector<gsSocks5ProxyInfo> dummy;
    loadCustomServers(custom, dummy);
    custom.removeAt(idx - predefinedServers().size());
    saveCustomServers(custom, dummy);

    refreshServerCombo();
    setupServerComboBox();
}

void chatIRC::on_btnAddProxy_clicked()
{
    gsSocks5ProxyInfo proxy;
    proxy.displayName = editProxyDisplayName->text().trimmed();
    proxy.host        = editProxyHost->text().trimmed();
    proxy.port        = spinProxyPort->value();
    proxy.user        = editProxyUser->text().trimmed();
    proxy.password    = editProxyPassword->text();

    if(proxy.displayName.isEmpty())
    {
        QMessageBox::warning(this, tr("Fehler"), tr("Anzeigename darf nicht leer sein!"));
        return;
    }

    if(!proxy.host.isEmpty() && proxy.port == 0)
    {
        QMessageBox::warning(this, tr("Fehler"), tr("Wenn Host angegeben ist, muss auch ein Port > 0 gesetzt sein!"));
        return;
    }

    QVector<gsIrcServerInfo> dummyServers;
    QVector<gsSocks5ProxyInfo> customProxies;
    loadCustomServers(dummyServers, customProxies);

    for(const auto& p : customProxies)
    {
        if(p.displayName == proxy.displayName)
        {
            QMessageBox::warning(this, tr("Fehler"), tr("Ein Proxy mit diesem Anzeigenamen existiert bereits!"));
            return;
        }
    }

    customProxies.append(proxy);
    saveCustomServers(dummyServers, customProxies);

    refreshProxyCombo();

    comboProxies->setCurrentIndex(comboProxies->count() - 1);
    setupProxyComboBox();
}

void chatIRC::on_btnUpdateProxy_clicked()
{
    int idx = comboProxies->currentIndex();
    if (idx < 0) return;
    if (idx < predefinedProxies().size()) return;

    gsSocks5ProxyInfo proxy = comboProxies->itemData(idx).value<gsSocks5ProxyInfo>();

    proxy.displayName = editProxyDisplayName->text().trimmed();
    proxy.host        = editProxyHost->text().trimmed();
    proxy.port        = spinProxyPort->value();
    proxy.user        = editProxyUser->text().trimmed();
    proxy.password    = editProxyPassword->text();

    if(proxy.displayName.isEmpty())
    {
        QMessageBox::warning(this, tr("Fehler"), tr("Anzeigename darf nicht leer sein!"));
        return;
    }

    if(!proxy.host.isEmpty() && proxy.port == 0)
    {
        QMessageBox::warning(this, tr("Fehler"), tr("Wenn Host angegeben ist, muss auch ein Port > 0 gesetzt sein!"));
        return;
    }

    QVector<gsIrcServerInfo> dummyServers;
    QVector<gsSocks5ProxyInfo> customProxies;
    loadCustomServers(dummyServers, customProxies);

    int customIdx = idx - predefinedProxies().size();
    customProxies[customIdx] = proxy;

    saveCustomServers(dummyServers, customProxies);

    refreshProxyCombo();
    comboProxies->setCurrentIndex(idx);

    setupProxyComboBox();
}

void chatIRC::on_btnDeleteProxy_clicked()
{
    int idx = comboProxies->currentIndex();
    if (idx < 0) return;
    if (idx < predefinedProxies().size()) return;

    if(QMessageBox::question(this, tr("Proxy löschen"), tr("Soll der Proxy \"%1\" wirklich gelöscht werden?").arg(comboProxies->currentText()),
                              QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes)
    {
        return;
    }

    QVector<gsIrcServerInfo> dummyServers;
    QVector<gsSocks5ProxyInfo> customProxies;
    loadCustomServers(dummyServers, customProxies);

    customProxies.removeAt(idx - predefinedProxies().size());
    saveCustomServers(dummyServers, customProxies);

    refreshProxyCombo();
    setupProxyComboBox();
}

void chatIRC::updateNickUserRealFromCurrentServer()
{
    int idx = ui->selectIRCServer->currentIndex();
    if(idx < 0) return;

    gsIrcServerInfo server = ui->selectIRCServer->itemData(idx).value<gsIrcServerInfo>();

    ui->lineNickName->setText(server.nick);
    ui->lineUserName->setText(server.user);
    ui->lineRealName->setText(server.real);
}

void chatIRC::appendDebugMessage(const QString& text)
{
    QString html = QString("<font color='red'>[%1] %2</font>")
    .arg(QTime::currentTime().toString())
    .arg(text);

    QTextDocument* document = ui->chatBrowser->document();
    if(document)
    {
        ui->chatBrowser->append(html);
    }
}

QString IrcMessageFormatter::formatMessage(IrcMessage* message)
{
    QString formatted;
    switch (message->type()) {
    case IrcMessage::Join:
        formatted = formatJoinMessage(static_cast<IrcJoinMessage*>(message));
        break;
    case IrcMessage::Mode:
        formatted = formatModeMessage(static_cast<IrcModeMessage*>(message));
        break;
    case IrcMessage::Names:
        formatted = formatNamesMessage(static_cast<IrcNamesMessage*>(message));
        break;
    case IrcMessage::Nick:
        formatted = formatNickMessage(static_cast<IrcNickMessage*>(message));
        break;
    case IrcMessage::Part:
        formatted = formatPartMessage(static_cast<IrcPartMessage*>(message));
        break;
    case IrcMessage::Private:
        formatted = formatPrivateMessage(static_cast<IrcPrivateMessage*>(message));
        break;
    case IrcMessage::Quit:
        formatted = formatQuitMessage(static_cast<IrcQuitMessage*>(message));
        break;
    default:
        break;
    }
    return formatMessage(formatted);
}

QString IrcMessageFormatter::formatMessage(const QString& message)
{
    if (!message.isEmpty()) {
        QString formatted = QObject::tr("[%1] %2").arg(QTime::currentTime().toString(), message);
        if (message.startsWith("!"))
            formatted = QObject::tr("<font color='gray'>%1</font>").arg(formatted);
        else if (message.startsWith("*"))
            formatted = QObject::tr("<font color='maroon'>%1</font>").arg(formatted);
        else if (message.startsWith("["))
            formatted = QObject::tr("<font color='indianred'>%1</font>").arg(formatted);
        return formatted;
    }
    return QString();
}

QString IrcMessageFormatter::formatJoinMessage(IrcJoinMessage* message)
{
    if (message->flags() & IrcMessage::Own)
        return QObject::tr("! You have joined %1 as %2").arg(message->channel(), message->nick());
    else
        return QObject::tr("! %1 has joined %2").arg(message->nick(), message->channel());
}

QString IrcMessageFormatter::formatModeMessage(IrcModeMessage* message)
{
    QString args = message->arguments().join(" ");
    if (message->isReply())
        return QObject::tr("! %1 mode is %2 %3").arg(message->target(), message->mode(), args);
    else
        return QObject::tr("! %1 sets mode %2 %3 %4").arg(message->nick(), message->target(), message->mode(), args);
}

QString IrcMessageFormatter::formatNamesMessage(IrcNamesMessage* message)
{
    return QObject::tr("! %1 has %2 users").arg(message->channel()).arg(message->names().count());
}

QString IrcMessageFormatter::formatNickMessage(IrcNickMessage* message)
{
    return QObject::tr("! %1 has changed nick to %2").arg(message->oldNick(), message->newNick());
}

QString IrcMessageFormatter::formatPartMessage(IrcPartMessage* message)
{
    if (message->reason().isEmpty())
        return QObject::tr("! %1 has left %2").arg(message->nick(), message->channel());
    else
        return QObject::tr("! %1 has left %2 (%3)").arg(message->nick(), message->channel(), message->reason());
}

QString IrcMessageFormatter::formatPrivateMessage(IrcPrivateMessage* message)
{
    const QString content = IrcTextFormat().toHtml(message->content());
    if (message->isAction())
        return QObject::tr("* %1 %2").arg(message->nick(), content);
    else
        return QObject::tr("&lt;%1&gt; %2").arg(message->nick(),content);
}

QString IrcMessageFormatter::formatQuitMessage(IrcQuitMessage* message)
{
    if (message->reason().isEmpty())
        return QObject::tr("! %1 has quit").arg(message->nick());
    else
        return QObject::tr("! %1 has quit (%2)").arg(message->nick(), message->reason());
}
