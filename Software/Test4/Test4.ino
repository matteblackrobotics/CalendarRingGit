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
#include "xPrint.h"



void setup() 
{
  setupSerial();
  setupDotStar();
  setupNeo();
  processFirstDays();
  setFinalDay();
  setFinalLED();
  

  // 1. dotStar does not update, clears only when depowered, but serial does print out
  setSolinoxs1();
  // printSolinoxs(); // printing solinoxs fails strip

  // ---------- RTC ----------//
  rtc.begin();
  setupRTC(); 
  readRTC();
  printRTC();
  setToday();


  // show strips
  Strip1.show();
  neo.setPixelColor(neoCount-1, 0,0,100); // show final LED
  neo.show();
}


void loop() 
{
  if(debugState == 1) 
  {
    Serial.println("debug outputs....");
    Serial.println(millis());
  } 

  // pulse today
  while(true)
  {
    if(pulseCount < todayColors[1])
    {
      setDay(dayOfYear, 0, pulseCount, 0);
      neo.show();
      delay(20);
      pulseCount++;
    }
    else(pulseCount = 0); 
  }
  
  // blink LEDs
  setDay(2,0,0,100);
  Strip1.show();
  neo.show();
  delay(100);
  setDay(2,0,0,0);
  Strip1.show();
  neo.show();
  delay(100);  
}
