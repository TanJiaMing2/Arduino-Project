#define led1 3
#define led3 4
#define buzz1 5
#define button1 6

void setup() {
  // put your setup code here, to run once:
//digitalWrite(led1,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(buzz1,OUTPUT);
pinMode(button1,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button1) == LOW){
    digitalWrite(led1,HIGH);
    digitalWrite(led3,HIGH);
    tone(buzz1,1000);
    delay(200);
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
    delay(200);
    digitalWrite(led1,HIGH);
    delay(200);
    digitalWrite(led1,LOW);
    delay(200);
    digitalWrite(led1,HIGH);
    delay(200);
    digitalWrite(led1,LOW);
    noTone(buzz1);
    delay(1000);
        digitalWrite(led1,HIGH);
    digitalWrite(led3,HIGH);
    tone(buzz1,1000);
    delay(200);
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
    delay(200);
    digitalWrite(led1,HIGH);
    delay(200);
    digitalWrite(led1,LOW);
    delay(200);
    digitalWrite(led1,HIGH);
    delay(200);
    digitalWrite(led1,LOW);
    noTone(buzz1);
    delay(1000);
        digitalWrite(led1,HIGH);
    digitalWrite(led3,HIGH);
   tone(buzz1,1000);
    delay(200);
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
    delay(200);
    digitalWrite(led1,HIGH);
    delay(200);
    digitalWrite(led1,LOW);
    delay(200);
    digitalWrite(led1,HIGH);
    delay(200);
    digitalWrite(led1,LOW);
    noTone(buzz1);
  }

}
