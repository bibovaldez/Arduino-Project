String command;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');

    if (command.equals("on")) {
      digitalWrite(13, HIGH);
    } else if (command.equals("off")) {
      digitalWrite(13, LOW);
    }
  }
  int data = analogRead(A0);
  data = map(data, 0, 1023, 0, 100);  // Corrected mapping
  Serial.println(data);
}