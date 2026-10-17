int analogVal;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogVal=analogRead (A4);
Serial.println(analogVal);
delay(100);

if  (analogVal <500) {digitalWrite(5,HIGH);}
else {digitalWrite(5,LOW);}


}
