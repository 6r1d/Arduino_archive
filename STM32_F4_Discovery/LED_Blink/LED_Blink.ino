// PD12 - green
// PD13 - orange
// PD14 - red
// PD15 - blue
#define LED_PIN PD12

bool state = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, state);
  state = !state;
  delay(100);
}
