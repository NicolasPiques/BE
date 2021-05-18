#include "Intrus.h"
#include <list>

//Instanciation des capteurs et de la Wi-Fi
Ultrason sonic;
Micro micro;
WIFI wifi1;

void setup() {

  //Configuration du moniteur série,des capteurs et de la Wi-Fi
  Serial.begin(9600);
  sonic.allumer_capteur();
  micro.allumer_capteur();
  micro.Set_threshold(300); //Seuil de bruit nécessaire pour détecter le claquement de mains
  wifi1.activer_wifi();

  //Configuration des leds principale et auxiliaire
  pinMode(2, OUTPUT); //Led auxiliaire
  pinMode(16, OUTPUT); //Led principale
  digitalWrite(2, HIGH); //Extinction led auxiliaire

  Serial.println();

  do {

    try {
      
      //Mise en place de la distance de référence du capteur à ultrasons
      Serial.println("Positionnez le capteur à un emplacement fixe...");
      sonic.Set_distance_ref();
      long dist = sonic.Get_distance_ref();
      Serial.print("Distance de référence = ");
      Serial.print(dist);
      Serial.println(" cm.");
    }

    catch (int e) {
      
      //Si la distance de référence est inférieure à 60 cm, on entre dans l'exception
      if (e == 1) {
        Serial.println("Mauvaise distance de référence, merci de reprendre la mesure.");
        continue;
      }
      
    }
    break;
  } while (true);

  delay(3000);

}

//Initialisation des variables

int compteur = 0;

int borne_inf_human = 3;    //Un homme sera identifié si le compteur est entre 3 et 39
int borne_inf_car = 40;     //Une voiture sera identifiée si le compteur est entre 40 et 99
int borne_inf_other = 100;  //Un intrus inconnu sera identifié si le compteur vaut 100

int mesure = 0;

int etat_systeme = 0;       //Le système est initialement éteint

list<Intrus*> liste;        //Les intrus seront stockés dans une liste
list<Intrus*>::iterator it;

float temps_detection = 0;  //Variables utiles pour l'affichage de la liste
int affichage_intrus_OK = 0;

void loop() {

  //Appel de la fonction permettant de démarrer le système
  etat_systeme = micro.commande_clap(etat_systeme);

  //Si le système est démarré...
  if (etat_systeme == 1) {
    
    digitalWrite(16, LOW);    //La led principale est allumée

    delay(50);                //delay minimum nécessaire à l'acquisition de la mesure du capteur à ultrasons
    mesure = sonic.mesure();  //Mesure de la distance


    Serial.print("Distance_calculee  = "); //Affichage de la distance
    Serial.println(mesure);

    if (mesure < (sonic.Get_distance_ref() - 5) and compteur<borne_inf_other and mesure>0) { //Dans le cas où on détecte un objet à moins de 5 cm de la distance de référence, on incrémente le compteur
      compteur++;
      Serial.print("Compteur  = ");
      Serial.println(compteur);

    };


    if ((mesure >= (sonic.Get_distance_ref() - 5)) or (compteur == borne_inf_other)) {      //Si on ne détecte plus de présence ou que le compteur a atteint 100...

      //En fonction de la valeur du compteur, on déduit le type d'intrus détecté
      if (compteur >= borne_inf_other) {

        //On crée une instanciation de l'intrus avec allocation en mémoire
        Autre *autre1 = new Autre;
        autre1->setcompt(compteur); //On lui attribue la valeur du compteur
        autre1->envoyer_mess();     //On envoie un mail spécifique à l'intrus
        delay(1000);
        autre1->BIP();              //On active une alarme spécifique à l'intrus
        liste.push_back(autre1);    //On ajoute l'intrus à la liste
        delay(1000);
        compteur = 0;               //Remise à 0 du compteur pour le prochain intrus
        
      }

      else if (compteur >= borne_inf_car) {
        
        Voiture* voiture1 = new Voiture;
        voiture1->setcompt(compteur);
        voiture1->envoyer_mess();
        delay(1000);
        voiture1->BIP();
        liste.push_back(voiture1);
        delay(1000);
        compteur = 0;
        
      }

      else if (compteur >= borne_inf_human) {
        
        Homme* homme1 = new Homme;
        homme1->setcompt(compteur);
        homme1->envoyer_mess();
        delay(1000);
        homme1->BIP();
        liste.push_back(homme1);
        delay(1000);
        compteur = 0;
        
      }
      
      else {
        
        compteur = 0;
        
      };

    }

    affichage_intrus_OK = 0; //Les intrus de la liste doivent être affichés

  }

//Si le système est éteint...
  else {  

    digitalWrite(16, HIGH); //La led principale est éteinte

    if (affichage_intrus_OK == 0) {   //Les intrus n'ont pas encore été affichés

      if (!liste.empty()) {   //La liste n'est pas nulle, on peut afficher les informations

        Serial.println();
        Serial.println("Intrus détectés : ");
        Serial.println();
        Autre* somme_compteurs = new Autre; //Création d'une instance servant uniquement à sommer les compteurs des intrus

        for (auto &it : liste) {    //Parcours de la liste
          
          (*somme_compteurs) += (*it);    //Addition des compteurs
          it->afficherCaracteristiques(); //Affichage des caractéristiques
          
        }

        temps_detection = 0.05 * somme_compteurs->getcompt();     //1 tick = 0.05 s pour notre programme
        Serial.print("Le temps de detection est d'environ : ");   //Affichage du temps de détection
        Serial.print(temps_detection);
        Serial.println(" s.");
        Serial.println();
        
        affichage_intrus_OK = 1; //Les intrus ont été affichés, on ne souhaite plus les revoir
        liste.clear();           //On vide la liste une fois affichée
        delay(7000);
        
      }

    }
  }
}
