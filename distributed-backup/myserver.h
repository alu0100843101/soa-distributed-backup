#ifndef MYSERVER_H
#define MYSERVER_H

#include <QMainWindow>

namespace Ui {
class MyServer;
}

class MyServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyServer(QWidget *parent = 0);
    ~MyServer();

private:
    Ui::MyServer *ui;
};

#endif // MYSERVER_H
