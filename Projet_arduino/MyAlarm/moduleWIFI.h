#include <cstdlib>
#include <Arduino.h>

using namespace std;

///////////////Classe WIFI/////////////////

class WIFI {

  public :

    //constructeur
    WIFI() {};

    //méthodes
    void envoyer_mess(String mess);
    void activer_wifi();

};
