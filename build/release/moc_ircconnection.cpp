/****************************************************************************
** Meta object code from reading C++ file 'ircconnection.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcCore/ircconnection.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ircconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13IrcConnectionE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcConnection::qt_create_metaobjectdata<qt_meta_tag_ZN13IrcConnectionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcConnection",
        "connecting",
        "",
        "connected",
        "disconnected",
        "statusChanged",
        "IrcConnection::Status",
        "status",
        "socketError",
        "QAbstractSocket::SocketError",
        "error",
        "socketStateChanged",
        "QAbstractSocket::SocketState",
        "state",
        "secureError",
        "nickNameReserved",
        "QString*",
        "alternate",
        "nickNameRequired",
        "reserved",
        "channelKeyRequired",
        "channel",
        "key",
        "messageReceived",
        "IrcMessage*",
        "message",
        "accountMessageReceived",
        "IrcAccountMessage*",
        "awayMessageReceived",
        "IrcAwayMessage*",
        "batchMessageReceived",
        "IrcBatchMessage*",
        "capabilityMessageReceived",
        "IrcCapabilityMessage*",
        "errorMessageReceived",
        "IrcErrorMessage*",
        "hostChangeMessageReceived",
        "IrcHostChangeMessage*",
        "inviteMessageReceived",
        "IrcInviteMessage*",
        "joinMessageReceived",
        "IrcJoinMessage*",
        "kickMessageReceived",
        "IrcKickMessage*",
        "modeMessageReceived",
        "IrcModeMessage*",
        "motdMessageReceived",
        "IrcMotdMessage*",
        "namesMessageReceived",
        "IrcNamesMessage*",
        "nickMessageReceived",
        "IrcNickMessage*",
        "noticeMessageReceived",
        "IrcNoticeMessage*",
        "numericMessageReceived",
        "IrcNumericMessage*",
        "partMessageReceived",
        "IrcPartMessage*",
        "pingMessageReceived",
        "IrcPingMessage*",
        "pongMessageReceived",
        "IrcPongMessage*",
        "privateMessageReceived",
        "IrcPrivateMessage*",
        "quitMessageReceived",
        "IrcQuitMessage*",
        "topicMessageReceived",
        "IrcTopicMessage*",
        "whoisMessageReceived",
        "IrcWhoisMessage*",
        "whowasMessageReceived",
        "IrcWhowasMessage*",
        "whoReplyMessageReceived",
        "IrcWhoReplyMessage*",
        "hostChanged",
        "host",
        "portChanged",
        "port",
        "serversChanged",
        "servers",
        "userNameChanged",
        "name",
        "nickNameChanged",
        "realNameChanged",
        "passwordChanged",
        "password",
        "nickNamesChanged",
        "names",
        "displayNameChanged",
        "userDataChanged",
        "QVariantMap",
        "data",
        "reconnectDelayChanged",
        "seconds",
        "connectionCountChanged",
        "count",
        "enabledChanged",
        "enabled",
        "secureChanged",
        "secure",
        "saslMechanismChanged",
        "mechanism",
        "ctcpRepliesChanged",
        "replies",
        "destroyed",
        "IrcConnection*",
        "connection",
        "open",
        "close",
        "quit",
        "reason",
        "setEnabled",
        "setDisabled",
        "disabled",
        "sendCommand",
        "IrcCommand*",
        "command",
        "sendData",
        "sendRaw",
        "createCtcpReply",
        "request",
        "_irc_connected",
        "_irc_disconnected",
        "_irc_error",
        "_irc_state",
        "_irc_sslErrors",
        "_irc_reconnect",
        "_irc_readData",
        "_irc_filterDestroyed",
        "clone",
        "parent",
        "isValidServer",
        "server",
        "saveState",
        "version",
        "restoreState",
        "userName",
        "nickName",
        "realName",
        "nickNames",
        "displayName",
        "userData",
        "encoding",
        "Status",
        "active",
        "reconnectDelay",
        "connectionCount",
        "socket",
        "QAbstractSocket*",
        "secureSupported",
        "saslMechanism",
        "supportedSaslMechanisms",
        "ctcpReplies",
        "network",
        "IrcNetwork*",
        "protocol",
        "IrcProtocol*",
        "Inactive",
        "Waiting",
        "Connecting",
        "Connected",
        "Closing",
        "Closed",
        "Error"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'connecting'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'connected'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'disconnected'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'statusChanged'
        QtMocHelpers::SignalData<void(IrcConnection::Status)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'socketError'
        QtMocHelpers::SignalData<void(QAbstractSocket::SocketError)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Signal 'socketStateChanged'
        QtMocHelpers::SignalData<void(QAbstractSocket::SocketState)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 12, 13 },
        }}),
        // Signal 'secureError'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nickNameReserved'
        QtMocHelpers::SignalData<void(QString *)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 16, 17 },
        }}),
        // Signal 'nickNameRequired'
        QtMocHelpers::SignalData<void(const QString &, QString *)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 }, { 0x80000000 | 16, 17 },
        }}),
        // Signal 'channelKeyRequired'
        QtMocHelpers::SignalData<void(const QString &, QString *)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 21 }, { 0x80000000 | 16, 22 },
        }}),
        // Signal 'messageReceived'
        QtMocHelpers::SignalData<void(IrcMessage *)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 24, 25 },
        }}),
        // Signal 'accountMessageReceived'
        QtMocHelpers::SignalData<void(IrcAccountMessage *)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 27, 25 },
        }}),
        // Signal 'awayMessageReceived'
        QtMocHelpers::SignalData<void(IrcAwayMessage *)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 29, 25 },
        }}),
        // Signal 'batchMessageReceived'
        QtMocHelpers::SignalData<void(IrcBatchMessage *)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 25 },
        }}),
        // Signal 'capabilityMessageReceived'
        QtMocHelpers::SignalData<void(IrcCapabilityMessage *)>(32, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 33, 25 },
        }}),
        // Signal 'errorMessageReceived'
        QtMocHelpers::SignalData<void(IrcErrorMessage *)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 35, 25 },
        }}),
        // Signal 'hostChangeMessageReceived'
        QtMocHelpers::SignalData<void(IrcHostChangeMessage *)>(36, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 37, 25 },
        }}),
        // Signal 'inviteMessageReceived'
        QtMocHelpers::SignalData<void(IrcInviteMessage *)>(38, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 39, 25 },
        }}),
        // Signal 'joinMessageReceived'
        QtMocHelpers::SignalData<void(IrcJoinMessage *)>(40, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 41, 25 },
        }}),
        // Signal 'kickMessageReceived'
        QtMocHelpers::SignalData<void(IrcKickMessage *)>(42, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 43, 25 },
        }}),
        // Signal 'modeMessageReceived'
        QtMocHelpers::SignalData<void(IrcModeMessage *)>(44, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 45, 25 },
        }}),
        // Signal 'motdMessageReceived'
        QtMocHelpers::SignalData<void(IrcMotdMessage *)>(46, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 47, 25 },
        }}),
        // Signal 'namesMessageReceived'
        QtMocHelpers::SignalData<void(IrcNamesMessage *)>(48, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 49, 25 },
        }}),
        // Signal 'nickMessageReceived'
        QtMocHelpers::SignalData<void(IrcNickMessage *)>(50, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 51, 25 },
        }}),
        // Signal 'noticeMessageReceived'
        QtMocHelpers::SignalData<void(IrcNoticeMessage *)>(52, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 53, 25 },
        }}),
        // Signal 'numericMessageReceived'
        QtMocHelpers::SignalData<void(IrcNumericMessage *)>(54, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 55, 25 },
        }}),
        // Signal 'partMessageReceived'
        QtMocHelpers::SignalData<void(IrcPartMessage *)>(56, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 57, 25 },
        }}),
        // Signal 'pingMessageReceived'
        QtMocHelpers::SignalData<void(IrcPingMessage *)>(58, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 59, 25 },
        }}),
        // Signal 'pongMessageReceived'
        QtMocHelpers::SignalData<void(IrcPongMessage *)>(60, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 61, 25 },
        }}),
        // Signal 'privateMessageReceived'
        QtMocHelpers::SignalData<void(IrcPrivateMessage *)>(62, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 63, 25 },
        }}),
        // Signal 'quitMessageReceived'
        QtMocHelpers::SignalData<void(IrcQuitMessage *)>(64, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 65, 25 },
        }}),
        // Signal 'topicMessageReceived'
        QtMocHelpers::SignalData<void(IrcTopicMessage *)>(66, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 67, 25 },
        }}),
        // Signal 'whoisMessageReceived'
        QtMocHelpers::SignalData<void(IrcWhoisMessage *)>(68, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 69, 25 },
        }}),
        // Signal 'whowasMessageReceived'
        QtMocHelpers::SignalData<void(IrcWhowasMessage *)>(70, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 71, 25 },
        }}),
        // Signal 'whoReplyMessageReceived'
        QtMocHelpers::SignalData<void(IrcWhoReplyMessage *)>(72, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 73, 25 },
        }}),
        // Signal 'hostChanged'
        QtMocHelpers::SignalData<void(const QString &)>(74, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 75 },
        }}),
        // Signal 'portChanged'
        QtMocHelpers::SignalData<void(int)>(76, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 77 },
        }}),
        // Signal 'serversChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(78, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 79 },
        }}),
        // Signal 'userNameChanged'
        QtMocHelpers::SignalData<void(const QString &)>(80, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 81 },
        }}),
        // Signal 'nickNameChanged'
        QtMocHelpers::SignalData<void(const QString &)>(82, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 81 },
        }}),
        // Signal 'realNameChanged'
        QtMocHelpers::SignalData<void(const QString &)>(83, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 81 },
        }}),
        // Signal 'passwordChanged'
        QtMocHelpers::SignalData<void(const QString &)>(84, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 85 },
        }}),
        // Signal 'nickNamesChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(86, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 87 },
        }}),
        // Signal 'displayNameChanged'
        QtMocHelpers::SignalData<void(const QString &)>(88, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 81 },
        }}),
        // Signal 'userDataChanged'
        QtMocHelpers::SignalData<void(const QVariantMap &)>(89, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 90, 91 },
        }}),
        // Signal 'reconnectDelayChanged'
        QtMocHelpers::SignalData<void(int)>(92, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 93 },
        }}),
        // Signal 'connectionCountChanged'
        QtMocHelpers::SignalData<void(int)>(94, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 95 },
        }}),
        // Signal 'enabledChanged'
        QtMocHelpers::SignalData<void(bool)>(96, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 97 },
        }}),
        // Signal 'secureChanged'
        QtMocHelpers::SignalData<void(bool)>(98, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 99 },
        }}),
        // Signal 'saslMechanismChanged'
        QtMocHelpers::SignalData<void(const QString &)>(100, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 101 },
        }}),
        // Signal 'ctcpRepliesChanged'
        QtMocHelpers::SignalData<void(const QVariantMap &)>(102, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 90, 103 },
        }}),
        // Signal 'destroyed'
        QtMocHelpers::SignalData<void(IrcConnection *)>(104, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 105, 106 },
        }}),
        // Slot 'open'
        QtMocHelpers::SlotData<void()>(107, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'close'
        QtMocHelpers::SlotData<void()>(108, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'quit'
        QtMocHelpers::SlotData<void(const QString &)>(109, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 110 },
        }}),
        // Slot 'quit'
        QtMocHelpers::SlotData<void()>(109, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'setEnabled'
        QtMocHelpers::SlotData<void(bool)>(111, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 97 },
        }}),
        // Slot 'setEnabled'
        QtMocHelpers::SlotData<void()>(111, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'setDisabled'
        QtMocHelpers::SlotData<void(bool)>(112, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 113 },
        }}),
        // Slot 'setDisabled'
        QtMocHelpers::SlotData<void()>(112, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'sendCommand'
        QtMocHelpers::SlotData<bool(IrcCommand *)>(114, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 115, 116 },
        }}),
        // Slot 'sendData'
        QtMocHelpers::SlotData<bool(const QByteArray &)>(117, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QByteArray, 91 },
        }}),
        // Slot 'sendRaw'
        QtMocHelpers::SlotData<bool(const QString &)>(118, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 25 },
        }}),
        // Slot 'createCtcpReply'
        QtMocHelpers::SlotData<IrcCommand *(IrcPrivateMessage *) const>(119, 2, QMC::AccessProtected, 0x80000000 | 115, {{
            { 0x80000000 | 63, 120 },
        }}),
        // Slot '_irc_connected'
        QtMocHelpers::SlotData<void()>(121, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_irc_disconnected'
        QtMocHelpers::SlotData<void()>(122, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_irc_error'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketError)>(123, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 2 },
        }}),
        // Slot '_irc_state'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketState)>(124, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 12, 2 },
        }}),
        // Slot '_irc_sslErrors'
        QtMocHelpers::SlotData<void()>(125, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_irc_reconnect'
        QtMocHelpers::SlotData<void()>(126, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_irc_readData'
        QtMocHelpers::SlotData<void()>(127, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_irc_filterDestroyed'
        QtMocHelpers::SlotData<void(QObject *)>(128, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QObjectStar, 2 },
        }}),
        // Method 'clone'
        QtMocHelpers::MethodData<IrcConnection *(QObject *) const>(129, 2, QMC::AccessPublic, 0x80000000 | 105, {{
            { QMetaType::QObjectStar, 130 },
        }}),
        // Method 'clone'
        QtMocHelpers::MethodData<IrcConnection *() const>(129, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 105),
        // Method 'isValidServer'
        QtMocHelpers::MethodData<bool(const QString &)>(131, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 132 },
        }}),
        // Method 'saveState'
        QtMocHelpers::MethodData<QByteArray(int) const>(133, 2, QMC::AccessPublic, QMetaType::QByteArray, {{
            { QMetaType::Int, 134 },
        }}),
        // Method 'saveState'
        QtMocHelpers::MethodData<QByteArray() const>(133, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QByteArray),
        // Method 'restoreState'
        QtMocHelpers::MethodData<bool(const QByteArray &, int)>(135, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QByteArray, 13 }, { QMetaType::Int, 134 },
        }}),
        // Method 'restoreState'
        QtMocHelpers::MethodData<bool(const QByteArray &)>(135, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { QMetaType::QByteArray, 13 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'host'
        QtMocHelpers::PropertyData<QString>(75, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 35),
        // property 'port'
        QtMocHelpers::PropertyData<int>(77, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 36),
        // property 'servers'
        QtMocHelpers::PropertyData<QStringList>(79, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 37),
        // property 'userName'
        QtMocHelpers::PropertyData<QString>(136, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 38),
        // property 'nickName'
        QtMocHelpers::PropertyData<QString>(137, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 39),
        // property 'realName'
        QtMocHelpers::PropertyData<QString>(138, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 40),
        // property 'password'
        QtMocHelpers::PropertyData<QString>(85, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 41),
        // property 'nickNames'
        QtMocHelpers::PropertyData<QStringList>(139, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 42),
        // property 'displayName'
        QtMocHelpers::PropertyData<QString>(140, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 43),
        // property 'userData'
        QtMocHelpers::PropertyData<QVariantMap>(141, 0x80000000 | 90, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 44),
        // property 'encoding'
        QtMocHelpers::PropertyData<QByteArray>(142, QMetaType::QByteArray, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'status'
        QtMocHelpers::PropertyData<enum Status>(7, 0x80000000 | 143, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 3),
        // property 'active'
        QtMocHelpers::PropertyData<bool>(144, QMetaType::Bool, QMC::DefaultPropertyFlags, 3),
        // property 'connected'
        QtMocHelpers::PropertyData<bool>(3, QMetaType::Bool, QMC::DefaultPropertyFlags, 3),
        // property 'enabled'
        QtMocHelpers::PropertyData<bool>(97, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 47),
        // property 'reconnectDelay'
        QtMocHelpers::PropertyData<int>(145, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 45),
        // property 'connectionCount'
        QtMocHelpers::PropertyData<int>(146, QMetaType::Int, QMC::DefaultPropertyFlags, 46),
        // property 'socket'
        QtMocHelpers::PropertyData<QAbstractSocket*>(147, 0x80000000 | 148, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'secure'
        QtMocHelpers::PropertyData<bool>(99, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 48),
        // property 'secureSupported'
        QtMocHelpers::PropertyData<bool>(149, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'saslMechanism'
        QtMocHelpers::PropertyData<QString>(150, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 49),
        // property 'supportedSaslMechanisms'
        QtMocHelpers::PropertyData<QStringList>(151, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'ctcpReplies'
        QtMocHelpers::PropertyData<QVariantMap>(152, 0x80000000 | 90, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 50),
        // property 'network'
        QtMocHelpers::PropertyData<IrcNetwork*>(153, 0x80000000 | 154, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'protocol'
        QtMocHelpers::PropertyData<IrcProtocol*>(155, 0x80000000 | 156, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Status'
        QtMocHelpers::EnumData<enum Status>(143, 143, QMC::EnumFlags{}).add({
            {  157, Status::Inactive },
            {  158, Status::Waiting },
            {  159, Status::Connecting },
            {  160, Status::Connected },
            {  161, Status::Closing },
            {  162, Status::Closed },
            {  163, Status::Error },
        }),
    };
    return QtMocHelpers::metaObjectData<IrcConnection, qt_meta_tag_ZN13IrcConnectionE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject IrcConnection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13IrcConnectionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13IrcConnectionE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13IrcConnectionE_t>.metaTypes,
    nullptr
} };

void IrcConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcConnection *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->connecting(); break;
        case 1: _t->connected(); break;
        case 2: _t->disconnected(); break;
        case 3: _t->statusChanged((*reinterpret_cast<std::add_pointer_t<IrcConnection::Status>>(_a[1]))); break;
        case 4: _t->socketError((*reinterpret_cast<std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 5: _t->socketStateChanged((*reinterpret_cast<std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 6: _t->secureError(); break;
        case 7: _t->nickNameReserved((*reinterpret_cast<std::add_pointer_t<QString*>>(_a[1]))); break;
        case 8: _t->nickNameRequired((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString*>>(_a[2]))); break;
        case 9: _t->channelKeyRequired((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString*>>(_a[2]))); break;
        case 10: _t->messageReceived((*reinterpret_cast<std::add_pointer_t<IrcMessage*>>(_a[1]))); break;
        case 11: _t->accountMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcAccountMessage*>>(_a[1]))); break;
        case 12: _t->awayMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcAwayMessage*>>(_a[1]))); break;
        case 13: _t->batchMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcBatchMessage*>>(_a[1]))); break;
        case 14: _t->capabilityMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcCapabilityMessage*>>(_a[1]))); break;
        case 15: _t->errorMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcErrorMessage*>>(_a[1]))); break;
        case 16: _t->hostChangeMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcHostChangeMessage*>>(_a[1]))); break;
        case 17: _t->inviteMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcInviteMessage*>>(_a[1]))); break;
        case 18: _t->joinMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcJoinMessage*>>(_a[1]))); break;
        case 19: _t->kickMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcKickMessage*>>(_a[1]))); break;
        case 20: _t->modeMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcModeMessage*>>(_a[1]))); break;
        case 21: _t->motdMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcMotdMessage*>>(_a[1]))); break;
        case 22: _t->namesMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcNamesMessage*>>(_a[1]))); break;
        case 23: _t->nickMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcNickMessage*>>(_a[1]))); break;
        case 24: _t->noticeMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcNoticeMessage*>>(_a[1]))); break;
        case 25: _t->numericMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcNumericMessage*>>(_a[1]))); break;
        case 26: _t->partMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcPartMessage*>>(_a[1]))); break;
        case 27: _t->pingMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcPingMessage*>>(_a[1]))); break;
        case 28: _t->pongMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcPongMessage*>>(_a[1]))); break;
        case 29: _t->privateMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcPrivateMessage*>>(_a[1]))); break;
        case 30: _t->quitMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcQuitMessage*>>(_a[1]))); break;
        case 31: _t->topicMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcTopicMessage*>>(_a[1]))); break;
        case 32: _t->whoisMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcWhoisMessage*>>(_a[1]))); break;
        case 33: _t->whowasMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcWhowasMessage*>>(_a[1]))); break;
        case 34: _t->whoReplyMessageReceived((*reinterpret_cast<std::add_pointer_t<IrcWhoReplyMessage*>>(_a[1]))); break;
        case 35: _t->hostChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 36: _t->portChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 37: _t->serversChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 38: _t->userNameChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 39: _t->nickNameChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 40: _t->realNameChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 41: _t->passwordChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 42: _t->nickNamesChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 43: _t->displayNameChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 44: _t->userDataChanged((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 45: _t->reconnectDelayChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 46: _t->connectionCountChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 47: _t->enabledChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 48: _t->secureChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 49: _t->saslMechanismChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 50: _t->ctcpRepliesChanged((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 51: _t->destroyed((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); break;
        case 52: _t->open(); break;
        case 53: _t->close(); break;
        case 54: _t->quit((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 55: _t->quit(); break;
        case 56: _t->setEnabled((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 57: _t->setEnabled(); break;
        case 58: _t->setDisabled((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 59: _t->setDisabled(); break;
        case 60: { bool _r = _t->sendCommand((*reinterpret_cast<std::add_pointer_t<IrcCommand*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 61: { bool _r = _t->sendData((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 62: { bool _r = _t->sendRaw((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 63: { IrcCommand* _r = _t->createCtcpReply((*reinterpret_cast<std::add_pointer_t<IrcPrivateMessage*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 64: _t->d_func()->_irc_connected(); break;
        case 65: _t->d_func()->_irc_disconnected(); break;
        case 66: _t->d_func()->_irc_error((*reinterpret_cast<std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 67: _t->d_func()->_irc_state((*reinterpret_cast<std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 68: _t->d_func()->_irc_sslErrors(); break;
        case 69: _t->d_func()->_irc_reconnect(); break;
        case 70: _t->d_func()->_irc_readData(); break;
        case 71: _t->d_func()->_irc_filterDestroyed((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1]))); break;
        case 72: { IrcConnection* _r = _t->clone((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcConnection**>(_a[0]) = std::move(_r); }  break;
        case 73: { IrcConnection* _r = _t->clone();
            if (_a[0]) *reinterpret_cast<IrcConnection**>(_a[0]) = std::move(_r); }  break;
        case 74: { bool _r = _t->isValidServer((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 75: { QByteArray _r = _t->saveState((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 76: { QByteArray _r = _t->saveState();
            if (_a[0]) *reinterpret_cast<QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 77: { bool _r = _t->restoreState((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 78: { bool _r = _t->restoreState((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcMessage* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcAccountMessage* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcAwayMessage* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcBatchMessage* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcCapabilityMessage* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcErrorMessage* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcHostChangeMessage* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcInviteMessage* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcJoinMessage* >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcKickMessage* >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcModeMessage* >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcMotdMessage* >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcNamesMessage* >(); break;
            }
            break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcNickMessage* >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcNoticeMessage* >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcNumericMessage* >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcPartMessage* >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcPingMessage* >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcPongMessage* >(); break;
            }
            break;
        case 29:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcPrivateMessage* >(); break;
            }
            break;
        case 30:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcQuitMessage* >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcTopicMessage* >(); break;
            }
            break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcWhoisMessage* >(); break;
            }
            break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcWhowasMessage* >(); break;
            }
            break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcWhoReplyMessage* >(); break;
            }
            break;
        case 51:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcConnection* >(); break;
            }
            break;
        case 63:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcPrivateMessage* >(); break;
            }
            break;
        case 66:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 67:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)()>(_a, &IrcConnection::connecting, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)()>(_a, &IrcConnection::connected, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)()>(_a, &IrcConnection::disconnected, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcConnection::Status )>(_a, &IrcConnection::statusChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(QAbstractSocket::SocketError )>(_a, &IrcConnection::socketError, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(QAbstractSocket::SocketState )>(_a, &IrcConnection::socketStateChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)()>(_a, &IrcConnection::secureError, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(QString * )>(_a, &IrcConnection::nickNameReserved, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QString & , QString * )>(_a, &IrcConnection::nickNameRequired, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QString & , QString * )>(_a, &IrcConnection::channelKeyRequired, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcMessage * )>(_a, &IrcConnection::messageReceived, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcAccountMessage * )>(_a, &IrcConnection::accountMessageReceived, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcAwayMessage * )>(_a, &IrcConnection::awayMessageReceived, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcBatchMessage * )>(_a, &IrcConnection::batchMessageReceived, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcCapabilityMessage * )>(_a, &IrcConnection::capabilityMessageReceived, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcErrorMessage * )>(_a, &IrcConnection::errorMessageReceived, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcHostChangeMessage * )>(_a, &IrcConnection::hostChangeMessageReceived, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcInviteMessage * )>(_a, &IrcConnection::inviteMessageReceived, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcJoinMessage * )>(_a, &IrcConnection::joinMessageReceived, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcKickMessage * )>(_a, &IrcConnection::kickMessageReceived, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcModeMessage * )>(_a, &IrcConnection::modeMessageReceived, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcMotdMessage * )>(_a, &IrcConnection::motdMessageReceived, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcNamesMessage * )>(_a, &IrcConnection::namesMessageReceived, 22))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcNickMessage * )>(_a, &IrcConnection::nickMessageReceived, 23))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcNoticeMessage * )>(_a, &IrcConnection::noticeMessageReceived, 24))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcNumericMessage * )>(_a, &IrcConnection::numericMessageReceived, 25))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcPartMessage * )>(_a, &IrcConnection::partMessageReceived, 26))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcPingMessage * )>(_a, &IrcConnection::pingMessageReceived, 27))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcPongMessage * )>(_a, &IrcConnection::pongMessageReceived, 28))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcPrivateMessage * )>(_a, &IrcConnection::privateMessageReceived, 29))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcQuitMessage * )>(_a, &IrcConnection::quitMessageReceived, 30))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcTopicMessage * )>(_a, &IrcConnection::topicMessageReceived, 31))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcWhoisMessage * )>(_a, &IrcConnection::whoisMessageReceived, 32))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcWhowasMessage * )>(_a, &IrcConnection::whowasMessageReceived, 33))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcWhoReplyMessage * )>(_a, &IrcConnection::whoReplyMessageReceived, 34))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QString & )>(_a, &IrcConnection::hostChanged, 35))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(int )>(_a, &IrcConnection::portChanged, 36))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QStringList & )>(_a, &IrcConnection::serversChanged, 37))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QString & )>(_a, &IrcConnection::userNameChanged, 38))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QString & )>(_a, &IrcConnection::nickNameChanged, 39))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QString & )>(_a, &IrcConnection::realNameChanged, 40))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QString & )>(_a, &IrcConnection::passwordChanged, 41))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QStringList & )>(_a, &IrcConnection::nickNamesChanged, 42))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QString & )>(_a, &IrcConnection::displayNameChanged, 43))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QVariantMap & )>(_a, &IrcConnection::userDataChanged, 44))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(int )>(_a, &IrcConnection::reconnectDelayChanged, 45))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(int )>(_a, &IrcConnection::connectionCountChanged, 46))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(bool )>(_a, &IrcConnection::enabledChanged, 47))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(bool )>(_a, &IrcConnection::secureChanged, 48))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QString & )>(_a, &IrcConnection::saslMechanismChanged, 49))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(const QVariantMap & )>(_a, &IrcConnection::ctcpRepliesChanged, 50))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcConnection::*)(IrcConnection * )>(_a, &IrcConnection::destroyed, 51))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 23:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IrcNetwork* >(); break;
        case 17:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->host(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->port(); break;
        case 2: *reinterpret_cast<QStringList*>(_v) = _t->servers(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->userName(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->nickName(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->realName(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->password(); break;
        case 7: *reinterpret_cast<QStringList*>(_v) = _t->nickNames(); break;
        case 8: *reinterpret_cast<QString*>(_v) = _t->displayName(); break;
        case 9: *reinterpret_cast<QVariantMap*>(_v) = _t->userData(); break;
        case 10: *reinterpret_cast<QByteArray*>(_v) = _t->encoding(); break;
        case 11: *reinterpret_cast<enum Status*>(_v) = _t->status(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->isActive(); break;
        case 13: *reinterpret_cast<bool*>(_v) = _t->isConnected(); break;
        case 14: *reinterpret_cast<bool*>(_v) = _t->isEnabled(); break;
        case 15: *reinterpret_cast<int*>(_v) = _t->reconnectDelay(); break;
        case 16: *reinterpret_cast<int*>(_v) = _t->connectionCount(); break;
        case 17: *reinterpret_cast<QAbstractSocket**>(_v) = _t->socket(); break;
        case 18: *reinterpret_cast<bool*>(_v) = _t->isSecure(); break;
        case 19: *reinterpret_cast<bool*>(_v) = _t->isSecureSupported(); break;
        case 20: *reinterpret_cast<QString*>(_v) = _t->saslMechanism(); break;
        case 21: *reinterpret_cast<QStringList*>(_v) = _t->supportedSaslMechanisms(); break;
        case 22: *reinterpret_cast<QVariantMap*>(_v) = _t->ctcpReplies(); break;
        case 23: *reinterpret_cast<IrcNetwork**>(_v) = _t->network(); break;
        case 24: *reinterpret_cast<IrcProtocol**>(_v) = _t->protocol(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setHost(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setPort(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setServers(*reinterpret_cast<QStringList*>(_v)); break;
        case 3: _t->setUserName(*reinterpret_cast<QString*>(_v)); break;
        case 4: _t->setNickName(*reinterpret_cast<QString*>(_v)); break;
        case 5: _t->setRealName(*reinterpret_cast<QString*>(_v)); break;
        case 6: _t->setPassword(*reinterpret_cast<QString*>(_v)); break;
        case 7: _t->setNickNames(*reinterpret_cast<QStringList*>(_v)); break;
        case 8: _t->setDisplayName(*reinterpret_cast<QString*>(_v)); break;
        case 9: _t->setUserData(*reinterpret_cast<QVariantMap*>(_v)); break;
        case 10: _t->setEncoding(*reinterpret_cast<QByteArray*>(_v)); break;
        case 14: _t->setEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 15: _t->setReconnectDelay(*reinterpret_cast<int*>(_v)); break;
        case 17: _t->setSocket(*reinterpret_cast<QAbstractSocket**>(_v)); break;
        case 18: _t->setSecure(*reinterpret_cast<bool*>(_v)); break;
        case 20: _t->setSaslMechanism(*reinterpret_cast<QString*>(_v)); break;
        case 22: _t->setCtcpReplies(*reinterpret_cast<QVariantMap*>(_v)); break;
        case 24: _t->setProtocol(*reinterpret_cast<IrcProtocol**>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *IrcConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13IrcConnectionE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IrcConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 79)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 79;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 79)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 79;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void IrcConnection::connecting()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void IrcConnection::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void IrcConnection::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void IrcConnection::statusChanged(IrcConnection::Status _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void IrcConnection::socketError(QAbstractSocket::SocketError _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void IrcConnection::socketStateChanged(QAbstractSocket::SocketState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void IrcConnection::secureError()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void IrcConnection::nickNameReserved(QString * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void IrcConnection::nickNameRequired(const QString & _t1, QString * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1, _t2);
}

// SIGNAL 9
void IrcConnection::channelKeyRequired(const QString & _t1, QString * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1, _t2);
}

// SIGNAL 10
void IrcConnection::messageReceived(IrcMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void IrcConnection::accountMessageReceived(IrcAccountMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void IrcConnection::awayMessageReceived(IrcAwayMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}

// SIGNAL 13
void IrcConnection::batchMessageReceived(IrcBatchMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}

// SIGNAL 14
void IrcConnection::capabilityMessageReceived(IrcCapabilityMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1);
}

// SIGNAL 15
void IrcConnection::errorMessageReceived(IrcErrorMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1);
}

// SIGNAL 16
void IrcConnection::hostChangeMessageReceived(IrcHostChangeMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 16, nullptr, _t1);
}

// SIGNAL 17
void IrcConnection::inviteMessageReceived(IrcInviteMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1);
}

// SIGNAL 18
void IrcConnection::joinMessageReceived(IrcJoinMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 18, nullptr, _t1);
}

// SIGNAL 19
void IrcConnection::kickMessageReceived(IrcKickMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 19, nullptr, _t1);
}

// SIGNAL 20
void IrcConnection::modeMessageReceived(IrcModeMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 20, nullptr, _t1);
}

// SIGNAL 21
void IrcConnection::motdMessageReceived(IrcMotdMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 21, nullptr, _t1);
}

// SIGNAL 22
void IrcConnection::namesMessageReceived(IrcNamesMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 22, nullptr, _t1);
}

// SIGNAL 23
void IrcConnection::nickMessageReceived(IrcNickMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 23, nullptr, _t1);
}

// SIGNAL 24
void IrcConnection::noticeMessageReceived(IrcNoticeMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 24, nullptr, _t1);
}

// SIGNAL 25
void IrcConnection::numericMessageReceived(IrcNumericMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 25, nullptr, _t1);
}

// SIGNAL 26
void IrcConnection::partMessageReceived(IrcPartMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 26, nullptr, _t1);
}

// SIGNAL 27
void IrcConnection::pingMessageReceived(IrcPingMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 27, nullptr, _t1);
}

// SIGNAL 28
void IrcConnection::pongMessageReceived(IrcPongMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 28, nullptr, _t1);
}

// SIGNAL 29
void IrcConnection::privateMessageReceived(IrcPrivateMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 29, nullptr, _t1);
}

// SIGNAL 30
void IrcConnection::quitMessageReceived(IrcQuitMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 30, nullptr, _t1);
}

// SIGNAL 31
void IrcConnection::topicMessageReceived(IrcTopicMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 31, nullptr, _t1);
}

// SIGNAL 32
void IrcConnection::whoisMessageReceived(IrcWhoisMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 32, nullptr, _t1);
}

// SIGNAL 33
void IrcConnection::whowasMessageReceived(IrcWhowasMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 33, nullptr, _t1);
}

// SIGNAL 34
void IrcConnection::whoReplyMessageReceived(IrcWhoReplyMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 34, nullptr, _t1);
}

// SIGNAL 35
void IrcConnection::hostChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 35, nullptr, _t1);
}

// SIGNAL 36
void IrcConnection::portChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 36, nullptr, _t1);
}

// SIGNAL 37
void IrcConnection::serversChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 37, nullptr, _t1);
}

// SIGNAL 38
void IrcConnection::userNameChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 38, nullptr, _t1);
}

// SIGNAL 39
void IrcConnection::nickNameChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 39, nullptr, _t1);
}

// SIGNAL 40
void IrcConnection::realNameChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 40, nullptr, _t1);
}

// SIGNAL 41
void IrcConnection::passwordChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 41, nullptr, _t1);
}

// SIGNAL 42
void IrcConnection::nickNamesChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 42, nullptr, _t1);
}

// SIGNAL 43
void IrcConnection::displayNameChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 43, nullptr, _t1);
}

// SIGNAL 44
void IrcConnection::userDataChanged(const QVariantMap & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 44, nullptr, _t1);
}

// SIGNAL 45
void IrcConnection::reconnectDelayChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 45, nullptr, _t1);
}

// SIGNAL 46
void IrcConnection::connectionCountChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 46, nullptr, _t1);
}

// SIGNAL 47
void IrcConnection::enabledChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 47, nullptr, _t1);
}

// SIGNAL 48
void IrcConnection::secureChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 48, nullptr, _t1);
}

// SIGNAL 49
void IrcConnection::saslMechanismChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 49, nullptr, _t1);
}

// SIGNAL 50
void IrcConnection::ctcpRepliesChanged(const QVariantMap & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 50, nullptr, _t1);
}

// SIGNAL 51
void IrcConnection::destroyed(IrcConnection * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 51, nullptr, _t1);
}
QT_WARNING_POP
