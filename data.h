#ifndef DATA_H
#define DATA_H

#include <QObject>

struct SFDL
{
    SFDL(int id = int(),
         const QString& fileName = QString(),
         const QString& filePath = QString(),
         const QString& Description = QString(),
         const QString& Uploader = QString(),
         const QString& SFDLFileVersion = QString(),
         const QString& Encrypted = QString(),
         const QString& Host = QString(),
         int Port = int(),
         const QString& Username = QString(),
         const QString& Password = QString(),
         bool AuthRequired = bool(),
         const QString& DataConnectionType = QString(),
         const QString& DataType = QString(),
         const QString& CharacterEncoding = QString(),
         const QString& EncryptionMode = QString(),
         const QString& ListMethod = QString(),
         const QString& DefaultPath = QString(),
         bool ForceSingleConnection = bool(),
         bool DataStaleDetection = bool(),
         bool SpecialServerMode = bool(),
         const QStringList& FileList = QStringList()
         ):

         sfdl_id(id),
         sfdl_fileName(fileName),
         sfdl_filePath(filePath),
         sfdl_Description(Description),
         sfdl_Uploader(Uploader),
         sfdl_SFDLFileVersion(SFDLFileVersion),
         sfdl_Encrypted(Encrypted),
         sfdl_Host(Host),
         sfdl_Port(Port),
         sfdl_Username(Username),
         sfdl_Password(Password),
         sfdl_AuthRequired(AuthRequired),
         sfdl_DataConnectionType(DataConnectionType),
         sfdl_DataType(DataType),
         sfdl_CharacterEncoding(CharacterEncoding),
         sfdl_EncryptionMode(EncryptionMode),
         sfdl_ListMethod(ListMethod),
         sfdl_DefaultPath(DefaultPath),
         sfdl_ForceSingleConnection(ForceSingleConnection),
         sfdl_DataStaleDetection(DataStaleDetection),
         sfdl_SpecialServerMode(SpecialServerMode),
         sfdl_FileList(FileList)
    {

    }

    int sfdl_id;
    QString sfdl_fileName;
    QString sfdl_filePath;
    QString sfdl_Description;
    QString sfdl_Uploader;
    QString sfdl_SFDLFileVersion;
    QString sfdl_Encrypted;
    QString sfdl_Host;
    int sfdl_Port;
    QString sfdl_Username;
    QString sfdl_Password;
    bool sfdl_AuthRequired;
    QString sfdl_DataConnectionType;
    QString sfdl_DataType;
    QString sfdl_CharacterEncoding;
    QString sfdl_EncryptionMode;
    QString sfdl_ListMethod;
    QString sfdl_DefaultPath;
    bool sfdl_ForceSingleConnection;
    bool sfdl_DataStaleDetection;
    bool sfdl_SpecialServerMode;
    QStringList sfdl_FileList;

};

#endif // DATA_H
