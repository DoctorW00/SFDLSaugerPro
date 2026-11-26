#ifndef QURLINFO_COMPAT_H
#define QURLINFO_COMPAT_H

/*
    QUrlInfo compatibility header for QFtp.

    QUrlInfo was removed from QtNetwork in Qt 5. This drop-in replacement
    provides the API needed by QFtp for both Qt 5 and Qt 6.
*/

#include <QtCore/qglobal.h>
#include <QtCore/qstring.h>
#include <QtCore/qdatetime.h>

class QUrlInfo
{
public:
    enum PermissionSpec {
        ReadOwner = 00400, WriteOwner = 00200, ExeOwner = 00100,
        ReadGroup = 00040, WriteGroup = 00020, ExeGroup = 00010,
        ReadOther = 00004, WriteOther = 00002, ExeOther = 00001
    };

    QUrlInfo() = default;

    QUrlInfo(const QString &name, int permissions, const QString &owner,
             const QString &group, qint64 size, const QDateTime &lastModified,
             const QDateTime &lastRead, bool isDir, bool isFile, bool isSymLink,
             bool isWritable, bool isReadable, bool isExecutable)
        : m_valid(true), m_name(name), m_owner(owner), m_group(group),
        m_lastModified(lastModified), m_lastRead(lastRead),
        m_size(size), m_permissions(permissions),
        m_isDir(isDir), m_isFile(isFile), m_isSymLink(isSymLink),
        m_isWritable(isWritable), m_isReadable(isReadable)
    {
        if (isExecutable)
            m_permissions |= ExeOwner;
    }

    // setters
    virtual void setName(const QString &name)               { m_valid = true; m_name = name; }
    virtual void setDir(bool b)                             { m_valid = true; m_isDir = b; }
    virtual void setFile(bool b)                            { m_valid = true; m_isFile = b; }
    virtual void setSymLink(bool b)                         { m_valid = true; m_isSymLink = b; }
    virtual void setOwner(const QString &owner)             { m_valid = true; m_owner = owner; }
    virtual void setGroup(const QString &group)             { m_valid = true; m_group = group; }
    virtual void setSize(qint64 size)                       { m_valid = true; m_size = size; }
    virtual void setWritable(bool b)                        { m_valid = true; m_isWritable = b; }
    virtual void setReadable(bool b)                        { m_valid = true; m_isReadable = b; }
    virtual void setPermissions(int p)                      { m_valid = true; m_permissions = p; }
    virtual void setLastModified(const QDateTime &dt)       { m_valid = true; m_lastModified = dt; }

    virtual ~QUrlInfo() = default;

    // getters
    QString name() const            { return m_name; }
    int permissions() const         { return m_permissions; }
    QString owner() const           { return m_owner; }
    QString group() const           { return m_group; }
    qint64 size() const             { return m_size; }
    QDateTime lastModified() const  { return m_lastModified; }
    QDateTime lastRead() const      { return m_lastRead; }
    bool isDir() const              { return m_valid && m_isDir; }
    bool isFile() const             { return m_valid && m_isFile; }
    bool isSymLink() const          { return m_valid && m_isSymLink; }
    bool isWritable() const         { return m_valid && m_isWritable; }
    bool isReadable() const         { return m_valid && m_isReadable; }
    bool isExecutable() const       { return m_valid && (m_permissions & ExeOwner); }
    bool isValid() const            { return m_valid; }

    bool operator==(const QUrlInfo &o) const
    {
        return m_valid == o.m_valid
               && m_name == o.m_name
               && m_owner == o.m_owner
               && m_group == o.m_group
               && m_size == o.m_size
               && m_permissions == o.m_permissions
               && m_lastModified == o.m_lastModified
               && m_lastRead == o.m_lastRead
               && m_isDir == o.m_isDir
               && m_isFile == o.m_isFile
               && m_isSymLink == o.m_isSymLink
               && m_isWritable == o.m_isWritable
               && m_isReadable == o.m_isReadable;
    }
    bool operator!=(const QUrlInfo &o) const { return !(*this == o); }

private:
    bool m_valid = false;
    QString m_name;
    QString m_owner;
    QString m_group;
    QDateTime m_lastModified;
    QDateTime m_lastRead;
    qint64 m_size = 0;
    int m_permissions = 0;
    bool m_isDir = false;
    bool m_isFile = true;
    bool m_isSymLink = false;
    bool m_isWritable = true;
    bool m_isReadable = true;
};

#endif // QURLINFO_COMPAT_H
