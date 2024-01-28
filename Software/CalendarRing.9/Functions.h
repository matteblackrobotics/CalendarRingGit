
#include <arduino.h>
#include <math.h>

float Pi = 3.14159265359;

// ------------- Bound ---------------- //
float setBound(float x, int xMin, int xMax)
{
  if(x > xMax) {x = xMax;}
  if(x < xMin) {x = xMin;}
  return x;
}

// --------- linearMap --------- //
float linearMap(float x, float x1, float x2, float y1, float y2)
{
  float m = (y2 - y1)/(x2-x1);
  float b = y1 - m*x1;
  float y = m*x + b;
  return y; 
}

// --------- Normalize --------- //
float Normalize(float x, float xMin, float xMax)
{
  float xNormal = linearMap(x, xMin, xMax, 0.0, 1.0);
  return xNormal; 
}

// ------------- cubicMap -------- //
float cubicMap(float x, float x1, float y1, float xoff, float yoff)
{
  float a = (y1-yoff)/pow(x1-xoff,3);
  float y = a*(pow(x-xoff,3) + yoff);
  return y;
}

// ---------------------- deadband ---------------------- //
float addDeadband(float x, float x_dead)
{
 float y; // output
 float x_min = -1.0;
 float x_max = 1.0;
 float y_min = -1.0;
 float y_max = 1.0;
 
 // float x_dead = .25; // dead in positive direction
 if(x < -x_dead) {y = linearMap(x, x_min, -x_dead, y_min, 0);}         // segment 1
 else if(x > x_dead) {y = linearMap(x, x_dead, x_max, 0, y_max);}      // segment 2
 else{y = 0;}                                                           // segment 0
 return y;
}




// ---------------------- findMin Function ------------------ //
int findMin(int a, int b, int c, int d)
{
  int array1[] = {a, b, c, d};
  int bytes_int = 2;
  int array1_size = sizeof(array1) / bytes_int;
  int min_val = array1[0];

  for(int i=0; i<array1_size; i++)
  {
    if(array1[i] < min_val) {min_val = array1[i];}
  }
  return min_val;
}



float findHypotenuse(float x, float y)
{
  float a = sqrt(pow(x,2) + pow(y,2));
  return a;
}


float degToRad(float deg)
{
  float rad;
  return rad = deg*(Pi/180.0);
}


float radToDeg(float rad)
{
  float deg;
  return deg = rad * (180.0/Pi);
}

// incorrect Passing arrays to functions issue
// https://www.tutorialspoint.com/arduino/arduino_passing_arrays_to_functions.htm
int findArraySize(float array2[])
{
  int total_bytes = sizeof(array2);
  int index_bytes = sizeof(array2[0]);
  int array_size = total_bytes/index_bytes;

  // int array_size = sizeof(array1)/sizeof(array1[0]);
  return array_size;
}