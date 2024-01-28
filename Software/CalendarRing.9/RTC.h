#ifndef RTC_h
#define RTC_h

// Real time clock sets day of the year
// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
// 5v to 5v
// GND to GND
// SDA to A4-nano/esp8266 GPIO4, D2 green
// SCL to A5-nano/esp8266 GPIO5, D1 yellow

// Xiao
// SDA to 6_SDA
// SCL to 7_SCL
const int SDA_Pin = 6;
const int SCL_Pin = 7;

#include "RTClib.h"
#include "DotStar.h"
#include "FirstDays.h"
#include <Wire.h>

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
void setRTC(int year, int month, int day, int hour, int minute, int second)
{
  rtc.adjust(DateTime(year, month, day, hour, minute, second)); 
  Serial.println("");
  Serial.println("RTC Set:");
  Serial.print("year: "); Serial.println(year);
  Serial.print("month: "); Serial.println(month);
  Serial.print("day: "); Serial.println(day);
  Serial.print("hour: "); Serial.println(hour);
  Serial.print("minute: "); Serial.println(minute);
  Serial.print("second: "); Serial.println(second);
  Serial.println("");
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
  dayOfYear = firstDays[Month-1] + Day-1;
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
  Serial.println(Second);
  Serial.print("dayOfYear: "); Serial.print(dayOfYear);
  Serial.println();
  Serial.println();
}


// --------------------- RTC --------------------- //
void setupRTC()
{
  pinMode(SDA_Pin, INPUT);
  pinMode(SCL_Pin, OUTPUT);
  rtc.begin();
  delay(500);

  // set RTC, comment out
  // setRTC(2023, 9, 7, 7, 44, 0); // year, month, day, hour-24, min, second
}


// --------------------- processRTC ------------------- //
// called by main, unused
void processRTC()
{
  setupRTC();
  readRTC();
  printRTC();
}

#endif