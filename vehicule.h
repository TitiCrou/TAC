#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>
#include <QString>


class Vehicule {

public:
    Vehicule();
    ~Vehicule();

    std::string getModele();
    void setModele (std::string mod);

    QString toQString();

protected:
    std::string modele;

};
#endif // VEHICULE_H
