#include <Servo.h>
#include <stdio.h>

// Constants:
Servo servo1; // servo controller (multiple can exist)
Servo servo2; 
Servo servo3; 
Servo servo4; 
Servo servo5; 
Servo servo6; 
Servo servo7; 
Servo servo8; 
Servo servo9; 
Servo servo10; 
Servo servo[10] = {servo1, servo2, servo3, servo4, servo5, servo6, servo7, servo8, servo9, servo10};

// PWM pins for servo control
int servoPin[10] = {2,3,4,5,6,7,8,9,10,11};

// Pins to read analog input:
int analogPin[10] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9};

// Analog values for servos
int value[10] = {0};

// Servo positions:
int pos[10] = {0};

bool moved[10] = {false};

void setup(){
  for (int i = 0; i < 10; i++) {
    servo[i].attach(servoPin[i]);
    
  }
  Serial.begin(9600);       //Begin serial communication
}

void loop(){
  for (int i = 0; i < 10; i++) {
    value[i] = analogRead(analogPin[i]);
    if (value[i] >= 350) moved[i] = true;
  }

  for (int i = 0; i < 10; i++) {
    Serial.print("servo ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(value[i]);
    Serial.println(); 
  }
    detectStretch();
}

void detectStretch() {
  for (int i = 1; i <= 180; i += 1) {                                      // goes from 0 degrees to 180 degrees
    for (int j = 0; j < 10; j++) {
      moveBack(j, i);
     }
    delay(15);                                                             // delay to allow the servo to reach the desired position
  }
  delay(500);

  for (int i = 180; i >= 0; i -= 1) {                                      // goes from 0 degrees to 180 degrees
   for (int j = 0; j < 10; j++) {
    moveBack(j, i);
   }
    delay(15);                                                             // delay to allow the servo to reach the desired position
  }
  delay(500);
}

void moveBack(int servoNum, int loc) {
  if (moved[servoNum]) {
    servo[servoNum].write(loc);
  }
  if (loc == 0) moved[servoNum] = false;
}
