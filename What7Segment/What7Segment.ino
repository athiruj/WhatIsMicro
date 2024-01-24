

#define buttonPinPlus A4
#define buttonPinMinu A5
const int ledPin = 13;

int buttonStatePlus=1, buttonStateMinu = 1;          // the current reading from the input pin
int lastButtonStatePlus=1, lastButtonStateMinu = 1;  // the previous reading from the input pin

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 10;

int readingPlus, readingMinu = 1;

int num[] = { 0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10 };
int digit[] = { 0xFE, 0xFD };
int n, m = 0;

void setup() {

  DDRD = 0xFF;
  DDRB = 0x03;
  pinMode(buttonPinPlus, INPUT_PULLUP);
  pinMode(buttonPinMinu, INPUT_PULLUP);
}

void loop() {
  readingPlus = digitalRead(buttonPinPlus);
  readingMinu = digitalRead(buttonPinMinu);



  if (readingPlus != lastButtonStatePlus || readingMinu != lastButtonStateMinu) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (buttonStatePlus != lastButtonStatePlus) {
      // delay(10);
      if (digitalRead(buttonPinPlus) == 0) {
        m++;
      }
        buttonStatePlus = digitalRead(buttonPinPlus);
    }
    if (buttonStateMinu != lastButtonStateMinu) {
      // delay(10);
      if (digitalRead(buttonPinMinu) == 0) {
        m--;
      }
        buttonStateMinu = digitalRead(buttonPinMinu);
    }
  }


  if (m == 10) {
    n++;
    m = 0;
  }

  if (m <= -1) {
     m = 9;
  
    if (n > 0) {
      n--;
    }
    if (n <= 0) {
      n = 9;
    }
  }

  PORTD = num[n % 10];
  PORTB = digit[0];
  delay(10);
  PORTB = 0xFF;
  PORTD = 0x00;

  PORTD = num[m];
  PORTB = digit[1];
  delay(10);
  PORTB = 0xFF;
  PORTD = 0x00;

  // Serial.print(n);
  // Serial.println(m);


  lastButtonStatePlus = readingPlus;
  lastButtonStateMinu = readingMinu;
}