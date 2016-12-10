#include "lienslocation.h"
#include <string.h>

#include<sstream>

LiensLocation::LiensLocation() {

}

LiensLocation::LiensLocation(Ui::FenetreLocation *ui) {

    this->uiLoc = ui;
    location = new Location();
    nbJours = 0;
    option = 0;
    prixAdresses = 0;

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


    // Connexions uiLoc
    connect(uiLoc->chooseButton, SIGNAL(clicked()), this, SLOT(validationVehicule()));
    connect(uiLoc->carButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    connect(uiLoc->bikeButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    connect(uiLoc->busButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    connect(uiLoc->boutonAdresseRendu, SIGNAL(clicked()), this, SLOT(choixAdresse()));
    connect(uiLoc->boutonStationRendu, SIGNAL(clicked()), this, SLOT(choixAdresse()));
    connect(uiLoc->boutonAdresseRetrait, SIGNAL(clicked()), this, SLOT(choixAdresse()));
    connect(uiLoc->boutonStationRetrait, SIGNAL(clicked()), this, SLOT(choixAdresse()));
    connect(uiLoc->validationDate, SIGNAL(clicked()), this, SLOT(validationDate()));
    connect(uiLoc->validationChoix, SIGNAL(clicked()), this, SLOT(validationChoix()));
    connect(uiLoc->validationAdresses, SIGNAL(clicked()), this, SLOT(validationAdresses()));

    //Retour page précédente uiLoc
    connect(uiLoc->retour, SIGNAL(clicked()), this, SLOT(retourPagePrecedente()));

    uiLoc->listVehicule->addItems(listeVoiture);
    uiLoc->listVehicule->setCurrentRow(0);

    uiLoc->champStationRendu->addItems(listeLieux);
    uiLoc->champStationRendu->setCurrentRow(0);
    uiLoc->champStationRetrait->addItems(listeLieux);
    uiLoc->champStationRetrait->setCurrentRow(0);
}


void LiensLocation::validationDate() {
    uiLoc->retour->show();
    choixCategorie();
    uiLoc->stackedWidget->setCurrentIndex(1);
    QDate dateDebut = uiLoc->dateDebut->selectedDate();
    QDate dateFin = uiLoc->dateFin->selectedDate();
    nbJours = dateDebut.daysTo(dateFin);
}


void LiensLocation::validationVehicule() {
    uiLoc->stackedWidget->setCurrentIndex(2);
    int index = uiLoc->listVehicule->currentIndex().row();

    if(uiLoc->busButton->isChecked()) {
        location->setVehicule(lesBus.getVehicule(index));
        QString option = patch::to_string(lesBus.getVehicule(index)->getPrixOption()).c_str();
        uiLoc->sansOption->setText("Sans chauffeur");
        uiLoc->avecOption->setText("Avec chauffeur ("+option+"€)");
    } else if(uiLoc->bikeButton->isChecked()) {
        location->setVehicule(lesVelos.getVehicule(index));
        QString option = patch::to_string(lesVelos.getVehicule(index)->getPrixOption()).c_str();
        uiLoc->sansOption->setText("Sans assistance");
        uiLoc->avecOption->setText("Avec assistance ("+option+"€)");
    } else if(uiLoc->carButton->isChecked()) {
        location->setVehicule(lesVoitures.getVehicule(index));
        QString option = patch::to_string(lesVoitures.getVehicule(index)->getPrixOption()).c_str();
        uiLoc->sansOption->setText("Sans chauffeur");
        uiLoc->avecOption->setText("Avec chauffeur ("+option+"€)");
    }

    QString attributs = location->getVehicule()->attributsFicheDetail();
    uiLoc->attributs->setText(attributs);
    QString choix = location->getVehicule()->toQStringDetail();
    uiLoc->fiche->setText(choix);
}

void LiensLocation::choixCategorie() {
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

void LiensLocation::choixAdresse() {
    if(uiLoc->boutonStationRetrait->isChecked()) {
        uiLoc->stackedRetrait->setCurrentIndex(0);
    } else {
        uiLoc->stackedRetrait->setCurrentIndex(1);
    }

    if(uiLoc->boutonStationRendu->isChecked()) {
        uiLoc->stackedRendu->setCurrentIndex(0);
    } else {
        uiLoc->stackedRendu->setCurrentIndex(1);
    }

    uiLoc->champStationRetrait->setCurrentRow(0);
    uiLoc->champStationRendu->setCurrentRow(0);
}

void LiensLocation::validationChoix() {
    uiLoc->champStationRendu->clear();
    uiLoc->champStationRendu->addItems(listeLieux);
    uiLoc->champStationRetrait->clear();
    uiLoc->champStationRetrait->addItems(listeLieux);

    uiLoc->stackedWidget->setCurrentIndex(3);
    option=0;

    if(uiLoc->avecOption->isChecked()) {
        option = location->getVehicule()->getPrixOption();;
    }

    choixAdresse();
}

void LiensLocation::validationAdresses() {
    uiLoc->stackedWidget->setCurrentIndex(4);
    int prixDeBase = location->getVehicule()->getPrix();
    prixAdresses = 0;

    if(uiLoc->boutonAdresseRetrait->isChecked()) {
        prixAdresses += 5;
    }

    if(uiLoc->boutonAdresseRendu->isChecked()) {
        prixAdresses += 5;
    }

    location->setPrix((prixDeBase*nbJours)+(option*nbJours)+prixAdresses);

    QString testString = patch::to_string((int)location->getPrix()).c_str();
    QMessageBox test;
    test.setText("Prix de la loc : "+testString+"€");
    test.exec();
}

void LiensLocation::retourPagePrecedente() {
    int pos = uiLoc->stackedWidget->currentIndex();
    if (pos > 0) {
        if (pos-1 == 0) {
            uiLoc->retour->hide();
        }
        uiLoc->stackedWidget->setCurrentIndex(pos-1);
    }
}

void LiensLocation::addVoiture(Voiture * v) {
    lesVoitures.addVehicule(v);
    listeVoiture << v->toQString();
}

void LiensLocation::addBus(Bus * b) {
    lesBus.addVehicule(b);
    listeBus << b->toQString();
}

void LiensLocation::addVelo(Velo * v) {
    lesVelos.addVehicule(v);
    listeVelo << v->toQString();
}

void LiensLocation::addLieu (Lieu * l) {
    lesLieux.addLieu(l);
    listeLieux << l->toQString();
}

LiensLocation::~LiensLocation() {


}
