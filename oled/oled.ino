#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128  // OLED display width,  in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);


  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true)
      ;
  }

  delay(2000);          // wait for initializing
  oled.clearDisplay();  // clear display
}

void loop() {
  for (int y = 0; y < 10; y++) {
    oled.setTextSize(2);       // text size
    oled.setTextColor(WHITE);  // text color
    oled.setCursor(0, 16);     // position to display
    oled.println("!@#$%^&*()" + y);     // text to display
    oled.display();            // show on OLED
    delay(1000);

    oled.clearDisplay();  // clear display
  }
}
