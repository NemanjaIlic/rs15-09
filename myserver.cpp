#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server nije pokrenut!";
    }
    else
    {
        qDebug() << "Server pokrenut!";
    }
}

void MyServer::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();
                                 socket->write("zdravo klijentelo moja!\r\n"); //pise nesto socketu i treba da salje sledecoj konekciji na redu
                                 socket->flush();
                                 socket->waitForBytesWritten(3000);
                                 socket->waitForReadyRead(3000);
                                 qDebug() << "poruka od klijenta:" << socket->bytesAvailable();
                                 socket->readAll();
                                 socket->close();
}
