#include "ig.h"

IG::IG(QWidget *parent) : QMainWindow(parent), uiPpale(new Ui::FenetrePrincipale), uiAvis(new Ui::FenetreAvis), uiLoc(new Ui::FenetreLocation)
{
    uiPpale->setupUi(this);
    uiAvis->setupUi(this);
    uiLoc->setupUi(this);
    stack = new QStackedWidget(this);

    fdem = uiPpale->centralWidget;
    favis = uiAvis->centralWidget;
    floc = uiLoc->centralWidget;

    stack->addWidget(fdem);
    stack->addWidget(favis);
    stack->addWidget(floc);

    this->setCentralWidget(stack);
    //stack->setCurrentIndex(0); /*Fixe la fenetre de demarrage*/

    connect(uiPpale->askLocation, SIGNAL(clicked()), this, SLOT(loc()));

    connect(uiPpale->avis, SIGNAL(clicked()), this, SLOT(mettreAvis()));
    connect(uiAvis->retour, SIGNAL(clicked()), this, SLOT(retourMenu()));
    connect(uiLoc->retour, SIGNAL(clicked()), this, SLOT(retourMenu()));
    connect(this, SIGNAL(signalChangement(int)), this, SLOT(afficherFenetre(int)));

}

void IG::loc() {
    //uiPpale->askLocation->setText("Demande OK");
    emit signalChangement(2);
}

void IG::afficherFenetre(int index) {
    if (index >= 0) {
        stack->setCurrentIndex(index);
    }
}

void IG::mettreAvis () {
    emit signalChangement(1);
}

void IG::retourMenu() {
    emit signalChangement(0);
}

IG::~IG()
{
    delete uiPpale;
    delete uiAvis;
}

