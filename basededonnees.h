#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H

#include <QObject>

#include <string.h>
#include <string>
#include <sstream>

#include "lienslocation.h"
#include "voiture.h"
#include "bus.h"
#include "velo.h"

#define TAILLE_MAX 1000

class BaseDeDonnees {

public:
    BaseDeDonnees();
    void creerBDD(LiensLocation * ll);
    ~BaseDeDonnees();

private:
    FILE *fichier ;
    LiensLocation * liensLoc;
    void chargerVoiture(std::vector<std::string> vo);
    void chargerBus(std::vector<std::string> bu);
    void chargerVelo(std::vector<std::string> ve);
};

#endif // BASEDEDONNEES_H
