#include "coteoperateur.h"

CoteOperateur::CoteOperateur() {

}

CoteOperateur::CoteOperateur(QWidget * parent) {

    uiOp = new Ui::FenetreOperateur;
    uiOp->setupUi(parent);

    listesDD = new ListesDeDonnees();

    bdd.creerBDD(listesDD);

    stack = new QStackedWidget(parent);
    stack->addWidget(uiOp->centralWidget);

    parent->setWindowTitle("Transports à la carte");

    for (int i = 0 ; i<listesDD->voituresSize() ; i++) {
        listeVoiture << listesDD->voitureToQString(i);
    }
    for (int i = 0 ; i<listesDD->busSize() ; i++) {
        listeBus << listesDD->busToQString(i);
    }
    for (int i = 0 ; i<listesDD->velosSize() ; i++) {
        listeVelo << listesDD->veloToQString(i);
    }
    for (int i = 0 ; i<listesDD->lieuxSize() ; i++) {
        listeLieux << listesDD->lieuToQString(i);
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


CoteOperateur::~CoteOperateur() {
    delete stack;
}
