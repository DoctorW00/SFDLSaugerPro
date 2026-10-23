#include "sfdl.h"

#include <QDebug>

#include <QCryptographicHash>
#include <QRegularExpression>
#include <qaesencryption.h>

sfdl::sfdl(QObject *parent) : QObject(parent) {}

static QString entryValue(const QStringList &list, int index)
{
    if(index < 0 || index >= list.count()) return QString();
    return list.at(index).section('|', 1);
}

static QString entryKey(const QStringList &list, int index)
{
    if(index < 0 || index >= list.count()) return QString();
    return list.at(index).section('|', 0, 0);
}

static bool hasPathTraversal(const QString &path)
{
    const QStringList parts = path.split(QRegularExpression("[/\\\\]"));
    return parts.contains("..");
}

QByteArray sfdl::loadSFDL(QString file)
{
    QFile f(file);

    if(f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray arr = f.readAll();
        f.close();

        return arr;
    }

    return QByteArray();
}

QString sfdl::decryptString(QString password, QString encodedString)
{
    encodedString = encodedString.trimmed();

    if(encodedString.isEmpty())
    {
        return QString();
    }

    QByteArray data = QByteArray::fromBase64(encodedString.toLatin1());

    if(data.size() < 16 || (data.size() % 16) != 0)
    {
        return QString();
    }

    QString iv = encodedString.left(16);

    QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::CBC, QAESEncryption::PADDING::PKCS7);

    QByteArray hashKey = QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Md5);
    QByteArray hashIV = QCryptographicHash::hash(iv.toLocal8Bit(), QCryptographicHash::Md5);

    QByteArray decodeText = encryption.decode(data, hashKey, hashIV);
    if(decodeText.isEmpty())
    {
        return QString();
    }

    return QString::fromUtf8(encryption.removePadding(decodeText).mid(16));
}

bool sfdl::validateIPv4(QString ip)
{
    static const QRegularExpression re("^((25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)\\.){3}(25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)$");
    return re.match(ip.trimmed()).hasMatch();
}

QString sfdl::sanitizeString(const QString& input)
{
    QString cleanString = input.trimmed();

    cleanString.replace(QRegularExpression("[\\\\/]"), "_");
    cleanString.replace(QRegularExpression("[^\\p{L}\\p{N}_\\- \\.]"), "_");

    while(cleanString.startsWith('.'))
    {
        cleanString.remove(0, 1);
    }

    if(cleanString.length() > 100)
    {
        cleanString = cleanString.left(100);
    }

    cleanString = cleanString.trimmed();
    while(cleanString.endsWith('.') || cleanString.endsWith(' '))
    {
        cleanString.chop(1);
    }

    static const QRegularExpression reserved("^(CON|PRN|AUX|NUL|COM[0-9]|LPT[0-9])(\\..*)?$", QRegularExpression::CaseInsensitiveOption);
    if(reserved.match(cleanString).hasMatch())
    {
        cleanString.prepend('_');
    }

    if(cleanString.isEmpty())
    {
        cleanString = "mysterydownload";
    }

    return cleanString;
}

QString sfdl::ListElements(QDomElement root, QString tagname)
{
    QDomNodeList items = root.elementsByTagName(tagname);

    QString element;
    for(int i = 0; i < items.count(); i++)
    {
        QDomNode itemnode = items.at(i);
        if(itemnode.isElement())
        {
            QDomElement itemele = itemnode.toElement();
            element = itemele.text();
        }
    }
    return element;
}

void sfdl::setSFDL(QString file, QStringList passwordList)
{
    _SFDLFile = file;
    _passwordList = passwordList;
}

void sfdl::readSFDL()
{
    struct FinishGuard
    {
        sfdl *s;
        explicit FinishGuard(sfdl *p) : s(p) {}
        ~FinishGuard() { emit s->finished(); }
    } finishGuard(this);

    QString file = _SFDLFile;
    QStringList passwords = _passwordList;

    QByteArray data = loadSFDL(file);
    if(data.isEmpty())
    {
        sendLogText("<font color=\"red\">" + file + tr(": Kann SFDL Datei nicht laden! (Keine Daten)</font>"));
        return;
    }

    QDomDocument sfdl;

    if(!sfdl.setContent(data))
    {
        sendLogText("<font color=\"red\">" + file + tr(": Kann SFDL Datei nicht laden! (Keine XML-Daten/Datei)</font>"));
        return;
    }

    QStringList n_data;
    QStringList n_files;

    // sfdl file
    n_data.append("SFDLFile|" + file);

    QDomElement root = sfdl.firstChildElement();

    QString Encrypted;
    QString Description;
    QString Uploader;
    QString SFDLFileVersion;
    QString MaxDownloadThreads;

    Encrypted = ListElements(root, "Encrypted");

    const bool isEncrypted = (Encrypted.trimmed().compare("true", Qt::CaseInsensitive) == 0);
    const QString rawDescription = ListElements(root, "Description").trimmed();
    bool descriptionIsPlainFallback = false;

    if(rawDescription.isEmpty())
    {
        Description = sanitizeString(QFileInfo(_SFDLFile).baseName());
        descriptionIsPlainFallback = true;
    }
    else if(isEncrypted)
    {
        Description = rawDescription;
    }
    else
    {
        Description = sanitizeString(rawDescription);
    }

    Uploader = ListElements(root, "Uploader");
    SFDLFileVersion = ListElements(root, "SFDLFileVersion");
    MaxDownloadThreads = ListElements(root, "MaxDownloadThreads");

    n_data.append("Description|" + Description);
    n_data.append("Uploader|" + Uploader);
    n_data.append("SFDLFileVersion|" + SFDLFileVersion);
    n_data.append("Encrypted|" + Encrypted);
    n_data.append("MaxDownloadThreads|" + MaxDownloadThreads);

    QDomNodeList ConnectionInfos = root.elementsByTagName("ConnectionInfo");

    QString Name;

    QString Host;
    int Port = 0;
    QString Username;
    QString Password;
    QString AuthRequired;

    QString DataConnectionType;
    QString DataType;
    QString CharacterEncoding;
    QString EncryptionMode;
    QString ListMethod;
    QString DefaultPath;
    QString ForceSingleConnection;
    QString DataStaleDetection;
    QString SpecialServerMode;

    for(int i = 0; i < ConnectionInfos.count(); i++)
    {
        QDomNode snode = ConnectionInfos.at(i);
        if(snode.isElement())
        {
            QDomElement info = snode.toElement();

            Name = ListElements(info, "Name");
            Host = ListElements(info, "Host");
            Port = ListElements(info, "Port").toInt();
            Username = ListElements(info, "Username");
            Password = ListElements(info, "Password");
            AuthRequired = ListElements(info, "AuthRequired");

            DataConnectionType = ListElements(info, "DataConnectionType");
            DataType = ListElements(info, "DataType");
            CharacterEncoding = ListElements(info, "CharacterEncoding");
            EncryptionMode = ListElements(info, "EncryptionMode");
            ListMethod = ListElements(info, "ListMethod");
            DefaultPath = ListElements(info, "DefaultPath");
            ForceSingleConnection = ListElements(info, "ForceSingleConnection");
            DataStaleDetection = ListElements(info, "DataStaleDetection");
            SpecialServerMode = ListElements(info, "SpecialServerMode");
        }
    }

    if(Description.isEmpty() || Host.isEmpty() || Port <= 0 || Port > 65535)
    {
        sendLogText("<font color=\"red\">" + file + tr(": Unzureichende Daten in SFDL Datei! Kein Download möglich.</font>"));
        return;
    }

    n_data.append("Name|" + Name);
    n_data.append("Host|" + Host);
    n_data.append("Port|" + QString::number(Port));
    n_data.append("Username|" + Username);
    n_data.append("Password|" + Password);
    n_data.append("AuthRequired|" + AuthRequired);

    n_data.append("DataConnectionType|" + DataConnectionType);
    n_data.append("DataType|" + DataType);
    n_data.append("CharacterEncoding|" + CharacterEncoding);
    n_data.append("EncryptionMode|" + EncryptionMode);
    n_data.append("ListMethod|" + ListMethod);
    n_data.append("DefaultPath|" + DefaultPath);
    n_data.append("ForceSingleConnection|" + ForceSingleConnection);
    n_data.append("DataStaleDetection|" + DataStaleDetection);
    n_data.append("SpecialServerMode|" + SpecialServerMode);

    QString sfdlPassword = QString();

    if(isEncrypted)
    {
        bool ipTextOK = false;

        for(int i = 0; i < passwords.count(); i++)
        {
            QString passTest = decryptString(passwords.at(i), entryValue(n_data, 7));

            if(passTest != "__fail__to__decrypt__" && !passTest.isEmpty() && validateIPv4(passTest))
            {
                sfdlPassword = passwords.at(i);
                ipTextOK = true;
                break;
            }
        }

        if(!ipTextOK)
        {
            sendLogText("<font color=\"red\">" + file + tr(": Kann SFDL Datei nicht entschlüsseln! (Kein passendes Passwort in der Liste)</font>"));
            return;
        }

        sendLogText(file + tr(": Erfolgreich mit Passwort <b>") + sfdlPassword + tr("</b> entschlüsselt."));

        for(int i = 0; i < n_data.count(); i++)
        {
            const QString dataInfo = entryKey(n_data, i);

            if(dataInfo == "Host" ||
                    dataInfo == "Username" ||
                    dataInfo == "Password" ||
                    dataInfo == "Uploader" ||
                    dataInfo == "Description" ||
                    dataInfo == "DefaultPath")
            {
                if(dataInfo == "Description" && descriptionIsPlainFallback)
                {
                    continue;
                }

                QString dec = decryptString(sfdlPassword, entryValue(n_data, i));

                if(dataInfo == "Description")
                {
                    dec = sanitizeString(dec);
                    Description = dec;
                }
                else if(dataInfo == "Host")
                {
                    Host = dec;
                }
                else if(dataInfo == "Username")
                {
                    Username = dec;
                }
                else if(dataInfo == "Password")
                {
                    Password = dec;
                }

                n_data[i] = dataInfo + "|" + dec;
            }
        }
    }

    QDomNodeList Packages = root.elementsByTagName("Packages");
    for(int i = 0; i < Packages.count(); i++)
    {
        QDomNode snode = Packages.at(i);
        if(snode.isElement())
        {
            QDomElement info = snode.toElement();
            if(ListElements(info, "BulkFolderMode") == "true")
            {
                QDomNodeList SFDLPackage = info.elementsByTagName("SFDLPackage");
                for(int i = 0; i < SFDLPackage.count(); i++)
                {
                    QDomNode snode = SFDLPackage.at(i);
                    if(snode.isElement())
                    {
                        QDomElement info = snode.toElement();

                        QDomNodeList FileList = info.elementsByTagName("BulkFolderList");
                        for(int i = 0; i < FileList.count(); i++)
                        {
                            QDomNode snode = FileList.at(i);
                            if(snode.isElement())
                            {
                                QDomElement info = snode.toElement();

                                QDomNodeList FileInfo = info.elementsByTagName("BulkFolder");
                                for(int i = 0; i < FileInfo.count(); i++)
                                {
                                    QDomNode snode = FileInfo.at(i);
                                    if(snode.isElement())
                                    {
                                        QDomElement info = snode.toElement();

                                        QString BulkFolderPath = ListElements(info, "BulkFolderPath");

                                        if(isEncrypted)
                                        {
                                            BulkFolderPath = decryptString(sfdlPassword, BulkFolderPath);
                                        }

                                        if(hasPathTraversal(BulkFolderPath))
                                        {
                                            sendLogText("<font color=\"red\">" + file + tr(": Unsicherer Pfad in SFDL Datei (\"..\")! Abbruch.</font>"));
                                            return;
                                        }

                                        n_data.append("BulkFolderPath|" + BulkFolderPath);

                                        #ifdef QT_DEBUG
                                            qDebug() << "BulkFolderPath (blank): " << BulkFolderPath;
                                        #endif
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                n_data.append("BulkFolderPath|false");

                QDomNodeList SFDLPackage = info.elementsByTagName("SFDLPackage");
                for(int i = 0; i < SFDLPackage.count(); i++)
                {
                    QDomNode snode = SFDLPackage.at(i);
                    if(snode.isElement())
                    {
                        QDomElement info = snode.toElement();

                        QDomNodeList FileList = info.elementsByTagName("FileList");
                        for(int i = 0; i < FileList.count(); i++)
                        {
                            QDomNode snode = FileList.at(i);
                            if(snode.isElement())
                            {
                                QDomElement info = snode.toElement();

                                QDomNodeList FileInfo = info.elementsByTagName("FileInfo");
                                for(int i = 0; i < FileInfo.count(); i++)
                                {
                                    QDomNode snode = FileInfo.at(i);
                                    if(snode.isElement())
                                    {
                                        QDomElement info = snode.toElement();

                                        qlonglong size = ListElements(info, "FileSize").toLongLong();

                                        QString theFilePath;
                                        theFilePath = ListElements(info, "DirectoryPath");

                                        QString FileFullPath;
                                        FileFullPath = ListElements(info, "FileFullPath");

                                        QString theFileName;
                                        theFileName = ListElements(info, "FileName");

                                        #ifdef QT_DEBUG
                                            qDebug() << "size: " << size;
                                            qDebug() << "theFilePath: " << theFilePath;
                                            qDebug() << "theFileName: " << theFileName;
                                            qDebug() << "FileFullPath: " << FileFullPath;
                                        #endif

                                        if(hasPathTraversal(FileFullPath))
                                        {
                                            sendLogText("<font color=\"red\">" + file + tr(": Unsicherer Dateipfad in SFDL Datei (\"..\")! Abbruch.</font>"));
                                            return;
                                        }

                                        n_files.append(FileFullPath + "|" + QString::number(size));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    emit sendSFDLData(n_data, n_files);
}
