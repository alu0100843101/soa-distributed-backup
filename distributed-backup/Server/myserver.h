#ifndef MYSERVER_H
#define MYSERVER_H

#include <QMainWindow>
#include <QAbstractSocket>

#include "myqtcpserver.h"
#include "senddestination.h"

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
    void sendSignal();

protected:
    //void incomingConnection(qintptr socketDescriptor);

private slots:
    void on_FindPushButton_clicked();
    void on_StartPushButton_clicked();

private:
    Ui::MyServer *ui;
                                    //El árbol de directorios transferido
    MyQTcpServer *server_;          //Puede quedarse en el servidor
    SendDestination *destination_;  //O puede mandarlo a otro destino(Cliente).

};

#endif // MYSERVER_H

