#ifndef VOITURE_H
#define VOITURE_H

#include "vehicule.h"

class Voiture : public Vehicule {

public:
    Voiture();
    Voiture(int km, int power, std::string mod, std::string marq, std::string color, std::string immat, int an, int price);
    QString toQStringDetail();
    QString attributsFicheDetail();
    int getKilo();
    int getPuissance();
    void setKilo(int kg);
    void setPower(int cv);

protected:
    int kilometrage, puissance;
};

#endif // VOITURE_H
