#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
#define BUTTON_PIN 3

void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();
pinMode(BUTTON_PIN,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte buttonState=digitalRead(BUTTON_PIN);

  if (buttonState==HIGH)
  {
    lcd.clear();
    lcd.print("Button On");

  }else{
    lcd.clear();
    lcd.print("Button Off")
  }
delay(100);
}
