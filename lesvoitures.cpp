#include "lesvoitures.h"

LesVoitures::LesVoitures() : LesVehicules() {
    Voiture v1, v2, v3;

    v1.setModele("Porsche Cayenne");
    v2.setModele("Peugeot 207");
    v3.setModele("Audi Q5");

    lesVehicules.push_back(v1);
    lesVehicules.push_back(v2);
    lesVehicules.push_back(v3);
}

