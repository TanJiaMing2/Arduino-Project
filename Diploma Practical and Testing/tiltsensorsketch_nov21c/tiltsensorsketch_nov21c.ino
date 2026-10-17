//Read the value of a tilt sensor

  int tiltsensor = 2;
  int buzz=3;
  int led=4;
  void setup()
  {
    pinMode(tiltsensor, INPUT);
    //initialize communication at 9600 bits per second
    Serial.begin(9600);
    pinMode(buzz,OUTPUT);
        pinMode(led,OUTPUT);
  }

  void loop()
  {
    //print the value on the serial monitor
    //Go to Tools->Serial Monitor to see the values
    Serial.println(digitalRead(tiltsensor));
    delay(100);

    if (digitalRead(tiltsensor)==1){
      digitalWrite(led,HIGH);
      tone(buzz,1000);
    }
    else{
  noTone(buzz);
        digitalWrite(led,LOW);
    }
    
  }