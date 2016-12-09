#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>
#include <QString>


class Vehicule {

public:
    Vehicule();
    Vehicule(std::string mod, std::string marq, std::string color, std::string immat, int an, int price);
    ~Vehicule();

    std::string getModele(), getMarque(), getCouleur(), getId();
    int getAnnee();
    int getPrix();
    int getPrixOption();
    void setModele (std::string mod);
    void setMarque (std::string marq);
    void setCouleur (std::string color);
    void setId (std::string id);
    void setAnnee(int an);
    void setPrix(int price);

    QString toQString();
    virtual QString toQStringDetail() = 0;
    virtual QString attributsFicheDetail() = 0;


protected:
    std::string modele, marque, couleur, id;
    int annee;
    int prix, prixOption;

};
#endif // VEHICULE_H
