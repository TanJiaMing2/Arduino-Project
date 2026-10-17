#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
#define BUTTON_PIN 3

byte lastButtonState=LOW;
int counter=0;

void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();
pinMode(BUTTON_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte buttonState=digitalRead(BUTTON_PIN);

  if (buttonState!=lastButtonState)
  {
    lastButtonState = buttonState;
    if(buttonState==LOW){
      lcd.clear();
      counter++;
      lcd.print("Counter: ");
      lcd.print(counter);
    }
  }
delay(100);
}
