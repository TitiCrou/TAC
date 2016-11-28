#include "voiture.h"

Voiture::Voiture() : Vehicule() {

}

Voiture::Voiture(int km, int power, std::string mod, std::string marq, std::string color, std::string immat) : Vehicule(mod, marq, color, immat){
    kilometrage = km;
    puissance = power;
}

QString Voiture::toQString() {
    return QString(this->getModele().c_str());
}
