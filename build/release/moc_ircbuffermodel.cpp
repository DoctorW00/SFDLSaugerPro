/****************************************************************************
** Meta object code from reading C++ file 'ircbuffermodel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcModel/ircbuffermodel.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ircbuffermodel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14IrcBufferModelE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcBufferModel::qt_create_metaobjectdata<qt_meta_tag_ZN14IrcBufferModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcBufferModel",
        "countChanged",
        "",
        "count",
        "emptyChanged",
        "empty",
        "added",
        "IrcBuffer*",
        "buffer",
        "removed",
        "aboutToBeAdded",
        "aboutToBeRemoved",
        "persistentChanged",
        "persistent",
        "buffersChanged",
        "QList<IrcBuffer*>",
        "buffers",
        "channelsChanged",
        "channels",
        "connectionChanged",
        "IrcConnection*",
        "connection",
        "networkChanged",
        "IrcNetwork*",
        "network",
        "messageIgnored",
        "IrcMessage*",
        "message",
        "bufferPrototypeChanged",
        "prototype",
        "channelPrototypeChanged",
        "IrcChannel*",
        "destroyed",
        "IrcBufferModel*",
        "model",
        "joinDelayChanged",
        "delay",
        "monitorEnabledChanged",
        "enabled",
        "clear",
        "receiveMessage",
        "sort",
        "column",
        "Qt::SortOrder",
        "order",
        "Irc::SortMethod",
        "method",
        "createBuffer",
        "title",
        "createChannel",
        "_irc_connected",
        "_irc_initialized",
        "_irc_disconnected",
        "_irc_bufferDestroyed",
        "_irc_restoreBuffers",
        "_irc_monitorStatus",
        "get",
        "index",
        "find",
        "contains",
        "indexOf",
        "add",
        "remove",
        "saveState",
        "version",
        "restoreState",
        "state",
        "sortOrder",
        "sortMethod",
        "displayRole",
        "Irc::DataRole",
        "bufferPrototype",
        "channelPrototype",
        "joinDelay",
        "monitorEnabled"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'countChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'emptyChanged'
        QtMocHelpers::SignalData<void(bool)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 },
        }}),
        // Signal 'added'
        QtMocHelpers::SignalData<void(IrcBuffer *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Signal 'removed'
        QtMocHelpers::SignalData<void(IrcBuffer *)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Signal 'aboutToBeAdded'
        QtMocHelpers::SignalData<void(IrcBuffer *)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Signal 'aboutToBeRemoved'
        QtMocHelpers::SignalData<void(IrcBuffer *)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Signal 'persistentChanged'
        QtMocHelpers::SignalData<void(bool)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 13 },
        }}),
        // Signal 'buffersChanged'
        QtMocHelpers::SignalData<void(const QList<IrcBuffer*> &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 },
        }}),
        // Signal 'channelsChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 18 },
        }}),
        // Signal 'connectionChanged'
        QtMocHelpers::SignalData<void(IrcConnection *)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 20, 21 },
        }}),
        // Signal 'networkChanged'
        QtMocHelpers::SignalData<void(IrcNetwork *)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 23, 24 },
        }}),
        // Signal 'messageIgnored'
        QtMocHelpers::SignalData<void(IrcMessage *)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 26, 27 },
        }}),
        // Signal 'bufferPrototypeChanged'
        QtMocHelpers::SignalData<void(IrcBuffer *)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 29 },
        }}),
        // Signal 'channelPrototypeChanged'
        QtMocHelpers::SignalData<void(IrcChannel *)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 29 },
        }}),
        // Signal 'destroyed'
        QtMocHelpers::SignalData<void(IrcBufferModel *)>(32, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 33, 34 },
        }}),
        // Signal 'joinDelayChanged'
        QtMocHelpers::SignalData<void(int)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 36 },
        }}),
        // Signal 'monitorEnabledChanged'
        QtMocHelpers::SignalData<void(bool)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 38 },
        }}),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'receiveMessage'
        QtMocHelpers::SlotData<void(IrcMessage *)>(40, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 26, 27 },
        }}),
        // Slot 'sort'
        QtMocHelpers::SlotData<void(int, Qt::SortOrder)>(41, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 42 }, { 0x80000000 | 43, 44 },
        }}),
        // Slot 'sort'
        QtMocHelpers::SlotData<void(int)>(41, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::Int, 42 },
        }}),
        // Slot 'sort'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'sort'
        QtMocHelpers::SlotData<void(Irc::SortMethod, Qt::SortOrder)>(41, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 45, 46 }, { 0x80000000 | 43, 44 },
        }}),
        // Slot 'sort'
        QtMocHelpers::SlotData<void(Irc::SortMethod)>(41, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 45, 46 },
        }}),
        // Slot 'createBuffer'
        QtMocHelpers::SlotData<IrcBuffer *(const QString &)>(47, 2, QMC::AccessProtected, 0x80000000 | 7, {{
            { QMetaType::QString, 48 },
        }}),
        // Slot 'createChannel'
        QtMocHelpers::SlotData<IrcChannel *(const QString &)>(49, 2, QMC::AccessProtected, 0x80000000 | 31, {{
            { QMetaType::QString, 48 },
        }}),
        // Slot '_irc_connected'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_irc_initialized'
        QtMocHelpers::SlotData<void()>(51, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_irc_disconnected'
        QtMocHelpers::SlotData<void()>(52, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_irc_bufferDestroyed'
        QtMocHelpers::SlotData<void(IrcBuffer *)>(53, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Slot '_irc_restoreBuffers'
        QtMocHelpers::SlotData<void()>(54, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_irc_monitorStatus'
        QtMocHelpers::SlotData<void()>(55, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'get'
        QtMocHelpers::MethodData<IrcBuffer *(int) const>(56, 2, QMC::AccessPublic, 0x80000000 | 7, {{
            { QMetaType::Int, 57 },
        }}),
        // Method 'find'
        QtMocHelpers::MethodData<IrcBuffer *(const QString &) const>(58, 2, QMC::AccessPublic, 0x80000000 | 7, {{
            { QMetaType::QString, 48 },
        }}),
        // Method 'contains'
        QtMocHelpers::MethodData<bool(const QString &) const>(59, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 48 },
        }}),
        // Method 'indexOf'
        QtMocHelpers::MethodData<int(IrcBuffer *) const>(60, 2, QMC::AccessPublic, QMetaType::Int, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Method 'add'
        QtMocHelpers::MethodData<IrcBuffer *(const QString &)>(61, 2, QMC::AccessPublic, 0x80000000 | 7, {{
            { QMetaType::QString, 48 },
        }}),
        // Method 'add'
        QtMocHelpers::MethodData<void(IrcBuffer *)>(61, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Method 'remove'
        QtMocHelpers::MethodData<void(const QString &)>(62, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 48 },
        }}),
        // Method 'remove'
        QtMocHelpers::MethodData<void(IrcBuffer *)>(62, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Method 'saveState'
        QtMocHelpers::MethodData<QByteArray(int) const>(63, 2, QMC::AccessPublic, QMetaType::QByteArray, {{
            { QMetaType::Int, 64 },
        }}),
        // Method 'saveState'
        QtMocHelpers::MethodData<QByteArray() const>(63, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QByteArray),
        // Method 'restoreState'
        QtMocHelpers::MethodData<bool(const QByteArray &, int)>(65, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QByteArray, 66 }, { QMetaType::Int, 64 },
        }}),
        // Method 'restoreState'
        QtMocHelpers::MethodData<bool(const QByteArray &)>(65, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { QMetaType::QByteArray, 66 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'count'
        QtMocHelpers::PropertyData<int>(3, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'empty'
        QtMocHelpers::PropertyData<bool>(5, QMetaType::Bool, QMC::DefaultPropertyFlags, 1),
        // property 'sortOrder'
        QtMocHelpers::PropertyData<Qt::SortOrder>(67, 0x80000000 | 43, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'sortMethod'
        QtMocHelpers::PropertyData<Irc::SortMethod>(68, 0x80000000 | 45, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'channels'
        QtMocHelpers::PropertyData<QStringList>(18, QMetaType::QStringList, QMC::DefaultPropertyFlags, 8),
        // property 'displayRole'
        QtMocHelpers::PropertyData<Irc::DataRole>(69, 0x80000000 | 70, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'persistent'
        QtMocHelpers::PropertyData<bool>(13, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'buffers'
        QtMocHelpers::PropertyData<QList<IrcBuffer*>>(16, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 7),
        // property 'connection'
        QtMocHelpers::PropertyData<IrcConnection*>(21, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 9),
        // property 'network'
        QtMocHelpers::PropertyData<IrcNetwork*>(24, 0x80000000 | 23, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 10),
        // property 'bufferPrototype'
        QtMocHelpers::PropertyData<IrcBuffer*>(71, 0x80000000 | 7, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 12),
        // property 'channelPrototype'
        QtMocHelpers::PropertyData<IrcChannel*>(72, 0x80000000 | 31, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 13),
        // property 'joinDelay'
        QtMocHelpers::PropertyData<int>(73, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 15),
        // property 'monitorEnabled'
        QtMocHelpers::PropertyData<bool>(74, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 16),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<IrcBufferModel, qt_meta_tag_ZN14IrcBufferModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN14IrcBufferModelE[] = {
    QMetaObject::SuperData::link<Irc::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject IrcBufferModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcBufferModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcBufferModelE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN14IrcBufferModelE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14IrcBufferModelE_t>.metaTypes,
    nullptr
} };

void IrcBufferModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcBufferModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->countChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->emptyChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->added((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 3: _t->removed((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 4: _t->aboutToBeAdded((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 5: _t->aboutToBeRemoved((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 6: _t->persistentChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->buffersChanged((*reinterpret_cast<std::add_pointer_t<QList<IrcBuffer*>>>(_a[1]))); break;
        case 8: _t->channelsChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 9: _t->connectionChanged((*reinterpret_cast<std::add_pointer_t<IrcConnection*>>(_a[1]))); break;
        case 10: _t->networkChanged((*reinterpret_cast<std::add_pointer_t<IrcNetwork*>>(_a[1]))); break;
        case 11: _t->messageIgnored((*reinterpret_cast<std::add_pointer_t<IrcMessage*>>(_a[1]))); break;
        case 12: _t->bufferPrototypeChanged((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 13: _t->channelPrototypeChanged((*reinterpret_cast<std::add_pointer_t<IrcChannel*>>(_a[1]))); break;
        case 14: _t->destroyed((*reinterpret_cast<std::add_pointer_t<IrcBufferModel*>>(_a[1]))); break;
        case 15: _t->joinDelayChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->monitorEnabledChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->clear(); break;
        case 18: _t->receiveMessage((*reinterpret_cast<std::add_pointer_t<IrcMessage*>>(_a[1]))); break;
        case 19: _t->sort((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<Qt::SortOrder>>(_a[2]))); break;
        case 20: _t->sort((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->sort(); break;
        case 22: _t->sort((*reinterpret_cast<std::add_pointer_t<Irc::SortMethod>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<Qt::SortOrder>>(_a[2]))); break;
        case 23: _t->sort((*reinterpret_cast<std::add_pointer_t<Irc::SortMethod>>(_a[1]))); break;
        case 24: { IrcBuffer* _r = _t->createBuffer((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcBuffer**>(_a[0]) = std::move(_r); }  break;
        case 25: { IrcChannel* _r = _t->createChannel((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcChannel**>(_a[0]) = std::move(_r); }  break;
        case 26: _t->d_func()->_irc_connected(); break;
        case 27: _t->d_func()->_irc_initialized(); break;
        case 28: _t->d_func()->_irc_disconnected(); break;
        case 29: _t->d_func()->_irc_bufferDestroyed((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 30: _t->d_func()->_irc_restoreBuffers(); break;
        case 31: _t->d_func()->_irc_monitorStatus(); break;
        case 32: { IrcBuffer* _r = _t->get((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcBuffer**>(_a[0]) = std::move(_r); }  break;
        case 33: { IrcBuffer* _r = _t->find((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcBuffer**>(_a[0]) = std::move(_r); }  break;
        case 34: { bool _r = _t->contains((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 35: { int _r = _t->indexOf((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 36: { IrcBuffer* _r = _t->add((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcBuffer**>(_a[0]) = std::move(_r); }  break;
        case 37: _t->add((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 38: _t->remove((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 39: _t->remove((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 40: { QByteArray _r = _t->saveState((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 41: { QByteArray _r = _t->saveState();
            if (_a[0]) *reinterpret_cast<QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 42: { bool _r = _t->restoreState((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 43: { bool _r = _t->restoreState((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< IrcBufferModel* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(int )>(_a, &IrcBufferModel::countChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(bool )>(_a, &IrcBufferModel::emptyChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(IrcBuffer * )>(_a, &IrcBufferModel::added, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(IrcBuffer * )>(_a, &IrcBufferModel::removed, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(IrcBuffer * )>(_a, &IrcBufferModel::aboutToBeAdded, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(IrcBuffer * )>(_a, &IrcBufferModel::aboutToBeRemoved, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(bool )>(_a, &IrcBufferModel::persistentChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(const QList<IrcBuffer*> & )>(_a, &IrcBufferModel::buffersChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(const QStringList & )>(_a, &IrcBufferModel::channelsChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(IrcConnection * )>(_a, &IrcBufferModel::connectionChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(IrcNetwork * )>(_a, &IrcBufferModel::networkChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(IrcMessage * )>(_a, &IrcBufferModel::messageIgnored, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(IrcBuffer * )>(_a, &IrcBufferModel::bufferPrototypeChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(IrcChannel * )>(_a, &IrcBufferModel::channelPrototypeChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(IrcBufferModel * )>(_a, &IrcBufferModel::destroyed, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(int )>(_a, &IrcBufferModel::joinDelayChanged, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcBufferModel::*)(bool )>(_a, &IrcBufferModel::monitorEnabledChanged, 16))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->count(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isEmpty(); break;
        case 2: *reinterpret_cast<Qt::SortOrder*>(_v) = _t->sortOrder(); break;
        case 3: *reinterpret_cast<Irc::SortMethod*>(_v) = _t->sortMethod(); break;
        case 4: *reinterpret_cast<QStringList*>(_v) = _t->channels(); break;
        case 5: *reinterpret_cast<Irc::DataRole*>(_v) = _t->displayRole(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->isPersistent(); break;
        case 7: *reinterpret_cast<QList<IrcBuffer*>*>(_v) = _t->buffers(); break;
        case 8: *reinterpret_cast<IrcConnection**>(_v) = _t->connection(); break;
        case 9: *reinterpret_cast<IrcNetwork**>(_v) = _t->network(); break;
        case 10: *reinterpret_cast<IrcBuffer**>(_v) = _t->bufferPrototype(); break;
        case 11: *reinterpret_cast<IrcChannel**>(_v) = _t->channelPrototype(); break;
        case 12: *reinterpret_cast<int*>(_v) = _t->joinDelay(); break;
        case 13: *reinterpret_cast<bool*>(_v) = _t->isMonitorEnabled(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setSortOrder(*reinterpret_cast<Qt::SortOrder*>(_v)); break;
        case 3: _t->setSortMethod(*reinterpret_cast<Irc::SortMethod*>(_v)); break;
        case 5: _t->setDisplayRole(*reinterpret_cast<Irc::DataRole*>(_v)); break;
        case 6: _t->setPersistent(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setConnection(*reinterpret_cast<IrcConnection**>(_v)); break;
        case 10: _t->setBufferPrototype(*reinterpret_cast<IrcBuffer**>(_v)); break;
        case 11: _t->setChannelPrototype(*reinterpret_cast<IrcChannel**>(_v)); break;
        case 12: _t->setJoinDelay(*reinterpret_cast<int*>(_v)); break;
        case 13: _t->setMonitorEnabled(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *IrcBufferModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcBufferModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14IrcBufferModelE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int IrcBufferModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void IrcBufferModel::countChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void IrcBufferModel::emptyChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void IrcBufferModel::added(IrcBuffer * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void IrcBufferModel::removed(IrcBuffer * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void IrcBufferModel::aboutToBeAdded(IrcBuffer * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void IrcBufferModel::aboutToBeRemoved(IrcBuffer * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void IrcBufferModel::persistentChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void IrcBufferModel::buffersChanged(const QList<IrcBuffer*> & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void IrcBufferModel::channelsChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void IrcBufferModel::connectionChanged(IrcConnection * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void IrcBufferModel::networkChanged(IrcNetwork * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void IrcBufferModel::messageIgnored(IrcMessage * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void IrcBufferModel::bufferPrototypeChanged(IrcBuffer * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}

// SIGNAL 13
void IrcBufferModel::channelPrototypeChanged(IrcChannel * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}

// SIGNAL 14
void IrcBufferModel::destroyed(IrcBufferModel * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1);
}

// SIGNAL 15
void IrcBufferModel::joinDelayChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1);
}

// SIGNAL 16
void IrcBufferModel::monitorEnabledChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 16, nullptr, _t1);
}
QT_WARNING_POP
