#ifndef DOTSTAR_h
#define DOTSTAR_h

// Adafruit DotStar: https://learn.adafruit.com/adafruit-dotstar-leds/overview
// SPI Communication
// 5v to 5v power supply
// GND to GND power supply (to MOSFET source) out drain to GND
// DI (data input green) to D11 (SPI MOSI pin ardiuno nano)
// CI (clock input yellow) to D13 (SPI SCK pin arduino nano)
#include <Arduino.h>
#include "Adafruit_DotStar.h"
// #include <Adafruit_DotStar.h>
#include <SPI.h>       
const int dotStarCount = 432;
#define dotStarDataPin    11
#define dotStarClockPin   13
//#define dotStarDataPin    6
//#define dotStarClockPin   5
// extern Adafruit_DotStar Strip1;

Adafruit_DotStar Strip1(dotStarCount, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR);

int totalDays  = 365;
//int ringShift = 0;
int ringShift = -354; // set winter solstice at top


// -------------------- shiftIndex ------------------- //
// @brief: shifts index around ring
// @param: index: [0:indexMax], indexMax: Max size if index vector, shift: index shift
// @return: new index after shift with wrap around
int shiftIndex(int index, int indexMax, int shift)
{
  int indexNew;
  indexNew = index + shift;
  if (indexNew < 0) {indexNew = indexMax + indexNew + 1;}
  if (indexNew > indexMax) {indexNew = indexNew - indexMax - 1;}
  return indexNew;
}


// -------------------- setDay ------------------- //
// @brief: set day of year RGB color
// @param: day of year or physical LED number[0-numLEDs], red[0-255], green[0-255], blue[0-255]
// @return: void, set led strip
void setDay1(int Day, int R, int G, int B)
{
  Strip1.setPixelColor(Day-1, R,G,B);
}


// with ring shift
void setDay(int Day, int R, int G, int B)
{
  int newIndex = shiftIndex(Day-1, dotStarCount-1, ringShift);
  Strip1.setPixelColor(newIndex, R,G,B);
}



// -------------------- setFinalDay ------------------- //
void setFinalDay()
{
  setDay(totalDays, 50, 0, 0);
  Serial.print("finalDay set Red:");  
  Serial.print(totalDays);
  Serial.println();
}


// -------------------- setFinalLED ------------------- //
void setFinalLED()
{
  setDay(dotStarCount, 50, 0, 0);
  Serial.print("finalLED set Red:");
  Serial.print(dotStarCount);
  Serial.println();
}


void setupDotStar()
{ 
  Strip1.begin(); 
  Strip1.clear();
  Strip1.show();
  Serial.println("setupDotStar");
  //Serial.print("ringShift: "); Serial.println(ringShift);
}

#endif
