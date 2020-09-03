/*
 * Quadrature encoder example with no debouncing.
 *
 * Based on a sketch by Max Wolf (www.meso.net)
 */

#define encoder_pin_a 3
#define encoder_pin_b 4
#define encoder_btn_pin 5

int  val;
int  encoder_position = 0;
bool encoder_pin_a_last = LOW;
bool n = LOW;

void setup() {
  pinMode(encoder_pin_a,   INPUT_PULLUP);
  pinMode(encoder_pin_b,   INPUT_PULLUP);
  pinMode(encoder_btn_pin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // Process encoder
  n = digitalRead(encoder_pin_a);
  if ((encoder_pin_a_last == LOW) && (n == HIGH)) {
    if (digitalRead(encoder_pin_b) == LOW) {
      encoder_position--;
    } else {
      encoder_position++;
    }
    Serial.println(encoder_position);
  }
  encoder_pin_a_last = n;

  // Process button on an encoder
  if (digitalRead(encoder_btn_pin) == LOW) {
    Serial.println("pressed");  
  } 
}
