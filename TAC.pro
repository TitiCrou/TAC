#-------------------------------------------------
#
# Project created by QtCreator 2016-11-22T10:16:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TAC
TEMPLATE = app


SOURCES += main.cpp\
        ig.cpp \
    vehicule.cpp \
    lesvehicules.cpp

HEADERS  += \
    ig.h \
    vehicule.h \
    lesvehicules.h

FORMS    += \
    fenetreprincipale.ui \
    fenetreavis.ui \
    fenetrelocation.ui
