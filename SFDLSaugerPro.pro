QT       += core widgets gui network ftp xml multimedia

TARGET = SFDLSaugerPro
TEMPLATE = app

include(SingleApplication/singleapplication.pri)
DEFINES += QAPPLICATION_CLASS=QApplication

SOURCES += \
        main.cpp \
        sfdlsauger.cpp \
        sfdl.cpp \
        ftplistfiles.cpp \
        ftpdownload.cpp \
        about.cpp \
        settings.cpp \
        crc32.cpp \
        unrar.cpp \
        qaesencryption.cpp

HEADERS += \
        sfdlsauger.h \
        sfdl.h \
        ftplistfiles.h \
        ftpdownload.h \
        data.h \
        about.h \
        settings.h \
        crc32.h \
        unrar.h \
        qaesencryption.h

FORMS += \
        sfdlsauger.ui \
        about.ui \
        settings.ui

RESOURCES += \
        gfx.qrc

CONFIG += C++14 crypto
VERSION = 1.3.11

QMAKE_TARGET_COMPANY = "GrafSauger"
QMAKE_TARGET_PRODUCT = "SFDLSauger Pro"
QMAKE_TARGET_DESCRIPTION = "SFDLSauger Pro - SFDL Downloader [4] MLCBoard.com"
QMAKE_TARGET_COPYRIGHT = "2019 - 2023 by GrafSauger"

DEFINES += APP_VERSION=\\\"$$VERSION\\\"
DEFINES += QMAKE_TARGET_COMPANY=\\\"$$QMAKE_TARGET_COMPANY\\\"
DEFINES += APP_PRODUCT=\"\\\"$$QMAKE_TARGET_PRODUCT\\\"\"
DEFINES += QMAKE_TARGET_DESCRIPTION=\"\\\"$$QMAKE_TARGET_DESCRIPTION\\\"\"
DEFINES += QMAKE_TARGET_COPYRIGHT=\"\\\"$$QMAKE_TARGET_COPYRIGHT\\\"\"

win32 {
    RC_ICONS = icon.ico
}

macx {
    ICON = icon.icns
}


