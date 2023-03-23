#ifndef FirstDays_h
#define FirstDays_h

#include <Arduino.h>
#include "DotStar.h"

// Layer 1

// ------------------------ first days -------------------- //
// day of year of first days of each month
// const int firstDay[12] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
const int monthLengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int firstDays[12];  // dayOfYear for first day of every month
int firstDayColors[3] = {0, 40, 40}; // RGB

// ---------------------- calculateFirstDays() ---------------------- //
void calculateFirstDays()
{
  firstDays[0] = 1;  // set Jan 1st
  for(int i=1; i<12; i++)
  {
    // next month first day is monthLengths[0], 31 days from Jan 1st
    firstDays[i] = firstDays[i-1] + monthLengths[i-1];
  }
}

// ---------------------- printFirstDays() ---------------------- //
void printFirstDays()
{
  Serial.print("firstDays[]: ");
  for(int i=0; i<12; i++)
  {
    Serial.print(firstDays[i]); 
    Serial.print(" ");
    delay(10);
  }
  Serial.println();
}


// ---------------------- printFirstDayColors() ---------------------- //
void printFirstDayColors()
{
  Serial.print("firstDayColors[]: ");
  for(int color=0; color<3; color++)
  {
    Serial.print(firstDayColors[color]); 
    Serial.print(" ");
    delay(10);
  }
  Serial.println(" - Light Blue");
}


// ------------------ setFirstDays() --------------- //
void setFirstDays()
{ 
  for(int Month = 0; Month < 12; Month++)
  {
    // from the first days array 1 to 12, set RGB
    // minus 1 for indexing
    Strip1.setPixelColor(firstDays[Month]-1, firstDayColors[0], firstDayColors[1], firstDayColors[2]);
  }  
  Serial.println("firstDays: set");
}


// ---------------------- processFirstDays() ---------------------- //
void processFirstDays()
{
  calculateFirstDays();
  printFirstDays();
  printFirstDayColors();
  setFirstDays();
  Serial.println();
}

#endif
