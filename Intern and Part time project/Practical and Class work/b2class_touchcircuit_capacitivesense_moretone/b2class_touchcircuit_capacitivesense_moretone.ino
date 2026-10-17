#include <CapacitiveSensor.h>

CapacitiveSensor capSensor_4_8 =CapacitiveSensor(4,8);
CapacitiveSensor capSensor_4_10 =CapacitiveSensor(4,10);
CapacitiveSensor capSensor_4_12 =CapacitiveSensor(4,12);
CapacitiveSensor capSensor_4_13 =CapacitiveSensor(4,13);
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long value1=capSensor_4_8.capacitiveSensor(30);
   long value2=capSensor_4_10.capacitiveSensor(30);
     long value3=capSensor_4_12.capacitiveSensor(30);
   long value4=capSensor_4_13.capacitiveSensor(30);

   if (value1>200) tone (2,262);
    if (value2>200) tone (2,294);
    if (value3>200) tone (2,330);
    if (value4>200) tone (2,349);
    if (value1<60 && value2<60 && value3<60 && value4<60) noTone (2);
            
            
            
    Serial.println(value1);
    delay(50);
}
