// Notes:
// Serial printing fails dotStar
// Only limited use serial.print() allows the dotStar to update
// Uncommenting line DotStar.h 43 for example prevents dotStar from updating.


#include "xPrint.h"
#include "FirstDays.h" 
#include "DotStar.h"

// ---------------------- setup -------------------- //
void setup() 
{
  setupSerial();

  // --------- dotStar -------- //
  setupDotStar();
  setFirstDay();
  setFinalDay();
  setFinalLED();
  
  // ---------- firstDays -------- //
  calculateFirstDays();
  printFirstDays();
  printFirstDayColors();
  setFirstDays();
  Serial.println();

  showStrip1();
}

// ---------------------- loop -------------------- //
void loop() 
{
  //Serial.print("millis(): ");
  //Serial.println(millis());
  delay(1000);
}
