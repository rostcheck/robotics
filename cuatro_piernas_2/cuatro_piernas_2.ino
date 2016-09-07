// Pasear con cuatros patas, diferente modo de andar

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
}  

// Esta función corre repetidamente
void loop()
{
  pasar1y2();
  delay(300);
  pasar3y4();
  delay(300);
}

void estarEnPie()
{
  servoFrente1.write(90);
  servoFrente2.write(90);
  servoAtras1.write(90);
  servoAtras2.write(90);   
}

void pasar1y2()
{
  servoFrente1.write(70);
  servoFrente2.write(110);
  servoAtras1.write(110);
  servoAtras2.write(70);  
}

void pasar3y4()
{
  servoAtras1.write(70);
  servoAtras2.write(110);    
  servoFrente1.write(110);  
  servoFrente2.write(70);  
}
