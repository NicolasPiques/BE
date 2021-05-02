#define SOUND_SENSOR A0
#define LED 2  
#define THRESHOLD_VALUE 400


void turnOnLED(){
  digitalWrite(LED,LOW);
  }
  
void turnOffLED(){
  digitalWrite(LED,HIGH);
  }

void pins_init(){
  pinMode(LED, OUTPUT);
pinMode(SOUND_SENSOR, INPUT); 
}

void setup() {
  Serial.begin(9600);
  pins_init();
  }

void loop() {
  int sensorValue = analogRead(SOUND_SENSOR); //use A0 to read the electrical signal
  Serial.print("sensorValue ");
  Serial.println(sensorValue);
  if(sensorValue > THRESHOLD_VALUE){
    digitalWrite(LED,LOW);//if the value read from A0 is larger than 400,then light the LED
    delay(500);
    }
    digitalWrite(LED,HIGH);
}
