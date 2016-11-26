#include "voiture.h"

Voiture::Voiture() : Vehicule() {

}

QString Voiture::toQString() {
    return QString(this->getModele().c_str());
}
