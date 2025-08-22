#include "about.h"
#include "ui_about.h"
#include <QFile>

About::About(QWidget *parent) : QDialog(parent), ui(new Ui::About)
{
    ui->setupUi(this);

    ui->label_3->setText(tr("Version <b>") + QString(APP_VERSION)
                         + "</b><br />" + tr("Erstellt mit ") +  "<a href=\"https://isocpp.org/\">C++</a> und <a href=\"https://www.qt.io/\">Qt</a>" + tr(" von ") + "<b>GrafSauger</b>"
                         + tr(" für ") + "<a href=\"https://mlcboard.com/\">MLCBoard.com</a></b>"
                         + "<br />" + tr("Was ist SFDL? Simple FTP download ") + "<a href=\"https://sfdl.net/\">SFDL.net</a>"
                         + "<br /> UnRAR © Alexander Roshal <a href=\"https://www.rarlab.com/rar_add.htm\">rarlab.com</a>");
    ui->label_3->setTextFormat(Qt::RichText);
    ui->label_3->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_3->setOpenExternalLinks(true);

    ui->label_4->setText("<a href=\"https://www.youtube.com/watch?v=gNqQL-1gZF8&t=5m46s\">True Facts About Marsupials</a>");
    ui->label_4->setTextFormat(Qt::RichText);
    ui->label_4->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_4->setOpenExternalLinks(true);

    _mediaPlayer = false;
}

void About::playMedia()
{
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(audioPositionChanged(qint64)));

    playlist->addMedia(QUrl("qrc:/snd/koala.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player->setPlaylist(playlist);
    player->setPosition(0);
    player->setVolume(50);
    player->play();

    movie = new QMovie(":/gfx/koala.gif");
    processLabel = new QLabel(this);
    processLabel->setMovie(movie);

    ui->gridLayout->addWidget(processLabel);

    movie->start();

    _mediaPlayer = true;
}

void About::audioPositionChanged(qint64 position)
{
    if(position == 8420)
    {
        player->setPosition(0);
        player->play();
    }
}

About::~About()
{
    _mediaPlayer = false;
    delete ui;
}

void About::closeEvent(QCloseEvent *e)
{
    e;

    player->stop();
    movie->stop();
    processLabel->clear();
    _mediaPlayer = false;
}

void About::on_lautleise_valueChanged(int value)
{
    player->setVolume(value);
}
