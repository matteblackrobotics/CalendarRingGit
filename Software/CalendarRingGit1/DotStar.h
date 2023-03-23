// DotStar LED support
// initializing
// setting
// displaying
// Serial Protocol

#ifndef DOTSTAR_h
#define DOTSTAR_h

#include "Ring.h"
#include "RTC.h"

// Neopixel Strip
#include <Adafruit_NeoPixel.h>
#define ledPin 2
#define numLeds 24
Adafruit_NeoPixel Strip2(numLeds, ledPin, NEO_GRB + NEO_KHZ800);

// DotStar
#include <Adafruit_DotStar.h>
#include <SPI.h>         
// total strip length = 144*3 = 432
// 333 works
// fails at 334
const int dotStarCountReal = 432;
const int dotStarCount = 180;
const int dotStarDataPin = 4;
const int dotStarClockPin = 5;
Adafruit_DotStar Strip1(dotStarCountReal, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR);

// MOSFET
const int stripPowerPin = 2; // Gate

// range dependent brightness
int brightness; // variable to hold brightness amplitutde
int brightnessStep = 1;   // 
const int bright = 2; // double the brightness of the LEDs
const int dim = 1;


// -------------------- showRing ------------------- //
// sets dotStarArray to set Pixel
void showRing()
{
  // set ring array to DotStars
  for(int Day = 0; Day < daysMax; Day++)
    {
      int R = ring[Day][0];
      int G = ring[Day][1];
      int B = ring[Day][2];
      Strip1.setPixelColor(Day, R, G, B);
    }
  Strip1.show();
 }


void setSecondLED()
{ 
    DateTime now = rtc.now();
    int secondTime = now.second();
    int secondLED = linearMap(secondTime, 0, 60, 0, dotStarCount-1);
    Strip1.setPixelColor(secondLED-1, 0, 0, 0);
    Strip1.setPixelColor(secondLED, 50, 0, 0); 
    Serial.println(secondLED);
}


void showStrip1()
{
  Strip1.show();
}


// -------------------- stripOn Off ------------------- //
void stripPowerOn()
{
  digitalWrite(stripPowerPin, HIGH);
  printString("stripPowerState: On");
  printLn();
  delay(10);
}

void stripPowerOff()
{
  digitalWrite(stripPowerPin, LOW);
  printString("stripPowerState: Off");
  printLn();
  delay(10);
}



void ledOff()
{
  for(int dotStar = 0; dotStar < dotStarCount; dotStar++) 
  {
    Strip1.setPixelColor(dotStar, 0, 0, 0);
  }
  Strip1.show();
}


// -------------------- remainingOff ------------------- //
// remaing leds in the strip to off
void remainingOff()
{
  for(int dotStar = dotStarCount; dotStar < dotStarCountReal; dotStar++) 
  {
    Strip1.setPixelColor(dotStar, 0, 0, 0);
  }
  printString("remainingOff: set");
  printLn();
}


// -------------------- setDay ------------------- //
void setDay(int Day, int R, int G, int B)
{
  // index shift from day 1 to index 0
  Strip1.setPixelColor(Day-1, R,G,B);
}


// -------------------- setFinalDay ------------------- //
void setFinalDay()
{
  setDay(dotStarCount, 0, 50, 0);
  printInt("finalDay set Green", dotStarCount);
  printLn();
}

// -------------------- setFinalLED ------------------- //
void setFinalLED()
{
  setDay(dotStarCountReal, 0, 50, 0);
  printInt("finalLED set Green", dotStarCountReal);
  printLn();
}

// -------------------- setupDotStar ------------------- //
void setupDotStar()
{ 
 pinMode(stripPowerPin, OUTPUT); 
 stripPowerOff();
 stripPowerOn();
 Strip1.begin();
 // Strip1.clear();
 // ledOff();
 // Strip1.setBrightness(10); //adjust brightness here
 // Strip1.setPixelColor(0, 100, 0,0); 
 Strip1.show();
 // ledOff();
 // printString("setupDotStar: compelete"); printLn();
}


/*

// -------------------- shiftBrightness ------------------- //
void shiftBrightness()
{
  for(int color = 0; color < 3; color++)
  {
    if(firstDaysColors[color] == 0)
    {
      firstDaysColors[color] = 0;
    }
    else
    {
      firstDaysColors[color] = color + 
    }
  }
}


*/

// uint_32 = strip1.getPixelColor(i);
// setBrightness();

#endif