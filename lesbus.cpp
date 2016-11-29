#include "lesbus.h"

LesBus::LesBus(): LesVehicules() {

    //Bus(int km, int cap, double height, double weight, std::string mod, std::string marq, std::string color, std::string immat);

    Bus v1(2000, 72, 3.36, 18, "INTEGRO", "Mercedes", "Grise", "AC-000-AA");
    Bus v2(4500, 102, 3.32, 19, "CITARO", "Mercedes", "Grise", "AC-001-AA");
    Bus v3(7800, 46, 3.71, 18, "TRAVEGO", "Mercedes", "Grise", "AC-002-AA");


    /*
    v1.setModele("Bus Scolaire");
    v2.setModele("Bus Urbain");
    v3.setModele("Bus Toursime");
    */

    lesVehicules.push_back(v1);
    lesVehicules.push_back(v2);
    lesVehicules.push_back(v3);
}

