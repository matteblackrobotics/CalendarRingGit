#ifndef DOTSTAR_h
#define DOTSTAR_h

#include "xPrint.h"

#include <Adafruit_DotStar.h>
#include <SPI.h>         
#define dotStarCount 432
#define dotStarDataPin 4
#define dotStarClockPin 5

const int stripPowerPin = 2;

Adafruit_DotStar Strip1(dotStarCount, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR);

// -------------------- stripPowerOn ------------------- //
void stripPowerOn()
{
  digitalWrite(stripPowerPin, HIGH);
  printString("stripPowerState: On");
  printLn();
  delay(10);
}

// -------------------- stripPowerOff ------------------- //
void stripPowerOff()
{
  digitalWrite(stripPowerPin, LOW);
  printString("stripPowerState: Off");
  printLn();
  delay(10);
}

// -------------------- setDay ------------------- //
void setDay(int Day, int R, int G, int B)
{
  // index shift from day 1 to index 0
  Strip1.setPixelColor(Day-1, R,G,B);
}


// -------------------- setFirstLED ------------------- //
void setFirstLED()
{
  setDay(1, 0, 100, 0);
  // printString("firstLED set Green");
  // printLn();
}


// -------------------- setFinalLED ------------------- //
void setFinalLED()
{
  setDay(dotStarCount, 100, 0, 0);
  // printInt("finalLED set Green", dotStarCount);
  // printLn();
}


// -------------------- setupDotStar ------------------- //
void setupDotStar()
{ 
 pinMode(stripPowerPin, OUTPUT); 
 stripPowerOff();
 stripPowerOn();
 Strip1.begin();
 Strip1.clear();
 // Strip1.setBrightness(10); //adjust brightness here
 Strip1.setPixelColor(0, 100, 0,0); 
 Strip1.show();
 Strip1.clear();
 // delay(1000);
 // Serial.println("setupDotStar: Complete");
 // printString("setupDotStar: compelete"); printLn();
}

#endif
