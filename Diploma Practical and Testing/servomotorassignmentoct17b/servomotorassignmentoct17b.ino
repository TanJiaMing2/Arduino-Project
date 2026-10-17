#include <Servo.h>
Servo servo1;
int pos = 0;
bool at180 = false;
void setup() {
  servo1.attach(7);
  pinMode(5,OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() {
if (!at180) {
    for (pos = 0; pos <= 180; pos += 1) {
      servo1.write(pos);
      delay(15);
      if (pos >= 180) {
        at180 = true;
   digitalWrite(5,HIGH);
   tone(6, 1000);
   delay(200);
   digitalWrite(5,LOW);
   delay(200);
   digitalWrite(5,HIGH);
   delay(200);
   digitalWrite(5,LOW);
   delay(200);
   digitalWrite(5,HIGH);
   delay(200);
   digitalWrite(5,LOW);
   delay(200);
   digitalWrite(5,HIGH);
   delay(200);
   digitalWrite(5,LOW);
   delay(200);
   digitalWrite(5,HIGH);
   delay(200);
   digitalWrite(5,LOW);
   noTone(6);
      }
      }
        } else {
    servo1.write(0);  // Return servo to 0 degrees
    at180 = false;  // Reset the flag
       delay(2000);
      }
}
  