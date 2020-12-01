#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
// #include <irrKlang.h>

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QLabel>
#include <QMovie>

namespace Ui
{
    class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();
    bool _mediaPlayer;

public slots:
    void playMedia();

private slots:
    void closeEvent(QCloseEvent *e);
    void on_lautleise_valueChanged(int value);
    void audioPositionChanged(qint64 position);

private:
    Ui::About *ui;
    // irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();
    QMediaPlayer *player = new QMediaPlayer(this);
    QMediaPlaylist *playlist = new QMediaPlaylist(this);
    QMovie *movie = new QMovie(this);
    QLabel *processLabel = new QLabel(this);
};

#endif // ABOUT_H
