#include "liensprobleme.h"

/**
 * @brief Constructeur vide de LiensProbleme
 */
LiensProbleme::LiensProbleme() {

}

/**
 * @brief Constructeur de LiensProbleme
 * @param ui l'interface définissant la fenêtre dédiée aux problèmes
 */
LiensProbleme::LiensProbleme(Ui::FenetreProbleme *ui) {

     this->uiProb = ui;


    // Connexions uiProb
    connect(uiProb->sendProbleme, SIGNAL(clicked()), this, SLOT(validerProbleme()));

}

/**
 * @brief Valide le problème rapporté par le loueur
 */
void LiensProbleme::validerProbleme() {
    QString probleme = uiProb->zoneProbleme->toPlainText();
    QMessageBox test;
    test.setText("Problème donné :\n"+probleme);
    test.exec();
}

/**
 * @brief Destructeur de LiensProbleme
 */
LiensProbleme::~LiensProbleme() {

}
