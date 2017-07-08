#include "myserver.h"

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    server_ = new QTcpServer(this);

    connect(server_, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server_->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server Could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

void MyServer::newConnection()
{
    QTcpSocket *socket_ = server_->nextPendingConnection();

    socket_->write(" WELCOME TO MY OWNER QTCPSERVER CREATED WITH QT CREATOR \r\n ");
    socket_->flush();

    socket_->waitForBytesWritten(3000);

    socket_->close();
}


