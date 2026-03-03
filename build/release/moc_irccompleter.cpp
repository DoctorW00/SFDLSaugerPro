/****************************************************************************
** Meta object code from reading C++ file 'irccompleter.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcUtil/irccompleter.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'irccompleter.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12IrcCompleterE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcCompleter::qt_create_metaobjectdata<qt_meta_tag_ZN12IrcCompleterE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcCompleter",
        "suffixChanged",
        "",
        "suffix",
        "bufferChanged",
        "IrcBuffer*",
        "buffer",
        "parserChanged",
        "IrcCommandParser*",
        "parser",
        "completed",
        "text",
        "cursor",
        "setSuffix",
        "setBuffer",
        "setParser",
        "complete",
        "Direction",
        "direction",
        "reset",
        "Forward",
        "Backward"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'suffixChanged'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'bufferChanged'
        QtMocHelpers::SignalData<void(IrcBuffer *)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Signal 'parserChanged'
        QtMocHelpers::SignalData<void(IrcCommandParser *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'completed'
        QtMocHelpers::SignalData<void(const QString &, int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 11 }, { QMetaType::Int, 12 },
        }}),
        // Slot 'setSuffix'
        QtMocHelpers::SlotData<void(const QString &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'setBuffer'
        QtMocHelpers::SlotData<void(IrcBuffer *)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Slot 'setParser'
        QtMocHelpers::SlotData<void(IrcCommandParser *)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Slot 'complete'
        QtMocHelpers::SlotData<void(const QString &, int, enum Direction)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 11 }, { QMetaType::Int, 12 }, { 0x80000000 | 17, 18 },
        }}),
        // Slot 'complete'
        QtMocHelpers::SlotData<void(const QString &, int)>(16, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 11 }, { QMetaType::Int, 12 },
        }}),
        // Slot 'reset'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'suffix'
        QtMocHelpers::PropertyData<QString>(3, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'buffer'
        QtMocHelpers::PropertyData<IrcBuffer*>(6, 0x80000000 | 5, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
        // property 'parser'
        QtMocHelpers::PropertyData<IrcCommandParser*>(9, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 2),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Direction'
        QtMocHelpers::EnumData<enum Direction>(17, 17, QMC::EnumFlags{}).add({
            {   20, Direction::Forward },
            {   21, Direction::Backward },
        }),
    };
    return QtMocHelpers::metaObjectData<IrcCompleter, qt_meta_tag_ZN12IrcCompleterE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject IrcCompleter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12IrcCompleterE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12IrcCompleterE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12IrcCompleterE_t>.metaTypes,
    nullptr
} };

void IrcCompleter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcCompleter *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->suffixChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->bufferChanged((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 2: _t->parserChanged((*reinterpret_cast<std::add_pointer_t<IrcCommandParser*>>(_a[1]))); break;
        case 3: _t->completed((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->setSuffix((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->setBuffer((*reinterpret_cast<std::add_pointer_t<IrcBuffer*>>(_a[1]))); break;
        case 6: _t->setParser((*reinterpret_cast<std::add_pointer_t<IrcCommandParser*>>(_a[1]))); break;
        case 7: _t->complete((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<enum Direction>>(_a[3]))); break;
        case 8: _t->complete((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->reset(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IrcCompleter::*)(const QString & )>(_a, &IrcCompleter::suffixChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcCompleter::*)(IrcBuffer * )>(_a, &IrcCompleter::bufferChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcCompleter::*)(IrcCommandParser * )>(_a, &IrcCompleter::parserChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcCompleter::*)(const QString & , int )>(_a, &IrcCompleter::completed, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->suffix(); break;
        case 1: *reinterpret_cast<IrcBuffer**>(_v) = _t->buffer(); break;
        case 2: *reinterpret_cast<IrcCommandParser**>(_v) = _t->parser(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSuffix(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setBuffer(*reinterpret_cast<IrcBuffer**>(_v)); break;
        case 2: _t->setParser(*reinterpret_cast<IrcCommandParser**>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *IrcCompleter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcCompleter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12IrcCompleterE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IrcCompleter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
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
void IrcCompleter::suffixChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void IrcCompleter::bufferChanged(IrcBuffer * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void IrcCompleter::parserChanged(IrcCommandParser * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void IrcCompleter::completed(const QString & _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}
QT_WARNING_POP
