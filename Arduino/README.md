# Examples for Arduino Nano and Arduino Uno boards

## Sketches

| Board                                                                  | Description                                                      |
| ---------------------------------------------------------------------- | ---------------------------------------------------------------- |
| [Quadrature encoder, basic example](/Arduino/quadrature_encoder_basic) | The simplest way to connect a quadrature encoder I know of       |
| [HX710 ADC and MPS20N0040D-D pressure sensor](/Arduino/HX710_sensor)   | Demonstrates working with `HX710` ADC without a specific library |
| [MCP4725 DAC](/Arduino/MCP4725_DAC)                                    | Using `MCP4725` DAC                                              |

### NeoPixel

**Important**: particle.io [article](https://blog.particle.io/heads-up-ws2812b-neopixels-are-about-to-change/) about NeoPixel changes.

| Board                                                                  | Description                                                      |
| ---------------------------------------------------------------------- | ---------------------------------------------------------------- |
| [NeoPixel single random pixel](/Arduino/NeoPixel_single_random)        | Filling a single pixel with a random value at a regular interval |
| [NeoPixel strip filling](/Arduino/NeoPixel_fill_strip)                 | Filling a whole NeoPixel strip with random values                |
| [NeoPixel strip HSV filler](/Arduino/NeoPixel_Strip_HSV_filler)        | Gradually filling NeoPixel with changing values                  |

### TODO: APA102

### MIDI

| Board                                                                  | Description                                                      |
| ---------------------------------------------------------------------- | ---------------------------------------------------------------- |
| Output, [random notes](/Arduino/MIDI_random_notes)                     | Sends some random notes by MIDI                                  |
| Input, [library-based, bare bones](/Arduino/MIDI_input_lib_barebones)  | A very basic demo of MIDI input using [Arduino MIDI library](https://github.com/FortySevenEffects/arduino_midi_library) |
