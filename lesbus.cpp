#include "lesbus.h"

LesBus::LesBus(): LesVehicules() {
    Bus v1, v2, v3;

    v1.setModele("Bus Scolaire");
    v2.setModele("Bus Urbain");
    v3.setModele("Bus Toursime");

    lesVehicules.push_back(v1);
    lesVehicules.push_back(v2);
    lesVehicules.push_back(v3);
}

