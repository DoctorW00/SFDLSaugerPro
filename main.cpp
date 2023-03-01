#include "sfdlsauger.h"
#include <singleapplication.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // Allow secondary instances
    SingleApplication app(argc, argv, true);

    // If this is a secondary instance
    if(app.isSecondary())
    {
        app.sendMessage(app.arguments().join('|').toUtf8());
        return 0;
    }

    SFDLSauger w;
    QObject::connect(&app, &SingleApplication::receivedMessage, &w, &SFDLSauger::loadSFDLConsol);

    QPixmap pixmap(":/gfx/icon.png");
    QSplashScreen splash(pixmap);
    splash.show();
    app.processEvents();

    #if defined(Q_OS_WIN)
    QSettings set("HKEY_CURRENT_USER\\SOFTWARE\\CLASSES", QSettings::NativeFormat);
    set.setValue(".sfdl/DefaultIcon/.",QDir::toNativeSeparators(qApp->applicationFilePath()));
    set.setValue(".sfdl/.","grafsauger.sfdlsauger.pro");
    set.setValue("grafsauger.sfdlsauger.pro/shell/open/command/.", QDir::toNativeSeparators(qApp->applicationFilePath()) + " %1");
    // set.endGroup();

    QSettings reg("HKEY_CURRENT_USER\\SOFTWARE\\Classes\\.sfdl\\DefaultIcon", QSettings::NativeFormat);
    reg.setValue("Default", QDir::toNativeSeparators(qApp->applicationFilePath() + "/") + "icon.ico");
    #endif

    app.setOrganizationName(QMAKE_TARGET_COMPANY);
    app.setOrganizationDomain("https://mlcboard.com/");
    app.setApplicationName(APP_PRODUCT);
    app.setApplicationVersion(APP_VERSION);

    QCommandLineParser parser;
    parser.setApplicationDescription("SFDLSauger Pro Console");
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption sfdlOption(QStringList() << "f" << "SFDL",
                QCoreApplication::translate("main", "Open SFDL File(s)"),
                QCoreApplication::translate("main", "SFDL File"));
    parser.addOption(sfdlOption);
    parser.process(app);

    foreach(QString file, parser.values(sfdlOption))
    {
        if(!file.isEmpty())
        {
            w.loadSFDL(file);
        }
    }

    if(app.arguments().count() == 2)
    {
        w.loadSFDL(app.arguments().at(1));
    }

    w.setWindowIcon(QIcon("icon.ico"));
    w.setWindowTitle("SFDLSauger Pro");

    splash.hide();
    w.show();

    return app.exec();
}
