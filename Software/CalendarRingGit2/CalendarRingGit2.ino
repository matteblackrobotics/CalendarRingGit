// Notes:
// Serial printing failes dotStar
// inclduing new files fails..?

// ISSSUE 1:
// printing too many bits to serial fails the dotstar upload


#include "xPrint.h"
#include "DotStar.h"
#include "FirstDays.h" 

Adafruit_DotStar Strip1(dotStarCount, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR); 

// ---------------------- setup -------------------- //
void setup() 
{
  setupSerial();

  // --------- dotStar -------- //
  setupDotStar();
  setFirstDay();
  setFinalDay();
  setFinalLED();
  // stripTest();
  
  // ---------- firstDays -------- //
  // calculateFirstDays();
  // printFirstDays();
  // printFirstDayColors();
  // setFirstDays();
  // Serial.println();


  showStrip1();
}

// ---------------------- loop -------------------- //
void loop() 
{
  Serial.print("millis(): ");
  Serial.println(millis());
  delay(1000);
}
