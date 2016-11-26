#include "vehicule.h"

Vehicule::Vehicule() {
}

std::string Vehicule::getModele() {
    return modele;
}

void Vehicule::setModele (std::string mod) {
    modele = mod;
}

QString Vehicule::toQString() {
   return QString(this->getModele().c_str());
}

Vehicule::~Vehicule() {

}
