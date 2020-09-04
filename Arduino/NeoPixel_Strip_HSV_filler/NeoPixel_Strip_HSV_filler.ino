#include <Adafruit_NeoPixel.h>
#define DATA_PIN 4
#define NUM_PX 12

// TODO:
// what does NEO_GRB + NEO_KHZ800 mean, anyway?
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PX, DATA_PIN, NEO_GRB + NEO_KHZ800);

int pixel = 0;
int rgb[3];
float hue = 0;

// Updates a color, adds a delay
void colorWipe(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(10);
  }
}

// Converts HSV to RGB color
// TODO: find author, add to credits
void HSV_to_RGB(double h, double s, double v, int * rgb) {
    double r, g, b;

    int i = int(h * 6);
    double f = h * 6 - i;
    double p = v * (1 - s);
    double q = v * (1 - f * s);
    double t = v * (1 - (1 - f) * s);

    switch(i % 6){
        case 0: r = v, g = t, b = p; break;
        case 1: r = q, g = v, b = p; break;
        case 2: r = p, g = v, b = t; break;
        case 3: r = p, g = q, b = v; break;
        case 4: r = t, g = p, b = v; break;
        case 5: r = v, g = p, b = q; break;
    }

    rgb[0] = (int) (r * 255.0);
    rgb[1] = (int) (g * 255.0);
    rgb[2] = (int) (b * 255.0);
}

void setup() {
  rgb[0] = 0;
  rgb[1] = 0;
  rgb[2] = 0;
  
  Serial.begin(9600);
  
  strip.begin();
  colorWipe(
    strip.Color(0,0,0)
  );
  strip.show();
}

// Updates a Hue parameter for HSV color,
// updates the NeoPixel strip
void loop() {
  HSV_to_RGB(hue, 1.0, 1.0, rgb);
  strip.setPixelColor(pixel, strip.Color(rgb[0], rgb[1], rgb[2]));
  strip.show();
  
  if (pixel < strip.numPixels() - 1) {
    pixel = pixel + 1;
  } else {
    pixel = 0;
    if (hue < 1.0) { hue += 0.01; }
    else { hue = 0.0; }
  }

  // Debug colors using a serial port
  Serial.print(rgb[0]);
  Serial.print(' ');
  Serial.print(rgb[1]);
  Serial.print(' ');
  Serial.print(rgb[2]);
  Serial.println();
  
  delay(10);
}
