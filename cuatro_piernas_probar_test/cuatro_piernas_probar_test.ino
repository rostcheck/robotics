// Enviar mandos a los dos servos para centrarse

#include <Servo.h>                            // Incluye archivo para controlar servos

// Declarar variables para representar los dos servos
Servo servoFrente1;
Servo servoFrente2;
Servo servoAtras1;
Servo servoAtras2;

// Esta función corre solo una vez, cuando empiece el Arduino
void setup()                                
{
  pinMode(A2, OUTPUT);
  servoFrente1.attach(9);                      // Adjuntar servo frente a clavija 9
  servoFrente2.attach(10);
  servoAtras1.attach(11);                      // Adjuntar servo atrás a clavija 11
  servoAtras2.attach(A2);
  estarEnPie();
  delay(2000);
  probarServos();
}  

void probarServos()
{
  // Foot 1
  servoFrente1.write(70);
  delay(1000);
  estarEnPie();
  delay(1000);
  // Foot 2
  for (int i = 0; i < 2; i++) 
  {
    servoFrente2.write(110);
    delay(1000);    
    servoFrente2.write(90);
    delay(1000);
  }
  estarEnPie();
   // Foot 3
  for (int i = 0; i < 3; i++) 
  {
    servoAtras1.write(100);
    delay(1000);    
    servoAtras1.write(90);
    delay(1000);
  }
  estarEnPie();
   // Foot 4
  for (int i = 0; i < 4; i++) 
  {
    servoAtras2.write(110);
    delay(1000);    
    servoAtras2.write(90);
    delay(1000);    
  }        
}

// Esta función corre repetidamente
void loop()
{
}

void estarEnPie()
{
  servoFrente1.write(120);
  servoFrente2.write(120);
  servoAtras1.write(120);
  servoAtras2.write(120);   
}
