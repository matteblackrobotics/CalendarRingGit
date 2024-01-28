#ifndef NEOPIXEL_h
#define NEOPIXEL_h

// ------------------ neoPixel ------------------- //
#include <Adafruit_NeoPixel.h>
#define neoPin 21 // GPI0  = Slik D3
#define neoCount 1
Adafruit_NeoPixel neo(neoCount, neoPin, NEO_GRB + NEO_KHZ800);

void neoPixelDeepSleep(){
  int shift = -80;
  uint8_t red = 198+shift;
  uint8_t green = 180+shift;
  uint8_t blue = 207+shift;
  neo.setPixelColor(0, red, green, blue);
  neo.show();
}

void neoPixelSleep(){
  int shift = -80;
  uint8_t red = 181+shift;
  uint8_t green = 203+shift;
  uint8_t blue = 227+shift;
  neo.setPixelColor(0, red, green, blue);
  neo.show();
}

void neoPixelAwake(){
  int shift = -80;
  uint8_t red = 126+shift;
  uint8_t green = 237+shift;
  uint8_t blue = 111+shift;
  neo.setPixelColor(0, red, green, blue);
  neo.show();
}

void neoPixelDebug(){
  int shift = -80;
  uint8_t red = 217+shift;
  uint8_t green = 213+shift;
  uint8_t blue = 95+shift;
  neo.setPixelColor(0, red, green, blue);
  neo.show();
}

// -------------------- setupNeoPixel ------------------- //
void setupNeo(){ 
  neo.begin(); 
  neo.clear();
  neoPixelSleep();
}

#endif
