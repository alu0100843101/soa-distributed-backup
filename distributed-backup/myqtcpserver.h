#ifndef MYQTCPSERVER_H
#define MYQTCPSERVER_H

#include <QMainWindow>
#include <QTcpServer>

class MyQTcpServer : public QTcpServer
{
    Q_OBJECT

public:
    MyQTcpServer(QHostAddress address, quint16 port, QString path, QObject *parent = 0);

public slots:
    void start();
    void end();

signals:
    void closeSignal();

protected:
    void incomingConnection(qintptr socketDescriptor);

private:
    QHostAddress address_;
    quint16 port_;
    QString path_;
};

#endif // MYQTCPSERVER_H
