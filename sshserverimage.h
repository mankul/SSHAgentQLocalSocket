#ifndef SSHSERVERIMAGE_H
#define SSHSERVERIMAGE_H
#include<QString>
#include<QObject>
class SshServerImage//: public QObject
{
private:
    QString sshAuthSock = "SSH_AUTH_SOCK";
public:
    SshServerImage();
    void setServerName();
    QString serverPath;
};

#endif // SSHSERVERIMAGE_H
