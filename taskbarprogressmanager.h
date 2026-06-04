#ifndef TASKBARPROGRESSMANAGER_H
#define TASKBARPROGRESSMANAGER_H

#include <QObject>
#include <QIcon>
#include <QPixmap>

#ifdef Q_OS_WIN
class QWinTaskbarButton;
class QWinTaskbarProgress;
#endif

class QWidget;

class TaskbarProgressManager : public QObject
{
    Q_OBJECT
public:
    explicit TaskbarProgressManager(QWidget *parentWindow);
    ~TaskbarProgressManager();

    void setProgress(int percentage);
    void clearProgress();

private:
    QWidget *m_parentWindow;
    QIcon m_baseIcon;

#ifdef Q_OS_WIN
    QWinTaskbarButton *m_winButton = nullptr;
    QWinTaskbarProgress *m_winProgress = nullptr;
    void initWinTaskbar();
#endif

    void updateDynamicIcon(int percentage);
};

#endif // TASKBARPROGRESSMANAGER_H
