#-------------------------------------------------
#
# Project created by QtCreator 2017-05-29T20:31:36
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PA_Opus_Control
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pulsecontrol.cpp

HEADERS  += mainwindow.h \
    pulsecontrol.h

FORMS    += mainwindow.ui
