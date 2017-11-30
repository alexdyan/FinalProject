#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

class DrumPad
{
  public:
    DrumPad(int _padPin, int _number, int _val);
    
    void process();
    void pressHandler(void (*f)(int, int));
    void releaseHandler(void (*f)(int));
    void (*pressCallback)(int, int);
    void (*releaseCallback)(int);

    int padPin;
    int padState;
    int lastPadState;
    int number;
    int val;
    boolean firstCheck;
    unsigned long lastCheck;
    int checkInt;

  private:
};

#endif
