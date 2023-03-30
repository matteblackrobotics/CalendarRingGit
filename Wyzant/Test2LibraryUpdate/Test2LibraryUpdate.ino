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
#include "xPrint.h" 
#include "test.h"

void setup() 
{
  setupSerial();
  testPrint(); // if the string is too long, it fails....
  setupDotStar();
  processFirstDays();
  setFinalDay();
  setDay(dotStarCount-1, 50, 50, 0);
  setFinalLED();

  // 1. dotStar does not update, clears only when depowered, but serial does print out
  setSolinoxs2();
  //setSolinoxs1(); 
  // printSolinoxs(); // printing solinoxs fails strip

  // 2. dotStar sets but printout from xPrint fails
  // setDay(solinoxs[0], springColors[0], springColors[1], springColors[2]);
  // setDay(solinoxs[1], summerColors[0], summerColors[1], summerColors[2]);
  // setDay(solinoxs[2], fallColors[0], fallColors[1], fallColors[2]);
  // setDay(solinoxs[3], winterColors[0], winterColors[1], winterColors[2]);

  Strip1.show();
}


void loop() 
{
  Serial.println(millis());
  setDay(2,0,0,100);
  Strip1.show();
  delay(100);
  setDay(2,0,0,0);
  Strip1.show();
  delay(100);  
}
