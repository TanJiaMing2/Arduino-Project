#define buzz_p 4

void setup() {
  pinMode(buzz_p,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  tone(buzz_p,1000);
  delay(1000);
  noTone(buzz_p);
  delay(1000);
  // put your main code here, to run repeatedly:

}
