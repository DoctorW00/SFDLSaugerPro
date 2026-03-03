/****************************************************************************
** Meta object code from reading C++ file 'ircusermodel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcModel/ircusermodel.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ircusermodel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12IrcUserModelE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcUserModel::qt_create_metaobjectdata<qt_meta_tag_ZN12IrcUserModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcUserModel",
        "added",
        "",
        "IrcUser*",
        "user",
        "removed",
        "aboutToBeAdded",
        "aboutToBeRemoved",
        "countChanged",
        "count",
        "emptyChanged",
        "empty",
        "namesChanged",
        "names",
        "titlesChanged",
        "titles",
        "usersChanged",
        "QList<IrcUser*>",
        "users",
        "channelChanged",
        "IrcChannel*",
        "channel",
        "clear",
        "sort",
        "column",
        "Qt::SortOrder",
        "order",
        "Irc::SortMethod",
        "method",
        "get",
        "index",
        "find",
        "name",
        "contains",
        "indexOf",
        "displayRole",
        "Irc::DataRole",
        "sortMethod",
        "sortOrder"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'added'
        QtMocHelpers::SignalData<void(IrcUser *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'removed'
        QtMocHelpers::SignalData<void(IrcUser *)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'aboutToBeAdded'
        QtMocHelpers::SignalData<void(IrcUser *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'aboutToBeRemoved'
        QtMocHelpers::SignalData<void(IrcUser *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'countChanged'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Signal 'emptyChanged'
        QtMocHelpers::SignalData<void(bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 11 },
        }}),
        // Signal 'namesChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 13 },
        }}),
        // Signal 'titlesChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 15 },
        }}),
        // Signal 'usersChanged'
        QtMocHelpers::SignalData<void(const QList<IrcUser*> &)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 17, 18 },
        }}),
        // Signal 'channelChanged'
        QtMocHelpers::SignalData<void(IrcChannel *)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 20, 21 },
        }}),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'sort'
        QtMocHelpers::SlotData<void(int, Qt::SortOrder)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 24 }, { 0x80000000 | 25, 26 },
        }}),
        // Slot 'sort'
        QtMocHelpers::SlotData<void(int)>(23, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::Int, 24 },
        }}),
        // Slot 'sort'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'sort'
        QtMocHelpers::SlotData<void(Irc::SortMethod, Qt::SortOrder)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 27, 28 }, { 0x80000000 | 25, 26 },
        }}),
        // Slot 'sort'
        QtMocHelpers::SlotData<void(Irc::SortMethod)>(23, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 27, 28 },
        }}),
        // Method 'get'
        QtMocHelpers::MethodData<IrcUser *(int) const>(29, 2, QMC::AccessPublic, 0x80000000 | 3, {{
            { QMetaType::Int, 30 },
        }}),
        // Method 'find'
        QtMocHelpers::MethodData<IrcUser *(const QString &) const>(31, 2, QMC::AccessPublic, 0x80000000 | 3, {{
            { QMetaType::QString, 32 },
        }}),
        // Method 'contains'
        QtMocHelpers::MethodData<bool(const QString &) const>(33, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 32 },
        }}),
        // Method 'indexOf'
        QtMocHelpers::MethodData<int(IrcUser *) const>(34, 2, QMC::AccessPublic, QMetaType::Int, {{
            { 0x80000000 | 3, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'count'
        QtMocHelpers::PropertyData<int>(9, QMetaType::Int, QMC::DefaultPropertyFlags, 4),
        // property 'empty'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags, 5),
        // property 'names'
        QtMocHelpers::PropertyData<QStringList>(13, QMetaType::QStringList, QMC::DefaultPropertyFlags, 6),
        // property 'titles'
        QtMocHelpers::PropertyData<QStringList>(15, QMetaType::QStringList, QMC::DefaultPropertyFlags, 7),
        // property 'users'
        QtMocHelpers::PropertyData<QList<IrcUser*>>(18, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 8),
        // property 'displayRole'
        QtMocHelpers::PropertyData<Irc::DataRole>(35, 0x80000000 | 36, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'channel'
        QtMocHelpers::PropertyData<IrcChannel*>(21, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 9),
        // property 'sortMethod'
        QtMocHelpers::PropertyData<Irc::SortMethod>(37, 0x80000000 | 27, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'sortOrder'
        QtMocHelpers::PropertyData<Qt::SortOrder>(38, 0x80000000 | 25, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<IrcUserModel, qt_meta_tag_ZN12IrcUserModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN12IrcUserModelE[] = {
    QMetaObject::SuperData::link<Irc::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject IrcUserModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12IrcUserModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12IrcUserModelE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN12IrcUserModelE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12IrcUserModelE_t>.metaTypes,
    nullptr
} };

void IrcUserModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcUserModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->added((*reinterpret_cast<std::add_pointer_t<IrcUser*>>(_a[1]))); break;
        case 1: _t->removed((*reinterpret_cast<std::add_pointer_t<IrcUser*>>(_a[1]))); break;
        case 2: _t->aboutToBeAdded((*reinterpret_cast<std::add_pointer_t<IrcUser*>>(_a[1]))); break;
        case 3: _t->aboutToBeRemoved((*reinterpret_cast<std::add_pointer_t<IrcUser*>>(_a[1]))); break;
        case 4: _t->countChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->emptyChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->namesChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 7: _t->titlesChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 8: _t->usersChanged((*reinterpret_cast<std::add_pointer_t<QList<IrcUser*>>>(_a[1]))); break;
        case 9: _t->channelChanged((*reinterpret_cast<std::add_pointer_t<IrcChannel*>>(_a[1]))); break;
        case 10: _t->clear(); break;
        case 11: _t->sort((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<Qt::SortOrder>>(_a[2]))); break;
        case 12: _t->sort((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->sort(); break;
        case 14: _t->sort((*reinterpret_cast<std::add_pointer_t<Irc::SortMethod>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<Qt::SortOrder>>(_a[2]))); break;
        case 15: _t->sort((*reinterpret_cast<std::add_pointer_t<Irc::SortMethod>>(_a[1]))); break;
        case 16: { IrcUser* _r = _t->get((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcUser**>(_a[0]) = std::move(_r); }  break;
        case 17: { IrcUser* _r = _t->find((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcUser**>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->contains((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { int _r = _t->indexOf((*reinterpret_cast<std::add_pointer_t<IrcUser*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IrcUserModel::*)(IrcUser * )>(_a, &IrcUserModel::added, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcUserModel::*)(IrcUser * )>(_a, &IrcUserModel::removed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcUserModel::*)(IrcUser * )>(_a, &IrcUserModel::aboutToBeAdded, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcUserModel::*)(IrcUser * )>(_a, &IrcUserModel::aboutToBeRemoved, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcUserModel::*)(int )>(_a, &IrcUserModel::countChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcUserModel::*)(bool )>(_a, &IrcUserModel::emptyChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcUserModel::*)(const QStringList & )>(_a, &IrcUserModel::namesChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcUserModel::*)(const QStringList & )>(_a, &IrcUserModel::titlesChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcUserModel::*)(const QList<IrcUser*> & )>(_a, &IrcUserModel::usersChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcUserModel::*)(IrcChannel * )>(_a, &IrcUserModel::channelChanged, 9))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->count(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isEmpty(); break;
        case 2: *reinterpret_cast<QStringList*>(_v) = _t->names(); break;
        case 3: *reinterpret_cast<QStringList*>(_v) = _t->titles(); break;
        case 4: *reinterpret_cast<QList<IrcUser*>*>(_v) = _t->users(); break;
        case 5: *reinterpret_cast<Irc::DataRole*>(_v) = _t->displayRole(); break;
        case 6: *reinterpret_cast<IrcChannel**>(_v) = _t->channel(); break;
        case 7: *reinterpret_cast<Irc::SortMethod*>(_v) = _t->sortMethod(); break;
        case 8: *reinterpret_cast<Qt::SortOrder*>(_v) = _t->sortOrder(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 5: _t->setDisplayRole(*reinterpret_cast<Irc::DataRole*>(_v)); break;
        case 6: _t->setChannel(*reinterpret_cast<IrcChannel**>(_v)); break;
        case 7: _t->setSortMethod(*reinterpret_cast<Irc::SortMethod*>(_v)); break;
        case 8: _t->setSortOrder(*reinterpret_cast<Qt::SortOrder*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *IrcUserModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcUserModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12IrcUserModelE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int IrcUserModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void IrcUserModel::added(IrcUser * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void IrcUserModel::removed(IrcUser * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void IrcUserModel::aboutToBeAdded(IrcUser * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void IrcUserModel::aboutToBeRemoved(IrcUser * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void IrcUserModel::countChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void IrcUserModel::emptyChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void IrcUserModel::namesChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void IrcUserModel::titlesChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void IrcUserModel::usersChanged(const QList<IrcUser*> & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void IrcUserModel::channelChanged(IrcChannel * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}
QT_WARNING_POP
