#include "BetterButton.h"

int pad1Pin = A17;
int pad2Pin = A16;
int pad3Pin = A15;
int pad4Pin = A14;

BetterButton p1 (pad1Pin, 0);
BetterButton p2 (pad2Pin, 0);
BetterButton p3 (pad3Pin, 0);
BetterButton p4 (pad4Pin, 0);

void setup() {
  Serial.begin(9600);
  p1.pressHandler(onPress);
  p1.releaseHandler(onRelease);
  p2.pressHandler(onPress);
  p2.releaseHandler(onRelease);
  p3.pressHandler(onPress);
  p3.releaseHandler(onRelease);
  p4.pressHandler(onPress);
  p4.releaseHandler(onRelease);
}

void loop() {
  p1.process();
  p2.process();
  p3.process();
  p4.process();
}

void onPress(int number) {
  Serial.write(0);
}

void onRelease(int number) {
  Serial.write(1);
}

