// Test dot star with power pin

#include <Adafruit_DotStar.h>
#include <SPI.h>         
#define dotStarCount 432
#define dotStarDataPin 4
#define dotStarClockPin 5

const int stripPowerPin = 2;

Adafruit_DotStar strip1(dotStarCount, dotStarDataPin, dotStarClockPin, DOTSTAR_BGR);


// ---------------------- setup -------------------- //
void setup() 
{
  Serial.begin(9600);
  strip1.begin();   
  pinMode(stripPowerPin, OUTPUT);   
  stripPowerOff();
  stripPowerOn();
  for(int i=0; i<dotStarCount; i++)
  {
    strip1.setPixelColor(i, 20, 200, 20);
  }
  strip1.setBrightness(12);
  strip1.setPixelColor(0, 0, 100, 100);
  strip1.setPixelColor(5, 0, 100, 100);
  setFinalLED();
  strip1.show();                     
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
  strip1.setPixelColor(dotStarCount-1, 200, 0, 0);
  Serial.print("finalLED: set Blue");
  Serial.println();
}


// ---------------------- stripPowerOn -------------------- //
void stripPowerOn()
{
  digitalWrite(stripPowerPin, HIGH);
  Serial.print("stripPowerState: On");
  Serial.println();
  delay(10);
}

// ---------------------- stripPowerOff -------------------- //
void stripPowerOff()
{
  digitalWrite(stripPowerPin, LOW);
  Serial.print("stripPowerState: Off");
  Serial.println();
  delay(10);
}
