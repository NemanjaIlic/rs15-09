TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += \
    simple_server_main.cpp \
    ServerSocket.cpp \
    socket.cpp

HEADERS += \
    ServerSocket.h \
    SocketException.h \
    socket.h

