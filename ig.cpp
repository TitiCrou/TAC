#include "ig.h"
#include <QMessageBox>
#include <string>

IG::IG(QWidget *parent) : QMainWindow(parent) {


    uiPpale = new Ui::FenetrePrincipale;
    uiAvis = new Ui::FenetreAvis;
    uiLoc = new Ui::FenetreLocation;
    uiProb = new Ui::FenetreProbleme;


    uiLoc->setupUi(this);
    uiPpale->setupUi(this);
    uiAvis->setupUi(this);
    uiProb->setupUi(this);

    liensLoc = new LiensLocation(uiLoc);


    this->setWindowTitle("Transports à la carte");
    stack = new QStackedWidget(this);


    fdem = uiPpale->centralWidget;
    favis = uiAvis->centralWidget;
    floc = uiLoc->centralWidget;
    fprob = uiProb->centralWidget;

    stack->addWidget(fdem);
    stack->addWidget(favis);
    stack->addWidget(floc);
    stack->addWidget(fprob);

    this->setCentralWidget(stack);

    // Connexions uiPpale
    connect(uiPpale->askLocation, SIGNAL(clicked()), this, SLOT(loc()));
    connect(uiPpale->avis, SIGNAL(clicked()), this, SLOT(mettreAvis()));
    connect(uiPpale->probleme, SIGNAL(clicked()), this, SLOT(mettreProbleme()));

    // Connexions uiAvis
    connect(uiAvis->retour, SIGNAL(clicked()), this, SLOT(retourMenu()));
    connect(uiAvis->sendAvis, SIGNAL(clicked()), this, SLOT(validerAvis()));
    uiAvis->rate5->setChecked("TRUE");

    // Connexions uiProb
    connect(uiProb->retour_3, SIGNAL(clicked()), this, SLOT(retourMenu()));
    connect(uiProb->sendProbleme, SIGNAL(clicked()), this, SLOT(validerProbleme()));


    //Retour menu uiLoc
    connect(uiLoc->retour, SIGNAL(clicked()), this, SLOT(retourMenu()));

    connect(this, SIGNAL(signalChangement(int)), this, SLOT(afficherFenetre(int)));

}

void IG::loc() {
    uiLoc->stackedWidget->setCurrentIndex(0);
    emit signalChangement(2);
}

void IG::afficherFenetre(int index) {
    if (index >= 0) {
        stack->setCurrentIndex(index);
    }
}

void IG::mettreAvis() {
    emit signalChangement(1);
}

void IG::mettreProbleme() {
    emit signalChangement(3);
}

void IG::retourMenu() {
    emit signalChangement(0);
}


void IG::validerAvis() {
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

void IG::validerProbleme() {
    QString probleme = uiProb->zoneProbleme->toPlainText();
    QMessageBox test;
    test.setText("Problème donné :\n"+probleme);
    test.exec();
}



IG::~IG()
{
    delete stack;
    delete uiPpale;
    delete uiAvis;
    delete uiLoc;
}

