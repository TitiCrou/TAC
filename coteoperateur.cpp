#include "coteoperateur.h"

CoteOperateur::CoteOperateur() {

}

CoteOperateur::CoteOperateur(QWidget * parent) {

    uiOp = new Ui::FenetreOperateur;
    uiOp->setupUi(parent);

    bdd.creerBDD(this);

    stack = new QStackedWidget(parent);
    stack->addWidget(uiOp->centralWidget);

    parent->setWindowTitle("Transports à la carte");

    for (int i = 0; i<lesVoitures.size() ; i++) {
        listeVoiture << lesVoitures.toQString(i);
    }
    for (int i = 0; i<lesBus.size() ; i++) {
        listeBus << lesBus.toQString(i);
    }
    for (int i = 0; i<lesVelos.size() ; i++) {
        listeVelo << lesVelos.toQString(i);
    }
    for (int i = 0; i<lesLieux.size() ; i++) {
        listeLieux << lesLieux.toQString(i);
    }

    // Init des boutons
    connect(uiOp->busButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    connect(uiOp->carButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    connect(uiOp->bikeButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    connect(uiOp->placeButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));

    connect(uiOp->modification, SIGNAL(clicked()), this, SLOT(modification()));
    connect(uiOp->ajout, SIGNAL(clicked()), this, SLOT(ajout()));


    uiOp->listVehicule->addItems(listeVoiture);
    uiOp->listVehicule->setCurrentRow(0);
}



void CoteOperateur::choixCategorie() {
    if(uiOp->busButton->isChecked()) {
        uiOp->listVehicule->clear();
        uiOp->listVehicule->addItems(listeBus);
    } else if(uiOp->bikeButton->isChecked()) {
        uiOp->listVehicule->clear();
        uiOp->listVehicule->addItems(listeVelo);
    } else if(uiOp->carButton->isChecked()) {
        uiOp->listVehicule->clear();
        uiOp->listVehicule->addItems(listeVoiture);
    } else if(uiOp->placeButton->isChecked()) {
        uiOp->listVehicule->clear();
        uiOp->listVehicule->addItems(listeLieux);
    }
    uiOp->listVehicule->setCurrentRow(0);
}

void CoteOperateur::modification() {
    uiOp->stackedWidget->setCurrentIndex(2);
}

void CoteOperateur::ajout() {
    uiOp->stackedWidget->setCurrentIndex(1);
}

/*void CoteOperateur::retourPagePrecedente() {
    int pos = uiOp->stackedWidget->currentIndex();
    if (pos > 0) {
        if (pos-1 == 0) {
            uiOp->retour->hide();
        }
        uiOp->stackedWidget->setCurrentIndex(pos-1);
    }
}*/

void CoteOperateur::addVoiture(Voiture * v) {
    lesVoitures.addVehicule(v);
    listeVoiture << v->toQString();
}

void CoteOperateur::addBus(Bus * b) {
    lesBus.addVehicule(b);
    listeBus << b->toQString();
}

void CoteOperateur::addVelo(Velo * v) {
    lesVelos.addVehicule(v);
    listeVelo << v->toQString();
}

void CoteOperateur::addLieu (Lieu * l) {
    lesLieux.addLieu(l);
    listeLieux << l->toQString();
}

CoteOperateur::~CoteOperateur() {
    delete stack;
}
