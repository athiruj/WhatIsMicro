#define LED_R 11
#define LED_G 10
#define LED_B 9

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  minToMax(LED_R, 0, 0);
  minToMax(LED_G, 0, 0);

  maxToMin(LED_R, 0, 0);  // V

  minToMax(LED_B, 0, 0);

  maxToMin(LED_G, 0, 0);  // V

  minToMax(LED_R, 0, 0);

  minToMax(LED_G, 0, 0);

  maxToMin(LED_R, LED_G, LED_B);
}

void minToMax(int pin1, int pin2, int pin3) {
  for (int i = 0; i < 255; i++) {
    analogWrite(pin1, i);
    analogWrite(pin2, i);
    analogWrite(pin3, i);
    delay(10);
  }
  return 0;
}

void maxToMin(int pin1, int pin2, int pin3) {
  for (int i = 255; i > 0; i--) {
    analogWrite(pin1, i);
    analogWrite(pin2, i);
    analogWrite(pin3, i);
    delay(10);
  }
  return 0;
}
