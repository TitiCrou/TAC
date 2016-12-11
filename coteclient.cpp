#include "coteclient.h"

/**
 * @brief Constructeur de CoteClient
 * @param parent le widget parent (en l'occurrence, la QMainWindow)
 * Dans ce constructeur, les différents outils pour le client sont créés et initialisés
 */
CoteClient::CoteClient(QWidget * parent) {

    uiPpale = new Ui::FenetrePrincipale;
    uiAvis = new Ui::FenetreAvis;
    uiLoc = new Ui::FenetreLocation;
    uiProb = new Ui::FenetreProbleme;

    uiLoc->setupUi(parent);
    uiPpale->setupUi(parent);
    uiAvis->setupUi(parent);
    uiProb->setupUi(parent);

    listesDD = new ListesDeDonnees();

    bdd.creerBDD(listesDD);

    liensLoc = new LiensLocation(uiLoc, listesDD);
    liensAv = new LiensAvis(uiAvis);
    liensProb = new LiensProbleme(uiProb);


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

    uiPpale->confirmLoc->hide();

    parent->setWindowTitle("Transports à la carte");
}

/**
 * @brief Début du formulaire de location
 */
void CoteClient::loc() {
    uiLoc->stackedWidget->setCurrentIndex(0);
    uiLoc->retour->hide();
    emit signalChangement(2);
}

/**
 * @brief Change de fenêtre
 * @param index l'indice de la fenêtre à afficher
 */
void CoteClient::afficherFenetre(int index) {
    if (index != 0) {
        uiPpale->confirmLoc->hide();
    }
    stack->setCurrentIndex(index);
}

/**
 * @brief Début du formulaire d'avis
 */
void CoteClient::mettreAvis() {
    emit signalChangement(1);
}

/**
 * @brief Début du formulaire de signalement de problème
 */
void CoteClient::mettreProbleme() {
    emit signalChangement(3);
}

/**
 * @brief Retour au menu principal
 */
void CoteClient::retourMenu() {
    emit signalChangement(0);
    if (liensLoc->getLocVal()) {
        uiPpale->confirmLoc->show();
        liensLoc->setLocVal(false);
    }
}

/**
 * @brief Destructeur de CoteClient
 */
CoteClient::~CoteClient() {
    delete stack;
    delete uiPpale;
    delete uiAvis;
    delete uiLoc;
}




