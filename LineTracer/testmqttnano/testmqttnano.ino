#include <SoftwareSerial.h>

// Konfigurasi koneksi serial
SoftwareSerial espSerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  if(Serial.available()){
    char ser=Serial.read();

    switch (ser){
      case '0':
        digitalWrite(LED_BUILTIN,LOW);
        break;
      case '1':
        digitalWrite(LED_BUILTIN,HIGH);
        break;
    }
  }
}
