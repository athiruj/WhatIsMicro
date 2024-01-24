#define SW1 2
#define SW2 3

#define LED_R 9
#define LED_G 10
#define LED_B 11

#define RESISTER 0

unsigned long time = 0;

int count, getValue, colorNum, mapValue = 0;
int color[3] = { 0, 0, 0 };
int led[3] = { LED_R, LED_G, LED_B };
bool status = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Terminal Start!");

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(RESISTER, INPUT);

  // LAB 3_1 , 3_2
  // attachInterrupt(digitalPinToInterrupt(SW1), plusCount, FALLING);
  // attachInterrupt(digitalPinToInterrupt(SW2), minusCount, FALLING);

  // LAB 3_3
  attachInterrupt(digitalPinToInterrupt(SW1), interruptsBTN, FALLING);
  attachInterrupt(digitalPinToInterrupt(SW2), nointerruptsBTN, FALLING);
}

// LAB 3_1
// void plusCount() {
//   if (millis() - time > 100) {
//     time = millis();
//     if (digitalRead(SW1) == 0) {
//       count = (count + 1) % 100;
//       Serial.print(" count up: ");
//       Serial.println(count);
//     }
//   }
// }

// LAB 3_1
// void minusCount() {
//   if (millis() - time > 100) {
//     time = millis();

//     if (digitalRead(SW2) == 0) {
//       if (count < 1) {
//         count = 99;
//         Serial.print(" count down: ");
//         Serial.println(count);
//         return;
//       }
//       count--;
//       Serial.print(" count down: ");
//       Serial.println(count);
//     }
//   }
// }

// void blink() {
//   digitalWrite(LED, !status);
//   delay(2000);
// }

void interruptsBTN() {
  if (millis() - time > 150) {
    time = millis();
    if (digitalRead(SW1) == 0) {
  interrupts();
      status = 1;
      colorNum = (colorNum + 1) % 3;
    }
  }
}

void nointerruptsBTN() {
  if (millis() - time > 150) {
    time = millis();
    if (digitalRead(SW2) == 0) {
  noInterrupts();
      status = 0;
      Serial.println("LED Config Mode : Stop");
    }
  }
}


void loop() {
  if (status != 0) {
    getValue = analogRead(0);
    mapValue = map(getValue, 0, 1000, 0, 255);
    if (getValue < 10) mapValue = 0;
    if (getValue > 1000) mapValue = 255;
    color[colorNum] = mapValue;

    analogWrite(led[(colorNum + 1) % 3], color[(colorNum + 1) % 3]);
    analogWrite(led[(colorNum + 2) % 3], color[(colorNum + 2) % 3]);
    analogWrite(led[colorNum], color[colorNum]);

    Serial.print("RED");
    Serial.print(color[0]);
    Serial.print("GREEN");
    Serial.print(color[1]);
    Serial.print("BLUE");
    Serial.println(color[2]);

    delay(10);
  }else{
    analogWrite(LED_R, color[0]);
    analogWrite(LED_G, color[1]);
    analogWrite(LED_B, color[2]);
  }
}
