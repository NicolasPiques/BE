#include <cstdlib>
#include "Ultrasonic.h"


using namespace std;

///////////////Classe abstraite Capteur/////////////////


class Capteur {
  public :

    //constructeur
    Capteur() {};

    //méthodes
    virtual void allumer_capteur();
    virtual void eteindre_capteur();

};

///////////////Classe Ultrason/////////////////

class Ultrason : public Capteur {

  public :

    //constructeur
    Ultrason(): Capteur() {};

    //méthodes
    virtual void allumer_capteur() {
      Ultrasonic ultrasonic(D3);
    };
    virtual void eteindre_capteur() {};

    //Getter et Setter
    void Set_distance_ref();
    long Get_distance_ref() {
      return distance_ref;
    };

    long mesure() {
      Ultrasonic ultrasonic(D3);
      return ultrasonic.MeasureInCentimeters();
    };


  protected :

    //Attributs
    int nb_acqui;
    long distance_ref;

};

///////////////Classe Micro/////////////////

class Micro : public Capteur {

  public :

    //constructeur
    Micro(): Capteur() {};

    //méthodes
    virtual void allumer_capteur() {
      pinMode(A0, INPUT);
    };
    virtual void eteindre_capteur() {};

    //Getter et Setter
    void Set_threshold(int thre) {
      threshold = thre;
    };
    int Get_threshold() {
      return threshold;
    };
    
    int mesure() {
      int sensorvalue = analogRead(A0);
      return sensorvalue;
    };
    int commande_clap(int etat_systeme);

  protected :

    //Attributs
    int threshold;



};
