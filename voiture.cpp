#include "voiture.h"

Voiture::Voiture() : Vehicule() {

}

Voiture::Voiture(int km, int power, std::string mod, std::string marq, std::string color, std::string immat, int an, double price) :
    Vehicule(mod, marq, color, immat, an , price){
    kilometrage = km;
    puissance = power;
}

int Voiture::getKilo() {
    return kilometrage;
}

int Voiture::getPuissance() {
    return puissance;
}

QString Voiture::toQStringDetail() {

    return QString((this->getMarque()+"\n"
                    +this->getModele()+"\n"
                    +this->getCouleur()+"\n"
                    /*+std::to_string(this->getPrix())+"\n"
                    +std::to_string(this->getAnnee())+"\n"
                    +std::to_string(this->getKilo())+"\n"
                    +std::to_string(this->getPuissance())*/).c_str());
}
