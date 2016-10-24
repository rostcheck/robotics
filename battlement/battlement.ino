// battlement
// Move the servo attached to pin 9 from 0 to 110 degrees smoothly

#include <Servo.h>    // include functions to control servos
Servo myServo;        // this is our Servo variable

const int min_angle = 10;
const int max_angle = 160;
const int minimum_distance = 250;
bool hidden;
// This function runs only once, when the Arduino starts
void setup() {      
  //pinMode(A1, INPUT);       // Set sensor pin, A1 to read signals
  myServo.attach(9);          // Attach our servo to pin 9 
  myServo.write(max_angle);   // Hide again  
  delay(4000);  
  myServo.write(min_angle);   // Fully exposed
  delay(4000);
  myServo.write(max_angle);   // Hide again  
  pinMode(A1, INPUT);         // set sensor pin to read signals      
  hidden = true;
  delay(2000);
}

// This function runs repeatedly
void loop() {
  if (scan() > minimum_distance)
  {
    // Come out     
    for (int angle = max_angle; angle > min_angle; angle = angle - 10)
    {
      myServo.write(angle);
      delay(100);
    }   
    // Hide again 
    for (int angle = min_angle; angle < max_angle; angle = angle + 10)
    {
      myServo.write(angle);
      delay(100);
    }   
    delay(300); 

    delay(2000);
  }
}

int scan()
{
    return analogRead(A1);  
}
