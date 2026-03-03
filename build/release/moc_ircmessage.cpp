/****************************************************************************
** Meta object code from reading C++ file 'ircmessage.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcCore/ircmessage.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ircmessage.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10IrcMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcMessage::qt_create_metaobjectdata<qt_meta_tag_ZN10IrcMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcMessage",
        "testFlag",
        "",
        "Flag",
        "flag",
        "setFlag",
        "on",
        "toData",
        "fromData",
        "IrcMessage*",
        "data",
        "IrcConnection*",
        "connection",
        "fromParameters",
        "prefix",
        "command",
        "parameters",
        "clone",
        "parent",
        "network",
        "IrcNetwork*",
        "type",
        "Type",
        "own",
        "implicit",
        "flags",
        "Flags",
        "valid",
        "nick",
        "ident",
        "host",
        "account",
        "timeStamp",
        "tags",
        "QVariantMap",
        "Unknown",
        "Capability",
        "Error",
        "Invite",
        "Join",
        "Kick",
        "Mode",
        "Motd",
        "Names",
        "Nick",
        "Notice",
        "Numeric",
        "Part",
        "Ping",
        "Pong",
        "Private",
        "Quit",
        "Topic",
        "WhoReply",
        "Account",
        "Away",
        "Whois",
        "Whowas",
        "HostChange",
        "Batch",
        "None",
        "Own",
        "Identified",
        "Unidentified",
        "Playback",
        "Implicit"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'testFlag'
        QtMocHelpers::MethodData<bool(enum Flag) const>(1, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Method 'setFlag'
        QtMocHelpers::MethodData<void(enum Flag, bool)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Bool, 6 },
        }}),
        // Method 'setFlag'
        QtMocHelpers::MethodData<void(enum Flag)>(5, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Method 'toData'
        QtMocHelpers::MethodData<QByteArray() const>(7, 2, QMC::AccessPublic, QMetaType::QByteArray),
        // Method 'fromData'
        QtMocHelpers::MethodData<IrcMessage *(const QByteArray &, IrcConnection *)>(8, 2, QMC::AccessPublic, 0x80000000 | 9, {{
            { QMetaType::QByteArray, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Method 'fromParameters'
        QtMocHelpers::MethodData<IrcMessage *(const QString &, const QString &, const QStringList &, IrcConnection *)>(13, 2, QMC::AccessPublic, 0x80000000 | 9, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 15 }, { QMetaType::QStringList, 16 }, { 0x80000000 | 11, 12 },
        }}),
        // Method 'clone'
        QtMocHelpers::MethodData<IrcMessage *(QObject *) const>(17, 2, QMC::AccessPublic, 0x80000000 | 9, {{
            { QMetaType::QObjectStar, 18 },
        }}),
        // Method 'clone'
        QtMocHelpers::MethodData<IrcMessage *() const>(17, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 9),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'connection'
        QtMocHelpers::PropertyData<IrcConnection*>(12, 0x80000000 | 11, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'network'
        QtMocHelpers::PropertyData<IrcNetwork*>(19, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'type'
        QtMocHelpers::PropertyData<enum Type>(21, 0x80000000 | 22, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'own'
        QtMocHelpers::PropertyData<bool>(23, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'implicit'
        QtMocHelpers::PropertyData<bool>(24, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'flags'
        QtMocHelpers::PropertyData<Flags>(25, 0x80000000 | 26, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'valid'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'command'
        QtMocHelpers::PropertyData<QString>(15, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'prefix'
        QtMocHelpers::PropertyData<QString>(14, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'nick'
        QtMocHelpers::PropertyData<QString>(28, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'ident'
        QtMocHelpers::PropertyData<QString>(29, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'host'
        QtMocHelpers::PropertyData<QString>(30, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'account'
        QtMocHelpers::PropertyData<QString>(31, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'parameters'
        QtMocHelpers::PropertyData<QStringList>(16, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'timeStamp'
        QtMocHelpers::PropertyData<QDateTime>(32, QMetaType::QDateTime, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'tags'
        QtMocHelpers::PropertyData<QVariantMap>(33, 0x80000000 | 34, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Type'
        QtMocHelpers::EnumData<enum Type>(22, 22, QMC::EnumFlags{}).add({
            {   35, Type::Unknown },
            {   36, Type::Capability },
            {   37, Type::Error },
            {   38, Type::Invite },
            {   39, Type::Join },
            {   40, Type::Kick },
            {   41, Type::Mode },
            {   42, Type::Motd },
            {   43, Type::Names },
            {   44, Type::Nick },
            {   45, Type::Notice },
            {   46, Type::Numeric },
            {   47, Type::Part },
            {   48, Type::Ping },
            {   49, Type::Pong },
            {   50, Type::Private },
            {   51, Type::Quit },
            {   52, Type::Topic },
            {   53, Type::WhoReply },
            {   54, Type::Account },
            {   55, Type::Away },
            {   56, Type::Whois },
            {   57, Type::Whowas },
            {   58, Type::HostChange },
            {   59, Type::Batch },
        }),
        // enum 'Flag'
        QtMocHelpers::EnumData<enum Flag>(3, 3, QMC::EnumFlags{}).add({
            {   60, Flag::None },
            {   61, Flag::Own },
            {   62, Flag::Identified },
            {   63, Flag::Unidentified },
            {   64, Flag::Playback },
            {   65, Flag::Implicit },
        }),
        // flag 'Flags'
        QtMocHelpers::EnumData<Flags>(26, 3, QMC::EnumIsFlag).add({
            {   60, Flag::None },
            {   61, Flag::Own },
            {   62, Flag::Identified },
            {   63, Flag::Unidentified },
            {   64, Flag::Playback },
            {   65, Flag::Implicit },
        }),
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(2, QMC::AccessPublic, {{
            { 0x80000000 | 11, 12 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcMessage, qt_meta_tag_ZN10IrcMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10IrcMessageE_t>.metaTypes,
    nullptr
} };

void IrcMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcMessage *_r = new IrcMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = _t->testFlag((*reinterpret_cast<std::add_pointer_t<enum Flag>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->setFlag((*reinterpret_cast<std::add_pointer_t<enum Flag>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2]))); break;
        case 2: _t->setFlag((*reinterpret_cast<std::add_pointer_t<enum Flag>>(_a[1]))); break;
        case 3: { QByteArray _r = _t->toData();
            if (_a[0]) *reinterpret_cast<QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 4: { IrcMessage* _r = _t->fromData((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[2])));
            if (_a[0]) *reinterpret_cast<IrcMessage**>(_a[0]) = std::move(_r); }  break;
        case 5: { IrcMessage* _r = _t->fromParameters((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[4])));
            if (_a[0]) *reinterpret_cast<IrcMessage**>(_a[0]) = std::move(_r); }  break;
        case 6: { IrcMessage* _r = _t->clone((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcMessage**>(_a[0]) = std::move(_r); }  break;
        case 7: { IrcMessage* _r = _t->clone();
            if (_a[0]) *reinterpret_cast<IrcMessage**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<IrcConnection**>(_v) = _t->connection(); break;
        case 1: *reinterpret_cast<IrcNetwork**>(_v) = _t->network(); break;
        case 2: *reinterpret_cast<enum Type*>(_v) = _t->type(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isOwn(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isImplicit(); break;
        case 5: QtMocHelpers::assignFlags<Flags>(_v, _t->flags()); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->isValid(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->command(); break;
        case 8: *reinterpret_cast<QString*>(_v) = _t->prefix(); break;
        case 9: *reinterpret_cast<QString*>(_v) = _t->nick(); break;
        case 10: *reinterpret_cast<QString*>(_v) = _t->ident(); break;
        case 11: *reinterpret_cast<QString*>(_v) = _t->host(); break;
        case 12: *reinterpret_cast<QString*>(_v) = _t->account(); break;
        case 13: *reinterpret_cast<QStringList*>(_v) = _t->parameters(); break;
        case 14: *reinterpret_cast<QDateTime*>(_v) = _t->timeStamp(); break;
        case 15: *reinterpret_cast<QVariantMap*>(_v) = _t->tags(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 8: _t->setPrefix(*reinterpret_cast<QString*>(_v)); break;
        case 13: _t->setParameters(*reinterpret_cast<QStringList*>(_v)); break;
        case 14: _t->setTimeStamp(*reinterpret_cast<QDateTime*>(_v)); break;
        case 15: _t->setTags(*reinterpret_cast<QVariantMap*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *IrcMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcMessageE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IrcMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN17IrcAccountMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcAccountMessage::qt_create_metaobjectdata<qt_meta_tag_ZN17IrcAccountMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcAccountMessage",
        "",
        "IrcConnection*",
        "connection",
        "account"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'account'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcAccountMessage, qt_meta_tag_ZN17IrcAccountMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcAccountMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17IrcAccountMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17IrcAccountMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17IrcAccountMessageE_t>.metaTypes,
    nullptr
} };

void IrcAccountMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcAccountMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcAccountMessage *_r = new IrcAccountMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcAccountMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->account(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcAccountMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcAccountMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17IrcAccountMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcAccountMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN14IrcAwayMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcAwayMessage::qt_create_metaobjectdata<qt_meta_tag_ZN14IrcAwayMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcAwayMessage",
        "",
        "IrcConnection*",
        "connection",
        "content",
        "reply",
        "away"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'content'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'reply'
        QtMocHelpers::PropertyData<bool>(5, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'away'
        QtMocHelpers::PropertyData<bool>(6, QMetaType::Bool, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcAwayMessage, qt_meta_tag_ZN14IrcAwayMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcAwayMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcAwayMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcAwayMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14IrcAwayMessageE_t>.metaTypes,
    nullptr
} };

void IrcAwayMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcAwayMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcAwayMessage *_r = new IrcAwayMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcAwayMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->content(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isReply(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isAway(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcAwayMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcAwayMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcAwayMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcAwayMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN15IrcBatchMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcBatchMessage::qt_create_metaobjectdata<qt_meta_tag_ZN15IrcBatchMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcBatchMessage",
        "",
        "IrcConnection*",
        "connection",
        "tag",
        "batch",
        "messages",
        "QList<IrcMessage*>"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'tag'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'batch'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'messages'
        QtMocHelpers::PropertyData<QList<IrcMessage*>>(6, 0x80000000 | 7, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcBatchMessage, qt_meta_tag_ZN15IrcBatchMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcBatchMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcBatchMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcBatchMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15IrcBatchMessageE_t>.metaTypes,
    nullptr
} };

void IrcBatchMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcBatchMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcBatchMessage *_r = new IrcBatchMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcBatchMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<IrcMessage*> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->tag(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->batch(); break;
        case 2: *reinterpret_cast<QList<IrcMessage*>*>(_v) = _t->messages(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcBatchMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcBatchMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcBatchMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcBatchMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN20IrcCapabilityMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcCapabilityMessage::qt_create_metaobjectdata<qt_meta_tag_ZN20IrcCapabilityMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcCapabilityMessage",
        "",
        "IrcConnection*",
        "connection",
        "subCommand",
        "capabilities"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'subCommand'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'capabilities'
        QtMocHelpers::PropertyData<QStringList>(5, QMetaType::QStringList, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcCapabilityMessage, qt_meta_tag_ZN20IrcCapabilityMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcCapabilityMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20IrcCapabilityMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20IrcCapabilityMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20IrcCapabilityMessageE_t>.metaTypes,
    nullptr
} };

void IrcCapabilityMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcCapabilityMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcCapabilityMessage *_r = new IrcCapabilityMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcCapabilityMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->subCommand(); break;
        case 1: *reinterpret_cast<QStringList*>(_v) = _t->capabilities(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcCapabilityMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcCapabilityMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20IrcCapabilityMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcCapabilityMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN15IrcErrorMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcErrorMessage::qt_create_metaobjectdata<qt_meta_tag_ZN15IrcErrorMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcErrorMessage",
        "",
        "IrcConnection*",
        "connection",
        "error"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'error'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcErrorMessage, qt_meta_tag_ZN15IrcErrorMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcErrorMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcErrorMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcErrorMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15IrcErrorMessageE_t>.metaTypes,
    nullptr
} };

void IrcErrorMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcErrorMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcErrorMessage *_r = new IrcErrorMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcErrorMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->error(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcErrorMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcErrorMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcErrorMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcErrorMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN20IrcHostChangeMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcHostChangeMessage::qt_create_metaobjectdata<qt_meta_tag_ZN20IrcHostChangeMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcHostChangeMessage",
        "",
        "IrcConnection*",
        "connection",
        "user",
        "host"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'user'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'host'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcHostChangeMessage, qt_meta_tag_ZN20IrcHostChangeMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcHostChangeMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20IrcHostChangeMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20IrcHostChangeMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20IrcHostChangeMessageE_t>.metaTypes,
    nullptr
} };

void IrcHostChangeMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcHostChangeMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcHostChangeMessage *_r = new IrcHostChangeMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcHostChangeMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->user(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->host(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcHostChangeMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcHostChangeMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20IrcHostChangeMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcHostChangeMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN16IrcInviteMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcInviteMessage::qt_create_metaobjectdata<qt_meta_tag_ZN16IrcInviteMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcInviteMessage",
        "",
        "IrcConnection*",
        "connection",
        "user",
        "channel",
        "reply"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'user'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'channel'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'reply'
        QtMocHelpers::PropertyData<bool>(6, QMetaType::Bool, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcInviteMessage, qt_meta_tag_ZN16IrcInviteMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcInviteMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16IrcInviteMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16IrcInviteMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16IrcInviteMessageE_t>.metaTypes,
    nullptr
} };

void IrcInviteMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcInviteMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcInviteMessage *_r = new IrcInviteMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcInviteMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->user(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->channel(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isReply(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcInviteMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcInviteMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16IrcInviteMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcInviteMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN14IrcJoinMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcJoinMessage::qt_create_metaobjectdata<qt_meta_tag_ZN14IrcJoinMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcJoinMessage",
        "",
        "IrcConnection*",
        "connection",
        "channel",
        "account",
        "realName"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'channel'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'account'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'realName'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcJoinMessage, qt_meta_tag_ZN14IrcJoinMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcJoinMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcJoinMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcJoinMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14IrcJoinMessageE_t>.metaTypes,
    nullptr
} };

void IrcJoinMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcJoinMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcJoinMessage *_r = new IrcJoinMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcJoinMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->channel(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->account(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->realName(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcJoinMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcJoinMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcJoinMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcJoinMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN14IrcKickMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcKickMessage::qt_create_metaobjectdata<qt_meta_tag_ZN14IrcKickMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcKickMessage",
        "",
        "IrcConnection*",
        "connection",
        "channel",
        "user",
        "reason"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'channel'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'user'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'reason'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcKickMessage, qt_meta_tag_ZN14IrcKickMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcKickMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcKickMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcKickMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14IrcKickMessageE_t>.metaTypes,
    nullptr
} };

void IrcKickMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcKickMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcKickMessage *_r = new IrcKickMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcKickMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->channel(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->user(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->reason(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcKickMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcKickMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcKickMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcKickMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN14IrcModeMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcModeMessage::qt_create_metaobjectdata<qt_meta_tag_ZN14IrcModeMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcModeMessage",
        "",
        "IrcConnection*",
        "connection",
        "target",
        "mode",
        "argument",
        "arguments",
        "reply",
        "kind",
        "Kind",
        "Channel",
        "User"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'target'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'mode'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'argument'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'arguments'
        QtMocHelpers::PropertyData<QStringList>(7, QMetaType::QStringList, QMC::DefaultPropertyFlags),
        // property 'reply'
        QtMocHelpers::PropertyData<bool>(8, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'kind'
        QtMocHelpers::PropertyData<enum Kind>(9, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Kind'
        QtMocHelpers::EnumData<enum Kind>(10, 10, QMC::EnumFlags{}).add({
            {   11, Kind::Channel },
            {   12, Kind::User },
        }),
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcModeMessage, qt_meta_tag_ZN14IrcModeMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcModeMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcModeMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcModeMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14IrcModeMessageE_t>.metaTypes,
    nullptr
} };

void IrcModeMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcModeMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcModeMessage *_r = new IrcModeMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcModeMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->target(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->mode(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->argument(); break;
        case 3: *reinterpret_cast<QStringList*>(_v) = _t->arguments(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isReply(); break;
        case 5: *reinterpret_cast<enum Kind*>(_v) = _t->kind(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcModeMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcModeMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcModeMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcModeMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN14IrcMotdMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcMotdMessage::qt_create_metaobjectdata<qt_meta_tag_ZN14IrcMotdMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcMotdMessage",
        "",
        "IrcConnection*",
        "connection",
        "lines"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'lines'
        QtMocHelpers::PropertyData<QStringList>(4, QMetaType::QStringList, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcMotdMessage, qt_meta_tag_ZN14IrcMotdMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcMotdMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcMotdMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcMotdMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14IrcMotdMessageE_t>.metaTypes,
    nullptr
} };

void IrcMotdMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcMotdMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcMotdMessage *_r = new IrcMotdMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcMotdMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QStringList*>(_v) = _t->lines(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcMotdMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcMotdMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcMotdMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcMotdMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN15IrcNamesMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcNamesMessage::qt_create_metaobjectdata<qt_meta_tag_ZN15IrcNamesMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcNamesMessage",
        "",
        "IrcConnection*",
        "connection",
        "channel",
        "names"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'channel'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'names'
        QtMocHelpers::PropertyData<QStringList>(5, QMetaType::QStringList, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcNamesMessage, qt_meta_tag_ZN15IrcNamesMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcNamesMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcNamesMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcNamesMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15IrcNamesMessageE_t>.metaTypes,
    nullptr
} };

void IrcNamesMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcNamesMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcNamesMessage *_r = new IrcNamesMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcNamesMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->channel(); break;
        case 1: *reinterpret_cast<QStringList*>(_v) = _t->names(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcNamesMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcNamesMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcNamesMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcNamesMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN14IrcNickMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcNickMessage::qt_create_metaobjectdata<qt_meta_tag_ZN14IrcNickMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcNickMessage",
        "",
        "IrcConnection*",
        "connection",
        "oldNick",
        "newNick"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'oldNick'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'newNick'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcNickMessage, qt_meta_tag_ZN14IrcNickMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcNickMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcNickMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcNickMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14IrcNickMessageE_t>.metaTypes,
    nullptr
} };

void IrcNickMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcNickMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcNickMessage *_r = new IrcNickMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcNickMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->oldNick(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->newNick(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcNickMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcNickMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcNickMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcNickMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN16IrcNoticeMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcNoticeMessage::qt_create_metaobjectdata<qt_meta_tag_ZN16IrcNoticeMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcNoticeMessage",
        "",
        "IrcConnection*",
        "connection",
        "target",
        "content",
        "statusPrefix",
        "private",
        "reply"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'target'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'content'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'statusPrefix'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'private'
        QtMocHelpers::PropertyData<bool>(7, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'reply'
        QtMocHelpers::PropertyData<bool>(8, QMetaType::Bool, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcNoticeMessage, qt_meta_tag_ZN16IrcNoticeMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcNoticeMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16IrcNoticeMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16IrcNoticeMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16IrcNoticeMessageE_t>.metaTypes,
    nullptr
} };

void IrcNoticeMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcNoticeMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcNoticeMessage *_r = new IrcNoticeMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcNoticeMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->target(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->content(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->statusPrefix(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isPrivate(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isReply(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcNoticeMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcNoticeMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16IrcNoticeMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcNoticeMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN17IrcNumericMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcNumericMessage::qt_create_metaobjectdata<qt_meta_tag_ZN17IrcNumericMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcNumericMessage",
        "",
        "IrcConnection*",
        "connection",
        "code",
        "composed"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'code'
        QtMocHelpers::PropertyData<int>(4, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'composed'
        QtMocHelpers::PropertyData<bool>(5, QMetaType::Bool, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcNumericMessage, qt_meta_tag_ZN17IrcNumericMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcNumericMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17IrcNumericMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17IrcNumericMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17IrcNumericMessageE_t>.metaTypes,
    nullptr
} };

void IrcNumericMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcNumericMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcNumericMessage *_r = new IrcNumericMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcNumericMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->code(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isComposed(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcNumericMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcNumericMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17IrcNumericMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcNumericMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN14IrcPartMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcPartMessage::qt_create_metaobjectdata<qt_meta_tag_ZN14IrcPartMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcPartMessage",
        "",
        "IrcConnection*",
        "connection",
        "channel",
        "reason"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'channel'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'reason'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcPartMessage, qt_meta_tag_ZN14IrcPartMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcPartMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcPartMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcPartMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14IrcPartMessageE_t>.metaTypes,
    nullptr
} };

void IrcPartMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcPartMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcPartMessage *_r = new IrcPartMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcPartMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->channel(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->reason(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcPartMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcPartMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcPartMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcPartMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN14IrcPingMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcPingMessage::qt_create_metaobjectdata<qt_meta_tag_ZN14IrcPingMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcPingMessage",
        "",
        "IrcConnection*",
        "connection",
        "argument"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'argument'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcPingMessage, qt_meta_tag_ZN14IrcPingMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcPingMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcPingMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcPingMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14IrcPingMessageE_t>.metaTypes,
    nullptr
} };

void IrcPingMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcPingMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcPingMessage *_r = new IrcPingMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcPingMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->argument(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcPingMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcPingMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcPingMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcPingMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN14IrcPongMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcPongMessage::qt_create_metaobjectdata<qt_meta_tag_ZN14IrcPongMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcPongMessage",
        "",
        "IrcConnection*",
        "connection",
        "argument"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'argument'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcPongMessage, qt_meta_tag_ZN14IrcPongMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcPongMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcPongMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcPongMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14IrcPongMessageE_t>.metaTypes,
    nullptr
} };

void IrcPongMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcPongMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcPongMessage *_r = new IrcPongMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcPongMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->argument(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcPongMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcPongMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcPongMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcPongMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN17IrcPrivateMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcPrivateMessage::qt_create_metaobjectdata<qt_meta_tag_ZN17IrcPrivateMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcPrivateMessage",
        "",
        "IrcConnection*",
        "connection",
        "target",
        "content",
        "statusPrefix",
        "private",
        "action",
        "request"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'target'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'content'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'statusPrefix'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'private'
        QtMocHelpers::PropertyData<bool>(7, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'action'
        QtMocHelpers::PropertyData<bool>(8, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'request'
        QtMocHelpers::PropertyData<bool>(9, QMetaType::Bool, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcPrivateMessage, qt_meta_tag_ZN17IrcPrivateMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcPrivateMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17IrcPrivateMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17IrcPrivateMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17IrcPrivateMessageE_t>.metaTypes,
    nullptr
} };

void IrcPrivateMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcPrivateMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcPrivateMessage *_r = new IrcPrivateMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcPrivateMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->target(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->content(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->statusPrefix(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isPrivate(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isAction(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->isRequest(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcPrivateMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcPrivateMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17IrcPrivateMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcPrivateMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN14IrcQuitMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcQuitMessage::qt_create_metaobjectdata<qt_meta_tag_ZN14IrcQuitMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcQuitMessage",
        "",
        "IrcConnection*",
        "connection",
        "reason"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'reason'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcQuitMessage, qt_meta_tag_ZN14IrcQuitMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcQuitMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcQuitMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcQuitMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14IrcQuitMessageE_t>.metaTypes,
    nullptr
} };

void IrcQuitMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcQuitMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcQuitMessage *_r = new IrcQuitMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcQuitMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->reason(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcQuitMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcQuitMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcQuitMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcQuitMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN15IrcTopicMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcTopicMessage::qt_create_metaobjectdata<qt_meta_tag_ZN15IrcTopicMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcTopicMessage",
        "",
        "IrcConnection*",
        "connection",
        "channel",
        "topic",
        "reply"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'channel'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'topic'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'reply'
        QtMocHelpers::PropertyData<bool>(6, QMetaType::Bool, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcTopicMessage, qt_meta_tag_ZN15IrcTopicMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcTopicMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcTopicMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcTopicMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15IrcTopicMessageE_t>.metaTypes,
    nullptr
} };

void IrcTopicMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcTopicMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcTopicMessage *_r = new IrcTopicMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcTopicMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->channel(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->topic(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isReply(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcTopicMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcTopicMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcTopicMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcTopicMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN15IrcWhoisMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcWhoisMessage::qt_create_metaobjectdata<qt_meta_tag_ZN15IrcWhoisMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcWhoisMessage",
        "",
        "IrcConnection*",
        "connection",
        "realName",
        "server",
        "info",
        "account",
        "address",
        "since",
        "idle",
        "secure",
        "channels",
        "awayReason"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'realName'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'server'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'info'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'account'
        QtMocHelpers::PropertyData<QString>(7, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'address'
        QtMocHelpers::PropertyData<QString>(8, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'since'
        QtMocHelpers::PropertyData<QDateTime>(9, QMetaType::QDateTime, QMC::DefaultPropertyFlags),
        // property 'idle'
        QtMocHelpers::PropertyData<int>(10, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'secure'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'channels'
        QtMocHelpers::PropertyData<QStringList>(12, QMetaType::QStringList, QMC::DefaultPropertyFlags),
        // property 'awayReason'
        QtMocHelpers::PropertyData<QString>(13, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcWhoisMessage, qt_meta_tag_ZN15IrcWhoisMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcWhoisMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcWhoisMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcWhoisMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15IrcWhoisMessageE_t>.metaTypes,
    nullptr
} };

void IrcWhoisMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcWhoisMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcWhoisMessage *_r = new IrcWhoisMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcWhoisMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->realName(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->server(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->info(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->account(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->address(); break;
        case 5: *reinterpret_cast<QDateTime*>(_v) = _t->since(); break;
        case 6: *reinterpret_cast<int*>(_v) = _t->idle(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->isSecure(); break;
        case 8: *reinterpret_cast<QStringList*>(_v) = _t->channels(); break;
        case 9: *reinterpret_cast<QString*>(_v) = _t->awayReason(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcWhoisMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcWhoisMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15IrcWhoisMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcWhoisMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN16IrcWhowasMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcWhowasMessage::qt_create_metaobjectdata<qt_meta_tag_ZN16IrcWhowasMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcWhowasMessage",
        "",
        "IrcConnection*",
        "connection",
        "realName",
        "server",
        "info",
        "account"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'realName'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'server'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'info'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'account'
        QtMocHelpers::PropertyData<QString>(7, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcWhowasMessage, qt_meta_tag_ZN16IrcWhowasMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcWhowasMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16IrcWhowasMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16IrcWhowasMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16IrcWhowasMessageE_t>.metaTypes,
    nullptr
} };

void IrcWhowasMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcWhowasMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcWhowasMessage *_r = new IrcWhowasMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcWhowasMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->realName(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->server(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->info(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->account(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcWhowasMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcWhowasMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16IrcWhowasMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcWhowasMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN18IrcWhoReplyMessageE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcWhoReplyMessage::qt_create_metaobjectdata<qt_meta_tag_ZN18IrcWhoReplyMessageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcWhoReplyMessage",
        "",
        "IrcConnection*",
        "connection",
        "mask",
        "server",
        "away",
        "servOp",
        "realName"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'mask'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'server'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'away'
        QtMocHelpers::PropertyData<bool>(6, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'servOp'
        QtMocHelpers::PropertyData<bool>(7, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'realName'
        QtMocHelpers::PropertyData<QString>(8, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(IrcConnection *)>(1, QMC::AccessPublic, {{
            { 0x80000000 | 2, 3 },
        }}),
    };
    return QtMocHelpers::metaObjectData<IrcWhoReplyMessage, qt_meta_tag_ZN18IrcWhoReplyMessageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcWhoReplyMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcMessage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18IrcWhoReplyMessageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18IrcWhoReplyMessageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18IrcWhoReplyMessageE_t>.metaTypes,
    nullptr
} };

void IrcWhoReplyMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcWhoReplyMessage *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcWhoReplyMessage *_r = new IrcWhoReplyMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcWhoReplyMessage((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->mask(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->server(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isAway(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isServOp(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->realName(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcWhoReplyMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcWhoReplyMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18IrcWhoReplyMessageE_t>.strings))
        return static_cast<void*>(this);
    return IrcMessage::qt_metacast(_clname);
}

int IrcWhoReplyMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcMessage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
