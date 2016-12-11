#ifndef LISTESDEDONNEES_H
#define LISTESDEDONNEES_H

#include "lesvoitures.h"
#include "lesbus.h"
#include "lesvelos.h"
#include "leslieux.h"

class ListesDeDonnees {


public:
    ListesDeDonnees();

    void addVoiture(Voiture * v);
    void addBus(Bus * b);
    void addVelo(Velo * v);
    void addLieu (Lieu * l);

    Vehicule * getVoiture(int index);
    Vehicule * getBus(int index);
    Vehicule * getVelo(int index);
    Lieu * getLieu(int index);

    QString voitureToQString(int index);
    QString busToQString(int index);
    QString veloToQString(int index);
    QString lieuToQString(int index);

    int voituresSize();
    int busSize();
    int velosSize();
    int lieuxSize();

private:
    LesVoitures lesVoitures;
    LesBus lesBus;
    LesVelos lesVelos;
    LesLieux lesLieux;
};

#endif // LISTESDEDONNEES_H
