#include "GUI.hpp"

#include <QApplication>
#include <QBoxLayout>


GUI_Qt::GUI_Qt() : description("Bienvenue") {

  fenetre.setWindowTitle( toQString("Transport à la carte") );

 
  QWidget *centre = new QWidget();
  fenetre.setCentralWidget(centre);

  QBoxLayout *algtBH = new QBoxLayout(QBoxLayout::BottomToTop, centre);
  /*for(int tp = 0; tp < pizzeria.nbTypes; tp++) {
    if (tp < nbTypeConfirm)  valeur[tp] = -1;
    QWidget *ligne = new QWidget();
    QBoxLayout *algtGD = new QBoxLayout(QBoxLayout::LeftToRight, ligne);
    for(int id = 0; id < pizzeria.nbIdent(tp); id++) {
      char str[3] = "  ";
      bouton[tp][id].setText( toQString( pizzeria.nomCourt(tp, id) ) ); 
      bouton[tp][id].setShortcut(pizzeria.raccourcis(tp, id)
				 - 'a' + Qt::Key_A);
      bouton[tp][id].setEnabled(tp == pizzeria.idFond);
      bouton[tp][id].setAutoExclusive(tp != nbTypeConfirm);
      algtGD->addWidget( &(bouton[tp][id]) );
      str[0] = 'A' + tp;  // type
      str[1] = '1' + id;  // identifiant
      mapper.setMapping(&(bouton[tp][id]), str);
      connect( &(bouton[tp][id]), SIGNAL( clicked() ), 
	       &mapper, SLOT( map() ) );
    } 
    algtBH->addWidget(ligne, 0, Qt::AlignCenter);
  } */
  
  
  algtBH->addWidget(&description, 0, Qt::AlignCenter);
  
  /*connect( &mapper, SIGNAL( mapped(const QString&) ), 
	   this, SLOT( gereBouton(const QString&) ) );
  */
  
  fenetre.show();
} 

/*void GUI_Qt::gereBouton(const QString& ti) {
  const int type = ti[0].toLatin1() - 'A',
    ident = ti[1].toLatin1() - '1';
  bool ok = (type >= nbTypeConfirm) || (valeur[type] < 0);
  if (! ok) {
    ok = fenetre.confirme(type);
    if (! ok) 
      bouton[type][valeur[type]].setChecked(true);
  }
  if (ok) {
    pizzeria.ajoute(type, ident);
    if (type < nbTypeConfirm)  valeur[type] = ident;
    description.setText( toQString( pizzeria.pizza().decrit() ) );
    for(int tp = type; tp < pizzeria.nbTypes; tp++) {
      if ( (tp > type) && (tp < nbTypeConfirm) )  valeur[tp] = -1;
      for(int id = 0; id < pizzeria.nbIdent(tp); id++) {
	if ( bouton[tp][id].isChecked() && (tp > type) ) {
	  bouton[tp][id].setAutoExclusive(false);  // nécessaire
	  bouton[tp][id].setChecked(false); 
	  bouton[tp][id].setAutoExclusive(tp < nbTypeConfirm);
	}
	bouton[tp][id].setEnabled
	  ( (tp == type + 1) ||
	    ( (tp == type) && (! bouton[tp][id].isChecked() ) ) );
      }
    } 
  } 
}*/

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);  
  GUI_Qt appli;                  
  return app.exec();            
}
