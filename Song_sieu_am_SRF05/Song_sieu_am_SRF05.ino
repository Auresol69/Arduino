#include <LiquidCrystal_I2C.h>

#define TRIGGER_PIN 8
#define ECHO_PIN 7
#define MAX_DISTANCE 400

unsigned long thoigian;
int khoangcach;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Gửi một xung kích hoạt (trigger)
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Đo thời gian sóng âm đi và về
  thoigian = pulseIn(ECHO_PIN, HIGH);

  // Tính toán khoảng cách (cm)
  // Chia cho 58 là hằng số chuyển đổi từ microgiây sang cm
  khoangcach = thoigian / 58;

  // Hiển thị khoảng cách, chỉ khi nó hợp lệ
  if (khoangcach > MAX_DISTANCE || khoangcach == 0) {
    Serial.println("Vượt quá giới hạn hoặc lỗi cảm biến");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Error!");
  } else {
    Serial.print("Distance: ");
    Serial.print(khoangcach);
    Serial.println("cm");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distance: ");
    lcd.print(khoangcach);
    lcd.print("cm");
  }

  delay(1000);
}