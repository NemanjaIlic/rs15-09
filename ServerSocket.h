//Definicija ServerSocket klase

#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H
#include "Socket.h" //Kad Jovan zavrsi Socket

//: public znaci oznacava rezim pristupa osnovnoj klasi
class ServerSocket : private Socket //Klasa ServerSocket nasledjuje klasu Socket
{
public:
    ServerSocket(int port); //konstruktor
    ServerSocket(){};       //default konstruktor
    virtual ~ServerSocket(); //Destruktor, kljucna rec virtual odlaze razresavanje poziva funkcije clanice do vremena izvrsavanja, drugim recima
                            //ako neka izvedena klasa ima potrebu da redfinise ovaj metod stavicemo da bude virtualan

    //const sprecava menjanje promenljive, argumenata ili vrednosti na koju pokazuje pokazivac
    const ServerSocket& operator << (const std::string&) const;
    const ServerSocket& operator >> (std::string&) const;

    void accept (ServerSocket&);
};

#endif // SERVERSOCKET_H
