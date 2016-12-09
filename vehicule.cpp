#include "vehicule.h"
#include "tostring.h"

Vehicule::Vehicule() {
}

Vehicule::Vehicule(std::string mod, std::string marq, std::string color, std::string immat, int an, int price) {
    modele = mod;
    marque = marq;
    couleur = color;
    id = immat;
    annee = an;
    prix = price;
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

int Vehicule::getAnnee() {
    return annee;
}

int Vehicule::getPrix() {
    return prix;
}

int Vehicule::getPrixOption() {
    return prixOption;
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

void Vehicule::setAnnee(int an) {
    annee = an;
}

void Vehicule::setPrix(int price) {
    prix = price;
}

QString Vehicule::toQString() {
   return QString((this->getMarque()+" "+this->getModele()).c_str());
}

Vehicule::~Vehicule() {

}
