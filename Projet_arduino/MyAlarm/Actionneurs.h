#include <cstdlib>
#include "Arduino.h"

using namespace std;

///////////////Classe abstraite Actionneur/////////////////


class Actionneur{

  public :

  //constructeur
 Actionneur(){};

  //méthodes
  virtual void allumer_actionneur();
  virtual void eteindre_actionneur();

};


///////////////Classe Buzzer/////////////////

class Buzzer : public Actionneur{

 public :

  //constructeur
  Buzzer():Actionneur(){pinMode(D5,OUTPUT);};

  //méthodes
  virtual void allumer_actionneur(){digitalWrite(D5,HIGH);};
  virtual void eteindre_actionneur(){digitalWrite(D5,LOW);};

};
