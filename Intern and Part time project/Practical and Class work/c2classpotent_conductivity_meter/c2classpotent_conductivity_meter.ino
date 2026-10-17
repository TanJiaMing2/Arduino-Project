int analogVal;
float voltage;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogVal=analogRead (A4);
voltage = analogVal / 1023.0 * 5.0;

Serial.println(voltage);
delay(100);
if (voltage>=0.2) digitalWrite(8,HIGH);else digitalWrite (8,LOW);
if (voltage>=1) digitalWrite(9,HIGH);else digitalWrite (9,LOW);
if (voltage>=2.5) digitalWrite(10,HIGH);else digitalWrite (10,LOW);
if (voltage>=4.0) digitalWrite(11,HIGH);else digitalWrite (11,LOW);

}



