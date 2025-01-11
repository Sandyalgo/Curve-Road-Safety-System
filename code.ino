#include <LiquidCrystal.h>

LiquidCrystal lcd(8,7,4,3,2,1);
const int trigpin = 9;
const int echopin = 10;
const int buzzerpin = 11;
const int ledpin = 13;
const int ledpin2 = 5;

long duration;
int distance;
void setup()
{
  	lcd.begin(16,2);
  	pinMode(trigpin,OUTPUT);
  	pinMode(echopin,INPUT);
  	pinMode(buzzerpin,OUTPUT);
  	pinMode(ledpin,OUTPUT);
  	pinMode(ledpin2,OUTPUT);
}

void loop()
{
	digitalWrite(trigpin,LOW);
  	delayMicroseconds(2);
  	digitalWrite(trigpin,HIGH);
  	delayMicroseconds(10);
  	digitalWrite(trigpin,LOW);
  
  	duration = pulseIn(echopin,HIGH);
  
  	distance = duration * 0.0343/2;
  	
  	if(distance>150){
      lcd.setCursor(0,0);
      lcd.print("You are Safe!");
      lcd.setCursor(0,1);
      lcd.print("Distance:");
      lcd.print(distance);
      lcd.print("cm  ");
      digitalWrite(buzzerpin,LOW);
      digitalWrite(ledpin,LOW);
      digitalWrite(ledpin2,LOW);
      delay(100);
      
  	}

  	if(distance<=150 && distance>=50){
      lcd.setCursor(0,0);
      lcd.print("warning!     ");
      lcd.setCursor(0,1);
      lcd.print("Distance:");
      lcd.print(distance);
      lcd.print("cm  ");
      digitalWrite(buzzerpin,LOW);
      digitalWrite(ledpin,LOW);
      digitalWrite(ledpin2,HIGH);
      delay(100);
  	}

  	if(distance<=50){
      lcd.setCursor(0,0);
      lcd.print("Caution!     ");
      lcd.setCursor(0,1);
      lcd.print("Distance:");
      lcd.print(distance);
      lcd.print("cm  ");
      tone(buzzerpin,2000);
      delay(100);
      noTone(buzzerpin);
      digitalWrite(ledpin,HIGH);
      digitalWrite(ledpin2,LOW);
      delay(50);
  	}
}
