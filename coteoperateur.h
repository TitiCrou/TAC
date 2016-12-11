#ifndef COTEOPERATEUR_H
#define COTEOPERATEUR_H

#include <QObject>
#include <string>
#include <QMessageBox>
#include <QList>

#include "ui_fenetreoperateur.h"

#include "lesvehicules.h"
#include "lesvoitures.h"
#include "lesbus.h"
#include "lesvelos.h"
#include "leslieux.h"
#include "basededonnees.h"

class CoteOperateur : public QObject {

    Q_OBJECT
protected slots:
    void choixCategorie();
    void modification();
    void ajout();

signals:
    void signalChangement(int);

public:
    QStackedWidget * stack;
    CoteOperateur();
    CoteOperateur(QWidget *parent);

    void addVoiture(Voiture * v);
    void addBus(Bus * b);
    void addVelo(Velo * v);
    void addLieu (Lieu * l);
    ~CoteOperateur();

private:
    Ui::FenetreOperateur * uiOp;
    QList<QString> listeVoiture, listeBus, listeVelo, listeLieux;
    ListesDeDonnees * listesDD;
    BaseDeDonnees bdd;
};

#endif // COTEOPERATEUR_H
