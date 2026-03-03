/****************************************************************************
** Meta object code from reading C++ file 'sfdlsauger.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../sfdlsauger.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sfdlsauger.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10SFDLSaugerE_t {};
} // unnamed namespace

template <> constexpr inline auto SFDLSauger::qt_create_metaobjectdata<qt_meta_tag_ZN10SFDLSaugerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SFDLSauger",
        "logAdded",
        "",
        "htmlLine",
        "doubleClicked",
        "loadSFDL",
        "file",
        "loadSFDLConsol",
        "instanceId",
        "message",
        "addLogText",
        "txt",
        "showLogMenu",
        "QPoint",
        "pos",
        "openLogsDialog",
        "addTab",
        "tabText",
        "chkSFDLData",
        "data",
        "files",
        "getSFDLData",
        "on_tabWidget_tabCloseRequested",
        "index",
        "MsgWarning",
        "label",
        "text",
        "bytes2Human",
        "filesize",
        "seconds_to_DHMS",
        "duration",
        "dragEnterEvent",
        "QDragEnterEvent*",
        "e",
        "dropEvent",
        "QDropEvent*",
        "closeEvent",
        "QCloseEvent*",
        "quitApp",
        "on_action_ffnen_triggered",
        "on_actionBeenden_triggered",
        "tabSelected",
        "on_actionLogs_anzeigen_triggered",
        "on_actionEinstellungen_triggered",
        "on_action_ber_triggered",
        "devModeSwitch",
        "checkSameDownloads",
        "name",
        "fileTableDoubleClicked",
        "row",
        "column",
        "openCloseSFDLTable",
        "openFileExplorer",
        "chkForExisitingFiles",
        "id",
        "updateTotalDownloadSize",
        "tblItemChanged",
        "QTableWidgetItem*",
        "item",
        "changeCHKBOX",
        "lock",
        "saveWindowStatus",
        "loadWindowStatus",
        "returnSubPath",
        "fullPath",
        "splitter",
        "removeDuplicateSlashes",
        "path",
        "openIRCDialog",
        "on_actionIRC_Chat_triggered",
        "startDownloadButton",
        "swapStartStopButton",
        "disableStartStopButton",
        "startDownload",
        "tabID",
        "stopDownload",
        "allDownloadsDone",
        "createSpeedreport",
        "dirFromFilePath",
        "filePath",
        "updateDownloadProgress",
        "nRow",
        "read",
        "total",
        "overwriteTime",
        "firstUpdate",
        "updateDownloadFileStatus",
        "statusMsg",
        "status",
        "downloadError",
        "error",
        "crc32Check",
        "updateCRC32",
        "crc32Data",
        "sfvCheck",
        "unrarFiles",
        "unrarProgressUpdate",
        "fileName",
        "progress",
        "unrarDeleteFiles",
        "openInFileZilla",
        "on_actionStrukturreformator_triggered"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'logAdded'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'doubleClicked'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'loadSFDL'
        QtMocHelpers::SlotData<void(QString)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Slot 'loadSFDLConsol'
        QtMocHelpers::SlotData<void(int, QByteArray)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 }, { QMetaType::QByteArray, 9 },
        }}),
        // Slot 'addLogText'
        QtMocHelpers::SlotData<void(QString)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 11 },
        }}),
        // Slot 'showLogMenu'
        QtMocHelpers::SlotData<void(const QPoint &)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 13, 14 },
        }}),
        // Slot 'openLogsDialog'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'addTab'
        QtMocHelpers::SlotData<int(QString)>(16, 2, QMC::AccessPrivate, QMetaType::Int, {{
            { QMetaType::QString, 17 },
        }}),
        // Slot 'chkSFDLData'
        QtMocHelpers::SlotData<void(QStringList, QStringList)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QStringList, 19 }, { QMetaType::QStringList, 20 },
        }}),
        // Slot 'getSFDLData'
        QtMocHelpers::SlotData<void(QStringList, QStringList)>(21, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QStringList, 19 }, { QMetaType::QStringList, 20 },
        }}),
        // Slot 'on_tabWidget_tabCloseRequested'
        QtMocHelpers::SlotData<void(int)>(22, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 23 },
        }}),
        // Slot 'MsgWarning'
        QtMocHelpers::SlotData<void(QString, QString)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 25 }, { QMetaType::QString, 26 },
        }}),
        // Slot 'bytes2Human'
        QtMocHelpers::SlotData<QString(float)>(27, 2, QMC::AccessPrivate, QMetaType::QString, {{
            { QMetaType::Float, 28 },
        }}),
        // Slot 'seconds_to_DHMS'
        QtMocHelpers::SlotData<QString(int)>(29, 2, QMC::AccessPrivate, QMetaType::QString, {{
            { QMetaType::Int, 30 },
        }}),
        // Slot 'dragEnterEvent'
        QtMocHelpers::SlotData<void(QDragEnterEvent *)>(31, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 32, 33 },
        }}),
        // Slot 'dropEvent'
        QtMocHelpers::SlotData<void(QDropEvent *)>(34, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 35, 33 },
        }}),
        // Slot 'closeEvent'
        QtMocHelpers::SlotData<void(QCloseEvent *)>(36, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 37, 33 },
        }}),
        // Slot 'quitApp'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action_ffnen_triggered'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionBeenden_triggered'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'tabSelected'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionLogs_anzeigen_triggered'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionEinstellungen_triggered'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action_ber_triggered'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'devModeSwitch'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'checkSameDownloads'
        QtMocHelpers::SlotData<QString(QString)>(46, 2, QMC::AccessPrivate, QMetaType::QString, {{
            { QMetaType::QString, 47 },
        }}),
        // Slot 'fileTableDoubleClicked'
        QtMocHelpers::SlotData<void(int, int)>(48, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 49 }, { QMetaType::Int, 50 },
        }}),
        // Slot 'openCloseSFDLTable'
        QtMocHelpers::SlotData<void()>(51, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'openFileExplorer'
        QtMocHelpers::SlotData<void()>(52, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'chkForExisitingFiles'
        QtMocHelpers::SlotData<void(QString)>(53, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 54 },
        }}),
        // Slot 'updateTotalDownloadSize'
        QtMocHelpers::SlotData<void(QString)>(55, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 54 },
        }}),
        // Slot 'tblItemChanged'
        QtMocHelpers::SlotData<void(QTableWidgetItem *)>(56, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 57, 58 },
        }}),
        // Slot 'changeCHKBOX'
        QtMocHelpers::SlotData<void(QString, bool)>(59, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 54 }, { QMetaType::Bool, 60 },
        }}),
        // Slot 'saveWindowStatus'
        QtMocHelpers::SlotData<void()>(61, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'loadWindowStatus'
        QtMocHelpers::SlotData<void()>(62, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'returnSubPath'
        QtMocHelpers::SlotData<QString(QString, QString)>(63, 2, QMC::AccessPrivate, QMetaType::QString, {{
            { QMetaType::QString, 64 }, { QMetaType::QString, 65 },
        }}),
        // Slot 'removeDuplicateSlashes'
        QtMocHelpers::SlotData<QString(QString)>(66, 2, QMC::AccessPrivate, QMetaType::QString, {{
            { QMetaType::QString, 67 },
        }}),
        // Slot 'openIRCDialog'
        QtMocHelpers::SlotData<void()>(68, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionIRC_Chat_triggered'
        QtMocHelpers::SlotData<void()>(69, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'startDownloadButton'
        QtMocHelpers::SlotData<void()>(70, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'swapStartStopButton'
        QtMocHelpers::SlotData<void(QString)>(71, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 54 },
        }}),
        // Slot 'disableStartStopButton'
        QtMocHelpers::SlotData<void(QString)>(72, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 54 },
        }}),
        // Slot 'startDownload'
        QtMocHelpers::SlotData<void(QString)>(73, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 74 },
        }}),
        // Slot 'stopDownload'
        QtMocHelpers::SlotData<void()>(75, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'allDownloadsDone'
        QtMocHelpers::SlotData<bool(QString)>(76, 2, QMC::AccessPrivate, QMetaType::Bool, {{
            { QMetaType::QString, 54 },
        }}),
        // Slot 'createSpeedreport'
        QtMocHelpers::SlotData<void(QString)>(77, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 54 },
        }}),
        // Slot 'dirFromFilePath'
        QtMocHelpers::SlotData<QStringList(QString)>(78, 2, QMC::AccessPrivate, QMetaType::QStringList, {{
            { QMetaType::QString, 79 },
        }}),
        // Slot 'updateDownloadProgress'
        QtMocHelpers::SlotData<void(QString, int, qint64, qint64, bool, bool)>(80, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 74 }, { QMetaType::Int, 81 }, { QMetaType::LongLong, 82 }, { QMetaType::LongLong, 83 },
            { QMetaType::Bool, 84 }, { QMetaType::Bool, 85 },
        }}),
        // Slot 'updateDownloadFileStatus'
        QtMocHelpers::SlotData<void(QString, int, QString, int)>(86, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 74 }, { QMetaType::Int, 81 }, { QMetaType::QString, 87 }, { QMetaType::Int, 88 },
        }}),
        // Slot 'downloadError'
        QtMocHelpers::SlotData<void(QString)>(89, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 90 },
        }}),
        // Slot 'crc32Check'
        QtMocHelpers::SlotData<void(QString)>(91, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 54 },
        }}),
        // Slot 'updateCRC32'
        QtMocHelpers::SlotData<void(QString, int, QString)>(92, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 54 }, { QMetaType::Int, 81 }, { QMetaType::QString, 93 },
        }}),
        // Slot 'sfvCheck'
        QtMocHelpers::SlotData<void(QString)>(94, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 54 },
        }}),
        // Slot 'unrarFiles'
        QtMocHelpers::SlotData<void(QString)>(95, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 54 },
        }}),
        // Slot 'unrarProgressUpdate'
        QtMocHelpers::SlotData<void(QString, QString, int)>(96, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 54 }, { QMetaType::QString, 97 }, { QMetaType::Int, 98 },
        }}),
        // Slot 'unrarDeleteFiles'
        QtMocHelpers::SlotData<void(QString)>(99, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 54 },
        }}),
        // Slot 'openInFileZilla'
        QtMocHelpers::SlotData<void()>(100, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionStrukturreformator_triggered'
        QtMocHelpers::SlotData<void()>(101, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SFDLSauger, qt_meta_tag_ZN10SFDLSaugerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SFDLSauger::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10SFDLSaugerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10SFDLSaugerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10SFDLSaugerE_t>.metaTypes,
    nullptr
} };

void SFDLSauger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SFDLSauger *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->logAdded((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->doubleClicked(); break;
        case 2: _t->loadSFDL((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->loadSFDLConsol((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 4: _t->addLogText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->showLogMenu((*reinterpret_cast<std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 6: _t->openLogsDialog(); break;
        case 7: { int _r = _t->addTab((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->chkSFDLData((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 9: _t->getSFDLData((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 10: _t->on_tabWidget_tabCloseRequested((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->MsgWarning((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 12: { QString _r = _t->bytes2Human((*reinterpret_cast<std::add_pointer_t<float>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->seconds_to_DHMS((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->dragEnterEvent((*reinterpret_cast<std::add_pointer_t<QDragEnterEvent*>>(_a[1]))); break;
        case 15: _t->dropEvent((*reinterpret_cast<std::add_pointer_t<QDropEvent*>>(_a[1]))); break;
        case 16: _t->closeEvent((*reinterpret_cast<std::add_pointer_t<QCloseEvent*>>(_a[1]))); break;
        case 17: _t->quitApp(); break;
        case 18: _t->on_action_ffnen_triggered(); break;
        case 19: _t->on_actionBeenden_triggered(); break;
        case 20: _t->tabSelected(); break;
        case 21: _t->on_actionLogs_anzeigen_triggered(); break;
        case 22: _t->on_actionEinstellungen_triggered(); break;
        case 23: _t->on_action_ber_triggered(); break;
        case 24: _t->devModeSwitch(); break;
        case 25: { QString _r = _t->checkSameDownloads((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->fileTableDoubleClicked((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 27: _t->openCloseSFDLTable(); break;
        case 28: _t->openFileExplorer(); break;
        case 29: _t->chkForExisitingFiles((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->updateTotalDownloadSize((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->tblItemChanged((*reinterpret_cast<std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 32: _t->changeCHKBOX((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2]))); break;
        case 33: _t->saveWindowStatus(); break;
        case 34: _t->loadWindowStatus(); break;
        case 35: { QString _r = _t->returnSubPath((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 36: { QString _r = _t->removeDuplicateSlashes((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 37: _t->openIRCDialog(); break;
        case 38: _t->on_actionIRC_Chat_triggered(); break;
        case 39: _t->startDownloadButton(); break;
        case 40: _t->swapStartStopButton((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 41: _t->disableStartStopButton((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 42: _t->startDownload((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 43: _t->stopDownload(); break;
        case 44: { bool _r = _t->allDownloadsDone((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 45: _t->createSpeedreport((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 46: { QStringList _r = _t->dirFromFilePath((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QStringList*>(_a[0]) = std::move(_r); }  break;
        case 47: _t->updateDownloadProgress((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qint64>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<qint64>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[6]))); break;
        case 48: _t->updateDownloadFileStatus((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[4]))); break;
        case 49: _t->downloadError((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 50: _t->crc32Check((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 51: _t->updateCRC32((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3]))); break;
        case 52: _t->sfvCheck((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 53: _t->unrarFiles((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 54: _t->unrarProgressUpdate((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3]))); break;
        case 55: _t->unrarDeleteFiles((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 56: _t->openInFileZilla(); break;
        case 57: _t->on_actionStrukturreformator_triggered(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SFDLSauger::*)(const QString & )>(_a, &SFDLSauger::logAdded, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SFDLSauger::*)()>(_a, &SFDLSauger::doubleClicked, 1))
            return;
    }
}

const QMetaObject *SFDLSauger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SFDLSauger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10SFDLSaugerE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SFDLSauger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 58)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 58;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 58)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 58;
    }
    return _id;
}

// SIGNAL 0
void SFDLSauger::logAdded(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void SFDLSauger::doubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
