/****************************************************************************
** Meta object code from reading C++ file 'irctextformat.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcUtil/irctextformat.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'irctextformat.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13IrcTextFormatE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcTextFormat::qt_create_metaobjectdata<qt_meta_tag_ZN13IrcTextFormatE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcTextFormat",
        "parse",
        "",
        "text",
        "toHtml",
        "toPlainText",
        "palette",
        "IrcPalette*",
        "urlPattern",
        "plainText",
        "html",
        "urls",
        "QList<QUrl>",
        "SpanFormat",
        "SpanStyle",
        "SpanClass"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'parse'
        QtMocHelpers::SlotData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Method 'toHtml'
        QtMocHelpers::MethodData<QString(const QString &) const>(4, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 3 },
        }}),
        // Method 'toPlainText'
        QtMocHelpers::MethodData<QString(const QString &) const>(5, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'palette'
        QtMocHelpers::PropertyData<IrcPalette*>(6, 0x80000000 | 7, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'urlPattern'
        QtMocHelpers::PropertyData<QString>(8, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'plainText'
        QtMocHelpers::PropertyData<QString>(9, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'html'
        QtMocHelpers::PropertyData<QString>(10, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'urls'
        QtMocHelpers::PropertyData<QList<QUrl>>(11, 0x80000000 | 12, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SpanFormat'
        QtMocHelpers::EnumData<enum SpanFormat>(13, 13, QMC::EnumFlags{}).add({
            {   14, SpanFormat::SpanStyle },
            {   15, SpanFormat::SpanClass },
        }),
    };
    return QtMocHelpers::metaObjectData<IrcTextFormat, qt_meta_tag_ZN13IrcTextFormatE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject IrcTextFormat::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13IrcTextFormatE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13IrcTextFormatE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13IrcTextFormatE_t>.metaTypes,
    nullptr
} };

void IrcTextFormat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcTextFormat *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->parse((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: { QString _r = _t->toHtml((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->toPlainText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<IrcPalette**>(_v) = _t->palette(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->urlPattern(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->plainText(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->html(); break;
        case 4: *reinterpret_cast<QList<QUrl>*>(_v) = _t->urls(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setUrlPattern(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *IrcTextFormat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcTextFormat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13IrcTextFormatE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IrcTextFormat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
