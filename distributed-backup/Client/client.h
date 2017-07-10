#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>

#include "myqtcpserver.h"
#include "senddestination.h"

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

private slots:
    void on_ConnectPushButton_clicked();
    void on_SendPushButton_clicked();
    void on_OriginFindPushButton_clicked();
    void on_DestinationFindPushButton_clicked();

private:
    Ui::Client *ui;

    MyQTcpServer *server_;
    SendDestination *destination_;

    QString filename_, filenameD_;
    QStringList files_;
};

#endif // CLIENT_H
