// Demo code for Grove - Temperature Sensor V1.1/1.2
// Loovee @ 2015-8-26
 
#include <math.h>
#include "Ultrasonic.h"
 
const int pinSensor = A0;     // Grove - Temperature Sensor connect to A0
 
#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif

Ultrasonic ultrasonic(D3);

void setup()
{
    Serial.begin(9600);
}
 
void loop()
{
    
 
    long RangeInCentimeters;
    RangeInCentimeters = ultrasonic.MeasureInCentimeters();
 
    Serial.print("distance = ");
    Serial.println(RangeInCentimeters);
 
    delay(50);
}
