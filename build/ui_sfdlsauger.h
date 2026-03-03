/********************************************************************************
** Form generated from reading UI file 'sfdlsauger.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SFDLSAUGER_H
#define UI_SFDLSAUGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SFDLSauger
{
public:
    QAction *action_ffnen;
    QAction *actionBeenden;
    QAction *actionLogs_anzeigen;
    QAction *action_ber;
    QAction *actionEinstellungen;
    QAction *actionIRC_Chat;
    QAction *actionStrukturreformator;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QTextEdit *textEdit;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuDatei;
    QMenu *menuOptionen;
    QMenu *menuHilfe;
    QMenu *menuTools;

    void setupUi(QMainWindow *SFDLSauger)
    {
        if (SFDLSauger->objectName().isEmpty())
            SFDLSauger->setObjectName("SFDLSauger");
        SFDLSauger->resize(950, 600);
        QFont font;
        font.setPointSize(10);
        SFDLSauger->setFont(font);
        SFDLSauger->setStyleSheet(QString::fromUtf8("background-color: #0d1117;"));
        SFDLSauger->setIconSize(QSize(38, 38));
        action_ffnen = new QAction(SFDLSauger);
        action_ffnen->setObjectName("action_ffnen");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/gfx/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_ffnen->setIcon(icon);
        actionBeenden = new QAction(SFDLSauger);
        actionBeenden->setObjectName("actionBeenden");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/gfx/quit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionBeenden->setIcon(icon1);
        actionLogs_anzeigen = new QAction(SFDLSauger);
        actionLogs_anzeigen->setObjectName("actionLogs_anzeigen");
        actionLogs_anzeigen->setCheckable(true);
        actionLogs_anzeigen->setChecked(true);
        action_ber = new QAction(SFDLSauger);
        action_ber->setObjectName("action_ber");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/gfx/info.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_ber->setIcon(icon2);
        actionEinstellungen = new QAction(SFDLSauger);
        actionEinstellungen->setObjectName("actionEinstellungen");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/gfx/gear.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionEinstellungen->setIcon(icon3);
        actionIRC_Chat = new QAction(SFDLSauger);
        actionIRC_Chat->setObjectName("actionIRC_Chat");
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8(":/gfx/irc.png")));
        actionIRC_Chat->setIcon(icon4);
        actionStrukturreformator = new QAction(SFDLSauger);
        actionStrukturreformator->setObjectName("actionStrukturreformator");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/gfx/reformator.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionStrukturreformator->setIcon(icon5);
        centralWidget = new QWidget(SFDLSauger);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName("splitter");
        splitter->setStyleSheet(QString::fromUtf8("QSplitter::handle {\n"
"	background: #21262d;\n"
"}\n"
"QSplitter::handle:hover {\n"
"	background: #58a6ff;\n"
"}"));
        splitter->setOrientation(Qt::Orientation::Vertical);
        splitter->setHandleWidth(5);
        splitter->setChildrenCollapsible(false);
        textEdit = new QTextEdit(splitter);
        textEdit->setObjectName("textEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMinimumSize(QSize(0, 50));
        textEdit->setMaximumSize(QSize(16777215, 100));
        textEdit->setSizeIncrement(QSize(0, 50));
        textEdit->setBaseSize(QSize(0, 120));
        textEdit->setFont(font);
        textEdit->setMouseTracking(true);
        textEdit->setTabletTracking(false);
        textEdit->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        textEdit->setAcceptDrops(false);
        textEdit->setStyleSheet(QString::fromUtf8("border: 1px solid #21262d;\n"
"background: #0d1117;\n"
"color: #8b949e;\n"
"font-size: 12px;\n"
"border-radius: 8px;\n"
"padding: 12px;"));
        textEdit->setFrameShape(QFrame::Shape::Box);
        textEdit->setFrameShadow(QFrame::Shadow::Raised);
        textEdit->setLineWidth(0);
        textEdit->setMidLineWidth(1);
        textEdit->setDocumentTitle(QString::fromUtf8(""));
        textEdit->setUndoRedoEnabled(false);
        textEdit->setReadOnly(true);
        textEdit->setMarkdown(QString::fromUtf8(""));
        textEdit->setHtml(QString::fromUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>"));
        textEdit->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
        textEdit->setPlaceholderText(QString::fromUtf8(""));
        splitter->addWidget(textEdit);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName("tabWidget");
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(0, 50));
        tabWidget->setSizeIncrement(QSize(0, 200));
        tabWidget->setBaseSize(QSize(0, 200));
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(true);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"	border: 1px solid #21262d;\n"
"	border-top: none;\n"
"	background: #0d1117;\n"
"	border-radius: 0 0 8px 8px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    background: #161b22;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"	background: #21262d;\n"
"	color: #8b949e;\n"
"	padding: 10px 20px;\n"
"	border-radius: 6px 6px 0 0;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #0d1117;\n"
"	color: #58a6ff;\n"
"	font-weight: 600;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover {\n"
"    background: #30363d;\n"
"	color: #c9d1d9;\n"
"}\n"
"\n"
"QTabBar::tab:top:!selected {\n"
"    margin-top: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:!selected {\n"
"    margin-bottom: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:top, QTabBar::tab:bottom {\n"
"    min-width: 8ex;\n"
"    margin-right: -1px;\n"
"    padding: 5px 10px 5px 10px;\n"
"}\n"
"\n"
"QTabBar::tab:top:selected {\n"
"    border-bottom-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:selected {\n"
"    border-top-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:top:last, QT"
                        "abBar::tab:bottom:last,\n"
"QTabBar::tab:top:only-one, QTabBar::tab:bottom:only-one {\n"
"    margin-right: 0;\n"
"}\n"
"\n"
"QTabBar::tab:left:!selected {\n"
"    margin-right: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:right:!selected {\n"
"    margin-left: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:left, QTabBar::tab:right {\n"
"    min-height: 8ex;\n"
"    margin-bottom: -1px;\n"
"    padding: 10px 5px 10px 5px;\n"
"}\n"
"\n"
"QTabBar::tab:left:selected {\n"
"    border-left-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:right:selected {\n"
"    border-right-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:left:last, QTabBar::tab:right:last,\n"
"QTabBar::tab:left:only-one, QTabBar::tab:right:only-one {\n"
"    margin-bottom: 0;\n"
"}\n"
"\n"
""));
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setIconSize(QSize(32, 32));
        tabWidget->setElideMode(Qt::TextElideMode::ElideNone);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        splitter->addWidget(tabWidget);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        SFDLSauger->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SFDLSauger);
        menuBar->setObjectName("menuBar");
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 950, 22));
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName("menuDatei");
        menuOptionen = new QMenu(menuBar);
        menuOptionen->setObjectName("menuOptionen");
        menuHilfe = new QMenu(menuBar);
        menuHilfe->setObjectName("menuHilfe");
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName("menuTools");
        SFDLSauger->setMenuBar(menuBar);

        menuBar->addAction(menuDatei->menuAction());
        menuBar->addAction(menuOptionen->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHilfe->menuAction());
        menuDatei->addAction(action_ffnen);
        menuDatei->addSeparator();
        menuDatei->addAction(actionBeenden);
        menuOptionen->addAction(actionLogs_anzeigen);
        menuOptionen->addSeparator();
        menuOptionen->addAction(actionEinstellungen);
        menuHilfe->addAction(action_ber);
        menuTools->addAction(actionIRC_Chat);
        menuTools->addAction(actionStrukturreformator);

        retranslateUi(SFDLSauger);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(SFDLSauger);
    } // setupUi

    void retranslateUi(QMainWindow *SFDLSauger)
    {
        SFDLSauger->setWindowTitle(QCoreApplication::translate("SFDLSauger", "SFDLSauger Pro", nullptr));
        action_ffnen->setText(QCoreApplication::translate("SFDLSauger", "\303\226ffnen", nullptr));
        actionBeenden->setText(QCoreApplication::translate("SFDLSauger", "Beenden", nullptr));
        actionLogs_anzeigen->setText(QCoreApplication::translate("SFDLSauger", "Logs anzeigen", nullptr));
        action_ber->setText(QCoreApplication::translate("SFDLSauger", "\303\234ber SFDLSauger Pro", nullptr));
        actionEinstellungen->setText(QCoreApplication::translate("SFDLSauger", "Einstellungen", nullptr));
#if QT_CONFIG(shortcut)
        actionEinstellungen->setShortcut(QCoreApplication::translate("SFDLSauger", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionIRC_Chat->setText(QCoreApplication::translate("SFDLSauger", "IRC Chat", nullptr));
        actionStrukturreformator->setText(QCoreApplication::translate("SFDLSauger", "Strukturreformator", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("SFDLSauger", "Datei", nullptr));
        menuOptionen->setTitle(QCoreApplication::translate("SFDLSauger", "Optionen", nullptr));
        menuHilfe->setTitle(QCoreApplication::translate("SFDLSauger", "Hilfe", nullptr));
        menuTools->setTitle(QCoreApplication::translate("SFDLSauger", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SFDLSauger: public Ui_SFDLSauger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SFDLSAUGER_H
