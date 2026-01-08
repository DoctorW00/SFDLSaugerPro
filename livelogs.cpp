#include "livelogs.h"
#include "ui_livelogs.h"
#include <QScrollBar>

LiveLogs::LiveLogs(QWidget *parent) : QDialog(parent), ui(new Ui::LiveLogs)
{
    ui->setupUi(this);

    ui->liveLogsText->setReadOnly(true);
    ui->liveLogsText->setTextInteractionFlags(Qt::NoTextInteraction);

    this->setStyleSheet(
        "QTextEdit {"
        "   background-color: #1e1e1e;"
        "   color: #d4d4d4;"
        "   border: none;"
        "   padding: 0px;"
        "   margin: 0px;"
        "   font-family: Consolas;"
        "}"
        );
}

LiveLogs::~LiveLogs()
{
    delete ui;
}

void LiveLogs::addLogText(const QString& logText)
{
    ui->liveLogsText->moveCursor(QTextCursor::End);
    ui->liveLogsText->insertHtml(logText);
    ui->liveLogsText->verticalScrollBar()->setValue(ui->liveLogsText->verticalScrollBar()->maximum());
}
