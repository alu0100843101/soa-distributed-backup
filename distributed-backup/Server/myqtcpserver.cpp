#include "myqtcpserver.h"

MyQTcpServer::MyQTcpServer(QHostAddress address, quint16 port, QString path, QObject *parent):
    address_(address), port_(port), path_(path), QTcpServer(parent)
{}

void MyQTcpServer::start()
{
    if ( this->listen(address_, port_) )
        qDebug() << "Server Connected " << address_.toString() << ":" << port_;
    else
        qDebug() << "Server can not connect";
}

void MyQTcpServer::end(){
    emit closeSignal();
}

void MyQTcpServer::incomingConnection(qintptr socketDescriptor)
{
    MySocket *mySocket_ = new MySocket(socketDescriptor, path_, this);
    connect(mySocket_, SIGNAL(finished()), mySocket_, SLOT(deleteLater()));

    mySocket_->start();
    connect(mySocket_, SIGNAL(SignalClose()), this, SLOT(end()));
}
