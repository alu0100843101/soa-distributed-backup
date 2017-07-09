#ifndef MYSERVER_H
#define MYSERVER_H

#include <QThreadPool>
#include <QTcpServer>
#include <QDebug>

#include "myrunnable.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    void myStart();

signals:

public slots:

protected:
    void incomingConnection(int hundle);

private:
    QThreadPool *pool_;

};

#endif // MYSERVER_H
