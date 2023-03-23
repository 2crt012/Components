/*   Author: PLACITECH. DIY and Funny videos!
 *   
 *   Tiktok: @placitech
 *   Instagram: @placitech_
 *   YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of 7-segment displays. In this example
 *  you will use a TM1637 module as a scoreboard. There will be 2 scores 
 *  (left and right) that you will be able able to change using push buttons.

 *  I used for this example is an Arduino Nano, but you can use any Micro
 *  that you have, like the Arduino UNO or MEGA.
 *  
*/

// You'll need this library, so make sure to have it downloaded
#include <TM1637Display.h>

// Define TM1637 and Buttons pins
#define CLK 2
#define DIO 3
#define left_but 9
#define right_but 7

// Declare display
TM1637Display scoreboard(CLK, DIO);

// Score variables 
byte left_score;
byte right_score;


// Function used to set the score on the display
void set_score(int left, int right){
  scoreboard.showNumberDecEx(left, 0x40, true, 2, 0);
  scoreboard.showNumberDecEx(right, 0x40, true, 2, 2);
}



void setup() {
  Serial.println("Scoreboard using a TM1637 7-Segment Display");
  pinMode(left_but, INPUT_PULLUP);
  pinMode(right_but, INPUT_PULLUP);
  scoreboard.setBrightness(7); // You can choose from 0 (lowest brightness) to 7 (highest brightness)
  set_score(0, 0);
}



void loop() {
 // Wait until a button is pressed
  while ((digitalRead(left_but) == HIGH) && (digitalRead(right_but) == HIGH)){
    delay(10);
  }  

  // If left button is pressed, increase count by 1
  if (digitalRead(left_but) == LOW){
    while (digitalRead(left_but) == LOW){ // Wait for left button to be released
      delay(10);
    }
    
    left_score++; // Increase left score
    if (left_score > 99){
      left_score = 0;
    }
  }
  
  // If right button is pressed, increase count by 1
  else if (digitalRead(right_but) == LOW){
    while (digitalRead(right_but) == LOW){ // Wait for right button to be released
      delay(10);
    }
    
    right_score++; // Increase right score
    if (right_score > 99){
      right_score = 0;
    }
  }

  // Update score
  set_score(left_score, right_score);
}
