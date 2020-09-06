# USB MIDI minimal template

This is a minimal template for using USB MIDI on [Blue Pill](https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill) boards.
It is using [USBComposite](https://github.com/arpruss/USBComposite_stm32f1) library by [arpruss](https://github.com/arpruss/).

## Description

This template only receives USB MIDI messages.
There are two types of signals it handles: `Note On` and `Note Off`, the ones on keyboard when you press a key.

First, `myMidi` class adds `Note On` and `Note Off` handlers, which write BluePill's status LED values.

Then `setProductString` sets the device name you will see in your [DAW](https://en.wikipedia.org/wiki/Digital_audio_workstation) application, MIDI keyboard, etc.

If your LED should be inverted, flip the value of `led_base_state` variable.

Firmware has a size of `20892` bytes in my case.

## Writing a firmware

I have used a cheap chinese STLink adapter.
I picked it by choosing `Tools` -> `Upload methods` -> `STLink`.
Then I found BluePill board as 
`Tools` -> `Boards` -> `STM32F1 boards (STM32Duino.com)` -> `Generic STM32F103C6/fake STM32F103C8`.

## "Usage"

Then you can connect the other side of the board by USB and check if it's connected in Linux.

    ~ lsusb
    Bus 001 Device 005: ID 1eaf:0030

Finally, pick "Tiny Helper" in your DAW and play a note. You'll see led glowing.

Windows users can be sure they'll see the device. I tested it on Windows 7 in [VMPK](https://vmpk.sourceforge.io/).

It's ok on Android as well, I used [MIDI keyboard](https://play.google.com/store/apps/details?id=com.mobileer.midikeyboard) app there to test it.
