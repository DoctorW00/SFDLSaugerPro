/****************************************************************************
** Meta object code from reading C++ file 'ircchannel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcModel/ircchannel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ircchannel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10IrcChannelE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcChannel::qt_create_metaobjectdata<qt_meta_tag_ZN10IrcChannelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcChannel",
        "keyChanged",
        "",
        "key",
        "modeChanged",
        "mode",
        "topicChanged",
        "topic",
        "destroyed",
        "IrcChannel*",
        "channel",
        "who",
        "join",
        "part",
        "reason",
        "close",
        "parent"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'keyChanged'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'modeChanged'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Signal 'topicChanged'
        QtMocHelpers::SignalData<void(const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Signal 'destroyed'
        QtMocHelpers::SignalData<void(IrcChannel *)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Slot 'who'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'join'
        QtMocHelpers::SlotData<void(const QString &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'join'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'part'
        QtMocHelpers::SlotData<void(const QString &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Slot 'part'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'close'
        QtMocHelpers::SlotData<void(const QString &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Slot 'close'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'key'
        QtMocHelpers::PropertyData<QString>(3, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'mode'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'topic'
        QtMocHelpers::PropertyData<QString>(7, QMetaType::QString, QMC::DefaultPropertyFlags, 2),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(QObject *)>(2, QMC::AccessPublic, {{
            { QMetaType::QObjectStar, 16 },
        }}),
        QtMocHelpers::ConstructorData<Constructor()>(2, QMC::AccessPublic | QMC::MethodCloned),
    };
    return QtMocHelpers::metaObjectData<IrcChannel, qt_meta_tag_ZN10IrcChannelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors);
}
Q_CONSTINIT const QMetaObject IrcChannel::staticMetaObject = { {
    QMetaObject::SuperData::link<IrcBuffer::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcChannelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcChannelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10IrcChannelE_t>.metaTypes,
    nullptr
} };

void IrcChannel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcChannel *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { IrcChannel *_r = new IrcChannel((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 1: { IrcChannel *_r = new IrcChannel();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) IrcChannel((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1]))); } break;
        case 1: { new (_a[0]) IrcChannel(); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->keyChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->modeChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->topicChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->destroyed((*reinterpret_cast<std::add_pointer_t<IrcChannel*>>(_a[1]))); break;
        case 4: _t->who(); break;
        case 5: _t->join((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->join(); break;
        case 7: _t->part((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->part(); break;
        case 9: _t->close((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->close(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcChannel* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IrcChannel::*)(const QString & )>(_a, &IrcChannel::keyChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcChannel::*)(const QString & )>(_a, &IrcChannel::modeChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcChannel::*)(const QString & )>(_a, &IrcChannel::topicChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcChannel::*)(IrcChannel * )>(_a, &IrcChannel::destroyed, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->key(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->mode(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->topic(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcChannel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcChannel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcChannelE_t>.strings))
        return static_cast<void*>(this);
    return IrcBuffer::qt_metacast(_clname);
}

int IrcChannel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IrcBuffer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void IrcChannel::keyChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void IrcChannel::modeChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void IrcChannel::topicChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void IrcChannel::destroyed(IrcChannel * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
