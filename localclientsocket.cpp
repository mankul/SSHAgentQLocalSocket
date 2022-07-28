#include "localclientsocket.h"



LocalClientSocket::LocalClientSocket()
{
    clientSocket = new QLocalSocket();
    qDebug()<<"new client socket created";
    connect(clientSocket, &QLocalSocket::connected, this, & LocalClientSocket::onNewConnection);
}

void LocalClientSocket::connectToServer(){
    clientSocket->connectToServer("localServer", QIODevice::ReadWrite);
    qDebug()<<Q_FUNC_INFO<<"connected to client";
}

void LocalClientSocket::onNewConnection(){
    qDebug()<<Q_FUNC_INFO<<"on new connection";
}


bool LocalClientSocket::getAllIdentities(){
    qDebug()<<Q_FUNC_INFO<<" fetching all ssh identities";
    char * identityMessage =reinterpret_cast<char*>( (&SSH_AGENTC_REQUEST_IDENTITIES), sizeof( SSH_AGENTC_REQUEST_IDENTITIES) ) ;
    clientSocket->write(identityMessage);
    qDebug()<<Q_FUNC_INFO<<" message written to socket";
    char buffer [1024];
    clientSocket->read(buffer, 1023);
    qDebug()<<Q_FUNC_INFO<<"read from local socket "<<buffer;
}

QString LocalClientSocket::getServerPath(){
    return clientSocket->fullServerName();
}
