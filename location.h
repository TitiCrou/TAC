#ifndef LOCATION_H
#define LOCATION_H

#include "vehicule.h"
#include "lieu.h"

class Location
{
public:
    Location();
    Location(Vehicule * v,int p,bool o);

    Vehicule * getVehicule();
    Lieu * getRetrait();
    Lieu * getRendu();
    int getPrix();
    bool getOption();
    void setVehicule(Vehicule * v);
    void setPrix(int f);
    void setOption(bool o);
    void setRetrait(Lieu * l);
    void setRendu(Lieu * l);

    QString toQString();
    ~Location();

protected:
    Vehicule * vehicule;
    Lieu * retrait;
    Lieu * rendu;
    int prix;
    bool option;

};




#endif // LOCATION_H
