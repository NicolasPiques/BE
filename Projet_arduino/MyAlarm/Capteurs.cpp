#include <cstdlib>
#include "Capteurs.h"
#include "Ultrasonic.h"
#define ERREUR 1 


using namespace std;

void Ultrason::Set_distance_ref(){
  
  Ultrasonic ultrasonic(D3);
  int dist;
  delay(5000);
  dist =ultrasonic.MeasureInCentimeters(); 
  
  {
    if(dist<=60){ //Si la distance de référence est inférierur à 60 cm, on a une exception
      
      throw ERREUR;
      
    }
    
  }
  
  distance_ref=dist;
};


int Micro::commande_clap(int etat_systeme){

  if (etat_systeme==0){

  Serial.println("Systeme eteint, attente du 1er clap...");

  }
  
  int sensorvalue = analogRead(A0);
  int intervalle_sup = 70;  //valeur avant laquelle on doit clapper
  
    if(sensorvalue>=threshold){ //Si on détecte un premier clap...

      Serial.println("Son detecté ! Clappez une fois la led eteinte.");
      digitalWrite(2,LOW);
      delay(3000);
      digitalWrite(2,HIGH);
      
       for(int compteur=0; compteur<=intervalle_sup; compteur++){
        
       sensorvalue = analogRead(A0);
       Serial.print("compteur =");
       Serial.println(compteur);
    
          if(sensorvalue>=threshold){ //Si on détecte le second clap...
            
            if(etat_systeme==1){  //on éteindra le système si celui-ci est actif
              
              etat_systeme=0; 
              compteur = intervalle_sup; 
              Serial.print("Extinction du système...");
              delay(5000);
              
              }
              
            else if(etat_systeme==0){   //on démarrera le système si celui-ci est éteint
              
              etat_systeme=1; 
              compteur = intervalle_sup; 
              Serial.print("Démarrage du système...");
              delay(5000);
              
              };
            
          };
          
        };
    }; 

    return etat_systeme;
    
  };
  
