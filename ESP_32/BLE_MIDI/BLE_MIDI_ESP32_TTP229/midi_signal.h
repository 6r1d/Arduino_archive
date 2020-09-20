/*
 * BLE MIDI packet generation code.
 * 
 * Timestamp part copypasted from SLEEK_Reciever / "BLE MIDI to UART MIDI":
 * https://os.mbed.com/teams/Sleek/code/SLEEK_Reciever//file/244f1d0a3810/main.cpp/
 * 
 * Other parts (apparently) copied from:
 * https://github.com/neilbags/arduino-esp32-BLE-MIDI
 * 
 * Documentation used for validation:
 * "Specification for MIDI over Bluetooth Low Energy"
 * http://www.hangar42.nl/wp-content/uploads/2017/10/BLE-MIDI-spec.pdf
 * 
 * More of it:
 * https://learn.sparkfun.com/tutorials/midi-ble-tutorial/all
 */

uint16_t ticks;
uint8_t  header_byte, timestamp_byte;

uint8_t midi_packet[] = {
  // MIDI header
  0x80,
  // Timestamp, not implemented
  0x80,
  // Status
  0x00,
  // 0x3c == 60 == middle c
  0x3c,
  // Initial velocity, zero
  0x00
};

void send_note_on(BLECharacteristic * pCharacteristic, int note) {
  // Read timer for timestamps
  ticks = millis() & 0x1fff;
  // Header & timestampHigh
  midi_packet[0] = 0x80 | ((ticks >> 7) & 0x3f);
  // TimestampLow
  midi_packet[1] = 0x80 | (ticks & 0x7f);
  // Note down, channel 0
  midi_packet[2] = 0x90;
  midi_packet[3] = note;
  // Velocity
  midi_packet[4] = 127;
  // Packet, length in bytes
  pCharacteristic->setValue(midi_packet, 5);
  // Send MIDI packet
  pCharacteristic->notify();
}

void send_note_off(BLECharacteristic * pCharacteristic, int note) {
  // Read timer for timestamps
  ticks = millis() & 0x1fff;
  // Header & timestampHigh
  midi_packet[0] = 0x80 | ((ticks >> 7) & 0x3f);
  // TimestampLow
  midi_packet[1] = 0x80 | (ticks & 0x7f);
  // Note up, channel 0
  midi_packet[2] = 0x80;
  midi_packet[3] = note;
  // Velocity
  midi_packet[4] = 0;
  // Packet, length in bytes
  pCharacteristic->setValue(midi_packet, 5);
  // Send MIDI packet
  pCharacteristic->notify();
}
