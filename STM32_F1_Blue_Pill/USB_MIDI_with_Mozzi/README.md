# USB MIDI on Blue Pill with Mozzi

## Description

I added a triangle oscillator and I handle each MIDI `Note On` event with changing the oscillator frequency.
To keep it as simple as possible, velocity is not handled in this example.

## Writing a firmware

I have used a cheap chinese STLink adapter.
I picked it by choosing `Tools` -> `Upload methods` -> `STLink`.
Then I found BluePill board as 
`Tools` -> `Boards` -> `STM32F1 boards (STM32Duino.com)` -> `Generic STM32F103C6/fake STM32F103C8`.

## "Usage"

Disconnect ST-Link, connect BluePill by USB.

Your system should detect it, whether it's Linux, Android or Windows.
