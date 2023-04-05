#ifndef Sonar_h
#define Sonar_h

#include <Arduino.h>

const int sonarPin = 1;
const float Vcc = 5000.0; //mV

float range;
float scalingFactor = Vcc/512.0; // mV/inch
float sonarVolt; // mV

int testbrightness = 10;
int inRange = 30; // inches away
float autoRangeMin = 20;
float autorangeMax = 20;
int brightnessMax = 200;
int brightness = 10;

int dim = 10;
int bright = 100;


// -------------------- setupSonar -------------- //
void setupSonar()
{
  pinMode(sonarPin, INPUT);
}


// -------------------- readSonar -------------- //
float readSonar()
{
  sonarVolt = analogRead(sonarPin) * (5000.0/1023.0);  // [mV]
  range = sonarVolt / scalingFactor; // [inches]
  // int inch2 = input*0.497;
  return range;
}


// -------------------- printSonar -------------- //
void printSonar()
{
  //printFloat("range", range);
  //Serial.print("range: "); Serial.println(range);
}


// -------------------- checkInRange -------------- //
void checkInRange()
{
  if(range <= inRange)
  {
    brightness = bright;
  }
  else{brightness = dim;}
}

// ---------------- ifInRange ----------------------//
// fade in brightness
// pulse dayOfYear LED

#endif
