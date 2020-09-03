# MCP4725 example

MCP4725 IC is one-channel digital-to-analog converter using I²C protocol.
There are several possible ICs, so I'm documenting the possible addresses.
You need to enter this address in `dac.begin` argument for `Adafruit_MCP4725` library:

    void setup(void) {
        dac.begin(0x60);
    }

## Connecting wires

These wires should be connected to Arduino to exchange data.

| Arduino pin | MCP4725 board pin |
| ----------- | ----------------- |
| `5V`        | `VCC`             |
| `GND`       | `GND`             |
| `A4`        | `SDA`             |
| `A5`        | `SCL`             |

## I²C addresses

| IC name     | A0 / ADDR pin state  | I²C address (HEX)           | I²C address (BIN) | Checked |
| ----------- | -------------------- | --------------------------- | ----------------- | --------|
| `MCP4725A0` | GND, default         | 0x60                        | 0b1100000;        | &#9745; |
| `MCP4725A0` | VCC                  | 0x61                        | 0b1100001;        | &#9745; |
| `MCP4725A1` | GND, default         | 0x62                        | 0b1100010;        | &#9744; |
| `MCP4725A1` | VCC                  | 0x63                        | 0b1100011;        | &#9744; |
| `MCP4725A2` | GND, default         | 0x64                        | 0b1100100;        | &#9744; |
| `MCP4725A2` | VCC                  | 0x65                        | 0b1100101;        | &#9744; |
| `MCP4725A3` | GND, default         | 0x66                        | 0b1100110;        | &#9744; |
| `MCP4725A3` | VCC                  | 0x67                        | 0b1100111;        | &#9744; |
