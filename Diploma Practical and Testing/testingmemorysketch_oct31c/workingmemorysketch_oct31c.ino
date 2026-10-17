#include <IRremote.h>

int IR_PIN = 2;
IRrecv irrecv(IR_PIN);
decode_results results;

int displayPins[] = {5, 6, 7, 8, 9, 10, 11}; // pin segm
int gled = 3;
int rled = 4;
int sequenceLength = 2;
int potentpin = A0;
int previousPotValue = 0;
int maxSequenceLength = 6; // max sequence leng
int sequence[6];
int userInput;
int currentStep = 0;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  for (int i = 0; i < 7; i++) {
    pinMode(displayPins[i], OUTPUT);
  }
  pinMode(gled, OUTPUT);
  pinMode(rled, OUTPUT);
  delay(1000);
  randomSeed(analogRead(0));
  generateSequence();
}

void loop() {
      Serial.println(results.value, HEX);
          irrecv.resume();
  int potValue = analogRead(potentpin);
  sequenceLength = map(potValue, 0, 1023, 1, maxSequenceLength);
  if (sequenceLength != previousPotValue) {
    generateSequence();
    previousPotValue = sequenceLength;
  }
      displaySequence();
  readPlayerInput();
  delay(2000);
}

void generateSequence() {
  for (int i = 0; i < sequenceLength; i++) {
    sequence[i] = random(10);
  }
  currentStep = 0;
}

void displaySequence() {
  for (int i = 0; i < sequenceLength; i++) {
    displayDigit(sequence[i]);
    delay(700);
    clearDisplay();
        if (i < sequenceLength - 1) {
      delay(800);
    }
  }
}

void displayDigit(int digit) {
  byte segments[] = {
    B00111111, B00000110, B01011011, B01001111, B01100110,
    B01101101, B01111101, B00000111, B01111111, B01101111
  };
  for (int segmentPin = 0; segmentPin < 7; segmentPin++) {
    digitalWrite(displayPins[segmentPin], bitRead(segments[digit], segmentPin));
  }
}

void clearDisplay() {
  for (int segmentPin = 0; segmentPin < 7; segmentPin++) {
    digitalWrite(displayPins[segmentPin], LOW);
  }
}

void readPlayerInput() {
  if (irrecv.decode(&results)) {
    userInput = getDigitFromIRCode(results.value);
    irrecv.resume();
    delay(100);
    checkUserInput();
}
}

int getDigitFromIRCode(unsigned long irCode) {
  if (irCode == 0xFF30CF) return 1;
  if (irCode == 0xFF18E7) return 2;
    if (irCode == 0xFF7A85) return 3;
      if (irCode == 0xFF10EF) return 4;
        if (irCode == 0xFF38C7) return 5;
          if (irCode == 0xFF5AA5) return 6;
            if (irCode == 0xFF42BD) return 7;
              if (irCode == 0xFF4AB5) return 8;
                if (irCode == 0xFF52AD) return 9;
                  if (irCode == 0xFF6897) return 0;
  return -1;
}

void checkUserInput() {
  if (userInput == sequence[currentStep]) {
    digitalWrite(gled, HIGH);
    delay(500);
    digitalWrite(gled, LOW);
    currentStep++;
    if (currentStep == sequenceLength) {
      currentStep = 0;
      generateSequence();
    }
  } else {
    digitalWrite(rled, HIGH);
    delay(500);
    digitalWrite(rled, LOW);
  }
}
