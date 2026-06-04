#include "taskbarprogressmanager.h"
#include <QWidget>
#include <QApplication>
#include <QPainter>
#include <QWindow>

#ifdef Q_OS_WIN
#include <QWinTaskbarButton>
#include <QWinTaskbarProgress>
#endif

TaskbarProgressManager::TaskbarProgressManager(QWidget *parentWindow)
    : QObject(parentWindow), m_parentWindow(parentWindow)
{
    m_baseIcon = m_parentWindow->windowIcon();
    if(m_baseIcon.isNull())
    {
        m_baseIcon = qApp->windowIcon();
    }
}

TaskbarProgressManager::~TaskbarProgressManager() {}

#ifdef Q_OS_WIN
void TaskbarProgressManager::initWinTaskbar()
{
    if(!m_winButton && m_parentWindow && m_parentWindow->windowHandle())
    {
        m_winButton = new QWinTaskbarButton(this);
        m_winButton->setWindow(m_parentWindow->windowHandle());
        m_winProgress = m_winButton->progress();
        m_winProgress->setRange(0, 100);
    }
}
#endif

void TaskbarProgressManager::setProgress(int percentage)
{
    if (percentage < 0) percentage = 0;
    if (percentage > 100) percentage = 100;

#ifdef Q_OS_WIN
    initWinTaskbar();
    if(m_winProgress)
    {
        m_winProgress->setValue(percentage);
        if(!m_winProgress->isVisible())
        {
            m_winProgress->setVisible(true);
        }
    }
#else
    updateDynamicIcon(percentage);
#endif
}

void TaskbarProgressManager::clearProgress()
{
#ifdef Q_OS_WIN
    if(m_winProgress)
    {
        m_winProgress->setVisible(false);
        m_winProgress->setValue(0);
    }
#else
    m_parentWindow->setWindowIcon(m_baseIcon);
    qApp->setWindowIcon(m_baseIcon);
#endif
}

void TaskbarProgressManager::updateDynamicIcon(int percentage)
{
    QPixmap pixmap = m_baseIcon.pixmap(128, 128);
    if(pixmap.isNull())
    {
        pixmap = QPixmap(128, 128);
        pixmap.fill(Qt::transparent);
    }

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    int barHeight = pixmap.height() * 0.12;
    QRect barRect(0, pixmap.height() - barHeight, pixmap.width(), barHeight);

    painter.fillRect(barRect, QColor(40, 40, 40, 220));

    int progressWidth = (pixmap.width() * percentage) / 100;
    QRect progressRect(0, pixmap.height() - barHeight, progressWidth, barHeight);
    painter.fillRect(progressRect, QColor(76, 175, 80));

    painter.end();

    m_parentWindow->setWindowIcon(QIcon(pixmap));
    qApp->setWindowIcon(QIcon(pixmap));
}
