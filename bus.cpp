#include "bus.h"

Bus::Bus() : Vehicule() {

}

Bus::Bus(int km, int cap, double height, double weight, std::string mod, std::string marq, std::string color, std::string immat) : Vehicule(mod, marq, color, immat){
    kilometrage = km;
    capacite = cap;
    hauteur = height;
    poids = weight;
}

QString Bus::toQString() {
    return QString(this->getModele().c_str());
}


