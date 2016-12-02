#include "velo.h"

Velo::Velo() : Vehicule() {

}

Velo::Velo(double pneu, std::string size, std::string mod, std::string marq, std::string color, std::string immat, int an, double price) : Vehicule(mod, marq, color, immat, an , price){
    taillePneu = pneu;
    taille = size;
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
                    +std::to_string(this->getPrix())+"\n"
                    +std::to_string(this->getAnnee())+"\n"
                    +std::to_string(this->getTaillePneu())+"\n"
                    +this->getTaille()).c_str());
}


