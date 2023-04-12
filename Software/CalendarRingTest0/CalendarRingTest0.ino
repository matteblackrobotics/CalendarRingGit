#include <MemoryFree.h>
#include <pgmStrToRAM.h>

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
  setFinalDay();
  setFinalLED();
  //stripTest();
  
  // ---------- firstDays -------- //
  calculateFirstDays();
  printFirstDays();
  printFirstDayColors();
  setFirstDays();
  Serial.println();

  showStrip1();

  Serial.println(getPSTR("Old way to force String to Flash"));
  Serial.println(F("New way to force String to Flash"));
  Serial.print(F("Free RAM (bytes) = "));
  Serial.println(freeMemory());
}

// ---------------------- loop -------------------- //
void loop() 
{
  Serial.print("millis(): ");
  Serial.println(millis());
  delay(1000);
}
