#include "lesvelos.h"

LesVelos::LesVelos(): LesVehicules() {

    //Velo(double pneu, std::string size, std::string mod, std::string marq, std::string color, std::string immat);
    Velo v1(27.5, "M", "ATX1", "Giant", "Noire/Orange", "AB-000-AA");
    Velo v2(27.5, "M", "ROAM 4", "Giant", "Noire", "AB-001-AA");
    Velo v3(27.5, "L", "ASPECT 910", "Scott", "Noire/Verte", "AB-002-AA");
    Velo v4(27.5, "M", "SILENCE EVO", "Scott", "Blanche/Orange", "AB-003-AA");

    /*
    v1.setModele("VTT Giant");
    v2.setModele("VTC Giant");
    v3.setModele("VTT Scott");
    v4.setModele("VTC Scott");*/

    lesVehicules.push_back(v1);
    lesVehicules.push_back(v2);
    lesVehicules.push_back(v3);
    lesVehicules.push_back(v4);
}

