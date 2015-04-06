#include <QtCore/QCoreApplication>//ova klasa se koristi od strane GUI aplikacija jer sadrzi main event loop
                                //gde svi dogadjaji na sistemu (tajmeri i dogadjaji na mrezi)i ostali su
                                //procesirani i otpremljeni. Za aplikacije koje ne koriste GUI trebalo bi da
                                //postoji tacno jedan objekat klase QCoreApplication
#include "sockettest.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    SocketTest cTest;   //instanciramo objekat nase klase SocketTest
    cTest.Connect();    //pozivamo metodu iz nase klase koju smo definisali u sockettest.cpp

    return a.exec();    //izvrsavanje
}
