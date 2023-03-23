#ifndef Sonar_h
#define Sonar_h

const int sonarPin = 0;
const float Vcc = 5000.0; //mV

float range;
float scalingFactor = Vcc/512.0; // mV/inch
float sonarVolt; // mV

int testbrightness = 10;
int inRange = 30; // inches away


// -------------------- setupSonar -------------- //
void setupSonar()
{
  pinMode(sonarPin, INPUT);
}


// -------------------- readSonar -------------- //
void readSonar()
{
  sonarVolt = analogRead(sonarPin) * (5000.0/1023.0);  // [mV]
  range = sonarVolt / scalingFactor; // [inches]
  // int inch2 = input*0.497;
}


// -------------------- printSonar -------------- //
void printSonar()
{
  printFloat("range", range);
}


// -------------------- checkInRange -------------- //
void checkInRange()
{
  if(range <= inRange)
  {
    brightness = bright;
  }
  else{brightness = dim;}
}

// ---------------- ifInRange ----------------------//
// fade in brightness
// pulse dayOfYear LED


#endif
