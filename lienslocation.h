#ifndef LIENSLOCATION_H
#define LIENSLOCATION_H

#include "ui_fenetrelocation.h"

#include <string>
#include <QMessageBox>
#include <QList>

#include "location.h"
#include "listesdedonnees.h"
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
    void validationLocation();

public:
    LiensLocation();
    LiensLocation(Ui::FenetreLocation *ui, ListesDeDonnees * lDD);
    ~LiensLocation();


    bool getLocVal();
    void setLocVal(bool b);

private:
    Ui::FenetreLocation *uiLoc;
    QList<QString> listeVoiture, listeBus, listeVelo, listeLieux;
    Location *location;
    int nbJours, option, prixAdresses;
    bool locVal;
    ListesDeDonnees * listesDD;
};

#endif // LIENSLOCATION_H
