#include "src/OfflineBroadcast.h"
#include <Arduino.h>

const int LED_PIN = 9; // Define LED pin as a constant

void dot() {
  digitalWrite(LED_PIN, HIGH);
  delay(100); // Use delay() for milliseconds, _delay is non-standard
  digitalWrite(LED_PIN, LOW);
  delay(500);
}

void dash() {
  digitalWrite(LED_PIN, HIGH);
  delay(300);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}

OfflineBroadcast broadcaster;

// Store the Morse code sequences in an array of strings
const char* morseCodes[] PROGMEM = {
  ".-",   // a
  "-...", // b
  "-.-.", // c
  "-..",  // d
  ".",    // e
  "..-.", // f
  "--.",  // g
  "....", // h
  "..",   // i
  ".---", // j
  "-.-",  // k
  ".-..", // l
  "--",   // m
  "-.",   // n
  "---",  // o
  ".--.", // p
  "--.-", // q
  ".-.",  // r
  "...",  // s
  "-",    // t
  "..-",  // u
  "...-", // v
  ".--",  // w
  "-..-", // x
  "-.--", // y
  "--..", // z
  "-----", // 0
  ".----", // 1
  "..---", // 2
  "...--", // 3
  "....-", // 4
  ".....", // 5
  "-....", // 6
  "--...", // 7
  "---..", // 8
  "----.", // 9
};

void broadcastHandler(const char* morse) {  // Pass the Morse code string
  for (int i = 0; morse[i] != '\0'; i++) { // Iterate through the string
    if (morse[i] == '.') {
      dot();
    } else if (morse[i] == '-') {
      dash();
    }
  }
  broadcaster.callOK();
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

  // Register the handlers using a loop
  char c = 'a';
  for (int i = 0; i <= 35; i++) {
    String key;
    if (i < 26) {
      key = String(c);
      c++;
    } else {
      key = String(i - 26); // Convert number to string
    }
    broadcaster.on(key, [i]() { broadcastHandler(morseCodes[i]); });
  }
}

void loop() {
  broadcaster.loop();
}