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
    lesvehicules.cpp \
    voiture.cpp \
    bus.cpp \
    velo.cpp \
    lesvoitures.cpp \
    lesbus.cpp \
    lesvelos.cpp \
    location.cpp \
    lienslocation.cpp \
    liensavis.cpp \
    liensprobleme.cpp \
    lieu.cpp \
    leslieux.cpp \
    basededonnees.cpp

HEADERS  += \
    ig.h \
    vehicule.h \
    lesvehicules.h \
    voiture.h \
    bus.h \
    velo.h \
    lesvoitures.h \
    lesbus.h \
    lesvelos.h \
    location.h \
    lienslocation.h \
    liensavis.h \
    liensprobleme.h \
    tostring.h \
    lieu.h \
    leslieux.h \
    basededonnees.h


FORMS    += \
    fenetreprincipale.ui \
    fenetreavis.ui \
    fenetrelocation.ui \
    fenetreprobleme.ui \
    fenetreconnexion.ui
