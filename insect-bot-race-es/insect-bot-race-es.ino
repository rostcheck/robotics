// //////////////////////////////////////////////////////////////////////////////////////
// Insect Bot - version para correra.                                                  //
// Modificado de Leopard Research para el curso de robótica                            //
/////////////////////////////////////////////////////////////////////////////////////////
 
#include <Servo.h>                        // inluya archivo de control para servomotores
Servo servoFrente;                        // servos en frente y atrás
Servo servoAtras;
const int velocidad = 0;                  // retraso entre pasos (ms)
const int retrasoDelServo = 6;            // retraso entre pasos de ángulo de servo
const int centro = 90;                    // ángulo de servo centrado (grados)
int servoFrentePos = centro;
int servoAtrasPos = centro;
const int servoCambio = 20;               // grados para cambiar ángulo mientras caminando
int frenteDerechaArriba = 70;             // ángulos de servos para caminar atras
int frenteIzquierdaArriba = 110;
int avanzaDerechoPieDetrasDerecha = 70;
int avanzaDerechoPieDetrasIzquierda = 110;
int posicionCentralDeVuelta = 81;
int frontTurnRightUp = 70;
int frontTurnLeftUp = 110;
int backTurnRightForward = 70;
int backTurnLeftForward = 110;
int distance = 0;                         // distancia desde objeto (0 - 1000), desde sensor
int sensorPin = A1;                       // sensor usa clavija analógica A1
// nota: valores más grandes son mas lejos, mas chicos son mas cerca
int dangerDistance = 350;                 // bejo de este valor de sensor, reactionar

// Esta función corre solo una vez, cuando empiece el Arduino
void setup()
{
  servoFrente.attach(9);                     // attach servos to pins 9 and 10
  servoAtras.attach(10);
  pinMode(sensorPin, INPUT);                // set sensor pin to read signals  
  servoFrente.write(centro);              // center servos
  servoAtras.write(centro);
  
  delay(3000);                              // wait 3 seconds before starting walking
  //Serial.begin(9600);                     // serial data setup - for debugging
}

// busca distancia al obstaculo, desde el sensor
void scan()
{  
  // deteca 5 valores de distancia;.lll/
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
  // if servoCambio is 20 (20 degrees), the front servo goes from 90 to 70 to 90 to 110 to 90 degrees
  stepRightFootForward(); // step right
  stepLeftFootForward();  // back to neutral
  stepLeftFootForward();  // step left
  stepRightFootForward(); // back to neutral  
}

void stepRightFootForward()
{
  // gira el servo en pasos para mejorar la motión
  for (int stepNum = 0; stepNum < servoCambio; stepNum++)
  {
    servoFrentePos--;
    servoAtrasPos++; // back servo does the opposite of front servo          
    servoFrente.write(servoFrentePos);
    servoAtras.write(servoAtrasPos);
    delay(retrasoDelServo);
  }    
}

void stepLeftFootForward()
{
  // gira el servo en pasos para mejorar la motión
  for (int stepNum = 0; stepNum < servoCambio; stepNum++)
  {
    servoFrentePos++;
    servoAtrasPos--;    
    servoFrente.write(servoFrentePos);
    servoAtras.write(servoAtrasPos);
    delay(retrasoDelServo);
  }  
}

// camina hacia atrás y a la derecha
void moveBackRight()
{
  servoFrente.write(frenteDerechaArriba);
  servoAtras.write(avanzaDerechoPieDetrasDerecha-6);
  delay(110);
  servoFrente.write(centro);
  servoAtras.write(centro-6);
  delay(80);
  servoFrente.write(frenteIzquierdaArriba+9);
  servoAtras.write(avanzaDerechoPieDetrasIzquierda-6);
  delay(110);
  servoFrente.write(centro);
  servoAtras.write(centro);
  delay(80);
}

// camina derecho y a la izquierda
void moveTurnLeft()
{
  servoFrente.write(frontTurnRightUp);
  servoAtras.write(backTurnLeftForward);
  delay(110);
  servoFrente.write(posicionCentralDeVuelta);
  servoAtras.write(posicionCentralDeVuelta);
  delay(80);
  servoFrente.write(frontTurnLeftUp);
  servoAtras.write(backTurnRightForward);
  delay(110);
  servoFrente.write(posicionCentralDeVuelta);
  servoAtras.write(posicionCentralDeVuelta);
  delay(80);
}

// enciende/apaga la luz LED. Puedes llamar esta función en cualquiera situación en que te 
// gustaría encender la luz LED, solo escribe "led(5);", por ejemplo, para parpadear la luz.
void led(int numBlinks){
  // Papadear numBlinks veces
  for (int counter = 0; counter <= numBlinks; counter++) 
  {
    digitalWrite(13, HIGH); // Enciende la luz
    delay(50);              // Queda la luz encendida para 0.05 sec (50 milisegundos)
    digitalWrite(13, LOW);  // Apaga la luz
    delay(100);             // Queda la luz apagada para 0.1 sec (100 milisegundos)
  }  
}

// Esta función corre repetidamente
void loop()
{
  // busca para obstaculos
  scan();
  //Serial.println(distance);
  if (distance > 1) // filters out the zero readings
  {     
    // obstaclo detectado, enciende la luz
    if (distance > dangerDistance) 
    {    
      reactToDanger();
    } 
    else 
    {
      // no hay obstaculos detectados, camina     
      moveForward();
      delay(velocidad/100);
    }
  }
}

void reactToDanger()
{
  led(5); // Blink LED 5x
}

