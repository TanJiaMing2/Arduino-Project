const int inPin =12;
int currentState=LOW;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(inPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
currentState =digitalRead(inPin);
Serial.println (currentState);
delay(100);
}
