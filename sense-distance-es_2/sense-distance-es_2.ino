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
  // Convierte el valor del rango desde 14 hasta 1
  int retrasoDeSensor = 14 - (valorDeSensor / 50);
  //Serial.println(valorDeSensor); 
  digitalWrite(13, HIGH);       // Encender la luz
  delay(retrasoDeSensor * 80);  // Espera (en milisegundos)
  digitalWrite(13, LOW);        // Apagar la luz
  delay(retrasoDeSensor * 80);  // Espera (en milisegundos)
}

int escanear() {
  return analogRead(A1);
}

