/* This minimal example shows how to get single-shot range
measurements from the VL6180X.

The range readings are in units of mm. */

#include <Wire.h>
#include <VL6180X.h>

VL6180X sensor;

void setup() 
{
  delay(100);
 // Serial.begin(9600);
  Wire.begin();
  
  sensor.init();
  sensor.configureDefault();
  sensor.setTimeout(500);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() 
{ 
  uint16_t distance = sensor.readRangeSingleMillimeters();
//  Serial.print(distance);
  if(distance < 40)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
  }
  else if(distance < 220)
  {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1);
    digitalWrite(LED_BUILTIN, LOW);
  }
  else
  {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }
  
 // if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
 //  Serial.println();
}
