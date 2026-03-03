/****************************************************************************
** Meta object code from reading C++ file 'irccommandparser.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcUtil/irccommandparser.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'irccommandparser.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16IrcCommandParserE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcCommandParser::qt_create_metaobjectdata<qt_meta_tag_ZN16IrcCommandParserE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcCommandParser",
        "commandsChanged",
        "",
        "commands",
        "triggersChanged",
        "triggers",
        "channelsChanged",
        "channels",
        "targetChanged",
        "target",
        "tolerancyChanged",
        "tolerant",
        "clear",
        "reset",
        "setTriggers",
        "setChannels",
        "setTarget",
        "syntax",
        "command",
        "Details",
        "details",
        "addCommand",
        "IrcCommand::Type",
        "type",
        "removeCommand",
        "parse",
        "IrcCommand*",
        "input",
        "Detail",
        "Full",
        "NoTarget",
        "NoPrefix",
        "NoEllipsis",
        "NoParentheses",
        "NoBrackets",
        "NoAngles",
        "Visual"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'commandsChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 3 },
        }}),
        // Signal 'triggersChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 5 },
        }}),
        // Signal 'channelsChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 7 },
        }}),
        // Signal 'targetChanged'
        QtMocHelpers::SignalData<void(const QString &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Signal 'tolerancyChanged'
        QtMocHelpers::SignalData<void(bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 11 },
        }}),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'reset'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setTriggers'
        QtMocHelpers::SlotData<void(const QStringList &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 5 },
        }}),
        // Slot 'setChannels'
        QtMocHelpers::SlotData<void(const QStringList &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 7 },
        }}),
        // Slot 'setTarget'
        QtMocHelpers::SlotData<void(const QString &)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Method 'syntax'
        QtMocHelpers::MethodData<QString(const QString &, Details) const>(17, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 18 }, { 0x80000000 | 19, 20 },
        }}),
        // Method 'syntax'
        QtMocHelpers::MethodData<QString(const QString &) const>(17, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QString, {{
            { QMetaType::QString, 18 },
        }}),
        // Method 'addCommand'
        QtMocHelpers::MethodData<void(IrcCommand::Type, const QString &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 22, 23 }, { QMetaType::QString, 17 },
        }}),
        // Method 'removeCommand'
        QtMocHelpers::MethodData<void(IrcCommand::Type, const QString &)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 22, 23 }, { QMetaType::QString, 17 },
        }}),
        // Method 'removeCommand'
        QtMocHelpers::MethodData<void(IrcCommand::Type)>(24, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 22, 23 },
        }}),
        // Method 'parse'
        QtMocHelpers::MethodData<IrcCommand *(const QString &) const>(25, 2, QMC::AccessPublic, 0x80000000 | 26, {{
            { QMetaType::QString, 27 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'commands'
        QtMocHelpers::PropertyData<QStringList>(3, QMetaType::QStringList, QMC::DefaultPropertyFlags, 0),
        // property 'triggers'
        QtMocHelpers::PropertyData<QStringList>(5, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'channels'
        QtMocHelpers::PropertyData<QStringList>(7, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'target'
        QtMocHelpers::PropertyData<QString>(9, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'tolerant'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
    };
    QtMocHelpers::UintData qt_enums {
        // flag 'Details'
        QtMocHelpers::EnumData<Details>(19, 28, QMC::EnumIsFlag).add({
            {   29, Detail::Full },
            {   30, Detail::NoTarget },
            {   31, Detail::NoPrefix },
            {   32, Detail::NoEllipsis },
            {   33, Detail::NoParentheses },
            {   34, Detail::NoBrackets },
            {   35, Detail::NoAngles },
            {   36, Detail::Visual },
        }),
    };
    return QtMocHelpers::metaObjectData<IrcCommandParser, qt_meta_tag_ZN16IrcCommandParserE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject IrcCommandParser::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16IrcCommandParserE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16IrcCommandParserE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16IrcCommandParserE_t>.metaTypes,
    nullptr
} };

void IrcCommandParser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcCommandParser *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->commandsChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 1: _t->triggersChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 2: _t->channelsChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 3: _t->targetChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->tolerancyChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->clear(); break;
        case 6: _t->reset(); break;
        case 7: _t->setTriggers((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 8: _t->setChannels((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 9: _t->setTarget((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: { QString _r = _t->syntax((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<Details>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->syntax((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->addCommand((*reinterpret_cast<std::add_pointer_t<IrcCommand::Type>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 13: _t->removeCommand((*reinterpret_cast<std::add_pointer_t<IrcCommand::Type>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 14: _t->removeCommand((*reinterpret_cast<std::add_pointer_t<IrcCommand::Type>>(_a[1]))); break;
        case 15: { IrcCommand* _r = _t->parse((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<IrcCommand**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IrcCommandParser::*)(const QStringList & )>(_a, &IrcCommandParser::commandsChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcCommandParser::*)(const QStringList & )>(_a, &IrcCommandParser::triggersChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcCommandParser::*)(const QStringList & )>(_a, &IrcCommandParser::channelsChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcCommandParser::*)(const QString & )>(_a, &IrcCommandParser::targetChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcCommandParser::*)(bool )>(_a, &IrcCommandParser::tolerancyChanged, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QStringList*>(_v) = _t->commands(); break;
        case 1: *reinterpret_cast<QStringList*>(_v) = _t->triggers(); break;
        case 2: *reinterpret_cast<QStringList*>(_v) = _t->channels(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->target(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isTolerant(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setTriggers(*reinterpret_cast<QStringList*>(_v)); break;
        case 2: _t->setChannels(*reinterpret_cast<QStringList*>(_v)); break;
        case 3: _t->setTarget(*reinterpret_cast<QString*>(_v)); break;
        case 4: _t->setTolerant(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *IrcCommandParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcCommandParser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16IrcCommandParserE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IrcCommandParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void IrcCommandParser::commandsChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void IrcCommandParser::triggersChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void IrcCommandParser::channelsChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void IrcCommandParser::targetChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void IrcCommandParser::tolerancyChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
