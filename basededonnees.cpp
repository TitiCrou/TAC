#include "basededonnees.h"

BaseDeDonnees::BaseDeDonnees() {

}
/* std::string color, std::string immat, int an, int price;*/
void BaseDeDonnees::chargerVoiture(std::vector<std::string> vo) {
    if (vo.size() == 9) {
        Voiture * vTemp = new Voiture(atoi(vo.at(1).c_str()), atoi(vo.at(2).c_str()),
                                      vo.at(3), vo.at(4), vo.at(5), vo.at(6),
                                      atoi(vo.at(7).c_str()), atoi(vo.at(8).c_str()));
        liensLoc->addVoiture(vTemp);
    }
}

void BaseDeDonnees::chargerBus(std::vector<std::string> bu) {
    //int int
    if (bu.size() == 11) {
        Bus * bTemp = new Bus(atoi(bu.at(1).c_str()), atoi(bu.at(2).c_str()),
                              atof(bu.at(3).c_str()), atof(bu.at(4).c_str()),
                              bu.at(5), bu.at(6), bu.at(7), bu.at(8),
                              atoi(bu.at(9).c_str()), atoi(bu.at(10).c_str()));
        liensLoc->addBus(bTemp);
    }

}

void BaseDeDonnees::chargerVelo(std::vector<std::string> ve) {

    if (ve.size() == 9) {
        Velo * vTemp = new Velo(atof(ve.at(1).c_str()),
                                ve.at(2), ve.at(3), ve.at(4), ve.at(5), ve.at(6),
                                atoi(ve.at(7).c_str()), atoi(ve.at(8).c_str()));
        liensLoc->addVelo(vTemp);
    }
}



void BaseDeDonnees::creerBDD(LiensLocation * ll) {
    liensLoc = ll;

    fichier = fopen("../TAC/vehicules.txt", "r+");
    if (!fichier) {
        fichier = fopen("../../../../TAC/vehicules.txt", "r+");
        if(!fichier) {
            printf("erreur à l'ouverture du fichier ../vehicules.txt\n") ;
            exit(2) ;
        }
    }

    char chaine[TAILLE_MAX] = "";
    std::vector<std::string> resultat;
    unsigned int j;

    std::string stringTemp, debutChaine;

    while (fgets(chaine, TAILLE_MAX, fichier) != NULL) {
        j = 0;
        while (chaine[j] != ';') {
            if (chaine[j] == ',') {
                resultat.push_back(stringTemp);
                stringTemp = "";
            } else {
                stringTemp += chaine[j];
            }
            j++;
        }
        resultat.push_back(stringTemp);
        stringTemp = "";

        debutChaine = resultat.at(0);
        if (debutChaine == "0") {
            chargerVoiture(resultat);
        } else if (debutChaine == "1") {
            chargerBus(resultat);
        } else if (debutChaine == "2") {
            chargerVelo(resultat);
        }

        resultat.clear();
    }
    fclose(fichier);
}

BaseDeDonnees::~BaseDeDonnees() {
    delete fichier;
}
