# Quadrature encoder (basic)

This example has no debouncing so values will sometimes jump to both sides randomly when you move the encoder, but it is useful to quickly test an encoder nevertheless. This example is well-tested on Arduino Nano and Arduino Uno, connection diagram is correct.

I used it with only encoder and wires, there are other parts with a PCB and passive SMD components I have not tested with this code.

Moreover, there are I²C encoders this code is incompatible with.

## Connection diagram

[![Connection diagram](/Arduino/quadrature_encoder_basic/img/kicad_sketch.png?raw=true)](/Arduino/quadrature_encoder_basic/img/kicad_sketch.svg)

Digital pins `D3` and `D4` on Arduino are connected to the encoder pins on the top. Middle encoder pin is connected to `GND`.
Two bottom pins are a simple button connection, so one can be connected to `GND` and other to `D5`.

## Credits
Based on a sketch by [Max Wolf](www.meso.net).
