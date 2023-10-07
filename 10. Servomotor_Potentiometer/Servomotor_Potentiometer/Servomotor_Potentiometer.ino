

#include <Servo.h>
const int pote= A0;
Servo servo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  servo.attach(11);  // attaches the servo on pin 9 to the servo object
  pinMode(pote, INPUT);
}

void loop() {
  int get = analogRead(pote);
  int madp = map(get, 0, 1023, 0, 180);
  servo.write(madp);

 
}
