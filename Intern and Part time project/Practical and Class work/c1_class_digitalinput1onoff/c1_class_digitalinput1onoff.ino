const int inPin =12;
const int outPin =5;
int currentState=LOW;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(inPin,INPUT);
pinMode(outPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
currentState =digitalRead(inPin);
if (currentState ==HIGH)
digitalWrite(outPin,HIGH);
else
digitalWrite(outPin,LOW);

Serial.println (currentState);
delay(10);
}
