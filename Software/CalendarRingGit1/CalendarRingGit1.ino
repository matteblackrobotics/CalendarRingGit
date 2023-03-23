// Calendar Ring
// Ring of LEDs representing the year with first day of each month, solinoxes, current day, and seasonal fade

// Behavior:
// Show seasonal color gradient between solinoxs
// Show equinoxs and solstaces
// Show first day of every month
// Read RTC and map day to day LED
// Brightness mapped to proximity and ambient light levels, in range, brighter

// Tasks:
// need to get LEDs to activate, maybe issue with RTC I2C Comms issue

// Issues:
// dotStarCountReal as a high number prevents strip from updating, not an issue in test code

// Future Develpomemt:
// Shows moon phases

// Note:
// Figure out dotStar count issue
// Start to work on LDR brightness input and inRange State


#include "xFunctions.h"      
#include "xPrint.h"          
#include "FirstDays.h"      
#include "Ring.h"           
#include "DotStar.h"        
#include "RTC.h"            
#include "Solinox.h"
#include "Sonar.h"
#include "Today.h"

// Setup systems
// Read RTC
// Calculate first days
// Generate dotStar Array
// Set background (maybe skip)
// Set first days
// Set Solinoxs
// Set current day

bool cycleLEDState = 1; // cycle led indicator
int b = 10; // brightness

void setup()
{
   setupSerial();   // wont display info on serial startup
  
   // ----------- dotStar -------- //
   setupDotStar();
   setFinalDay();
   setFinalLED();

   // ---------- firstDays -------- //
   processFirstDays();
   
  // ------------ solinoxs ----------- //
   printSolinoxs(); 
   printSolinoxColors();
   setSolinoxs2();

  // ------------ today ----------- //
  // ------------ RTC ----------- //
   setupRTC();
   readRTC();
   printRTC();
   setToday();

   // remainingOff();
   
   // setOriginLED();
   // setSeasonLEDs();
   // calculateLEDGaps();
   // setLEDFill();
   // ledOff();
   printString("---- end setup ---- ");
   printLn();
}

void loop()
{
  // ------------------ checkNewDay() -------------- //
  // dayNew = checkNewDay();
  
  // ------------------ firstDay ---------------- //
    if(b<50)
    {
      setDay(dayOfYear, b, b, 0);
      b++;
    }
    else(b=10);
    Serial.println(b);

  // --------------- loop LED --------------- //
    Strip1.setPixelColor(1, 2, 0, 0);
    showStrip1();
    Strip1.setPixelColor(1, 0, 0, 0);
 
  
  // --------------- showStrip ------------ //
  showStrip1();
  
  // --------------- ifNewDay --------------//
 /*
  if(dayNew)
  {
    dayNew = false;
    printFirstDays();
    setFirstDays();

    printSolinoxs();
    setSolinoxs();

    printRTC();
    setToday();
    showStrip1();
  }
*/

// -------------------- checkRange ---------- ----- //
  // checkInRange();
  
  // printRTC();
  //printBool("dayNew", dayNew);
  printString("Loop");
  printLn();
 
  // readRTC();
  // printRTC();
  // showRing();
  // delay(1000);
}
