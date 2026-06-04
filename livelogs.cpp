#include "livelogs.h"
#include "ui_livelogs.h"
#include <QScrollBar>
#include <QKeyEvent>
#include <QClipboard>
#include <QMenu>
#include <QFileDialog>
#include <QTextStream>
#include <QDateTime>
#include <QDir>
#include <QDesktopServices>
#include <QUrl>
#include <QStyle>

LiveLogs::LiveLogs(QWidget *parent) : QDialog(parent), ui(new Ui::LiveLogs)
{
    ui->setupUi(this);
    ui->liveLogsText->installEventFilter(this);
    ui->liveLogsText->viewport()->installEventFilter(this);
    ui->liveLogsText->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->liveLogsText->viewport()->setCursor(Qt::IBeamCursor);
    ui->liveLogsText->setTextInteractionFlags(ui->liveLogsText->textInteractionFlags() | Qt::LinksAccessibleByMouse);
    ui->liveLogsText->setUndoRedoEnabled(false);
    ui->liveLogsText->document()->setUndoRedoEnabled(false);
    ui->liveLogsText->setAcceptDrops(false);
    ui->liveLogsText->setReadOnly(true);
    connect(ui->liveLogsText, &QWidget::customContextMenuRequested, this, &LiveLogs::showSafeMenu);

    this->setStyleSheet(
        "QTextEdit {"
        "   background-color: #1e1e1e;"
        "   color: #d4d4d4;"
        "   border: none;"
        "   padding: 0px;"
        "   margin: 0px;"
        "   font-family: Consolas;"
        "   font-size: 14px;"
        "}"
        );
}

LiveLogs::~LiveLogs()
{
    delete ui;
}

bool LiveLogs::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->liveLogsText || obj == ui->liveLogsText->viewport())
    {
        if(event->type() == QEvent::MouseButtonRelease)
        {
            QMouseEvent *me = static_cast<QMouseEvent*>(event);
            QString link = ui->liveLogsText->anchorAt(me->pos());

            if(!link.isEmpty())
            {
                if(event->type() == QEvent::MouseButtonRelease)
                {
                    QDesktopServices::openUrl(QUrl(link));
                }
                return true;
            }
        }

        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *ke = static_cast<QKeyEvent*>(event);
            if(ke->matches(QKeySequence::Copy)) {
                QString selected = ui->liveLogsText->textCursor().selectedText();
                selected.replace(QChar(0x2029), "\n");
                selected.replace(QChar(0x2028), "\n");
                QApplication::clipboard()->setText(selected);
                return true;
            }
        }
    }

    if(event->type() == QEvent::MouseMove)
    {
        QMouseEvent *me = static_cast<QMouseEvent*>(event);
        if(!ui->liveLogsText->anchorAt(me->pos()).isEmpty())
        {
            ui->liveLogsText->viewport()->setCursor(Qt::PointingHandCursor);
        }
        else
        {
            ui->liveLogsText->viewport()->setCursor(Qt::IBeamCursor);
        }
    }

    return QDialog::eventFilter(obj, event);
}

void LiveLogs::showSafeMenu(const QPoint &pos)
{
    QMenu menu(this);

    if(ui->liveLogsText->textCursor().hasSelection())
    {
        auto *copyAction = menu.addAction(tr("Kopieren"));
        copyAction->setIcon(style()->standardIcon(QStyle::SP_FileDialogContentsView));
        connect(copyAction, &QAction::triggered, this, [this]() {
            QString selected = ui->liveLogsText->textCursor().selectedText();
            selected.replace(QChar(0x2029), "\n");
            selected.replace(QChar(0x2028), "\n");
            QApplication::clipboard()->setText(selected);
        });
    }

    auto *selectAllAction = menu.addAction(tr("Alles markieren"));
    selectAllAction->setIcon(style()->standardIcon(QStyle::SP_FileDialogListView));
    connect(selectAllAction, &QAction::triggered, ui->liveLogsText, &QTextEdit::selectAll);

    auto *saveAction = menu.addAction(tr("Log speichern unter..."));
    saveAction->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
    connect(saveAction, &QAction::triggered, this, &LiveLogs::saveLogToFile);

    menu.exec(ui->liveLogsText->mapToGlobal(pos));
}

void LiveLogs::saveLogToFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Log speichern"), "", tr("Log-Datei (*.log);;Text-Datei (*.txt);;Alle Dateien (*)"));
    QString nativePath = QDir::toNativeSeparators(fileName);

    if(fileName.isEmpty())
    {
        return;
    }

    QString logText;
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << ui->liveLogsText->toPlainText();
        file.close();

        QString fileUrl = QUrl::fromLocalFile(fileName).toString();
        QString link = QString("<a href=\"%1\" style=\"color: #4CAF50;\">%2</a>").arg(fileUrl, nativePath);
        logText = tr("[Logs] Log-Datei erfolgreich unter <b>") + link + tr("</b> gespeichert.");
    }
    else
    {
        logText = tr("[Logs] Fehler: Log-Datei konnte nicht geschrieben werden:") + " <b>" + file.errorString() + "</b>";
    }

    emit sendLogText(logText);
}

void LiveLogs::addLogText(const QString& logText)
{
    ui->liveLogsText->moveCursor(QTextCursor::End);
    ui->liveLogsText->insertHtml(logText);
    ui->liveLogsText->verticalScrollBar()->setValue(ui->liveLogsText->verticalScrollBar()->maximum());
}

void LiveLogs::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
    QWidget::changeEvent(event);
}
