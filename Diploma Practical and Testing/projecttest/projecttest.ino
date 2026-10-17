#define ledr 3
#define ledb 5
int buzz1 = 6;
#define touch1 7
int temp1 = A1;
int light1 = A5;
int lasttouchstate;
int currenttouchstate;
int lightstate = LOW;
int ledbright = 10; // 0 to 255
int lightdetect;

void setup() {
  pinMode(ledr, OUTPUT);
  pinMode(ledb, OUTPUT);
  pinMode(buzz1, OUTPUT);
  pinMode(touch1, INPUT);
  currenttouchstate = digitalRead(touch1);
  lightdetect = 0;
  Serial.begin(9600);
}

void loop() {
  lasttouchstate = currenttouchstate;
  currenttouchstate = digitalRead(touch1);
  temp1 = analogRead(A1);
  temp1 = temp1 * 0.48828125;
  Serial.print("TEMPERATURE = ");
  Serial.print(temp1);
  Serial.println("*C");
  Serial.print("light value: ");
  lightdetect = analogRead(light1);
  Serial.println(lightdetect);

  if (lasttouchstate == LOW && currenttouchstate == HIGH) {
    lightstate = !lightstate;
    tone(buzz1, 3000);
  }

  if (lightstate) {
    // RGB LED color changes based on temperature
    if (temp1 < 30) {
      digitalWrite(ledr, 0);
      digitalWrite(ledb, 255);
    } else if (temp1 < 40) {
      digitalWrite(ledr, 255);
      digitalWrite(ledb, 0);
    } else {
      digitalWrite(ledr, 0);
      digitalWrite(ledb, 255);
    }

    // Adjust LED brightness based on light sensor value
   // ledbright = map(lightdetect, 0, 1023, 255, 0);
   // analogWrite(ledr, ledbright);
  //  analogWrite(ledb, ledbright);
  } else {
    // Turn off the RGB LED when not touched
    analogWrite(ledr, 0);
    analogWrite(ledb, 0);
  }

  delay(100);
  noTone(buzz1);
}
