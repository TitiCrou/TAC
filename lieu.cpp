#include "lieu.h"

Lieu::Lieu() {

}

Lieu::Lieu(std::string adr, bool pers) {
    adresse = adr;
    perso = pers;
}

void Lieu::setAdresse(std::string adr) {
    adresse = adr;
}

std::string Lieu::getAdresse() {
    return adresse;
}

bool Lieu::isPerso() {
    return perso;
}

QString Lieu::toQString() {
   return QString((this->getAdresse()).c_str());
}

