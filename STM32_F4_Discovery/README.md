# STM32F4 Discovery

## Notes

### Selecting a proper board

* `Tools` > `Board` > `STM32F4 Boards` > `STM32 Discovery F407`
* `Tools` > `USB configuration` can remain as `USB serial`
* `Tools` > `Get board info` shows it's a genuine `STM32 Discovery F407` on `/dev/ttyACM0`

`USB configuration` means how USB port will be used. It can just hang in air, work as a mass storage, or as USB serial.
In case of `Blue Pill` boards on a simpler MCU I was able to use several, but I guess I can't there.

### Led map

STM32F4 Discovery board has four leds you'll be using the most, and those are located around an accelerometer IC.

I'd like to map the locations of those LEDs, assuming `ST-Link` / `SWD` pins is the top one
and the stereo jack part is the bottom one.

| LED name | Pin  | Color                | Board location                                        |
| -------- | ---- | -------------------- | ----------------------------------------------------- |
| LD4      | PD12 | green                | left side, near to blue button labelled `User`        |
| LD3      | PD13 | reddish orange / red | top side, close to STM32F4 MCU                        |
| LD5      | PD14 | red                  | right side, closer to a black button labelled `Reset` |
| LD6      | PD15 | blue                 | bottom side, closer to the stereo jack and USB port   |
