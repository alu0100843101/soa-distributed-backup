#ifndef MYSERVER_H
#define MYSERVER_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);

signals:

public slots:
    void newConnection();

private:
    QTcpServer *server_;
};

#endif // MYSERVER_H
