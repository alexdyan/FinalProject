#include "Arduino.h"
#include "BetterButton.h"

BetterButton::BetterButton(int _padPin, int _number) {
  padPin = _padPin;
  number = _number;
  padState;
  lastPadState;;
  lastCheck = 0;
  checkInt = 100;

  pinMode(padPin, INPUT);
}

void BetterButton::process() {
  if (millis() < lastCheck + checkInt)  //every 1/10 second
    return;

  lastPadState = padState;
  padState = analogRead(padPin);
  int thresh = 10;
  if (lastPadState <= thresh && padState > thresh) {  //if you're hitting the sensor
    pressCallback(number);
    lastCheck = millis();
  }
  if (lastPadState > thresh && padState <= thresh)  //if you're not hitting it
    releaseCallback(number);
}

void BetterButton::pressHandler(void (*f)(int)) {    //sensor triggered
  pressCallback = *f;
}

void BetterButton::releaseHandler(void (*f)(int)) {  //sensor not triggered
  releaseCallback = *f;
}

