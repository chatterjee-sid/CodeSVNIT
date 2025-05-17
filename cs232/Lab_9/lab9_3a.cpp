const int potPin = A0;     // Potentiometer connected to A0
const int motorPin = 9;    // Motor control (PWM) pin

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);       // Read potentiometer (0-1023)
  int motorSpeed = map(potValue, 0, 1023, 0, 255); // Map to PWM range
  analogWrite(motorPin, motorSpeed);       // Control motor speed
}
