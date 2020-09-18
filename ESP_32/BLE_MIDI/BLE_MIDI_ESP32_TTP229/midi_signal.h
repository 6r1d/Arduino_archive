uint8_t midiPacket[] = {
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
  // Note down, channel 0
  midiPacket[2] = 0x90;
  midiPacket[3] = note;
  // Velocity
  midiPacket[4] = 127;
  // Packet, length in bytes
  pCharacteristic->setValue(midiPacket, 5);
  // Send MIDI packet
  pCharacteristic->notify();
}

void send_note_off(BLECharacteristic * pCharacteristic, int note) {
  // Note up, channel 0
  midiPacket[2] = 0x80;
  midiPacket[3] = note;
  // Velocity
  midiPacket[4] = 0;
  // Packet, length in bytes
  pCharacteristic->setValue(midiPacket, 5);
  // Send MIDI packet
  pCharacteristic->notify();
}
