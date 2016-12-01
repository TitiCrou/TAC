#ifndef LIENSPROBLEME_H
#define LIENSPROBLEME_H

#include <QObject>
#include <QMessageBox>

#include "ui_fenetreprobleme.h"

class LiensProbleme : public QObject
{
    Q_OBJECT
public:
    LiensProbleme();
    LiensProbleme(Ui::FenetreProbleme *ui);
    ~LiensProbleme();

protected slots:
    void validerProbleme();

private:
    Ui::FenetreProbleme * uiProb;

};

#endif // LIENSPROBLEME_H
