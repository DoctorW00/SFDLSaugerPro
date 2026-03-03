/****************************************************************************
** Meta object code from reading C++ file 'irccommand.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcCore/irccommand.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'irccommand.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10IrcCommandE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcCommand::qt_create_metaobjectdata<qt_meta_tag_ZN10IrcCommandE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcCommand",
        "toMessage",
        "IrcMessage*",
        "",
        "prefix",
        "IrcConnection*",
        "connection",
        "createAdmin",
        "IrcCommand*",
        "server",
        "createAway",
        "reason",
        "createCapability",
        "subCommand",
        "capability",
        "capabilities",
        "createCtcpAction",
        "target",
        "action",
        "createCtcpReply",
        "reply",
        "createCtcpRequest",
        "request",
        "createInfo",
        "createInvite",
        "user",
        "channel",
        "createJoin",
        "key",
        "channels",
        "keys",
        "createKick",
        "createKnock",
        "message",
        "createList",
        "createMessage",
        "createMode",
        "mode",
        "arg",
        "createMonitor",
        "command",
        "targets",
        "createMotd",
        "createNames",
        "createNick",
        "nick",
        "createNotice",
        "notice",
        "createPart",
        "createPing",
        "argument",
        "createPong",
        "createQuit",
        "createQuote",
        "raw",
        "parameters",
        "createStats",
        "query",
        "createTime",
        "createTopic",
        "topic",
        "createTrace",
        "createUsers",
        "createVersion",
        "createWho",
        "mask",
        "operators",
        "createWhois",
        "createWhowas",
        "count",
        "network",
        "IrcNetwork*",
        "encoding",
        "type",
        "Type",
        "Admin",
        "Away",
        "Capability",
        "CtcpAction",
        "CtcpReply",
        "CtcpRequest",
        "Custom",
        "Info",
        "Invite",
        "Join",
        "Kick",
        "Knock",
        "List",
        "Message",
        "Mode",
        "Motd",
        "Names",
        "Nick",
        "Notice",
        "Part",
        "Ping",
        "Pong",
        "Quit",
        "Quote",
        "Stats",
        "Time",
        "Topic",
        "Trace",
        "Users",
        "Version",
        "Who",
        "Whois",
        "Whowas",
        "Monitor"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toMessage'
        QtMocHelpers::MethodData<IrcMessage *(const QString &, IrcConnection *) const>(1, 3, QMC::AccessPublic, 0x80000000 | 2, {{
            { QMetaType::QString, 4 }, { 0x80000000 | 5, 6 },
        }}),
        // Method 'createAdmin'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(7, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 9 },
        }}),
        // Method 'createAdmin'
        QtMocHelpers::MethodData<IrcCommand *()>(7, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8),
        // Method 'createAway'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(10, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 11 },
        }}),
        // Method 'createAway'
        QtMocHelpers::MethodData<IrcCommand *()>(10, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8),
        // Method 'createCapability'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(12, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 13 }, { QMetaType::QString, 14 },
        }}),
        // Method 'createCapability'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QStringList &)>(12, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 13 }, { QMetaType::QStringList, 15 },
        }}),
        // Method 'createCapability'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(12, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 13 },
        }}),
        // Method 'createCtcpAction'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(16, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 17 }, { QMetaType::QString, 18 },
        }}),
        // Method 'createCtcpReply'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(19, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 17 }, { QMetaType::QString, 20 },
        }}),
        // Method 'createCtcpRequest'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(21, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 17 }, { QMetaType::QString, 22 },
        }}),
        // Method 'createInfo'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(23, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 9 },
        }}),
        // Method 'createInfo'
        QtMocHelpers::MethodData<IrcCommand *()>(23, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8),
        // Method 'createInvite'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(24, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 25 }, { QMetaType::QString, 26 },
        }}),
        // Method 'createJoin'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(27, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 26 }, { QMetaType::QString, 28 },
        }}),
        // Method 'createJoin'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(27, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 26 },
        }}),
        // Method 'createJoin'
        QtMocHelpers::MethodData<IrcCommand *(const QStringList &, const QStringList &)>(27, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QStringList, 29 }, { QMetaType::QStringList, 30 },
        }}),
        // Method 'createJoin'
        QtMocHelpers::MethodData<IrcCommand *(const QStringList &)>(27, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QStringList, 29 },
        }}),
        // Method 'createKick'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &, const QString &)>(31, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 26 }, { QMetaType::QString, 25 }, { QMetaType::QString, 11 },
        }}),
        // Method 'createKick'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(31, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 26 }, { QMetaType::QString, 25 },
        }}),
        // Method 'createKnock'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(32, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 26 }, { QMetaType::QString, 33 },
        }}),
        // Method 'createKnock'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(32, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 26 },
        }}),
        // Method 'createList'
        QtMocHelpers::MethodData<IrcCommand *(const QStringList &, const QString &)>(34, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QStringList, 29 }, { QMetaType::QString, 9 },
        }}),
        // Method 'createList'
        QtMocHelpers::MethodData<IrcCommand *(const QStringList &)>(34, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QStringList, 29 },
        }}),
        // Method 'createList'
        QtMocHelpers::MethodData<IrcCommand *()>(34, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8),
        // Method 'createMessage'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(35, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 17 }, { QMetaType::QString, 33 },
        }}),
        // Method 'createMode'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &, const QString &)>(36, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 17 }, { QMetaType::QString, 37 }, { QMetaType::QString, 38 },
        }}),
        // Method 'createMode'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(36, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 17 }, { QMetaType::QString, 37 },
        }}),
        // Method 'createMode'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(36, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 17 },
        }}),
        // Method 'createMonitor'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(39, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 40 }, { QMetaType::QString, 17 },
        }}),
        // Method 'createMonitor'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(39, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 40 },
        }}),
        // Method 'createMonitor'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QStringList &)>(39, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 40 }, { QMetaType::QStringList, 41 },
        }}),
        // Method 'createMotd'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(42, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 9 },
        }}),
        // Method 'createMotd'
        QtMocHelpers::MethodData<IrcCommand *()>(42, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8),
        // Method 'createNames'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(43, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 26 }, { QMetaType::QString, 9 },
        }}),
        // Method 'createNames'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(43, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 26 },
        }}),
        // Method 'createNames'
        QtMocHelpers::MethodData<IrcCommand *()>(43, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8),
        // Method 'createNames'
        QtMocHelpers::MethodData<IrcCommand *(const QStringList &, const QString &)>(43, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QStringList, 29 }, { QMetaType::QString, 9 },
        }}),
        // Method 'createNames'
        QtMocHelpers::MethodData<IrcCommand *(const QStringList &)>(43, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QStringList, 29 },
        }}),
        // Method 'createNick'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(44, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 45 },
        }}),
        // Method 'createNotice'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(46, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 17 }, { QMetaType::QString, 47 },
        }}),
        // Method 'createPart'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(48, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 26 }, { QMetaType::QString, 11 },
        }}),
        // Method 'createPart'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(48, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 26 },
        }}),
        // Method 'createPart'
        QtMocHelpers::MethodData<IrcCommand *(const QStringList &, const QString &)>(48, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QStringList, 29 }, { QMetaType::QString, 11 },
        }}),
        // Method 'createPart'
        QtMocHelpers::MethodData<IrcCommand *(const QStringList &)>(48, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QStringList, 29 },
        }}),
        // Method 'createPing'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(49, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 50 },
        }}),
        // Method 'createPong'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(51, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 50 },
        }}),
        // Method 'createQuit'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(52, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 11 },
        }}),
        // Method 'createQuit'
        QtMocHelpers::MethodData<IrcCommand *()>(52, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8),
        // Method 'createQuote'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(53, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 54 },
        }}),
        // Method 'createQuote'
        QtMocHelpers::MethodData<IrcCommand *(const QStringList &)>(53, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QStringList, 55 },
        }}),
        // Method 'createStats'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(56, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 57 }, { QMetaType::QString, 9 },
        }}),
        // Method 'createStats'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(56, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 57 },
        }}),
        // Method 'createTime'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(58, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 9 },
        }}),
        // Method 'createTime'
        QtMocHelpers::MethodData<IrcCommand *()>(58, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8),
        // Method 'createTopic'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, const QString &)>(59, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 26 }, { QMetaType::QString, 60 },
        }}),
        // Method 'createTopic'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(59, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 26 },
        }}),
        // Method 'createTrace'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(61, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 17 },
        }}),
        // Method 'createTrace'
        QtMocHelpers::MethodData<IrcCommand *()>(61, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8),
        // Method 'createUsers'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(62, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 9 },
        }}),
        // Method 'createUsers'
        QtMocHelpers::MethodData<IrcCommand *()>(62, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8),
        // Method 'createVersion'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(63, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 25 },
        }}),
        // Method 'createVersion'
        QtMocHelpers::MethodData<IrcCommand *()>(63, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8),
        // Method 'createWho'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, bool)>(64, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 65 }, { QMetaType::Bool, 66 },
        }}),
        // Method 'createWho'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(64, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 65 },
        }}),
        // Method 'createWhois'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(67, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 25 },
        }}),
        // Method 'createWhowas'
        QtMocHelpers::MethodData<IrcCommand *(const QString &, int)>(68, 3, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 25 }, { QMetaType::Int, 69 },
        }}),
        // Method 'createWhowas'
        QtMocHelpers::MethodData<IrcCommand *(const QString &)>(68, 3, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 8, {{
            { QMetaType::QString, 25 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'connection'
        QtMocHelpers::PropertyData<IrcConnection*>(6, 0x80000000 | 5, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'network'
        QtMocHelpers::PropertyData<IrcNetwork*>(70, 0x80000000 | 71, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'parameters'
        QtMocHelpers::PropertyData<QStringList>(55, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'encoding'
        QtMocHelpers::PropertyData<QByteArray>(72, QMetaType::QByteArray, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'type'
        QtMocHelpers::PropertyData<enum Type>(73, 0x80000000 | 74, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Type'
        QtMocHelpers::EnumData<enum Type>(74, 74, QMC::EnumFlags{}).add({
            {   75, Type::Admin },
            {   76, Type::Away },
            {   77, Type::Capability },
            {   78, Type::CtcpAction },
            {   79, Type::CtcpReply },
            {   80, Type::CtcpRequest },
            {   81, Type::Custom },
            {   82, Type::Info },
            {   83, Type::Invite },
            {   84, Type::Join },
            {   85, Type::Kick },
            {   86, Type::Knock },
            {   87, Type::List },
            {   88, Type::Message },
            {   89, Type::Mode },
            {   90, Type::Motd },
            {   91, Type::Names },
            {   92, Type::Nick },
            {   93, Type::Notice },
            {   94, Type::Part },
            {   95, Type::Ping },
            {   96, Type::Pong },
            {   97, Type::Quit },
            {   98, Type::Quote },
            {   99, Type::Stats },
            {  100, Type::Time },
            {  101, Type::Topic },
            {  102, Type::Trace },
            {  103, Type::Users },
            {  104, Type::Version },
            {  105, Type::Who },
            {  106, Type::Whois },
            {  107, Type::Whowas },
            {  108, Type::Monitor },
        }),
    };
    return QtMocHelpers::metaObjectData<IrcCommand, qt_meta_tag_ZN10IrcCommandE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject IrcCommand::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcCommandE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcCommandE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10IrcCommandE_t>.metaTypes,
    nullptr
} };

void IrcCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcCommand *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { IrcMessage* _r = _t->toMessage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcMessage**>(_a[0]) = std::move(_r); }  break;
        case 1: { IrcCommand* _r = _t->createAdmin((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 2: { IrcCommand* _r = _t->createAdmin();
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 3: { IrcCommand* _r = _t->createAway((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 4: { IrcCommand* _r = _t->createAway();
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 5: { IrcCommand* _r = _t->createCapability((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 6: { IrcCommand* _r = _t->createCapability((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 7: { IrcCommand* _r = _t->createCapability((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 8: { IrcCommand* _r = _t->createCtcpAction((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 9: { IrcCommand* _r = _t->createCtcpReply((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 10: { IrcCommand* _r = _t->createCtcpRequest((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 11: { IrcCommand* _r = _t->createInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 12: { IrcCommand* _r = _t->createInfo();
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 13: { IrcCommand* _r = _t->createInvite((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 14: { IrcCommand* _r = _t->createJoin((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 15: { IrcCommand* _r = _t->createJoin((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 16: { IrcCommand* _r = _t->createJoin((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 17: { IrcCommand* _r = _t->createJoin((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 18: { IrcCommand* _r = _t->createKick((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 19: { IrcCommand* _r = _t->createKick((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 20: { IrcCommand* _r = _t->createKnock((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 21: { IrcCommand* _r = _t->createKnock((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 22: { IrcCommand* _r = _t->createList((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 23: { IrcCommand* _r = _t->createList((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 24: { IrcCommand* _r = _t->createList();
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 25: { IrcCommand* _r = _t->createMessage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 26: { IrcCommand* _r = _t->createMode((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 27: { IrcCommand* _r = _t->createMode((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 28: { IrcCommand* _r = _t->createMode((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 29: { IrcCommand* _r = _t->createMonitor((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 30: { IrcCommand* _r = _t->createMonitor((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 31: { IrcCommand* _r = _t->createMonitor((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 32: { IrcCommand* _r = _t->createMotd((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 33: { IrcCommand* _r = _t->createMotd();
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 34: { IrcCommand* _r = _t->createNames((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 35: { IrcCommand* _r = _t->createNames((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 36: { IrcCommand* _r = _t->createNames();
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 37: { IrcCommand* _r = _t->createNames((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 38: { IrcCommand* _r = _t->createNames((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 39: { IrcCommand* _r = _t->createNick((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 40: { IrcCommand* _r = _t->createNotice((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 41: { IrcCommand* _r = _t->createPart((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 42: { IrcCommand* _r = _t->createPart((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 43: { IrcCommand* _r = _t->createPart((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 44: { IrcCommand* _r = _t->createPart((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 45: { IrcCommand* _r = _t->createPing((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 46: { IrcCommand* _r = _t->createPong((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 47: { IrcCommand* _r = _t->createQuit((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 48: { IrcCommand* _r = _t->createQuit();
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 49: { IrcCommand* _r = _t->createQuote((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 50: { IrcCommand* _r = _t->createQuote((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 51: { IrcCommand* _r = _t->createStats((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 52: { IrcCommand* _r = _t->createStats((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 53: { IrcCommand* _r = _t->createTime((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 54: { IrcCommand* _r = _t->createTime();
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 55: { IrcCommand* _r = _t->createTopic((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 56: { IrcCommand* _r = _t->createTopic((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 57: { IrcCommand* _r = _t->createTrace((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 58: { IrcCommand* _r = _t->createTrace();
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 59: { IrcCommand* _r = _t->createUsers((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 60: { IrcCommand* _r = _t->createUsers();
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 61: { IrcCommand* _r = _t->createVersion((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 62: { IrcCommand* _r = _t->createVersion();
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 63: { IrcCommand* _r = _t->createWho((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 64: { IrcCommand* _r = _t->createWho((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 65: { IrcCommand* _r = _t->createWhois((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 66: { IrcCommand* _r = _t->createWhowas((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        case 67: { IrcCommand* _r = _t->createWhowas((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<IrcConnection**>(_v) = _t->connection(); break;
        case 1: *reinterpret_cast<IrcNetwork**>(_v) = _t->network(); break;
        case 2: *reinterpret_cast<QStringList*>(_v) = _t->parameters(); break;
        case 3: *reinterpret_cast<QByteArray*>(_v) = _t->encoding(); break;
        case 4: *reinterpret_cast<enum Type*>(_v) = _t->type(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setParameters(*reinterpret_cast<QStringList*>(_v)); break;
        case 3: _t->setEncoding(*reinterpret_cast<QByteArray*>(_v)); break;
        case 4: _t->setType(*reinterpret_cast<enum Type*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *IrcCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcCommandE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IrcCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 68)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 68;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 68)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 68;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
