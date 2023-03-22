#include "DotStar.h"
#include "xPrint.h" 
#include "FirstDays.h"

void setup() 
{
  setupSerial();
  setupDotStar();
  // processFirstDays();
  calculateFirstDays();
  printFirstDays();
  
  setFinalDay();
  setFinalLED();
  Strip1.show();
}


void loop() 
{
  Serial.println(millis());
  Strip1.setPixelColor(1,0,0,100);
  Strip1.show();
  delay(100);
  Strip1.setPixelColor(1,0,0,0);
  Strip1.show();
  delay(200);
}
