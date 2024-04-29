#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//#include <SoftwareSerial.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
//SoftwareSerial gsmSerial(D4, D3);
 
const int trigPin = D6;
const int echoPin = D5;
const int threshold = 75;
 
//String phoneNumber = "+9188305848xx";
 
void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
 
  //gsmSerial.begin(9600);
  delay(1000);
 
  lcd.clear();
  lcd.print("Smart Dustbin");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
}
 
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
 
  int fillLevel = map(distance, 0, 100, 100, 0);
 
 Serial.print("Fill Level: ");
 Serial.println(fillLevel);
  lcd.clear();
  lcd.print("Fill Level: ");
  lcd.print(fillLevel);
  lcd.print("%");
 
  if (fillLevel >= threshold) {
    sendSMSAlert();
  }
 
  delay(2000);
}
 
void sendSMSAlert() {
  lcd.clear();
  lcd.print("Sending Alert...");
  //gsmSerial.println("AT+CPIN=<SIM_PIN>");
  // delay(2000);
  // gsmSerial.println("AT+CMGF=1");
  // delay(1000);
  // gsmSerial.print("AT+CMGS=\"");
  // gsmSerial.print(phoneNumber);
  // gsmSerial.println("\"");
  // delay(1000);
 
  String message = "Dustbin Full! Please Empty.";
  //gsmSerial.print(message);
  // delay(1000);
  // gsmSerial.write(0x1A);
  // delay(2000);
 
  lcd.clear();
  lcd.print("Alert Sent!");
  delay(2000);
}