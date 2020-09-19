# ESP32 Bluetooth Low Energy demos

![It's not the best photo, but I am having fun](https://i.imgur.com/U9bBBOy.jpg)

## Notes

This directory contains MIDI examples for Bluetooth Low Energy.
I started using [npi3pak/ACID-Keys](https://github.com/npi3pak/ACID-Keys) code as a template, but I am removing the accumulator reading, his keyboard implementation and reorganizing code to make it slightly simpler (at least for me).

This document can be messy, because I'm really tired while writing it. Please be patient with me. :P

### Selecting a proper board

Use `Tools` > `Board` > `ESP32 Arduino` > `ESP32 Dev module`.

### Packet structure

You can read more about BLE MIDI packet structure in [Bluetooth LE MIDI Specification](https://www.midi.org/specifications/item/bluetooth-le-midi). I believe this document and these demos are related only to MIDI versions less than MIDI 2.0; more on MIDI 2.0 is there: "[Details about MIDI 2.0™, MIDI-CI, Profiles and Property Exchange](https://www.midi.org/midi-articles/details-about-midi-2-0-midi-ci-profiles-and-property-exchange)".

### Latency

In initial example, I saw a delay. I am not using it anymore, but there is a non-blocking [example](https://forum.arduino.cc/index.php?topic=616844.0) I decided to save: simply using Arduino's [`millis()`](https://www.arduino.cc/reference/en/language/functions/time/millis/) function to check if a required amount of milliseconds passed. There are more [notes](https://randomnerdtutorials.com/why-you-shouldnt-always-use-the-arduino-delay-function/) about that.

## Software

### Linux

I have tested BLE MIDI on `Ubuntu 18.04.5 LTS`. I had to reinstall Bluez using [this doc](https://tttapa.github.io/Pages/Ubuntu/Software-Installation/BlueZ.html), otherwise it didn't work at all. The only difference is Bluez version I have downloaded.

Installing requirements:

```
sudo apt install libudev-dev libical-dev libreadline-dev libdbus-1-dev libasound2-dev
sudo apt install build-essential
```

Downloading and building [`Bluez`](http://www.bluez.org/download/):

```
cd /tmp
wget http://www.kernel.org/pub/linux/bluetooth/bluez-5.54.tar.xz
tar -xf bluez-5.54.tar.xz

cd bluez-5.54
./configure --enable-midi --with-systemdsystemunitdir=/etc/systemd/system
make
sudo make install
sudo apt-get install --reinstall bluez
```

I have no idea why reinstalling `Bluez` makes everything work after, too.

For playing the sounds, I am using [LMMS](https://lmms.io/lsp/), when I just want to see the keyboard, [VMPK](https://vmpk.sourceforge.io/) is enough. To list MIDI devices, I am using `aplaymidi -l`.

### Android

I was not able to simply select a BLE MIDI device in Android's Bluetooth menu. There is another method, though!

To connect my MIDI keyboard, I am using "[MIDI BLE Connect](https://play.google.com/store/apps/details?id=com.mobileer.example.midibtlepairing)" app. It allows to pick a BLE device and emulate a MIDI device.
To test sound, I am using [FluidSynth](https://play.google.com/store/apps/details?id=net.volcanomobile.fluidsynthmidi) app and simply picking a MIDI device.

There is another BLE testing app for [Android](https://play.google.com/store/apps/details?id=no.nordicsemi.android.mcp) and [iOS](https://apps.apple.com/us/app/nrf-connect/id1054362403) by Nordic Semiconductor. It seems more generic, just to monitor BLE and maybe send messages, so I will play with it later.

## Questions

### Reconnection
Let's assume I am walking with an instrument far away or it powers down accidentally. If it reconnects to a computer, there is a possibility the device can be found on another MIDI port (I am checking with `aplaymidi -l` and LMMS). I tested the current code just now, everything's perfect now, but before I had a concerning situation like this, two different devices.

![LMMS MIDI glitch](https://i.imgur.com/rZqPXbg.png)

**UPD**: I added a StackOverflow [question](https://stackoverflow.com/questions/63956602/esp32-ble-midi-reconnection), maybe someone knows how to improve this code.

### Ambigous "iPhone connections issue"
Connection intervals for Bluetooth MIDI devices are documented ambigously.

I saw [this message](https://devzone.nordicsemi.com/f/nordic-q-a/22772/adding-midi-services) on NordicSemi devzone:

> According to the specification, the BLE MIDI device must request a connection interval of 15 ms or less.
> A lower connection interval is preferred in most applications of MIDI.
> The lowest allowed connection interval for BLE is 7.5 ms.

There is a certain timing configuration for "arduino-esp32/libraries/BLE/examples/BLE_server/BLE_server.ino" example at `espressif / arduino-esp32` repo people are copying.

```
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  ...
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
```

I have no idea if it's related to all the iPhone models, or it's something to forget about to make the connection faster, so I created an [issue](https://github.com/espressif/arduino-esp32/issues/4347) to ask about that.

`npi3pak`'s demo contained other timing values:

```
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  ...
  pAdvertising->setMinPreferred(0x12);
  pAdvertising->setMaxPreferred(0x16);
```

Related [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/bluetooth/esp_gap_ble.html) documentation.

Maybe [this issue](https://github.com/espressif/arduino-esp32/issues/3578) and [this one](https://github.com/nkolban/esp32-snippets/issues/209) are related, too.

### SERVICE_UUID and CHARACTERISTIC_UUID

I can [generate](https://www.uuidgenerator.net/) UUIDs. I doubt I should change this, since SparkFun [MIDI tutorial](https://learn.sparkfun.com/tutorials/midi-ble-tutorial/all) tells both should be fixed according to MIDI standard.

## Sketches

| Sketch name                                             | Description                                            |
| ------------------------------------------------------- | ------------------------------------------------------ |
| [Middle C press](/ESP_32/BLE_MIDI/BLE_MIDI_ESP32)       | Presses a middle C note (MIDI `60`), releases, repeats |
| [TTP-229 test](/ESP_32/BLE_MIDI/BLE_MIDI_ESP32_TTP229/) | Demonstrates using a TTP-229 sensor to select notes    |

## Links

* [NordicSemi DevZone topic](https://devzone.nordicsemi.com/f/nordic-q-a/22772/adding-midi-services) about BLE configuration for MIDI
* [Bluetooth LE MIDI Specification](https://www.midi.org/specifications/item/bluetooth-le-midi)
* [Details about MIDI 2.0™, MIDI-CI, Profiles and Property Exchange](https://www.midi.org/midi-articles/details-about-midi-2-0-midi-ci-profiles-and-property-exchange)
* SparkFun's [MIDI tutorial](https://learn.sparkfun.com/tutorials/midi-ble-tutorial/all)
* [An article about BLE](https://diytech.ru/projects/nachalo-raboty-s-esp32-bluetooth-v-arduino-ide) / Bluetooth Low Energy (russian)
* [BLE_MIDI Example by neilbags](https://github.com/neilbags/arduino-esp32-BLE-MIDI/blob/master/)
