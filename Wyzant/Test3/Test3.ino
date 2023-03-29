// Notes:
// author and filename serial out fails

// Questions:
// How does dotStar and serial.print interact
// How do .h files interact?
// adafruit dotstar thing in H file breaks it

#include "FirstDays.h"
#include "Solinox.h"
#include "xPrint.h" 
#include "test.h"

Adafruit_DotStar Strip1(dotStarCount, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR);


void setup() 
{
 
  setupSerial();
  testPrint(); // if the string is too long, it fails....
  
  processFirstDays();
  //setFinalDay();
  //setFinalLED();

  // 1. dotStar does not update, clears only when depowered, but serial does print out
  // setSolinoxs2(); 

  // 2. dotStar sets but printout from xPrint fails
  // setDay(solinoxs[0], springColors[0], springColors[1], springColors[2]);
  // setDay(solinoxs[1], summerColors[0], summerColors[1], summerColors[2]);
  // setDay(solinoxs[2], fallColors[0], fallColors[1], fallColors[2]);
  // setDay(solinoxs[3], winterColors[0], winterColors[1], winterColors[2]);

  
}


void loop() 
{
}
