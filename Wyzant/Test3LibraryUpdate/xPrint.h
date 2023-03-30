#ifndef xPrint_h
#define xPrint_h

#include <Arduino.h>
String fileName = "------------------ Test2 ------------------";
String author = "Matt Pfeiffer Feb, 2023 ";

long baudRate1 =9600;
long baudRate2 = 115200;

void setupSerial()
{
  Serial.begin(baudRate1); 
  delay(200);
  Serial.println(fileName); 
  Serial.println(author); 
  Serial.println("setupSerial");
  Serial.flush();
}

#endif
