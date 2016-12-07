#ifndef LOCATION_H
#define LOCATION_H

#include "vehicule.h"

class Location
{
public:
    Location();
    Location(Vehicule * v,float p,bool o);

    Vehicule * getVehicule();
    float getPrix();
    bool getOption();

<<<<<<< HEAD
    void setVehicule(Vehicule v);
=======
    void setVehicule(Vehicule * v);
>>>>>>> bfbeeb2c65aa5736c695ccc1f6fefee9cd112d8c
    void setPrix(float f);
    void setOption(bool o);

    QString toQstring();
    ~Location();

protected:
    Vehicule * vehicule;
    float prix;
    bool option;

};




#endif // LOCATION_H
