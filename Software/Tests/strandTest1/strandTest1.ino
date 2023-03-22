
#include <Adafruit_DotStar.h>
#include <SPI.h>


const int dotStarCount = 432;
#define dotStarDataPin    11
#define dotStarClockPin   13
Adafruit_DotStar Strip1(dotStarCount, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR);


void setup() 
{
  Serial.begin(9600);
  Strip1.begin();
  Strip1.clear();
  Strip1.show();
  Strip1.setPixelColor(0,0,100,0);
  Strip1.setPixelColor(dotStarCount-1,100,0,0);
  Strip1.show();
}


void loop() 
{
  Serial.println(millis());
  Strip1.setPixelColor(1,0,100,100);
  Strip1.show();
  delay(100);
  Strip1.setPixelColor(1,0,0,0);
  Strip1.show();
  delay(200);
}
