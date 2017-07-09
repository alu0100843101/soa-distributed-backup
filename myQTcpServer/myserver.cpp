#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
    pool_ = new QThreadPool(this);
    pool_->setMaxThreadCount(5);
}

void MyServer::myStart()
{
    if(this->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server started";
    }
    else
    {
        qDebug() << "Server did not start!";
    }
}

void MyServer::incomingConnection(int handle)
{
    MyRunnable *task_ = new MyRunnable();
    task_->setAutoDelete(true);

    task_->SocketDescriptor = handle;
    pool_->start(task_);
}
