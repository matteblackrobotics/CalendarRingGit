#ifndef State_h
#define State_h
// Set state of device:
// Read range finder
// Communication loss

// Inputs:
#include "Sonar.h"
#include "DotStar.h"
#include "NeoPixel.h"
#include "Timer.h"

// Variables:
int systemState;
int systemStateLast;
bool systemStateChange = 0;
bool connected = 1; // eventually will go in comms.h
Timer systemStateTimer(200);
bool debugState = 0;

// @brief: Check the state of the system based off range finder and connectivity
// @param: range, from Sonar.h, from comms
// @return: systemState 0:2 and systemStateLast
int checkSystemState(){
    systemStateLast = systemState;
    if(debugState){
        brightness = brightnessMax;
        neoPixelDebug();
    }
    if(!connected){
        systemState = 0;    // DeepSleep
    }
    else{
        if(range >= rangeActive){
            systemState = 1;    // Sleep
        }
        else{
            systemState = 2;    // Awake
        }
    }
    return systemState;
}


// @brief: Check to see if the state of the system has changed
// This is to trigger setSystemState()
// @param: systemState and systemStateLast
// @return: systemStateChange boolean
bool checkSystemStateChange(){
    if(systemState != systemStateLast){
        systemStateChange = 1;
    }
    else{
        systemStateChange = 0;
    }
    return systemStateChange;
}


// @brief: setSystem State targets based off state checker
// @param: systemState
// @return: state fuctions of specific hardware
void setSystemState(){
    switch (systemState){
        case 0: // Deep Sleep
            Serial.print("SystemState: DeepSleep - "); Serial.println(systemState);
            // dotStarDeepSleep();
            neoPixelDeepSleep();
            brightnessTarget = brightnessMin;
        break;

        case 1: // Sleep
            // dotStarSleep();
            neoPixelSleep();
            Serial.print("SystemState: Sleep - "); Serial.println(systemState);
            brightnessTarget = brightnessMin;
        break;

        case 2: // Awake
            // dotStarAwake();
            neoPixelAwake();
            Serial.print("SystemState: Awake - "); Serial.println(systemState);
            brightnessTarget = brightnessMax;
        break;  
    }
}
#endif