#include "bus.h"

Bus::Bus() : Vehicule() {

}

QString Bus::toQString() {
    return QString(this->getModele().c_str());
}


