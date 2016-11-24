#include "ig.h"
#include <QMessageBox>

IG::IG(QWidget *parent) : QMainWindow(parent), uiPpale(new Ui::FenetrePrincipale), uiAvis(new Ui::FenetreAvis), uiLoc(new Ui::FenetreLocation)
{
    uiPpale->setupUi(this);
    uiAvis->setupUi(this);
    uiLoc->setupUi(this);
    stack = new QStackedWidget(this);

    listeVoiture << "Porsche Cayenne" << "Peugeot 207" << "Audi Q5";
    listeBus << "Bus Scolaire" << "Bus Urbain" << "Bus Toursime";
    listeVelo << "VTT Giant" << "VTC Giant" << "VTT Scott" << "VTC Scott";

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

    // Connexions uiLoc
    connect(uiLoc->retour, SIGNAL(clicked()), this, SLOT(retourMenu()));
    connect(uiLoc->chooseButton, SIGNAL(clicked()), this, SLOT(choixVehicule()));
    connect(uiLoc->buttonGroup, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    uiLoc->listVehicule->addItems(listeVoiture);

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
    QString note = uiAvis->buttonGroup->checkedButton()->text();
    QMessageBox test;
    test.setText("Note donnée : "+note+"\nAvis donné :\n"+avis);
    test.exec();
}

void IG::choixCategorie() {
    if(uiLoc->buttonGroup->checkedButton()->text() == "Bus") {
        uiLoc->listVehicule->clear();
        uiLoc->listVehicule->addItems(listeBus);
    } else if(uiLoc->buttonGroup->checkedButton()->text() == "Vélo") {
        uiLoc->listVehicule->clear();
        uiLoc->listVehicule->addItems(listeVelo);
    } else if(uiLoc->buttonGroup->checkedButton()->text() == "Voiture") {
        uiLoc->listVehicule->clear();
        uiLoc->listVehicule->addItems(listeVoiture);
    }
}

IG::~IG()
{
    delete uiPpale;
    delete uiAvis;
    delete uiLoc;
}

