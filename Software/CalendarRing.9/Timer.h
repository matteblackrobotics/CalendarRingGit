#ifndef Timer_h
#define Timer_h

#include <Arduino.h>

class Timer{
  private:
  bool timeUp;
  long remainingTime;
  unsigned long interval;

  public: // can be called outside the function
  unsigned long startTime;

  Timer(unsigned long interval);

  void resetTimer();
  bool checkTimer();  // check if timer is finished
  int remainingTimer();
  void printInterval();
  void printRemaining();
};

#endif