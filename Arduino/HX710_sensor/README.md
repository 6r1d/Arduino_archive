# HX710 sensor demo using a pressure sensors

## Idea
There is a 24-bit ADC chip called HX710 made by [Avia Semiconductor / Xiamen](http://en.aviaic.com/).

This chips are very popular in AliExpress pressure sensor boards with a DIP pressure sensor: look up something like "3.3-5V Digital Barometric Pressure Sensor Module For Arduino". You connect a soft plastic tube and you get the pressure measurement as an integer.
You don't have an output in [Pa](https://en.wikipedia.org/wiki/Pascal_(unit)) / [Bar](https://en.wikipedia.org/wiki/Bar_(unit)) / [Psi](https://en.wikipedia.org/wiki/Pounds_per_square_inch), though, so you'll have to use another sensor to make sense of the measurement. With a low cost it is not a bad deal at all.

### Pressure sensor IC

Pressure sensor IC is easy to find, as well. Look for "DIP-6 Sphygmomanometer Sensor 0-40kPa".

It apparently is called `MPS20N0040D-D` and requires 5V power input, judging by a random translated datasheet.
Another random datasheet calls it `MPS20N0040D-S` and has info about it contacts, so I made an illustration.
`TODO` I will have to test its sensitivity for different voltages myself someday.

[![HX710](/Arduino/HX710_sensor/img/pressure_sensor.png)](/Arduino/HX710_sensor/img/pressure_sensor.svg)

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

## Documentation

* [Datasheet](https://softroboticstoolkit.com/files/sorotoolkit/files/mps20n0040d-s_datasheet.pdf) for MPS20N0040D-S pressure sensor; I am not sure about its reliability, but it is still useful
* [Calibration manual](https://makersportal.com/blog/2020/6/4/mps20n0040d-pressure-sensor-calibration-with-arduino)

## Links

* [HX711 library](https://github.com/bogde/HX711). This library is for `HX711` sensors, which are a bit different. This [issue](https://github.com/bogde/HX711/issues/180) discusses how to adapt the library for `HX710` sensors.
* A russian [article](https://habr.com/ru/post/438772/) claiming that HX711 datasheet is incorrect and working with HX711 requires some magic.
* A [topic](https://forum.arduino.cc/index.php?topic=486101.15) on Arduino forums about IC gain configuration
* Another [topic](https://forum.arduino.cc/index.php?topic=568044.0) on Arduino forums about the DIY weighting machine on the `HX71x` IC
