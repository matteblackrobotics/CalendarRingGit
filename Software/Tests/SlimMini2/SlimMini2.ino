#include "FirstDays.h"
#include "Solinox.h"
#include "DotStar.h"
#include "xPrint.h" 


void setup() 
{
  setupSerial();
  
  setupDotStar();
  // setSolinoxs1();
  processFirstDays();
  
  
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
