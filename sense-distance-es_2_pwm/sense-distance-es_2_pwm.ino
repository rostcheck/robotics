// sense-distance
// Lea el sensor de distancia y escribe su valor al puerto serial

// Esta función corre solo una vez, cuando empiece el Arduino
void setup() {  
  pinMode(13, OUTPUT);      // configura clavija 13 - que controla el luz LED - para enviar señales
  pinMode(A1, INPUT);       // set sensor pin, A1 to read signals    
  Serial.begin(9600);       // serial data setup  
}

// Esta función corre repetidamente 
void loop() {
  int valorDeSensor = escanear();
  // Valores tipicos del sensor son de 20-600
  // Convierte el valor del rango desde 0 hasta 255
  int intensidad = (valorDeSensor - 20) / 2.47;
  if (intensidad < 20)
    intensidad = 0;                  // Forzar valores chicos (ruido del sensor) a 0
  //Serial.println(valorDeSensor); 
  analogWrite(13, intensidad);       // Fijar intensidad del LED
}

int escanear() {
  return analogRead(A1);
}

