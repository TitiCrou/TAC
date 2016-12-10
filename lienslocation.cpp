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
    connect(uiLoc->validationLoc, SIGNAL(clicked()), this, SLOT(validationLocation()));

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
    int indexRetrait = uiLoc->champStationRetrait->currentIndex().row();
    int indexRendu = uiLoc->champStationRendu->currentIndex().row();
    prixAdresses = 0;

    if(uiLoc->boutonAdresseRetrait->isChecked()) {
        Lieu * adrRetrait = new Lieu(uiLoc->champAdresseRetrait->toPlainText().toStdString(), true);

        prixAdresses += 5;
        location->setRetrait(adrRetrait);
    } else {
        location->setRetrait(lesLieux.getLieu(indexRetrait));
    }

    if(uiLoc->boutonAdresseRendu->isChecked()) {
        Lieu * adrRendu = new Lieu(uiLoc->champAdresseRendu->toPlainText().toStdString(), true);

        prixAdresses += 5;
        location->setRendu(adrRendu);
    } else {
        location->setRendu(lesLieux.getLieu(indexRendu));
    }

    location->setPrix((prixDeBase*nbJours)+(option*nbJours)+prixAdresses);

    // Partie récap
    QString attributsAdresses = "Durée de location : \n"
            +location->getRetrait()->toQStringRetrait()+"\n"
            +location->getRendu()->toQStringRendu();
    QString ficheAdresses = QString::number(nbJours)+" jour(s)\n"
            +location->getRetrait()->toQString()+"\n"
            +location->getRendu()->toQString();
    QString attributs = location->getVehicule()->attributsFicheDetail()+"\n\n"
            +"Coût déplacement : \n"
            +"Coût option : \n"
            +"Coût véhicule : \n\n"
            +"Total :";
    QString choix = location->getVehicule()->toQStringDetail()+"\n\n"
            +QString::number(prixAdresses)+"€\n"
            +QString::number(option*nbJours)+"€\n"
            +QString::number(location->getVehicule()->getPrix()*nbJours)+"€\n\n"
            +QString::number(location->getPrix())+"€";


    uiLoc->attributsAdresses->setText(attributsAdresses);
    uiLoc->ficheAdresses->setText(ficheAdresses);
    uiLoc->attributsRecap->setText(attributs);
    uiLoc->ficheRecap->setText(choix);
}

void LiensLocation::validationLocation() {

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
