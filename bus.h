#ifndef BUS_H
#define BUS_H

#include "vehicule.h"

class Bus : public Vehicule {

public:
    Bus();
    QString toQString();
};

#endif // BUS_H

