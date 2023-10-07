// Define the pins for the ultrasonic sensor
const int trigPin = 9;  // Trigger pin
const int echoPin = 8; // Echo pin

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Set trigPin as OUTPUT and echoPin as INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a pulse to the trigger pin to start the measurement
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the speed of sound (343 m/s at room temperature)
  // and the time taken for the echo to return
  float distance = (duration * 0.0343) / 2; // Divide by 2 because of the two-way trip

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Add a delay before the next measurement
  delay(1000);
}
