
int AIN1 = 4;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           //kanan
int AIN2 = 2;
int BIN1 = 7; //kiri
int BIN2 = 8;
int STBY = 9;
int PWMA = 3; //kanan
int PWMB = 5; //kiri
float skiri = 163;
float skanan = 158.5;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int sl1 = A0;
int sl2 = A1;
int sl3 = A2;
int sl4 = A3;
int sl5 = A6;

int baca1,baca2,baca3,baca4,baca5;

void setup(){
  Serial.begin(9600);
  //softserial.begin(9600);
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
}

void loop(){
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    int index1 = data.indexOf(',');
    int index2 = data.indexOf(',', index1 + 1);
    int index3 = data.indexOf(',', index2 + 1);
    int index4 = data.indexOf(',', index3 + 1);
    int index5 = data.indexOf(',', index4 + 1);
    int index6 = data.indexOf(',', index5 + 1);
    int distance1 = data.substring(0, index1).toInt();
    int distance2 = data.substring(index1 + 1, index2).toInt();
    int distance3 = data.substring(index2 + 1, index3).toInt();
    float distance4 = data.substring(index3 + 1, index4).toInt();
    float distance5 = data.substring(index4 + 1, index5).toInt();
    float distance6 = data.substring(index5 + 1, index6).toInt();
    Serial.print(distance1);
    Serial.print(",");
    Serial.print(distance2);
    Serial.print(",");
    Serial.print(distance3);
    Serial.print(",");
    
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
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print(baca4);
    lcd.print(" ");
    lcd.print(baca5);
    lcd.print(" "); 
  }
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
