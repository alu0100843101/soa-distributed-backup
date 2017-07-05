#include <QCoreApplication>
#include "mysocket.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MySocket mysocket_;
    mysocket_.myConnect();

    return a.exec();
}
