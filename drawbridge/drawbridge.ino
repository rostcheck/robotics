// test-servo
// Move the servo attached to pin 9 to 9 degrees, then 0, then 180

#include <Servo.h>    // include functions to control servos
Servo myServo;        // this is our Servo variable

// This function runs only once, when the Arduino starts
void setup() {      
  pinMode(A1, INPUT);       // Set sensor pin, A1 to read signals
  myServo.attach(9);        // Attach our servo to pin 9
}

// This function runs repeatedly
void loop() {
  myServo.write(90);        // Start at angle 90
  //Serial.begin(9600);
  delay(2000);
  myServo.write(160);         // Go to 10
  delay(2000);
    
}
