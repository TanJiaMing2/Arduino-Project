#include <IRremote.h>
int IR_PIN = 2;
IRrecv irrecv(IR_PIN);
decode_results results;

int displayPins[] = {5, 6, 7, 8, 9, 10, 11}; // Replace with your pin numbers
int gled = 3;
int rled = 4;
const int potentiometerPin = A0;
const int sequenceLength = 2; // Adjust the sequence length as needed
int sequence[sequenceLength]; // Store the generated sequence
int currentStep = 0;


void setup() {
      Serial.begin(9600);
  irrecv.enableIRIn();
  for (int i = 0; i < 7; i++) {
    pinMode(displayPins[i], OUTPUT);
  }

    pinMode(gled, OUTPUT);
        pinMode(gled, OUTPUT);
  
  randomSeed(analogRead(0)); // create random num
  generateSequence(); // output number
}



void loop() {
  displaySequence();
  readPlayerInput();

  if(irrecv.decode(&results))
  {Serial.println(results.value,HEX);
  irrecv.resume();}
}

void generateSequence() {
  for (int i = 0; i < sequenceLength; i++) {
    sequence[i] = random(10); // Generate random numbers (0-9) for the sequence
  }
}

void displaySequence() {
  for (int i = 0; i < sequenceLength; i++) {
    // Display sequence[i] on the 7-segment display
    displayDigit(sequence[i]);
    delay(1000); // Display each number for 1 second
    // Turn off the 7-segment display
  for (int segmentPin = 0; segmentPin < 7; segmentPin++) {
    digitalWrite(displayPins[segmentPin], LOW);
  }
    delay(500); // Delay between numbers (adjust as needed)
  }
}

void displayDigit(int digit) { //display the segment
  byte segments[] = {
    B00111111,  // 0
    B00000110,  // 1
    B01011011,  // 2
    B01001111,  // 3
    B01100110,  // 4
    B01101101,  // 5
    B01111101,  // 6
    B00000111,  // 7
    B01111111,  // 8
    B01101111   // 9
  };
  for (int segmentPin = 0; segmentPin < 7; segmentPin++) {
    if (bitRead(segments[digit], segmentPin) == 1) {
      digitalWrite(displayPins[segmentPin], HIGH);
    } else {
      digitalWrite(displayPins[segmentPin], LOW);
    }
  }

}

void readPlayerInput() {
  if (irrecv.decode(&results)) {
    int userInput = results.value;
    if (userInput == sequence[currentStep]) {
      digitalWrite(gled, HIGH); // Green LED on
      delay(500); // LED on for half a second
      digitalWrite(gled, LOW); // Green LED off
      irrecv.resume(); // Continue listening for IR signals
      currentStep++;

      // Check if the player completed the sequence
      if (currentStep == sequenceLength) {
        // Player completed the round, update the sequence or game state
        currentStep = 0;
        generateSequence(); // Generate a new sequence for the next round
      }
    } else {
      // Incorrect input
      digitalWrite(rled, HIGH); // Red LED on
      delay(500); // LED on for half a second
      digitalWrite(rled, LOW); // Red LED off

      irrecv.resume(); // Continue listening for IR signals
    }
  }
}

