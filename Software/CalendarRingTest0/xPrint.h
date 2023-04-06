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
