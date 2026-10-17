const int POTENTIOMETER_PIN = A1;
const int LED_PIN1           = 7;
const int LED_PIN2           = 6;  
const int LED_PIN3           = 5;  
const int LED_PIN4           = 4;  
const int LED_PIN5           = 3;    
const int ANALOG_THRESHOLD1  = 300;
const int ANALOG_THRESHOLD2  = 450;
const int ANALOG_THRESHOLD3  = 550;
const int ANALOG_THRESHOLD4  = 650;
const int ANALOG_THRESHOLD5  = 750;
const int buzzer = 8;
void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT); 
  pinMode(LED_PIN3, OUTPUT); 
  pinMode(LED_PIN4, OUTPUT); 
  pinMode(LED_PIN5, OUTPUT);
  pinMode(buzzer, OUTPUT);   
}

void loop() {
  int analogValue = analogRead(POTENTIOMETER_PIN); 

  if(analogValue > ANALOG_THRESHOLD1){
    digitalWrite(LED_PIN1, HIGH);
  }
  else{
    digitalWrite(LED_PIN1, LOW); }

  if(analogValue > ANALOG_THRESHOLD2)
    digitalWrite(LED_PIN2, HIGH);

 else
    digitalWrite(LED_PIN2, LOW); 

  if(analogValue > ANALOG_THRESHOLD3)
    digitalWrite(LED_PIN3, HIGH);

   else
    digitalWrite(LED_PIN3, LOW); 

   if(analogValue > ANALOG_THRESHOLD4)
    digitalWrite(LED_PIN4, HIGH);

   else
    digitalWrite(LED_PIN4, LOW); 


  if(analogValue > ANALOG_THRESHOLD5){
    digitalWrite(LED_PIN5, HIGH);
    tone(buzzer, 1046);
  }
   else{
    digitalWrite(LED_PIN5, LOW); 
    noTone(buzzer);
   }
}