// Connections
//
// ESP32-WROOM-32: SDA <-> GPIO 21
//                 SCL <-> GPIO 22
//

#include <Wire.h>
#include <TTP229.h>

TTP229 ttp229;
int keys[16] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
bool key_pressed;

void setup()
{
  Wire.begin();
  Serial.begin(115200);
}

void loop()
{
  ttp229.readKeys();

  for (int i = 0; i < 16; ++i) {
    key_pressed = ttp229.isKeyPress(i);
    if (key_pressed != keys[i]) {
      if (keys[i]) {
        Serial.print("  ");
      } else {
        Serial.print("> ");
      }
      Serial.print(i, HEX);
      Serial.println();
    }
    keys[i] = key_pressed;
  }

  delay(100);
}
