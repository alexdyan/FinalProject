#include "DrumPad.h"

int pad1Pin = A17;  //set the pins you're using
int pad2Pin = A16;
int pad3Pin = A15;
int pad4Pin = A14;

DrumPad p1 (pad1Pin, 60, 1); //kick
DrumPad p2 (pad2Pin, 62, 2); //hi hat
DrumPad p3 (pad3Pin, 64, 3); //crash
DrumPad p4 (pad4Pin, 65, 4); //snare

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

void onPress(int number, int val) {   //when there's a hit, do this...
  Serial.write(val);                  //send the val (1-4) to processing
  usbMIDI.sendNoteOn(number, 127, 1); //send the MIDI note number to the DAW
}

void onRelease(int number) {          //when the hit is over, do this...
  Serial.write(0);                    //send 0 to processing to stop drawing
  usbMIDI.sendNoteOff(number, 0, 1);  //change MIDI note velocity to 0
}

