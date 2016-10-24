// control-servo
// Mueve el servo adjunto a la clavija en manera que corresponde a distancia a
// objeto al sensor

#include <Servo.h>    // incluye funcionas para controlar servos
Servo miServo;        // variable que reprenta nuestro servo
int servoAngle = 90;

// Esta función corre solo una vez, cuando empiece el Arduino
void setup() {      
  pinMode(A1, INPUT);       // Configura clavija del sensor, A1, par leer señales
  miServo.attach(9);        // Adjunta nuestro servo a clavija 9
  miServo.write(90);        // Enpiece en angulo 90
  //Serial.begin(9600);
  delay(2000);
}

// Esta función corre repetidamente
void loop() {
  int valorDeSensor = escanear();
  // Valores típicos de sensor son desde 20-650. Convierte en ángulo, desde 1 hasta 180
  //Serial.println(valorDeSensor);
  int anguloDeServo = (valorDeSensor - 20) * 179.0 / 650; // Necesitamos .0 para forzar math decimal
  //Serial.println(anguloDeServo);
  miServo.write(anguloDeServo);
  delay(100);
}

int escanear() {
  return analogRead(A1);
}
