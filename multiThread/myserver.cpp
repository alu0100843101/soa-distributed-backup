#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}

void MyServer::myStart()
{
    if(!this->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening...";
    }
}

void MyServer::incomingConnection(int socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";

    MyThread *thread_ = new MyThread(socketDescriptor, this);

    connect(thread_, SIGNAL(finished()), thread_, SLOT(deleteLater()));
    thread_->start();
}
