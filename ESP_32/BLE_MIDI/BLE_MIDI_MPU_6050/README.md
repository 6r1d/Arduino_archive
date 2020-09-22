# BLE demo with ESP32 and MPU-6050

![Li-Ion power bank, ESP32 small batch fixture, MPU-6050 sensor](https://i.imgur.com/YgH9aDH.jpg)

`MPU-6050` is a gyroscope and accelerometer module by TDK.

It is `I²C`-compatible, which is pretty convenient, because it's easy to connect to a microcontroller.
I used `ESP32` to make it portable and `BLE`-compatible, too, so now you can use it to "play music", or at the very least, bother others with weird sounds.

## Description

Just connect some `ESP32` board to `MPU-6050` module, like `GY-521` from AliExpress.
Upload the firmware, connect your device by `BLE`, select "Bluetooth MIDI Keyboard", turn `MPU-6050` board to play different notes and change pauses, have fun!

I tested it with Android and Ubuntu Linux, these are fun to play with.

### Connection

| MPU 6050 | ESP32 board |
| -------- | ----------- |
| `VCC`    | `3.3 V`     |
| `GND`    | `GND`       |
| `SCL`    | `IO 22`     |
| `SDA`    | `IO 21`     |

### Notes

#### Accelerometer and gyroscope registers

**Warning!** You might need to replace `ax` with `gx` and `ay` with `gy`!

In my case, accelerometer variables are storing gyroscope data and vice versa.
I am planning to make my own accelerometer PCB to fix that, because I am not sure if the chip I have there is an original one or not.

## Demo

[Soundcloud](https://soundcloud.com/i-am-6r1d/testing-mpu-6050-gyroscope)

## Links

- Accelerometer-only [demo](https://github.com/6r1d/Arduino_archive/tree/master/ESP_32/MPU_6050)
- [MPU-6050](https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/) page
