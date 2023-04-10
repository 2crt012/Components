/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of OLED displays. In this example
 *  you will print any message you want on the display by sending it
 *  via the serial monitor. This specific example is for 128x128 Color OLED
 *  displays. Also, the amount of text that you can print is finite, so make sure
 *  to send messages that can fit the screen.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

// Make sure you have these libraries installed
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

// Display dimensions
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 128

// Assign pins
#define MOSI_PIN 2
#define SCLK_PIN 3
#define CS_PIN   4
#define DC_PIN   5
#define RST_PIN  6

// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

// Declare display
Adafruit_SSD1351 oled = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, CS_PIN, DC_PIN, MOSI_PIN, SCLK_PIN, RST_PIN);  


// I created this basic function to print text more efficiently and clean
void oled_print(String txt){
  oled.fillScreen(BLACK);
  oled.setCursor(0, 0);
  oled.print(txt);
}



void setup(void) {
  Serial.begin(9600);
  oled.begin();
  oled.setRotation(0); // You can choose any value between 0-3. This will change the text orientation
  oled.setTextSize(2);
  oled.fillScreen(BLACK); // Clear display
  oled.setTextColor(WHITE); // You can set this to any of the colors defined above
}



void loop() {
  // Wait for input from serial monitor
  while (!Serial.available()){
    delay(10);
  }

  // Get text in the form of a string 
  String input = Serial.readString();

  // Print text
  oled_print(input);
}
