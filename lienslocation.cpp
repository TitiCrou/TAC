#include "lienslocation.h"
#include <string.h>

#include<sstream>

LiensLocation::LiensLocation() {

}



LiensLocation::LiensLocation(Ui::FenetreLocation *ui) {

    this->uiLoc = ui;
    location = new Location();
    nbJours = 0;

    for (int i = 0; i<lesVoitures.size() ; i++) {
        listeVoiture << lesVoitures.toQString(i);
    }
    for (int i = 0; i<lesBus.size() ; i++) {
        listeBus << lesBus.toQString(i);
    }
    for (int i = 0; i<lesVelos.size() ; i++) {
        listeVelo << lesVelos.toQString(i);
    }


    // Connexions uiLoc
    connect(uiLoc->chooseButton, SIGNAL(clicked()), this, SLOT(choixVehicule()));
    connect(uiLoc->carButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    connect(uiLoc->bikeButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    connect(uiLoc->busButton, SIGNAL(clicked()), this, SLOT(choixCategorie()));
    connect(uiLoc->validationDate, SIGNAL(clicked()), this, SLOT(choixDate()));

    //Retour page précédente uiLoc
    connect(uiLoc->retour, SIGNAL(clicked()), this, SLOT(retourPagePrecedente()));

    uiLoc->listVehicule->addItems(listeVoiture);
    uiLoc->listVehicule->setCurrentRow(0);
}


void LiensLocation::choixDate() {
    uiLoc->retour->show();
    uiLoc->stackedWidget->setCurrentIndex(1);
    QDate dateDebut = uiLoc->dateDebut->selectedDate();
    QDate dateFin = uiLoc->dateFin->selectedDate();
    nbJours = dateDebut.daysTo(dateFin);

    //std::string jours = patch::to_string(dateDebut.daysTo(dateFin)) ;

    /*QString sformat="dd-MM-yyyy";
    QString nbJours = jours.c_str();
    QMessageBox test;
    test.setText("Date debut : "+dateDebut.toString(sformat)+"/ Date fin : "+dateFin.toString(sformat)+"\nNombre de jours : "+nbJours);
    test.exec();*/
}


void LiensLocation::choixVehicule() {
    uiLoc->stackedWidget->setCurrentIndex(2);
    int index = uiLoc->listVehicule->currentIndex().row();

    if(uiLoc->busButton->isChecked()) {
        location->setVehicule(lesBus.getVehicule(index));
    } else if(uiLoc->bikeButton->isChecked()) {
        location->setVehicule(lesVelos.getVehicule(index));
    } else if(uiLoc->carButton->isChecked()) {
        location->setVehicule(lesVoitures.getVehicule(index));
    }

    int prixDeBase = location->getVehicule()->getPrix();
    location->setPrix(prixDeBase*nbJours);

    QMessageBox test;
    test.setText((std::to_string(prixDeBase*nbJours)).c_str());
    test.exec();


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


void LiensLocation::retourPagePrecedente() {
    int pos = uiLoc->stackedWidget->currentIndex();
    if (pos > 0) {
        if (pos-1 == 0) {
            uiLoc->retour->hide();
        }
        uiLoc->stackedWidget->setCurrentIndex(pos-1);
    }
}

LiensLocation::~LiensLocation() {


}
