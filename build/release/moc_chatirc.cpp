/****************************************************************************
** Meta object code from reading C++ file 'chatirc.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chatirc.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatirc.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7chatIRCE_t {};
} // unnamed namespace

template <> constexpr inline auto chatIRC::qt_create_metaobjectdata<qt_meta_tag_ZN7chatIRCE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "chatIRC",
        "loadIRCLayout",
        "",
        "createParser",
        "createConnection",
        "createCompleter",
        "createUserList",
        "createBufferList",
        "onConnected",
        "onConnecting",
        "onDisconnected",
        "onTextEdited",
        "onTextEntered",
        "onCompletion",
        "onCompleted",
        "text",
        "cursor",
        "onBufferAdded",
        "IrcBuffer*",
        "buffer",
        "onBufferRemoved",
        "onBufferActivated",
        "QModelIndex",
        "index",
        "onUserActivated",
        "receiveMessage",
        "IrcMessage*",
        "message",
        "on_inputEdit_returnPressed",
        "on_buttonChatSend_pressed",
        "disableChatUi",
        "enableChatUi",
        "connectButtonHandling",
        "on_ircConnectButton_pressed",
        "setupServerComboBox",
        "on_selectIRCServer_currentIndexChanged",
        "setupProxyComboBox",
        "on_selectIRCProxy_currentIndexChanged",
        "appendDebugMessage",
        "closeEvent",
        "QCloseEvent*",
        "event"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'loadIRCLayout'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'createParser'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'createConnection'
        QtMocHelpers::SlotData<bool()>(4, 2, QMC::AccessPrivate, QMetaType::Bool),
        // Slot 'createCompleter'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'createUserList'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'createBufferList'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onConnected'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onConnecting'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onDisconnected'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onTextEdited'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onTextEntered'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onCompletion'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onCompleted'
        QtMocHelpers::SlotData<void(const QString &, int)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 15 }, { QMetaType::Int, 16 },
        }}),
        // Slot 'onBufferAdded'
        QtMocHelpers::SlotData<void(IrcBuffer *)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 18, 19 },
        }}),
        // Slot 'onBufferRemoved'
        QtMocHelpers::SlotData<void(IrcBuffer *)>(20, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 18, 19 },
        }}),
        // Slot 'onBufferActivated'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(21, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 22, 23 },
        }}),
        // Slot 'onUserActivated'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 22, 23 },
        }}),
        // Slot 'receiveMessage'
        QtMocHelpers::SlotData<void(IrcMessage *)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 26, 27 },
        }}),
        // Slot 'on_inputEdit_returnPressed'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_buttonChatSend_pressed'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'disableChatUi'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'enableChatUi'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'connectButtonHandling'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_ircConnectButton_pressed'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'setupServerComboBox'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_selectIRCServer_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(35, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 23 },
        }}),
        // Slot 'setupProxyComboBox'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_selectIRCProxy_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(37, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 23 },
        }}),
        // Slot 'appendDebugMessage'
        QtMocHelpers::SlotData<void(const QString &)>(38, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 15 },
        }}),
        // Slot 'closeEvent'
        QtMocHelpers::SlotData<void(QCloseEvent *)>(39, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 40, 41 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<chatIRC, qt_meta_tag_ZN7chatIRCE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject chatIRC::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7chatIRCE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7chatIRCE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7chatIRCE_t>.metaTypes,
    nullptr
} };

void chatIRC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<chatIRC *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->loadIRCLayout(); break;
        case 1: _t->createParser(); break;
        case 2: { bool _r = _t->createConnection();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->createCompleter(); break;
        case 4: _t->createUserList(); break;
        case 5: _t->createBufferList(); break;
        case 6: _t->onConnected(); break;
        case 7: _t->onConnecting(); break;
        case 8: _t->onDisconnected(); break;
        case 9: _t->onTextEdited(); break;
        case 10: _t->onTextEntered(); break;
        case 11: _t->onCompletion(); break;
        case 12: _t->onCompleted((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 13: _t->onBufferAdded((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 14: _t->onBufferRemoved((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 15: _t->onBufferActivated((*reinterpret_cast<std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 16: _t->onUserActivated((*reinterpret_cast<std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 17: _t->receiveMessage((*reinterpret_cast<std::add_pointer_t<IrcMessage*>>(_a[1]))); break;
        case 18: _t->on_inputEdit_returnPressed(); break;
        case 19: _t->on_buttonChatSend_pressed(); break;
        case 20: _t->disableChatUi(); break;
        case 21: _t->enableChatUi(); break;
        case 22: _t->connectButtonHandling(); break;
        case 23: _t->on_ircConnectButton_pressed(); break;
        case 24: _t->setupServerComboBox(); break;
        case 25: _t->on_selectIRCServer_currentIndexChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->setupProxyComboBox(); break;
        case 27: _t->on_selectIRCProxy_currentIndexChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->appendDebugMessage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->closeEvent((*reinterpret_cast<std::add_pointer_t<QCloseEvent*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcBuffer* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcBuffer* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcMessage* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *chatIRC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chatIRC::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7chatIRCE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int chatIRC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}
QT_WARNING_POP
