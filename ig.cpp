#include "ig.h"
#include <QMessageBox>

IG::IG(QWidget *parent) : QMainWindow(parent) {

    uiPpale = new Ui::FenetrePrincipale;
    uiAvis = new Ui::FenetreAvis;
    uiLoc = new Ui::FenetreLocation;

    uiPpale->setupUi(this);
    uiAvis->setupUi(this);
    uiLoc->setupUi(this);
    stack = new QStackedWidget(this);

    for (int i = 0; i<lesVoitures.size() ; i++) {
        listeVoiture << lesVoitures.toQString(i);
    }
    for (int i = 0; i<lesBus.size() ; i++) {
        listeBus << lesBus.toQString(i);
    }
    for (int i = 0; i<lesVelos.size() ; i++) {
        listeVelo << lesVelos.toQString(i);
    }

    fdem = uiPpale->centralWidget;
    favis = uiAvis->centralWidget;
    floc = uiLoc->centralWidget;

    stack->addWidget(fdem);
    stack->addWidget(favis);
    stack->addWidget(floc);

    this->setCentralWidget(stack);
    //stack->setCurrentIndex(0); /*Fixe la fenetre de demarrage*/

    // Connexions uiPpale
    connect(uiPpale->askLocation, SIGNAL(clicked()), this, SLOT(loc()));
    connect(uiPpale->avis, SIGNAL(clicked()), this, SLOT(mettreAvis()));

    // Connexions uiAvis
    connect(uiAvis->retour, SIGNAL(clicked()), this, SLOT(retourMenu()));
    connect(uiAvis->sendAvis, SIGNAL(clicked()), this, SLOT(validerAvis()));
    uiAvis->rate5->setChecked("TRUE");

    // Connexions uiLoc
    connect(uiLoc->retour, SIGNAL(clicked()), this, SLOT(retourMenu()));
    connect(uiLoc->chooseButton, SIGNAL(clicked()), this, SLOT(choixVehicule()));
    connect(uiLoc->carButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    connect(uiLoc->bikeButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    connect(uiLoc->busButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    uiLoc->listVehicule->addItems(listeVoiture);
    uiLoc->listVehicule->setCurrentRow(0);

    connect(this, SIGNAL(signalChangement(int)), this, SLOT(afficherFenetre(int)));

}

void IG::loc() {
    emit signalChangement(2);
}

void IG::afficherFenetre(int index) {
    if (index >= 0) {
        stack->setCurrentIndex(index);
    }
}

void IG::mettreAvis () {
    emit signalChangement(1);
}

void IG::retourMenu() {
    emit signalChangement(0);
}

void IG::choixVehicule() {
    QString choix = uiLoc->listVehicule->currentItem()->text();
    QMessageBox test;
    test.setText(choix);
    test.exec();
}

void IG::validerAvis() {
    QString avis = uiAvis->zoneAvis->toPlainText();
    //QString note = uiAvis->buttonGroup->checkedButton()->text();
    QString note;
    QMessageBox test;

    /*if(uiAvis->buttonGroup->checkedButton()) {
        test.setText("Veuillez selectionner une note.");
        test.exec();
    } else {*/
    note = uiAvis->buttonGroup->checkedButton()->text();
    test.setText("Note donnée : "+note+"\nAvis donné :\n"+avis);
    test.exec();
}

void IG::choixCategorie() {
    if(uiLoc->busButton->isChecked()) {
        uiLoc->listVehicule->clear();
        uiLoc->listVehicule->addItems(listeBus);
    } else if(uiLoc->bikeButton->isChecked()) {
        uiLoc->listVehicule->clear();
        uiLoc->listVehicule->addItems(listeVelo);
    } else if(uiLoc->carButton->isChecked()) {
        uiLoc->listVehicule->clear();
        uiLoc->listVehicule->addItems(listeVoiture);
    }
    uiLoc->listVehicule->setCurrentRow(0);
}

IG::~IG()
{
    delete uiPpale;
    delete uiAvis;
    delete uiLoc;
    delete stack;
    delete fdem;
    delete favis;
    delete floc;
}

