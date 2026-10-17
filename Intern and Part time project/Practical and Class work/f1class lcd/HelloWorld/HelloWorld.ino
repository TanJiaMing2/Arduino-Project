
// I2C library:
#include <LiquidCrystal_I2C.h>


// I2C: use the line below
// Parameters: LCD address, number of columns = 16, and the number of rows = 2
LiquidCrystal_I2C lcd(0x27, 16, 4);

void setup() {
  // Normal begin statement for LCD requiring the number of columns and rows:
  lcd.init();                     // Direct wire statement

  // I2C: Turn on the blacklight
  lcd.backlight();
  
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {

}
