// battlement
// Move the servo attached to pin 9 from 0 to 110 degrees smoothly

#include <Servo.h>    // include functions to control servos
Servo myServo;        // this is our Servo variable

int min_angle = 10;
int max_angle = 160;
// This function runs only once, when the Arduino starts
void setup() {      
  //pinMode(A1, INPUT);       // Set sensor pin, A1 to read signals
  myServo.attach(9);        // Attach our servo to pin 9 
  myServo.write(min_angle);
  delay(2000);
  myServo.write(max_angle);
  delay(2000);
}

// This function runs repeatedly
void loop() {
  // Come out
  for (int angle = max_angle; angle > min_angle; angle = angle - 10)
  {
    myServo.write(angle);
    delay(100);
  }
  delay(300);
  // Hide again  
  for (int angle = min_angle; angle < max_angle; angle = angle + 10)
  {
    myServo.write(angle);
    delay(100);
  }
  //Serial.begin(9600);
  //delay(2000);
  //myServo.write(160);         // Go to 10
  delay(2000);

}
