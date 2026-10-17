

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte customChar[] = {
  B00001,
  B00011,
  B00011,
  B11001,
  B10101,
  B10011,
  B00111,
  B00111
};

byte customChar1[] = {
  B10100,
  B11010,
  B11000,
  B10011,
  B10101,
  B11001,
  B11100,
  B11100
};
byte customChar2[] = {
  B00111,
  B00111,
  B00111,
  B00111,
  B00111,
  B00000,
  B00000,
  B00000
};

byte customChar3[] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B00000,
  B00000,
  B00000
};

byte customChar4[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte customChar5[] = {
  B01110,
  B11111,
  B00111,
  B00011,
  B11111,
  B01111,
  B00111,
  B00011
};

byte customChar6[] = {
  B11100,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B10110,
  B10010
};

byte customChar7[] = {
  B00000,
  B00000,
  B01000,
  B11100,
  B11110,
  B00011,
  B00111,
  B00111
};
byte customChar8[] = {
  B00011,
  B00111,
  B01111,
  B01111,
  B01111,
  B11111,
  B11111,
  B11111
};
byte customChar9[] = {
  B11000,
  B11000,
  B11100,
  B11100,
  B11110,
  B11110,
  B11111,
  B11110
};
void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();
  lcd.createChar(0, customChar);
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);

  lcd.createChar(4, customChar4);
  lcd.createChar(5, customChar5);
  lcd.createChar(6, customChar6);
  lcd.createChar(7, customChar7);

       
  lcd.home();
  lcd.setCursor(0, 0);  
  lcd.write(0);
  lcd.setCursor(1, 0);
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.write(2);
  lcd.setCursor(1, 1);
  lcd.write(3);

  lcd.setCursor(6, 0);
  lcd.write(4);
  lcd.setCursor(7, 0);
  lcd.write(5);
  lcd.setCursor(8, 0);
  lcd.write(6);
  lcd.setCursor(6, 1);
  lcd.write(7);

    // lcd.createChar(7, customChar8);
  // lcd.createChar(8, customChar9);

  // lcd.setCursor(7, 1);
  // lcd.write(8);
  // lcd.setCursor(8, 1);
  // lcd.write(9);
}

void loop()
{

}