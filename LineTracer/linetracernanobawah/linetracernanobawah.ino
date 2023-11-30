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

void setup() {
  Serial.begin(9600); 
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
  Serial.println(distance3);
}
