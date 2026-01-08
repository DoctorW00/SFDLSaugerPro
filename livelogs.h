#ifndef LIVELOGS_H
#define LIVELOGS_H

#include <QDialog>

namespace Ui
{
    class LiveLogs;
}

class LiveLogs : public QDialog
{
    Q_OBJECT

public:
    explicit LiveLogs(QWidget *parent = nullptr);
    ~LiveLogs();

public slots:
    void addLogText(const QString& logText);

private:
    Ui::LiveLogs *ui;

};

#endif // LIVELOGS_H
