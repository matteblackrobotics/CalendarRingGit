// CalendarRing
// 365 LED ring on wall as visual indicator of progression through the year
// Shows 1st days of every month, solstices and equinoxes, read RTC and show current day
// Range finder senses if you are near and brightens ring

// Questions:
// How does dotStar and serial.print interact?
// How do .h files interact?


#include "DotStar.h"
#include "FirstDays.h"
#include "Solinox.h"
#include "RTC.h"
#include "Today.h"
#include "Sonar.h"
#include "xPrint.h"


void setup() 
{
  // -------- setups -------- //
  setupSerial();
  setupDotStar();
  setupNeo();
  // setupSonar();
  processFirstDays();
  setFinalDay();
  setFinalLED();
  setSolinoxs1();
  printSolinoxColors();

  //---------- RTC ----------//
  //rtc.begin();
  //setupRTC(); 
  //readRTC();
  //printRTC();
  //setToday();

  //---------- showStrips ----------//
  neo.setPixelColor(neoCount-1, 100, 0, 0); // show final LED
  showStrips();
  Serial.println("hello");
}


void loop() 
{
  Serial.println("loop"); delay(100);
  //---------- if debug ----------//
  if(debugState == 1) 
  {
    Serial.println("debug outputs....");
    Serial.println(millis());
  } 

  
  //---------- range to brightness ----------//
  // if in range of sonar, brighten ring
  if(0)
  {
    range = readSonar();
    printSonar();
    brightness = map(range, 130, 5, 10, 200);
    if(brightness < 0) {brightness = 0;}
    neo.setBrightness(brightness);
    Strip1.setBrightness(brightness);
    setFirstDays();
    setSolinoxs1();
    setToday();
    Serial.print("brightness: "); Serial.println(brightness);
    showStrips();
  }


  //---------- pulse Today LED ----------//
  if(0)
  {
    if(pulseCount < todayColors[1])
    {
      setDay(dayOfYear, 0, pulseCount, 0);
      showStrips();
      delay(1);
      pulseCount++;
    }
    else{pulseCount = 0;}
  }

  
  //---------- shift brightness ----------//
  // test setBrightness() function
  if(0)
  {
    if(brightness < brightnessMax)
    {
      neo.setBrightness(brightness);
      Strip1.setBrightness(brightness);
      setFirstDays();
      setSolinoxs1();
      setToday();
      //Serial.println(brightness);
      showStrips();
      brightness++;
    }
    else{brightness = 1;}
  }

  
  //---------- blink LED ----------//
  // verify code is running
  if(0)
  {
    setDay(2,0,0,100);
    showStrips();
    delay(1);
    setDay(2,0,0,0);
    showStrips();
    delay(1);  
  }
}
