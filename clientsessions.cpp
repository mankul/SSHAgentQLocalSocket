#include "clientsessions.h"

ClientSessions::ClientSessions()
{
    qDebug()<<Q_FUNC_INFO;
}

void ClientSessions::createNewClientSocket(){
    client = new LocalClientSocket();
    qDebug()<<Q_FUNC_INFO<<"a local socket client is created";
}


void ClientSessions::connectClientToServer(){
    qDebug()<<Q_FUNC_INFO<<"new client looking for connection to server";
    client->connectToServer();
}


void ClientSessions::fetchAddedIdentities(){
    qDebug()<<Q_FUNC_INFO;
    client->getAllIdentities();
}


LocalClientSocket *ClientSessions::localClientSocket() const
{
    return client;
}
