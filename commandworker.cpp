#include "commandworker.h"
#include <QProcess>

#if defined(Q_OS_WIN)
#define SHELL_PROG "cmd.exe"
#define SHELL_ARG "/c"
#else
#define SHELL_PROG "/bin/sh"
#define SHELL_ARG "-c"
#endif

CommandWorker::CommandWorker(const QVector<CustomCommand>& commands,
                             const QString& downloadPath,
                             QObject* parent)
    : QObject(parent)
    , m_commands(commands)
    , m_downloadPath(downloadPath)
    , m_currentIndex(0)
    , m_atLeastOneExecuted(false)
{
}

CommandWorker::~CommandWorker(){}

void CommandWorker::startExecution()
{
    m_currentIndex = 0;
    m_atLeastOneExecuted = false;
    executeNext();
}

void CommandWorker::executeNext()
{
    if(m_currentIndex >= m_commands.size())
    {
        emit allCommandsFinished(m_atLeastOneExecuted);
        return;
    }

    const CustomCommand& cmd = m_commands.at(m_currentIndex);

    if(!cmd.enabled)
    {
        emit commandSkipped(cmd.name);
        m_currentIndex++;
        executeNext();
        return;
    }

    m_atLeastOneExecuted = true;
    emit commandStarted(cmd.name);

    QString finalCommandLine = prepareCommand(cmd.commandLine);
    QProcess* process = new QProcess(this);

    if(!m_downloadPath.isEmpty())
    {
        process->setWorkingDirectory(m_downloadPath);
    }

    connect(process, &QProcess::readyReadStandardOutput, [this, process]() {
        emit logOutput(QString::fromUtf8(process->readAllStandardOutput()));
    });
    connect(process, &QProcess::readyReadStandardError, [this, process]() {
        emit logOutput(QString::fromUtf8(process->readAllStandardError()));
    });

    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            [this, process, cmd](int exitCode, QProcess::ExitStatus exitStatus) {

                bool success = (exitStatus == QProcess::NormalExit && exitCode == 0);
                emit commandFinished(cmd.name, exitCode, success);

                process->deleteLater();
                m_currentIndex++;
                executeNext();
            });

    process->start(SHELL_PROG, QStringList() << SHELL_ARG << finalCommandLine);
}

QString CommandWorker::prepareCommand(const QString& rawCommand) const
{
    QString finalCommand = rawCommand;
    finalCommand.replace("%DOWNLOADPATH%", m_downloadPath, Qt::CaseInsensitive);
    return finalCommand;
}

