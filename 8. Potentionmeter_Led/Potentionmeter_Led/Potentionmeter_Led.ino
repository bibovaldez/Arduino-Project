const int analogPin = A0;   // Analog input pin for the potentiometer
const int ledPin = 2;       // PWM (Pulse Width Modulation) pin for the LED

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(analogPin);     // Read the potentiometer value (0-1023)
  int brightness = map(potValue, 0, 1023, 0, 255);  // Map the potentiometer value to LED brightness range (0-255)
  
  analogWrite(ledPin, brightness);  // Set the LED brightness using PWM
  
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print("\tBrightness: ");
  Serial.println(brightness);
  
  delay(100);  // Delay for stability and easier observation
}
