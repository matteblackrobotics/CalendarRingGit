#ifndef DOTSTAR_h
#define DOTSTAR_h

// Adafruit DotStar: https://learn.adafruit.com/adafruit-dotstar-leds/overview
// SPI Communication
// 5v to 5v power supply
// GND to GND power supply (to MOSFET source) out drain to GND
// DI (data input green) to D11 (SPI MOSI pin ardiuno nano) D4 was connceted to what I though was SDA
// CI (clock input yellow) to D13 (SPI SCK pin arduino nano) D5 was connected to what I thought was SCL

#include <Adafruit_DotStar.h>
#include <SPI.h>         
const int dotStarCount = 432;
#define dotStarDataPin 4  // green MOSI  GPIO Pins Esp8266
#define dotStarClockPin 5  // yellow CLK GPIO Pins Esp8266

const int totalDays = 365;

// MOSFET
const int stripPowerPin = 2; // gate

Adafruit_DotStar Strip1(dotStarCount, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR); 

void showStrip1()
{
  Strip1.show();
}



// -------------------- setDay ------------------- //
void setDay(int Day, int R, int G, int B)
{
  // index shift from day 1 to index 0
  Strip1.setPixelColor(Day-1, R,G,B);
}


// -------------------- setFirstLED ------------------- //
void setFirstDay()
{
  setDay(1, 100, 100, 0);
  //Serial.println("firstDay set");
}


// -------------------- setFinalDay ------------------- //
void setFinalDay()
{
  setDay(totalDays, 100, 0, 0);
  //Serial.println("finalDay set");
}


// -------------------- setFinalLED ------------------- //
void setFinalLED()
{
  setDay(dotStarCount, 100, 0, 0);
  // Serial.println("finalLED set");
}


// -------------------- setFill ------------------- //
void setFill(int startLED, int endLED, int r, int g, int b)
{
  for(int i = startLED; i < endLED; i++)
  {
    Strip1.setPixelColor(i, r, g, b);
  }
}


// -------------------- setupDotStar ------------------- //
void setupDotStar()
{ 
 Strip1.begin(); 
 Strip1.clear();
 Strip1.show();
 setFill(0, dotStarCount-1, 0, 30, 30); 
 Strip1.show();
 delay(100);
 Strip1.clear();
 // Serial.println("setupDotStar: complete");

 // ISSUE 1
 Serial.println("small works");
 //Serial.println("Large fails lllaslkasdjfkjahsdfkjna;efkn;wkmnf;lkmsfd;lkasmdflsadmf;lsdkf");
}


void stripTest()
{
  setFill(0, dotStarCount, 0, 100, 100);
  setDay(dotStarCount, 100, 100, 0);
  setDay(1, 0, 100, 0);
  setDay(5, 100, 100, 100);
  Strip1.show(); 
}
#endif
