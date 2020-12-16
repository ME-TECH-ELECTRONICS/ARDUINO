#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);// sometimes the address will be 0x3F

//Global variables//
double pulse, frequency, inductance;
float cap_val = 220E-9; //Insert capacitor value here.(220E-9 = 220nF)
#define oscillate_in  3// Oscillation reading pin
#define pulse_induct  2// Inductor pulsing pin

void setup() {
  pinMode(pulse_induct,OUTPUT);// Make D2 pin as output
  pinMode(oscillate_in,INPUT);// Make D# pin as input
  lcd.init();                 // Initialize LCD display
  lcd.backlight();            // comment to turn off the backlight of LCD
  lcd.setCursor(3,0);
  lcd.print("INDUCTANCE");
  lcd.setCursor(5,1);
  lcd.print("METER");
  delay(2000);

}
void loop() {
   digitalWrite(pulse_induct, HIGH);
   delay(5);//give some time to charge inductor.
   digitalWrite(pulse_induct,LOW);
   delayMicroseconds(100); //make sure resonation is measured
   pulse = pulseIn(oscillate_in,HIGH,5000);//returns 0 if timeout
   if(pulse > 0.1) {
    frequency = 1E6/(2*pulse);
    inductance = 1/(cap_val*frequency*frequency*4.*3.14159*3.14159);
    inductance *= 1E6;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Fr=");
    lcd.setCursor(3,0);
    lcd.print(frequency);
    lcd.print("Hz");
    lcd.setCursor(3,1);
    lcd.print(inductance);
    lcd.setCursor(0,1);
    lcd.print("L=");
    lcd.print("uH");
    delay(250);
   }
   else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Fr=");
    lcd.setCursor(3,0);
    lcd.print("0.00Hz");
    lcd.setCursor(0,1);
    lcd.print("L=");
    lcd.setCursor(2,1);
    lcd.print("0.00uH");
    delay(250);
   }
}
