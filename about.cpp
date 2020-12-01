#include "about.h"
#include "ui_about.h"

#include <QDebug>
#include <QFile>

/*
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QWidget>
#include <QVBoxLayout>
*/

About::About(QWidget *parent) : QDialog(parent), ui(new Ui::About)
{
    ui->setupUi(this);

    // engine->play2D("D:/space_debris.mod", true);
    // engine->setSoundVolume(0.5);

    /*
    auto *window = new QWidget(this);
    auto layout = new QVBoxLayout(this);
    auto player = new QMediaPlayer(this);
    auto videoWidget = new QVideoWidget(this);

    videoWidget->installEventFilter(this);

    videoWidget->setStyleSheet("background: black;");

    layout->addWidget(videoWidget);
    layout->setEnabled(1);
    window->setLayout(layout);
    window->setStyleSheet("background: black;");


    ui->gridLayout->addWidget(window);


    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("D:/Projekte/Qt/SFDLSaugerPro/vid/koalasintherain144.avi"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    // player->setMedia(QUrl("D:/Projekte/Qt/SFDLSaugerPro/vid/koalasintherain144.avi"));
    player->setPlaylist(playlist);
    player->setVolume(50);

    // ui->gridLayout->addWidget(videoWidget);
    // ui->gridLayout->setGeometry(QRect(120, 30, 256, 144));

    videoWidget->show();
    player->play();
    */

    // auto player = new QMediaPlayer(this);
    // auto playlist = new QMediaPlaylist(this);

    // playlist->addMedia(QUrl("qrc:/snd/koala.mp3"));
    // playlist->setPlaybackMode(QMediaPlaylist::Loop);

    ui->label_3->setText(tr("Version <b>") + QString(APP_VERSION)
                         + "</b><br />" + tr("Erstellt mit ") +  "<a href=\"https://isocpp.org/\">C++</a> und <a href=\"https://www.qt.io/\">Qt</a>" + tr(" von ") + "<b>GrafSauger</b>"
                         + tr(" für ") + "<a href=\"https://mlcboard.com/\">MLCBoard.com</a></b>"
                         + "<br />" + tr("Was ist SFDL? Simple FTP download ") + "<a href=\"https://sfdl.net/\">SFDL.net</a>");
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

    // player->setPlaylist(playlist);
    player->setMedia(QUrl("qrc:/snd/koala.mp3"));
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
    // qDebug() << "audioPositionChanged: " << position;

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
    //float newValue = float(value) / 100;
    //engine->setSoundVolume(newValue);

    player->setVolume(value);
}
