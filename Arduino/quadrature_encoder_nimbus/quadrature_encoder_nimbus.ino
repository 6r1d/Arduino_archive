/*
 * Quadrature encoder example found in Nimbus synth.
 * Encoder: d3, d4.
 * Button: d5.
 * https://github.com/otem/RDEI/blob/master/Nimbus/Nimbus.ino
 */

#include "encoder.h"

void setup() {
  Serial.begin(9600);
  setupEncoder();
  setupEncoderBtn();
}

void loop() {
  // Encoder
  update_encoder();
  if (abs(scaled_enc_val - prev_scaled_enc_val) > 0) {
    prev_scaled_enc_val = scaled_enc_val;
    Serial.println(prev_scaled_enc_val);
  }
  
  // Process button on an encoder
  if (digitalRead(encoder_btn_pin) == LOW) {
    Serial.println("pressed");
  }
}
