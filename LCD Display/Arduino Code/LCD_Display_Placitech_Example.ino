/*   Author: PLACITECH. DIY and Funny videos!
 *   
 *   Tiktok: @placitech
 *   Instagram: @placitech_
 *   YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of LCD Displays. In this example
 *  you will print any message you want on the display by sending it
 *  via the serial monitor. This specific example is for 16x2 displays,
 *  which means that your message cannot be longer than 32 character.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

// Make sure to have these libraries installed
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Declare LCD Display
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD address of 0x27 for a 16-column and 2-line display


// I created this function to print messages in an easier way 
void lcd_print(String txt){
  txt.trim(); // Eliminate whitespaces from the end of the message
  lcd.clear(); // Erase all letter from the display
  lcd.setCursor(0, 0);

  // Print each letter and space individually
  for (int i = 0; i < txt.length(); i++){
     
    if (i == 16){ // Once the first 16 characters have been printed, switch to row 2
      lcd.setCursor(0, 1);
      // If the first character of row 2 is a space, ignore it
      if (txt[i] == ' '){
        i = 17;
      }
    }

    // If the message is longer than 32 characters (or 33, if there is an ignored 
    // space at the beginning of the second row), then the remaining text will be cut
    else if (i == 33){
      break;
    }
    
    lcd.print(txt[i]);
  }
}


  
void setup(){
  Serial.begin(9600);
  lcd.init();     
  lcd.backlight(); // Turn on backlight
}



void loop(){
  // Wait for message to be sent via the serial monitor
  while (!Serial.available()){
    delay(10);
  }

  // Get message in the form of a string
  String text = Serial.readString();

  // Print message
  lcd_print(text);
}
