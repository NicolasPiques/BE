#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "moduleWIFI.h"
#include "EMailSender.h"
#include <ESP8266WiFi.h>

using namespace std;

void WIFI::activer_wifi() {   

  WiFi.begin("AndroidNico", "DELLyess");    //Définir ici le point d'accès Wi-Fi : WiFi.begin("nom_du_point_d_acces", "mot_de_passe");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

};

void WIFI::envoyer_mess(String mess) {

  EMailSender emailSend("projetbe4a@gmail.com", "gitlesang21!");
  EMailSender::EMailMessage message;
  message.subject = "Intrusion détectée depuis GHDetector";
  message.message = mess;
  EMailSender::Response resp = emailSend.send("orned@outlook.fr", message); //Définir ici le récepteur des mails : emailSend.send("mon_adresse@mail.com", message);


  //Utilisé pour le debug
  Serial.println("Sending status: ");
  Serial.println(resp.code);
  Serial.println(resp.desc);
  Serial.println(resp.status);

};
