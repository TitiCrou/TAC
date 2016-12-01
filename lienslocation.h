#ifndef LIENSLOCATION_H
#define LIENSLOCATION_H

#include "ui_fenetrelocation.h"

#include <string>
#include <QMessageBox>
#include <QList>


#include "lesvoitures.h"
#include "lesbus.h"
#include "lesvelos.h"
#include "location.h"

class LiensLocation : public QObject {

signals:
    void signalChangement(int);

public slots:
    void afficherFenetre(int index);

    void choixDate();
    void choixVehicule();
    void choixCategorie();

public:
    LiensLocation();
    LiensLocation(Ui::FenetreLocation *ui);
    ~LiensLocation();

private:
    Ui::FenetreLocation *uiLoc;
    QList<QString> listeVoiture, listeBus, listeVelo;
    LesVoitures lesVoitures;
    LesBus lesBus;
    LesVelos lesVelos;
};

#endif // LIENSLOCATION_H