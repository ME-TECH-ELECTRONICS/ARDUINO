#include <LiquidCrystal.h> 
LiquidCrystal lcd(4,5,6,7,8,9);//RS=D4,E=D5,DB4=D6,DB4=D7,DB4=D8,DB4=D9

//Global variables//
double pulse, frequency, inductance;
float cap_val = 0.22E-6; //Insert capacitor value here.(220E-9 = 220nF)
#define oscillate_in  3// Oscillation reading pin
#define pulse_induct  2// Inductor pulsing pin

void setup() {
  pinMode(pulse_induct,OUTPUT);// Make D2 pin as output
  pinMode(oscillate_in,INPUT);// Make D# pin as input
  lcd.begin(16,2);                 // Initialize LCD display
  lcd.setCursor(3,0);
  lcd.print("INDUCTANCE");
  lcd.setCursor(5,1);
  lcd.print("METER");
  delay(2000);
  
}
void loop() {
   lcd.clear();
   digitalWrite(pulse_induct, HIGH);
   delay(5);//give some time to charge inductor.
   digitalWrite(pulse_induct,LOW);
   delayMicroseconds(100); //make sure resonation is measured
   pulse = pulseIn(oscillate_in,HIGH,5000);//returns 0 if timeout
   if(pulse > 0.1) {
    frequency = 1E6/(2*pulse);
    inductance = 1/(cap_val*frequency*frequency*4.*3.14159*3.14159);
    inductance *= 1E6;
    if(frequency >= 1000) {
      lcd.setCursor(0,0);
      lcd.print("Fr=");
      lcd.setCursor(3,0);
      lcd.print(frequency/1000);
      lcd.print("KHz");
    }
    else {
      lcd.setCursor(0,0);
      lcd.print("Fr=");
      lcd.setCursor(3,0);
      lcd.print(frequency);
      lcd.print("Hz");
    }
    if(inductance >= 1000) {
      lcd.setCursor(0,1);
      lcd.print("L=");
      lcd.setCursor(2,1);
      lcd.print(inductance/1000);
      lcd.print("mH");  
      delay(500);
    }
    else{
      lcd.setCursor(0,1);
      lcd.print("L=");
      lcd.setCursor(2,1);
      lcd.print(inductance);
      lcd.print("uH");  
      delay(500);
    }      
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
    delay(500); 
   }
}
