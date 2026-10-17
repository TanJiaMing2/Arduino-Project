const int inPin =12;
const int outPin =5;
int currentState=LOW;
int previousState=LOW;
int outState =LOW;
void setup() {
  // put your setup code here, to run once:

pinMode(inPin,INPUT);
pinMode(outPin,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
currentState =digitalRead(inPin);
if ((currentState == HIGH) && (previousState == LOW))
  {
    if(outState==LOW)
    outState=HIGH;
    else
    outState=LOW;
    }
    previousState=currentState;
    digitalWrite(outPin,outState);
    delay(10);
    }
