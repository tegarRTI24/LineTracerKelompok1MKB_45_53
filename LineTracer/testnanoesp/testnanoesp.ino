#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

SoftwareSerial nanoSerial(10, 11);  // RX, TX
const char* ssid = ".";
const char* password = "11242003";
const char* mqtt_server = "broker.hivemq.com";
const char* mqtt_topic1 = "sensornilai1";
const char* mqtt_topic2 = "sensornilai2";
const char* mqtt_topic3 = "sensornilai3";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(9600);
  nanoSerial.begin(9600);

  connectToWiFi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  // Baca nilai sensor yang dikirim dari Arduino Nano melalui Software Serial
  if (nanoSerial.available() > 0) {
    String data = nanoSerial.readStringUntil('\n');
    int d1 = data.substring(0, data.indexOf(',')).toInt();
    int d2 = data.substring(data.indexOf(',') + 1, data.lastIndexOf(',')).toInt();
    int d3 = data.substring(data.lastIndexOf(',') + 1).toInt();
//    int d1,d2,d3;
    // Kirim nilai sensor ke broker MQTT untuk tiga topik yang berbeda
    sendSensorDataToMQTT(mqtt_topic1, d1);
    sendSensorDataToMQTT(mqtt_topic2, d2);
    sendSensorDataToMQTT(mqtt_topic3, d3);
  }

  // Menerima pesan dari MQTT dan melakukan operasi lainnya
  client.loop();
}

void connectToWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
}

void sendSensorDataToMQTT(const char* topic, int value) {
  // Kirim nilai sensor ke topik MQTT
  String payload = String(value);
  
  if (!client.connected()) {
    reconnectMQTT();
  }

  client.publish(topic, payload.c_str());
}

void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP01Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }
}
