#ifndef RTC_h
#define RTC_h

// Real time clock sets day of the year
// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
// 5v to 5v
// GND to GND
// SDA to A4-nano/esp8266 GPIO4, D2 green
// SCL to A5-nano/esp8266 GPIO5, D1 yellow

#include "RTClib.h"
#include "DotStar.h"
#include "FirstDays.h"

RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int Year;
int Month;
int Day;
String DayOfWeek;
int Hour;
int Minute;
int Second;
int dayOfYear;


// --------------------- Daylight Savings ---------------- //
int daylightSavings = 0;
int startDaylightSavings = 71; // March 12th, Spring forward
int endDaylightSavings = 309; // November 5th, Fall back
bool checkDaylightSavings()
{
  if(dayOfYear >= startDaylightSavings && dayOfYear <= endDaylightSavings)
  {
    daylightSavings = 1; // summer, start earlier
  }
  else
  {
    daylightSavings = 0; // winter
  } 
  return daylightSavings;
}


// --------------------- setRTC ------------------- //
// adjust date and time, upload, comment out, upload again:
void setRTC(int year, int month, int day, int hour, int min, int second)
{
  rtc.adjust(DateTime(year, month, day, hour, min, second)); 
  Serial.println("RTC Set");
}


// --------------------- readRTC ------------------- //
void readRTC()
{
  DateTime now = rtc.now();
  Year = now.year();
  Month = now.month();
  Day = now.day();
  DayOfWeek = daysOfTheWeek[now.dayOfTheWeek()];
  daylightSavings = checkDaylightSavings();
  Hour = now.hour() + daylightSavings;
  Minute = now.minute();
  Second = now.second(); 
}


// --------------------- printRTC ------------------- //
void printRTC()
{
  Serial.print("daylightSavings: "); Serial.println(daylightSavings);
  Serial.print("RTC: ");
  Serial.print(Year); Serial.print('/');
  Serial.print(Month); Serial.print('/');
  Serial.print(Day); Serial.print(" (");
  Serial.print(DayOfWeek); Serial.print(") ");
  Serial.print(Hour); Serial.print(":");
  Serial.print(Minute); Serial.print(":");
  Serial.print(Second);
  Serial.println();
  Serial.println();
}


// --------------------- RTC --------------------- //
void setupRTC()
{
  rtc.begin();
  delay(500);
  // setRTC(2023, 4, 4, 7, 33, 0); year, month, day, hour-24, min, second
}


// --------------------- processRTC ------------------- //
// called by main
void processRTC()
{
  setupRTC();
  readRTC();
  printRTC();
}

#endif
