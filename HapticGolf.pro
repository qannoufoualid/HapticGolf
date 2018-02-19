#-------------------------------------------------
#
# Project created by QtCreator 2018-02-10T12:20:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HapticGolf
TEMPLATE = app



INCLUDEPATH += "C:\Program Files\Immersion Corporation\IFC23\inc"

LIBS += "C:\Program Files\Immersion Corporation\IFC23\lib\IFC23.lib"


SOURCES += main.cpp\
    mainwindow.cpp \
    ball.cpp \
    wall.cpp \
    course.cpp \
    point.cpp \
    gestionhaptique.cpp

HEADERS  += mainwindow.h \
    ball.h \
    wall.h \
    course.h \
    point.h \
    walltype.h \
    gestionhaptique.h


FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
