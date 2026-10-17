int analogVal;
int analogOut;
const int potPin =A0;
const int ledPin =5;

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogVal = analogRead (potPin);
analogOut = analogVal / 1023.0 * 255.0;

analogWrite (ledPin, analogOut);
delay(100);
}
