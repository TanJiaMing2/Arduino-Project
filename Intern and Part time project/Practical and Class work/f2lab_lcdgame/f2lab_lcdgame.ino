#include <Wire.h>

// C++ code
//
#include <LiquidCrystal_I2C.h>

int ground = 0;

int buttonpressed = 0;
LiquidCrystal_I2C lcd_1(0x27, 16, 2);

byte customChar[] = {
  B00000,
  B00100,
  B00110,
  B01110,
  B01110,
  B00110,
  B01111,
  B11111
};

byte block[] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B10101,
  B11011,
  B10101,
  B11111
};
void setup()
{
lcd_1.init();
lcd_1.backlight();
  lcd_1.home();
  pinMode(3, INPUT);
}

void loop()
  
{
   //lcd_1.setBacklight(1);
    lcd_1.createChar(0,customChar);

    lcd_1.createChar(1,block);
  

  
  for (ground =15; ground >=-1; ground-=1)
  
  {
    
      if (digitalRead(3) ==HIGH)
  {
    buttonpressed=0;
  }else{
    
    buttonpressed=1;
  }
        lcd_1.clear();
        lcd_1.setCursor(ground, 1);
        lcd_1.write(0);
    
        lcd_1.setCursor(4, buttonpressed);
       	lcd_1.write(1);

    	delay(100);
    


  
  }
  

  
 

  

 
  
  //delay(100); // Delay a little bit to improve simulation performance
}