
#define Sensor 5
#define LED 6
 
void setup() {
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(LED, OUTPUT);
}
 
void loop() {
  bool value = digitalRead(Sensor);
  Serial.println(value);
 
  if (value == 0) {
    digitalWrite(LED, HIGH);
    Serial.println("LED on");
  } else {
    digitalWrite(LED, LOW);
  }
}