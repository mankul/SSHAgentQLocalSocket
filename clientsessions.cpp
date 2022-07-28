#include "clientsessions.h"

ClientSessions::ClientSessions()
{
    qDebug()<<Q_FUNC_INFO;
    sshServerImage = new SshServerImage();
    sshServerImage->setServerName();
    qDebug()<<"server path is "<<sshServerImage->serverPath;

}

void ClientSessions::createNewClientSocket(){
    client = new LocalClientSocket();
    qDebug()<<Q_FUNC_INFO<<"a local socket client is created";
}


void ClientSessions::connectClientToServer(){
    qDebug()<<Q_FUNC_INFO<<"new client looking for connection to server";
    client->connectToServer(sshServerImage->serverPath);
}


void ClientSessions::fetchAddedIdentities(){
    qDebug()<<Q_FUNC_INFO;
    client->getAllIdentities();
}

void ClientSessions::contactServer(){

}


LocalClientSocket *ClientSessions::localClientSocket() const
{
    return client;
}
