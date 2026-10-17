
long duration, distance;
const int echoPin =7;
const int trigPin = 8;


void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);

pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);

duration = pulseIn(echoPin,HIGH);
distance = duration/57.8;
Serial.println(distance);

delay(50);
if(distance<20) tone(9,200);
else noTone(9);
}
