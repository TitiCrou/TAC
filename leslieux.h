#ifndef LESLIEUX_H
#define LESLIEUX_H

#include <vector>
#include "lieu.h"

class LesLieux {

public:
    LesLieux();
    Lieu * getLieu (int index);
    void addLieu (Lieu * l);
    int size();
    QString toQString(int index);

protected:
    std::vector<Lieu*> lesLieux;

};

#endif // LESLIEUX_H
