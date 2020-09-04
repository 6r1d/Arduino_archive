// Sets random values in a single NeoPixel.

#include <Adafruit_NeoPixel.h>
#define DATA_PIN 4
#define NUM_PX 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PX, DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  // Sets a color for NeoPixel 0
  strip.setPixelColor(
    0,
    strip.Color(random(0,255), random(0,255), random(0,255))
  );
  // Updates a strip
  strip.show();
  // Waits 100 ms
  delay(100);
}
