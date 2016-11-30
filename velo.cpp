#include "velo.h"

Velo::Velo() : Vehicule() {

}

Velo::Velo(double pneu, std::string size, std::string mod, std::string marq, std::string color, std::string immat, int an, double price) : Vehicule(mod, marq, color, immat, an , price){
    taillePneu = pneu;
    taille = size;
}

QString Velo::toQString() {
   return QString(this->getModele().c_str());
}


