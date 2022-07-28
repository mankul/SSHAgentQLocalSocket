#include "sshserverimage.h"
#include<QDebug>
#include<QProcess>
#include<QList>

SshServerImage::SshServerImage()
{
    qDebug()<<Q_FUNC_INFO;
}

void SshServerImage::setServerName(){
    QString ssh_path_command = QString("echo $%1").arg(sshAuthSock);
    qDebug()<<Q_FUNC_INFO<<sshAuthSock<<ssh_path_command;
    QProcess * proc = new QProcess();

    //    connect(proc, &QProcess::readyReadStandardOutput, [=](){

    //    });
    proc->start("bash", QStringList()<<"-c"<<ssh_path_command );
    //    QString output = proc->readAllStandardOutput();
    proc->waitForFinished();
    QString commandOutput = proc->readAllStandardOutput();
    QStringList list = commandOutput.split("\n");
    serverPath = list[0];
}
