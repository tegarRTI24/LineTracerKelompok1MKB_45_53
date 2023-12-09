#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27,20,4);
SoftwareSerial nanoSerial(10, 11);  // RX, TX
int s1 = 4;  // Pin analog untuk sensor 1
int s2 = 5;  // Pin analog untuk sensor 2
int s3 = 6;  // Pin analog untuk sensor 3

void setup() {
  Serial.begin(9600);
  nanoSerial.begin(9600);
  pinMode(s1,INPUT_PULLUP);
  pinMode(s2,INPUT_PULLUP);
  pinMode(s3,INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int d1 = digitalRead(s1);
  int d2 = digitalRead(s2);
  int d3 = digitalRead(s3);

  Serial.print(d1);
  Serial.print(",");
  Serial.print(d2);
  Serial.print(",");
  Serial.println(d3);
  lcd.setCursor(0,0);
  lcd.print(d1);
  lcd.print(" ");
  lcd.print(d2);
  lcd.print(" ");
  lcd.print(d3);
  lcd.print(" ");
}
