// Blink
// Turn the LED - attached to pin 13 - on and off

// This function runs only once, when the Arduino starts
void setup() {
  // configure pin 13 - which controls the LED - to send signals
  pinMode(13, OUTPUT);
}

// This function runs repeatedly
void loop() {
  digitalWrite(13, HIGH);   // Turn on the LED
  delay(3000);              // Wait (in milliseconds)
  digitalWrite(13, LOW);    // Turn off the LED
  delay(1000);              // Wait (in milliseconds)
}
