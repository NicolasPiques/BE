#include <cstdlib>
#include "Capteurs.h"
#include "Ultrasonic.h"


using namespace std;

void Ultrason::Set_distance_ref(){
  Ultrasonic ultrasonic(D3);
  
  int dist;
  Serial.println("Attente de la prise");
  delay(5000);
  
  dist =ultrasonic.MeasureInCentimeters();
  distance_ref=dist;
};




int Micro::commande_clap(int etat_systeme){

  if (etat_systeme==0){

  Serial.println("Systeme eteint, attente 1er clap");

  }
  
  int sensorvalue = analogRead(A0);
  int intervalle_sup = 70;
  //int intervalle_inf = 50;
  
    if(sensorvalue>=threshold){

      Serial.println("son detecte ! clap une fois la led eteinte");
      digitalWrite(2,LOW);
      delay(3000);
      digitalWrite(2,HIGH);
      
       for(int compteur=0; compteur<=intervalle_sup; compteur++){
        
       sensorvalue = analogRead(A0);
       Serial.print("compteur =");
       Serial.println(compteur);
    
          if(sensorvalue>=threshold){
            
            Serial.print("etat_systeme precedent : ");
            Serial.println(etat_systeme);
            if(etat_systeme==1){etat_systeme=0; compteur = intervalle_sup; delay(5000);}
            else if(etat_systeme==0){etat_systeme=1; compteur = intervalle_sup; delay(5000);};
            
            Serial.print("changement etat_systeme : ");
            Serial.println(etat_systeme);
          }; 
          
        };
    }; 

    return etat_systeme;
    
  };
  
