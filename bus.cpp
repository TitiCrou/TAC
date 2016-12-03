#include "bus.h"

Bus::Bus() : Vehicule() {

}

Bus::Bus(int km, int cap, double height, double weight, std::string mod, std::string marq, std::string color, std::string immat, int an, double price) :
    Vehicule(mod, marq, color, immat, an, price){
    kilometrage = km;
    capacite = cap;
    hauteur = height;
    poids = weight;
}

int Bus::getKilo() {
    return kilometrage;
}

int Bus::getCapacite() {
    return capacite;
}

double Bus::getHauteur() {
    return hauteur;
}

double Bus::getPoids() {
    return poids;
}

QString Bus::toQStringDetail() {
    return QString((this->getMarque()+"\n"
                    +this->getModele()+"\n"
                    +this->getCouleur()+"\n"
                    /*+std::to_string(this->getPrix())+"\n"
                    +std::to_string(this->getAnnee())+"\n"
                    +std::to_string(this->getKilo())+"\n"
                    +std::to_string(this->getCapacite())+"\n"
                    +std::to_string(this->getHauteur())+"\n"
                    +std::to_string(this->getPoids())*/).c_str());
}



