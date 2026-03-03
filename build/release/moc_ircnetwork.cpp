/****************************************************************************
** Meta object code from reading C++ file 'ircnetwork.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcCore/ircnetwork.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ircnetwork.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10IrcNetworkE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcNetwork::qt_create_metaobjectdata<qt_meta_tag_ZN10IrcNetworkE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcNetwork",
        "initialized",
        "",
        "nameChanged",
        "name",
        "modesChanged",
        "modes",
        "prefixesChanged",
        "prefixes",
        "channelTypesChanged",
        "types",
        "statusPrefixesChanged",
        "availableCapabilitiesChanged",
        "capabilities",
        "requestedCapabilitiesChanged",
        "activeCapabilitiesChanged",
        "skipCapabilityValidationChanged",
        "skip",
        "requestingCapabilities",
        "requestCapability",
        "capability",
        "requestCapabilities",
        "setRequestedCapabilities",
        "setSkipCapabilityValidation",
        "modeToPrefix",
        "mode",
        "prefixToMode",
        "prefix",
        "isChannel",
        "channelModes",
        "IrcNetwork::ModeTypes",
        "numericLimit",
        "IrcNetwork::Limit",
        "limit",
        "modeLimit",
        "channelLimit",
        "type",
        "targetLimit",
        "command",
        "hasCapability",
        "isCapable",
        "channelTypes",
        "statusPrefixes",
        "availableCapabilities",
        "requestedCapabilities",
        "activeCapabilities",
        "skipCapabilityValidation",
        "ModeType",
        "TypeA",
        "TypeB",
        "TypeC",
        "TypeD",
        "AllTypes",
        "ModeTypes",
        "Limit",
        "NickLength",
        "ChannelLength",
        "TopicLength",
        "MessageLength",
        "KickReasonLength",
        "AwayReasonLength",
        "ModeCount",
        "MonitorCount"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'initialized'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nameChanged'
        QtMocHelpers::SignalData<void(const QString &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'modesChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 6 },
        }}),
        // Signal 'prefixesChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 8 },
        }}),
        // Signal 'channelTypesChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 10 },
        }}),
        // Signal 'statusPrefixesChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 8 },
        }}),
        // Signal 'availableCapabilitiesChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 13 },
        }}),
        // Signal 'requestedCapabilitiesChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 13 },
        }}),
        // Signal 'activeCapabilitiesChanged'
        QtMocHelpers::SignalData<void(const QStringList &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 13 },
        }}),
        // Signal 'skipCapabilityValidationChanged'
        QtMocHelpers::SignalData<void(bool)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 17 },
        }}),
        // Signal 'requestingCapabilities'
        QtMocHelpers::SignalData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'requestCapability'
        QtMocHelpers::SlotData<bool(const QString &)>(19, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 20 },
        }}),
        // Slot 'requestCapabilities'
        QtMocHelpers::SlotData<bool(const QStringList &)>(21, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QStringList, 13 },
        }}),
        // Slot 'setRequestedCapabilities'
        QtMocHelpers::SlotData<void(const QStringList &)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 13 },
        }}),
        // Slot 'setSkipCapabilityValidation'
        QtMocHelpers::SlotData<void(bool)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 17 },
        }}),
        // Method 'modeToPrefix'
        QtMocHelpers::MethodData<QString(const QString &) const>(24, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 25 },
        }}),
        // Method 'prefixToMode'
        QtMocHelpers::MethodData<QString(const QString &) const>(26, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 27 },
        }}),
        // Method 'isChannel'
        QtMocHelpers::MethodData<bool(const QString &) const>(28, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 4 },
        }}),
        // Method 'channelModes'
        QtMocHelpers::MethodData<QStringList(IrcNetwork::ModeTypes) const>(29, 2, QMC::AccessPublic, QMetaType::QStringList, {{
            { 0x80000000 | 30, 10 },
        }}),
        // Method 'numericLimit'
        QtMocHelpers::MethodData<int(IrcNetwork::Limit) const>(31, 2, QMC::AccessPublic, QMetaType::Int, {{
            { 0x80000000 | 32, 33 },
        }}),
        // Method 'modeLimit'
        QtMocHelpers::MethodData<int(const QString &) const>(34, 2, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::QString, 25 },
        }}),
        // Method 'channelLimit'
        QtMocHelpers::MethodData<int(const QString &) const>(35, 2, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::QString, 36 },
        }}),
        // Method 'targetLimit'
        QtMocHelpers::MethodData<int(const QString &) const>(37, 2, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::QString, 38 },
        }}),
        // Method 'hasCapability'
        QtMocHelpers::MethodData<bool(const QString &) const>(39, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 20 },
        }}),
        // Method 'isCapable'
        QtMocHelpers::MethodData<bool(const QString &) const>(40, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 20 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'initialized'
        QtMocHelpers::PropertyData<bool>(1, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'modes'
        QtMocHelpers::PropertyData<QStringList>(6, QMetaType::QStringList, QMC::DefaultPropertyFlags, 2),
        // property 'prefixes'
        QtMocHelpers::PropertyData<QStringList>(8, QMetaType::QStringList, QMC::DefaultPropertyFlags, 3),
        // property 'channelTypes'
        QtMocHelpers::PropertyData<QStringList>(41, QMetaType::QStringList, QMC::DefaultPropertyFlags, 4),
        // property 'statusPrefixes'
        QtMocHelpers::PropertyData<QStringList>(42, QMetaType::QStringList, QMC::DefaultPropertyFlags, 5),
        // property 'availableCapabilities'
        QtMocHelpers::PropertyData<QStringList>(43, QMetaType::QStringList, QMC::DefaultPropertyFlags, 6),
        // property 'requestedCapabilities'
        QtMocHelpers::PropertyData<QStringList>(44, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'activeCapabilities'
        QtMocHelpers::PropertyData<QStringList>(45, QMetaType::QStringList, QMC::DefaultPropertyFlags, 8),
        // property 'skipCapabilityValidation'
        QtMocHelpers::PropertyData<bool>(46, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 9),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ModeType'
        QtMocHelpers::EnumData<enum ModeType>(47, 47, QMC::EnumFlags{}).add({
            {   48, ModeType::TypeA },
            {   49, ModeType::TypeB },
            {   50, ModeType::TypeC },
            {   51, ModeType::TypeD },
            {   52, ModeType::AllTypes },
        }),
        // flag 'ModeTypes'
        QtMocHelpers::EnumData<ModeTypes>(53, 47, QMC::EnumIsFlag).add({
            {   48, ModeType::TypeA },
            {   49, ModeType::TypeB },
            {   50, ModeType::TypeC },
            {   51, ModeType::TypeD },
            {   52, ModeType::AllTypes },
        }),
        // enum 'Limit'
        QtMocHelpers::EnumData<enum Limit>(54, 54, QMC::EnumFlags{}).add({
            {   55, Limit::NickLength },
            {   56, Limit::ChannelLength },
            {   57, Limit::TopicLength },
            {   58, Limit::MessageLength },
            {   59, Limit::KickReasonLength },
            {   60, Limit::AwayReasonLength },
            {   61, Limit::ModeCount },
            {   62, Limit::MonitorCount },
        }),
    };
    return QtMocHelpers::metaObjectData<IrcNetwork, qt_meta_tag_ZN10IrcNetworkE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject IrcNetwork::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcNetworkE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcNetworkE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10IrcNetworkE_t>.metaTypes,
    nullptr
} };

void IrcNetwork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcNetwork *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->initialized(); break;
        case 1: _t->nameChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->modesChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 3: _t->prefixesChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 4: _t->channelTypesChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 5: _t->statusPrefixesChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 6: _t->availableCapabilitiesChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 7: _t->requestedCapabilitiesChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 8: _t->activeCapabilitiesChanged((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 9: _t->skipCapabilityValidationChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->requestingCapabilities(); break;
        case 11: { bool _r = _t->requestCapability((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->requestCapabilities((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->setRequestedCapabilities((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 14: _t->setSkipCapabilityValidation((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: { QString _r = _t->modeToPrefix((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->prefixToMode((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->isChannel((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { QStringList _r = _t->channelModes((*reinterpret_cast<std::add_pointer_t<IrcNetwork::ModeTypes>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QStringList*>(_a[0]) = std::move(_r); }  break;
        case 19: { int _r = _t->numericLimit((*reinterpret_cast<std::add_pointer_t<IrcNetwork::Limit>>(_a[1])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 20: { int _r = _t->modeLimit((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 21: { int _r = _t->channelLimit((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 22: { int _r = _t->targetLimit((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->hasCapability((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { bool _r = _t->isCapable((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IrcNetwork::*)()>(_a, &IrcNetwork::initialized, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcNetwork::*)(const QString & )>(_a, &IrcNetwork::nameChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcNetwork::*)(const QStringList & )>(_a, &IrcNetwork::modesChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcNetwork::*)(const QStringList & )>(_a, &IrcNetwork::prefixesChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcNetwork::*)(const QStringList & )>(_a, &IrcNetwork::channelTypesChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcNetwork::*)(const QStringList & )>(_a, &IrcNetwork::statusPrefixesChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcNetwork::*)(const QStringList & )>(_a, &IrcNetwork::availableCapabilitiesChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcNetwork::*)(const QStringList & )>(_a, &IrcNetwork::requestedCapabilitiesChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcNetwork::*)(const QStringList & )>(_a, &IrcNetwork::activeCapabilitiesChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcNetwork::*)(bool )>(_a, &IrcNetwork::skipCapabilityValidationChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (IrcNetwork::*)()>(_a, &IrcNetwork::requestingCapabilities, 10))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isInitialized(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->name(); break;
        case 2: *reinterpret_cast<QStringList*>(_v) = _t->modes(); break;
        case 3: *reinterpret_cast<QStringList*>(_v) = _t->prefixes(); break;
        case 4: *reinterpret_cast<QStringList*>(_v) = _t->channelTypes(); break;
        case 5: *reinterpret_cast<QStringList*>(_v) = _t->statusPrefixes(); break;
        case 6: *reinterpret_cast<QStringList*>(_v) = _t->availableCapabilities(); break;
        case 7: *reinterpret_cast<QStringList*>(_v) = _t->requestedCapabilities(); break;
        case 8: *reinterpret_cast<QStringList*>(_v) = _t->activeCapabilities(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->skipCapabilityValidation(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 7: _t->setRequestedCapabilities(*reinterpret_cast<QStringList*>(_v)); break;
        case 9: _t->setSkipCapabilityValidation(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *IrcNetwork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcNetwork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcNetworkE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IrcNetwork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 25;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void IrcNetwork::initialized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void IrcNetwork::nameChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void IrcNetwork::modesChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void IrcNetwork::prefixesChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void IrcNetwork::channelTypesChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void IrcNetwork::statusPrefixesChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void IrcNetwork::availableCapabilitiesChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void IrcNetwork::requestedCapabilitiesChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void IrcNetwork::activeCapabilitiesChanged(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void IrcNetwork::skipCapabilityValidationChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void IrcNetwork::requestingCapabilities()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
