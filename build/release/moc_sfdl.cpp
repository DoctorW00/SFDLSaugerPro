/****************************************************************************
** Meta object code from reading C++ file 'sfdl.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../sfdl.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sfdl.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN4sfdlE_t {};
} // unnamed namespace

template <> constexpr inline auto sfdl::qt_create_metaobjectdata<qt_meta_tag_ZN4sfdlE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "sfdl",
        "sendSFDLData",
        "",
        "data",
        "files",
        "sendWarning",
        "label",
        "text",
        "sendLogText",
        "readSFDL",
        "setSFDL",
        "file",
        "passwordList",
        "loadSFDL",
        "ListElements",
        "QDomElement",
        "root",
        "tagname",
        "decryptString",
        "password",
        "encodedString",
        "validateIPv4",
        "ip"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sendSFDLData'
        QtMocHelpers::SignalData<void(QStringList, QStringList)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 3 }, { QMetaType::QStringList, 4 },
        }}),
        // Signal 'sendWarning'
        QtMocHelpers::SignalData<void(QString, QString)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { QMetaType::QString, 7 },
        }}),
        // Signal 'sendLogText'
        QtMocHelpers::SignalData<void(QString)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'readSFDL'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setSFDL'
        QtMocHelpers::SlotData<void(QString, QStringList)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 11 }, { QMetaType::QStringList, 12 },
        }}),
        // Slot 'loadSFDL'
        QtMocHelpers::SlotData<QByteArray(QString)>(13, 2, QMC::AccessPrivate, QMetaType::QByteArray, {{
            { QMetaType::QString, 11 },
        }}),
        // Slot 'ListElements'
        QtMocHelpers::SlotData<QString(QDomElement, QString)>(14, 2, QMC::AccessPrivate, QMetaType::QString, {{
            { 0x80000000 | 15, 16 }, { QMetaType::QString, 17 },
        }}),
        // Slot 'decryptString'
        QtMocHelpers::SlotData<QString(QString, QString)>(18, 2, QMC::AccessPrivate, QMetaType::QString, {{
            { QMetaType::QString, 19 }, { QMetaType::QString, 20 },
        }}),
        // Slot 'validateIPv4'
        QtMocHelpers::SlotData<bool(QString)>(21, 2, QMC::AccessPrivate, QMetaType::Bool, {{
            { QMetaType::QString, 22 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<sfdl, qt_meta_tag_ZN4sfdlE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject sfdl::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4sfdlE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4sfdlE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN4sfdlE_t>.metaTypes,
    nullptr
} };

void sfdl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<sfdl *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sendSFDLData((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 1: _t->sendWarning((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->sendLogText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->readSFDL(); break;
        case 4: _t->setSFDL((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 5: { QByteArray _r = _t->loadSFDL((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->ListElements((*reinterpret_cast<std::add_pointer_t<QDomElement>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->decryptString((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->validateIPv4((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (sfdl::*)(QStringList , QStringList )>(_a, &sfdl::sendSFDLData, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (sfdl::*)(QString , QString )>(_a, &sfdl::sendWarning, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (sfdl::*)(QString )>(_a, &sfdl::sendLogText, 2))
            return;
    }
}

const QMetaObject *sfdl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sfdl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4sfdlE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int sfdl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void sfdl::sendSFDLData(QStringList _t1, QStringList _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void sfdl::sendWarning(QString _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void sfdl::sendLogText(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
