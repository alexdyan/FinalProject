#include "Arduino.h"
#include "DrumPad.h"

DrumPad::DrumPad(int _padPin, int _number, int _val) {
  padPin = _padPin;
  number = _number;
  val = _val;
  padState;
  lastPadState;
  lastCheck = 0;
  checkInt = 100;

  pinMode(padPin, INPUT);
}

void DrumPad::process() {
  if (millis() < lastCheck + checkInt)  //every 1/10 second
    return;

  lastPadState = padState;
  padState = analogRead(padPin);
  int thresh = 10;
  if (lastPadState <= thresh && padState > thresh) {  //if you're hitting the sensor
    pressCallback(number, val);
    lastCheck = millis();
  }
  if (lastPadState > thresh && padState <= thresh)  //if you're not hitting it
    releaseCallback(number);
}

void DrumPad::pressHandler(void (*f)(int, int)) {    //sensor triggered
  pressCallback = *f;
}

void DrumPad::releaseHandler(void (*f)(int)) {  //sensor not triggered
  releaseCallback = *f;
}

