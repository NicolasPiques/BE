#include <cstdlib>
#include "Ultrasonic.h"

using namespace std;

///////////////Classe Capteur/////////////////


class Capteur{
  public :

  //constructeur
  Capteur(){};

  //méthodes
  virtual void allumer_capteur();
  virtual void eteindre_capteur();

};

class Ultrason : public Capteur{

 public :

  //constructeur
  Ultrason(Ultrasonic ultras):Capteur(),ultra(ultras){};

  //méthodes
  virtual void allumer_capteur(){ultra = ultra(D3);};

  void Set_distance_ref(int dist){distance_ref=dist;};

  long mesure(){
    long RangeInCentimeters;
    RangeInCentimeters = ultra.MeasureInCentimeters();
    return RangeInCentimeters;}
    ;
  

 protected :

    int nb_acqui;
    int distance_ref;
    Ultrasonic ultra;

};
