#include <Arduino.h>
#include "Timer.h"


// Constructor
Timer::Timer(unsigned long _interval){
    //this->interval = interval;
    interval = _interval;
    resetTimer();
}

// --------------- setupTimer --------------- //
void Timer::resetTimer(){
    startTime = millis();
}


// --------------- checkTimer --------------- //
// if duration is surpassed,a pass boolean false
bool Timer::checkTimer(){
  if(millis() - startTime >= interval){
    resetTimer();
    timeUp = true;
  }
  else{timeUp = false;}
  return timeUp;
}

// ------ print timer charactaristics ----- //
void Timer::printInterval(){
    Serial.println();
    Serial.print("interval: "); Serial.print(interval);
    Serial.println();
}

// ------- timeRemaining ------- //
int Timer::remainingTimer(){
    remainingTime = startTime + interval - millis();
    return remainingTime;
}

// --------- printRemaining ------- //
void Timer::printRemaining(){
    Serial.println();
    Serial.print("remainingTime: "); 
    Serial.print(remainingTime);
    Serial.println();
}