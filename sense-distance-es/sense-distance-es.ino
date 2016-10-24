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
  Serial.println(valorDeSensor); 
  digitalWrite(13, HIGH);     // Encender la luz
  delay(1000);                // Espera (en milisegundos)
  digitalWrite(13, LOW);      // Apagar la luz
  delay(1000);                // Espera un segundo (en milisegundos)
}

int escanear() {
  return analogRead(A1);
}

