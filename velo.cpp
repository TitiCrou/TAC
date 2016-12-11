#include "velo.h"

#include "tostring.h"
#include <QString>

Velo::Velo() : Vehicule() {

}


/**
 * @brief Constructeur de Velo
 * @param pneu sa taille de pneu en pouces
 * @param size sa taille du cadre
 * @param mod son modèle (Exemple : "ATX1")
 * @param marq sa marque (Exemple : "Giant")
 * @param color sa couleur
 * @param immat son numéro de chassis
 * @param an l'année de son achat
 * @param price son prix (par jour)
 */
Velo::Velo(double pneu, std::string size, std::string mod, std::string marq, std::string color, std::string immat, int an, int price) :
    Vehicule(mod, marq, color, immat, an, price){
    taillePneu = pneu;
    taille = size;
    prixOption = 30;
}

/**
 * @brief getter de la taille de pneu
 * @return la taille de pneu du Velo
 */
double Velo::getTaillePneu() {
    return taillePneu;
}

/**
 * @brief getter de la taille de cadre
 * @return la taille de cadre du Velo
 */
std::string Velo::getTaille() {
    return taille;
}

/**
 * @brief setter de la taille de cadre
 * @param t la nouvelle taille de cadre du vélo
 */
void Velo::setTaille(std::string t) {
    taille = t;
}

/**
 * @brief setter de la taille de pneu
 * @param tp la nouvelle taille de pneu du vélo (en pouces)
 */
void Velo::setTaillePneu(double tp) {
    taillePneu = tp;
}

/**
 * @brief Construit la fiche détaillée du velo
 * @return la fiche contenue dans un QString
 * Construit la fiche détaillée du velo pour l'afficher
 * lors de la validation du véhicule par le loueur.
 * Stocké dans un QString pour remplir le QLabel associé
 */
QString Velo::toQStringDetail() {
    return QString((this->getMarque()+"\n"
                    +this->getModele()+"\n"
                    +this->getCouleur()+"\n"
                    +patch::to_string(this->getPrix())+"\n"
                    +patch::to_string(this->getAnnee())+"\n"
                    +patch::to_string(this->getTaillePneu())+"\n"
                    +this->getTaille()).c_str());
}

/**
 * @brief Utile pour le remplissage du label d'attributs
 * @return les attributs du velo
 * Renvoie les attributs du velo pour remplir le QLabel associé
 * qui est affiché dans la fiche détaillée
 */
QString Velo::attributsFicheDetail() {
    return QString ("Marque\nModèle\nCouleur\nPrix par jour (€)\nAnnée\nPneus (\")\nTaille");
}
