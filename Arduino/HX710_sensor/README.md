# HX710 sensor demo using a pressure sensors

## Idea
There is a 24-bit ADC chip called HX710 made by [Avia Semiconductor / Xiamen](http://en.aviaic.com/).

This chips are very popular in AliExpress pressure sensor boards with a DIP pressure sensor: look up something like "3.3-5V Digital Barometric Pressure Sensor Module For Arduino". You connect a soft plastic tube and you get the pressure measurement as an integer.
You don't have an output in [Pa](https://en.wikipedia.org/wiki/Pascal_(unit)) / [Bar](https://en.wikipedia.org/wiki/Bar_(unit)) / [Psi](https://en.wikipedia.org/wiki/Pounds_per_square_inch), though, so you'll have to use another sensor to make sense of the measurement. With a low cost it is not a bad deal at all.

You can easily find the pressure sensor itself, too. Look for "DIP-6 Sphygmomanometer Sensor 0-40kPa".
It apparently is called `MPS20N0040D-D` and requires 5V power input, judging by a random translated datasheet.
`TODO` I will have to test its sensitivity for different voltages myself someday.

## Connecting

The sensor boards typically have 4 pins and are quite easy to connect:

| Board     | Arduino |
| --------- | ------- |
| 5V / 3.3V | VCC     |
| GND       | GND     |
| SCK       | A3      |
| DATA      | A2      |

## Uses
The pressure sensor chip itself is mostly used in portable sphygmomanometers to monitor air pressure.
It probably can be used to monitor liquid level indirectly, too.

I found out about it by dismantling a sphygmomanometer and decided it is worth some interest: for example, you can make a music keyboard using many sensors connected to an array of tubes, where each tube filled with air is a key. That'll give a lot of aftertouch values. ;-)

Also, `MPS20N0040D-D` is cheaper than `MPXHZ6400AC6T1` by NXP, which is nice. 