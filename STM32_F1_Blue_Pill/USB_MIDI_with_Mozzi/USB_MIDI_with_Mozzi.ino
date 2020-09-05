#include <MozziGuts.h>
#include <Oscil.h>
#include <mozzi_midi.h>
#include <ADSR.h>
#include <tables/triangle2048_int8.h>
#include <STM32ADC.h>

#define CONTROL_RATE 128
Oscil <2048, AUDIO_RATE> aCarrier(TRIANGLE2048_DATA);

#include <USBComposite.h>

class myMidi : public USBMIDI {
  virtual void handleNoteOff(unsigned int channel, unsigned int note, unsigned int velocity) {
  }
  virtual void handleNoteOn(unsigned int channel, unsigned int note, unsigned int velocity) {
    aCarrier.setFreq( mtof((int)note) );
    //CompositeSerial.write(note);
  }
};

myMidi midi;
USBHID HID;
USBCompositeSerial CompositeSerial;

void setup() {
    USBComposite.setProductId(0x0030);
    USBComposite.setSerialString("01234567890123456789");
    USBComposite.setManufacturerString("6r1d");
    USBComposite.setProductString("Tiny Helper");
    
    midi.registerComponent();
    CompositeSerial.registerComponent();
    USBComposite.begin();
    
    aCarrier.setFreq(440);
    startMozzi(CONTROL_RATE);
}

void updateControl(){
}

int updateAudio() {
  return aCarrier.next();
}

void loop() {
  midi.poll();
  audioHook();
}
