#include "moduleWIFI.h"

void setup() {
  Serial.begin(115200);
  Serial.println();

  WIFI wifi1;

  wifi1.activer_wifi();

  wifi1.envoyer_mess("LETS GO");

}

void loop() {
  // put your main code here, to run repeatedly:

}
