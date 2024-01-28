#ifndef Today_h
#define Today_h

// Sets today from RTC

#include "DotStar.h"
#include "RTC.h"
#include "Timer.h"

bool dayNew;  // is it a new day
int dayLast;
int todayColors[] = {0, 100, 0}; //green = today

// Colors already set on the strip
uint8_t todayBaseRed;
uint8_t todayBaseGreen;
uint8_t todayBaseBlue;
uint32_t todayBaseRGB;

int pulseCount = 0;
Timer todayPulse(20); // timer when to iterate the pulse


// --------------------- checkNewDay --------------------- //
// when the day of year changes, flag to rebuild ring
bool checkNewDay(){
  if(dayLast =! Day){
    dayNew = true;
    dayLast = Day;
  }
  else{dayNew = false;}
  return dayNew;
}

// -------------------- setToday --------------------- //
void setToday(){
  setDay(dayOfYear, todayColors[0], todayColors[1], todayColors[2]);
  //Serial.print("today: set green");
  //Serial.println();
}


// ---------------------- pulseTodayBrightness ------------------ //
// Reads sin wave and pulses LED
bool printWave = 1; // print the wave in the beginning
int pulseTodayBrightness(int index){
  const int indexMax = 150;
  const float amplitude = .5;                 // amplitude is from middle of sine wave to extreme
  const float period = 2*PI;                  // period of sine wave
  const float x0 = .5*PI;                    // horizontal shift
  const float y0 = .5; 
  const int scalar = 200;                   // max amplitude

  float radian = index * (2*Pi/indexMax);
  int output = scalar * (amplitude * sin((2*PI/period) * (radian - x0)) + y0); 

  if(printWave){ // only run once
    Serial.print("todaySineWave: ");
    int sineWave[indexMax];
    for(int i=0; i <indexMax; i++){
      radian = i * (2*Pi/indexMax);
      sineWave[i] = scalar * (amplitude * sin((2*PI/period) * (radian - x0)) + y0); 
      Serial.print(sineWave[i]);
      Serial.print(" ");
    }
    Serial.println();
    printWave = 0;
  }
  return output;  
}


// Check what the base colors of Today is already set on the ring
void checkTodayBaseColors(){
  todayBaseRGB = Strip1.getPixelColor(dayOfYear-1);
  todayBaseRed = (todayBaseRGB >> 16) & 0xFF; // Returns the Red component of a 32-bit color
  todayBaseGreen = (todayBaseRGB >> 8) & 0xFF; // Returns the Green component of a 32-bit color
  todayBaseBlue = todayBaseRGB & 0xFF;  // Returns the Blue component of a 32-bit color


  if(1){
    Serial.println();
    Serial.print("today base colors: ");
    Serial.print(todayBaseRed); Serial.print(" ");
    Serial.print(todayBaseGreen); Serial.print(" ");
    Serial.print(todayBaseBlue); Serial.println("");
  }
}

#endif