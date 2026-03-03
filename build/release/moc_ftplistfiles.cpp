/****************************************************************************
** Meta object code from reading C++ file 'ftplistfiles.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ftplistfiles.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftplistfiles.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12FTPListFilesE_t {};
} // unnamed namespace

template <> constexpr inline auto FTPListFiles::qt_create_metaobjectdata<qt_meta_tag_ZN12FTPListFilesE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "FTPListFiles",
        "sendWarning",
        "",
        "label",
        "text",
        "sendLogText",
        "sendFTPData",
        "data",
        "files",
        "ftpList",
        "ip",
        "port",
        "user",
        "pass",
        "path",
        "proxyHost",
        "proxyPort",
        "proxyUser",
        "proxyPass",
        "getFTPIndex"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sendWarning'
        QtMocHelpers::SignalData<void(QString, QString)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 4 },
        }}),
        // Signal 'sendLogText'
        QtMocHelpers::SignalData<void(QString)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'sendFTPData'
        QtMocHelpers::SignalData<void(QStringList, QStringList)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 7 }, { QMetaType::QStringList, 8 },
        }}),
        // Slot 'ftpList'
        QtMocHelpers::SlotData<void(QString, int, QString, QString, QString, QString, QString, QString, QString, QStringList)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 }, { QMetaType::Int, 11 }, { QMetaType::QString, 12 }, { QMetaType::QString, 13 },
            { QMetaType::QString, 14 }, { QMetaType::QString, 15 }, { QMetaType::QString, 16 }, { QMetaType::QString, 17 },
            { QMetaType::QString, 18 }, { QMetaType::QStringList, 7 },
        }}),
        // Slot 'getFTPIndex'
        QtMocHelpers::SlotData<void(QString, int, QString, QString, QString)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 10 }, { QMetaType::Int, 11 }, { QMetaType::QString, 12 }, { QMetaType::QString, 13 },
            { QMetaType::QString, 14 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<FTPListFiles, qt_meta_tag_ZN12FTPListFilesE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject FTPListFiles::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12FTPListFilesE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12FTPListFilesE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12FTPListFilesE_t>.metaTypes,
    nullptr
} };

void FTPListFiles::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<FTPListFiles *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sendWarning((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->sendLogText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->sendFTPData((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 3: _t->ftpList((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[10]))); break;
        case 4: _t->getFTPIndex((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (FTPListFiles::*)(QString , QString )>(_a, &FTPListFiles::sendWarning, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (FTPListFiles::*)(QString )>(_a, &FTPListFiles::sendLogText, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (FTPListFiles::*)(QStringList , QStringList )>(_a, &FTPListFiles::sendFTPData, 2))
            return;
    }
}

const QMetaObject *FTPListFiles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FTPListFiles::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12FTPListFilesE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FTPListFiles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FTPListFiles::sendWarning(QString _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void FTPListFiles::sendLogText(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void FTPListFiles::sendFTPData(QStringList _t1, QStringList _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}
QT_WARNING_POP
