#ifndef BUS_H
#define BUS_H

#include "vehicule.h"

class Bus : public Vehicule {

public:
    Bus();
    Bus(int km, int cap, double height, double weight, std::string mod, std::string marq, std::string color, std::string immat, int an, double price);
    QString toQStringDetail();
    int getKilo();
    int getCapacite();
    double getHauteur();
    double getPoids();

protected:
   int kilometrage, capacite;
   double hauteur, poids;

};

#endif // BUS_H

