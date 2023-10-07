/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-relay
 */

// constants won't change
const int RELAY_PIN = 4;  // the Arduino pin, which connects to the IN pin of relay

// the setup function runs once when you press reset or power the board
void setup() {
  digitalWrite(RELAY_PIN, LOW);
  // initialize digital pin as an output.
  pinMode(RELAY_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RELAY_PIN, 1);
  delay(300);
  digitalWrite(RELAY_PIN, 0);
  delay(500);
  
}
