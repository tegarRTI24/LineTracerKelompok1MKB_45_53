#include <NewPing.h>
#define TRIGGER_PIN 5
#define ECHO_PIN 4
#define TRIGGER_PIN2 7
#define ECHO_PIN2 6
#define TRIGGER_PIN3 3
#define ECHO_PIN3 2
#define MAX_DISTANCE 200

NewPing sonar1(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE);

#include <Wire.h>

float RateRoll,RatePitch,RateYaw;

float RateCalibrationRoll,RateCalibrationPitch,RateCalibrationYaw;

int RateCalibrationNumber;

void gyro_signals(void){
  Wire.beginTransmission(0x68);
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x1B);
  Wire.write(0x08);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0x68,6);
  int16_t GyroX=Wire.read()<<8 | Wire.read();
  int16_t GyroY=Wire.read()<<8 | Wire.read();
  int16_t GyroZ=Wire.read()<<8 | Wire.read();
  RateRoll=(float)GyroX/65.5;
  RatePitch=(float)GyroY/65.5;
  RateYaw=(float)GyroZ/65.5;
}

void setup() {
  Serial.begin(9600); 
  Wire.setClock(400000);
  Wire.begin();
  delay(250);
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
  for(RateCalibrationNumber=0;RateCalibrationNumber<2000;RateCalibrationNumber++){
    gyro_signals();
    RateCalibrationRoll+=RateRoll;
    RateCalibrationPitch+=RatePitch;
    RateCalibrationYaw+=RateYaw;
    delay(1);
  }
  RateCalibrationRoll/=2000;
  RateCalibrationPitch/=2000;
  RateCalibrationYaw/=2000;
}

void loop() {
  delay(50);
  
  int distance1 = sonar1.ping_cm();
  int distance2 = sonar2.ping_cm();
  int distance3 = sonar3.ping_cm();

  Serial.print(distance1);
  Serial.print(",");
  Serial.print(distance2);
  Serial.print(",");
  Serial.print(distance3);
  Serial.print(",");

  gyro_signals();
  RateRoll-=RateCalibrationRoll;
  RatePitch-=RateCalibrationPitch;
  RateYaw-=RateCalibrationYaw;

  Serial.print(RateRoll);
  Serial.print(",");
  Serial.print(RatePitch);
  Serial.print(",");
  Serial.println(RateYaw);

}
