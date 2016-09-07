// control-servo
// Move the servo attached to pin based on how close an object is to the sensor

#include <Servo.h>    // include functions to control servos
Servo myServo;        // this is our Servo variable
int servoAngle = 90;

// This function runs only once, when the Arduino starts
void setup() {      
  pinMode(A1, INPUT);       // Set sensor pin, A1 to read signals
  myServo.attach(9);        // Attach our servo to pin 9
  myServo.write(90);        // Start at angle 90
  //Serial.begin(9600);
  delay(2000);
}

// This function runs repeatedly
void loop() {
  int sensorValue = scan();
  // Typical sensor values are around 20-650. Convert it to an angle, from 1 to 180
  //Serial.println(sensorValue);
  int servoAngle = (sensorValue - 20) * 179.0 / 650; // Need .0 to force decimal math
  //Serial.println(servoAngle);
  myServo.write(servoAngle);
  delay(100);
}

int scan() {
  return analogRead(A1);
}
