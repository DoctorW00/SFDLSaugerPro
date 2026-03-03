/****************************************************************************
** Meta object code from reading C++ file 'ircbuffer.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcModel/ircbuffer.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ircbuffer.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9IrcBufferE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcBuffer::qt_create_metaobjectdata<qt_meta_tag_ZN9IrcBufferE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcBuffer",
        "titleChanged",
        "",
        "title",
        "nameChanged",
        "name",
        "prefixChanged",
        "messageReceived",
        "IrcMessage*",
        "message",
        "destroyed",
        "IrcBuffer*",
        "buffer",
        "activeChanged",
        "active",
        "stickyChanged",
        "sticky",
        "persistentChanged",
        "persistent",
        "userDataChanged",
        "QVariantMap",
        "data",
        "setName",
        "setPrefix",
        "prefix",
        "receiveMessage",
        "close",
        "reason",
        "toChannel",
        "IrcChannel*",
        "sendCommand",
        "IrcCommand*",
        "command",
        "parent",
        "connection",
        "IrcConnection*",
        "network",
        "IrcNetwork*",
        "model",
        "IrcBufferModel*",
        "channel",
        "userData",
        "Type",
        "Basic",
        "Channel",
        "Custom"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'titleChanged'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'nameChanged'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Signal 'prefixChanged'
        QtMocHelpers::SignalData<void(const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Signal 'messageReceived'
        QtMocHelpers::SignalData<void(IrcMessage *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'destroyed'
        QtMocHelpers::SignalData<void(IrcBuffer *)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Signal 'activeChanged'
        QtMocHelpers::SignalData<void(bool)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 14 },
        }}),
        // Signal 'stickyChanged'
        QtMocHelpers::SignalData<void(bool)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 16 },
        }}),
        // Signal 'persistentChanged'
        QtMocHelpers::SignalData<void(bool)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 18 },
        }}),
        // Signal 'userDataChanged'
        QtMocHelpers::SignalData<void(const QVariantMap &)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 20, 21 },
        }}),
        // Slot 'setName'
        QtMocHelpers::SlotData<void(const QString &)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Slot 'setPrefix'
        QtMocHelpers::SlotData<void(const QString &)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 24 },
        }}),
        // Slot 'receiveMessage'
        QtMocHelpers::SlotData<void(IrcMessage *)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Slot 'close'
        QtMocHelpers::SlotData<void(const QString &)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 27 },
        }}),
        // Slot 'close'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Method 'toChannel'
        QtMocHelpers::MethodData<IrcChannel *()>(28, 2, QMC::AccessPublic, 0x80000000 | 29),
        // Method 'sendCommand'
        QtMocHelpers::MethodData<bool(IrcCommand *)>(30, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 31, 32 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'title'
        QtMocHelpers::PropertyData<QString>(3, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'prefix'
        QtMocHelpers::PropertyData<QString>(24, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'connection'
        QtMocHelpers::PropertyData<IrcConnection*>(34, 0x80000000 | 35, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'network'
        QtMocHelpers::PropertyData<IrcNetwork*>(36, 0x80000000 | 37, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'model'
        QtMocHelpers::PropertyData<IrcBufferModel*>(38, 0x80000000 | 39, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'active'
        QtMocHelpers::PropertyData<bool>(14, QMetaType::Bool, QMC::DefaultPropertyFlags, 5),
        // property 'channel'
        QtMocHelpers::PropertyData<bool>(40, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'sticky'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'persistent'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'userData'
        QtMocHelpers::PropertyData<QVariantMap>(41, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 8),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Type'
        QtMocHelpers::EnumData<enum Type>(42, 42, QMC::EnumFlags{}).add({
            {   43, Type::Basic },
            {   44, Type::Channel },
            {   45, Type::Custom },
        }),
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(QObject *)>(2, QMC::AccessPublic, {{
            { QMetaType::QObjectStar, 33 },
        }}),
        QtMocHelpers::ConstructorData<Constructor()>(2, QMC::AccessPublic | QMC::MethodCloned),
    };
    return QtMocHelpers::metaObjectData<IrcBuffer, qt_meta_tag_ZN9IrcBufferE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcBuffer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9IrcBufferE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9IrcBufferE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9IrcBufferE_t>.metaTypes,
    nullptr
} };

void IrcBuffer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcBuffer *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcBuffer *_r = new IrcBuffer((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 1: { IrcBuffer *_r = new IrcBuffer();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcBuffer((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1]))); } break;
        case 1: { new (_a[0]) IrcBuffer(); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->titleChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->nameChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->prefixChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->messageReceived((*reinterpret_cast<std::add_pointer_t<IrcMessage*>>(_a[1]))); break;
        case 4: _t->destroyed((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 5: _t->activeChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->stickyChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->persistentChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->userDataChanged((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 9: _t->setName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->setPrefix((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->receiveMessage((*reinterpret_cast<std::add_pointer_t<IrcMessage*>>(_a[1]))); break;
        case 12: _t->close((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->close(); break;
        case 14: { IrcChannel* _r = _t->toChannel();
            if (_a[0]) *reinterpret_cast<IrcChannel**>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->sendCommand((*reinterpret_cast<std::add_pointer_t<IrcCommand*>>(_a[1])));
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcBuffer* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IrcBuffer::*)(const QString & )>(_a, &IrcBuffer::titleChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBuffer::*)(const QString & )>(_a, &IrcBuffer::nameChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBuffer::*)(const QString & )>(_a, &IrcBuffer::prefixChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBuffer::*)(IrcMessage * )>(_a, &IrcBuffer::messageReceived, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBuffer::*)(IrcBuffer * )>(_a, &IrcBuffer::destroyed, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBuffer::*)(bool )>(_a, &IrcBuffer::activeChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBuffer::*)(bool )>(_a, &IrcBuffer::stickyChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBuffer::*)(bool )>(_a, &IrcBuffer::persistentChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBuffer::*)(const QVariantMap & )>(_a, &IrcBuffer::userDataChanged, 8))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->title(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->name(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->prefix(); break;
        case 3: *reinterpret_cast<IrcConnection**>(_v) = _t->connection(); break;
        case 4: *reinterpret_cast<IrcNetwork**>(_v) = _t->network(); break;
        case 5: *reinterpret_cast<IrcBufferModel**>(_v) = _t->model(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->isActive(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->isChannel(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->isSticky(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->isPersistent(); break;
        case 10: *reinterpret_cast<QVariantMap*>(_v) = _t->userData(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setName(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setPrefix(*reinterpret_cast<QString*>(_v)); break;
        case 8: _t->setSticky(*reinterpret_cast<bool*>(_v)); break;
        case 9: _t->setPersistent(*reinterpret_cast<bool*>(_v)); break;
        case 10: _t->setUserData(*reinterpret_cast<QVariantMap*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *IrcBuffer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcBuffer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9IrcBufferE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IrcBuffer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void IrcBuffer::titleChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void IrcBuffer::nameChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void IrcBuffer::prefixChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void IrcBuffer::messageReceived(IrcMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void IrcBuffer::destroyed(IrcBuffer * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void IrcBuffer::activeChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void IrcBuffer::stickyChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void IrcBuffer::persistentChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void IrcBuffer::userDataChanged(const QVariantMap & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}
QT_WARNING_POP
