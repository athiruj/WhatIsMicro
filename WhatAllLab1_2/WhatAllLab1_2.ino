#define L1 10
#define L2 9
#define L3 8
#define L4 7
#define L5 6
#define L6 5

bool s1 = 0;
bool s2 = 0;
bool s3 = 0;
bool s4 = 0;
bool s5 = 0;
bool s6 = 0;

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

  if (Serial.available() > 0) {
    // char d = NULL;
    // char input_char = Serial.read();
    // if(input_char == '\n');
    // else d = input_char;
    String d = Serial.readStringUntil(" ");
    lightSwitch(d[0]);
  } else {
    digitalWrite(L1, s1);
    digitalWrite(L2, s2);
    digitalWrite(L3, s3);
    digitalWrite(L4, s4);
    digitalWrite(L5, s5);
    digitalWrite(L6, s6);
  }
}

void lightSwitch(char i) {
  switch (i) {
    case '1':
      s1 = !s1;
      Serial.println("LED: 1");
      break;
    case '2':
      s2 = !s2;
      Serial.println("LED: 2");
      break;
    case '3':
      s3 = !s3;
      Serial.println("LED: 3");
      break;
    case '4':
      s4 = !s4;
      Serial.println("LED: 4");
      break;
    case '5':
      s5 = !s5;
      Serial.println("LED: 5");
      break;
    case '6':
      s6 = !s6;
      Serial.println("LED: 6");
      break;
    case '0':
      s1 = 0;
      s2 = 0;
      s3 = 0;
      s4 = 0;
      s5 = 0;
      s6 = 0;
      Serial.println("LEDALL: OFF");
      break;
    default:
      Serial.println("Error");
      break;
  }
}
