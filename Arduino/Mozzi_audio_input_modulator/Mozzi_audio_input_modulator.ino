#include <MozziGuts.h>
#include <Oscil.h>

#include <tables/sin2048_int8.h>
Oscil <2048, AUDIO_RATE> aSin(SIN2048_DATA);
  
void setup(){
  startMozzi();
}

void updateControl(){
}

int updateAudio(){
  int temp = getAudioInput();
  aSin.setFreq(temp);
  return aSin.next();
}

void loop(){
  audioHook();
}
