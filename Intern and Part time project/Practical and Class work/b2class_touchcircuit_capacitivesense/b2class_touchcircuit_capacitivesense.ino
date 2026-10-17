#include <CapacitiveSensor.h>

CapacitiveSensor capSensor_4_8 =CapacitiveSensor(4,8);
CapacitiveSensor capSensor_4_10 =CapacitiveSensor(4,10);

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long value1=capSensor_4_8.capacitiveSensor(30);
   long value2=capSensor_4_10.capacitiveSensor(30);

   if (value1>200) tone (2,262);
      if (value1>200) tone (2,294);
            if (value1>200 && value2<200) noTone (2);
            Serial.println(value1);
            delay(50);
}
