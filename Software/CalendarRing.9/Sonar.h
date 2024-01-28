#ifndef Sonar_h
#define Sonar_h

#include <Arduino.h>
#include "DotStar.h"
#include "Timer.h"

const int sonarPin = 2;  //gpio pin
const float Vcc = 5000.0; //mV
const float scalingFactor = Vcc/512.0; // mV/inch
float sonarVolt; // mV

int range;
int rangeActive = 200; // inches away

float rangeMin = 50;
float rangeMax = 20; // initial setting

Timer checkRangeTimer(500);

// -------------------- setupSonar -------------- //
void setupSonar(){
  pinMode(sonarPin, INPUT);
}


/// ------------------ smoothAnalogRead Function --------------- //
// Analog reads a pin and creates a matrix and averages data across it [mV]
int smoothAnalogRead(int pin)
{
  int const matrix_size = 20;
  int input = 0;
  double matrix_total = 0;
  int avg = 0;
  for (int i=0; i<matrix_size; i++){ // has run matrix_size times, 0-9
   input = analogRead(pin);
   matrix_total = matrix_total + input; // Generate running total
   // Serial.print(volt); Serial.print(" ");
  }
   avg = matrix_total / matrix_size;
   // Serial.print(avg); Serial.print(" ");
   return avg;
}


// -------------------- readSonar -------------- //
float readSonar(){
  sonarVolt = smoothAnalogRead(sonarPin) * (5000.0/1023.0);
  // sonarVolt = analogRead(sonarPin) * (5000.0/1023.0);  // [mV]
  range = sonarVolt / scalingFactor; // [inches]
  // int inch2 = input*0.497;
  return range;
}


// -------------------- printSonar -------------- //
void printSonar(){
  Serial.print("  range: "); Serial.print(range);
}


// --------------------- setRangeMax ----------- //
float setRangeMax(float range, float rangeMax){
  if(range > rangeMax){
    rangeMax = range;
  }
  return rangeMax;
}


// --------------------- setRangeMin ----------- //
float setRangeMin(float range, float rangeMin){
  if(range < rangeMin){
    rangeMin = range;
  }
  return rangeMin;
}


// -------------------- checkrangeActive -------------- //
void checkrangeActive(){
  if(range <= rangeActive){
    brightness = brightnessMax;
  }
  else{brightness = brightnessDim;}
}

// ---------------- ifrangeActive ----------------------//
// fade in brightness
// pulse dayOfYear LED

#endif