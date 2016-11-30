#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>
#include <QString>


class Vehicule {

public:
    Vehicule();
    Vehicule(std::string mod, std::string marq, std::string color, std::string id);
    ~Vehicule();

    std::string getModele(), getMarque(), getCouleur(), getId();
    void setModele (std::string mod);
    void setMarque (std::string marq);
    void setCouleur (std::string color);
    void setId (std::string id);

    QString toQString();

protected:
    std::string modele, marque, couleur, id;

};
#endif // VEHICULE_H
