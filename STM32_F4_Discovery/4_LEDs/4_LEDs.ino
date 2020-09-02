/*
 * Attention: you may need to press Reset after programming.
 */

int mode;
bool state = LOW;

void setup() {
  pinMode(PD12, OUTPUT);
  pinMode(PD13, OUTPUT);
  pinMode(PD14, OUTPUT);
  pinMode(PD15, OUTPUT);
}

void loop() {
  switch (mode)
  {
      case 0:
        digitalWrite(PD12, state);
        break;
      case 1:
        digitalWrite(PD13, state);
        break;
      case 2:
        digitalWrite(PD14, state);
        break;
      case 3:
        digitalWrite(PD15, state);
        break;
  }

  if (mode < 3) {
    mode += 1;
  } else {
    mode = 0;
    state = !state;
  }

  delay(100);
}
