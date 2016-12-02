#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>
#include <QString>


class Vehicule {

public:
    Vehicule();
    Vehicule(std::string mod, std::string marq, std::string color, std::string id, int an, double price);
    ~Vehicule();

    std::string getModele(), getMarque(), getCouleur(), getId();
    int getAnnee();
    double getPrix();
    void setModele (std::string mod);
    void setMarque (std::string marq);
    void setCouleur (std::string color);
    void setId (std::string id);
    void setAnnee(int an);
    void setPrix(double price);

    QString toQString();
    virtual QString toQStringDetail();

protected:
    std::string modele, marque, couleur, id;
    int annee;
    double prix;

};
#endif // VEHICULE_H
