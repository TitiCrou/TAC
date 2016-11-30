#include "vehicule.h"

Vehicule::Vehicule() {
}

Vehicule::Vehicule(std::string mod, std::string marq, std::string color, std::string immat) {
    modele = mod;
    marque = marq;
    couleur = color;
    id = immat;
}

std::string Vehicule::getModele() {
    return modele;
}

std::string Vehicule::getCouleur() {
    return couleur;
}

std::string Vehicule::getMarque() {
    return marque;
}

std::string Vehicule::getId() {
    return id;
}

void Vehicule::setModele (std::string mod) {
    modele = mod;
}

void Vehicule::setMarque(std::string marq) {
    marque = marq;
}

void Vehicule::setCouleur (std::string color) {
    couleur = color;
}

void Vehicule::setId (std::string immat) {
    id = immat;
}

QString Vehicule::toQString() {
   return QString((this->getMarque()+" "+this->getModele()).c_str());
}

Vehicule::~Vehicule() {

}
