#include <USBComposite.h>

class myMidi : public USBMIDI {
 virtual void handleNoteOff(unsigned int channel, unsigned int note, unsigned int velocity) {
  digitalWrite(PC13, LOW);
 }
 virtual void handleNoteOn(unsigned int channel, unsigned int note, unsigned int velocity) {
   digitalWrite(PC13, HIGH);
 } 
};

myMidi midi;
USBCompositeSerial CompositeSerial;

void setup() {
    pinMode(PC13, OUTPUT);
    USBComposite.setProductId(0x0030);
    midi.registerComponent();
    CompositeSerial.registerComponent();
    USBComposite.begin();
}

void loop() {
  midi.poll();
}
