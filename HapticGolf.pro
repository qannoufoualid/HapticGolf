#-------------------------------------------------
#
# Project created by QtCreator 2018-02-10T12:20:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HapticGolf
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ball.cpp \
    wall.cpp \
    course.cpp

HEADERS  += mainwindow.h \
    ball.h \
    wall.h \
    course.h

FORMS    += mainwindow.ui
