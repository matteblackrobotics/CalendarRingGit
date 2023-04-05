// CalendarRing
// Shows 1st days of every month, solstaces and equinoxs, eventually an RTC will show current day

// Notes:
// author and filename serial out fails

// Questions:
// How does dotStar and serial.print interact
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
  setupSerial();
  setupDotStar();
  setupNeo();
  setupSonar();
  processFirstDays();
  setFinalDay();
  setFinalLED();
  

  // 1. dotStar does not update, clears only when depowered, but serial does print out
  setSolinoxs1();
  // printSolinoxs(); // printing solinoxs dotStar fails strip

  //---------- RTC ----------//
  rtc.begin();
  setupRTC(); 
  readRTC();
  printRTC();
  setToday();

  //---------- showStrips ----------//
  neo.setPixelColor(neoCount-1, 100, 0, 0); // show final LED
  showStrips();
}


void loop() 
{
  if(debugState == 1) 
  {
    Serial.println("debug outputs....");
    Serial.println(millis());
  } 

  
  //---------- mapRange to Brightness ----------//
  if(1)
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
    //Serial.print("brightness: "); Serial.println(brightness);
    showStrips();
  }


  //---------- pulse Today LED ----------//
  if(true)
  {
    if(pulseCount < todayColors[1])
    {
      setDay(dayOfYear, 0, pulseCount, 0);
      neo.show();
      delay(1);
      pulseCount++;
    }
    else{pulseCount = 0;}
  }

  
  //---------- shift brightness ----------//
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
