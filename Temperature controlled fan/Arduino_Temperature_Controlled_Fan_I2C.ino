#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int Plus_but=8;
int Minus_but=7;
int Fan=9;
bool Plus_state=true;
bool Minus_state=true;
int Count=25;
void setup() 
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("ARDUINO");
  lcd.setCursor(2,1);
  lcd.print("THERMOMETER");
  delay(1000);
  pinMode(Plus_but,INPUT_PULLUP);
  pinMode(Minus_but,INPUT_PULLUP);
  pinMode(Fan,OUTPUT);
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
  lcd.createChar(1,degree_symbol);
}
void loop() 
{
  lcd.clear();
  float val=analogRead(A0);
  float temp=val*(5.0/1023.0)*85;
  lcd.setCursor(0,0);
  lcd.print("T=");
  lcd.print(temp);
  lcd.write(1);
  lcd.print("C");
  if(!digitalRead(Plus_but)&&Plus_state)
  {
    Count++;
    lcd.setCursor(9,0);
    lcd.print("|S=");
    lcd.print(Count);
  }
  else if(!digitalRead(Minus_but)&&Minus_state)
  {
    Count--;
    lcd.setCursor(9,0);
    lcd.print("|S=");
    lcd.print(Count);
  }
  if(temp>=Count)
  {
    lcd.setCursor(9,0);
    lcd.print("|S=");
    lcd.print(Count);
    digitalWrite(Fan,HIGH);
    lcd.setCursor(0,1);
    lcd.print("FAN STATUS : ON");
  }
  else
  {
    lcd.setCursor(9,0);
    lcd.print("|S=");
    lcd.print(Count);
    digitalWrite(Fan,LOW);
    lcd.setCursor(0,1);
    lcd.print("FAN STATUS : OFF");
  }
  delay(500);
}
