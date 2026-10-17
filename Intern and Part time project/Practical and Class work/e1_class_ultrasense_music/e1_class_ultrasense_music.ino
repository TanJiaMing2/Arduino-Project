int analogVal;
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
  // analogVal=analogRead(A4);

digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);

duration = pulseIn(echoPin,HIGH);
distance = duration/57.8;
Serial.println(distance);

delay(50);
if(distance >5& distance <=10) tone (9,262);
if(distance >10& distance <=15) tone (9,294);
if(distance >15& distance <=20) tone (9,330);
if(distance >20& distance <=25) tone (9,349);
if(distance >25& distance <=30) tone (9,392);
if(distance >35& distance <=40) tone (9,440);
if(distance >45& distance <=50) tone (9,494);
if(distance <=5 or distance >50) noTone (9);
}
