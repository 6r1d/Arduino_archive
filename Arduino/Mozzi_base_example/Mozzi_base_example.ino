#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/triangle2048_int8.h>

#define CONTROL_RATE 128
Oscil <2048, AUDIO_RATE> aTri(TRIANGLE2048_DATA);

void setup() {
  aTri.setFreq(440);
  startMozzi(CONTROL_RATE);
}

void updateControl() {
}

int updateAudio() {
  return aTri.next();
}

void loop() {
  audioHook();
}
