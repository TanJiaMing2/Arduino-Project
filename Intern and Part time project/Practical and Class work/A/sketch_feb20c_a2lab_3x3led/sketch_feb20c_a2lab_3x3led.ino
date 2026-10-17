void setup() {
  // put your setup code here, to run once:
    pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
//LED1
digitalWrite (2,HIGH);digitalWrite (3,LOW);digitalWrite (4,LOW);
digitalWrite (5,LOW);digitalWrite (6,HIGH);digitalWrite (7,HIGH);
delay(500);
//LED2
digitalWrite (2,LOW);digitalWrite (3,HIGH);digitalWrite (4,LOW);
digitalWrite (5,LOW);digitalWrite (6,HIGH);digitalWrite (7,HIGH);
delay(500);
//LED3
digitalWrite (2,LOW);digitalWrite (3,LOW);digitalWrite (4,HIGH);
digitalWrite (5,LOW);digitalWrite (6,HIGH);digitalWrite (7,HIGH);
delay(500);
//LED4
digitalWrite (2,HIGH);digitalWrite (3,LOW);digitalWrite (4,LOW);
digitalWrite (5,HIGH);digitalWrite (6,LOW);digitalWrite (7,HIGH);
delay(500);
//LED5
digitalWrite (2,LOW);digitalWrite (3,HIGH);digitalWrite (4,LOW);
digitalWrite (5,HIGH);digitalWrite (6,LOW);digitalWrite (7,HIGH);
delay(500);
//LED6
digitalWrite (2,LOW);digitalWrite (3,LOW);digitalWrite (4,HIGH);
digitalWrite (5,HIGH);digitalWrite (6,LOW);digitalWrite (7,HIGH);
delay(500);
//LED7
digitalWrite (2,HIGH);digitalWrite (3,LOW);digitalWrite (4,LOW);
digitalWrite (5,HIGH);digitalWrite (6,HIGH);digitalWrite (7,LOW);
delay(500);
//LED8
digitalWrite (2,LOW);digitalWrite (3,HIGH);digitalWrite (4,LOW);
digitalWrite (5,HIGH);digitalWrite (6,HIGH);digitalWrite (7,LOW);
delay(500);
//LED9
digitalWrite (2,LOW);digitalWrite (3,LOW);digitalWrite (4,HIGH);
digitalWrite (5,HIGH);digitalWrite (6,HIGH);digitalWrite (7,LOW);
delay(500);

}
