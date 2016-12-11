#include "listesdedonnees.h"

/**
 * @brief Constructeur de ListesDeDonnees
 */
ListesDeDonnees::ListesDeDonnees() {

}

/* Ajout éléments dans listes */
/**
 * @brief Ajoute une Voiture dans la liste associée
 * @param v la Voiture à ajouter
 */
void ListesDeDonnees::addVoiture(Voiture * v) {
    lesVoitures.addVehicule(v);
}

/**
 * @brief Ajoute un Bus dans la liste associée
 * @param b le Bus à ajouter
 */
void ListesDeDonnees::addBus(Bus * b) {
    lesBus.addVehicule(b);
}

/**
 * @brief Ajoute un Velo dans la liste associée
 * @param v le Velo à ajouter
 */
void ListesDeDonnees::addVelo(Velo * v) {
    lesVelos.addVehicule(v);
}

/**
 * @brief Ajoute un Lieu dans la liste associée
 * @param l le Lieu à ajouter
 */
void ListesDeDonnees::addLieu (Lieu * l) {
    lesLieux.addLieu(l);
}

/* getters des éléments */
/**
 * @brief getter d'une Voiture à un certain index
 * @param index le rang de la Voiture dans la liste
 * @return la Voiture correspondante
 */
Vehicule * ListesDeDonnees::getVoiture(int index) {
    return lesVoitures.getVehicule(index);
}

/**
 * @brief getter d'un Bus à un certain index
 * @param index le rang du Bus dans la liste
 * @return le Bus correspondant
 */
Vehicule * ListesDeDonnees::getBus(int index) {
    return lesBus.getVehicule(index);
}

/**
 * @brief getter d'un Velo à un certain index
 * @param index le rang du Velo dans la liste
 * @return le Velo correspondant
 */
Vehicule * ListesDeDonnees::getVelo(int index) {
    return lesVelos.getVehicule(index);
}

/**
 * @brief getter d'un Lieu à un certain index
 * @param index le rang du Lieu dans la liste
 * @return le Lieu correspondant
 */
Lieu * ListesDeDonnees::getLieu(int index) {
    return lesLieux.getLieu(index);
}


/* toQString des éléments */

/**
 * @brief Appelle l'affichage de la Voiture à un certain index
 * @param index le rang de la Voiture dans la liste
 * @return le QString contenant ses spécificités
 */
QString ListesDeDonnees::voitureToQString(int index) {
    return lesVoitures.toQString(index);
}

/**
 * @brief Appelle l'affichage du Bus à un certain index
 * @param index le rang du Bus dans la liste
 * @return le QString contenant ses spécificités
 */
QString ListesDeDonnees::busToQString(int index) {
    return lesBus.toQString(index);
}

/**
 * @brief Appelle l'affichage du Velo à un certain index
 * @param index le rang du Velo dans la liste
 * @return le QString contenant ses spécificités
 */
QString ListesDeDonnees::veloToQString(int index) {
    return lesVelos.toQString(index);
}

/**
 * @brief Appelle l'affichage du Lieu à un certain index
 * @param index le rang du Lieu dans la liste
 * @return le QString contenant ses spécificités
 */
QString ListesDeDonnees::lieuToQString(int index) {
    return lesLieux.toQString(index);
}



/* Taille des listes */

/**
 * @brief
 * @return La taille de la liste de Voitures
 */
int ListesDeDonnees::voituresSize() {
    return lesVoitures.size();
}

/**
 * @brief
 * @return La taille de la liste de Bus
 */
int ListesDeDonnees::busSize() {
    return lesBus.size();
}

/**
 * @brief
 * @return La taille de la liste de Velo
 */
int ListesDeDonnees::velosSize() {
    return lesVelos.size();
}

/**
 * @brief
 * @return La taille de la liste de Lieu
 */
int ListesDeDonnees::lieuxSize() {
    return lesLieux.size();
}
