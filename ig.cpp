#include "ig.h"

IG::IG(QWidget *parent) : QMainWindow(parent), uiPpale(new Ui::FenetrePrincipale), uiAvis(new Ui::FenetreAvis)
{
    uiPpale->setupUi(this);
    uiAvis->setupUi(this);
    stack = new QStackedWidget(this);

    fdem = uiPpale->centralWidget;
    favis = uiAvis->centralWidget;

    stack->addWidget(fdem);
    stack->addWidget(favis);

    this->setCentralWidget(stack);
    //stack->setCurrentIndex(0); /*Fixe la fenetre de demarrage*/

    connect(uiPpale->askLocation, SIGNAL(clicked()), this, SLOT(loc()));

    connect(uiPpale->avis, SIGNAL(clicked()), this, SLOT(mettreAvis()));
    connect(this, SIGNAL(signalChangement(int)), this, SLOT(afficherFenetre(int)));

}

void IG::loc() {
    uiPpale->askLocation->setText("Demande OK");
}

void IG::afficherFenetre(int index) {
    if (index >= 0) {
        stack->setCurrentIndex(index);
    }
}

void IG::mettreAvis () {
    emit signalChangement(1);
}

IG::~IG()
{
    delete uiPpale;
    delete uiAvis;
}

