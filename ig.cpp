#include "ig.h"
#include <QMessageBox>
#include <string>

IG::IG(QWidget *parent) : QMainWindow(parent) {


    uiPpale = new Ui::FenetrePrincipale;
    uiAvis = new Ui::FenetreAvis;
    uiLoc = new Ui::FenetreLocation;
    uiProb = new Ui::FenetreProbleme;
    uiConnex = new Ui::FenetreConnexion;


    uiLoc->setupUi(this);
    uiPpale->setupUi(this);
    uiAvis->setupUi(this);
    uiProb->setupUi(this);
    uiConnex->setupUi(this);

    liensLoc = new LiensLocation(uiLoc);
    liensAv = new LiensAvis(uiAvis);
    liensProb = new LiensProbleme(uiProb);

    this->setWindowTitle("Transports à la carte");
    stack = new QStackedWidget(this);

    fconnex = uiConnex->centralWidget;
    fdem = uiPpale->centralWidget;
    favis = uiAvis->centralWidget;
    floc = uiLoc->centralWidget;
    fprob = uiProb->centralWidget;


    stack->addWidget(fdem);
    stack->addWidget(favis);
    stack->addWidget(floc);
    stack->addWidget(fprob);

    this->setCentralWidget(uiConnex->centralWidget);

    // Connexions uiPpale
    connect(uiPpale->askLocation, SIGNAL(clicked()), this, SLOT(loc()));
    connect(uiPpale->avis, SIGNAL(clicked()), this, SLOT(mettreAvis()));
    connect(uiPpale->probleme, SIGNAL(clicked()), this, SLOT(mettreProbleme()));

    //Retour menu
    connect(uiLoc->menu, SIGNAL(clicked()), this, SLOT(retourMenu()));
    connect(uiAvis->menu, SIGNAL(clicked()), this, SLOT(retourMenu()));
    connect(uiProb->menu, SIGNAL(clicked()), this, SLOT(retourMenu()));

    // Connexions uiConnex
    connect(uiConnex->adminCo, SIGNAL(clicked()), this, SLOT(adminChoice()));
    connect(uiConnex->clientCo, SIGNAL(clicked()), this, SLOT(clientChoice()));

    connect(this, SIGNAL(signalChangement(int)), this, SLOT(afficherFenetre(int)));

}

void IG::loc() {
    uiLoc->stackedWidget->setCurrentIndex(0);
    uiLoc->retour->hide();
    emit signalChangement(2);
}

void IG::adminChoice() {
    this->setCentralWidget(stack);
}

void IG::clientChoice() {
    this->setCentralWidget(stack);
}

void IG::afficherFenetre(int index) {
    stack->setCurrentIndex(index);
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



IG::~IG()
{
    delete stack;
    delete uiPpale;
    delete uiAvis;
    delete uiLoc;
}

