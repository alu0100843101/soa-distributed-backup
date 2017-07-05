#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>


class MySocket : public QObject
{
    Q_OBJECT
public:
    explicit MySocket(QObject *parent = 0);

    void myConnect();

signals:


public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private:
    QTcpSocket *socket_;
};

#endif // MYSOCKET_H
