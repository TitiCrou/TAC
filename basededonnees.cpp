#include "basededonnees.h"

BaseDeDonnees::BaseDeDonnees() {

}

bool BaseDeDonnees::strToBool(std::string s) {
   if(s == "true") {
      return true;
   }
   return false;
}

void BaseDeDonnees::chargerVoiture(std::vector<std::string> vo) {
    if (vo.size() == 9) {
        Voiture * vTemp = new Voiture(atoi(vo.at(1).c_str()), atoi(vo.at(2).c_str()),
                                      vo.at(3), vo.at(4), vo.at(5), vo.at(6),
                                      atoi(vo.at(7).c_str()), atoi(vo.at(8).c_str()));
        liensLoc->addVoiture(vTemp);
    }
}

void BaseDeDonnees::chargerBus(std::vector<std::string> bu) {

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

void BaseDeDonnees::chargerLieu(std::vector<std::string> li) {

    if (li.size() == 3) {
        Lieu * lTemp = new Lieu(li.at(1), strToBool(li.at(2)));
        liensLoc->addLieu(lTemp);
    }
}

void BaseDeDonnees::creerBDD(LiensLocation * ll) {
    liensLoc = ll;

    fichier = fopen("../TAC/bdd.txt", "r+");
    if (!fichier) {
        fichier = fopen("../../../../TAC/bdd.txt", "r+");
        if(!fichier) {
            printf("erreur à l'ouverture du fichier ../vehicules.txt\n") ;
            exit(2) ;
        }
    }

    char chaine[TAILLE_MAX] = "";
    std::vector<std::string> resultat;
    unsigned int j;

    std::string stringTemp;
    int debutChaine;

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

        debutChaine = atoi(resultat.at(0).c_str());
        switch (debutChaine) {
        case 0:
            chargerVoiture(resultat);
            break;
        case 1:
            chargerBus(resultat);
            break;
        case 2:
            chargerVelo(resultat);
            break;
        case 3:
            chargerLieu(resultat);
            break;
        default:
            break;
        }

        resultat.clear();
    }
    fclose(fichier);
}

BaseDeDonnees::~BaseDeDonnees() {
}
