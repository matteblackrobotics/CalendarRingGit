// Simple strand test for Adafruit Dot Star RGB LED strip.
// This is a basic diagnostic tool, NOT a graphics demo...helps confirm
// correct wiring and tests each pixel's ability to display red, green
// and blue and to forward data down the line.  By limiting the number
// and color of LEDs, it's reasonably safe to power a couple meters off
// the Arduino's 5V pin.  DON'T try that with other code!

#include "DotStar.h" 
#include "xPrint.h" 
#include "FirstDays.h"

void setup() 
{
  setupSerial();
  setupDotStar();
  processFirstDays();
  setFinalDay();
  setFinalLED();
  Strip1.show();
}

void loop()
{
  Serial.println(millis());
  Strip1.setPixelColor(1,0,100,0);
  Strip1.show();
  delay(100);
  Strip1.setPixelColor(0,0,0,0);
  Strip1.show();
  delay(200);
}
