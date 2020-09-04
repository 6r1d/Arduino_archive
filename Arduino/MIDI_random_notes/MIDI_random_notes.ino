#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

// A base key to randomize values around
int fluctuation_base = 63;
// MIDI key pitch and pressure velocity
int pitch, velocity;
// MIDI channel remains the same in this demo
const int channel = 1;

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop()
{
  // Constrain is useless when fluctuation base is 63
  // and fluctuation is between 0 and 14,
  // but may help if you'll play with the example
  pitch = constrain(
            fluctuation_base + random(0, 14),
            0,
            127
          );
  velocity = random(60, 127);
  MIDI.sendNoteOn(pitch, velocity, channel);
  delay(random(5, 10) * 50);
  MIDI.sendNoteOff(pitch, velocity, channel);
  delay(random(1, 10) * 50);
}
