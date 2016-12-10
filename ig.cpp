#include "ig.h"

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

void IG::adminChoice() {
    CoteOperateur * cOperateur = new CoteOperateur(this);
    this->setCentralWidget(cOperateur->stack);
}

void IG::clientChoice() {
    CoteClient * cClient = new CoteClient(this);
    this->setCentralWidget(cClient->stack);
}

IG::~IG()
{
    delete uiConnex; 
}

