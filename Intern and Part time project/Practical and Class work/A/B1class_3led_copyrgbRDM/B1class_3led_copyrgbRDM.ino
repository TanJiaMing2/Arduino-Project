const int ledPinR=11;
const int ledPinG=10;
const int ledPinB=9;
int brightR;
int brightG;
int brightB;

void setup() {
  // put your setup code here, to run once:
pinMode(brightR,OUTPUT);
pinMode(brightG,OUTPUT);
pinMode(brightB,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

 brightR=random(2);
 brightG=random(2);
 brightB=random(2);
digitalWrite (ledPinR,brightR);
digitalWrite (ledPinG,brightG);
digitalWrite (ledPinB,brightB);
delay(500);
}
