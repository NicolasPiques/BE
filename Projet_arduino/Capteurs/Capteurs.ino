#include "Capteurs.h"

void setup() {

  Serial.begin(9600);

  long valeur;


  Ultrason sonic(Ultrasonic son;);
  sonic.allumer_capteur();


}

void loop() {

  valeur = sonic.mesure();

    Serial.print("distance = ");
    Serial.println(valeur);
 
    delay(50);


}
