// //////////////////////////////////////////////////////////////////////////////////////
// Insect Bot - version para correra.                                                  //
// Modificado de Leopard Research para el curso de robótica                            //
/////////////////////////////////////////////////////////////////////////////////////////
 
#include <Servo.h>                        // inluya archivo de control para servomotores
Servo frontServo;                         // servos en frente y atrás
Servo rearServo;
const int walkSpeed = 0;                  // retraso entre pasos (ms)
const int servoStepDelay = 6;             // retraso entre pasos de ángulo de servo
const int centerPos = 90;                 // ángulo de servo centrado (grados)
int frontServoPos = centerPos;
int backServoPos = centerPos;
const int servoOffset = 20;               // grados para cambiar ángulo mientras caminando
int frontRightUp = 70;                    // ángulos de servos para caminar atras
int frontLeftUp = 110;
int backRightForward = 70;
int backLeftForward = 110;
int centerTurnPos = 81;
int frontTurnRightUp = 70;
int frontTurnLeftUp = 110;
int backTurnRightForward = 70;
int backTurnLeftForward = 110;
int distance = 0;                         // distancia desde objeto (0 - 1000), desde sensor
int sensorPin = A1;                       // sensor usa clavija analógica A1
// nota: valores más grandes son mas lejos, mas chicos son mas cerca
int dangerDistance = 350;                 // bejo de este valor de sensor, reactionar

// this function runs only one time, when the Arduino starts
void setup()
{
  frontServo.attach(9);                     // attach servos to pins 9 and 10
  rearServo.attach(10);
  pinMode(sensorPin, INPUT);                // set sensor pin to read signals  
  frontServo.write(centerPos);              // center servos
  rearServo.write(centerPos);
  
  delay(3000);                              // wait 3 seconds before starting walking
  //Serial.begin(9600);                     // serial data setup - for debugging
}

// check distance to obstacle, from sensor
void scan()
{  
  // read 5 distance values
  distance = 0;
  for (int i = 0; i < 5; i = i + 1) 
  {
    int distanceRead = analogRead(sensorPin);
    // serial output, for testing
    //Serial.print(distanceRead);     
    distance = distance + distanceRead;   
  }
  // Average value (helps filter sensor noise)
  distance = distance / 5;
  delay(20);     
} 

// walk forward
void moveForward()
{   
  // if servoOffset is 20 (20 degrees), the front servo goes from 90 to 70 to 90 to 110 to 90 degrees
  stepRightFootForward(); // step right
  stepLeftFootForward();  // back to neutral
  stepLeftFootForward();  // step left
  stepRightFootForward(); // back to neutral  
}

void stepRightFootForward()
{
  // move the servo in steps for smoother motion
  for (int stepNum = 0; stepNum < servoOffset; stepNum++)
  {
    frontServoPos--;
    backServoPos++; // back servo does the opposite of front servo          
    frontServo.write(frontServoPos);
    rearServo.write(backServoPos);
    delay(servoStepDelay);
  }    
}

void stepLeftFootForward()
{
  // move the servo in steps for smoother motion
  for (int stepNum = 0; stepNum < servoOffset; stepNum++)
  {
    frontServoPos++;
    backServoPos--;    
    frontServo.write(frontServoPos);
    rearServo.write(backServoPos);
    delay(servoStepDelay);
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

// blink LED. This function can be called in any situation you want. Just add led(); 
// in the code where you want to blink the LED.
void led(int numBlinks){
  // loop for the LED to blink it numBlinks times for 0.05 sec on and 0.1 sec off
  for (int l = 0; l <= numBlinks; l++) 
  {
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(100);
  }  
}

// this function runs repeatedly
void loop()
{
  // call function for checking the distance
  scan();
  //Serial.println(distance);
  if (distance > 1) // filters out the zero readings
  {     
    // an obstacle is being detected, blink lights
    if (distance > dangerDistance) 
    {    
      reactToDanger();
    } 
    else 
    {
      // all clear, no obstacle detected. Just walk forward      
      moveForward();
      delay(walkSpeed/100);
    }
  }
}

void reactToDanger()
{
  led(5); // Blink LED 5x
}

