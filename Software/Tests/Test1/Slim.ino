// Notes:
// Serial printing failes dotStar
// inclduing new files fails..?

// ISSSUE 1:
// printing too many bits to serial fails the dotstar upload

// #include "xPrint.h"

// Adafruit DotStar: https://learn.adafruit.com/adafruit-dotstar-leds/overview
// SPI Communication
// 5v to 5v power supply
// GND to GND power supply (to MOSFET source) out drain to GND
// DI (data input green) to D11 (SPI MOSI pin ardiuno nano) D4 was connceted to what I though was SDA
// CI (clock input yellow) to D13 (SPI SCK pin arduino nano) D5 was connected to what I thought was SCL

#include <Adafruit_DotStar.h>
#include <SPI.h>         
#define dotStarCount 432
#define dotStarDataPin 11
#define dotStarClockPin 13
Adafruit_DotStar Strip1(dotStarCount, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR); 

const int totalDays = 365;

// MOSFET
const int stripPowerPin = 2; // gate



// -------------------------- serial ------------------- //
String fileName = "------------------ Slim ------------------";
String author = "Matt Pfeiffer March, 2023 ";


// ---------------------- setup -------------------- //
// ---------------------- setup -------------------- //
void setup() 
{
  setupSerial();

  Strip1.begin(); 
 Strip1.clear();
 Strip1.show();
 setFill(0, dotStarCount-1, 0, 30, 30); 
 Strip1.show();
 delay(100);
 Strip1.clear();

  // --------- dotStar -------- //
  //setupDotStar();
  // setFirstDay();
  //setFinalDay();
  //setFinalLED();
  // stripTest();
  
  // ---------- firstDays -------- //
  // calculateFirstDays();
  // printFirstDays();
  // printFirstDayColors();
  // setFirstDays();
  // Serial.println();


  // showStrip1();
}

// ---------------------- loop -------------------- //
// ---------------------- loop -------------------- //
void loop() 
{
  Serial.print("millis(): ");
  Serial.println(millis());
  delay(1000);
}


// --------------- setupSerial --------------- //
void setupSerial()
{
  Serial.begin(9600); delay(200);
  Serial.println();
  Serial.println(fileName);
  Serial.println(author);
  Serial.println();
}


// ------------------- showStrip --------------- //
void showStrip1()
{
  // Strip1.show();
}


// -------------------- stripPowerOn ------------------- //
void stripPowerOn()
{
  digitalWrite(stripPowerPin, HIGH);
  Serial.println("stripPowerOn");
  delay(10);
}

// -------------------- stripPowerOff ------------------- //
void stripPowerOff()
{
  digitalWrite(stripPowerPin, LOW);
  Serial.println("stripPowerOff");
  delay(10);
}

// -------------------- setDay ------------------- //
void setDay(int Day, int R, int G, int B)
{
  // index shift from day 1 to index 0
  //Strip1.setPixelColor(Day-1, R,G,B);
}


// -------------------- setFirstLED ------------------- //
void setFirstDay()
{
  setDay(1, 100, 100, 0);
  Serial.println("firstDay set");
}


// -------------------- setFinalDay ------------------- //
void setFinalDay()
{
  setDay(totalDays, 100, 0, 0);
  Serial.println("finalDay set");
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
    //Strip1.setPixelColor(i, r, g, b);
  }
}


// -------------------- setupDotStar ------------------- //
void setupDotStar()
{ 
 //pinMode(stripPowerPin, OUTPUT); 
 //stripPowerOff();
 //stripPowerOn();
 Strip1.begin(); 
 Strip1.clear();
 Strip1.show();
 setFill(0, dotStarCount-1, 0, 30, 30); 
 Strip1.show();
 delay(100);
 Strip1.clear();
 //Serial.println("setupDotStar: complete");

 // ISSUE 1
 //Serial.println("small works");
 //Serial.println("Large works lllaslkasdjfkjahsdfkjna;efkn;wkmnf;lkmsfd;lkasmdflsadmf;lsdkf");
}


void stripTest()
{
  setFill(0, dotStarCount, 0, 100, 100);
  setDay(dotStarCount, 100, 100, 0);
  setDay(1, 0, 100, 0);
  setDay(5, 100, 100, 100);
  //Strip1.show(); 
}