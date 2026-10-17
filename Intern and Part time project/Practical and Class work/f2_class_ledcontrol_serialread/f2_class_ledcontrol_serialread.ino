void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT);
Serial.begin(9600);

//stay in while loop until serial connection established

while(!Serial);
//print a message to the lcd.
Serial.println("input 1 to turn led on and 2 to off");
}

void loop() {
  // put your main code here, to run repeatedly:
// look for the next valid integer in the incoming serial

int state = Serial.parseInt();

// if (state == 1)
// {
//   digitalWrite(7,HIGH);
//   Serial.println("Led on");
// }

// if (state== 2)
// {
//   digitalWrite(7,LOW);
//     Serial.println("Led off");
// }


switch(state){
  case 1:
  digitalWrite(7,HIGH);
  Serial.println("LED on");
  break;
    case 2:
  digitalWrite(7,LOW);
  Serial.println("LED off");
  break;
}

}
