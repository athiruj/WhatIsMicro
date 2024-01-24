#include <DHT.h>

#include <LiquidCrystal_I2C.h>

#define LDR A0
#define DHTPIN 2
#define DHTTYPE DHT22

#define buttonPinPlus A2
#define buttonPinMinu A3

int buttonStatePlus = 1, buttonStateMinu = 1;          // the current reading from the input pin
int lastButtonStatePlus = 1, lastButtonStateMinu = 1;  // the previous reading from the input pin

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 10;

int readingPlus, readingMinu = 1;


int n = 0;
int light = 0;
float temp = 0;
float humi = 0;

DHT dht(DHTPIN, DHTTYPE);


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(buttonPinPlus, INPUT_PULLUP);
  pinMode(buttonPinMinu, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();

  dht.begin();
}

void timerSet() {
  if (millis() / 3600000 % 60 < 10) lcd.print("0");
  lcd.print(millis() / 3600000 % 60);

  lcd.print(":");

  if (millis() / 60000 % 60 < 10) lcd.print("0");
  lcd.print(millis() / 60000 % 60);

  lcd.print(":");

  if (millis() / 1000 % 60 < 10) lcd.print("0");
  lcd.print(millis() / 1000 % 60);
}

void ldr() {
  light = map(analogRead(LDR), 0, 1013, 0, 100);
  lcd.setCursor(0, 1);
  lcd.print("Brightness");
  lcd.setCursor(13, 1);
  if (light < 10) lcd.setCursor(14, 1);
  lcd.print(light);
  lcd.print("%");
}

void tempa() {
  temp = dht.readTemperature();
  // if(isnan(temp)){
  //   Serial.println("Temp Error");
  //   return;
  // }

  lcd.setCursor(0, 1);
  lcd.print("TEMP");
  lcd.setCursor(12, 1);
  if ((int)temp < 10) lcd.setCursor(13, 1);
  lcd.print((int)temp);
  lcd.print(" C");
}

void humidity() {
  // lcd.clear();
  humi = dht.readHumidity();
  // if(isnan(humi)){
  //   Serial.println("Humi Error");
  //   return;
  // }

  lcd.setCursor(0, 1);
  lcd.print("Humidity");
  lcd.setCursor(12, 1);
  if ((int)humi < 10) lcd.setCursor(13, 1);
  lcd.print((int)humi);
  lcd.print(" %");
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
        lcd.clear();
        n++;
      }
      buttonStatePlus = digitalRead(buttonPinPlus);
    }
    if (buttonStateMinu != lastButtonStateMinu) {
      // delay(10);
      if (digitalRead(buttonPinMinu) == 0) {
        lcd.clear();
        n--;
      }
      buttonStateMinu = digitalRead(buttonPinMinu);
    }
  }
  lcd.setCursor(4, 0);
  timerSet();

  switch (n % 3) {
    case 0:
      ldr();
      break;
    case 1:
      tempa();
      break;
    case 2:
      humidity();
      break;
  }
  lastButtonStatePlus = readingPlus;
  lastButtonStateMinu = readingMinu;
}