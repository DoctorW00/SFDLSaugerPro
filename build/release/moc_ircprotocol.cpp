/****************************************************************************
** Meta object code from reading C++ file 'ircprotocol.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcCore/ircprotocol.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QSet>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ircprotocol.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11IrcProtocolE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcProtocol::qt_create_metaobjectdata<qt_meta_tag_ZN11IrcProtocolE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcProtocol",
        "receiveMessage",
        "",
        "IrcMessage*",
        "message",
        "setNickName",
        "name",
        "setStatus",
        "IrcConnection::Status",
        "status",
        "setInfo",
        "QHash<QString,QString>",
        "info",
        "setAvailableCapabilities",
        "QSet<QString>",
        "capabilities",
        "setActiveCapabilities",
        "_irc_pauseHandshake",
        "_irc_resumeHandshake",
        "connection",
        "IrcConnection*",
        "socket",
        "QAbstractSocket*"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'receiveMessage'
        QtMocHelpers::SlotData<void(IrcMessage *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'setNickName'
        QtMocHelpers::SlotData<void(const QString &)>(5, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Slot 'setStatus'
        QtMocHelpers::SlotData<void(IrcConnection::Status)>(7, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Slot 'setInfo'
        QtMocHelpers::SlotData<void(const QHash<QString,QString> &)>(10, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Slot 'setAvailableCapabilities'
        QtMocHelpers::SlotData<void(const QSet<QString> &)>(13, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 14, 15 },
        }}),
        // Slot 'setActiveCapabilities'
        QtMocHelpers::SlotData<void(const QSet<QString> &)>(16, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 14, 15 },
        }}),
        // Slot '_irc_pauseHandshake'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_irc_resumeHandshake'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'connection'
        QtMocHelpers::PropertyData<IrcConnection*>(19, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'socket'
        QtMocHelpers::PropertyData<QAbstractSocket*>(21, 0x80000000 | 22, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<IrcProtocol, qt_meta_tag_ZN11IrcProtocolE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject IrcProtocol::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11IrcProtocolE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11IrcProtocolE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11IrcProtocolE_t>.metaTypes,
    nullptr
} };

void IrcProtocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcProtocol *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->receiveMessage((*reinterpret_cast<std::add_pointer_t<IrcMessage*>>(_a[1]))); break;
        case 1: _t->setNickName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->setStatus((*reinterpret_cast<std::add_pointer_t<IrcConnection::Status>>(_a[1]))); break;
        case 3: _t->setInfo((*reinterpret_cast<std::add_pointer_t<QHash<QString,QString>>>(_a[1]))); break;
        case 4: _t->setAvailableCapabilities((*reinterpret_cast<std::add_pointer_t<QSet<QString>>>(_a[1]))); break;
        case 5: _t->setActiveCapabilities((*reinterpret_cast<std::add_pointer_t<QSet<QString>>>(_a[1]))); break;
        case 6: _t->d_func()->_irc_pauseHandshake(); break;
        case 7: _t->d_func()->_irc_resumeHandshake(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcMessage* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSet<QString> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSet<QString> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IrcConnection* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<IrcConnection**>(_v) = _t->connection(); break;
        case 1: *reinterpret_cast<QAbstractSocket**>(_v) = _t->socket(); break;
        default: break;
        }
    }
}

const QMetaObject *IrcProtocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcProtocol::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11IrcProtocolE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IrcProtocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
