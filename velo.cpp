#include "velo.h"

Velo::Velo() : Vehicule() {

}



QString Velo::toQString() {
   return QString(this->getModele().c_str());
}


