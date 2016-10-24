#include <Servo.h>                        // inluya archivo de control para servomotores
Servo mainServo;

const int startAngle = 40;
const int endAngle = 115;
const int winchAngle = 10;
int lastServoAngle;
bool charging;

void setup()
{
  // put your setup code here, to run once:
  mainServo.attach(9);  // Attach to pin 9
  pinMode(A1, INPUT);                // set sensor pin to read signals    
  mainServo.write(startAngle);  
  delay(4000);
  //mainServo.write(endAngle);  
  //delay(2000);
  // Start it upright
  for (int angle = startAngle; angle < endAngle; angle += winchAngle)
  {
    mainServo.write(angle);
    delay(600);
  }
  lastServoAngle = endAngle;
  charging = true;  
  //Serial.begin(9600);       // serial data setup    
}

void loop() 
{
  int sensorValue = scan();  
  if (charging)
  {
    // Typical sensor values are around 20-650. Convert it to an angle, from min to max
    int servoAngle = endAngle - (sensorValue - 20) * (endAngle - startAngle * 1.0) / 600; // Need .0 to force decimal math
    //Serial.println(sensorValue); 
    //Serial.println(servoAngle); 
    if (servoAngle <= startAngle)
    {
      servoAngle = startAngle;
      charging = false; // charged      
    }
    if (servoAngle <= lastServoAngle)
    {
      lastServoAngle = servoAngle;
    }
    mainServo.write(lastServoAngle);
  }
  else
  {
    if (sensorValue < 50)
    {
      mainServo.write(endAngle);  // Throw!      
    }
    lastServoAngle = endAngle;    
    delay(4000);
    charging = true;
  }
  /*
  // Wind up
  for (int angle = endAngle; angle > startAngle; angle -= winchAngle)
  {
    mainServo.write(angle);
    delay(300);
  }
  delay(4000);
  

  //mainServo.write(startAngle - 30);
  mainServo.write(endAngle);  // Throw!
  delay(4000);
  */
}

int scan()
{
    return analogRead(A1);  
}

