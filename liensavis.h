#ifndef LIENSAVIS_H
#define LIENSAVIS_H

#include <QObject>
#include <QMessageBox>

#include "ui_fenetreavis.h"

class LiensAvis : public QObject
{
    Q_OBJECT
public:
    LiensAvis();
    LiensAvis(Ui::FenetreAvis *ui);
    ~LiensAvis();

protected slots:
    void validerAvis();

private:
    Ui::FenetreAvis * uiAvis;

};

#endif // LIENSAVIS_H
