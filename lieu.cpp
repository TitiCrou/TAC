#include "lieu.h"

Lieu::Lieu() {

}

/**
 * @brief Constructeur d'un Lieu
 * @param adr son adresse postal
 * @param pers son paramètre permettant de savoir si le Lieu est personnel ou proposé par l'appli
 */
Lieu::Lieu(std::string adr, bool pers) {
    adresse = adr;
    perso = pers;
}

/**
 * @brief setter de l'adresse
 * @param adr nouvelle adresse du lieu
 */
void Lieu::setAdresse(std::string adr) {
    adresse = adr;
}

/**
 * @brief getter de l'adresse
 * @return l'adresse du lieu
 */
std::string Lieu::getAdresse() {
    return adresse;
}

/**
 * @brief getter d'information sur le lieu
 * @return si oui ou non le lieu est personnel
 */
bool Lieu::isPerso() {
    return perso;
}

/**
 * @brief getter de l'adresse en QString
 * @return l'adresse du lieu
 */
QString Lieu::toQString() {
   return QString((this->getAdresse()).c_str());
}

/**
 * @brief Construit une chaine de caractères pour l'affichage du point de retrait
 * @return une chaine de caractères pour un point de retrait
 */
QString Lieu::toQStringRetrait() {
    return QString("Point de retrait : ");
}

/**
 * @brief Construit une chaine de caractères pour l'affichage du point de rendu
 * @return une chaine de caractères pour un point de rendu
 */
QString Lieu::toQStringRendu() {
    return QString("Point de rendu : ");
}
