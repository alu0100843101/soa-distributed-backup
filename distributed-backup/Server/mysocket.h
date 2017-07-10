#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QDir>
#include <QFile>
#include <QThread>
#include <QTcpSocket>
#include <QDataStream>
#include <QHostAddress>
#include <QNetworkInterface>

class MySocket : public QThread
{
    Q_OBJECT

public:
    MySocket(qintptr socketDescriptor, QString path, QObject *parent = 0);
    ~MySocket();

protected:
    void run() Q_DECL_OVERRIDE;

signals:
    void SignalClose();

private slots:
    void ReadyRead();
    void SlotClose();

private:
    qintptr     socketDescriptor_;
    QTcpSocket *socket_;
    qint32      blockSize_;
    qint64      filesize_;
    QString     path_;
};

#endif // MYSOCKET_H
