#include <Adafruit_NeoPixel.h>
#define DATA_PIN 4
#define NUM_PX 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(
    NUM_PX,
    DATA_PIN,
    NEO_GRB + NEO_KHZ800
);

int dataPin = 4;
int pixels = 12;
int pixel = 0;
int col_mode = 0;

void colorWipe(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(10);
  }
}

void setup() {
  strip.begin();
  colorWipe(
    strip.Color(0,0,0)
  );
  strip.show();
}

void loop() {
  if (col_mode == 0) {
    strip.setPixelColor(
      pixel,
      strip.Color(255, 0, 0)
    );
  }
  if (col_mode == 1) {
    strip.setPixelColor(
      pixel,
      strip.Color(0,255,0)
    );
  }
  if (col_mode == 2) {
    strip.setPixelColor(
      pixel,
      strip.Color(0,0,255)
    );
  }
  if (col_mode == 3) {
    strip.setPixelColor(
      pixel,
      strip.Color(0,0,0)
    );
  }

  strip.show();
  if (pixel < strip.numPixels() - 1) {
    pixel = pixel + 1;
  } else {
    pixel = 0;
    if (col_mode < 3) { col_mode++; }
    else { col_mode = 0; }
  }
  delay(1000);
}
