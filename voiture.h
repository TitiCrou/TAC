#ifndef VOITURE_H
#define VOITURE_H

#include "vehicule.h"

class Voiture : public Vehicule {

public:
    Voiture();
    Voiture(int km, int power, std::string mod, std::string marq, std::string color, std::string immat);
    QString toQString();

protected:
    int kilometrage, puissance;

};

#endif // VOITURE_H
