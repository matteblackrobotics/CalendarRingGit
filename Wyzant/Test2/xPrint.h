#ifndef xPrint_h
#define xPrint_h

#include <Arduino.h>
String fileName = "------------------ SlimMini ------------------";
String author = "Matt Pfeiffer Feb, 2023 ";


void setupSerial()
{
  Serial.begin(9600); delay(200);
  Serial.println(fileName); 
  Serial.println(author); 
  Serial.println("setupSerial");
}

#endif
