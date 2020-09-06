#include <USBComposite.h>

bool led_base_state = HIGH;

// MIDI handler class
class myMidi : public USBMIDI {
    virtual void handleNoteOff(unsigned int channel, unsigned int note, unsigned int velocity) {
      digitalWrite(PC13,  led_base_state);
    }
    virtual void handleNoteOn(unsigned int channel, unsigned int note, unsigned int velocity) {
      digitalWrite(PC13, !led_base_state);
    }
};

myMidi midi;
USBCompositeSerial CompositeSerial;

void setup() {
  // Configures BluePill LED pin as output
  pinMode(PC13, OUTPUT);
  // Inits LED
  digitalWrite(PC13, led_base_state);
  // Configure USB behavior for handling MIDI.
  USBComposite.setProductId(0x0030);
  USBComposite.setManufacturerString("6r1d");
  USBComposite.setProductString("Tiny Helper");
  midi.registerComponent();
  CompositeSerial.registerComponent();
  USBComposite.begin();
}

void loop() {
  midi.poll();
}
