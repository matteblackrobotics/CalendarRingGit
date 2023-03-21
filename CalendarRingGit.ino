// Notes:
// Serial printing failes dotStar
// try faster serial?

#include "xPrint.h"
#include "DotStar.h"


// ---------------------- setup -------------------- //
void setup() 
{
  setupSerial();
  // Serial.begin(9600); delay(200);
  Serial.println("setupDotStar: Complete"); // nope
  // Serial.println("dotStarSetup: Complete");
  setupDotStar();
  // Serial.println("setupDotStar: Complete");


  for(int i=0; i<dotStarCount; i++)
  {
    Strip1.setPixelColor(i, 0, 50, 200);
  }
  Strip1.setBrightness(12);
  // Strip1.setPixelColor(0, 100, 0, 100);
  // Strip1.setPixelColor(5, 0, 100, 0);
  setDay(dotStarCount, 100, 100, 0);
  setDay(1, 0, 100, 0);
  setDay(5, 100, 0, 100);
  Strip1.show();  
  // Serial.println("setupDotStar: Complete");   //  yes     
  // printString("setup complete"); // yes something weird with serial
  // printLn();        
}


// ---------------------- loop -------------------- //
void loop() 
{
  while(false)
  {
    stripPowerOn();
    delay(1000);
    stripPowerOff();
    delay(1000);
  }
  Serial.print("millis(): ");
  Serial.println(millis());
  delay(1000);
}
