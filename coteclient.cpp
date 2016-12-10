#include "coteclient.h"

CoteClient::CoteClient(QWidget * parent) {

    uiPpale = new Ui::FenetrePrincipale;
    uiAvis = new Ui::FenetreAvis;
    uiLoc = new Ui::FenetreLocation;
    uiProb = new Ui::FenetreProbleme;

    uiLoc->setupUi(parent);
    uiPpale->setupUi(parent);
    uiAvis->setupUi(parent);
    uiProb->setupUi(parent);

    liensLoc = new LiensLocation(uiLoc);
    liensAv = new LiensAvis(uiAvis);
    liensProb = new LiensProbleme(uiProb);

    bdd.creerBDD(liensLoc);

    stack = new QStackedWidget(parent);

    fdem = uiPpale->centralWidget;
    favis = uiAvis->centralWidget;
    floc = uiLoc->centralWidget;
    fprob = uiProb->centralWidget;

    stack->addWidget(fdem);
    stack->addWidget(favis);
    stack->addWidget(floc);
    stack->addWidget(fprob);

    // Connexions uiPpale
    connect(uiPpale->askLocation, SIGNAL(clicked()), this, SLOT(loc()));
    connect(uiPpale->avis, SIGNAL(clicked()), this, SLOT(mettreAvis()));
    connect(uiPpale->probleme, SIGNAL(clicked()), this, SLOT(mettreProbleme()));

    //Retour menu
    connect(uiLoc->menu, SIGNAL(clicked()), this, SLOT(retourMenu()));
    connect(uiAvis->menu, SIGNAL(clicked()), this, SLOT(retourMenu()));
    connect(uiProb->menu, SIGNAL(clicked()), this, SLOT(retourMenu()));

    connect(this, SIGNAL(signalChangement(int)), this, SLOT(afficherFenetre(int)));
}

void CoteClient::loc() {
    uiLoc->stackedWidget->setCurrentIndex(0);
    uiLoc->retour->hide();
    emit signalChangement(2);
}

void CoteClient::afficherFenetre(int index) {
    stack->setCurrentIndex(index);
}

void CoteClient::mettreAvis() {
    emit signalChangement(1);
}

void CoteClient::mettreProbleme() {
    emit signalChangement(3);
}

void CoteClient::retourMenu() {
    emit signalChangement(0);
}

CoteClient::~CoteClient() {
    delete stack;
    delete uiPpale;
    delete uiAvis;
    delete uiLoc;
}




