#include "unrar.h"

UnRAR::UnRAR(QStringList data) : data(data)
{
    mutex.lock();
    id = this->data.at(0);
    unar = this->data.at(1);
    file = this->data.at(2);
    destPath = this->data.at(3);
    command = unar + " x -kb -y " + file + " " + destPath;
    mutex.unlock();
}

UnRAR::~UnRAR()
{

}

void UnRAR::startUnRAR()
{
    #ifdef QT_DEBUG
        qDebug() << "id: " << id;
        qDebug() << "unar: " << unar;
        qDebug() << "file: " << file;
        qDebug() << "destPath: " << destPath;
        qDebug() << "command: " << command;
    #endif

    p = new QProcess(this);

    if(p)
    {
        p->setEnvironment(QProcess::systemEnvironment());
        p->setProcessChannelMode(QProcess::MergedChannels);

        p->start(command);
        p->waitForStarted();

        connect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(ReadOut()) );
        connect(p, SIGNAL(readyReadStandardError()), this, SLOT(ReadErr()) );
        connect(p, SIGNAL(finished(int)), p, SLOT(deleteLater()));
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

        // QRegularExpression percentage("\b\b\b\b[\\s]+([0-9]{1,3}|OK)");
        QRegularExpression percentage("\b\b\b\b[\\s]+([0-9]{1,3})|(All OK)");
        QRegularExpression progressFile("\\r\\n\\r\\nExtracting from (.+)\\r\\n");

        QRegularExpressionMatch match1 = percentage.match(output);
        QRegularExpressionMatch match2 = progressFile.match(output);

        if(match1.hasMatch())
        {
            // if(match1.captured(1) == "OK")
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
            updateUnRarProgress(id, fileName, progress);
        }
    }
}

void UnRAR::ReadErr()
{
    if(p)
    {
        #ifdef QT_DEBUG
            qDebug() << "ReadErr: " << p->readAllStandardError();
        #endif
    }
}
