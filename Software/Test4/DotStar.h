#ifndef DOTSTAR_h
#define DOTSTAR_h

// Handles dotStar and/or neoPixel

#include "xPrint.h"

// Adafruit DotStar: https://learn.adafruit.com/adafruit-dotstar-leds/overview
// Library: https://github.com/adafruit/Adafruit_DotStar
// 
// SPI Communication
// 5v to 5v power supply
// GND to GND power supply (to MOSFET source) out drain to GND
// DI (data input green) to D11 (SPI MOSI pin ardiuno nano)
// CI (clock input yellow) to D13 (SPI SCK pin arduino nano)
#include <Arduino.h>
#include <Adafruit_DotStar.h>
#include <SPI.h>       
const int dotStarCount = 432;
#define dotStarDataPin    11
#define dotStarClockPin   13
Adafruit_DotStar Strip1(dotStarCount, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR);

#include <Adafruit_NeoPixel.h>
#define neoPin 2
#define neoCount 300
Adafruit_NeoPixel neo(neoCount, neoPin, NEO_GRB + NEO_KHZ800);

int totalDays  = 365;


// -------------------- setDay ------------------- //
// @brief: set day of year RGB color
// @param: day of year or physical LED number, red[0-255], green[0-255], blue[0-255]
// @return: void, set led strip
void setDay(int Day, int R, int G, int B)
{
  Strip1.setPixelColor(Day-1, R,G,B);
  neo.setPixelColor(Day-1, R,G,B);
}


// -------------------- setFinalDay ------------------- //
void setFinalDay()
{
  setDay(totalDays, 50, 0, 0);
  // if(debugState == 1)
  //Serial.print("finalDay set Red:");  
  //Serial.print(totalDays);
  //Serial.println();
}


// -------------------- setFinalLED ------------------- //
void setFinalLED()
{
  setDay(dotStarCount, 50, 0, 0);
  //Serial.print("finalLED set Red:");
  //Serial.print(dotStarCount);
  //Serial.println();
}


void setupDotStar()
{ 
  Strip1.begin(); 
  Strip1.clear();
  Strip1.show();
  //Serial.println("setupDotStar");
}

void setupNeo()
{ 
  neo.begin(); 
  neo.clear();
  neo.show();
}

#endif
