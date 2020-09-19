/* Encoder-related functions and variables. */

#define encoder_pin_a 3
#define encoder_pin_b 4
#define encoder_btn_pin 5

int encoded;
volatile int last_encoded = 0;
volatile long encoder_value = 0;

int scaled_enc_val;
int prev_scaled_enc_val;

void update_encoder() {
  // MSB = most significant bit
  int MSB = digitalRead(encoder_pin_a);
  // LSB = least significant bit
  int LSB = digitalRead(encoder_pin_b);
  // converting the 2 pin value to single number
  encoded = (MSB << 1) | LSB;
  // adding it to the previous encoded value
  int sum  = (last_encoded << 2) | encoded;
  if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoder_value ++;
  if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoder_value --;
  if (encoder_value < 0) encoder_value = 0;
  // ?
  scaled_enc_val = encoder_value / 4;
  // store this value for next time
  last_encoded = encoded;
}

void setupEncoder() {
  // Configure encoder pins as inputs
  pinMode(encoder_pin_a, INPUT);
  pinMode(encoder_pin_b, INPUT);
  // Pull encoder pins up
  digitalWrite(encoder_pin_a, HIGH);
  digitalWrite(encoder_pin_b, HIGH);
  // Attach encoder pin interrupts
  attachInterrupt(encoder_pin_a, update_encoder, CHANGE);
  attachInterrupt(encoder_pin_b, update_encoder, CHANGE);
}

void setupEncoderBtn() {
  pinMode(encoder_btn_pin, INPUT_PULLUP);
}
