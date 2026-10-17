#include <IRremote.h>
const int RECU_PIN=6;
IRrecv irrecv(RECU_PIN);
decode_results results;
#define buzz_p 3
#define button_p 2

void setup() {
  // put your setup code here, to run once:
    pinMode(buzz_p, OUTPUT);
  pinMode(button_p, INPUT_PULLUP);
Serial.begin(9600);
irrecv.enableIRIn();
irrecv.blink13(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results))
  {Serial.println(results.value,HEX);
  irrecv.resume();}

    int buttonState = digitalRead(button_p);
  if (buttonState == LOW) {
    // Button is pressed, play the tone
    tone(buzz_p, 1000);
  } else {
    // Button is released, stop the tone
    noTone(buzz_p);
}
}
