#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define sensorPin A0


void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
//clear screen every loop
lcd.clear();

// read from lm35 (temp)
int reading= analogRead(sensorPin);

//conver reading to volt

float voltage =reading* (5.0 /1024.0);

//convert volt to temp (C)

float tempF = voltage *100;
float tempC = (tempF-32) * 5/9;
//print temp in C

lcd.print("Temp: ");
lcd.print(tempC);

//print the degree symbol character

lcd.print((char)223);
lcd.print("C");

// a delay between reading

delay(1000);


}
