#include "unrar.h"

UnRAR::UnRAR(QStringList data) : data(data)
{
    mutex.lock();
    id = this->data.at(0);
    unar = this->data.at(1);
    file = this->data.at(2);
    destPath = this->data.at(3);

    m_program = unar;
    m_arguments = QStringList() << "x" << "-kb" << "-y" << file << destPath;

    mutex.unlock();
}

UnRAR::~UnRAR()
{
    if (p) {
        if (p->state() == QProcess::Running) {
            p->kill();
        }
        p->deleteLater();
    }
}

void UnRAR::startUnRAR()
{
    p = new QProcess(this);

    if(p)
    {
        p->setEnvironment(QProcess::systemEnvironment());
        p->setProcessChannelMode(QProcess::MergedChannels);

        connect(p, &QProcess::readyReadStandardOutput, this, &UnRAR::ReadOut);
        connect(p, &QProcess::errorOccurred, this, [this](QProcess::ProcessError errorError) {
            QString msg = tr("Systemfehler beim Starten von UnRAR!");
            if(errorError == QProcess::FailedToStart)
            {
                msg = tr("unrar.exe wurde nicht gefunden.");
            }
            else if (errorError == QProcess::Crashed)
            {
                msg = tr("unrar.exe ist im Hintergrund abgestürzt.");
            }
            emit error(msg);
        });
        connect(p, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
                this, [this](int exitCode, QProcess::ExitStatus exitStatus) {
                    if(exitStatus == QProcess::CrashExit)
                    {
                        return;
                    }

                    if(exitCode != 0)
                    {
                        QString msg = tr("Unrar fehlgeschlagen (Code %1): ").arg(exitCode);
                        if(exitCode == 3)
                        {
                            msg += tr("CRC-Fehler (Archiv beschädigt).");
                        }
                        else if (exitCode == 11)
                        {
                            msg += tr("Falsches Passwort oder Lesefehler.");
                        }
                        else
                        {
                            msg += tr("Unbekannter UnRAR-Fehler.");
                        }
                        emit error(msg);
                    }
                    else
                    {
                        emit finished();
                    }
                });

        p->start(m_program, m_arguments);
    }
}

void UnRAR::ReadOut()
{
    if(p)
    {
        bool update = false;
        QString output = p->readAllStandardOutput();

#ifdef QT_DEBUG
        qDebug() << "output: " << output;
#endif

        QRegularExpression percentage("\b\b\b\b[\\s]+([0-9]{1,3})|(All OK)");
        QRegularExpression progressFile("\\r\\n\\r\\nExtracting from (.+)\\r\\n");

        QRegularExpressionMatch match1 = percentage.match(output);
        QRegularExpressionMatch match2 = progressFile.match(output);

        if(match1.hasMatch())
        {
            if(match1.captured(2) == "All OK")
            {
                progress = 100;
            }
            else
            {
                progress = match1.captured(1).toInt();
            }
            update = true;
        }

        if(match2.hasMatch())
        {
            QString filename = match2.captured(1);

            if(filename.contains("\\"))
            {
                fileName = filename.split("\\").last();
            }

            if(fileName.contains("/"))
            {
                fileName = filename.split("/").last();
            }
            update = true;
        }

        if(update)
        {
            emit updateUnRarProgress(id, fileName, progress);
        }
    }
}


