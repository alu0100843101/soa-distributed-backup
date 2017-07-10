#include "mysocket.h"

MySocket::MySocket(qintptr socketDescriptor, QString path, QObject *parent):
QThread(parent), socketDescriptor_(socketDescriptor), blockSize_(0), path_(path)
{}

MySocket::~MySocket()
{
    delete socket_;
}

void MySocket::run()
{
    socket_ = new QTcpSocket();

    connect(socket_, SIGNAL(readyRead()), this, SLOT(ReadyRead()), Qt::DirectConnection);
    connect(socket_, SIGNAL(disconnected()), this, SLOT(SlotClose()), Qt::DirectConnection);

    exec();
}

void MySocket::ReadyRead()
{
    QDataStream in(socket_);
    //in.setVersion(QDataStream::Qt_5_8);

    in >> filesize_;

    QString fileName, path;

    in >> fileName;
    path = fileName;

    QByteArray byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream << 1;
    socket_->write(byteArray);
    socket_->waitForBytesWritten(-1);
    socket_->flush();

    //Comprobamos que exista el directorio, sino lo creamos.
    if(fileName.lastIndexOf("/")!=0){
        path.truncate(fileName.lastIndexOf("/"));
        QDir dir(path_ + path);
        if (!dir.exists()){
             dir.mkpath(path_ + path);
        }
    }

    QFile files(path_ + fileName);
    files.open(QIODevice::Append);

    QByteArray read;
    while(socket_->waitForReadyRead())
    {
        read.clear();
        if(socket_->bytesAvailable()>(filesize_-files.size())){
            read = socket_->read(filesize_-files.size());
        }
        else{
            read = socket_->read(socket_->bytesAvailable());
        }

        files.write(read);

        if(files.size()== filesize_){
            files.close();
            filesize_=0;
            break;
        }
    }

    socket_->write(byteArray);
    socket_->waitForBytesWritten(-1);
    socket_->flush();
}

void MySocket::SlotClose()
{
    socket_->close();
    emit SignalClose();
    quit();
}
