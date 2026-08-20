#include "about.h"
#include "ui_about.h"
#include <QFile>

About::About(QWidget *parent) : QDialog(parent), ui(new Ui::About)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    movie = new QMovie(":/gfx/koala.gif", QByteArray(), this);

    processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    processLabel->setFixedHeight(144);
    ui->gridLayout->addWidget(processLabel);

    ui->label_3->setMinimumSize(0, 0);
    ui->label_3->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
    ui->label_3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    ui->label_3->setWordWrap(true);
    ui->label_3->setText(tr("Version ") + "<b>"+ QString(APP_VERSION) + "</b>");
    ui->label_3->updateGeometry();
    ui->label_3->setTextFormat(Qt::RichText);
    ui->label_3->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_3->setOpenExternalLinks(true);

    ui->label_4->setTextFormat(Qt::RichText);
    ui->label_4->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_4->setOpenExternalLinks(true);

    _mediaPlayer = false;
}

void About::playMedia()
{
    disconnect(player, SIGNAL(positionChanged(qint64)), this, SLOT(audioPositionChanged(qint64)));
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(audioPositionChanged(qint64)));

    if(playlist->isEmpty())
    {
        playlist->addMedia(QUrl("qrc:/snd/koala.mp3"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        player->setPlaylist(playlist);
    }

    player->setPosition(0);
    player->setVolume(ui->lautleise->value());
    player->play();

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
    Q_UNUSED(e);

    player->stop();
    movie->stop();
    _mediaPlayer = false;
}

void About::on_lautleise_valueChanged(int value)
{
    player->setVolume(value);
}

void About::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
    QWidget::changeEvent(event);
}
