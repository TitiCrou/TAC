#include "lesvehicules.h"

/*****************************/
/*    Structure provisoire   */
/*        -> Héritage        */
/*****************************/

LesVehicules::LesVehicules() {
}

/* tailles des vecteurs */
int LesVehicules::size() {
    return lesVehicules.size();
}

/* getters des véhicules */
Vehicule LesVehicules::getVehicule (int index) {
    return lesVehicules.at(index);
}

/* transformation en QString */
QString LesVehicules::toQString(int index) {
    return QString(this->getVehicule(index).toQString());
}



