#include "thememanager.h"

#include <QApplication>
#include <QEvent>
#include <QFile>
#include <QGuiApplication>
#include <QHash>
#include <QSettings>
#include <QStyle>
#include <QStyleFactory>
#include <QStyleHints>
#include <QTimer>
#include <QWidget>
#include <QWindow>

#ifdef Q_OS_WIN
    #include <windows.h>
    #include <QLibrary>
#endif
#ifdef Q_OS_MAC
    #include <QProcess>
#endif

ThemeManager *ThemeManager::instance()
{
    static ThemeManager *inst = new ThemeManager(qApp);
    return inst;
}

ThemeManager::ThemeManager(QObject *parent) : QObject(parent)
{
}

void ThemeManager::init()
{
    if(m_initialised)
    {
        return;
    }
    m_initialised = true;

    m_defaultStyle = qApp->style()->objectName();
    m_defaultPalette = qApp->palette();

    QSettings config(QSettings::IniFormat, QSettings::UserScope, "SFDLSaugerPro", "config");
    int stored = config.value("appearance/theme", static_cast<int>(Auto)).toInt();
    m_mode = (stored >= Auto && stored <= Dark) ? static_cast<Mode>(stored) : Auto;

    m_lastSystemDark = systemPrefersDark();

#ifdef Q_OS_WIN
    qApp->installEventFilter(this);
#endif

#if QT_VERSION >= QT_VERSION_CHECK(6, 5, 0)
    connect(QGuiApplication::styleHints(), &QStyleHints::colorSchemeChanged, this, [this]() {
        pollSystemTheme();
    });
#elif defined(Q_OS_WIN)
    m_pollTimer = new QTimer(this);
    m_pollTimer->setInterval(2000);
    connect(m_pollTimer, &QTimer::timeout, this, &ThemeManager::pollSystemTheme);
    m_pollTimer->start();
#endif

    apply(true);
}

void ThemeManager::setMode(Mode mode)
{
    m_mode = mode;

    QSettings config(QSettings::IniFormat, QSettings::UserScope, "SFDLSaugerPro", "config");
    config.setValue("appearance/theme", static_cast<int>(mode));
    config.sync();

    if(mode == Auto)
    {
        m_lastSystemDark = systemPrefersDark();
    }
    apply();
}

bool ThemeManager::systemPrefersDark() const
{
#if QT_VERSION >= QT_VERSION_CHECK(6, 5, 0)
    return QGuiApplication::styleHints()->colorScheme() == Qt::ColorScheme::Dark;
#elif defined(Q_OS_WIN)
    QSettings s("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", QSettings::NativeFormat);
    return s.value("AppsUseLightTheme", 1).toInt() == 0;
#else
    #ifdef Q_OS_MAC
    QProcess proc;
    proc.start("defaults", QStringList() << "read" << "-g" << "AppleInterfaceStyle");
    if(proc.waitForFinished(1000))
    {
        return proc.readAllStandardOutput().trimmed().compare("Dark", Qt::CaseInsensitive) == 0;
    }
    #endif
    const QPalette &pal = m_defaultPalette;
    return pal.color(QPalette::WindowText).lightness() > pal.color(QPalette::Window).lightness();
#endif
}

void ThemeManager::pollSystemTheme()
{
    const bool sysDark = systemPrefersDark();
    if(sysDark == m_lastSystemDark)
    {
        return;
    }
    m_lastSystemDark = sysDark;

    if(m_mode == Auto)
    {
        apply();
    }
}

void ThemeManager::apply(bool force)
{
    const bool dark = (m_mode == Dark) || (m_mode == Auto && m_lastSystemDark);
    if(!force && dark == m_dark)
    {
        return;
    }
    m_dark = dark;

    if(dark)
    {
        if(QStyle *fusion = QStyleFactory::create("Fusion"))
        {
            QApplication::setStyle(fusion);
        }
        QApplication::setPalette(darkPalette());
        m_customised = true;
    }
    else if(m_customised)
    {
        if(!m_defaultStyle.isEmpty())
        {
            if(QStyle *orig = QStyleFactory::create(m_defaultStyle))
            {
                QApplication::setStyle(orig);
            }
        }
        QApplication::setPalette(m_defaultPalette);
        m_customised = false;
    }

    qApp->setStyleSheet(buildStyleSheet(dark));

    const QList<QWidget *> widgets = QApplication::topLevelWidgets();
    for(QWidget *w : widgets)
    {
        applyNativeTitleBar(w, dark);
    }

    emit themeChanged(dark);
}

QPalette ThemeManager::darkPalette() const
{
    QPalette p;

    const QColor window(45, 45, 48);
    const QColor base(30, 30, 30);
    const QColor altBase(37, 37, 38);
    const QColor button(60, 60, 63);
    const QColor text(230, 230, 230);
    const QColor disabled(127, 127, 127);
    const QColor highlight(42, 130, 218);

    p.setColor(QPalette::Window, window);
    p.setColor(QPalette::WindowText, text);
    p.setColor(QPalette::Base, base);
    p.setColor(QPalette::AlternateBase, altBase);
    p.setColor(QPalette::ToolTipBase, QColor(60, 60, 63));
    p.setColor(QPalette::ToolTipText, text);
    p.setColor(QPalette::Text, text);
    p.setColor(QPalette::Button, button);
    p.setColor(QPalette::ButtonText, text);
    p.setColor(QPalette::BrightText, QColor(255, 85, 85));
    p.setColor(QPalette::Link, QColor(90, 169, 255));
    p.setColor(QPalette::LinkVisited, QColor(180, 140, 255));
    p.setColor(QPalette::Highlight, highlight);
    p.setColor(QPalette::HighlightedText, Qt::white);
    p.setColor(QPalette::PlaceholderText, QColor(138, 138, 138));

    // 3D-Kanten (Fusion)
    p.setColor(QPalette::Light, QColor(74, 74, 77));
    p.setColor(QPalette::Midlight, QColor(64, 64, 67));
    p.setColor(QPalette::Mid, QColor(51, 51, 54));
    p.setColor(QPalette::Dark, QColor(26, 26, 26));
    p.setColor(QPalette::Shadow, Qt::black);

    // deaktivierte Elemente
    p.setColor(QPalette::Disabled, QPalette::WindowText, disabled);
    p.setColor(QPalette::Disabled, QPalette::Text, disabled);
    p.setColor(QPalette::Disabled, QPalette::ButtonText, disabled);
    p.setColor(QPalette::Disabled, QPalette::Highlight, QColor(80, 80, 80));
    p.setColor(QPalette::Disabled, QPalette::HighlightedText, disabled);

    return p;
}

QString ThemeManager::gfx(const QString &name, bool dark)
{
    if(dark)
    {
        const QString darkVariant = QString(":/gfx/%1_dark.png").arg(name);
        if(QFile::exists(darkVariant))
        {
            return darkVariant;
        }
    }
    return QString(":/gfx/%1.png").arg(name);
}

QString ThemeManager::buildStyleSheet(bool dark) const
{
    QHash<QString, QString> c;

    if(dark)
    {
        c["menuBar"]     = "background: #2d2d30 url(" + gfx("menubg", true) + ") repeat-x; color: #e6e6e6;";
        c["menuBarSel"]  = "background: #3e3e42; color: #ffffff;";
        c["splitterBg"]  = "#2d2d30";
        c["logBg"]       = "#1e1e1e";
        c["paneBg"]      = "#252526";
        c["paneBorder"]  = "#555558";
        c["tabBorder"]   = "#555558";
        c["tabSel"]      = "#252526";
        c["tabUnsel"]    = "#323235";
        c["tabHover"]    = "#45454a";
        c["tbStop0"]     = "#48484c";
        c["tbStop1"]     = "#434347";
        c["tbStop2"]     = "#3e3e42";
        c["tbStop3"]     = "#38383b";
        c["tbText"]      = "color: #e6e6e6;";
        c["barBg"]       = "#1e1e1e";
        c["barBorder"]   = "#8a2a2a";
        c["barText"]     = "color: #e6e6e6;";
        c["rlsBg"]       = "#3a3826";
        c["rlsBorder"]   = "#55523a";
        c["rlsText"]     = "color: #f0e9b8;";
        c["toolbarBg"]   = "#2d2d30";
        c["extras"]      = "QToolTip { color: #e6e6e6; background-color: #3c3c3f; border: 1px solid #5a5a5e; }";
    }
    else
    {
        c["menuBar"]     = "background: #a2a2a2 url(" + gfx("menubg", false) + ") repeat-x; color: #f1f1f1;";
        c["menuBarSel"]  = "color: black;";
        c["splitterBg"]  = "#FFFFFF";
        c["logBg"]       = "#e4e4e4";
        c["paneBg"]      = "#ffffff";
        c["paneBorder"]  = "black";
        c["tabBorder"]   = "#2d2d2d";
        c["tabSel"]      = "white";
        c["tabUnsel"]    = "silver";
        c["tabHover"]    = "#999";
        c["tbStop0"]     = "#E1E1E1";
        c["tbStop1"]     = "#DDDDDD";
        c["tbStop2"]     = "#D8D8D8";
        c["tbStop3"]     = "#D3D3D3";
        c["tbText"]      = "";
        c["barBg"]       = "white";
        c["barBorder"]   = "#420000";
        c["barText"]     = "";
        c["rlsBg"]       = "#ffffeb";
        c["rlsBorder"]   = "#f0f0f0";
        c["rlsText"]     = "";
        c["toolbarBg"]   = "#f0f0f0";
        c["extras"]      = "";
    }

    // c["splitterImg"]  = gfx("splitter", dark);
    // c["splitterImg2"] = gfx("splitter2", dark);
    c["splitterImg"]  = gfx("splitter_t", dark);
    c["splitterImg2"] = gfx("splitter2_t", dark);
    c["tabBgImg"]     = gfx("tabbackground", dark);
    c["TW"]           = "QTabWidget#tabWidget";

    QString css = QString::fromLatin1(R"CSS(
/* ---------- Menueleiste ---------- */
QMenuBar { @menuBar@ }
QMenuBar::item:selected { @menuBarSel@ }

/* ---------- Splitter ---------- */
QSplitter[role="mainSplitter"]::handle {
    background: @splitterBg@ url(@splitterImg@) center no-repeat;
}
QSplitter#splitter_2::handle {
    background: @splitterBg@ url(@splitterImg@) center no-repeat;
}
QSplitter#splitter_2::handle:horizontal {
    background: @splitterBg@ url(@splitterImg2@) center no-repeat;
}

/* ---------- Haupt-Log ---------- */
QTextEdit#textEdit { border: none; background: @logBg@; }

/* ---------- Tabs ---------- */
@TW@::pane {
    border: none;
    background: @paneBg@ url(@tabBgImg@) center no-repeat;
    border-top: 1px solid @paneBorder@;
}
@TW@::tab-bar { background: @paneBg@; }
@TW@::tab-bar:top { top: 1px; }
@TW@::tab-bar:bottom { bottom: 1px; }
@TW@::tab-bar:left { right: 1px; }
@TW@::tab-bar:right { left: 1px; }
@TW@ QTabBar::tab { border: 1px solid @tabBorder@; }
@TW@ QTabBar::tab:selected { background: @tabSel@; }
@TW@ QTabBar::tab:!selected { background: @tabUnsel@; }
@TW@ QTabBar::tab:!selected:hover { background: @tabHover@; }
@TW@ QTabBar::tab:top:!selected { margin-top: 3px; }
@TW@ QTabBar::tab:bottom:!selected { margin-bottom: 3px; }
@TW@ QTabBar::tab:top, @TW@ QTabBar::tab:bottom {
    min-width: 8ex;
    margin-right: -1px;
    padding: 5px 10px 5px 10px;
}
@TW@ QTabBar::tab:top:selected { border-bottom-color: none; }
@TW@ QTabBar::tab:bottom:selected { border-top-color: none; }
@TW@ QTabBar::tab:top:last, @TW@ QTabBar::tab:bottom:last,
@TW@ QTabBar::tab:top:only-one, @TW@ QTabBar::tab:bottom:only-one {
    margin-right: 0;
}
@TW@ QTabBar::tab:left:!selected { margin-right: 3px; }
@TW@ QTabBar::tab:right:!selected { margin-left: 3px; }
@TW@ QTabBar::tab:left, @TW@ QTabBar::tab:right {
    min-height: 8ex;
    margin-bottom: -1px;
    padding: 10px 5px 10px 5px;
}
@TW@ QTabBar::tab:left:selected { border-left-color: none; }
@TW@ QTabBar::tab:right:selected { border-right-color: none; }
@TW@ QTabBar::tab:left:last, @TW@ QTabBar::tab:right:last,
@TW@ QTabBar::tab:left:only-one, @TW@ QTabBar::tab:right:only-one {
    margin-bottom: 0;
}

/* ---------- Einstellungen: ToolBox ---------- */
QToolBox::tab {
    font-weight: bold;
    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                stop: 0 @tbStop0@, stop: 0.4 @tbStop1@, stop: 0.5 @tbStop2@, stop: 1.0 @tbStop3@);
    @tbText@
}

/* ---------- Download-Tabs ---------- */
QToolBar#toolbar { background: @toolbarBg@; }

QLabel[role="releaseTitle"] {
    background: @rlsBg@;
    border: 1px solid @rlsBorder@;
    padding: 3px;
    @rlsText@
}

QProgressBar[role="fileBar"] {
    border: 1px solid @barBorder@;
    margin: 1px;
    border-radius: 5px;
    text-align: center;
    @barText@
}
QProgressBar[role="fileBar"]::chunk { background-color: #c52222; width: 1px; margin: 0px; }

QProgressBar#mProgBar {
    background: @barBg@;
    height: 30px;
    margin: 0 5px 0 5px;
    border: 1px solid @barBorder@;
    border-radius: 5px;
    text-align: center;
    @barText@
}
QProgressBar#mProgBar::chunk { background-color: #c52222; width: 1px; margin: 0px; }

@extras@
)CSS");

    for(auto it = c.constBegin(); it != c.constEnd(); ++it)
    {
        css.replace("@" + it.key() + "@", it.value());
    }
    return css;
}

bool ThemeManager::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::Show && obj->isWidgetType())
    {
        QWidget *w = static_cast<QWidget *>(obj);
        if(w->isWindow())
        {
            applyNativeTitleBar(w, m_dark);
        }
    }
    return QObject::eventFilter(obj, event);
}

void ThemeManager::applyNativeTitleBar(QWidget *w, bool dark) const
{
#ifdef Q_OS_WIN
    if(!w || !w->isWindow())
    {
        return;
    }
    QWindow *win = w->windowHandle();
    if(!win)
    {
        return;
    }

    typedef HRESULT (WINAPI *DwmSetWindowAttributeFn)(HWND, DWORD, LPCVOID, DWORD);
    static DwmSetWindowAttributeFn setAttr =
        reinterpret_cast<DwmSetWindowAttributeFn>(QLibrary::resolve("dwmapi", "DwmSetWindowAttribute"));
    if(!setAttr)
    {
        return;
    }

    HWND hwnd = reinterpret_cast<HWND>(win->winId());
    const BOOL value = dark ? TRUE : FALSE;
    if(FAILED(setAttr(hwnd, 20, &value, sizeof(value))))
    {
        setAttr(hwnd, 19, &value, sizeof(value));
    }

    if(w->isVisible())
    {
        SetWindowPos(hwnd, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
    }
#else
    Q_UNUSED(w)
    Q_UNUSED(dark)
#endif
}
