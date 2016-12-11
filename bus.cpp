#include "bus.h"

#include "tostring.h"

Bus::Bus() : Vehicule() {

}

/**
 * @brief Constructeur de Bus
 * @param km le kilomètrage du bus
 * @param cap sa capacité maximale
 * @param height sa hauteur
 * @param weight son poids
 * @param mod son modèle (exemple : "CITARO")
 * @param marq sa marque (exemple : "Mercedes")
 * @param color sa couleur
 * @param immat le numéro de sa plaque d'immatriculation
 * @param an l'année de son achat
 * @param price son prix (par jour)
 */
Bus::Bus(int km, int cap, double height, double weight, std::string mod, std::string marq, std::string color, std::string immat, int an, int price) :
    Vehicule(mod, marq, color, immat, an, price){
    kilometrage = km;
    capacite = cap;
    hauteur = height;
    poids = weight;
    prixOption = 96;
}

/**
 * @brief getter du kilométrage
 * @return le kilométrage du bus
 */
int Bus::getKilo() {
    return kilometrage;
}

/**
 * @brief getter de la capacité maximale
 * @return la capacité maximale du bus
 */
int Bus::getCapacite() {
    return capacite;
}

/**
 * @brief getter de la hauteur
 * @return la hauteur du bus
 */
double Bus::getHauteur() {
    return hauteur;
}

/**
 * @brief getter du poids
 * @return le poids du bus
 */
double Bus::getPoids() {
    return poids;
}

/**
 * @brief Construit la fiche détaillée du bus
 * @return la fiche contenue dans un QString
 * Construit la fiche détaillée du bus pour l'afficher
 * lors de la validation du véhicule par le loueur.
 * Stocké dans un QString pour remplir le QLabel associé
 */
QString Bus::toQStringDetail() {
    return QString((this->getMarque()+"\n"
                    +this->getModele()+"\n"
                    +this->getCouleur()+"\n"
                    +patch::to_string(this->getPrix())+"\n"
                    +patch::to_string(this->getAnnee())+"\n"
                    +patch::to_string(this->getKilo())+"\n"
                    +patch::to_string(this->getCapacite())+"\n"
                    +patch::to_string(this->getHauteur())+"\n"
                    +patch::to_string(this->getPoids())).c_str());
}


QString Bus::attributsFicheDetail() {
    return QString ("Marque\nModèle\nCouleur\nPrix par jour (€)\nAnnée\nKilométrage\nCapacité\nHauteur (m)\nPoids (t)");
}


