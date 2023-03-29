#ifndef Solinox_h
#define Solinox_h

#include <Arduino.h>

// Layer 2
const int solinoxMax = 4;
const int solinoxs[solinoxMax] = {79, 172, 266, 355};  // March 20, June 21st, Sept 23, Dec 21 
int solinoxColors[] = {80, 10, 50};

int springColors[] = {0, 50, 0};  // green
int summerColors[] = {50, 10, 0}; // red
int fallColors[] = {50, 25, 0};   // orange brown
int winterColors[] = {50, 50, 50}; // light blue

// ------------------ setSolionxs() --------------- //
// all same colors
void setSolinoxs1()
{
  for(int solinox = 0; solinox < solinoxMax; solinox++)
  {
    // Strip1.setPixelColor(solinoxs[solinox]-1, solinoxColors[0], solinoxColors[1], solinoxColors[2]);
  }
  Serial.println("solinoxs1: all same colors");
  Serial.println();
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
