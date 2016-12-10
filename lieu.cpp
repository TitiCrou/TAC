#include "lieu.h"

Lieu::Lieu() {

}

Lieu::Lieu(std::string dep, std::string fin) {
    adresseDepart = dep;
    adresseArrivee = fin;
}

int Lieu::getPrix() {
    return prix;
}

void Lieu::setPrix(int p) {
    prix = p;
}

void Lieu::setDepart(std::string dep) {
    adresseDepart = dep;
}

void Lieu::setArrivee(std::string fin) {
    adresseArrivee = fin;
}

