#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QMainWindow>
#include <QAbstractSocket>

#include "myqtcpserver.h"

namespace Ui {
class MyServer;
}

class MyServer : public QMainWindow //public QTcpServer
{
    Q_OBJECT

public:
    explicit MyServer(QWidget *parent = 0);
    ~MyServer();

public slots:
    //void myStart();

protected:
    //void incomingConnection(qintptr socketDescriptor);

private slots:
    void on_FindPushButton_clicked();
    void on_StartPushButton_clicked();

private:
    Ui::MyServer *ui;

    MyQTcpServer *server_;

};

#endif // MYSERVER_H

