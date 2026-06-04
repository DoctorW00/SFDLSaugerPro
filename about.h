#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
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
    void on_lautleise_valueChanged(int value);
    void audioPositionChanged(qint64 position);

protected:
    void closeEvent(QCloseEvent *e) override;
    void changeEvent(QEvent *event) override;

private:
    Ui::About *ui;
    QMediaPlayer *player = new QMediaPlayer(this);
    QMediaPlaylist *playlist = new QMediaPlaylist(this);
    QMovie *movie = new QMovie(this);
    QLabel *processLabel = new QLabel(this);
};

#endif // ABOUT_H
