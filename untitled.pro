#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T16:59:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    player.cpp \
    myqlistwidgetitem.cpp

HEADERS  += mainwindow.h \
    player.h \
    myqlistwidgetitem.h

FORMS    += mainwindow.ui

LIBS += -LC:/Users/Rory/Desktop/x64/ -lWinMM

DISTFILES +=

RESOURCES += \
    images.qrc
