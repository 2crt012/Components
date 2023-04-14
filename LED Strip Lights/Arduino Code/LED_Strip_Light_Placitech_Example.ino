/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of controlling LED Strip Lights based
 *  on the WS2812B controller. In this example, you will set the LEDs color
 *  by sending the values of their Red, Green and Blue elements via the
 *  serial monitor. Those values go from 0 to 255, so make sure to input
 *  valid numbers.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
*/

// Make sure to have this library installed
#include <FastLED.h>

#define NUM_LEDS 3 // Change this number to the amount of LEDs you are using
#define LED_PIN 5

// Declare LEDs
CRGB led[NUM_LEDS];

// Color variables
byte red;
byte green;
byte blue;


// Function used to get values from serial monitor
int get_val(){
  // Wait for input
  while (!Serial.available()){
    delay(10);
  }

  // Get value from serial monitor
  int val[2];
  int i = 0;
  while (Serial.available()){
    val[i] = Serial.parseInt();
    i++;
    delay(10);
  }

  // If value entered is out of range, fix it
  if (val[0] > 255){
    val[0] = 255;
  }

  else if (val[0] < 0){
    val[0] = 0;
  }

  Serial.println("Value sent: " + String(val[0]));
  return val[0];
}


// Function used to set the LEDs color
void all_leds(byte R, byte G, byte B){
  for(int i = 0; i < NUM_LEDS; i++){
    led[i] = CRGB(R, G, B);
  }
  FastLED.show();
}



void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, LED_PIN>(led, NUM_LEDS);
  all_leds(0, 0, 0); // Turn off LEDs when program first starts
}



void loop() {
  // Get values
  Serial.println("Enter a value between 0-255 for Red");
  red = get_val();
  Serial.println();
  Serial.println("Enter a value between 0-255 for Green");
  green = get_val();
  Serial.println();
  Serial.println("Enter a value between 0-255 for Blue");
  blue = get_val();

  // Set LEDs color
  all_leds(red, green, blue);
  Serial.println();
  Serial.println("LED lights color succesfully set");
  Serial.println();
}
