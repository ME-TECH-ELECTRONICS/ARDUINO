#include <LiquidCrystal.h> //LCD library
LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  lcd.begin(16,2);//Initialise the lcd desplay
  lcd.setCursor(0,0);
  lcd.print("ARDUINO");
  lcd.setCursor(4,1);
  lcd.print("VOLTMETER");
}
void loop() {
  float sensorValue = analogRead(A0);
  float voltage = ((sensorValue*5)/1024)*11.25;//11.25 is the calibration value for geting actual value.
                                                                                           // enter your calibration value here.
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("VOLTMETER");
  lcd.setCursor(0,1);
  lcd.print("Voltage=");
  lcd.print(voltage);
  lcd.print("V");
}
