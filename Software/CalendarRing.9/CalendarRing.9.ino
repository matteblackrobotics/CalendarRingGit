// CalendarRing
// 365 LED ring on wall as visual indicator of progression through the year
// Shows 1st days of every month, solstices and equinoxes, read RTC and show current day
// Range finder senses if you are near and brightens ring

// Modes:
// Awake, range trigger, all leds lit, curent day pulses
// Asleep, range trigger, all leds off, current day barely pulses
// Drop brightness of entire ring

// Questions:
// How does dotStar and serial.print interact?
// How do .h files interact?

// Tasks:
// Target LEDs
// function that blinks each month its month number
// I need to set brightness for Today LED separate from the rest of the strip
// Sonar units are wrong test
// understand circular buffer and modulo % function
// function that combines leds or overrides leds
// understand board configurations

#include "Utilities.h"
#include "Functions.h"
#include "DotStar.h"
#include "NeoPixel.h"
#include "FirstDays.h"
#include "Solinox.h"
#include "RTC.h"
#include "Today.h"
#include "Sonar.h"
#include "Timer.h"
#include "State.h"

void setup() 
{
  // -------- setups -------- //
  setupUtilities();
  setupDotStar();
  setupNeo();
  setupSonar();
  processFirstDays();
  setFinalDay();
  setSolinoxs1();
  printSolinoxColors();

  // ---------- RTC ----------//
  setupRTC(); 
  readRTC();
  printRTC();

  // --------- Today --------- //
  setToday();
  setDay(dayOfYear, 20, 10, 30); // check colors test
  checkTodayBaseColors();

  //---------- showStrips ----------//
  showStrips();
  Serial.println("hello test");
  delay(4000);

  if(debugState == 1) 
  {
    Serial.println();
    Serial.println("debugState");
  } 
}


void loop() 
{
  if(systemStateTimer.checkTimer()){
    systemState = checkSystemState();
    if(checkSystemStateChange()){
      setSystemState();
    } 
  }

  neoPixelAwake();
  //readRTC();
  //printRTC();

  //---------------------------- range to brightness --------------------------//
  // if in range of sonar, brighten ring
  if(1)
  {
    if(debugState)
    {
      brightness = 100;
      Strip1.setBrightness(brightness);
    }
    else
    {
      if(checkRangeTimer.checkTimer()){
        range = readSonar();
        printSonar();
        rangeMax = setRangeMax(range, rangeMax);

        brightness = map(range, rangeMin, rangeActive, brightnessMax, brightnessMin);
        brightness = setBound(brightness, 0, 255);
        Strip1.setBrightness(brightness);
        Serial.print("  brightness: "); Serial.print(brightness);
      }
    }

    setFirstDays();
    setSolinoxs1();
    setToday();
    showStrips();
  }

  //----------------------------- pulse Today LED ---------------------------//
  if(1)
  {
    //Strip1.setBrightness(100); // For today LED
    // if timer triggered, advance sine wave
    if(todayPulse.checkTimer())
    {
      float output = pulseTodayBrightness(pulseCount++);
      // add the pulse output ontop of what has already been set
      setDay(dayOfYear, todayBaseRed, todayBaseGreen + output, todayBaseBlue);
      showStrips();
      Serial.print(output);
      Serial.println();
    }
  }
}