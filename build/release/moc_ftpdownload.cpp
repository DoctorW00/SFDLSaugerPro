/****************************************************************************
** Meta object code from reading C++ file 'ftpdownload.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ftpdownload.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftpdownload.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11FTPDownloadE_t {};
} // unnamed namespace

template <> constexpr inline auto FTPDownload::qt_create_metaobjectdata<qt_meta_tag_ZN11FTPDownloadE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "FTPDownload",
        "finished",
        "",
        "error",
        "err",
        "statusUpdateFile",
        "id",
        "tableRow",
        "statusMsg",
        "status",
        "doProgress",
        "read",
        "total",
        "overwriteTime",
        "firstUpdate",
        "process",
        "updateProgress",
        "finishedDownload",
        "abort"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'error'
        QtMocHelpers::SignalData<void(QString)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'statusUpdateFile'
        QtMocHelpers::SignalData<void(QString, int, QString, int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { QMetaType::Int, 7 }, { QMetaType::QString, 8 }, { QMetaType::Int, 9 },
        }}),
        // Signal 'doProgress'
        QtMocHelpers::SignalData<void(QString, int, qint64, qint64, bool, bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { QMetaType::Int, 7 }, { QMetaType::LongLong, 11 }, { QMetaType::LongLong, 12 },
            { QMetaType::Bool, 13 }, { QMetaType::Bool, 14 },
        }}),
        // Slot 'process'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateProgress'
        QtMocHelpers::SlotData<void(qint64, qint64)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::LongLong, 2 }, { QMetaType::LongLong, 2 },
        }}),
        // Slot 'finishedDownload'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'abort'
        QtMocHelpers::MethodData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<FTPDownload, qt_meta_tag_ZN11FTPDownloadE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject FTPDownload::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11FTPDownloadE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11FTPDownloadE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11FTPDownloadE_t>.metaTypes,
    nullptr
} };

void FTPDownload::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<FTPDownload *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->error((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->statusUpdateFile((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[4]))); break;
        case 3: _t->doProgress((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qint64>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<qint64>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[6]))); break;
        case 4: _t->process(); break;
        case 5: _t->updateProgress((*reinterpret_cast<std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qint64>>(_a[2]))); break;
        case 6: _t->finishedDownload(); break;
        case 7: _t->abort(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (FTPDownload::*)()>(_a, &FTPDownload::finished, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (FTPDownload::*)(QString )>(_a, &FTPDownload::error, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (FTPDownload::*)(QString , int , QString , int )>(_a, &FTPDownload::statusUpdateFile, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (FTPDownload::*)(QString , int , qint64 , qint64 , bool , bool )>(_a, &FTPDownload::doProgress, 3))
            return;
    }
}

const QMetaObject *FTPDownload::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FTPDownload::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11FTPDownloadE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FTPDownload::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void FTPDownload::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FTPDownload::error(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void FTPDownload::statusUpdateFile(QString _t1, int _t2, QString _t3, int _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 3
void FTPDownload::doProgress(QString _t1, int _t2, qint64 _t3, qint64 _t4, bool _t5, bool _t6)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2, _t3, _t4, _t5, _t6);
}
QT_WARNING_POP
