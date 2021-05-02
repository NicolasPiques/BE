#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "moduleWIFI.h"
#include "EMailSender.h"
#include <ESP8266WiFi.h>

using namespace std;

void WIFI::activer_wifi(){
  
  WiFi.begin("AndroidNico", "DELLyess");

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

void WIFI::envoyer_mess(String mess){

  EMailSender emailSend("projetbe4a@gmail.com", "gitlesang21!");
  EMailSender::EMailMessage message;
  message.subject = "Intrusion détectée depuis GHDetector";
  message.message = mess;
  EMailSender::Response resp = emailSend.send("orned@outlook.fr", message);

  
  //utilisé pour le debug
  Serial.println("Sending status: ");
  Serial.println(resp.code);
  Serial.println(resp.desc);
  Serial.println(resp.status);

};



  
