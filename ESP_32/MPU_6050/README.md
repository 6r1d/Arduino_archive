# MPU-6050

## Description

A fork of [CircuitDigest.com](https://circuitdigest.com/microcontroller-projects/mpu6050-gyro-sensor-interfacing-with-esp32-nodemcu-board) MPU-6050 demo. Adds better serial formatting, removes WiFi support I wasn't using.

### Connection

| MPU 6050 | ESP32 board |
| -------- | ----------- |
| `VCC`    | `3.3 V`     |
| `GND`    | `GND`       |
| `SCL`    | `IO 22`     |
| `SDA`    | `IO 21`     |

## Videos

Asciinema: [Playing with TDK MPU-6050 accelerometer](https://asciinema.org/a/361002)

## Example output

    AX:  0.07 AY:  0.13 AZ: -0.46 GX: -0.08 GY: -0.00 GZ: -0.02
    AX:  0.07 AY:  0.13 AZ: -0.48 GX: -0.08 GY: -0.01 GZ:  0.01
    AX:  0.06 AY:  0.13 AZ: -0.47 GX: -0.08 GY: -0.02 GZ:  0.01
    AX:  0.07 AY:  0.14 AZ: -0.47 GX: -0.08 GY:  0.01 GZ: -0.01
    AX:  0.07 AY:  0.12 AZ: -0.47 GX: -0.08 GY: -0.00 GZ: -0.01
    AX:  0.06 AY:  0.13 AZ: -0.47 GX: -0.08 GY:  0.00 GZ: -0.00
    AX:  0.06 AY:  0.13 AZ: -0.47 GX: -0.08 GY: -0.01 GZ: -0.00
    AX:  0.07 AY:  0.13 AZ: -0.47 GX: -0.08 GY:  0.01 GZ:  0.01

## TO-DO

- [ ] fix type ambiguity; [related topic](https://stackoverflow.com/questions/3519282/why-is-this-ambiguity-here)
- [ ] review [signal filtering](https://www.esp32.com/viewtopic.php?t=6848)
