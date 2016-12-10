#include "leslieux.h"

LesLieux::LesLieux() {
    Lieu * l1 = new Lieu("1 - Ghocancrouville Hôpital central", false);
    Lieu * l2 = new Lieu("2 - Ghocancrouville Centre des Congrès", false);
    Lieu * l3 = new Lieu("3 - Ghocancrouville Place Justicrou Decnien", false);

    lesLieux.push_back(l1);
    lesLieux.push_back(l2);
    lesLieux.push_back(l3);
}

/* tailles des vecteurs */
int LesLieux::size() {
    return lesLieux.size();
}

/* getters des lieux */
Lieu * LesLieux::getLieu(int index) {
    return lesLieux.at(index);
}

/* transformation en QString */
QString LesLieux::toQString(int index) {
    return QString(this->getLieu(index)->toQString());
}


