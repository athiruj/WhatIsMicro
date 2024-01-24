#define L1 10
#define L2 9
#define L3 8
#define L4 7
#define L5 6
#define L6 5

void lightFor();

void setup() {
  Serial.begin(9600);

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);

  digitalWrite(L1, 1);
  digitalWrite(L2, 1);
  digitalWrite(L3, 1);
  digitalWrite(L4, 1);
  digitalWrite(L5, 1);
  digitalWrite(L6, 1);

  delay(500);

  digitalWrite(L1, 0);
  digitalWrite(L2, 0);
  digitalWrite(L3, 0);
  digitalWrite(L4, 0);
  digitalWrite(L5, 0);
  digitalWrite(L6, 0);
  lightFor();
}

void loop() {
}

void lightFor() {
  for (int i = 0; i < 1000; i++) {
      digitalWrite(L1, 1);
      digitalWrite(L2, 0);
      digitalWrite(L3, 0);
      digitalWrite(L4, 0);
      digitalWrite(L5, 0);
      digitalWrite(L6, 0);
     delay(1000);

      digitalWrite(L1, 1);
      digitalWrite(L2, 1);
      digitalWrite(L3, 0);
      digitalWrite(L4, 0);
      digitalWrite(L5, 0);
      digitalWrite(L6, 0);
     delay(1000);

      digitalWrite(L1, 1);
      digitalWrite(L2, 1);
      digitalWrite(L3, 1);
      digitalWrite(L4, 0);
      digitalWrite(L5, 0);
      digitalWrite(L6, 0);
     delay(1000);

      digitalWrite(L1, 1);
      digitalWrite(L2, 1);
      digitalWrite(L3, 1);
      digitalWrite(L4, 1);
      digitalWrite(L5, 0);
      digitalWrite(L6, 0);
     delay(1000);

      digitalWrite(L1, 1);
      digitalWrite(L2, 1);
      digitalWrite(L3, 1);
      digitalWrite(L4, 1);
      digitalWrite(L5, 1);
      digitalWrite(L6, 0);
     delay(1000);
      digitalWrite(L1, 1);
      digitalWrite(L2, 1);
      digitalWrite(L3, 1);
      digitalWrite(L4, 1);
      digitalWrite(L5, 1);
      digitalWrite(L6, 1);
     delay(1000);
      digitalWrite(L1, 0);
      digitalWrite(L2, 0);
      digitalWrite(L3, 0);
      digitalWrite(L4, 0);
      digitalWrite(L5, 0);
      digitalWrite(L6, 0);
    delay(1000);
  }
}
