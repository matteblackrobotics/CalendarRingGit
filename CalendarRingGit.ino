// Notes:
// Serial printing failes dotStar
// try faster serial?

#include "xPrint.h"
#include "DotStar.h"
 
 

// ---------------------- setup -------------------- //
void setup() 
{
  setupSerial();

  setupDotStar();
  setFill(0, dotStarCount, 0, 20, 100);
  setDay(dotStarCount, 100, 100, 0);
  setDay(1, 0, 100, 0);
  setDay(5, 100, 100, 100);
  Strip1.show();  
  // Serial.println("setupDotStar: Complete");   //  yes     
  // printString("setup complete"); // yes but doesn't print
  // printLn();        
}

// ---------------------- loop -------------------- //
void loop() 
{
  Serial.print("millis(): ");
  Serial.println(millis());
  delay(1000);
}
