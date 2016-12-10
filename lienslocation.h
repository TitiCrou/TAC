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
#include "leslieux.h"
#include "location.h"

#include "tostring.h"

class LiensLocation : public QObject {

    Q_OBJECT
protected slots:
    void validationDate();
    void validationVehicule();
    void choixCategorie();
    void choixAdresse();
    void retourPagePrecedente();
    void validationChoix();
    void validationAdresses();

public:
    LiensLocation();
    LiensLocation(Ui::FenetreLocation *ui);
    ~LiensLocation();

    void addVoiture(Voiture * v);
    void addBus(Bus * b);
    void addVelo(Velo * v);
    void addLieu (Lieu * l);

private:
    Ui::FenetreLocation *uiLoc;
    QList<QString> listeVoiture, listeBus, listeVelo, listeLieux;
    Location *location;
    LesVoitures lesVoitures;
    LesBus lesBus;
    LesVelos lesVelos;
    LesLieux lesLieux;
    int nbJours, option, prixAdresses;
};

#endif // LIENSLOCATION_H
