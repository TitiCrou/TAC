#ifndef IG_H
#define IG_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QList>
#include "ui_fenetreprincipale.h"
#include "ui_fenetreavis.h"
#include "ui_fenetrelocation.h"

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
            void retourMenu();
            void choixVehicule();
            void validerAvis();
            void choixCategorie();

        private:
            Ui::FenetrePrincipale *uiPpale;
            Ui::FenetreAvis *uiAvis;
            Ui::FenetreLocation *uiLoc;
            QStackedWidget *stack;
            QWidget *fdem, *favis, *floc;
            QList<QString> listeVoiture, listeBus, listeVelo;
    };



#endif // IG_H
