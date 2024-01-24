#define LED_R 11
#define LED_G 10
#define LED_B 9

int getValue;
unsigned int n;
int leds[3] = { 11, 10, 9 };

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    getValue = Serial.readStringUntil('&').toInt();
    if (getValue > 255 && getValue < 0) {
      Serial.println("out of range 255 < value < 0");
    }
    analogWrite(leds[n % 3], getValue);
    n++;
  } else {
  }
}
