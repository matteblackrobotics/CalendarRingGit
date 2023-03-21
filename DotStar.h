#ifndef DOTSTAR_h
#define DOTSTAR_h

#include <Adafruit_DotStar.h>
#include <SPI.h>         
#define dotStarCount 432
#define dotStarDataPin 4
#define dotStarClockPin 5

const int stripPowerPin = 2;

Adafruit_DotStar Strip1(dotStarCount, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR);

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


// -------------------- setupDotStar ------------------- //
void setupDotStar()
{ 
 pinMode(stripPowerPin, OUTPUT); 
 stripPowerOff();
 stripPowerOn();
 Strip1.begin();
 // Strip1.clear();
 ledOff();
 // Strip1.setBrightness(10); //adjust brightness here
 Strip1.setPixelColor(0, 100, 0,0); 
 Strip1.show();
 ledOff(); delay(200);
 // Serial.println("setupDotStar: Complete");
 // printString("setupDotStar: compelete"); printLn();
}

#endif
