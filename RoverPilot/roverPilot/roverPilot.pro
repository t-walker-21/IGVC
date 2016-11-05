#-------------------------------------------------
#
# Project created by QtCreator 2016-11-03T02:02:50
#
#-------------------------------------------------

QT       += core gui

CONFIG   += serialport



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = roverPilot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
