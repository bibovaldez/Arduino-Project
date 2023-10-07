const int segmentPin1[7] = { 2, 3, 4, 5, 6, 7, 8 };
const int segmentPin2[7] = { 9, 10, 11, 12, 13, A0, A1 };
const int btn1 = A2;
const int btn2 = A3;
const int btn3 = A4;
const int btn4 = A5;

int bt1 = 0;
int bt2 = 0;
int bt3 = 0;
int bt4 = 0;

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

void display(int num2, int num1) {
  for (int u = 0; u < 7; u++) {
    digitalWrite(segmentPin1[u], number[num1][u]);
    digitalWrite(segmentPin2[u], number[num2][u]);
  }
}

void decoder(int bt1, int bt2, int bt3, int bt4) {
  if (bt1 == LOW && bt2 == LOW && bt3 == LOW && bt4 == LOW) {
    display(0,0);
  } else if (bt1 == LOW && bt2 == LOW && bt3 == LOW && bt4 == HIGH) {
    display(0,1);    
  } else if (bt1 == LOW && bt2 == LOW && bt3 == HIGH && bt4 == LOW) {
    display(0,2);  
  } else if (bt1 == LOW && bt2 == LOW && bt3 == HIGH && bt4 == HIGH) {
    display(0,3);  
  } else if (bt1 == LOW && bt2 == HIGH && bt3 == LOW && bt4 == LOW) {
    display(0,4);  
  } else if (bt1 == LOW && bt2 == HIGH && bt3 == LOW && bt4 == HIGH) {
    display(0,5);  
  } else if (bt1 == LOW && bt2 == HIGH && bt3 == HIGH && bt4 == LOW) {
    display(0,6);  
  } else if (bt1 == LOW && bt2 == HIGH && bt3 == HIGH && bt4 == HIGH) {
    display(0,7);  
  } else if (bt1 == HIGH && bt2 == LOW && bt3 == LOW && bt4 == LOW) {
    display(0,8);  
  } else if (bt1 == HIGH && bt2 == LOW && bt3 == LOW && bt4 == HIGH) {
    display(0,9);  
  } else if (bt1 == HIGH && bt2 == LOW && bt3 == HIGH && bt4 == LOW) {
    display(1,0);  
  } else if (bt1 == HIGH && bt2 == LOW && bt3 == HIGH && bt4 == HIGH) {
    display(1,1);  
  } else if (bt1 == HIGH && bt2 == HIGH && bt3 == LOW && bt4 == LOW) {
    display(1,2);  
  } else if (bt1 == HIGH && bt2 == HIGH && bt3 == LOW && bt4 == HIGH) {
    display(1,3);  
  } else if (bt1 == HIGH && bt2 == HIGH && bt3 == HIGH && bt4 == LOW) {
    display(1,4);  
  } else if (bt1 == HIGH && bt2 == HIGH && bt3 == HIGH && bt4 == HIGH) {
    display(1,5);  
  }

}

void setup() {
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);

  for (int i = 0; i < 7; i++) {
    pinMode(segmentPin1[i], OUTPUT);
    pinMode(segmentPin2[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  bt1 = digitalRead(btn1);
  bt2 = digitalRead(btn2);
  bt3 = digitalRead(btn3);
  bt4 = digitalRead(btn4);
  decoder(bt1, bt2, bt3, bt4);
}
