const int potentiometerPin = A0; // Analog pin for potentiometer

const int ledPins[] = {2, 3, 4, 5, 6}; // Digital pins for the LEDs

void setup() {
  Serial.begin(9600); // Initialize the serial communication
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(9, OUTPUT);
}

void loop() {
  int potValue = analogRead(potentiometerPin);

  // Map the potentiometer value to the frequency range of the buzzer
  int frequency = map(potValue, 0, 1023, 100, 1000);

  // Control the LEDs based on potentiometer value
  for (int i = 0; i < 5; i++) {
    if (i * 204 < potValue) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  // Check if all LEDs are lit
  bool allLedsOn = true;
  for (int i = 0; i < 5; i++) {
    if (digitalRead(ledPins[i]) == LOW) {
      allLedsOn = false;
      break; // If any LED is off, exit the loop
    }
  }

  // If all LEDs are lit, make the buzzer produce sound
  if (allLedsOn) {
    tone(9, frequency);
  } else {
    noTone(9); // Turn off the buzzer if not all LEDs are lit
  }

  // Print the potentiometer value to the serial monitor
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);

  delay(100); // Add a short delay to control the rate of serial output
}