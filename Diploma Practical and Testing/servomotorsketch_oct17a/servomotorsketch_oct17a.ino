# include <Servo.h>
# define buzz1 2
# define led 3

Servo servo1;


void setup() {
  // put your setup code here, to run once:
  servo1.attach(1); // pinmode

}

void loop() {
  // put your main code here, to run repeatedly:
  servo1.write(180); //rotate



}
