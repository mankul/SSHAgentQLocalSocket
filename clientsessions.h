#ifndef CLIENTSESSIONS_H
#define CLIENTSESSIONS_H

#include<qobject.h>
#include<qlocalsocket.h>
#include<localclientsocket.h>
#include "sshserverimage.h"
class ClientSessions: public QObject
{
    Q_OBJECT

public:

    ClientSessions();
    Q_INVOKABLE void createNewClientSocket();
    Q_INVOKABLE void connectClientToServer();

    LocalClientSocket *localClientSocket() const;

    Q_INVOKABLE void fetchAddedIdentities();

private:
    LocalClientSocket * client;
    void contactServer();
    SshServerImage * sshServerImage;
};


#endif // CLIENTSESSIONS_H
