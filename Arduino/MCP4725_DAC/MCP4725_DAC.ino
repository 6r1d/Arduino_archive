#include <Wire.h>
#include <Adafruit_MCP4725.h>

/*
 * This is an example, simplified to a minimum.
 * It is based on triangle wave example from Adafruit_MCP4725 demos.
 *
 * It only shows one voltage value.
 */

Adafruit_MCP4725 dac;

#define VOLTAGE 4095;

void setup(void) {
  // I²C addresses:
  // MCP4725A1: 0x62 (default) or 0x63 (ADDR pin tied to VCC)
  // MCP4725A0: 0x60 (default) or 0x61 (ADDR pin tied to VCC)
  // MCP4725A2: 0x64 (default) or 0x65 (ADDR pin tied to VCC)
  dac.begin(0x60);
}

void loop(void) {
    // Set min voltage value
    // dac.setVoltage(0, false);
    // Set max voltage value
    dac.setVoltage(VOLTAGE, false);
    // Set delay
    delay(1000);
}
