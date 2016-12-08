#ifndef LIENSLOCATION_H
#define LIENSLOCATION_H

#include "ui_fenetrelocation.h"

#include <string>
#include <QMessageBox>
#include <QList>

#include "lesvehicules.h"
#include "lesvoitures.h"
#include "lesbus.h"
#include "lesvelos.h"
#include "location.h"

#include "tostring.h"

class LiensLocation : public QObject {

    Q_OBJECT
protected slots:
    void choixDate();
    void choixVehicule();
    void choixCategorie();
    void retourPagePrecedente();

public:
    LiensLocation();
    LiensLocation(Ui::FenetreLocation *ui);
    ~LiensLocation();

private:
    Ui::FenetreLocation *uiLoc;
    QList<QString> listeVoiture, listeBus, listeVelo;
    Location *location;
    LesVoitures lesVoitures;
    LesBus lesBus;
    LesVelos lesVelos;
    int nbJours;
};

#endif // LIENSLOCATION_H
