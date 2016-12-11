#include "lesvehicules.h"

LesVehicules::LesVehicules() {
}

/**
 * @brief getter de la taille du veteur des véhicules
 * @return la taille du veteur lesVehicules
 */
int LesVehicules::size() {
    return lesVehicules.size();
}

/**
 * @brief getter d'un véhicule
 * @param index position du véhicule dans le veteur
 * @return le véhicule à la position index du veteur lesVehicules
 */
Vehicule * LesVehicules::getVehicule (int index) {
    return lesVehicules.at(index);
}

/**
 * @brief ajout d'un véhicule dans le vecteur
 * @param v le nouveau véhicule à ajouter
 */
void LesVehicules::addVehicule(Vehicule * v) {
    lesVehicules.push_back(v);
}

/**
 * @brief toString du véhicule en QString
 * @param index position du véhicule dans le vecteur
 * @return un QString du véhicule à la position index du vecteur des véhicules
 */
QString LesVehicules::toQString(int index) {
    return QString(this->getVehicule(index)->toQString());
}



