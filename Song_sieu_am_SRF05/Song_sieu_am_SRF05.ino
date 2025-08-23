#include <NewPing.h>

#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  unsigned int uS = sonar.ping();
  Serial.print("Distance: ");
  Serial.print(uS/US_ROUNDTRIP_CM);
  Serial.println("cm");
}
