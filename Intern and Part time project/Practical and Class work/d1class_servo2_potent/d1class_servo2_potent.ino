#include <Servo.h>
Servo myservo;
int analogVal;
int pos=0;
const int potPin = A0;

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
}

void loop() {

  // put your main code here, to run repeatedly:

analogVal= analogRead (potPin);
pos = analogVal / 1023.0*180.0;
myservo.write(pos);
  delay(15);
  
}
