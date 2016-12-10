#ifndef COTEOPERATEUR_H
#define COTEOPERATEUR_H

#include <QObject>

#include "ui_fenetreoperateur.h"

#include "basededonnees.h"

class CoteOperateur : public QObject {

    Q_OBJECT

signals:
    void signalChangement(int);

public:
    QStackedWidget * stack;
    CoteOperateur();
    CoteOperateur(QWidget *parent);
    ~CoteOperateur();

private:
    Ui::FenetreOperateur * uiOp;
    BaseDeDonnees bdd;
};

#endif // COTEOPERATEUR_H
