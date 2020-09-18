# Arduino archive

## Idea
Hey!

I guess you accidentally found this repo. It seems I have a number of Arduino sources and this number is growing.

So I am simply going to throw those here and make notes. Why? I often want to find a pin with LED on a breadboard, connect I²S soundcard or some I²C thermometer without googling in the first place, that's why.

Why I am not using Gist? Because I can make notes here better.

So, deal? I mean, there are videos on YouTube telling you how not to hold the soldering iron by the tip or a barrel, so bear with me.

Still no deal? Fine, whatever.


## Topics

| Board / MCU                               | Description                                                            |
| ----------------------------------------- | ---------------------------------------------------------------------- |
| [Arduino](/Arduino)                       | AtMega 328, 5V, 8 bit                                                  |
| [Digispark](/Digispark)                   | AtTiny 85, 5V, 8 bit                                                   |
| [ESP_32](/ESP_32)                         | ESP32-WROOM-32                                                         |
| [STM32 F1 Blue Pill](/STM32_F1_Blue_Pill) | STM32F103C8T6, 3.3v, 32-bit, 64KiB flash, 20KiB SRAM                   |
| [STM32 F4 Discovery](/STM32_F4_Discovery) | STM32F407VG, 3.3v, 32-bit, 1 Mb flash, 192 Kb RAM                      |

## To-Do

### MIDI 2.0
Determine if MIDI 2.0 will require different schematics, find out about the required code changes.

**UPD**: I found a note in [this article](https://www.midi.org/midi-articles/details-about-midi-2-0-midi-ci-profiles-and-property-exchange) on [MIDI.org](midi.org):

> The traditional 5 pin DIN transport from MIDI 1.0 uses a byte stream rather than packets. At the moment, there is no plan to use the Universal MIDI Packet on the 5 pin DIN transport. Unless/Until that plan changes, 5 pin DIN will only support the MIDI 1.0 Protocol.

On the other hand, MIDI forum admins [claim](https://www.midi.org/forum/3794-what-will-the-midi-2-0-speed-be#reply-3883):

> As for 5 PIN DIn, Electron had products several years ago that had 10 times the speed of MIDI 1.0 on the same 5 Pin DIN connector, but with a slight modification of the part for the UART. MIDI-CI provides a method for negotiation so it would be possible for two devices to negotiate to a higher bandwidth on 5 Pin DIN. MIDI - CI makes a lot of things possible and we just need to prioritize the work that will get done next.

TL;DR: I am confused.

* [Forum topic](https://www.midi.org/forum/3794-what-will-the-midi-2-0-speed-be) about MIDI 2.0 speed
* [Forum topic](https://www.midi.org/midi/forum/4791-midi-2-0-keyboards) about keyboards and MIDI 2.0 on Arduino
