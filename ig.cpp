#include "ig.h"
#include <QMessageBox>
#include <string>

IG::IG(QWidget *parent) : QMainWindow(parent) {


    uiPpale = new Ui::FenetrePrincipale;
    uiAvis = new Ui::FenetreAvis;
    uiLoc = new Ui::FenetreLocation;
    uiProb = new Ui::FenetreProbleme;


    uiPpale->setupUi(this);
    uiAvis->setupUi(this);
    uiLoc->setupUi(this);
    uiProb->setupUi(this);

    this->setWindowTitle("Transports à la carte");
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
    fprob = uiProb->centralWidget;

    stack->addWidget(fdem);
    stack->addWidget(favis);
    stack->addWidget(floc);
    stack->addWidget(fprob);

    this->setCentralWidget(stack);

    // Connexions uiPpale
    connect(uiPpale->askLocation, SIGNAL(clicked()), this, SLOT(loc()));
    connect(uiPpale->avis, SIGNAL(clicked()), this, SLOT(mettreAvis()));
    connect(uiPpale->probleme, SIGNAL(clicked()), this, SLOT(mettreProbleme()));

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
    connect(uiLoc->validationDate, SIGNAL(clicked()), this, SLOT(choixDate()));
    uiLoc->listVehicule->addItems(listeVoiture);
    uiLoc->listVehicule->setCurrentRow(0);

    // Connexions uiProb
    connect(uiProb->retour_3, SIGNAL(clicked()), this, SLOT(retourMenu()));
    connect(uiProb->sendProbleme, SIGNAL(clicked()), this, SLOT(validerProbleme()));

    connect(this, SIGNAL(signalChangement(int)), this, SLOT(afficherFenetre(int)));

}

void IG::loc() {
    uiLoc->stackedWidget->setCurrentIndex(0);
    emit signalChangement(2);
}

void IG::afficherFenetre(int index) {
    if (index >= 0) {
        stack->setCurrentIndex(index);
    }
}

void IG::mettreAvis() {
    emit signalChangement(1);
}

void IG::mettreProbleme() {
    emit signalChangement(3);
}

void IG::retourMenu() {
    emit signalChangement(0);
}

void IG::choixDate() {
    uiLoc->stackedWidget->setCurrentIndex(1);
    QDate dateDebut = uiLoc->dateDebut->selectedDate();
    QDate dateFin = uiLoc->dateFin->selectedDate();

    QString sformat="dd-MM-yyyy";
    std::string jours = std::to_string(dateDebut.daysTo(dateFin));
    QString nbJours = jours.c_str();
    QMessageBox test;
    test.setText("Date debut : "+dateDebut.toString(sformat)+"/ Date fin : "+dateFin.toString(sformat)+"\nNombre de jours : "+nbJours);
    test.exec();
}

void IG::choixVehicule() {
    uiLoc->stackedWidget->setCurrentIndex(2);
    //location.setVehicule(uiLoc->listVehicule->currentItem());
    /*QString choix = uiLoc->listVehicule->currentItem()->text();
    QMessageBox test;
    test.setText(choix);
    test.exec();*/
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

void IG::validerProbleme() {
    QString probleme = uiProb->zoneProbleme->toPlainText();
    QMessageBox test;
    test.setText("Problème donné :\n"+probleme);
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
    delete stack;
    delete uiPpale;
    delete uiAvis;
    delete uiLoc;
}

