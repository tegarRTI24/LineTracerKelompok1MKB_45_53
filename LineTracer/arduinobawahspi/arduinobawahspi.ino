#include <SPI.h>
#include <NewPing.h>
#define TRIGGER_PIN 5
#define ECHO_PIN 4
#define TRIGGER_PIN2 7
#define ECHO_PIN2 6
#define TRIGGER_PIN3 3
#define ECHO_PIN3 2
#define MAX_DISTANCE 200

#include <Wire.h>

float RateRoll, RatePitch, RateYaw;
float RateCalibrationRoll, RateCalibrationPitch, RateCalibrationYaw;
int RateCalibrationNumber;

void setup() {
  Serial.begin(9600);
  Wire.setClock(400000);
  Wire.begin();
  delay(250);
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
  for (RateCalibrationNumber = 0; RateCalibrationNumber < 2000; RateCalibrationNumber++) {
    gyro_signals();
    RateCalibrationRoll += RateRoll;
    RateCalibrationPitch += RatePitch;
    RateCalibrationYaw += RateYaw;
    delay(1);
  }
  RateCalibrationRoll /= 2000;
  RateCalibrationPitch /= 2000;
  RateCalibrationYaw /= 2000;

  // Initialize SPI
  SPI.begin();
}

void loop() {
  delay(50);

  int distance1 = getDistance(TRIGGER_PIN, ECHO_PIN);
  int distance2 = getDistance(TRIGGER_PIN2, ECHO_PIN2);
  int distance3 = getDistance(TRIGGER_PIN3, ECHO_PIN3);

  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  SPI.transfer(distance1 >> 8);
  SPI.transfer(distance1 & 0xFF);

  SPI.transfer(distance2 >> 8);
  SPI.transfer(distance2 & 0xFF);

  SPI.transfer(distance3 >> 8);
  SPI.transfer(distance3 & 0xFF);

  SPI.endTransaction();

  gyro_signals();
  RateRoll -= RateCalibrationRoll;
  RatePitch -= RateCalibrationPitch;
  RateYaw -= RateCalibrationYaw;

  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  SPI.transfer(RateRoll);
  SPI.transfer(RatePitch);
  SPI.transfer(RateYaw);

  SPI.endTransaction();
}

int getDistance(int triggerPin, int echoPin) {
  NewPing sonar(triggerPin, echoPin, MAX_DISTANCE);
  return sonar.ping_cm();
}

void gyro_signals(void) {
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
  Wire.requestFrom(0x68, 6);
  int16_t GyroX = Wire.read() << 8 | Wire.read();
  int16_t GyroY = Wire.read() << 8 | Wire.read();
  int16_t GyroZ = Wire.read() << 8 | Wire.read();
  RateRoll = (float)GyroX / 65.5;
  RatePitch = (float)GyroY / 65.5;
  RateYaw = (float)GyroZ / 65.5;
}
