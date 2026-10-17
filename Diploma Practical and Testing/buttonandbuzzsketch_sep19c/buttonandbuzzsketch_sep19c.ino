#define buzz_p 5
#define button_p 6

void setup() {
  pinMode(buzz_p, OUTPUT);
  pinMode(button_p, INPUT_PULLUP); // Use INPUT_PULLUP to enable the internal pull-up resistor
}

void loop() {
  // Read the state of the button
  int buttonState = digitalRead(button_p);

  if (buttonState == LOW) {
    // Button is pressed, play the tone
    tone(buzz_p, 1000);
  } else {
    // Button is released, stop the tone
    noTone(buzz_p);
  }
}