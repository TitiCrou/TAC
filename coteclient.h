#ifndef COTECLIENT_H
#define COTECLIENT_H

#include <QStackedWidget>

#include "ui_fenetreprincipale.h"
#include "ui_fenetreavis.h"
#include "ui_fenetrelocation.h"
#include "ui_fenetreprobleme.h"

#include "lienslocation.h"
#include "liensavis.h"
#include "liensprobleme.h"
#include "basededonnees.h"

class CoteClient : public QObject {

    Q_OBJECT

signals:
    void signalChangement(int);

public:
    QStackedWidget *stack;
    CoteClient(QWidget *parent);
    ~CoteClient();

protected slots:
    void loc();
    void afficherFenetre(int index);
    void mettreAvis();
    void mettreProbleme();
    void retourMenu();

private:
    Ui::FenetrePrincipale *uiPpale;
    Ui::FenetreAvis *uiAvis;
    Ui::FenetreLocation *uiLoc;
    Ui::FenetreProbleme *uiProb;
    QWidget *fdem, *favis, *floc, *fprob;
    LiensLocation * liensLoc;
    LiensAvis * liensAv;
    LiensProbleme * liensProb;
    BaseDeDonnees bdd;
    // Location location;
};

#endif // COTECLIENT_H
