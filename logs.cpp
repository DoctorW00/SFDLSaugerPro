#include "logs.h"
#include "ui_logs.h"

Logs::Logs(QWidget *parent) : QWidget(parent), ui(new Ui::logs)
{
    ui->setupUi(this);
}

Logs::~Logs()
{
    delete ui;
}
