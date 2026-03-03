/********************************************************************************
** Form generated from reading UI file 'chatirc.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATIRC_H
#define UI_CHATIRC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_chatIRC
{
public:
    QGridLayout *gridLayout;
    QPushButton *buttonChatSend;
    QLineEdit *inputEdit;
    QSplitter *splitter_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *labelUserName;
    QPushButton *buttonSetup;
    QLabel *labelNickName;
    QComboBox *selectIRCProxy;
    QLabel *labelIRCProxy;
    QLineEdit *lineRealName;
    QComboBox *selectIRCServer;
    QLineEdit *lineNickName;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ircConnectButton;
    QLabel *labelIRCServer;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineUserName;
    QLabel *labelRealName;
    QSpacerItem *verticalSpacer;
    QSplitter *splitter;
    QListView *bufferView;
    QTextEdit *chatBrowser;
    QListView *userList;

    void setupUi(QDialog *chatIRC)
    {
        if (chatIRC->objectName().isEmpty())
            chatIRC->setObjectName("chatIRC");
        chatIRC->resize(800, 450);
        chatIRC->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(chatIRC);
        gridLayout->setObjectName("gridLayout");
        buttonChatSend = new QPushButton(chatIRC);
        buttonChatSend->setObjectName("buttonChatSend");
        buttonChatSend->setFlat(true);

        gridLayout->addWidget(buttonChatSend, 1, 1, 1, 1);

        inputEdit = new QLineEdit(chatIRC);
        inputEdit->setObjectName("inputEdit");
        inputEdit->setFrame(false);

        gridLayout->addWidget(inputEdit, 1, 0, 1, 1);

        splitter_2 = new QSplitter(chatIRC);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setStyleSheet(QString::fromUtf8("QSplitter::handle {\n"
"	background: #FFFFFF url(:/gfx/splitter.png) center no-repeat;\n"
"}\n"
"\n"
"QSplitter::handle:horizontal {\n"
"	background: #FFFFFF url(:/gfx/splitter2.png) center no-repeat;\n"
"}\n"
""));
        splitter_2->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter_2);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 100));
        groupBox->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        groupBox->setFont(font);
        groupBox->setFlat(false);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        labelUserName = new QLabel(groupBox);
        labelUserName->setObjectName("labelUserName");

        gridLayout_2->addWidget(labelUserName, 1, 4, 1, 1);

        buttonSetup = new QPushButton(groupBox);
        buttonSetup->setObjectName("buttonSetup");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonSetup->sizePolicy().hasHeightForWidth());
        buttonSetup->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(buttonSetup, 0, 0, 3, 1);

        labelNickName = new QLabel(groupBox);
        labelNickName->setObjectName("labelNickName");

        gridLayout_2->addWidget(labelNickName, 0, 4, 1, 1);

        selectIRCProxy = new QComboBox(groupBox);
        selectIRCProxy->setObjectName("selectIRCProxy");

        gridLayout_2->addWidget(selectIRCProxy, 1, 2, 1, 1);

        labelIRCProxy = new QLabel(groupBox);
        labelIRCProxy->setObjectName("labelIRCProxy");

        gridLayout_2->addWidget(labelIRCProxy, 1, 1, 1, 1);

        lineRealName = new QLineEdit(groupBox);
        lineRealName->setObjectName("lineRealName");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineRealName->sizePolicy().hasHeightForWidth());
        lineRealName->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(lineRealName, 2, 5, 1, 1);

        selectIRCServer = new QComboBox(groupBox);
        selectIRCServer->setObjectName("selectIRCServer");

        gridLayout_2->addWidget(selectIRCServer, 0, 2, 1, 1);

        lineNickName = new QLineEdit(groupBox);
        lineNickName->setObjectName("lineNickName");
        sizePolicy2.setHeightForWidth(lineNickName->sizePolicy().hasHeightForWidth());
        lineNickName->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(lineNickName, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 7, 3, 1);

        ircConnectButton = new QPushButton(groupBox);
        ircConnectButton->setObjectName("ircConnectButton");
        sizePolicy1.setHeightForWidth(ircConnectButton->sizePolicy().hasHeightForWidth());
        ircConnectButton->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(ircConnectButton, 0, 6, 3, 1);

        labelIRCServer = new QLabel(groupBox);
        labelIRCServer->setObjectName("labelIRCServer");

        gridLayout_2->addWidget(labelIRCServer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 3, 3, 1);

        lineUserName = new QLineEdit(groupBox);
        lineUserName->setObjectName("lineUserName");
        sizePolicy2.setHeightForWidth(lineUserName->sizePolicy().hasHeightForWidth());
        lineUserName->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(lineUserName, 1, 5, 1, 1);

        labelRealName = new QLabel(groupBox);
        labelRealName->setObjectName("labelRealName");

        gridLayout_2->addWidget(labelRealName, 2, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 5);

        splitter_2->addWidget(groupBox);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName("splitter");
        splitter->setLineWidth(0);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setChildrenCollapsible(false);
        bufferView = new QListView(splitter);
        bufferView->setObjectName("bufferView");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(bufferView->sizePolicy().hasHeightForWidth());
        bufferView->setSizePolicy(sizePolicy3);
        bufferView->setMinimumSize(QSize(100, 0));
        bufferView->setMaximumSize(QSize(200, 16777215));
        bufferView->setSizeIncrement(QSize(100, 0));
        bufferView->setBaseSize(QSize(100, 0));
        bufferView->setFrameShape(QFrame::NoFrame);
        bufferView->setFrameShadow(QFrame::Plain);
        bufferView->setLineWidth(0);
        splitter->addWidget(bufferView);
        chatBrowser = new QTextEdit(splitter);
        chatBrowser->setObjectName("chatBrowser");
        chatBrowser->setMinimumSize(QSize(0, 0));
        chatBrowser->setBaseSize(QSize(300, 0));
        chatBrowser->setMouseTracking(false);
        chatBrowser->setFocusPolicy(Qt::NoFocus);
        chatBrowser->setContextMenuPolicy(Qt::NoContextMenu);
        chatBrowser->setAcceptDrops(false);
        chatBrowser->setFrameShape(QFrame::NoFrame);
        chatBrowser->setFrameShadow(QFrame::Plain);
        chatBrowser->setLineWidth(0);
        chatBrowser->setUndoRedoEnabled(false);
        chatBrowser->setReadOnly(true);
        chatBrowser->setTextInteractionFlags(Qt::NoTextInteraction);
        chatBrowser->setPlaceholderText(QString::fromUtf8(""));
        splitter->addWidget(chatBrowser);
        userList = new QListView(splitter);
        userList->setObjectName("userList");
        sizePolicy3.setHeightForWidth(userList->sizePolicy().hasHeightForWidth());
        userList->setSizePolicy(sizePolicy3);
        userList->setMinimumSize(QSize(100, 0));
        userList->setMaximumSize(QSize(200, 16777215));
        userList->setSizeIncrement(QSize(100, 0));
        userList->setBaseSize(QSize(100, 0));
        userList->setFrameShape(QFrame::NoFrame);
        userList->setFrameShadow(QFrame::Plain);
        userList->setLineWidth(0);
        splitter->addWidget(userList);
        splitter_2->addWidget(splitter);

        gridLayout->addWidget(splitter_2, 0, 0, 1, 2);


        retranslateUi(chatIRC);

        QMetaObject::connectSlotsByName(chatIRC);
    } // setupUi

    void retranslateUi(QDialog *chatIRC)
    {
        chatIRC->setWindowTitle(QCoreApplication::translate("chatIRC", "Dialog", nullptr));
        buttonChatSend->setText(QCoreApplication::translate("chatIRC", "Chat", nullptr));
        groupBox->setTitle(QCoreApplication::translate("chatIRC", "IRC Chat", nullptr));
        labelUserName->setText(QCoreApplication::translate("chatIRC", "Username:", nullptr));
        buttonSetup->setText(QCoreApplication::translate("chatIRC", "Setup", nullptr));
        labelNickName->setText(QCoreApplication::translate("chatIRC", "Nick:", nullptr));
        labelIRCProxy->setText(QCoreApplication::translate("chatIRC", "Proxy:", nullptr));
        ircConnectButton->setText(QCoreApplication::translate("chatIRC", "Verbinden", nullptr));
        labelIRCServer->setText(QCoreApplication::translate("chatIRC", "IRC Server:", nullptr));
        labelRealName->setText(QCoreApplication::translate("chatIRC", "Real:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatIRC: public Ui_chatIRC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATIRC_H
