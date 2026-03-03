/********************************************************************************
** Form generated from reading UI file 'livelogs.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVELOGS_H
#define UI_LIVELOGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_LiveLogs
{
public:
    QGridLayout *gridLayout;
    QTextEdit *liveLogsText;

    void setupUi(QDialog *LiveLogs)
    {
        if (LiveLogs->objectName().isEmpty())
            LiveLogs->setObjectName("LiveLogs");
        LiveLogs->resize(600, 400);
        gridLayout = new QGridLayout(LiveLogs);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        liveLogsText = new QTextEdit(LiveLogs);
        liveLogsText->setObjectName("liveLogsText");
        liveLogsText->setAcceptDrops(false);
        liveLogsText->setFrameShape(QFrame::NoFrame);
        liveLogsText->setFrameShadow(QFrame::Plain);
        liveLogsText->setLineWidth(0);

        gridLayout->addWidget(liveLogsText, 0, 0, 1, 1);


        retranslateUi(LiveLogs);

        QMetaObject::connectSlotsByName(LiveLogs);
    } // setupUi

    void retranslateUi(QDialog *LiveLogs)
    {
        LiveLogs->setWindowTitle(QCoreApplication::translate("LiveLogs", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LiveLogs: public Ui_LiveLogs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVELOGS_H
