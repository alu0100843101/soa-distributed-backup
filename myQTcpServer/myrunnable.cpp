#include "myrunnable.h"

MyRunnable::MyRunnable()
{
}

void MyRunnable::run()
{
    if(!SocketDescriptor) return;

    QTcpSocket socket;
    socket.setSocketDescriptor(SocketDescriptor);

    socket.write("WELCOME TO MY SERVER!!");
    socket.flush();
    socket.waitForBytesWritten();
    socket.close();
}
