// Notes:
// Serial printing failes dotStar
// try faster serial?

#include "xPrint.h"
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
  // stripTest();
  showStrip1();
       
}

// ---------------------- loop -------------------- //
void loop() 
{
  Serial.print("millis(): ");
  Serial.println(millis());
  delay(1000);
}
