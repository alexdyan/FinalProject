#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

class BetterButton
{
  public:
    BetterButton(int _padPin, int _number);
    
    void process();
    void pressHandler(void (*f)(int));
    void releaseHandler(void (*f)(int));
    void (*pressCallback)(int);
    void (*releaseCallback)(int);

    int padPin;
    int padState;
    int lastPadState;
    int number;
    boolean firstCheck;
    unsigned long lastCheck;
    int checkInt;

  private:
};

#endif
