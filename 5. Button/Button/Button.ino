const int buttonPin = 2;  // Button connected to digital pin 2

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Set the pin as input with pull-up
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);  // Read the button state

  if (buttonState == LOW) {
    Serial.println("Button is pressed!");
  } else {
    Serial.println("Button is not pressed.");
  }

  delay(100);  // Small delay to avoid rapid button presses
}
