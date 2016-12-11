#include "vehicule.h"
#include "tostring.h"

Vehicule::Vehicule() {
}

/**
 * @brief Constructeur d'un Véhicule (Bus, Vélo ou Voiture)
 * @param mod son modèle
 * @param marq sa marque
 * @param color sa couleur
 * @param immat son numéro d'identification
 * @param an l'année de son achat
 * @param price son prix (par jour)
 */
Vehicule::Vehicule(std::string mod, std::string marq, std::string color, std::string immat, int an, int price) {
    modele = mod;
    marque = marq;
    couleur = color;
    id = immat;
    annee = an;
    prix = price;
}

/**
 * @brief getter du modèle
 * @return le modèle du véhicule
 */
std::string Vehicule::getModele() {
    return modele;
}

/**
 * @brief getter de la couleur
 * @return la couleur du véhicule
 */
std::string Vehicule::getCouleur() {
    return couleur;
}

/**
 * @brief getter de la marque
 * @return la marque du véhicule
 */
std::string Vehicule::getMarque() {
    return marque;
}

/**
 * @brief getter du numéro d'identification
 * @return le numéro d'identification du véhicule
 */
std::string Vehicule::getId() {
    return id;
}

/**
 * @brief getter de l'année d'achat
 * @return l'année d'achat du véhicule
 */
int Vehicule::getAnnee() {
    return annee;
}

/**
 * @brief getter du prix par jour
 * @return le prix par jour du véhicule
 */
int Vehicule::getPrix() {
    return prix;
}

/**
 * @brief getter du prix de l'option du véhicule (chauffeur ou assistance électrique)
 * @return le prix de l'option par jour du véhicule
 */
int Vehicule::getPrixOption() {
    return prixOption;
}

/**
 * @brief setter du modèle
 * @param mod le nouveau modèle du véhicule
 */
void Vehicule::setModele (std::string mod) {
    modele = mod;
}

/**
 * @brief setter de la marque
 * @param marq la nouvelle marque du véhicule
 */
void Vehicule::setMarque(std::string marq) {
    marque = marq;
}

/**
 * @brief setter de la couleur
 * @param color nouvelle couleur du véhicule
 */
void Vehicule::setCouleur (std::string color) {
    couleur = color;
}

/**
 * @brief setter du numéro d'identification
 * @param immat le nouveau numéro d'identification du véhicule
 */
void Vehicule::setId (std::string immat) {
    id = immat;
}

/**
 * @brief setter de l'année d'achat
 * @param an la nouvelle année d'achat du véhicule
 */
void Vehicule::setAnnee(int an) {
    annee = an;
}

/**
 * @brief setter du prix par jour
 * @param price le nouveau prix par jour du véhicule
 */
void Vehicule::setPrix(int price) {
    prix = price;
}

/**
 * @brief Construit le nom d'un véhicule, habituellement la marque et le modèle (Exemple : "Peugeot 208")
 * @return le nom du véhicule composé de sa marque et de son modèle
 */
QString Vehicule::toQString() {
   return QString((this->getMarque()+" "+this->getModele()).c_str());
}

Vehicule::~Vehicule() {

}
