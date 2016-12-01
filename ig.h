#ifndef IG_H
#define IG_H

#include <QMainWindow>
#include <QStackedWidget>

#include "ui_fenetreprincipale.h"
#include "ui_fenetreavis.h"
#include "ui_fenetrelocation.h"
#include "ui_fenetreprobleme.h"


#include "lienslocation.h"


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
            void validerAvis();
            void validerProbleme();
            void retourMenu();

        private:
            Ui::FenetrePrincipale *uiPpale;
            Ui::FenetreAvis *uiAvis;
            Ui::FenetreLocation *uiLoc;
            Ui::FenetreProbleme *uiProb;
            QStackedWidget *stack;
            QWidget *fdem, *favis, *floc, *fprob;
            LiensLocation * liensLoc;
           // Location location;
    };



#endif // IG_H
