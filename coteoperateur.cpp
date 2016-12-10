#include "coteoperateur.h"

CoteOperateur::CoteOperateur() {

}

CoteOperateur::CoteOperateur(QWidget * parent) {

    uiOp = new Ui::FenetreOperateur;
    uiOp->setupUi(parent);

    stack = new QStackedWidget(parent);

    stack->addWidget(uiOp->centralWidget);
}

CoteOperateur::~CoteOperateur() {
    delete stack;
}
