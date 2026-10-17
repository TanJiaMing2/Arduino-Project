int analogVal;

void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);

analogVal = analogRead(A4);
Serial.println(analogVal);
delay(100);
}
