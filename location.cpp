#include "location.h"

Location::Location()
{

}

Location::Location(Vehicule v,float p,bool o){
    vehicule = v;
    prix = p;
    option = o;
}


 Vehicule Location::getVehicule(){
    return vehicule;
}

 float Location::getPrix(){
     return prix;
 }

 bool Location::getOption(){
     return option;
 }

 void Location::setVehicule(Vehicule v){
     vehicule = v;
 }

 void Location::setPrix(float p){
     prix = p;
 }

 void Location::setOption(bool o){
     option = o;
 }

