#ifndef VOITURE_H
#define VOITURE_H

#include "vehicule.h"

class Voiture : public Vehicule {

public:
    Voiture();
    QString toQString();
};

#endif // VOITURE_H
