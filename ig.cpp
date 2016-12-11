#include "ig.h"

/**
 * @brief Constructeur de la fenêtre d'accueil
 * @param parent
 */
IG::IG(QWidget *parent) : QMainWindow(parent) {

    uiConnex = new Ui::FenetreConnexion;
    uiConnex->setupUi(this);

    this->setWindowTitle("Transports à la carte");

    fconnex = uiConnex->centralWidget;

    this->setCentralWidget(fconnex);

    // Connexions uiConnex
    connect(uiConnex->adminCo, SIGNAL(clicked()), this, SLOT(adminChoice()));
    connect(uiConnex->clientCo, SIGNAL(clicked()), this, SLOT(clientChoice()));
}

/**
 * @brief Début de l'interface côté opérateur
 */
void IG::adminChoice() {
    CoteOperateur * cOperateur = new CoteOperateur(this);
    this->setCentralWidget(cOperateur->stack);
}

/**
 * @brief Début de l'interface côté client
 */
void IG::clientChoice() {
    CoteClient * cClient = new CoteClient(this);
    this->setCentralWidget(cClient->stack);
}

/**
 * @brief Destructeur d'IG
 */
IG::~IG()
{
    delete uiConnex; 
}

