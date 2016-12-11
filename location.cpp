#include "location.h"

/**
 * @brief Constructeur vide
 */
Location::Location()
{

}

/**
 * @brief Constructeur de Location
 * @param v le véhicule loué
 * @param p le prix de la location
 * @param o le booléen définissant le choix d'une option ou non
 */
Location::Location(Vehicule * v,int p,bool o){
    vehicule = v;
    prix = p;
    option = o;
}

/**
 * @brief getter du Vehicule
 * @return le Vehicule loué
 */
Vehicule * Location::getVehicule(){
    return vehicule;
}

/**
 * @brief getter du Lieu de retrait
 * @return le Lieu où le loueur viendra chercher son véhicule
 */
Lieu * Location::getRetrait() {
    return retrait;
}

/**
 * @brief getter du Lieu de rendu
 * @return le lieu où le loueur déposera son véhicule
 */
Lieu * Location::getRendu() {
    return rendu;
}

/**
 * @brief getter du prix de la location
 * @return le prix total de la location
 */
int Location::getPrix(){
    return prix;
}

/**
 * @brief getter du booléen d'option
 * @return le booléen permettant de mémoriser le choix d'une option
 */
bool Location::getOption(){
    return option;
}

/**
 * @brief setter du Lieu de retrait
 * @param l le Lieu où le loueur viendra chercher son véhicule
 */
void Location::setRetrait(Lieu * l) {
    retrait = l;
}

/**
 * @brief setter du Lieu de rendu
 * @param l le Lieu où le loueur viendra déposer son véhicule
 */
void Location::setRendu(Lieu * l) {
    rendu = l;
}

/**
 * @brief setter du Vehicule
 * @param v le véhicule que le loueur souhaite
 */
void Location::setVehicule(Vehicule * v){
    vehicule = v;
}

/**
 * @brief setter du prix
 * @param p le prix total de la location
 */
void Location::setPrix(int p){
    prix = p;
}

/**
 * @brief setter du booléen d'option
 * @param o le booléen permettant de mémoriser le choix d'une option
 */
void Location::setOption(bool o){
    option = o;
}


