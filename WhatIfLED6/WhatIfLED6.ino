#define L1 10
#define L2 9
#define L3 8
#define L4 7
#define L5 6
#define L6 5

void lightIf(int i);

int x = 0;

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
}

void loop() {


  x++;
  lightIf(6 -x%7);
  Serial.println(6 - x%7);
  delay(1000);
}

void lightIf(int i) {
  if (i == 1) {

    digitalWrite(L1, 1);
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
  } else if (i == 2) {

    digitalWrite(L1, 1);
    digitalWrite(L2, 1);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
  } else if (i == 3) {

    digitalWrite(L1, 1);
    digitalWrite(L2, 1);
    digitalWrite(L3, 1);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
  } else if (i == 4) {

    digitalWrite(L1, 1);
    digitalWrite(L2, 1);
    digitalWrite(L3, 1);
    digitalWrite(L4, 1);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
  } else if (i == 5) {

    digitalWrite(L1, 1);
    digitalWrite(L2, 1);
    digitalWrite(L3, 1);
    digitalWrite(L4, 1);
    digitalWrite(L5, 1);
    digitalWrite(L6, 0);
  } else if (i == 6) {
    digitalWrite(L1, 1);
    digitalWrite(L2, 1);
    digitalWrite(L3, 1);
    digitalWrite(L4, 1);
    digitalWrite(L5, 1);
    digitalWrite(L6, 1);
  } else {
    digitalWrite(L1, 0);
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
  }
}
