#include "localclientsocket.h"



LocalClientSocket::LocalClientSocket()
{
    clientSocket = new QLocalSocket();
    qDebug()<<"new client socket created";
    connect(clientSocket, &QLocalSocket::connected, this, & LocalClientSocket::onNewConnection);
    connect(clientSocket, &QLocalSocket::readyRead, this , &LocalClientSocket::readFromServer);
}

void LocalClientSocket::connectToServer(QString serverPath){
    clientSocket->connectToServer(serverPath, QIODevice::ReadWrite);
    qDebug()<<Q_FUNC_INFO<<"connected to client";
}

void LocalClientSocket::onNewConnection(){
    qDebug()<<Q_FUNC_INFO<<"on new connection";
}

void LocalClientSocket::readFromServer(){
    qDebug()<<Q_FUNC_INFO;
}

bool LocalClientSocket::getAllIdentities(){
    qDebug()<<Q_FUNC_INFO<<" fetching all ssh identities";
    const char * identityMessage =reinterpret_cast<const char*>(&SSH_AGENTC_REQUEST_IDENTITIES) ;
    qint64 messageLength = strlen(identityMessage);
    qint64 result = clientSocket->write(identityMessage, messageLength);
    qDebug()<<Q_FUNC_INFO<<" message written to socket "<<result;
    clientSocket->waitForBytesWritten();
}

QString LocalClientSocket::getServerPath(){
    return clientSocket->fullServerName();
}
