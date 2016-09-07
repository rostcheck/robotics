// sense-distance
// Read the distance sensor and output its reading to the serial port

// This function runs only once, when the Arduino starts
void setup() {  
  pinMode(13, OUTPUT);      // configure pin 13 - which controls the LED - to send signals
  pinMode(A1, INPUT);       // set sensor pin, A1 to read signals    
  Serial.begin(9600);       // serial data setup  
}

// This function runs repeatedly
void loop() {
  int sensorValue = scan();
  Serial.println(sensorValue); 
  digitalWrite(13, HIGH);     // Turn on the LED
  delay(1000);  // Wait (in milliseconds)
  digitalWrite(13, LOW);      // Turn off the LED
  delay(1000);  // Wait (in milliseconds)
}

int scan() {
  return analogRead(A1);
}

