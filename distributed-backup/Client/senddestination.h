#ifndef SENDDESTINATION_H
#define SENDDESTINATION_H

#include <QDir>
#include <QFile>
#include <QThread>
#include <QTcpSocket>
#include <QDataStream>
#include <QHostAddress>
#include <QNetworkInterface>

class SendDestination : public QThread
{
public:
    SendDestination(QString path, QStringList files, QHostAddress address, quint16 port);
    void run();

private slots:
    void closeSlot();

private:
    QString path_;
    QStringList files_;
    QHostAddress address_;
    quint16 port_;

    QFile *file_;
};

#endif // SENDDESTINATION_H
