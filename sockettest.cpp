#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) :
    QObject(parent)
{
}


void SocketTest::Connect()
{
    //connected
    socket = new QTcpSocket(this);

    socket->connectToHost("127.0.0.1", 1234); //nov komentar: port 1234 za tcp, na localhost
                                            //stari komentari://random port treba na 80
                                            //sa nslookup vidis ip adresu ako je potrebno

    //ceka na konekcju 3000ms ili 3sec
    if(socket->waitForConnected(7000))
    {
        qDebug()<< "Uspesno povezivanje sa serverom";

        //send
        socket->write("Hello server!\r\n\r\n\r\n\r\n"); //pise nesto u socket odn salje serveru, a ovaj treba da mu odgovori
        socket->waitForBytesWritten(1000); //ceka na odgovor servera 1sekundu
        socket->waitForReadyRead(3000);
        qDebug()<< "Reading!"<< socket->bytesAvailable();
        socket->readAll();


        socket->close();
    }
    else
    {
        qDebug()<< "Neuspelo povezivanje sa serverom";
    }



        //sent

        //got

        //closed
    }
