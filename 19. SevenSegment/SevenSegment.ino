// seven segment display

const int pinS[7] = { 2, 3, 4, 5, 6, 7, 8 };

const int number[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  //0
  { 0, 1, 1, 0, 0, 0, 0 },  //1
  { 1, 1, 0, 1, 1, 0, 1 },  //2
  { 1, 1, 1, 1, 0, 0, 1 },  //3
  { 0, 1, 1, 0, 0, 1, 1 },  //4
  { 1, 0, 1, 1, 0, 1, 1 },  //5
  { 1, 0, 1, 1, 1, 1, 1 },  //6
  { 1, 1, 1, 0, 0, 0, 0 },  //7
  { 1, 1, 1, 1, 1, 1, 1 },  //8
  { 1, 1, 1, 1, 0, 1, 1 }   //9
};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 7; i++) {  // Changed the loop condition to < 7
    pinMode(pinS[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int y = 0; y < 10; y++) {  // Changed the loop condition to < 7
    for (int i = 0; i < 7; i++) {
      digitalWrite(pinS[i], number[y][i]);
    }
    delay(500);
  }
}
