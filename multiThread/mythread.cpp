#include "mythread.h"

MyThread::MyThread(int ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor_ = ID;
}

void MyThread::run()
{
    // thread starts here
    qDebug() << socketDescriptor_ << " Starting thread";
    socket_ = new QTcpSocket();
    if(!socket_->setSocketDescriptor(this->socketDescriptor_))
    {
        emit error(socket_->error());
        return;
    }

    connect(socket_, SIGNAL(readyRead()), this, SLOT(readyRead()),Qt::DirectConnection);
    connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor_ << " Client connected";

    // make this thread a loop
    exec();
}

void MyThread::readyRead()
{
    QByteArray Data = socket_->readAll();

    qDebug() << socketDescriptor_ << " Data in: " << Data;

    socket_->write(Data);
}

void MyThread::disconnected()
{
    qDebug() << socketDescriptor_ << " Disconnected";
    socket_->deleteLater();
    exit(0);
}
