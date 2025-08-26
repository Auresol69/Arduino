#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  unsigned int uS = sonar.ping();
  Serial.print("Distance: ");
  Serial.print(uS/US_ROUNDTRIP_CM);
  Serial.println("cm");
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print("            ");
  lcd.setCursor(9, 1);
  lcd.print(uS/US_ROUNDTRIP_CM);
  lcd.setCursor(12, 1);
  lcd.print("cm");
}
