#ifndef xPrint_h
#define xPrint_h

// Serial 

#include <Arduino.h>
String fileName = "------------------ Esp8266Test4 ------------------";
String author = "Matt Pfeiffer April, 2023 ";

bool debugState = 0;

void setupSerial()
{
  Serial.begin(9600); 
  delay(200);
  Serial.println();
  Serial.println(fileName); 
  Serial.println(author); 
  Serial.println("setupSerial");
  Serial.flush();
}


#endif
