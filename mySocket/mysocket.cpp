#include "mysocket.h"

MySocket::MySocket(QObject *parent) : QObject(parent)
{}

void MySocket::myConnect()
{
    socket_= new QTcpSocket(this);

    connect(socket_, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket_, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
    connect(socket_, SIGNAL(readyRead()), this, SLOT(readyRead()));

    qDebug() << "Connecting...";

    socket_->connectToHost("google.com", 80);

    if(!socket_->waitForConnected(3000))
    {
        qDebug() << "Error: " << socket_->errorString();
    }

    /**
    if(socket_->waitForConnected(3000))
    {
        qDebug() << "Connected!";

        //Send
        socket_->write("hello server");
        socket_->waitForBytesWritten(1000);
        socket_->waitForReadyRead(3000);

        //Got
        qDebug() << "Reading: " << socket_->bytesAvailable();
        qDebug() << socket_->readAll();

        //Close
        socket_->close();
    }
    else
    {
        qDebug() << "Not Connected!";
    }
    **/
}

void MySocket::connected()
{
    qDebug() << "Connected!";

    socket_->write(" WELCOME TO MY OWNER QTCPSERVER CREATED WITH QT CREATOR \r\n ");
}

void MySocket::disconnected()
{
    qDebug() << "Disconnected!";
}

void MySocket::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes;
}

void MySocket::readyRead()
{
    qDebug() << "Reading...";
    qDebug() << socket_->readAll();
}

