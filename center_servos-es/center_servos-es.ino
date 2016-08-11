// Enviar mandos a los dos servos para centrarse

#include <Servo.h>                            // Incluye archivo para controlar servos

// Declarar variables para representar los dos servos
Servo servoFrente;
Servo servoAtras;

// Esta función corre solo una vez, cuando empiece el Arduino
void setup()                                
{
  servoFrente.attach(9);                      // Adjuntar servo frente a clavija 9
  servoAtras.attach(10);                      // Adjuntar servo atrás a clavija 10

  servoFrente.writeMicroseconds(1500);        // Manda señal para quedar en lugar, 1.5 segundos 
  servoAtras.writeMicroseconds(1500);         // Manda señal para quedar en lugar, 1.5 segundos
}  

// Esta función corre repetidamente
void loop()
{
}
