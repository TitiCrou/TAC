#ifndef IG_H
#define IG_H

#include <QMainWindow>
#include <QMessageBox>

#include "ui_fenetreconnexion.h"

#include "coteclient.h"
#include "coteoperateur.h"

namespace Ui {
    class IG;
}

class IG : public QMainWindow {
        Q_OBJECT

        public:
            explicit IG(QWidget *parent = 0);
            ~IG();

        protected slots:
            void adminChoice();
            void clientChoice();

        private:
            Ui::FenetreConnexion *uiConnex;
            QWidget *fconnex;
    };



#endif // IG_H
