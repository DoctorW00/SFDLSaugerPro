#ifndef CRC32_H
#define CRC32_H

#include <QObject>
#include <QtCore>
#include <QString>
#include <QMap>

class Crc32 : public QObject
{
    Q_OBJECT

public:
    explicit Crc32(QStringList data);
    ~Crc32();
    // QString calculateFromFile(QString filename);
    // void calculateFromFile();
    void initInstance(int i);
    void pushData(int i, char *data, int len);
    quint32 releaseInstance(int i);

public slots:
    void calculateFromFile();

private:
    quint32 crc_table[256];
    QMap<int, quint32> instances;
    QStringList data;
    QString id;
    int nRow;
    QString filepath;

signals:
    void finished();
    void updateCRC32data(QString id, int nRow, QString returnCRC32);

};

#endif // CRC32_H
