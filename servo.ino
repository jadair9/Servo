#include <Servo.h>

Servo servo1;
Servo servo2;

int ppmPin1 = 2;
int ppmPin2 = 3;
int servo1Value;
int servo2Value;
int servo1Min = 0; //min location of servo in degrees
int servo1Max = 180; //max location of servo in degrees
int servo2Min = 0;
int servo2Max = 180;

void setup() {
  // put your setup code here, to run once:
servo1.attach(7);
servo2.attach(8);
pinMode(ppmPin1, INPUT);
pinMode(ppmPin2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ppmValue1 = pulseIn(ppmPin1, HIGH, 25000);
  int ppmValue2 = pulseIn(ppmPin2, HIGH, 25000);
  if (ppmValue1 !=0){
    servo1Value = map(ppmValue1, 900, 2100, servo1Max, servo1Min);
    servo1.write(servo1Value);
  }
  if (ppmValue2 != 0) {
    servo2Value = map(ppmValue2, 900, 2100, servo2Max, servo2Min);
    servo2.write(servo2Value);
  }
}
