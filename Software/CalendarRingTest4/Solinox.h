#ifndef Solinox_h
#define Solinox_h

// Solstices and Equinoxes
// Layer 2

#include <Arduino.h>
#include "DotStar.h"
#include "xPrint.h"


const int solinoxMax = 4;
const int solinoxs[solinoxMax] = {79, 172, 266, 355};  // March 20, June 21st, Sept 23, Dec 21 
int solinoxColors[] = {80, 10, 50};

int springColors[] = {0, 50, 0};  // green
int summerColors[] = {50, 10, 0}; // red
int fallColors[] = {50, 25, 0};   // orange brown
int winterColors[] = {50, 50, 50}; // light blue


// ------------------ setSolionxs1() --------------- //
// all same colors
void setSolinoxs1()
{
  for(int solinox = 0; solinox < solinoxMax; solinox++)
  {
    setDay(solinoxs[solinox], solinoxColors[0], solinoxColors[1], solinoxColors[2]);
  }
  if(debugState == 1)
  {
    //Serial.println("solinoxs1: all same colors");
    //Serial.println();
  }
}


// ------------------ setSolionxs2() --------------- //
// individual colors
void setSolinoxs2()
{
  setDay(solinoxs[0], springColors[0], springColors[1], springColors[2]);
  setDay(solinoxs[1], summerColors[0], summerColors[1], summerColors[2]);
  setDay(solinoxs[2], fallColors[0], fallColors[1], fallColors[2]);
  setDay(solinoxs[3], winterColors[0], winterColors[1], winterColors[2]);
  // Serial.println("solionoxs2: green, red, brown, white");
  // Serial.println();
}


// ------------------ printSolionxs() --------------- //
void printSolinoxs()
{
  Serial.print("solinoxs[]: ");
  for(int solinox = 0; solinox < solinoxMax; solinox++)
  {
    Serial.print(solinoxs[solinox]); 
    Serial.print(" ");
    delay(10);
  }
  Serial.println();
}


// ------------------ printSolinoxColors() --------------- //
void printSolinoxColors()
{
  Serial.print("solinoxColors[]: ");
  for(int color = 0; color < 3; color++)
  {
    Serial.print(solinoxColors[color]); 
    Serial.print(" ");
    delay(10);
  }
  Serial.print(" - Purple");
  Serial.println();
}


#endif
