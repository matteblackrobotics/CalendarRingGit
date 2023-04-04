#ifndef xPrint_h
#define xPrint_h

#include <Arduino.h>
String fileName = "------------------ Test3 ------------------";
String author = "Matt Pfeiffer April, 2023 ";

bool debugState = 0;

void setupSerial()
{
  Serial.begin(9600); 
  delay(200);
  Serial.println(fileName); 
  Serial.println(author); 
  Serial.println("setupSerial");
  Serial.flush();
}


#endif
