#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// set the lcd address to 0x27 for a 16 characters and 2 line display

LiquidCrystal_I2C lcd(0x27,16,4);

void setup() {
  // put your setup code here, to run once:
lcd.init();

//turn on the backlight
//turn off the backlight with lcd.noBacklight()

lcd.backlight();
lcd.print("Hello, world!");
}

void loop() {
  // put your main code here, to run repeatedly:
// No program in loop
}
