#ifndef LIEU_H
#define LIEU_H

#include <QString>
#include <string>

class Lieu {

public:
    Lieu();
    Lieu(std::string adr, bool perso);

    bool isPerso();
    void setAdresse(std::string adr);

    QString toQString();
    ~Lieu();

protected:
    std::string adresse;
    bool perso;

};



#endif // LIEU_H
