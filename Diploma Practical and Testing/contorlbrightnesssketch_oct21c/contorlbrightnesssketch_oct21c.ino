const int potentiometerPin = A0; // Analog pin for the potentiometer
const int ledPin = 9; // Digital pin for the LED
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 10}; // Digital pins for the 7-segment display
int brightnessLevels[] = {1, 10, 30, 45, 60, 80, 150, 175, 200, 255}; // Brightness levels for digits 0-9
int brightness = 0; // Initial LED brightness

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW); // Ensure all segments are initially off
  
  }
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int potValue = analogRead(potentiometerPin);
  int displayValue = map(potValue, 0, 1023, 0, 9); // Map potentiometer value to 0-9


  if (displayValue != brightness) {
    brightness = displayValue;
    updateDisplay(displayValue);
        analogWrite(ledPin, brightnessLevels[displayValue]);
  }



  // Print potentiometer value to the serial monitor
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);
}

void updateDisplay(int digit) {
  const byte digitPatterns[] = {
    B00111111, // 0
    B00000110, // 1
    B11011011, // 2
    B11001111, // 3
    B01100110, // 4
    B11101101, // 5
    B11111101, // 6
    B00000111, // 7
    B11111111, // 8
    B01101111  // 9
  };

  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(digitPatterns[digit], i));
  }
}