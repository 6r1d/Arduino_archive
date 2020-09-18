# ESP32 TTP229 demo

This example demonstrates how `TTP-229` [sensor board](https://robotdyn.com/catalog/16-keys-capacitive-touch-ttp229-i2c-module.html) from RobotDyn works. Be careful if you are making your own board, the [TTP-229](https://www.tontek.com.tw/uploads/product/106/TTP229-LSF_V1.0_EN.pdf) chip itself has several possible pinouts and TonTek makes different. I tried to contact TonTek, but I had no results.

## Connecting
I am usign a default [ESP32-WROOM-32](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf) [I²C](https://en.wikipedia.org/wiki/I%C2%B2C) connection:

* `SDA` to `GPIO` 21
* `SCL` to `GPIO` 22
* `GND` is obviously connected to `GND`
* `TTP-229` board's `VCC` to `3V3` pin

I am using ESP32 small batch fixture to do my test.

## Testing

This sketch is tested just now and works.

```
rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:1
load:0x3fff0018,len:4
load:0x3fff001c,len:1100
load:0x40078000,len:9232
load:0x40080400,len:6400
entry 0x400806a8
> 0
  0
> 0
  0
> F
  F
> 9
  9
```
