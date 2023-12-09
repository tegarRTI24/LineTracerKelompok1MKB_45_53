#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char *ssid = ".";
const char *password = "11242003";
const char *mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
#include <SoftwareSerial.h>
WiFiClient espClient;
PubSubClient client(espClient);
SoftwareSerial espserial(10,11);//rx,tx
const char *mqttTopic = "tegarrrrrr";

void setup() {
  Serial.begin(9600);
  espserial.begin(9600);
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Setup MQTT
  client.setServer(mqttServer, mqttPort);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
//  if (espserial.available()) {
//    String data = Serial.readStringUntil('\n');
//    int distance1 = data.substring(0, data.indexOf(',')).toInt();
//    int distance2 = data.substring(data.indexOf(',') + 1, data.lastIndexOf(',')).toInt();
//    int distance3 = data.substring(data.lastIndexOf(',') + 1).toInt();
//    String di1 = String(distance1);
//    String di2 = String(distance2);
//    String di3 = String(distance3);
//    // Publish data to MQTT topic
    int da1 =0;
    int da2 =0;
    int da3 =0;
    String di1 = String(da1);
    String di2 = String(da2);
    String di3 = String(da3);
    client.publish(mqttTopic, di1.c_str());
    client.publish(mqttTopic, di2.c_str());
    client.publish(mqttTopic, di3.c_str());

    delay(100);  // Send every 0.1 seconds
//  }
}

void reconnect() {
  // Loop until reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("esp01-client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
