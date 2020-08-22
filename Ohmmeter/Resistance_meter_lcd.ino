#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int res_scale = 0;
bool but_state = true;
int button = 12; //connect push button pin 12
int res_2_2k = 8; //connect resistor 2.2K pin 8
int res_22k = 9; //connect resistor 22K pin 9
int res_560k = 10; //connect resistor 560K pin 10
int res_1M = 11; //connect resistor 1M pin 11
float R1=0;
float R2=0;
float R=0;
int R3=0;
int mode = 0;
int analog=A2;
int Res_2_2k_value=2199;        //2.2K resistor actual value
int Res_22k_value =22009;      //22K resistor actual value
int Res_560k_value =560.89;   //560K resistor actual value
int Res_1M_value=988.20;     //1M resistor actual value

void setup() 
{
 pinMode(button,INPUT);
 delay(100);
 lcd.clear();
 lcd.begin(16,2);
 lcd.setCursor(5,0);
 lcd.print("ARDUINO");
 lcd.setCursor(0,1);
 lcd.print("RESISTANCE METER");
 delay(2000); 
 
}
void loop() 
{
 if(!digitalRead(button) && but_state)
  {
    res_scale = res_scale + 1;
    but_state = false;
    if(res_scale > 3)
    {
      res_scale=0;
    }
   }
 if(digitalRead(button) && !but_state)
  {
    but_state = true;
  }
 byte ohm [8]=
  {
    0b00000,
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b01010,
    0b11011,
    0b00000
  };
  lcd.createChar(0,ohm);
  R2=analogRead(analog);
  R1=(R2*5)/1024; 
  if(res_scale == 0)
 {  
  pinMode(res_2_2k,OUTPUT);
  pinMode(res_22k,INPUT);
  pinMode(res_560k,INPUT);
  pinMode(res_1M,INPUT);
  digitalWrite(res_2_2k,LOW);
  R=Res_2_2k_value*((5/R1)-1);
  if(R<1000)
  {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("OHMMETER");
   lcd.setCursor(8,0);
   lcd.print("|");
   lcd.setCursor(10,0);
   lcd.print("SCALE");
   lcd.setCursor(8,1);
   lcd.print("|");
   lcd.setCursor(10,1);
   lcd.print("0-2.2K");
   lcd.setCursor(0,1);
   lcd.print(R);
   lcd.write(byte(0));
   delay(500);
  }
  else if(R<2200)
  {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("OHMMETER");
   lcd.setCursor(8,0);
   lcd.print("|");
   lcd.setCursor(10,0);
   lcd.print("SCALE");
   lcd.setCursor(8,1);
   lcd.print("|");
   lcd.setCursor(10,1);
   lcd.print("0-2.2K");
   lcd.setCursor(0,1);
   lcd.print(R/1000);
   lcd.print("K");
   lcd.write(byte(0));
   delay(500);
  }
  else
  {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("OHMMETER");
   lcd.setCursor(8,0);
   lcd.print("|");
   lcd.setCursor(10,0);
   lcd.print("SCALE");
   lcd.setCursor(8,1);
   lcd.print("|");
   lcd.setCursor(10,1);
   lcd.print("0-2.2K");
   lcd.setCursor(0,1);
   lcd.print(">2000");
   delay(500);
  }
 }
 if(res_scale == 1)
 {
  pinMode(res_2_2k,INPUT);
  pinMode(res_22k,OUTPUT);
  pinMode(res_560k,INPUT);
  pinMode(res_1M,INPUT);
  digitalWrite(res_22k,LOW);
  R=Res_22k_value*((5/R1)-1);
  
  if(R<22000)
  {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("OHMMETER");
   lcd.setCursor(9,0);
   lcd.print("|");
   lcd.setCursor(11,0);
   lcd.print("SCALE");
   lcd.setCursor(9,1);
   lcd.print("|");
   lcd.setCursor(11,1);
   lcd.print("2-22K");
   lcd.setCursor(0,1);
   lcd.print(R/1000);
   lcd.print("K");
   lcd.write(byte(0));
   delay(500);
  }
  else
  {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("OHMMETER");
   lcd.setCursor(9,0);
   lcd.print("|");
   lcd.setCursor(11,0);
   lcd.print("SCALE");
   lcd.setCursor(9,1);
   lcd.print("|");
   lcd.setCursor(11,1);
   lcd.print("2-22K");
   lcd.setCursor(0,1);
   lcd.print(">22K");
   delay(500);
  }
 }
 if(res_scale == 2)
 {
  pinMode(res_2_2k,INPUT);
  pinMode(res_22k,INPUT);
  pinMode(res_560k,OUTPUT);
  pinMode(res_1M,INPUT);
  digitalWrite(res_560k,LOW);
  R=Res_560k_value*((5/R1)-1);
  if(R<560)
  {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("OHMMETER");
   lcd.setCursor(8,0);
   lcd.print("|");
   lcd.setCursor(10,0);
   lcd.print("SCALE");
   lcd.setCursor(8,1);
   lcd.print("|");
   lcd.setCursor(9,1);
   lcd.print("22-560K");
   lcd.setCursor(0,1);
   lcd.print(R);
   lcd.print("K");
   lcd.write(byte(0));
   delay(500);
  }
  else
  {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("OHMMETER");
   lcd.setCursor(8,0);
   lcd.print("|");
   lcd.setCursor(10,0);
   lcd.print("SCALE");
   lcd.setCursor(8,1);
   lcd.print("|");
   lcd.setCursor(9,1);
   lcd.print("22-560K");
   lcd.setCursor(0,1);
   lcd.print(">560K");
   delay(500);
  }
 }
 if(res_scale == 3)
 {
  pinMode(res_2_2k,INPUT);
  pinMode(res_22k,INPUT);
  pinMode(res_560k,INPUT);
  pinMode(res_1M,OUTPUT);
  digitalWrite(res_1M,LOW);
  R=Res_1M_value*((5/R1)-1);
  
 if(R<1000)
  {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("OHMMETER");
   lcd.setCursor(8,0);
   lcd.print("|");
   lcd.setCursor(10,0);
   lcd.print("SCALE");
   lcd.setCursor(8,1);
   lcd.print("|");
   lcd.setCursor(9,1);
   lcd.print("560K-1M");
   lcd.setCursor(0,1);
   lcd.print(R);
   lcd.print("K");
   lcd.write(byte(0));
   delay(500);
  }
 else
 {
  lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("OHMMETER");
   lcd.setCursor(8,0);
   lcd.print("|");
   lcd.setCursor(10,0);
   lcd.print("SCALE");
   lcd.setCursor(8,1);
   lcd.print("|");
   lcd.setCursor(9,1);
   lcd.print("560K-1M");
   lcd.setCursor(0,1);
   lcd.print(">1M");
   delay(500);
 }
 } 
}
