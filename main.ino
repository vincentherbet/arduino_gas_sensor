#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int set = 50;
int buzzer = 11, R_led = 12, G_led = 13, senserPin = A0;
void setup() {
  pinMode(G_led, OUTPUT);
  pinMode(R_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(senserPin, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   WELCOME To   ");
  lcd.setCursor(0, 1);
  lcd.print("  GAS Detector  ");
  delay(2000);
  lcd.clear();
}

void loop() {
  int gasVal = analogRead(senserPin);
  gasVal = gasVal - 50;
  if (gasVal < 0) {
    gasVal = 0;
  }

  lcd.setCursor(0, 0);
  lcd.print("Smoke Level: ");
  lcd.print(gasVal);
  lcd.print("  ");


  if (gasVal > 300) {
    lcd.setCursor(0, 1);
    lcd.print("Alert....!!!    ");
    digitalWrite(buzzer, HIGH);
    digitalWrite(R_led, HIGH);
    digitalWrite(G_led, LOW);
    delay(1000);
  }
  if (gasVal < 250) {
    lcd.setCursor(0, 1);
    lcd.print(".....Normal.....");
    digitalWrite(buzzer, LOW);
    digitalWrite(R_led, LOW);
    digitalWrite(G_led, HIGH);
  }
  delay(100);
}
