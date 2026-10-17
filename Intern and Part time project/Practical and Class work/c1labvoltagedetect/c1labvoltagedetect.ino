int analogVal;
float voltage;
int R1=1000;
int R2 =1000 ;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
analogVal=analogRead(A0);
voltage=analogVal / 1023.0 *5.0 * (R1+R2)/R1;
Serial.println (voltage);
delay(100);
}
