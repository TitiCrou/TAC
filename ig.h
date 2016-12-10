#ifndef IG_H
#define IG_H

#include <QMainWindow>
#include <QStackedWidget>

#include "ui_fenetreprincipale.h"
#include "ui_fenetreavis.h"
#include "ui_fenetrelocation.h"
#include "ui_fenetreprobleme.h"
#include "ui_fenetreconnexion.h"


#include "lienslocation.h"
#include "liensavis.h"
#include "liensprobleme.h"

#include "basededonnees.h"

namespace Ui {
    class IG;
}

class IG : public QMainWindow {
        Q_OBJECT


        signals:
            void signalChangement(int);

        public:
            explicit IG(QWidget *parent = 0);
            ~IG();

        protected slots:
            void loc();
            void afficherFenetre(int index);
            void mettreAvis();
            void mettreProbleme();
            void retourMenu();
            void adminChoice();
            void clientChoice();


        private:
            Ui::FenetrePrincipale *uiPpale;
            Ui::FenetreAvis *uiAvis;
            Ui::FenetreLocation *uiLoc;
            Ui::FenetreProbleme *uiProb;
            Ui::FenetreConnexion *uiConnex;
            QStackedWidget *stack;
            QWidget *fdem, *favis, *floc, *fprob, *fconnex;
            LiensLocation * liensLoc;
            LiensAvis * liensAv;
            LiensProbleme * liensProb;
            BaseDeDonnees bdd;
           // Location location;
    };



#endif // IG_H
