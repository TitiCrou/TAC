#include "lesvelos.h"

LesVelos::LesVelos(): LesVehicules() {
    Velo v1, v2, v3, v4;

    v1.setModele("VTT Giant");
    v2.setModele("VTC Giant");
    v3.setModele("VTT Scott");
    v4.setModele("VTC Scott");

    lesVehicules.push_back(v1);
    lesVehicules.push_back(v2);
    lesVehicules.push_back(v3);
    lesVehicules.push_back(v4);
}

