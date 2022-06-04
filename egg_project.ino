
#include <LiquidCrystal.h>

#include <DHT.h>

#include "DHT.h"
//LCD pin to Arduino
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 
LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);
int L= 7;
int F= 8;
#define DHTPIN A0     // what pin we're connected to

#define DHTTYPE DHT11   // we are using the DHT11 sensor


DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  for (int DigitalPin = 7; DigitalPin <= 8; DigitalPin++) 
 {
  pinMode(DigitalPin, OUTPUT);
 }
  lcd.begin(16,2);  //16 by 2 character display
  
dht.begin();
}
 
void loop()
{
  delay(1000);
  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  
  float t = dht.readTemperature();  // Read temperature as Celsius (the default)

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);  //printing temperarture to the LCD display


  lcd.print("'C");
  
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(h);  //printing humidity to the LCD display
  lcd.print("%");
  

//the 3-led setup process
  if (t>=37)
 
  {
  digitalWrite(L, LOW);
  digitalWrite(F, HIGH);
  }
  else if (t<37)
  {
  digitalWrite(L, HIGH );
  digitalWrite(F, LOW);
  } 
  if (h>=70)
  {
  digitalWrite(F, HIGH);
  digitalWrite(L, LOW);
  }
  else if (h<70)
  {
  digitalWrite(F, LOW);
  digitalWrite(L, HIGH );
  }
   
 }

  
