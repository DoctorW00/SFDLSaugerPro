#include "about.h"
#include "ui_about.h"
About::About(QWidget *parent) : QDialog(parent), ui(new Ui::About)
{
    ui->setupUi(this);

    ui->label_3->setText(
        tr("Version <b>%1</b>").arg(QString(APP_VERSION))
        + "<br />"
        + tr("Erstellt mit <a href=\"https://isocpp.org/\">C++</a> und "
             "<a href=\"https://www.qt.io/\">Qt</a> von <b>Captive-IT</b>.")
        + "<br /><br />"
        + tr("Links:")
        + "<br />- " + tr("SFDL") + ": <a href=\"https://sfdl.net/\">sfdl.net</a>"
        + "<br />- " + tr("UnRAR") + ": <a href=\"https://www.rarlab.com/rar_add.htm\">rarlab.com</a>"
        + "<br />- " + tr("libcommuni") + ": <a href=\"https://github.com/communi/libcommuni\">github.com/communi/libcommuni</a>"
    );
    ui->label_3->setTextFormat(Qt::RichText);
    ui->label_3->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_3->setOpenExternalLinks(true);
    ui->label_3->setWordWrap(true);
}

About::~About()
{
    delete ui;
}
