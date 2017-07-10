#include "senddestination.h"

SendDestination::SendDestination(QString path, QStringList files, QHostAddress address, quint16 port):
    path_(path), files_(files), address_(address), port_(port)
{}

void SendDestination::run()
{
    QTcpSocket *sct_ = new QTcpSocket();

    connect(sct_, SIGNAL(disconnected()), sct_, SLOT(deleteLater()));
    connect(sct_, SIGNAL(disconnected()), this, SLOT(closeSlot()));

    sct_->connectToHost(address_, port_);
    sct_->waitForConnected();

    QListIterator<QString> it (files_);
        while (it.hasNext()) {
            QString current = it.next();

            file_ = new QFile(current);

            //Abriendo el archivo.
            file_->open(QIODevice::ReadOnly);
            if(!(file_->open(QIODevice::ReadOnly))){
                qDebug() << "Error al abrir el archivo";
                exit(0);
            }

            QByteArray byteArray_;
            QDataStream out(&byteArray_, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_5_8);


            current.remove(0, path_.size());
            out << (quint64)0 << current; //name

            out.device()->seek(0);
            out << (quint64)(file_->size()); //size

            qint64 ba = 0;
            while (ba < byteArray_.size()) {
                qint64 wba = sct_->write(byteArray_);
                ba += wba; //Bytes escritos.
                sct_->waitForBytesWritten();
            }
            sct_->waitForReadyRead(-1);
            sct_->flush();

            QByteArray read;
            while(1)
            {
                read.clear();
                read = file_->read(32768*8);
                if(read.size()==0) break; //Si no se lee nada se sale.

                sct_->waitForBytesWritten(-1);
                read.clear();
            }
            file_->close();

            sct_->waitForReadyRead(-1);
            sct_->flush();
        }

        sct_->disconnectFromHost();
}

void SendDestination::closeSlot()
{
    qDebug() << "Close";
}
