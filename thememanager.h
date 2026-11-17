#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QObject>
#include <QPalette>
#include <QString>

class QTimer;
class QWidget;

class ThemeManager : public QObject
{
    Q_OBJECT

public:
    enum Mode { Auto = 0, Light = 1, Dark = 2 };
    Q_ENUM(Mode)

    static ThemeManager *instance();

    void init();

    void setMode(Mode mode);
    Mode mode() const { return m_mode; }
    bool isDark() const { return m_dark; }
    bool systemPrefersDark() const;

signals:
    void themeChanged(bool dark);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    explicit ThemeManager(QObject *parent = nullptr);

    void apply(bool force = false);
    void pollSystemTheme();
    QPalette darkPalette() const;
    QString buildStyleSheet(bool dark) const;
    static QString gfx(const QString &name, bool dark);
    void applyNativeTitleBar(QWidget *w, bool dark) const;

    Mode m_mode = Auto;
    bool m_dark = false;
    bool m_initialised = false;
    bool m_customised = false;
    bool m_lastSystemDark = false;
    QString m_defaultStyle;
    QPalette m_defaultPalette;
    QTimer *m_pollTimer = nullptr;
};

#endif // THEMEMANAGER_H
