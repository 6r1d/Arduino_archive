#include <Wire.h>
#include <Adafruit_MCP4725.h>

/*
 * This is an example, simplified to a minimum.
 * It is based on triangle wave example from Adafruit_MCP4725 demos.
 *
 * It only shows one voltage value.
 * 
 * On Arduino Nano / Uno and MCP4725 board, connections are:
 * 5V - VCC
 * GND - GND
 * A4 - SDA
 * A5 - SCL
 */

#define VOLTAGE 4095

Adafruit_MCP4725 dac;

void setup(void) {
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
