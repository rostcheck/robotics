// //////////////////////////////////////////////////////////////////////////////////////
// INSECT BOT MINI (Insectbot Kit Product Code: KIT0051                                //
// http://www.dfrobot.com/index.php?route=product/product&product_id=1055              //
//                                                                                     //
// modified by Lumi for DFRobot.com                                                    //
// 2013/12/23                                                                          //
/////////////////////////////////////////////////////////////////////////////////////////
 
// Servo Library 
#include <Servo.h>
// Servo name
Servo frontServo;
Servo rearServo;
// time delay between steps
const int walkSpeed = 500;
// center servos
const int centerPos = 90;
// servo angles for walking pattern
int frontRightUp = 70;
int frontLeftUp = 110;
int backRightForward = 70;
int backLeftForward = 110;
// another center position 
int centerTurnPos = 81;
// servo angles for walking pattern
int frontTurnRightUp = 70;
int frontTurnLeftUp = 110;
int backTurnRightForward = 70;
int backTurnLeftForward = 110;
// variable for distance value
int distance = 0;
// average distance value
int distanceCheck = 0;
// Array for distance values
int collectDistance[5];
// Variables for counters
int i;
int f;
int r;
// assign analog pin A1
int sensorPin = A1;
// distance value for danger close. Bigger values are greater distance and smaller values are lower distance
int dangerDistance = 350; 
/* Setup function */
void setup()
{
  // attach servos
  frontServo.attach(9);
  rearServo.attach(10);
  // assign sensor
  pinMode(sensorPin, INPUT);
  // center servos
  frontServo.write(centerPos);
  rearServo.write(centerPos);
  // wait 3 seconds for start walking
  delay(3000);
  //Serial.begin(9600); // serial data setup
}
/* distance check function */
void scan()
{  
  // read 5 distance values
  for (i = 0; i < 5; i = i + 1) 
  {
    distanceCheck = analogRead(sensorPin);
    collectDistance[i] = distanceCheck;
    // serial output for testing
    //Serial.print (i);
    //Serial.print(" = ");
    //Serial.println(collectDistance[i]);
  }
  // Average 5 distance values. This will prevent the robot to change behavior by reading one wrong value
  distance = (collectDistance[0] + collectDistance[1] + collectDistance[2] + collectDistance[3] + collectDistance[4])/5;
  delay(20);     
} 
 
// walk forward
void moveForward()
{  
  // loop for the servo angles to smoothen the steps
  for (f = 0; f < 39; f++)
  {
    frontRightUp++; 
    backLeftForward--;
    frontServo.write(frontRightUp);
    rearServo.write(backLeftForward);
    delay(10);
  }

  // loop for the servo angles to smoothen the steps
  for (r = 0; r < 39; r++)
  {
    frontRightUp--; 
    backLeftForward++;
    frontServo.write(frontRightUp);
    rearServo.write(backLeftForward);
    delay(10);
  } 
}

// walk backwards to the left
void moveBackRight()
{
  frontServo.write(frontRightUp);
  rearServo.write(backRightForward-6);
  delay(110);
  frontServo.write(centerPos);
  rearServo.write(centerPos-6);
  delay(80);
  frontServo.write(frontLeftUp+9);
  rearServo.write(backLeftForward-6);
  delay(110);
  frontServo.write(centerPos);
  rearServo.write(centerPos);
  delay(80);
}

// walk forward to the left
void moveTurnLeft()
{
  frontServo.write(frontTurnRightUp);
  rearServo.write(backTurnLeftForward);
  delay(110);
  frontServo.write(centerTurnPos);
  rearServo.write(centerTurnPos);
  delay(80);
  frontServo.write(frontTurnLeftUp);
  rearServo.write(backTurnRightForward);
  delay(110);
  frontServo.write(centerTurnPos);
  rearServo.write(centerTurnPos);
  delay(80);
}

// blink LED. This function can be called in any situation you want. Just add led(); in the code where you want to blink the LED.
void led(int numBlinks){
  // loop for the LED to blink it numBlinks times, for 0.05 sec on and 0.1 sec off
  for (int l = 0; l <= numBlinks; l++) 
  {
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(100);
  }  
}

// that's the loop. This is repeatedly called as long as the robot is powered on
void loop()
{
  // call function for checking the distance
  scan();
  //Serial.println(distance);
  if (distance > 1) // filters out the zero readings
  { 
    // an obstacle is being detected
    if (distance > dangerDistance) 
    {      
      led(5); // Blink LED 5x
      // 4 steps backward left
      for (int i = 0; i <= 3; i++) 
      {
        moveBackRight();
        delay(walkSpeed);
      }
      led(4);
      // 4 steps forward left
      for (int i = 0; i <= 3; i++) 
      {
        moveTurnLeft();
        delay(walkSpeed);
      }
    } 
    else 
    {
      // all clear, no obstacle detected. Just walk forward
      led(1);
      moveForward();
      delay(walkSpeed/100);
    }
  }
}
