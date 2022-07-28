#ifndef LOCALCLIENTSOCKET_H
#define LOCALCLIENTSOCKET_H

#include<qlocalsocket.h>
class LocalClientSocket: public QObject
{
    Q_OBJECT
public:
    LocalClientSocket();
    void connectToServer();
    Q_INVOKABLE QString getServerPath();
    void onNewConnection();
    Q_INVOKABLE bool getAllIdentities();
private:
    const quint8 SSH_AGENTC_REQUEST_IDENTITIES = 11;
    QLocalSocket * clientSocket;
};
#endif // LOCALCLIENTSOCKET_H
