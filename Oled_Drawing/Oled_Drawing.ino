/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-oled
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(2000); // wait for initializing
  oled.setCursor(0, 0);
}

void loop() {
  // draw rectangle
  oled.clearDisplay();
  oled.drawRect(0, 15, 60, 40, WHITE);
  oled.display();
  delay(2000);

  // fill rectangle
  oled.clearDisplay();
  oled.fillRect(0, 15, 60, 40, WHITE);
  oled.display();
  delay(2000);


  // draw the round rectangle
  oled.clearDisplay();
  oled.drawRoundRect(0, 15, 60, 40, 8, WHITE);
  oled.display();
  delay(2000);

  // fill the round rectangle
  oled.clearDisplay();
  oled.fillRoundRect(0, 15, 60, 40, 8, WHITE);
  oled.display();
  delay(2000);

  // draw circle
  oled.clearDisplay();
  oled.drawCircle(20, 35, 20, WHITE);
  oled.display();
  delay(2000);

  // fill circle
  oled.clearDisplay();
  oled.fillCircle(20, 35, 20, WHITE);
  oled.display();
  delay(2000);

  // draw triangle
  oled.clearDisplay();
  oled.drawTriangle(30, 15, 0, 60, 60, 60, WHITE);
  oled.display();
  delay(2000);

  // fill triangle
  oled.clearDisplay();
  oled.fillTriangle(30, 15, 0, 60, 60, 60, WHITE);
  oled.display();
  delay(2000);
}
