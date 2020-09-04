#include <MIDI.h>
#define LED_PIN 13

MIDI_CREATE_DEFAULT_INSTANCE();

void blink_led() {
  digitalWrite(LED_PIN, HIGH);
  delay(50);
  digitalWrite(LED_PIN, LOW);
  delay(50);
}

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop()
{
  if ( MIDI.read() ) {
    blink_led();
  }
}
