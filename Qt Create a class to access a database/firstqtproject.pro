#-------------------------------------------------
#
# Project created by QtCreator 2013-11-03T22:12:55
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = firstqtproject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    YTDBConnection.cpp

HEADERS  += mainwindow.h \
    YTDBConnection.h

FORMS    += mainwindow.ui
