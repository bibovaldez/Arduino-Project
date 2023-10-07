const int PIN_TO_SENSOR = 2;  // the pin that OUTPUT pin of the sensor is connected to
const int ledpin = 3;
int pinStateCurrent = LOW;   // current state of pin
int pinStatePrevious = LOW;  // previous state of pin
bool ledOn = false;          // flag to track LED state

void setup() {
  Serial.begin(9600);             // initialize serial
  pinMode(PIN_TO_SENSOR, INPUT);  // set Arduino pin to input mode to read value from OUTPUT pin of sensor
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // Read the current state of the sensor
  pinStatePrevious = pinStateCurrent;
  pinStateCurrent = digitalRead(PIN_TO_SENSOR);

  // Check if the state has changed from LOW to HIGH (motion detected)
  if (pinStatePrevious == LOW && pinStateCurrent == HIGH) {
    ledOn = !ledOn;  // Toggle the LED state
    digitalWrite(ledpin, ledOn ? HIGH : LOW);

    if (ledOn) {
      Serial.println("LED ON");
    } else {
      Serial.println("LED OFF");
    }

    delay(500);  // Add a delay to avoid multiple rapid toggles
  }
}
