#define LED_R 11
#define LED_G 10
#define LED_B 9
 int getValue,mapValue;
float voltValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_R,OUTPUT);
  pinMode(LED_G,OUTPUT);
  pinMode(LED_B,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  getValue = analogRead(A0);
  if(getValue < 70) mapValue = 70;
  if(getValue > 1000) mapValue = 1000;
  mapValue = map(getValue,69,1000,0,1023);
  voltValue = mapValue * 5.0/1023.0;
  Serial.println(String(getValue) + " : " + String(mapValue) + " : " + String(voltValue));
  delay(10);
}

// void loop() {
//   getValue = analogRead(A0);
//   mapValue = map(getValue,70,1000,0,1023);
//   if(getValue < 70) mapValue = 0;
//   if(getValue > 1000) mapValue = 1023;
//   voltValue = mapValue * 5.0/1023.0;
//   Serial.println(String(getValue) + " : " + String(mapValue) + " : " + String(voltValue));
//   delay(10);
// }
