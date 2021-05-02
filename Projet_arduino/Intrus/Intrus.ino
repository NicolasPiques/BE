#include "Intrus.h"


  Ultrason sonic;
  Micro micro;
  WIFI wifi1;
  
void setup() {

  Serial.begin(9600);
  sonic.allumer_capteur();
  micro.allumer_capteur();
  wifi1.activer_wifi();

  pinMode(2, OUTPUT);
  digitalWrite(2,HIGH);
  
  micro.Set_threshold(300);
  sonic.Set_distance_ref();
  long dist = sonic.Get_distance_ref();
  Serial.print("distance ref = ");
  Serial.println(dist);

  delay(3000);

}

int compteur=0;

int borne_inf_human = 3;
int borne_inf_car = 10;
int borne_inf_other = 20;
int mail=0;
int mesure=0;

void loop() {

  
  delay(500);
  mesure=sonic.mesure();


  Serial.print("distance_calculee  = ");
  Serial.println(mesure);

  if (mesure<(sonic.Get_distance_ref()-5) and compteur<borne_inf_other and mesure>0){
    compteur++;
    Serial.print("compteur  = ");
    Serial.println(compteur); 
    
  };

  if(mail<3 and ((mesure>=(sonic.Get_distance_ref()-5)) or (compteur == borne_inf_other))){

  if (compteur>=borne_inf_other){
    
    Autre autre1;
    autre1.envoyer_mess();
    mail++;
    delay(3000);
    autre1.BIP();
    compteur=0;
    }
    
  else if (compteur>=borne_inf_car){
     Voiture voiture1;
     voiture1.envoyer_mess();
     mail++;
     delay(3000);
     voiture1.BIP();
     compteur=0;
    }
    
  else if (compteur>=borne_inf_human){
      Homme homme1;
      homme1.envoyer_mess();
      mail++;
      delay(3000);
      homme1.BIP();
      compteur=0;
    };

  };

}
