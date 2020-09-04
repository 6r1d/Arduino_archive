// IO pins
const int SCK_PIN = A3;
const int DATA_PIN = A2;
// Calculation-related
long x = 0, y = 0;
long sum = 0;
// Average of the ten initial values
long initial_average_pressure = 0;
// Was an average value calculated?
bool min_calculated = false;

void setup() {
  // Start serial communication at 9600 baud
  Serial.begin(9600);
  // Initialize IO pins
  pinMode(DATA_PIN, INPUT);
  pinMode(SCK_PIN, OUTPUT);
}

// Updates SCK pin value
void clk() {
  digitalWrite(SCK_PIN, HIGH);
  digitalWrite(SCK_PIN, LOW);
}

void read_sensor() {
  // SCK is made LL
  digitalWrite(SCK_PIN, LOW);
  // Wait until Data Line goes LOW
  while (digitalRead(DATA_PIN) != LOW);
  // Read 24-bit data from HX711
  for (int i = 0; i < 24; i++) {
     // Generate CLK pulse to get MSB-it at DATA_PIN-pin
     clk();
     bitWrite(x, 0, digitalRead(DATA_PIN));
     x = x << 1;
  }
  clk();
  y = x;
  x = 0;
}

void loop() {
  // Calculate an average initial value
  if (!min_calculated) {
    delay(100);
    for (int j = 0; j < 10; j++)
    {
      read_sensor();
      delay(100);
      sum += y;
    }
    initial_average_pressure = sum / 10;
    Serial.println("Initial average pressure:");
    Serial.println(initial_average_pressure, DEC);
    min_calculated = true;
  }
  else {
    // Read and print a sensor value
    read_sensor();
    Serial.print(y - initial_average_pressure, DEC);
    Serial.print(" ");
    Serial.print(initial_average_pressure, DEC);
    Serial.print("\n");
    // Optional delay between sending new values to the serial port
    delay(1);
  }
}
