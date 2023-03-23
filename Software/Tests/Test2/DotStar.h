#ifndef DOTSTAR_h
#define DOTSTAR_h

#include <Adafruit_DotStar.h>
#include <SPI.h>       

const int dotStarCount = 432;
#define dotStarDataPin    11
#define dotStarClockPin   13
Adafruit_DotStar Strip1(dotStarCount, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR);
// Hardware SPI is a little faster, but must be wired to specific pins
// (Arduino Uno = pin 11 for data, 13 for clock, other boards are different).

int totalDays = 365;

// -------------------- setDay ------------------- //
void setDay(int Day, int R, int G, int B)
{
  Strip1.setPixelColor(Day-1, R,G,B);
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
}

#endif
