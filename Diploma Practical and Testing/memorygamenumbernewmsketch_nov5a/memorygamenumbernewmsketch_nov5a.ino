#include <IRremote.h>


const int irReceiverPin = 2;
int a=5;
int b=6;
int c=7;
int d=8;
int e=9;
int f=10;
int g=11;
int rdmnumber = 0;
const int sequenceLength = 1; // Adjust the sequence length as needed
int sequence[sequenceLength]; // Store the generated sequence
// Define the IR remote control values for each digit

IRrecv irrecv(irReceiverPin);
decode_results results;

void setup() {
   Serial.begin(9600);
  irrecv.enableIRIn();
   pinMode(a,OUTPUT);
   pinMode(b,OUTPUT);
   pinMode(c,OUTPUT);
   pinMode(d,OUTPUT);
   pinMode(e,OUTPUT);
   pinMode(f,OUTPUT);
   pinMode(g,OUTPUT);
  digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,LOW);
   randomSeed(analogRead(0));



void loop() {
  rdmnumber = random(9);
  if (irrecv.decode(&results)) {
  }
  {
    Serial.println(results.value, HEX);
   if(results.value==0xFF30CF )  // Displaying 1
   { 
   digitalWrite(a,LOW);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,LOW);
   digitalWrite(e,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,LOW);
   }
    
  
   if(results.value==0xFF18E7)   // Displaying 2
     { 
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,LOW);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,LOW);
   digitalWrite(g,HIGH);
   }

    if(results.value==0xFF7A85)   // Displaying 3
   { 
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,HIGH);
   }
       if(results.value==0xFF10EF)   // Displaying 4
      { 
   digitalWrite(a,LOW);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,LOW);
   digitalWrite(e,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   }

      if(results.value==0xFF38C7)   // Displaying 5
    { 
   digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   }
  
    
   if(results.value==0xFF5AA5)  //Displaying 6
      { 
   digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   }
  

  
   if(results.value==0xFF42BD)   // Displaying 7
   { 
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,LOW);
   digitalWrite(e,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,LOW);
   }

    if(results.value==0xFF4AB5)   // Displaying 8
    { 
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   }
       if(results.value==0xFF52AD)   // Displaying 9
    { 
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   }

       if(results.value==0xFF6897)   // Displaying 0
      { 
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,LOW);
   }
    irrecv.resume();   
    delay(100); 
  } 

}
  
