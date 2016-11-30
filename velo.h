#ifndef VELO_H
#define VELO_H

#include "vehicule.h"

class Velo : public Vehicule {

public:
    Velo();
    Velo(double pneu, std::string size, std::string mod, std::string marq, std::string color, std::string immat, int an, double price);
    QString toQString();

protected:
    double taillePneu;
    std::string taille;

};

#endif // VELO_H
