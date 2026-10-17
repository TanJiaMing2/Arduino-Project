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
  Serial.print("temp = ");
  Serial.println(temp1);
  Serial.println("*C");
 Serial.print("light value: ");
  lightdetect = analogRead(light1);
 Serial.println(lightdetect);

  if (lasttouchstate == LOW && currenttouchstate == HIGH) { //for toggling the touch sen
    lightstate = !lightstate;
    tone(buzz1, 3000);
  }

  if (lightstate) {
    ledbright = map(lightdetect, 80, 500, 40, 250);
    // rgbled color changes based on temperature
    if (temp1 < 32) {
      analogWrite(ledr, 0);
      analogWrite(ledb, ledbright);
    } else if (temp1 < 70) {
      analogWrite(ledr, ledbright);
      analogWrite(ledb, 0);
    } else {
      analogWrite(ledr, 0);
      analogWrite(ledb, ledbright);
    }

  } else {
    // Turn off the RGB LED when not touched
    analogWrite(ledr, 0);
    analogWrite(ledb, 0);
  }

  delay(100);
  noTone(buzz1);
}
