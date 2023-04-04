#ifndef Today_h
#define Today_h

#include "DotStar.h"
#include "RTC.h"

bool dayNew;  // is it a new day
int dayLast;
int todoyColors[] = {0, 100, 0}; //green = today


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
  Strip1.setPixelColor(dayOfYear-1, todoyColors[0], todoyColors[1], todoyColors[2]);
  //Serial.print("dayOfYear: "); Serial.print(dayOfYear); Serial.println(" ");
  //Serial.print("today: set Yellow");
  //Serial.println();
}




#endif
