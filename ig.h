#ifndef IG_H
#define IG_H

#include <QMainWindow>
#include <QStackedWidget>
#include "ui_fenetreprincipale.h"
#include "ui_fenetreavis.h"

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

        private:
            Ui::FenetrePrincipale *uiPpale;
            Ui::FenetreAvis *uiAvis;
            QStackedWidget *stack;
            QWidget *fdem, *favis;
    };



#endif // IG_H
