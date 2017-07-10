#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QTcpSocket>
#include <QProcess>
#include <QThread>
#include <QFile>
#include <QDir>

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
