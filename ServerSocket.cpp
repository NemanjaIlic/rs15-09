#include "ServerSocket.h"
#include "SocketException.h"
#include <iostream>

//---------------NL------------------------------------------------

//definicija konsruktora
ServerSocket::ServerSocket ( int port ) //port na kom se osluskuje
{
  if (!Socket::create()) //kreiranje socketa, ako nije uspelo baci izuzetak
    {
      throw SocketException ("Nimoze se kreirati Server Socket.");
    }

  if (!Socket::bind (port))//povezivanje na port, ako nije uspelo baci izuzetak
    {
      throw SocketException ("Nije moguce vezivanje na port.");
    }

  if (!Socket::listen()) //slusanje na portu(odn soketu), ako nije moguce baci izuzetak
    {
      throw SocketException ("Nije moguce slusanje porta(soketa).");
    }
}

//Destruktor
ServerSocket::~ServerSocket()
{
}

//TODO redefinisi operatore za streamove i accept function
//redefinisanje operatora << i >>
const ServerSocket& ServerSocket::operator << ( const std::string& s ) const
{
  if ( ! Socket::send ( s ) ) //poziva se metoda iz klase Socket i salje poruka sadrzana u stringu s
    {
      throw SocketException ("Nije moguce pisati u Socket.");
    }

  return *this; //this pokazuje na objekat u kome se trenutno vrse operacije u okviru funkcije clanice

}


const ServerSocket& ServerSocket::operator >> ( std::string& s ) const
{
  if ( ! Socket::recv ( s ) )
    {
      throw SocketException ( "Nije moguce citati iz Socketa." );
    }

  return *this;
}

void ServerSocket::accept ( ServerSocket& sock )
{
  if ( ! Socket::accept ( sock ) )
    {
      throw SocketException ( "Nije moguce prihvatiti socket." );
    }
}
//----------------NL-----------------------------------------------
