#include "listesdedonnees.h"

ListesDeDonnees::ListesDeDonnees() {

}

/* Ajout éléments dans listes */
void ListesDeDonnees::addVoiture(Voiture * v) {
    lesVoitures.addVehicule(v);
}

void ListesDeDonnees::addBus(Bus * b) {
    lesBus.addVehicule(b);
}

void ListesDeDonnees::addVelo(Velo * v) {
    lesVelos.addVehicule(v);
}

void ListesDeDonnees::addLieu (Lieu * l) {
    lesLieux.addLieu(l);
}

/* getters des éléments */
Vehicule * ListesDeDonnees::getVoiture(int index) {
    return lesVoitures.getVehicule(index);
}

Vehicule * ListesDeDonnees::getBus(int index) {
    return lesBus.getVehicule(index);
}

Vehicule * ListesDeDonnees::getVelo(int index) {
    return lesVelos.getVehicule(index);
}

Lieu * ListesDeDonnees::getLieu(int index) {
    return lesLieux.getLieu(index);
}


/* toQString des éléments */

QString ListesDeDonnees::voitureToQString(int index) {
    return lesVoitures.toQString(index);
}

QString ListesDeDonnees::busToQString(int index) {
    return lesBus.toQString(index);
}

QString ListesDeDonnees::veloToQString(int index) {
    return lesVelos.toQString(index);
}

QString ListesDeDonnees::lieuToQString(int index) {
    return lesLieux.toQString(index);
}



/* Taille des listes */

int ListesDeDonnees::voituresSize() {
    return lesVoitures.size();
}

int ListesDeDonnees::busSize() {
    return lesBus.size();
}

int ListesDeDonnees::velosSize() {
    return lesVelos.size();
}

int ListesDeDonnees::lieuxSize() {
    return lesLieux.size();
}
