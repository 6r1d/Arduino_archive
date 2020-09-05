#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>
//#include <STM32ADC.h> // Uncomment if you are using STM32 BluePill board

#define CONTROL_RATE 64
Oscil <2048, AUDIO_RATE> aSin(SIN2048_DATA);
int temp;

void setup() {
  aSin.setFreq(0);
  startMozzi(CONTROL_RATE);
}

void updateControl() {}

int updateAudio() {
  // TODO: check if I need value clamping
  temp = 440 + mozziAnalogRead(A0) + mozziAnalogRead(A1);
  aSin.setFreq(temp);
  return aSin.next();
}

void loop(){
  audioHook();
}
