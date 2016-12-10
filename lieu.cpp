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

bool Lieu::isPerso() {
    return perso;
}


