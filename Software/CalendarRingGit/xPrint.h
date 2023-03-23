// Print to serial monitor

#ifndef xPrint_h
#define xPrint_h
#include <Arduino.h>

// buad rates
const int baud1 = 9600;
const int baud2 = 19200;
const int baud3 = 115200;
int baudRate = baud1;

String fileName = "------------------ CalendarRingGit ------------------";
String author = "Matt Pfeiffer March, 2023 ";


void printInt(String a, int b)
{
  Serial.print(a);
  Serial.print(": ");
  Serial.print(b);
  Serial.print("  ");
}


void printLong(String a, long b)
{
  Serial.print(" ");
  Serial.print(a);
  Serial.print(": ");
  Serial.print(b);
  Serial.print("  ");
}


void printFloat(String a, float b)
{
  Serial.print(a);
  Serial.print(": ");
  Serial.print(b);
  Serial.print("  ");
}


void printBool(String a, bool b)
{
  if(b == true)
  {
    Serial.print(a);
    Serial.print(": true ");
  }

  if(b == false)
  {
    Serial.print(a);
    Serial.print(": false ");
  }
}

void printString(String a)
{
  Serial.print(a);
  Serial.print(" ");
}

void printLn()
{
  Serial.println("");
}


// --------------- setupSerial --------------- //
void setupSerial()
{
  Serial.begin(9600); delay(200);
  Serial.println();
  Serial.println(fileName);
  Serial.println(author);
  Serial.println();
}

#endif
