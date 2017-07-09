#include "myserver.h"
#include "ui_myserver.h"

MyServer::MyServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyServer)
{
    ui->setupUi(this);
}

MyServer::~MyServer()
{
    delete ui;
}

void MyServer::on_FindPushButton_clicked()
{

}

void MyServer::on_StartPushButton_clicked()
{

}
