#include "leslieux.h"

LesLieux::LesLieux() {

}

/**
 * @brief getter de la taille du veteur des lieux
 * @return la taille du veteur lesLieux
 */
int LesLieux::size() {
    return lesLieux.size();
}

/**
 * @brief getter d'un Lieu
 * @param index position du lieu dans le veteur
 * @return le lieu à la position index du veteur lesLieux
 */
Lieu * LesLieux::getLieu(int index) {
    return lesLieux.at(index);
}

/**
 * @brief ajout d'un lieu dans le vecteur
 * @param l le nouveau lieu à ajouter
 */
void LesLieux::addLieu(Lieu * l) {
    lesLieux.push_back(l);
}


/**
 * @brief toString du lieu en QString
 * @param index position du lieu dans le vecteur
 * @return un QString du lieu à la position index du vecteur des lieux
 */
QString LesLieux::toQString(int index) {
    return QString(this->getLieu(index)->toQString());
}


