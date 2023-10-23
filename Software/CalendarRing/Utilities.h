#ifndef Utilities_h
#define Utilities_h

#include <Arduino.h>
String fileName = "------------------ CalendarRing.9 - Xiao ------------------";
String author = "Matt Pfeiffer - September, 2023 ";

void setupUtilities()
{
  //Serial.begin(9600); 
  Serial.begin(19200);
  delay(200);
  Serial.println();
  Serial.println(fileName); 
  Serial.println(author);
  Serial.flush();
}
#endif