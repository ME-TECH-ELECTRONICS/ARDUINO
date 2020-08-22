#include<LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int B=13;
float D,Di=0;
void setup() 
{
  lcd.init();
  lcd.backlight();
  pinMode(B,OUTPUT); 
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("ME TECH");
  lcd.setCursor(3,1);
  lcd.print("D/C TESTER");
  delay(2000);
}
void loop() 
{
 
 D=analogRead(A0);
 Di = D* (5.0/1023.0);
 if(Di>0.08)
 {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Diode");
  lcd.setCursor(0,1);
  lcd.print(Di);
  lcd.print("V");
  delay(200);
 }
 else
 {
  byte buzzer [8]=
  {
   0b00001,
   0b00011,
   0b01111,
   0b01111,
   0b01111,
   0b00011,
   0b00001,
   0b00000
  };
  byte sound [8]=
  {
   0b00000,
   0b00100,
   0b00010,
   0b10010,
   0b10010,
   0b00010,
   0b00100,
   0b00000
  };
  lcd.createChar(1,buzzer);
  lcd.createChar(2,sound);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Continuity");
  lcd.setCursor(1,1);
  lcd.print("Yes");
  lcd.write(byte(1));
  lcd.write(byte(2));
  if(D<0.02)
  {
   digitalWrite(B,HIGH);
   delay(500);
   digitalWrite(B,LOW);
  }
  else
  {
   digitalWrite(B,LOW);
  }
 }
}
