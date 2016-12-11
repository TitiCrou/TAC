#include "lienslocation.h"
#include <string.h>

#include <sstream>

/**
 * @brief Constructeur vide de LiensLocation
 */
LiensLocation::LiensLocation() {

}

/**
 * @brief Constructeur de LiensLocation
 * @param ui l'interface définissant la fenêtre dédiée à la location
 * @param lDD la classe contenant toutes les données nécessaire (véhicules, lieux)
 * Dans ce constructeur, tous les éléments nécessaires au formulaire de location
 * sont initialisés
 */
LiensLocation::LiensLocation(Ui::FenetreLocation *ui, ListesDeDonnees *lDD) {

    this->uiLoc = ui;
    location = new Location();
    nbJours = 0;
    option = 0;
    prixAdresses = 0;
    setLocVal(false);

    listesDD = lDD;

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


/**
 * @brief Le client valide les dates de début et de fin et passe au choix du véhicule
 */
void LiensLocation::validationDate() {
    uiLoc->retour->show();
    choixCategorie();
    uiLoc->stackedWidget->setCurrentIndex(1);
    QDate dateDebut = uiLoc->dateDebut->selectedDate();
    QDate dateFin = uiLoc->dateFin->selectedDate();
    nbJours = dateDebut.daysTo(dateFin);
}

/**
 * @brief Le client choisit un véhicule et est redirigé sur la fiche détaillée
 * Les données du véhicule choisi sont stockées dans l'instance de la classe Location
 * La fiche détaillée est créée en fonction du descriptif du véhicule
 */
void LiensLocation::validationVehicule() {
    uiLoc->stackedWidget->setCurrentIndex(2);
    int index = uiLoc->listVehicule->currentIndex().row();

    if(uiLoc->busButton->isChecked()) {
        location->setVehicule(listesDD->getBus(index));
        QString option = QString::number(listesDD->getBus(index)->getPrixOption());
        uiLoc->sansOption->setText("Sans chauffeur");
        uiLoc->avecOption->setText("Avec chauffeur ("+option+"€)");
    } else if(uiLoc->bikeButton->isChecked()) {
        location->setVehicule(listesDD->getVelo(index));
        QString option = QString::number(listesDD->getVelo(index)->getPrixOption());
        uiLoc->sansOption->setText("Sans assistance");
        uiLoc->avecOption->setText("Avec assistance ("+option+"€)");
    } else if(uiLoc->carButton->isChecked()) {
        location->setVehicule(listesDD->getVoiture(index));
        QString option = QString::number(listesDD->getVoiture(index)->getPrixOption());
        uiLoc->sansOption->setText("Sans chauffeur");
        uiLoc->avecOption->setText("Avec chauffeur ("+option+"€)");
    }

    QString attributs = location->getVehicule()->attributsFicheDetail();
    uiLoc->attributs->setText(attributs);
    QString choix = location->getVehicule()->toQStringDetail();
    uiLoc->fiche->setText(choix);
}

/**
 * @brief Charge les véhicules disponibles en fonction de leur type
 */
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

/**
 * @brief Gestion des stations et des adresses personnalisées
 */
void LiensLocation::choixAdresse() {
    if(uiLoc->boutonStationRetrait->isChecked()) {
        uiLoc->stackedRetrait->setCurrentIndex(0);
    } else {
        uiLoc->stackedRetrait->setCurrentIndex(1);
    }
    //uiLoc->champStationRetrait->setCurrentRow(0);

    if(uiLoc->boutonStationRendu->isChecked()) {
        uiLoc->stackedRendu->setCurrentIndex(0);
    } else {
        uiLoc->stackedRendu->setCurrentIndex(1);
    }
    //uiLoc->champStationRendu->setCurrentRow(0);
}

/**
 * @brief Affichage des stations après validation du choix du véhicule
 */
void LiensLocation::validationChoix() {
    uiLoc->champStationRendu->clear();
    uiLoc->champStationRendu->addItems(listeLieux);
    uiLoc->champStationRetrait->clear();
    uiLoc->champStationRetrait->addItems(listeLieux);

    uiLoc->stackedWidget->setCurrentIndex(3);
    option=0;

    if(uiLoc->avecOption->isChecked()) {
        option = location->getVehicule()->getPrixOption();
    }

    choixAdresse();
    uiLoc->champStationRetrait->setCurrentRow(0);
    uiLoc->champStationRendu->setCurrentRow(0);
}

/**
 * @brief Affichage du récapitulatif après enregistrement des lieux dans la location
 */
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
        location->setRetrait(listesDD->getLieu(indexRetrait));
    }

    if(uiLoc->boutonAdresseRendu->isChecked()) {
        Lieu * adrRendu = new Lieu(uiLoc->champAdresseRendu->toPlainText().toStdString(), true);
        prixAdresses += 5;
        location->setRendu(adrRendu);
    } else {
        location->setRendu(listesDD->getLieu(indexRendu));
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

/**
 * @brief Validation de la location et retour au menu principal
 */
void LiensLocation::validationLocation() {
    setLocVal(true);
    uiLoc->menu->click();
}

/**
 * @brief Retour à la page précédente après clic sur bouton
 */
void LiensLocation::retourPagePrecedente() {
    int pos = uiLoc->stackedWidget->currentIndex();
    if (pos > 0) {
        if (pos-1 == 0) {
            uiLoc->retour->hide();
        }
        uiLoc->stackedWidget->setCurrentIndex(pos-1);
    }
}

/**
 * @brief getter du booléen permettant l'affichage de la validation de la location
 * @return vrai : on affiche le message de fin de location | faux : on le cache
 */
bool LiensLocation::getLocVal() {
    return locVal;
}

/**
 * @brief setter du booléen permettant l'affichage de la validation de la location
 * @param b le booléen
 */
void LiensLocation::setLocVal(bool b) {
    locVal = b;
}

/**
 * @brief Destructeur de LiensLocation
 */
LiensLocation::~LiensLocation() {


}
