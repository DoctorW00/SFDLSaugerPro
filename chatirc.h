#ifndef CHATIRC_H
#define CHATIRC_H

#pragma once
#include <QMetaType>

struct IrcServerInfo
{
    QString displayName;
    QString hostname;
    int     port = 6667;
    bool    ssl  = false;
    QString nick = "Nick";
    QString user = "User";
    QString real = "RealName";
    QString password = "";
    QString defaultChannel = "";
    bool operator==(const IrcServerInfo& other) const
    {
        return displayName == other.displayName &&
               hostname    == other.hostname &&
               port        == other.port &&
               ssl         == other.ssl;
    }
};
Q_DECLARE_METATYPE(IrcServerInfo)

struct Socks5ProxyInfo
{
    QString  displayName;
    QString  host;
    quint16  port = 0;
    QString  user;
    QString  password;

    bool operator==(const Socks5ProxyInfo& other) const
    {
        return displayName == other.displayName &&
               host        == other.host &&
               port        == other.port &&
               user        == other.user &&
               password    == other.password;
    }
    bool operator!=(const Socks5ProxyInfo& other) const { return !(*this == other); }
};
Q_DECLARE_METATYPE(Socks5ProxyInfo)

#include <QDialog>

#include <Irc>
#include <IrcUser>
#include <IrcBuffer>
#include <IrcCommand>
#include <IrcMessage>
#include <IrcUserModel>
#include <IrcCompleter>
#include <IrcConnection>
#include <IrcBufferModel>
#include <IrcCommandParser>
#include <IrcChannel>
#include <QRandomGenerator>
#include <QTextDocument>
#include <QHash>
#include <QListView>

#include <QString>
#include <QVector>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QNetworkProxy>

#include <QSettings>

class IrcMessageFormatter
{
public:
    static QString formatMessage(IrcMessage* message);
    static QString formatMessage(const QString& message);

private:
    static QString formatJoinMessage(IrcJoinMessage* message);
    static QString formatModeMessage(IrcModeMessage* message);
    static QString formatNamesMessage(IrcNamesMessage* message);
    static QString formatNickMessage(IrcNickMessage* message);
    static QString formatPartMessage(IrcPartMessage* message);
    static QString formatPrivateMessage(IrcPrivateMessage* message);
    static QString formatQuitMessage(IrcQuitMessage* message);
};

namespace Ui { class chatIRC; }

class chatIRC : public QDialog
{
    Q_OBJECT

public:
    explicit chatIRC(QWidget *parent = nullptr);
    ~chatIRC();
    static void saveCustomServers(const QVector<IrcServerInfo>& servers, const QVector<Socks5ProxyInfo>& proxies);
    static void loadCustomServers(QVector<IrcServerInfo>& servers,QVector<Socks5ProxyInfo>& proxies);
    static QVector<IrcServerInfo> getAllServers();
    static QVector<Socks5ProxyInfo> getAllProxies();

private slots:
    void loadIRCLayout();
    void createParser();
    void createConnection();
    void createCompleter();
    void createUserList();
    void createBufferList();
    void onConnected();
    void onConnecting();
    void onDisconnected();
    void onTextEdited();
    void onTextEntered();
    void onCompletion();
    void onCompleted(const QString& text, int cursor);
    void onBufferAdded(IrcBuffer* buffer);
    void onBufferRemoved(IrcBuffer* buffer);
    void onBufferActivated(const QModelIndex& index);
    void onUserActivated(const QModelIndex& index);
    void receiveMessage(IrcMessage* message);
    void on_inputEdit_returnPressed();
    void on_buttonChatSend_pressed();
    void disableChatUi();
    void enableChatUi();
    void connectButtonHandling();
    void on_ircConnectButton_pressed();
    void setupServerComboBox();
    void on_selectIRCServer_currentIndexChanged(int index);
    void setupProxyComboBox();
    void on_selectIRCProxy_currentIndexChanged(int index);
    void appendDebugMessage(const QString& text);

private:
    static const QVector<IrcServerInfo>& predefinedServers();
    static const QVector<Socks5ProxyInfo>& predefinedProxies();

    Ui::chatIRC *ui;
    IrcCompleter *completer;
    IrcCommandParser *parser;
    IrcConnection *connection;
    QTcpSocket *proxySocket;
    IrcBufferModel *bufferModel;
    QHash<IrcBuffer*, IrcUserModel*> userModels;
    QHash<IrcBuffer*, QTextDocument*> documents;

    // irc con vars
    QString ircServer_DisplayName;
    QString ircServer_Host;
    int ircServer_Port;
    QString ircServer_Room;
    QString ircServer_UserName;
    QString ircServer_NickName;
    QString ircServer_RealName;
    bool ircServer_UseSSL = false;
    QString ircServer_Password; // sasl plain pass

    // socks5 proxy
    bool ircServer_UseProxy = false;
    QString ircServer_ProxyName;
    QString ircServer_ProxyHost;
    int ircServer_ProxyPort;
    QString ircServer_ProxyUser;
    QString ircServer_ProxyPass;

    // irc server setup
    QDialog* setupDialog = nullptr;
    QComboBox* comboServers;
    QComboBox* comboProxies;
    QLineEdit *editDisplayName, *editHostname, *editNick, *editUser, *editReal, *editPass, *editDefaultChannel;
    QSpinBox  *spinPort;
    QCheckBox *checkSsl;
    QLineEdit *editProxyDisplayName, *editProxyHost, *editProxyUser, *editProxyPassword;
    QSpinBox  *spinProxyPort;
    QPushButton *btnAddServer, *btnUpdateServer, *btnDeleteServer;
    QPushButton *btnAddProxy,  *btnUpdateProxy,  *btnDeleteProxy;

    void createSetupDialog();
    void refreshServerCombo();
    void refreshProxyCombo();
    void loadCurrentServerIntoFields();
    void loadCurrentProxyIntoFields();

    void on_btnAddServer_clicked();
    void on_btnUpdateServer_clicked();
    void on_btnDeleteServer_clicked();
    void on_btnAddProxy_clicked();
    void on_btnUpdateProxy_clicked();
    void on_btnDeleteProxy_clicked();

    void updateNickUserRealFromCurrentServer();
};

#endif // CHATIRC_H
