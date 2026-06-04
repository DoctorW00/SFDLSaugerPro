QT += core widgets gui network ftp xml multimedia

win32 {
    QT += winextras
}

TARGET = SFDLSaugerPro
TEMPLATE = app

DEFINES += QT_NO_WARNING_OUTPUT

include(SingleApplication/singleapplication.pri)
include(libcommuni/src/src.pri)
DEFINES += QAPPLICATION_CLASS=QApplication

SOURCES += \
        commandworker.cpp \
        filewatcher.cpp \
        main.cpp \
        notificationclient.cpp \
        sfdlsauger.cpp \
        sfdl.cpp \
        ftplistfiles.cpp \
        ftpdownload.cpp \
        about.cpp \
        settings.cpp \
        crc32.cpp \
        taskbarprogressmanager.cpp \
        unrar.cpp \
        qaesencryption.cpp \
        unrarextractor.cpp \
        chatirc.cpp \
        livelogs.cpp \
        webserver.cpp

HEADERS += \
        FileOrganizer.h \
        commandworker.h \
        filewatcher.h \
        httplib.h \
        notificationclient.h \
        sfdlsauger.h \
        sfdl.h \
        ftplistfiles.h \
        ftpdownload.h \
        data.h \
        about.h \
        settings.h \
        crc32.h \
        taskbarprogressmanager.h \
        unrar.h \
        qaesencryption.h \
        unrarextractor.h \
        chatirc.h \
        livelogs.h \
        webserver.h

FORMS += \
        sfdlsauger.ui \
        about.ui \
        settings.ui \
        chatirc.ui \
        livelogs.ui

RESOURCES += \
        gfx.qrc

QMAKE_CXXFLAGS -= -Werror

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
    QMAKE_CXXFLAGS += -Wno-dangling-else
}
win32 {
    SOURCES -= $$files($$PWD/unrar/posix.cpp)
    DEFINES += _WIN_ALL WINVER=0x0601 _UNICODE UNICODE
}
# <- unrar end

CONFIG += C++14 crypto thread
VERSION = 1.6.0

QMAKE_TARGET_COMPANY = "GrafSauger"
QMAKE_TARGET_PRODUCT = "SFDLSauger Pro"
QMAKE_TARGET_DESCRIPTION = "SFDLSauger Pro - SFDL Downloader [4] MLCBoard.com"
QMAKE_TARGET_COPYRIGHT = "2019 - 2026 by GrafSauger"

DEFINES += APP_VERSION=\\\"$$VERSION\\\"
DEFINES += QMAKE_TARGET_COMPANY=\\\"$$QMAKE_TARGET_COMPANY\\\"
DEFINES += APP_PRODUCT=\"\\\"$$QMAKE_TARGET_PRODUCT\\\"\"
DEFINES += QMAKE_TARGET_DESCRIPTION=\"\\\"$$QMAKE_TARGET_DESCRIPTION\\\"\"
DEFINES += QMAKE_TARGET_COPYRIGHT=\"\\\"$$QMAKE_TARGET_COPYRIGHT\\\"\"

win32 {
    RC_ICONS = icon.ico
    QMAKE_LFLAGS += /FORCE:MULTIPLE
    CONFIG += static
    LIBS += -lws2_32 -luser32 -lshell32
}

unix {
    LIBS += -lpthread
}

macx {
    ICON = icon.icns
    QMAKE_ENTITLEMENTS = $$PWD/entitlements.plist
}

# translations start ->
TRANSLATIONS += i18n/German_de.ts \
                i18n/English_en.ts

qtPrepareTool(LRELEASE, lrelease)
qm_files.commands = $$LRELEASE ${QMAKE_FILE_IN} -qm ${QMAKE_FILE_OUT}
qm_files.input = TRANSLATIONS
qm_files.output = $$OUT_PWD/i18n/${QMAKE_FILE_BASE}.qm
qm_files.CONFIG += no_link target_predeps
QMAKE_EXTRA_COMPILERS += qm_files

QM_QM_FILES = $$replace(TRANSLATIONS, \.ts, .qm)
QM_QM_FILES = $$replace(QM_QM_FILES, i18n/, $$OUT_PWD/i18n/)

I18N_QRC = $$OUT_PWD/i18n_generated.qrc
QRC_CONTENT = "<RCC><qresource prefix=\"/i18n\">"
for(file, QM_QM_FILES) {
    baseName = $$basename(file)
    QRC_CONTENT += "<file alias=\"$$baseName\">$$file</file>"
}
QRC_CONTENT += "</qresource></RCC>"
write_file($$I18N_QRC, QRC_CONTENT)

RESOURCES += $$I18N_QRC
# <- translations end

QMAKE_PROJECT_DEPTH = 0


