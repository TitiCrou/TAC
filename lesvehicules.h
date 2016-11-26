#ifndef LESVEHICULES_H
#define LESVEHICULES_H

#include <vector>
#include "vehicule.h"


class LesVehicules {

public:
    LesVehicules();
    Vehicule getVoiture (int index);
    Vehicule getBus (int index);
    Vehicule getVelo (int index);



    QString voitureToQString(int index);
    QString busToQString(int index);
    QString veloToQString(int index);

    int voituresSize();
    int busSize();
    int velosSize();


private:
    std::vector<Vehicule> listeVoitures;
    std::vector<Vehicule> listeBus;
    std::vector<Vehicule> listeVelos;


};

#endif // LESVEHICULES_H
