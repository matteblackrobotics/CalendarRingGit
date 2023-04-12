#ifndef xPrint_h
#define xPrint_h

// Serial 

#include <MemoryFree.h>
#include <pgmStrToRAM.h>

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

void checkMemory()
{
  //Serial.print(F("Free RAM (bytes) = "));
  Serial.print("Free RAM (bytes): ");
  Serial.println(freeMemory());
}

#endif
