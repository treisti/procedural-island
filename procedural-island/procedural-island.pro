#-------------------------------------------------
#
# Project created by QtCreator 2018-03-12T14:01:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = procedural-island
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    heightmap.cpp \
    random.cpp \
    preview2d.cpp

HEADERS  += mainwindow.h \
    heightmap.h \
    random.h \
    preview2d.h

FORMS    += mainwindow.ui \
    preview2d.ui
