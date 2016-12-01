#ifndef IG_H
#define IG_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QList>

#include "ui_fenetreprincipale.h"
#include "ui_fenetreavis.h"
#include "ui_fenetrelocation.h"
#include "ui_fenetreprobleme.h"

#include "lesvoitures.h"
#include "lesbus.h"
#include "lesvelos.h"
#include "location.h"

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
            void choixVehicule();
            void validerAvis();
            void validerProbleme();
            void choixCategorie();
            void choixDate();

        private:
            Ui::FenetrePrincipale *uiPpale;
            Ui::FenetreAvis *uiAvis;
            Ui::FenetreLocation *uiLoc;
            Ui::FenetreProbleme *uiProb;
            QStackedWidget *stack;
            QWidget *fdem, *favis, *floc, *fprob;
            QList<QString> listeVoiture, listeBus, listeVelo;
            LesVoitures lesVoitures;
            LesBus lesBus;
            LesVelos lesVelos;
           // Location location;
    };



#endif // IG_H
