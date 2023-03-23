/*   Author: PLACITECH. DIY and Funny videos!
 *   
 *   Tiktok: @placitech
 *   Instagram: @placitech_
 *   YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of MP3 Modules. In this example
 *  you will use the DFPlayerMini module to play or stop the first song
 *  stored in a MicroSD Card. You'll control this using a push button.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/
// Make sure to have these libraries installed
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h" 

SoftwareSerial mySoftwareSerial(10, 11);
DFRobotDFPlayerMini mp3module;

const byte button = 3;


// Function used to wait for button press and release
void wait_but(){
  while (digitalRead(button) == HIGH){
    delay(10);
  }

  while (digitalRead(button) == LOW){
    delay(10);
  }
}



void setup(){
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!mp3module.begin(mySoftwareSerial)) { 
    Serial.println("Unable to connect to module!");
    Serial.println("Check cable connections and");
    Serial.println("make sure SD Card is inserted");
    while(1);
  }
  
  Serial.println("Succesfully connected to DFPlayer Mini");
  
  mp3module.setTimeOut(500); // Set serial communictaion time out to 500 ms
  mp3module.volume(25);  //Set volume value (0-30).
  mp3module.EQ(DFPLAYER_EQ_NORMAL); // Set equalization to normal
  mp3module.outputDevice(DFPLAYER_DEVICE_SD); // Read music from MicroSD card
}



void loop(){
  wait_but();
  mp3module.play(1);  // Play the first mp3
  wait_but();
  mp3module.stop();  // Stop playing
}
