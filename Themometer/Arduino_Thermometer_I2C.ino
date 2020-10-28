#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("ARDUINO");
  lcd.setCursor(2,1);
  lcd.print("THERMOMETER");
  delay(1000);
  byte degree_symbol[8] =
  {
    0b00111,
    0b00101,
    0b00111,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
  };
  lcd.createChar(1, degree_symbol);
}
void loop() {
  lcd.clear();
  float val=analogRead(A0);
  float temp=val*(5.0/1023.0)*85;
  lcd.setCursor(2,0);
  lcd.print("THERMOMETER");
  lcd.setCursor(0,1);
  lcd.print("T=");
  lcd.print(temp);
  lcd.write(1);
  lcd.print("C");
  delay(1000);
}
