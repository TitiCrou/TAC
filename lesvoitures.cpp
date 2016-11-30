#include "lesvoitures.h"

LesVoitures::LesVoitures() : LesVehicules() {
    //Voiture v1, v2, v3;

    Voiture v1(2500, 192, "RS4", "Audi", "Noire", "AA-000-AA", 2016, 120);
    Voiture v2(12000, 90, "C4", "Citroën", "Grise", "AA-001-AA", 2014, 55);
    Voiture v3(6000, 130, "S60", "Volvo", "Rouge", "AA-002-AA", 2015, 65);

    lesVehicules.push_back(v1);
    lesVehicules.push_back(v2);
    lesVehicules.push_back(v3);
}

