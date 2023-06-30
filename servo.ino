//credit to Shane for code
//feel free to use different pins as needed but remember to change your code to match!
#include <Servo.h> //include servo library

Servo servo1; //Declares a servo object for controlling first servo
Servo servo2; //Declares a servo object for controlling second servo
//PPM stands for Pulse Position Modulation and is the method by which the transmitter tells the servo to move
int ppmPin1 = 2; //defines inout pin for channel 1 (trigger) of transmitter, in this case pin 2
int ppmPin2 = 3; //defines input pin for channel 2 (wheel) of transmitter, in this case pin 3
int servo1Value; //declares integer variable to store cuttent position of servo 1
int servo2Value; 
int servo1Min = 0; //min location of servo 1 in degrees
int servo1Max = 180; //max location of servo 1 in degrees
int servo2Min = 0;
int servo2Max = 180;

void setup() {
  // put your setup code here, to run once:
servo1.attach(7); //attaches servo1 to digital pin 7 on arduino board
servo2.attach(8);
pinMode(ppmPin1, INPUT); //configures ppmPin1 as an input pin to read the ppm signal for channel 1
pinMode(ppmPin2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ppmValue1 = pulseIn(ppmPin1, HIGH, 25000); //reads PPM signal for channel 1. It waits for a HIGH signal on ppmPin1 and measures duration in microseconds. Max allowed duration is 25000 microseconds (25 milliseconds).
  int ppmValue2 = pulseIn(ppmPin2, HIGH, 25000);
  if (ppmValue1 !=0){ //checks if ppmValue1 is not equal to zero
    servo1Value = map(ppmValue1, 900, 2100, servo1Max, servo1Min); //Maps ppmValue1 to the servo range by scaling between one range (900,2100) to (servo1Min, servo1Max)
    servo1.write(servo1Value); //sets the position of servo1 to the value of servo1Value
  }
  if (ppmValue2 != 0) {
    servo2Value = map(ppmValue2, 900, 2100, servo2Max, servo2Min);
    servo2.write(servo2Value);
  }
}
