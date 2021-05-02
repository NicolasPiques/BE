#include "Actionneurs.h"

  Buzzer buzzer;
  
void setup() {


}

void loop() {

  buzzer.allumer_actionneur();
  delay(500);
  buzzer.eteindre_actionneur();
  delay(500);

}
