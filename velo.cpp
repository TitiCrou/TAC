#include "velo.h"

#include "tostring.h"

Velo::Velo() : Vehicule() {

}

Velo::Velo(double pneu, std::string size, std::string mod, std::string marq, std::string color, std::string immat, int an, int price) :
    Vehicule(mod, marq, color, immat, an, price){
    taillePneu = pneu;
    taille = size;
    prixOption = 30;
}

double Velo::getTaillePneu() {
    return taillePneu;
}

std::string Velo::getTaille() {
    return taille;
}

QString Velo::toQStringDetail() {
    return QString((this->getMarque()+"\n"
                    +this->getModele()+"\n"
                    +this->getCouleur()+"\n"
                    +patch::to_string(this->getPrix())+"\n"
                    +patch::to_string(this->getAnnee())+"\n"
                    +patch::to_string(this->getTaillePneu())+"\n"
                    +this->getTaille()).c_str());
}

QString Velo::attributsFicheDetail() {
    return QString ("Marque\nModèle\nCouleur\nPrix par jour (€)\nAnnée\nPneus (\")\nTaille");
}
