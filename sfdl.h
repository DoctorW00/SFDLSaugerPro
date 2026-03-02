#ifndef SFDL_H
#define SFDL_H

// #include "data.h"

#include <QtXml/QtXml>
#include <QByteArray>
#include <QObject>
// #include <QHostAddress>

#ifdef QT_DEBUG
    #include <QDebug>
#endif

class sfdl : public QObject
{
    Q_OBJECT

public:
    explicit sfdl(QObject *parent = nullptr);
    QString _SFDLFile;
    QStringList _passwordList;

public slots:
    void readSFDL();
    void setSFDL(QString file, QStringList passwordList);

private slots:
    QByteArray loadSFDL(QString file);
    QString ListElements(QDomElement root, QString tagname);
    QString decryptString(QString password, QString encodedString);
    bool validateIPv4(QString ip);

signals:
    void sendSFDLData(QStringList data, QStringList files);
    void sendWarning(QString label, QString text);
    void sendLogText(QString text);

};

#endif // SFDL_H
