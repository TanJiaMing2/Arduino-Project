#define button_p 4

void setup() {
  Serial.begin(9600);
  pinMode(button_p,INPUT_PULLUP);
  // put your setup code here, to run once:

}

void loop() {
  Serial.println(digitalRead(button_p));
  delay(100);
  // put your main code here, to run repeatedly:

}
