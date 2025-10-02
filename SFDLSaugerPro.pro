QT += core widgets gui network ftp xml multimedia

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
        qaesencryption.cpp \
        unrarextractor.cpp

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
        qaesencryption.h \
        unrarextractor.h

FORMS += \
        sfdlsauger.ui \
        about.ui \
        settings.ui

RESOURCES += \
        gfx.qrc

# unrar start ->
SOURCES += $$files($$PWD/unrar/*.cpp)
HEADERS += $$files($$PWD/unrar/*.hpp)
INCLUDEPATH += $$PWD/unrar
unix {
    LIBS += -L$$PWD/unrar -lunrar
}
win32 {
    LIBS += -L$$PWD/unrardll -lunrar
}
DEFINES += RARDLL
unix {
    SOURCES -= $$files($$PWD/unrar/win*.cpp)
    SOURCES -= $$files($$PWD/unrar/isnt.cpp)
    SOURCES -= $$files($$PWD/unrar/motw.cpp)
    DEFINES += _UNIX _LARGEFILE_SOURCE _FILE_OFFSET_BITS=64
    QMAKE_CXXFLAGS += -Wno-zero-as-null-pointer-constant
}
win32 {
    SOURCES -= $$files($$PWD/unrar/posix.cpp)
    DEFINES += _WIN_ALL WINVER=0x0601 _UNICODE UNICODE
}
# <- unrar end

CONFIG += C++14 crypto
VERSION = 1.4.1

QMAKE_TARGET_COMPANY = "GrafSauger"
QMAKE_TARGET_PRODUCT = "SFDLSauger Pro"
QMAKE_TARGET_DESCRIPTION = "SFDLSauger Pro - SFDL Downloader [4] MLCBoard.com"
QMAKE_TARGET_COPYRIGHT = "2019 - 2025 by GrafSauger"

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



