#ifndef DOTSTAR_h
#define DOTSTAR_h
#include <Arduino.h>

// ------------------ dotStar ------------------- //
// Adafruit DotStar: https://learn.adafruit.com/adafruit-dotstar-leds/overview
// Library: https://github.com/adafruit/Adafruit_DotStar
// SPI Communication
// 5v to 5v power supply
// GND to GND power supply (to MOSFET source) out drain to GND
// DI (data input green) to D11 (SPI MOSI pin ardiuno nano)
// CI (clock input yellow) to D13 (SPI SCK pin arduino nano)

// Xiao:
// DI to 10_MOSI
// CL to 8_SCK

// ESP8266:
// DI to Silk D6
// CL to Silk D5


// ----------------- DotStar ----------------- //
#include <Adafruit_DotStar.h>
#include <SPI.h> 

const int totalDays = 365;
int ringShift = 181;
//int ringShift = 183; // shift ring half way around
// int ringShift = -10;

// Brightness Control
int brightnessMax = 200;
int brightnessDim = 20;
int brightnessMin = 0;
int brightness = 10;
int brightnessTarget;


const int dotStarCount = totalDays;
#define dotStarClockPin 8
#define dotStarDataPin 10
Adafruit_DotStar Strip1(dotStarCount, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR);

// -------------------- shiftDay ------------------- //
// @brief: shifts led index around ring
// @param: index: [0:indexMax], indexMax: Max size if index vector, shift: index shift
// @return: new index after shift with wrap around
int shiftIndex(int index, int indexMax, int shift){
  int indexNew = index + shift;
  if (indexNew < 0) {indexNew = indexMax + indexNew +1;}
  if (indexNew > indexMax) {indexNew = indexNew - indexMax-1;}
  return indexNew;
}


// -------------------- setDay ------------------- //
// @brief: set day of year RGB color
// @param: day of year or physical LED number, red[0-255], green[0-255], blue[0-255]
// @return: void, set led strip
void setDay(int Day, int R, int G, int B){
  int indexNew = shiftIndex(Day-1, totalDays-1, ringShift);
  Strip1.setPixelColor(indexNew, R, G, B);  // with index shift and 0 indexing
}


// -------------------- setFinalDay ------------------- //
void setFinalDay(){
  setDay(totalDays, 50, 0, 0);
}


// -------------------- setupDotStar ------------------- //
void setupDotStar(){ 
  pinMode(dotStarClockPin, OUTPUT);
  pinMode(dotStarDataPin, OUTPUT);
  Strip1.begin(); 
  Strip1.clear();
  Strip1.show();
  //Serial.println("setupDotStar");
}

void showStrips(){
  Strip1.show();
}

#endif
