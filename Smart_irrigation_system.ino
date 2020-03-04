#include <LiquidCrystal_I2C.h> //LCD I2C liberary 
                                              
#include <Wire.h> //wire library 

LiquidCrystal_I2C lcd(0x27, 16, 2); 
int Ricepump = 4; //pin number of rice pump
int Wheatpump = 8;//pin number of wheat pump 
void setup()
{
  Serial.begin(9600);
  pinMode(Ricepump,OUTPUT);//declaring rice pump as output 
  pinMode(Wheatpump,OUTPUT);//declaring wheat pump as output
  lcd.begin();   
  lcd.backlight(); 
}
void loop()
{
  int S1= analogRead(A0);//declaring sensor 1 pin
  int S2= analogRead(A2);//declaring sensor 2 pin
  Serial.print(S1);    
  Serial.print(" - ");
  Serial.print(S2);    
  Serial.print(" - ");
  if(S1>=1000 && S2>=1000)//when both sensor are not in soil
  {
    lcd.setCursor(0,0);
    lcd.print("Rice=Not in soil");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Not in soil");
    digitalWrite(Ricepump,LOW);
    digitalWrite(Wheatpump,LOW);
  }
    if((S1 < 1000 && S1>=800)&&(S2 < 1000 && S2>=800))//when both sensor indicates dry soil
  {
    lcd.setCursor(0,0);
    lcd.print("Rice=Dry        ");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Dry       ");
    digitalWrite(Ricepump,HIGH);
    digitalWrite(Wheatpump,HIGH);
  }
    if((S1 <800 && S1 >=370)&&(S2 <800 && S2 >=370))//when both sensor indicates humid soil
  {
    lcd.setCursor(0,0);
    lcd.print("Rice=Humid        ");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Humid       ");
    digitalWrite(Ricepump,LOW);
    digitalWrite(Wheatpump,LOW);
  }
  if((S1 < 370)&&(S2 < 370))//when both sensor indicates water 
  {
    lcd.setCursor(0,0);
    lcd.print("Rice=Water");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Water");
    digitalWrite(Ricepump,LOW);
    digitalWrite(Wheatpump,LOW);
  }
  else if((S1 >=1000) && (S2 <1000 && S2 >=800))//when one sensor is not in soil and another indicates dry soil 
  {
    lcd.setCursor(0,0);
    lcd.print("Rice=Not in soil");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Dry       ");
    digitalWrite(Wheatpump,HIGH);
    digitalWrite(Ricepump,LOW);
  }
  else if((S1 >=1000)&& (S2 < 800 && S2 >=370))//when one sensor is not in soil and another indicates humid soil
  {
    lcd.setCursor(0,0);
    lcd.print("Rice=Not in soil");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Humid      ");
    digitalWrite(Ricepump,LOW);
    digitalWrite(Wheatpump,LOW);
  }
  else if((S1 >=1000) && (S2 < 370))//when one sensor is not in soil and another indicates water
  {
     lcd.setCursor(0,0);
    lcd.print("Rice=Not in soil");
    lcd.setCursor(0,1);
    lcd.print("Wheat=water      ");
    digitalWrite(Ricepump,LOW);
    digitalWrite(Wheatpump,LOW);
  }
  else if((S1 < 1000 && S1 >=800) && (S2 >=1000))//when one sensor indicates dry soil and another sensor is not in soil
  {
     lcd.setCursor(0,0);
     lcd.print("Rice=Dry        ");
     lcd.setCursor(0,1);
     lcd.print("Wheat=Not in soil");
     digitalWrite(Ricepump,HIGH);
    digitalWrite(Wheatpump,LOW);
  }
  else if((S1 < 1000 && S1 >=800) && (S2 < 800 && S2 >=370))//when one sensor indicates dry soil and another sensor indicates humid soil
  {
     lcd.setCursor(0,0);
    lcd.print("Rice=Dry        ");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Humid     ");
    digitalWrite(Ricepump,HIGH);
    digitalWrite(Wheatpump,LOW);
  }
  else if((S1 < 1000 && S1 >=800) && (S2 < 370))//when one sensor indicates dry soil and another sensor indicates water
  {
     lcd.setCursor(0,0);
    lcd.print("Rice=Dry         ");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Water      ");
    digitalWrite(Ricepump,HIGH);
    digitalWrite(Wheatpump,LOW);
  }
  else if((S1 < 800 && S1 >=370) && (S2 >=1000))//when one sensor indicates humid soil and another sensor is not in soil
  {
     lcd.setCursor(0,0);
    lcd.print("Rice=Humid       ");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Not in soil");
    digitalWrite(Ricepump,LOW);
    digitalWrite(Wheatpump,LOW);
  }
  else if((S1 <800 && S1 >=370) && (S2 < 1000 && S2 >=800))//when one sensor indicates humid soil and another sensor indicates dry soil
  {
     lcd.setCursor(0,0);
    lcd.print("Rice=Humid      ");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Dry      ");
    digitalWrite(Wheatpump,HIGH);
    digitalWrite(Ricepump,LOW);
  }
  else if((S1 <800 && S1 >=370) && (S2 < 370))//when one sensor indicates humid soil and another sensor indicates water
  {
     lcd.setCursor(0,0);
    lcd.print("Rice=Humid      ");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Water      ");
    digitalWrite(Ricepump,LOW);
    digitalWrite(Wheatpump,LOW);
  }
  else if((S1 < 370) && (S2 >=1000))//when one sensor indicates water and another sensor is not in soil
  {
     lcd.setCursor(0,0);
    lcd.print("Rice=Water      ");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Not in Soil");
    digitalWrite(Ricepump,LOW);
    digitalWrite(Wheatpump,LOW);
  }
  else if((S1 < 370) && (S2 < 1000 && S2 >=800))//when one sensor indicates water and another sensor indicates dry soil
  {
     lcd.setCursor(0,0);
    lcd.print("Rice=Water      ");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Dry       ");
    digitalWrite(Wheatpump,HIGH);
    digitalWrite(Ricepump,LOW);
  }
  else if((S1 < 370) && (S2 < 800 && S2 >=370))//when one sensor indicates water and another sensor indicates humid soil
  {
     lcd.setCursor(0,0);
    lcd.print("Rice=Water      ");
    lcd.setCursor(0,1);
    lcd.print("Wheat=Humid      ");
    digitalWrite(Ricepump,LOW);
    digitalWrite(Wheatpump,LOW);
  }
  }
  
