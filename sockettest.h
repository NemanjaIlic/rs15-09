#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QObject> //QObject class je bazna klasa za sve Qt objekte.
                    //iz dokumentacije citat ,,QObject is the heart of the Qt Object Model."
#include <QTcpSocket> //QTcpSocket obezbedjuje podrsku za TCP socket
                    //TCP je pouzdan stream-oriented, connection-oriented transport protocol
                    //Pogodan za kontinuiran prenos podataka
                    //nasledjuje QAbstractSocket koja omogucava uspostavljanje TCP konekcije
                    //i transfer tokova podataka
#include <QDebug>   //QDebug obezbedjuje izlazni tok za ispis informacija (debagovanje)

class SocketTest : public QObject
{
    Q_OBJECT    //vrsta makroa koja zapravo umece deo koda iz QObject

public:
    explicit SocketTest(QObject *parent = 0); //konstruktor, explicit sprecava konstruktor da izvrsi auto konverziju
    
    void Connect();

signals:
    
public slots:

private:
    QTcpSocket* socket;
    
};

#endif // SOCKETTEST_H
