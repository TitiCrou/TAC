#include "voiture.h"

#include "tostring.h"

Voiture::Voiture() : Vehicule() {

}

/**
 * @brief Constructeur de la Voiture
 * @param km son kilométrage
 * @param power sa puissance en CV
 * @param mod son modèle (Exemple : "208")
 * @param marq sa marque (Exemple : "Peugeot")
 * @param color sa couleur
 * @param immat sa plaque d'immatriculation
 * @param an l'année de son achat
 * @param price son prix (par jour)
 */
Voiture::Voiture(int km, int power, std::string mod, std::string marq, std::string color, std::string immat, int an, int price) :
    Vehicule(mod, marq, color, immat, an , price){
    kilometrage = km;
    puissance = power;
    prixOption = 80;
}

/**
 * @brief getter du kilométrage
 * @return le kilométrage de la voiture
 */
int Voiture::getKilo() {
    return kilometrage;
}

/**
 * @brief getter de la puissance
 * @return la puissance de la voiture
 */
int Voiture::getPuissance() {
    return puissance;
}

/**
 * @brief setter du kilométrage
 * @param kg le nouveau kilométrage de la voiture
 */
void Voiture::setKilo(int kg) {
    kilometrage = kg;
}

/**
 * @brief setter de la puissance
 * @param cv la nouvelle puissance de la voiture
 */
void Voiture::setPower(int cv) {
    puissance = cv;
}

/**
 * @brief Construit la fiche détaillée de la voiture
 * @return la fiche contenue dans un QString
 * Construit la fiche détaillée de la voiture pour l'afficher
 * lors de la validation du véhicule par le loueur.
 * Stocké dans un QString pour remplir le QLabel associé
 */
QString Voiture::toQStringDetail() {

    return QString((this->getMarque()+"\n"
                    +this->getModele()+"\n"
                    +this->getCouleur()+"\n"
                    +patch::to_string(this->getPrix())+"\n"
                    +patch::to_string(this->getAnnee())+"\n"
                    +patch::to_string(this->getKilo())+"\n"
                    +patch::to_string(this->getPuissance())).c_str());
}

/**
 * @brief Utile pour le remplissage du label d'attributs
 * @return les attributs de la voiture
 * Renvoie les attributs de la voiture pour remplir le QLabel associé
 * qui est affiché dans la fiche détaillée
 */
QString Voiture::attributsFicheDetail() {
    return QString ("Marque\nModèle\nCouleur\nPrix par jour (€)\nAnnée\nKilométrage\nPuissance");
}
