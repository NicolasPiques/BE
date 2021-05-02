#include "Capteurs.h"


  Ultrason sonic;
  Micro micro;
  
void setup() {

  Serial.begin(9600);
  sonic.allumer_capteur();
  micro.allumer_capteur();
  micro.Set_threshold(300);
  sonic.Set_distance_ref();
  pinMode(2, OUTPUT);
  digitalWrite(2,HIGH);

}
    int mic;
    long dist;
    int etat_systeme = 0;
    
void loop() {

    etat_systeme=micro.commande_clap(etat_systeme);

    if (etat_systeme==1){
    
    dist = sonic.mesure();
    mic = micro.mesure();

    Serial.print("distance = ");
    Serial.print(dist);
    Serial.print("     son = ");
    Serial.println(mic);
    

    };
 


}
