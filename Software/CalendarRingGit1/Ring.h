// Matrix that holds all LED RGB values

// set a grid of primary leds with RGB
// fade between primary leds evenly

#ifndef Ring_h
#define Ring_h

// rows = days
// columns = colors
const int daysMax = 100;  // days of year
const int colorsMax = 3; // RGB
const int ringRows = 4; // DOY and RGB
int ring[daysMax][ringRows]; // ring array
int dayShift = 1;


// add day of year column 1-356
void setupRing()  // initalize zeros array
{
  for(int Day = 0; Day < daysMax; Day++)
  {
    ring[Day][0] = Day+1; // set first column to print out the day of the year
    for(int i = 1; i < ringRows; i++)    
    {
      ring[Day][i] = 0;
    }
  }
}


// ------------------------- shift dotStar Array -------------------------- //
// shifts ring around strip
// pulls out temp array of dot stars
// shifts remaining dotStars
// sets original array to temp array

void shiftRing()
{
  int tempRing[dayShift][colorsMax];  // temp array is the size of number of days to shift

  // starting with the first of the dotStars to shift
  for(int Day = 0; Day < dayShift; Day++)
  {
    for(int color = 0; color < colorsMax; color++)
    {
      tempRing[Day][color] = ring[daysMax - dayShift][color];
    } 
  }

  // transfer remaining dotStars from the shift onward
  for(int Day = dayShift; Day < daysMax; Day++)
  {
    for(int color = 0; color < colorsMax; color++)
    {
      tempRing[Day][color] = ring[Day - dayShift][color];
    }
  }

  // set original array to temp array
   for(int Day = 0; Day < daysMax; Day++)
  {
    for(int color = 0; color < colorsMax; color++)
    {
      ring[Day][color] = tempRing[Day][color];
    }
  }
}


void setOrigin()
{
  int origin = 0;
  int R = 120;
  int G = 32;
  int B = 94;
  int originColors[] = {R, G, B};

  for (int color = 0; color < colorsMax; color++)
  {
    ring[origin][1+color] = originColors[color];
  }
}


void printRing()
{
  Serial.println(" ");
  Serial.println("ring:");
  Serial.println("{");

  for(int Day = 0; Day < daysMax; Day++)
  {
    for(int i = 0; i < ringRows; i++)
    {
      Serial.print(ring[Day][i]); Serial.print(" ");  // print row with spaces
    }
    Serial.println(" "); // return after each row
  }
  Serial.println("}");
}



 
#endif
