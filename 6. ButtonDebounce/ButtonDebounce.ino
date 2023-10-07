const int buttonPin = 2;  // Button connected to digital pin 2
const int ledPin = 13;    // LED connected to digital pin 13

int buttonState = HIGH;   // Current state of the button
int lastButtonState = HIGH; // Previous state of the button
int ledState = LOW;       // Current state of the LED

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
        if (ledState == HIGH) {
          Serial.println("LED turned ON");
        } else {
          Serial.println("LED turned OFF");
        }
      }
    }
  }

  lastButtonState = reading;
}
