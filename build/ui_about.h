/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName("About");
        About->resize(600, 320);
        label = new QLabel(About);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setGeometry(QRect(20, 90, 64, 64));
        label->setScaledContents(true);
        label_2 = new QLabel(About);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 10, 181, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label_2->setFont(font);
        label_3 = new QLabel(About);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 60, 480, 220));
        QFont font1;
        font1.setPointSize(10);
        label_3->setFont(font1);

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "\303\234ber SFDLSauger Pro", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("About", "SFDLSauger Pro", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
