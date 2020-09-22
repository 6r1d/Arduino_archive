# BLE demo with ESP32 and MPU-6050

MPU-6050 is a gyroscope and accelerometer module by TDK.
It is I²C compatible, which is cool, because it's easy to connect to a microcontroller.
But I used ESP32 to make it portable and BLE-compatible, too, so now you can use it to "play music", or at the very least, bother others with weird sounds.

## Description

Just connect some ESP32 board to MPU-6050 module, like GY-521 from AliExpress.
Upload the firmware, connect your device by BLE, select "Bluetooth MIDI Keyboard", have fun!

### Connection

| MPU 6050 | ESP32 board |
| -------- | ----------- |
| `VCC`    | `3.3 V`     |
| `GND`    | `GND`       |
| `SCL`    | `IO 22`     |
| `SDA`    | `IO 21`     |

## Demo

[Soundcloud](https://soundcloud.com/i-am-6r1d/testing-mpu-6050-gyroscope)
