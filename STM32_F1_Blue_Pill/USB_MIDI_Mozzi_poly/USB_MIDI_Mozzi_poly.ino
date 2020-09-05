/*
 * TODO there's something clearly broken in ADSR code
 * and I will have to figure out a way to fix that
 */

#include <MozziGuts.h>
#include <mozzi_midi.h>
#include <Oscil.h>
#include <ADSR.h>
#include <tables/saw512_int8.h>
#include <STM32ADC.h>

#include <USBComposite.h>

#define CONTROL_RATE 256

//set maximum number of polyphony
#define MAX_POLY 6
#define OSC_NUM_CELLS 512
#define WAVE_DATA SAW512_DATA

//Envelope controllers
#define ATTACK 22
#define DECAY 3000
#define SUSTAIN 8000
#define RELEASE 300
#define ATTACK_LEVEL 64
#define DECAY_LEVEL 0

//Voices
struct Voice {
  Oscil<OSC_NUM_CELLS, AUDIO_RATE> osc;  // audio oscillator
  ADSR<CONTROL_RATE, AUDIO_RATE> env;  // envelope generator
  byte note = 0;
  byte velocity = 0;
};

Voice voices[MAX_POLY];

//optional midi monitor
#define LED PC13

class myMidi : public USBMIDI {
    virtual void handleNoteOn(unsigned int channel, unsigned int note, unsigned int velocity) {
      CompositeSerial.write(note);
      if (velocity > 0) {
        int activeVoice = 0;
        int voiceToSteal = 0;
        int lowestVelocity = 128;
        for (unsigned int i = 0 ; i < MAX_POLY; i++) {
          if (!voices[i].env.playing()) {
            voices[i].env.noteOff();
            voices[i].osc.setFreq(mtof(float(note)));
            voices[i].env.noteOn();
            voices[i].note = note;
            voices[i].velocity = velocity;
            break;
          } else {
            activeVoice++;
            if (lowestVelocity >= voices[i].velocity) {
              lowestVelocity = voices[i].velocity;
              voiceToSteal = i;
            }
          }
        }
        if (activeVoice == MAX_POLY) {
          voices[voiceToSteal].env.noteOff();
          voices[voiceToSteal].osc.setFreq(mtof(float(note)));
          voices[voiceToSteal].env.noteOn();
          voices[voiceToSteal].note = note;
          voices[voiceToSteal].velocity = velocity;
        }
        digitalWrite(LED, HIGH);
      }
    }
    virtual void handleNoteOff(unsigned int channel, unsigned int note, unsigned int velocity) {
      byte handsOffChecker = 0;
      for (unsigned int i = 0; i < MAX_POLY; i++) {
        if (note == voices[i].note) {
          voices[i].env.noteOff();
          voices[i].note = 0;
          voices[i].velocity = 0;
        }
        handsOffChecker += voices[i].note;
      }
      if (handsOffChecker == 0) {
        digitalWrite(LED, LOW);
      }
    }
};

myMidi midi;
USBCompositeSerial CompositeSerial;

void setup() {
  pinMode(LED, OUTPUT);
  for (unsigned int i = 0; i < MAX_POLY; i++) {
    voices[i].env.setADLevels(ATTACK_LEVEL, DECAY_LEVEL);
    voices[i].env.setTimes(ATTACK, DECAY, SUSTAIN, RELEASE);
    voices[i].osc.setTable(WAVE_DATA);
  }
  
  USBComposite.setProductId(0x0030);
  USBComposite.setSerialString("01234567890123456789");
  USBComposite.setManufacturerString("6r1d");
  USBComposite.setProductString("Tiny Helper");
    
  midi.registerComponent();
  CompositeSerial.registerComponent();
  USBComposite.begin();

  startMozzi(CONTROL_RATE);
}

void updateControl() {
  midi.poll();
  for (unsigned int i = 0; i < MAX_POLY; i++) {
    voices[i].env.update();
  }
}

int updateAudio() {
  int currentSample = 0;
  for (unsigned int i = 0; i < MAX_POLY; i++) {
    currentSample += voices[i].env.next() * voices[i].osc.next();
  }
  return (int) (currentSample) >> 8;
}


void loop() {
  audioHook();
}
