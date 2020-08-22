#include <LiquidCrystal_I2C.h>  //LCD display library
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();//Initialise the lcd display
  lcd.backlight();// To turn on lcd backlight
  lcd.setCursor(0,0);
  lcd.print("ARDUINO");
  lcd.setCursor(4,1);
  lcd.print("VOLTMETER");
}
void loop() {
  float sensorValue = analogRead(A0);
  float voltage = ((sensorValue*5)/1024)*11.25;//11.25 is the calibration for geting actual value.
                                                                                          // enter your calibration value here.
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("VOLTMETER");
  lcd.setCursor(0,1);
  lcd.print("Voltage=");
  lcd.print(voltage);
  lcd.print("V");
}
