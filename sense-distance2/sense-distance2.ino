// sense-distance2
// Turn the LED - attached to pin 13 - on and off more rapidly as an object gets closer
// Print the sensor readings out to the serial console

// This function runs only once, when the Arduino starts
void setup() {  
  pinMode(13, OUTPUT);      // configure pin 13 - which controls the LED - to send signals
  pinMode(A1, INPUT);       // set sensor pin, A1 to read signals
  //Serial.begin(9600);       // serial data setup
}

// This function runs repeatedly
void loop() {
  int sensorValue = scan();
  // Typical sensor values are around 20-600. 
  // Convert it to a range from 14 to 1
  int sensorDelay = 14 - (sensorValue / 50);
  Serial.println(sensorDelay); 
  digitalWrite(13, HIGH);     // Turn on the LED
  delay(sensorDelay * 80);    // Wait (in milliseconds)
  digitalWrite(13, LOW);      // Turn off the LED
  delay(sensorDelay * 80);    // Wait (in milliseconds)
}

int scan() {
  return analogRead(A1);
}
