#-------------------------------------------------
#
# Project created by QtCreator 2019-10-30T08:59:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += console
SOURCES += \
        main.cpp \
    graph.cpp \
    list.cpp \
    welcome.cpp \
    busroute.cpp \
    myview.cpp \
    mygraphicsline.cpp \
    myscene.cpp \
    manager.cpp \
    myrect.cpp \
    walkroute.cpp \
    pathsolve.cpp \
    graphicsdraw.cpp \
    dataprocess.cpp

HEADERS += \
    edge.h \
    element.h \
    graph.h \
    list.h \
    listnode.h \
    constant.h \
    dist.h \
    welcome.h \
    busroute.h \
    myview.h \
    mygraphicsline.h \
    myscene.h \
    manager.h \
    myrect.h \
    sceniccenterpoint.h \
    walkroute.h \
    disjointset.h \
    dataprocess.h \
    pathsolve.h \
    graphicsdraw.h

FORMS += \
    welcome.ui \
    busroute.ui \
    walkroute.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
