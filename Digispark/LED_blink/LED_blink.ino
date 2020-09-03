// Pin 1 on Model A
// Pin 0 on Model B
#define LED_PIN 1;

// Description:
// https://digistump.com/wiki/digispark/tutorials/connecting

void setup() {                
  // Initialize the digital pin as an output.
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Turn the LED on
  digitalWrite(LED_PIN, HIGH);
  // Wait for 500 ms
  delay(500);
  // Turn the LED off
  digitalWrite(LED_PIN, LOW);
  // Wait for 500 ms
  delay(500);
}
