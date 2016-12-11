#include "basededonnees.h"

BaseDeDonnees::BaseDeDonnees() {

}

/**
 * @brief Convertit une chaine de caractères en booléen
 * @param s la chaine à convertir, contient soit "true" soit "false"
 * @return le booléen correspondant
 */
bool BaseDeDonnees::strToBool(std::string s) {
   if(s == "true") {
      return true;
   }
   return false;
}

/**
 * @brief Crée une Voiture et le stocke dans la liste
 * @param vo les chaines de caractères correspondant aux champs du constructeur
 * Crée une Voiture à partir d'un ensemble de chaines de caractères
 * ayant un ordre précis lors de l'appel
 * (int, int, string, string, string, string, int et int)
 * et la stocke dans la liste de Voitures
 * contenue dans une instance de LiensLocation
 */
void BaseDeDonnees::chargerVoiture(std::vector<std::string> vo) {
    if (vo.size() == 9) {
        Voiture * vTemp = new Voiture(atoi(vo.at(1).c_str()), atoi(vo.at(2).c_str()),
                                      vo.at(3), vo.at(4), vo.at(5), vo.at(6),
                                      atoi(vo.at(7).c_str()), atoi(vo.at(8).c_str()));
        listesDD->addVoiture(vTemp);
    }
}

/**
 * @brief Crée un Bus et le stocke dans la liste
 * @param bu les chaines de caractères correspondant aux champs du constructeur
 * Crée un Bus à partir d'un ensemble de chaines de caractères
 * ayant un ordre précis lors de l'appel
 * (int, int, double, double, string, string, string, string, int et int)
 * et le stocke dans la liste de Bus
 * contenue dans une instance de LiensLocation
 */
void BaseDeDonnees::chargerBus(std::vector<std::string> bu) {

    if (bu.size() == 11) {
        Bus * bTemp = new Bus(atoi(bu.at(1).c_str()), atoi(bu.at(2).c_str()),
                              atof(bu.at(3).c_str()), atof(bu.at(4).c_str()),
                              bu.at(5), bu.at(6), bu.at(7), bu.at(8),
                              atoi(bu.at(9).c_str()), atoi(bu.at(10).c_str()));
        listesDD->addBus(bTemp);
    }

}

/**
 * @brief Crée un Vélo et le stocke dans la liste
 * @param ve les chaines de caractères correspondant aux champs du constructeur
 * Crée un Vélo à partir d'un ensemble de chaines de caractères
 * ayant un ordre précis lors de l'appel
 * (double, string, string, string, string, string, int et int)
 * et le stocke dans la liste de Vélos
 * contenue dans une instance de LiensLocation
 */
void BaseDeDonnees::chargerVelo(std::vector<std::string> ve) {

    if (ve.size() == 9) {
        Velo * vTemp = new Velo(atof(ve.at(1).c_str()),
                                ve.at(2), ve.at(3), ve.at(4), ve.at(5), ve.at(6),
                                atoi(ve.at(7).c_str()), atoi(ve.at(8).c_str()));
        listesDD->addVelo(vTemp);
    }
}

/**
 * @brief Crée un Lieu et le stocke dans la liste
 * @param li les chaines de caractères correspondant aux champs du constructeur
 * Crée un Lieu à partir d'un ensemble de chaines de caractères
 * ayant un ordre précis lors de l'appel
 * (string et bool)
 * et le stocke dans la liste de Lieux
 * contenue dans une instance de LiensLocation
 */
void BaseDeDonnees::chargerLieu(std::vector<std::string> li) {

    if (li.size() == 3) {
        Lieu * lTemp = new Lieu(li.at(1), strToBool(li.at(2)));
        listesDD->addLieu(lTemp);
    }
}


/**
 * @brief Récupère le texte d'un fichier et le transforme en données
 * @param ll l'instance de LiensLocation utile pour charger la "base de données"
 * Récupère tout le texte contenu dans un fichier,
 * écrit de façon à ce que chaque champ d'un élément soit séparé par une virgule
 * et chaque élément par un point virgule.
 * Chaque élément contient comme premier champ un numéro
 * qui correspond à son type (0 = Voiture, 1= Bus, 2=Vélo, 3=Lieu),
 * en fonction du numéro on appelle la fonction de chargement correspondante.
 */
void BaseDeDonnees::creerBDD(ListesDeDonnees * ldd) {
    listesDD = ldd;

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
