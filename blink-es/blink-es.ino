// Blink.es 
// Enciende y apaga la luz LED - adjunto a clavija 13 - para un segundo 

// Esta función corre solo una vez, cuando empiece el Arduino
void setup() {
  // configura clavija 13 - que controla el luz LED - para enviar señales
  pinMode(13, OUTPUT);
}

// Esta función corre repetidamente
void loop() {
  digitalWrite(13, HIGH);   // Encender la luz
  delay(1000);              // Espera un segundo (1000 milisegundos)
  digitalWrite(13, LOW);    // Apagar la luz
  delay(1000);              // Espera un segundo
}
