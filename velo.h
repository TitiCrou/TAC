#ifndef VELO_H
#define VELO_H

#include "vehicule.h"

class Velo : public Vehicule {

public:
    Velo();
    Velo(double pneu, std::string size, std::string mod, std::string marq, std::string color, std::string immat, int an, int price);
    QString toQStringDetail();
    QString attributsFicheDetail();

    double getTaillePneu();
    std::string getTaille();
    void setTaille(std::string t);
    void setTaillePneu(double tp);

protected:
    double taillePneu;
    std::string taille;

};

#endif // VELO_H
