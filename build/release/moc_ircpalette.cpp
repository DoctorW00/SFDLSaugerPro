/****************************************************************************
** Meta object code from reading C++ file 'ircpalette.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../libcommuni/include/IrcUtil/ircpalette.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ircpalette.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10IrcPaletteE_t {};
} // unnamed namespace

template <> constexpr inline auto IrcPalette::qt_create_metaobjectdata<qt_meta_tag_ZN10IrcPaletteE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IrcPalette",
        "white",
        "black",
        "blue",
        "green",
        "red",
        "brown",
        "purple",
        "orange",
        "yellow",
        "lightGreen",
        "cyan",
        "lightCyan",
        "lightBlue",
        "pink",
        "gray",
        "lightGray"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'white'
        QtMocHelpers::PropertyData<QString>(1, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'black'
        QtMocHelpers::PropertyData<QString>(2, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'blue'
        QtMocHelpers::PropertyData<QString>(3, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'green'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'red'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'brown'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'purple'
        QtMocHelpers::PropertyData<QString>(7, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'orange'
        QtMocHelpers::PropertyData<QString>(8, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'yellow'
        QtMocHelpers::PropertyData<QString>(9, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'lightGreen'
        QtMocHelpers::PropertyData<QString>(10, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'cyan'
        QtMocHelpers::PropertyData<QString>(11, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'lightCyan'
        QtMocHelpers::PropertyData<QString>(12, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'lightBlue'
        QtMocHelpers::PropertyData<QString>(13, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'pink'
        QtMocHelpers::PropertyData<QString>(14, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'gray'
        QtMocHelpers::PropertyData<QString>(15, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'lightGray'
        QtMocHelpers::PropertyData<QString>(16, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<IrcPalette, qt_meta_tag_ZN10IrcPaletteE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject IrcPalette::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcPaletteE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcPaletteE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10IrcPaletteE_t>.metaTypes,
    nullptr
} };

void IrcPalette::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IrcPalette *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->white(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->black(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->blue(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->green(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->red(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->brown(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->purple(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->orange(); break;
        case 8: *reinterpret_cast<QString*>(_v) = _t->yellow(); break;
        case 9: *reinterpret_cast<QString*>(_v) = _t->lightGreen(); break;
        case 10: *reinterpret_cast<QString*>(_v) = _t->cyan(); break;
        case 11: *reinterpret_cast<QString*>(_v) = _t->lightCyan(); break;
        case 12: *reinterpret_cast<QString*>(_v) = _t->lightBlue(); break;
        case 13: *reinterpret_cast<QString*>(_v) = _t->pink(); break;
        case 14: *reinterpret_cast<QString*>(_v) = _t->gray(); break;
        case 15: *reinterpret_cast<QString*>(_v) = _t->lightGray(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setWhite(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setBlack(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setBlue(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setGreen(*reinterpret_cast<QString*>(_v)); break;
        case 4: _t->setRed(*reinterpret_cast<QString*>(_v)); break;
        case 5: _t->setBrown(*reinterpret_cast<QString*>(_v)); break;
        case 6: _t->setPurple(*reinterpret_cast<QString*>(_v)); break;
        case 7: _t->setOrange(*reinterpret_cast<QString*>(_v)); break;
        case 8: _t->setYellow(*reinterpret_cast<QString*>(_v)); break;
        case 9: _t->setLightGreen(*reinterpret_cast<QString*>(_v)); break;
        case 10: _t->setCyan(*reinterpret_cast<QString*>(_v)); break;
        case 11: _t->setLightCyan(*reinterpret_cast<QString*>(_v)); break;
        case 12: _t->setLightBlue(*reinterpret_cast<QString*>(_v)); break;
        case 13: _t->setPink(*reinterpret_cast<QString*>(_v)); break;
        case 14: _t->setGray(*reinterpret_cast<QString*>(_v)); break;
        case 15: _t->setLightGray(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *IrcPalette::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IrcPalette::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10IrcPaletteE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IrcPalette::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
