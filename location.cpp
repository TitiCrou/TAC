#include "location.h"

Location::Location()
{

}

Location::Location(Vehicule * v,int p,bool o){
    vehicule = v;
    prix = p;
    option = o;
}


Vehicule * Location::getVehicule(){
    return vehicule;
}

Lieu * Location::getRetrait() {
    return retrait;
}

Lieu * Location::getRendu() {
    return rendu;
}

int Location::getPrix(){
    return prix;
}

bool Location::getOption(){
    return option;
}

void Location::setRetrait(Lieu * l) {
    retrait = l;
}

void Location::setRendu(Lieu * l) {
    rendu = l;
}

void Location::setVehicule(Vehicule * v){
    vehicule = v;
}

void Location::setPrix(int p){
    prix = p;
}

void Location::setOption(bool o){
    option = o;
}


