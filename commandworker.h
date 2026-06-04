#ifndef COMMANDWORKER_H
#define COMMANDWORKER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QVector>

struct CustomCommand {
    QString id;
    QString name;
    QString commandLine;
    bool enabled = true;
};

class CommandWorker : public QObject
{
    Q_OBJECT

public:
    explicit CommandWorker(const QVector<CustomCommand>& commands, const QString& downloadPath, QObject* parent = nullptr);
    virtual ~CommandWorker();

public slots:
    void startExecution();

signals:
    void commandStarted(const QString& commandName);
    void commandFinished(const QString& commandName, int exitCode, bool success);
    void commandSkipped(const QString& commandName);
    void logOutput(const QString& output);
    void allCommandsFinished(bool atLeastOneExecuted);

private:
    void executeNext();
    QString prepareCommand(const QString& rawCommand) const;
    QVector<CustomCommand> m_commands;
    QString m_downloadPath;
    int m_currentIndex;
    bool m_atLeastOneExecuted;
};

#endif // COMMANDWORKER_H

