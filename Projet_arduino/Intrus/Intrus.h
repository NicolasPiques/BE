#include <cstdlib>
#include "Arduino.h"
#include "moduleWIFI.h"
#include "Actionneurs.h"
#include "Capteurs.h"

using namespace std;

///////////////Classe Capteur/////////////////


class Intrus{

  public :

  //constructeur
 Intrus(){};

  //méthodes
  virtual void envoyer_mess();
  virtual void BIP();
  virtual int getborne();

};

class Voiture : public Intrus{

 public :

  //constructeur
  Voiture():Intrus(){};

  //méthodes
  virtual void envoyer_mess(){
    WIFI wifi1; 
    wifi1.envoyer_mess("Nous venons de détecter la présence d'un intrus s'apparentant à une voiture sur votre propriété. Il est préférable de venir vérifier ou d'avertir les services de police.");
    };
    
  virtual void BIP(){
    Buzzer buz;
    buz.allumer_actionneur();
    delay(5000);
    buz.eteindre_actionneur();
    delay(200);
    buz.allumer_actionneur();
    delay(5000);
    buz.eteindre_actionneur();
    };

    virtual int getborne(){return borne_inf_car;};

protected :

    int borne_inf_car;

};

class Homme : public Intrus{

 public :

  //constructeur
  Homme():Intrus(){};

  //méthodes
  virtual void envoyer_mess(){
    WIFI wifi1; 
    wifi1.envoyer_mess("Nous venons de détecter la présence d'un intrus s'apparentant à une personne sur votre propriété. Il est préférable de venir vérifier ou d'avertir les services de police.");
    };
    
  virtual void BIP(){
   Buzzer buz;
    buz.allumer_actionneur();
    delay(10000);
    buz.eteindre_actionneur();
    delay(100);
    buz.allumer_actionneur();
    delay(10000);
    buz.eteindre_actionneur();
  };

  virtual int getborne(){return borne_inf_human;};

protected :

  int borne_inf_human;
  
};

class Autre : public Intrus{

 public :

  //constructeur
  Autre():Intrus(){};

  //méthodes
  virtual void envoyer_mess(){
    WIFI wifi1; 
    wifi1.envoyer_mess("Nous venons de détecter une présence inconnue sur votre propriété.");
    };
    
  virtual void BIP(){
   Buzzer buz;
    buz.allumer_actionneur();
    delay(5000);
    buz.eteindre_actionneur();
    delay(100);
    buz.allumer_actionneur();
    delay(1000);
    buz.eteindre_actionneur();
    delay(100);
    buz.allumer_actionneur();
    delay(5000);
    buz.eteindre_actionneur();
  };

  virtual int getborne(){return borne_inf_other;};

  protected :

  int borne_inf_other;
};
