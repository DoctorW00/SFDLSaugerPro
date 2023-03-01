#ifndef CRC32_H
#define CRC32_H

#include <QObject>
#include <QtCore>
#include <QString>
#include <QMap>
#include <QMutex>

#ifdef QT_DEBUG
    #include <QDebug>
#endif

class Crc32 : public QObject
{
    Q_OBJECT

public:
    explicit Crc32(QStringList data);
    ~Crc32();
    QString _id;

public slots:
    void calculateFromFile();

private slots:
    void initTable();
    void initInstance(int i);
    void pushData(int i, char *data, int len);
    quint32 releaseInstance(int i);

signals:
    void finished();
    void updateCRC32data(QString id, int nRow, QString returnCRC32);

private:
    quint32 crc_table[256];
    QMap<int, quint32> instances;
    QStringList data;
    int nRow;
    QString filepath;
    QMutex mutex;
    QString id;

};

#endif // CRC32_H
