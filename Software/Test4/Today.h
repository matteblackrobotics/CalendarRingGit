#ifndef Today_h
#define Today_h

// Sets today from RTC

#include "DotStar.h"
#include "RTC.h"

bool dayNew;  // is it a new day
int dayLast;
int todayColors[] = {0, 100, 0}; //green = today


// --------------------- checkNewDay --------------------- //
// when the the day of year changes, flag
bool checkNewDay()
{
  if(dayLast =! Day) 
  {
    dayNew = true;
    dayLast = Day;
  }
  else{dayNew = false;}
}


// --------------------- setToday --------------------- //
void setToday()
{
  dayOfYear = firstDays[Month-1] + Day-1;
  setDay(dayOfYear, todayColors[0], todayColors[1], todayColors[2]);
  Serial.print("dayOfYear: "); Serial.print(dayOfYear); Serial.println(" ");
  Serial.print("today: set green");
  Serial.println();
}

#endif
