/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGridLayout *gridLayout;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QCheckBox *chk_sfv;
    QPushButton *button_openUnrarPath;
    QLabel *label;
    QCheckBox *chk_unrar_del;
    QLabel *label_2;
    QFrame *line_2;
    QLabel *label_16;
    QPushButton *button_openDownloadPath;
    QProgressBar *bar_openDownloadPath;
    QCheckBox *chk_flatDownloads;
    QLabel *label_4;
    QLineEdit *line_unrar_path;
    QLabel *label_3;
    QCheckBox *chk_crc32;
    QCheckBox *chk_use_internal_unrar;
    QLineEdit *line_openDownloadPath;
    QFrame *line;
    QLabel *label_21;
    QSpacerItem *verticalSpacer;
    QCheckBox *chk_unrar;
    QFrame *line_3;
    QWidget *page_2;
    QGridLayout *gridLayout_5;
    QLabel *label_14;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_13;
    QPushButton *btn_new_password;
    QLineEdit *line_new_password;
    QPushButton *btn_del_password;
    QListWidget *list_sfdl_passwords;
    QLabel *label_12;
    QLabel *label_15;
    QWidget *page_3;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *line_proxy_port;
    QLineEdit *line_proxy_user;
    QLabel *label_7;
    QLineEdit *line_proxy_pass;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *line_proxy_host;
    QLabel *label_11;
    QWidget *page_4;
    QGridLayout *gridLayout_6;
    QPushButton *btn_new_exception;
    QListWidget *list_exceptions;
    QLabel *label_20;
    QLabel *label_19;
    QLabel *label_17;
    QPushButton *btn_del_exception;
    QLineEdit *line_new_exception;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_18;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(700, 500);
        gridLayout = new QGridLayout(Settings);
        gridLayout->setObjectName("gridLayout");
        toolBox = new QToolBox(Settings);
        toolBox->setObjectName("toolBox");
        QFont font;
        font.setPointSize(10);
        toolBox->setFont(font);
        toolBox->setFrameShape(QFrame::Shape::Panel);
        toolBox->setFrameShadow(QFrame::Shadow::Sunken);
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 666, 430));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName("gridLayout_2");
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_5, 16, 0, 1, 1);

        chk_sfv = new QCheckBox(page);
        chk_sfv->setObjectName("chk_sfv");

        gridLayout_2->addWidget(chk_sfv, 12, 1, 1, 1);

        button_openUnrarPath = new QPushButton(page);
        button_openUnrarPath->setObjectName("button_openUnrarPath");

        gridLayout_2->addWidget(button_openUnrarPath, 16, 2, 1, 1);

        label = new QLabel(page);
        label->setObjectName("label");
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        chk_unrar_del = new QCheckBox(page);
        chk_unrar_del->setObjectName("chk_unrar_del");

        gridLayout_2->addWidget(chk_unrar_del, 19, 1, 1, 1);

        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(8);
        label_2->setFont(font2);

        gridLayout_2->addWidget(label_2, 5, 1, 1, 2);

        line_2 = new QFrame(page);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_2, 14, 1, 1, 2);

        label_16 = new QLabel(page);
        label_16->setObjectName("label_16");
        label_16->setFont(font2);

        gridLayout_2->addWidget(label_16, 17, 1, 1, 1);

        button_openDownloadPath = new QPushButton(page);
        button_openDownloadPath->setObjectName("button_openDownloadPath");

        gridLayout_2->addWidget(button_openDownloadPath, 1, 2, 1, 1);

        bar_openDownloadPath = new QProgressBar(page);
        bar_openDownloadPath->setObjectName("bar_openDownloadPath");
        bar_openDownloadPath->setEnabled(true);
        bar_openDownloadPath->setValue(0);
        bar_openDownloadPath->setTextVisible(true);
        bar_openDownloadPath->setInvertedAppearance(false);
        bar_openDownloadPath->setTextDirection(QProgressBar::Direction::TopToBottom);

        gridLayout_2->addWidget(bar_openDownloadPath, 2, 1, 1, 1);

        chk_flatDownloads = new QCheckBox(page);
        chk_flatDownloads->setObjectName("chk_flatDownloads");

        gridLayout_2->addWidget(chk_flatDownloads, 8, 1, 1, 1);

        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);
        label_4->setScaledContents(true);
        label_4->setWordWrap(true);

        gridLayout_2->addWidget(label_4, 13, 1, 1, 2);

        line_unrar_path = new QLineEdit(page);
        line_unrar_path->setObjectName("line_unrar_path");
        line_unrar_path->setReadOnly(true);

        gridLayout_2->addWidget(line_unrar_path, 16, 1, 1, 1);

        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_3, 11, 0, 1, 1);

        chk_crc32 = new QCheckBox(page);
        chk_crc32->setObjectName("chk_crc32");

        gridLayout_2->addWidget(chk_crc32, 11, 1, 1, 1);

        chk_use_internal_unrar = new QCheckBox(page);
        chk_use_internal_unrar->setObjectName("chk_use_internal_unrar");
        chk_use_internal_unrar->setChecked(true);

        gridLayout_2->addWidget(chk_use_internal_unrar, 15, 1, 1, 1);

        line_openDownloadPath = new QLineEdit(page);
        line_openDownloadPath->setObjectName("line_openDownloadPath");
        line_openDownloadPath->setFrame(true);
        line_openDownloadPath->setReadOnly(true);

        gridLayout_2->addWidget(line_openDownloadPath, 1, 1, 1, 1);

        line = new QFrame(page);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line, 6, 1, 1, 2);

        label_21 = new QLabel(page);
        label_21->setObjectName("label_21");
        label_21->setFont(font2);

        gridLayout_2->addWidget(label_21, 9, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 20, 1, 1, 1);

        chk_unrar = new QCheckBox(page);
        chk_unrar->setObjectName("chk_unrar");

        gridLayout_2->addWidget(chk_unrar, 18, 1, 1, 1);

        line_3 = new QFrame(page);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_3, 10, 1, 1, 2);

        toolBox->addItem(page, QString::fromUtf8("Allgemein"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 680, 356));
        gridLayout_5 = new QGridLayout(page_2);
        gridLayout_5->setObjectName("gridLayout_5");
        label_14 = new QLabel(page_2);
        label_14->setObjectName("label_14");
        label_14->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTop|Qt::AlignmentFlag::AlignTrailing);

        gridLayout_5->addWidget(label_14, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 3, 3, 1, 1);

        label_13 = new QLabel(page_2);
        label_13->setObjectName("label_13");
        label_13->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_5->addWidget(label_13, 1, 1, 1, 1);

        btn_new_password = new QPushButton(page_2);
        btn_new_password->setObjectName("btn_new_password");

        gridLayout_5->addWidget(btn_new_password, 1, 3, 1, 1);

        line_new_password = new QLineEdit(page_2);
        line_new_password->setObjectName("line_new_password");

        gridLayout_5->addWidget(line_new_password, 1, 2, 1, 1);

        btn_del_password = new QPushButton(page_2);
        btn_del_password->setObjectName("btn_del_password");

        gridLayout_5->addWidget(btn_del_password, 2, 3, 1, 1);

        list_sfdl_passwords = new QListWidget(page_2);
        list_sfdl_passwords->setObjectName("list_sfdl_passwords");
        list_sfdl_passwords->setFont(font);
        list_sfdl_passwords->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        list_sfdl_passwords->setProperty("showDropIndicator", QVariant(false));

        gridLayout_5->addWidget(list_sfdl_passwords, 2, 2, 2, 1);

        label_12 = new QLabel(page_2);
        label_12->setObjectName("label_12");
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTop|Qt::AlignmentFlag::AlignTrailing);

        gridLayout_5->addWidget(label_12, 0, 0, 1, 1);

        label_15 = new QLabel(page_2);
        label_15->setObjectName("label_15");
        label_15->setFont(font2);
        label_15->setWordWrap(true);

        gridLayout_5->addWidget(label_15, 0, 1, 1, 3);

        toolBox->addItem(page_2, QString::fromUtf8("SFDL"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setGeometry(QRect(0, 0, 680, 356));
        gridLayout_4 = new QGridLayout(page_3);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 5, 2, 1, 1);

        line_proxy_port = new QLineEdit(page_3);
        line_proxy_port->setObjectName("line_proxy_port");
        line_proxy_port->setMaximumSize(QSize(80, 16777215));

        gridLayout_3->addWidget(line_proxy_port, 1, 2, 1, 1);

        line_proxy_user = new QLineEdit(page_3);
        line_proxy_user->setObjectName("line_proxy_user");
        line_proxy_user->setMaximumSize(QSize(200, 16777215));

        gridLayout_3->addWidget(line_proxy_user, 2, 2, 1, 1);

        label_7 = new QLabel(page_3);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(label_7, 0, 1, 1, 1);

        line_proxy_pass = new QLineEdit(page_3);
        line_proxy_pass->setObjectName("line_proxy_pass");
        line_proxy_pass->setMaximumSize(QSize(200, 16777215));

        gridLayout_3->addWidget(line_proxy_pass, 3, 2, 1, 1);

        label_6 = new QLabel(page_3);
        label_6->setObjectName("label_6");
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        label_8 = new QLabel(page_3);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(label_8, 1, 1, 1, 1);

        label_9 = new QLabel(page_3);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(label_9, 2, 1, 1, 1);

        label_10 = new QLabel(page_3);
        label_10->setObjectName("label_10");
        label_10->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(label_10, 3, 1, 1, 1);

        line_proxy_host = new QLineEdit(page_3);
        line_proxy_host->setObjectName("line_proxy_host");
        line_proxy_host->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(line_proxy_host, 0, 2, 1, 1);

        label_11 = new QLabel(page_3);
        label_11->setObjectName("label_11");
        label_11->setFont(font2);

        gridLayout_3->addWidget(label_11, 4, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        toolBox->addItem(page_3, QString::fromUtf8("Proxy"));
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        page_4->setGeometry(QRect(0, 0, 680, 356));
        gridLayout_6 = new QGridLayout(page_4);
        gridLayout_6->setObjectName("gridLayout_6");
        btn_new_exception = new QPushButton(page_4);
        btn_new_exception->setObjectName("btn_new_exception");

        gridLayout_6->addWidget(btn_new_exception, 1, 3, 1, 1);

        list_exceptions = new QListWidget(page_4);
        list_exceptions->setObjectName("list_exceptions");

        gridLayout_6->addWidget(list_exceptions, 2, 2, 2, 1);

        label_20 = new QLabel(page_4);
        label_20->setObjectName("label_20");
        label_20->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_6->addWidget(label_20, 1, 1, 1, 1);

        label_19 = new QLabel(page_4);
        label_19->setObjectName("label_19");
        label_19->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTop|Qt::AlignmentFlag::AlignTrailing);

        gridLayout_6->addWidget(label_19, 2, 1, 2, 1);

        label_17 = new QLabel(page_4);
        label_17->setObjectName("label_17");
        label_17->setFont(font1);
        label_17->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        gridLayout_6->addWidget(label_17, 0, 0, 1, 1);

        btn_del_exception = new QPushButton(page_4);
        btn_del_exception->setObjectName("btn_del_exception");

        gridLayout_6->addWidget(btn_del_exception, 2, 3, 1, 1);

        line_new_exception = new QLineEdit(page_4);
        line_new_exception->setObjectName("line_new_exception");

        gridLayout_6->addWidget(line_new_exception, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer_4, 3, 3, 1, 1);

        label_18 = new QLabel(page_4);
        label_18->setObjectName("label_18");
        label_18->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_18->setWordWrap(true);

        gridLayout_6->addWidget(label_18, 0, 1, 1, 3);

        toolBox->addItem(page_4, QString::fromUtf8("Ausnahmen"));

        gridLayout->addWidget(toolBox, 0, 0, 1, 1);


        retranslateUi(Settings);

        toolBox->setCurrentIndex(0);
        toolBox->layout()->setSpacing(6);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("Settings", "UnRAR:", nullptr));
        chk_sfv->setText(QCoreApplication::translate("Settings", "Nach SFV Datei suchen und CRC32 vergleichen", nullptr));
        button_openUnrarPath->setText(QCoreApplication::translate("Settings", "\303\226ffenen", nullptr));
        label->setText(QCoreApplication::translate("Settings", "Downloadpfad:", nullptr));
        chk_unrar_del->setText(QCoreApplication::translate("Settings", "RAR Dateien nach dem erfolgreichen Auspacken automatisch l\303\266schen", nullptr));
        label_2->setText(QCoreApplication::translate("Settings", "Hier werden deine Downloads abgelegt. Der Pfad mu\303\237 g\303\274ltig und Schreiberechte vorhanden sein", nullptr));
        label_16->setText(QCoreApplication::translate("Settings", "Absoluter Pfad zu UnRAR. Nur erforderlich, wenn RAR Dateien ausgepackt werden sollen.", nullptr));
        button_openDownloadPath->setText(QCoreApplication::translate("Settings", "\303\226ffnen", nullptr));
        chk_flatDownloads->setText(QCoreApplication::translate("Settings", "Keine Unterordner erstellen (flat download)", nullptr));
        label_4->setText(QCoreApplication::translate("Settings", "Ben\303\266tigt zus\303\244tzliche Rechenzeit und kann den Computer f\303\274r einige Zeit auslasten.", nullptr));
        label_3->setText(QCoreApplication::translate("Settings", "CRC32 / SFV:", nullptr));
        chk_crc32->setText(QCoreApplication::translate("Settings", "CRC32 Pr\303\274fsummen erstellen", nullptr));
        chk_use_internal_unrar->setText(QCoreApplication::translate("Settings", "Benutze integriertes UnRAR", nullptr));
        label_21->setText(QCoreApplication::translate("Settings", "Erstellt keine Unterodner, l\303\244dt alles in den Stammordner. Kann Vor- und Nachteile haben.", nullptr));
        chk_unrar->setText(QCoreApplication::translate("Settings", "RAR Dateien autoamtisch auspacken", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("Settings", "Allgemein", nullptr));
        label_14->setText(QCoreApplication::translate("Settings", "Passw\303\266rter", nullptr));
        label_13->setText(QCoreApplication::translate("Settings", "Neues Passwort", nullptr));
        btn_new_password->setText(QCoreApplication::translate("Settings", "Hinzuf\303\274gen", nullptr));
        btn_del_password->setText(QCoreApplication::translate("Settings", "Entfernen", nullptr));
        label_12->setText(QCoreApplication::translate("Settings", "Passw\303\266rter:", nullptr));
        label_15->setText(QCoreApplication::translate("Settings", "Diese Passw\303\266rter dienen zum entschl\303\274sseln verschl\303\274sselter SFDL Dateien. Wenn das korrekte Passwort nicht in dieser Liste steht, ist auch kein Download m\303\266glich. Das g\303\274ltige Passwort mu\303\237 vor dem \303\226ffnen einer SFDL Datei hier eingetragen werden. Die Reihenfolge der Passw\303\266rter ist egal.", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("Settings", "SFDL", nullptr));
        label_7->setText(QCoreApplication::translate("Settings", "Host", nullptr));
        label_6->setText(QCoreApplication::translate("Settings", "FTP Proxy:", nullptr));
        label_8->setText(QCoreApplication::translate("Settings", "Port", nullptr));
        label_9->setText(QCoreApplication::translate("Settings", "Benutzer", nullptr));
        label_10->setText(QCoreApplication::translate("Settings", "Passwort", nullptr));
        label_11->setText(QCoreApplication::translate("Settings", "Unterst\303\274tzt werden nur SOCKS 5 Proxy Server nach RFC 1928.", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("Settings", "Proxy", nullptr));
        btn_new_exception->setText(QCoreApplication::translate("Settings", "Hinzuf\303\274gen", nullptr));
        label_20->setText(QCoreApplication::translate("Settings", "Neue Ausnahme", nullptr));
        label_19->setText(QCoreApplication::translate("Settings", "Ausnahmen", nullptr));
        label_17->setText(QCoreApplication::translate("Settings", "Ausnahmen:", nullptr));
        btn_del_exception->setText(QCoreApplication::translate("Settings", "Entfernen", nullptr));
        label_18->setText(QCoreApplication::translate("Settings", "Hier k\303\266nnen Ausnahmen definiert werden, die vom Download ausgeschlossen werden. Es wird anhand eines regul\303\244ren Ausdrucks (RegExp) gepr\303\274ft, ob die Datei in der Downloadliste eine \303\234bereinstimmung hat. Dies ist ausdr\303\274cklich NICHT auf Dateiendungen beschr\303\244nkt!", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("Settings", "Ausnahmen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
