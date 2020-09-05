# Mozzi analog input modulator

This is a little, possibly silly experiment I did with Mozzi sonification library.
It performs a frequency modulation on a sine wave played (as with all Mozzi demos besides the Teensy ones) through the PWM output.

A fun thing about this modulation is a modulation data source: `XD-RF-5V` receiver module (`315 MHz`, `330 MHz`, `433 MHz`)!

A less fun thing there is the possibility of this modulation possibly using the same value twice (`TODO: check`).

Some demo is required later.

## Sections

`void setup()` initializes the sine wave and configures Mozzi's control rate. Control rate configures how much `updateControl` is called, so it's not that useful.

`void updateControl() {}` is not being used. I'd normally consider using it, but it's too slow.

`int updateAudio()` does analog value capture, calculates frequency, performs a modulation and returns the modulated sine wave.
