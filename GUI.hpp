#ifndef GUI_QT
#define GUI_QT

#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>
#include <QLabel>
#include <QRadioButton>
#include <QSignalMapper>


class GUI_Qt : QObject {
  Q_OBJECT

  
  class MaFenetre : public QMainWindow {
  public:
    
    MaFenetre() : QMainWindow() {}

    
    bool confirme(const int type) const {
      QString msg = "Voulez-vous vraiment ";
      msg += ( type == 0 ? "changer de fond" :
	       (type == 1) ? "une autre base" : "quitter" );
      msg += " ?";
      // Création d'une boîte de dialogue
      QMessageBox btDlg(QMessageBox::Question,      // icone = ?
			"Demande de confirmation",  // titre 
			msg, QMessageBox::Ok        // message & ...
			| QMessageBox::Cancel);     // ... boutons
      return (btDlg.exec() == QMessageBox::Ok); 
    }
    
  protected:
    
    void keyPressEvent(QKeyEvent *e) {
      if ( ( (e->key() == Qt::Key_Q) || (e->key() == Qt::Key_X) )
	   && confirme(-1) )  close();
    }
  };
  
  /*
  static const int nbTypeConfirm = Pizzeria::idIngredient; 
  
  Pizzeria      pizzeria;     ///< @brief La fabrique de pizzas.
  MaFenetre     fenetre;      ///< @brief La fenêtre principale.
  /// @brief Le nom de la dernière pizza fabriquée.
  QLabel        description;
  /// @brief L'identificateur des types demandant confirmation.
  int           valeur[nbTypeConfirm];
  /// @brief Le tableau des boutons permettant de changer de pizza.
  QRadioButton  bouton[Pizzeria::nbTypes][Pizzeria::nbMaxIdent];
  /// @brief L'objet liant bouton et type/identificateur.
  QSignalMapper mapper; */

public:
  GUI_Qt();

private slots:  
  void gereBouton(const QString& ti);
				    
private:
  static QString toQString(const char *str) 
  { return QString::fromUtf8(str); }
  
  static QString toQString(const std::string str) 
  { return toQString( str.c_str() ); }
  
};

#endif 
