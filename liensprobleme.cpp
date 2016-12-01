#include "liensprobleme.h"

LiensProbleme::LiensProbleme() {

}

LiensProbleme::LiensProbleme(Ui::FenetreProbleme *ui) {

     this->uiProb = ui;


    // Connexions uiProb
    connect(uiProb->sendProbleme, SIGNAL(clicked()), this, SLOT(validerProbleme()));

}

void LiensProbleme::validerProbleme() {
    QString probleme = uiProb->zoneProbleme->toPlainText();
    QMessageBox test;
    test.setText("Problème donné :\n"+probleme);
    test.exec();
}

LiensProbleme::~LiensProbleme() {

}
