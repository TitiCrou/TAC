#include "lesvehicules.h"

/*****************************/
/*    Structure provisoire   */
/*        -> Héritage        */
/*****************************/

LesVehicules::LesVehicules() {
    Vehicule v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;

    v1.setModele("Porsche Cayenne");
    v2.setModele("Peugeot 207");
    v3.setModele("Audi Q5");

    v4.setModele("Bus Scolaire");
    v5.setModele("Bus Urbain");
    v6.setModele("Bus Toursime");

    v7.setModele("VTT Giant");
    v8.setModele("VTC Giant");
    v9.setModele("VTT Scott");
    v10.setModele("VTC Scott");

    listeVoitures.push_back(v1);
    listeVoitures.push_back(v2);
    listeVoitures.push_back(v3);

    listeBus.push_back(v4);
    listeBus.push_back(v5);
    listeBus.push_back(v6);

    listeVelos.push_back(v7);
    listeVelos.push_back(v8);
    listeVelos.push_back(v9);
    listeVelos.push_back(v10);

}

/* tailles des vecteurs */
int LesVehicules::voituresSize() {
    return listeVoitures.size();
}

int LesVehicules::busSize() {
    return listeBus.size();
}

int LesVehicules::velosSize() {
    return listeVelos.size();
}

/* getters des véhicules */
Vehicule LesVehicules::getVoiture (int index) {
    return listeVoitures.at(index);
}

Vehicule LesVehicules::getBus (int index) {
    return listeBus.at(index);
}

Vehicule LesVehicules::getVelo (int index) {
    return listeVelos.at(index);
}

/* transformation en QString */
QString LesVehicules::voitureToQString(int index) {
    return QString(this->getVoiture(index).toQString());
}

QString LesVehicules::busToQString(int index) {
    return QString(this->getBus(index).toQString());
}
QString LesVehicules::veloToQString(int index) {
    return QString(this->getVelo(index).toQString());
}


