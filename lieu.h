#ifndef LIEU_H
#define LIEU_H

#include <QString>
#include <string>

class Lieu {

public:
    Lieu();
    Lieu(std::string dep, std::string fin);

    int getPrix();
    void setPrix(int p);
    void setDepart(std::string dep);
    void setArrivee(std::string fin);

    QString toQstring();
    ~Lieu();

protected:
    std::string adresseDepart;
    std::string adresseArrivee;
    int prix;
};



#endif // LIEU_H
