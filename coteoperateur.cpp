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

    // Section d'ajout
    connect(uiOp->annulationAjout, SIGNAL(clicked()), this, SLOT(annulation()));
    connect(uiOp->validationAjout, SIGNAL(clicked()), this, SLOT(validationAjout()));

    // Section de modif/supp
    connect(uiOp->annulationModif, SIGNAL(clicked()), this, SLOT(annulation()));
    //connect(uiOp->validationModif, SIGNAL(clicked()), this, SLOT(validation()));
    connect(uiOp->suppressionVehicule, SIGNAL(clicked()), this, SLOT(suppression()));

    uiOp->listVehicule->addItems(listeVoiture);
    uiOp->listVehicule->setCurrentRow(0);

    uiOp->stackedWidget->setCurrentIndex(0);
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

    int index = uiOp->listVehicule->currentIndex().row();

    if(uiOp->busButton->isChecked()) {
        Bus * b = (Bus*) listesDD->getBus(index);
        uiOp->attributsModif->setText(b->attributsFicheDetail());
        fenetreModif(0);
        uiOp->marque->setPlainText((b->getMarque()).c_str());
        uiOp->modele->setPlainText((b->getModele()).c_str());
        uiOp->couleur->setPlainText((b->getCouleur()).c_str());
        uiOp->prix->setPlainText(QString::number(b->getPrix()));
        uiOp->annee->setPlainText(QString::number(b->getAnnee()));
        uiOp->option1->setPlainText(QString::number(b->getKilo()));
        uiOp->option2->setPlainText(QString::number(b->getCapacite()));
        uiOp->option3->setPlainText(QString::number(b->getHauteur()));
        uiOp->option4->setPlainText(QString::number(b->getPoids()));

    } else if(uiOp->bikeButton->isChecked()) {
        Velo * v = (Velo*) listesDD->getVelo(index);
        uiOp->attributsModif->setText(v->attributsFicheDetail());
        fenetreModif(1);
        uiOp->marque->setPlainText((v->getMarque()).c_str());
        uiOp->modele->setPlainText((v->getModele()).c_str());
        uiOp->couleur->setPlainText((v->getCouleur()).c_str());
        uiOp->prix->setPlainText(QString::number(v->getPrix()));
        uiOp->annee->setPlainText(QString::number(v->getAnnee()));
        uiOp->option1->setPlainText(QString::number(v->getTaillePneu()));
        uiOp->option2->setPlainText((v->getTaille().c_str()));

    } else if(uiOp->carButton->isChecked()) {
        Voiture * v = (Voiture*) listesDD->getVoiture(index);
        uiOp->attributsModif->setText(v->attributsFicheDetail());
        fenetreModif(2);
        uiOp->marque->setPlainText((v->getMarque()).c_str());
        uiOp->modele->setPlainText((v->getModele()).c_str());
        uiOp->couleur->setPlainText((v->getCouleur()).c_str());
        uiOp->prix->setPlainText(QString::number(v->getPrix()));
        uiOp->annee->setPlainText(QString::number(v->getAnnee()));
        uiOp->option1->setPlainText(QString::number(v->getKilo()));
        uiOp->option2->setPlainText(QString::number(v->getPuissance()));

    } else if(uiOp->placeButton->isChecked()) {
        Lieu * l = listesDD->getLieu(index);
        uiOp->attributsModif->setText("Adresse du lieu");
        fenetreModif(3);
        uiOp->marque->setPlainText((l->getAdresse()).c_str());

    }

}

void CoteOperateur::ajout() {
    uiOp->stackedWidget->setCurrentIndex(1);

    if(uiOp->busButton->isChecked()) {
        Bus * b = new Bus();
        uiOp->attributsAjout->setText(b->attributsFicheDetail());
        fenetreModif(0);

    } else if(uiOp->bikeButton->isChecked()) {
        Velo * v = new Velo();
        uiOp->attributsAjout->setText(v->attributsFicheDetail());
        fenetreModif(1);

    } else if(uiOp->carButton->isChecked()) {
        Voiture * v = new Voiture();
        uiOp->attributsAjout->setText(v->attributsFicheDetail());
        fenetreModif(2);

    } else if(uiOp->placeButton->isChecked()) {
        //Lieu * l = listesDD->getLieu(index);
        uiOp->attributsAjout->setText("Adresse du lieu");
        fenetreModif(3);
    }
}

void CoteOperateur::validationAjout() {

    if(uiOp->addOption1->isHidden()) {
        Lieu * l = new Lieu(uiOp->addMarque->toPlainText().toStdString(), false);
        listesDD->addLieu(l);
    } else if(!uiOp->addOption4->isHidden()) {
        Bus * b = new Bus(uiOp->addOption1->toPlainText().toInt(),
                          uiOp->addOption2->toPlainText().toInt(),
                          uiOp->addOption3->toPlainText().toInt(),
                          uiOp->addOption4->toPlainText().toInt(),
                          uiOp->addModele->toPlainText().toStdString(),
                          uiOp->addMarque->toPlainText().toStdString(),
                          uiOp->addCouleur->toPlainText().toStdString(),
                          "AA-004-AC",
                          uiOp->addAnnee->toPlainText().toInt(),
                          uiOp->addPrix->toPlainText().toInt());
        //listesDD->addBus(b);
        listeBus.push_back(b->toQString());
    }

    annulation();
}

void CoteOperateur::suppression() {



    annulation();
}

void CoteOperateur::annulation() {
    uiOp->stackedWidget->setCurrentIndex(0);

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

/* 0->Bus, 1->Vélo, 2->Voiture, 3->Lieu */
void CoteOperateur::fenetreModif(int i) {
    uiOp->option1->setPlainText("");
    uiOp->option2->setPlainText("");
    uiOp->option3->setPlainText("");
    uiOp->option4->setPlainText("");
    switch (i) {
    case 0:
        uiOp->marque->show();
        uiOp->modele->show();
        uiOp->couleur->show();
        uiOp->prix->show();
        uiOp->annee->show();
        uiOp->option1->show();
        uiOp->option2->show();
        uiOp->option3->show();
        uiOp->option4->show();

        uiOp->addMarque->show();
        uiOp->addModele->show();
        uiOp->addCouleur->show();
        uiOp->addPrix->show();
        uiOp->addAnnee->show();
        uiOp->addOption1->show();
        uiOp->addOption2->show();
        uiOp->addOption3->show();
        uiOp->addOption4->show();
        break;
    case 1: case 2:
        uiOp->marque->show();
        uiOp->modele->show();
        uiOp->couleur->show();
        uiOp->prix->show();
        uiOp->annee->show();
        uiOp->option1->show();
        uiOp->option2->show();
        uiOp->option3->hide();
        uiOp->option4->hide();

        uiOp->addMarque->show();
        uiOp->addModele->show();
        uiOp->addCouleur->show();
        uiOp->addPrix->show();
        uiOp->addAnnee->show();
        uiOp->addOption1->show();
        uiOp->addOption2->show();
        uiOp->addOption3->hide();
        uiOp->addOption4->hide();
        break;
    case 3:
        uiOp->marque->show();
        uiOp->modele->hide();
        uiOp->couleur->hide();
        uiOp->prix->hide();
        uiOp->annee->hide();
        uiOp->option1->hide();
        uiOp->option2->hide();
        uiOp->option3->hide();
        uiOp->option4->hide();

        uiOp->addMarque->show();
        uiOp->addModele->hide();
        uiOp->addCouleur->hide();
        uiOp->addPrix->hide();
        uiOp->addAnnee->hide();
        uiOp->addOption1->hide();
        uiOp->addOption2->hide();
        uiOp->addOption3->hide();
        uiOp->addOption4->hide();
        break;
    }

}

CoteOperateur::~CoteOperateur() {
    delete stack;
}
