#include "liensavis.h"

LiensAvis::LiensAvis() {

}

LiensAvis::LiensAvis(Ui::FenetreAvis *ui) {

    this->uiAvis = ui;


    // Connexions uiAvis
    connect(uiAvis->sendAvis, SIGNAL(clicked()), this, SLOT(validerAvis()));
    uiAvis->rate5->setChecked("TRUE");
}


void LiensAvis::validerAvis() {
    QString avis = uiAvis->zoneAvis->toPlainText();
    //QString note = uiAvis->buttonGroup->checkedButton()->text();
    QString note;
    QMessageBox test;

    /*if(uiAvis->buttonGroup->checkedButton()) {
        test.setText("Veuillez selectionner une note.");
        test.exec();
    } else {*/
    note = uiAvis->buttonGroup->checkedButton()->text();
    test.setText("Note donnée : "+note+"\nAvis donné :\n"+avis);
    test.exec();
}


LiensAvis::~LiensAvis() {

}
