#include "Intrus.h"
#include <list>



  Ultrason sonic;
  Micro micro;
  WIFI wifi1;

void setup() {

  Serial.begin(9600);
  sonic.allumer_capteur();
  micro.allumer_capteur();
  wifi1.activer_wifi();

  pinMode(2, OUTPUT);
  pinMode(16, OUTPUT);
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
int borne_inf_car = 40;
int borne_inf_other = 100;
int mail=0;
int mesure=0;

int etat_systeme = 0;

  list<Intrus> liste;
  list<Intrus>::iterator it;

void loop() {


   etat_systeme=micro.commande_clap(etat_systeme);  

    if (etat_systeme==1){
      digitalWrite(16,LOW);

  
  delay(50);
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
    autre1.setcompt(compteur);
    /*autre1.envoyer_mess();
    mail++;
    delay(3000);
    autre1.BIP();*/
    liste.push_back(autre1);
    delay(500);
    compteur=0;
    }
    
  else if (compteur>=borne_inf_car){
     Voiture voiture1;
     voiture1.setcompt(compteur);
     liste.push_back(voiture1);
     delay(500);
     /*voiture1.envoyer_mess();
     mail++;
     delay(3000);
     voiture1.BIP();*/
     compteur=0;
    }
    
  else if (compteur>=borne_inf_human){
      Homme homme1;
      homme1.setcompt(compteur);
      /*homme1.envoyer_mess();
      mail++;
      delay(3000);
      homme1.BIP();*/
      liste.push_back(homme1);
      delay(500);
      compteur=0;
    }
    else {compteur=0;};

  }

}

else{digitalWrite(16,HIGH);
for(it=liste.begin(); it!=liste.end(); it++)
{it->afficherCaracteristiques();}
}

}
