
const int PIN_TO_SENSOR = 2;   // the pin that OUTPUT pin of sensor is connected to
int pinStateCurrent   = LOW; // current state of pin


void setup() {
  Serial.begin(9600);            // initialize serial
  pinMode(PIN_TO_SENSOR, INPUT); // set arduino pin to input mode to read value from OUTPUT pin of sensor
}

void loop() {
  pinStateCurrent = digitalRead(PIN_TO_SENSOR);
  Serial.println(pinStateCurrent);
}
