#-------------------------------------------------
#
# Project created by QtCreator 2015-04-10T20:12:15
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = serverZaMagarence
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

DEFINES += SERVERZAMAGARENCE_LIBRARY

SOURCES += main_server.cpp \
	myserver.cpp

HEADERS += myserver.h

