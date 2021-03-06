#ifndef LESVEHICULES_H
#define LESVEHICULES_H

#include <vector>
#include "vehicule.h"

class LesVehicules {

public:
    LesVehicules();
    Vehicule * getVehicule (int index);
    void addVehicule(Vehicule * v);
    int size();
    QString toQString(int index);

protected:
    std::vector<Vehicule*> lesVehicules;

};

#endif // LESVEHICULES_H
