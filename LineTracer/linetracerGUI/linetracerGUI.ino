#include <SPI.h>
int AIN1 = 4;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           //kanan
int AIN2 = 2;
int BIN1 = 7; //kiri
int BIN2 = 8;
int STBY = 9;
int PWMA = 3; //kanan
int PWMB = 5; //kiri
float skiri = 163;
float skanan = 156;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,12,2);

int sl1 = A0;
int sl2 = A1;
int sl3 = A2;
int sl4 = A3;
int sl5 = A6;

int baca1,baca2,baca3,baca4,baca5;

void setup(){
  Serial.begin(9600);
  pinMode(sl1,INPUT);
  pinMode(sl2,INPUT);
  pinMode(sl3,INPUT);
  pinMode(sl4,INPUT);
  pinMode(sl5,INPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(STBY,OUTPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(PWMB,OUTPUT);
  lcd.init();
  lcd.backlight();
  SPI.begin();
}

void loop(){
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  int distance1 = (SPI.transfer16(0) & 0x7FFF);
  int distance2 = (SPI.transfer16(0) & 0x7FFF);
  int distance3 = (SPI.transfer16(0) & 0x7FFF);

  SPI.endTransaction();

  float distance4 = SPI.transfer(0);
  float distance5 = SPI.transfer(0);
  float distance6 = SPI.transfer(0);
  if (Serial.available() > 0) {
    char dataGUI = Serial.read();
    if(dataGUI == 'O'){
      // Check the conditions and control the motor
      if (distance1 >= 20) {
        maju();
      } else if(distance2<=5 && distance1<=5) {
        kanan();
      }else if(distance3<=5 && distance1<=5) {
        kiri();
      }else if(distance1<=5){
        stopp();
      }
    }
    if(dataGUI == 'F'){
      maju();
    }
    if(dataGUI == 'B'){
      mundur();
    }
    if(dataGUI == 'K'){
      kanan();
    }
    if(dataGUI == 'J'){
      kiri();
    }
    if(dataGUI == 'S'){
      stopp();
    }
    if(dataGUI == 'C'){
      kanan();
      delay(10000);
      stopp();
    }
    if(dataGUI == 'L'){
      maju();
      delay(2000);
      kiri();
      delay(500);
      stopp();
    } 
  }
    Serial.print(distance1);
    Serial.print(",");
    Serial.print(distance2);
    Serial.print(",");
    Serial.print(distance3);
    Serial.print(",");    
    bacaline();
    Serial.print(baca1);
    Serial.print(",");
    Serial.print(baca2);
    Serial.print(",");
    Serial.print(baca3);
    Serial.print(",");
    Serial.print(baca4);
    Serial.print(",");
    Serial.print(baca5);
    Serial.print(",");
    Serial.print(distance4);
    Serial.print(",");
    Serial.print(distance5);
    Serial.print(",");
    Serial.println(distance6);
    lcd.setCursor(0,0);
    lcd.print(baca1);
    lcd.print(" ");
    lcd.print(baca2);
    lcd.print(" ");
    lcd.print(baca3);
    lcd.setCursor(0,1);
    lcd.print(baca4);
    lcd.print(" ");
    lcd.print(baca5);
}

void bacaline(){
  baca1=analogRead(sl1);
  baca2=analogRead(sl2);
  baca3=analogRead(sl3);
  baca4=analogRead(sl4);
  baca5=analogRead(sl5);
}

void maju(){
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
  digitalWrite(STBY,HIGH);
  analogWrite(PWMA,skanan);
  analogWrite(PWMB,skiri);
}

void mundur(){
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
  digitalWrite(STBY,HIGH);
  analogWrite(PWMA,skanan);
  analogWrite(PWMB,skiri);
}

void kanan(){
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
  digitalWrite(STBY,HIGH);
  analogWrite(PWMA,skanan);
  analogWrite(PWMB,skiri);
}

void kiri(){
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
  digitalWrite(STBY,HIGH);
  analogWrite(PWMA,skanan);
  analogWrite(PWMB,skiri);
}

void stopp(){
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,LOW);
  digitalWrite(STBY,LOW);
  analogWrite(PWMA,0);
  analogWrite(PWMB,0);
}
