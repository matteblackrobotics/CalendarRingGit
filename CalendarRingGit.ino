// Test dot star with power pin

#include "xPrint.h"
#include "DotStar.h"
  


// ---------------------- setup -------------------- //
void setup() 
{
  Serial.begin(9600); 
  pinMode(stripPowerPin, OUTPUT); 
  stripPowerOff();
  stripPowerOn();
  Strip1.begin();
 

  for(int i=0; i<dotStarCount; i++)
  {
    Strip1.setPixelColor(i, 20, 50, 200);
  }
  Strip1.setBrightness(12);
  Strip1.setPixelColor(0, 0, 0, 100);
  Strip1.setPixelColor(5, 0, 100, 0);
  setFinalLED();
  Strip1.show();                     
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
}

// -------------------- setFinalLED ------------------- //
void setFinalLED()
{
  Strip1.setPixelColor(dotStarCount-1, 200, 2000, 0);
  Serial.print("finalLED: set Blue");
  Serial.println();
}

