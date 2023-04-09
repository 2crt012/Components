/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of capacitive fingerprint sensors.
 *  In this example, you will use the sensor to detect the fingerprints
 *  that you should have already registered using the 
 *  "Register_Fingerprint_Placitech_Example" file. The detection results
 *  will be displayed on the serial monitor.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

// Make sure to have these libraries installed
#include <DFRobot_ID809.h>
#include <SoftwareSerial.h>

// Declare sensor and set communication pins
DFRobot_ID809 fingerprint;
SoftwareSerial Serial2(6, 7);



void setup(){
  Serial.begin(9600);
  Serial2.begin(115200);
  fingerprint.begin(Serial2);

  while(fingerprint.isConnected() == false){
    Serial.println("Communication with sensor failed. Check connections");
    delay(2000);
  }

  Serial.println("Place your finger on the sensor");
  fingerprint.ctrlLED(fingerprint.eBreathing, fingerprint.eLEDBlue, 0);
}



void loop(){
  // This variable will tell you the ID assigned to the 
  // recognized fingerprint when it was registered
  uint8_t fp_id = 0;

  // Check if fingerprint was succesfully captured (Finger was placed on sensor correctly)
  if((fingerprint.collectionFingerprint(0)) != ERR_ID809){
    delay(100);
    fingerprint.ctrlLED(fingerprint.eKeepsOn, fingerprint.eLEDYellow, 0);
    Serial.println();
    Serial.println("Fingerprint succesfully captured.");
    Serial.println("Release your finger.");
    Serial.println();

    fp_id = fingerprint.search(); // Determine if fingerprint is registered

    // Wait for finger to be released
    while(fingerprint.detectFinger()){
      delay(100);
    }

    // Display result on serial monitor
    
    if (fp_id != 0){ // If recognized
      fingerprint.ctrlLED(fingerprint.eKeepsOn, fingerprint.eLEDGreen, 0);
      Serial.println("Fingerprint recognized. ID = " + String(fp_id));
    }

    else { // If not recognized
      Serial.println("Fingerprint NOT recognized");
      fingerprint.ctrlLED(fingerprint.eKeepsOn, fingerprint.eLEDRed, 0);
    }

    delay(2000);
    Serial.println();
    Serial.println("Place your finger on the sensor.");
    fingerprint.ctrlLED(fingerprint.eBreathing, fingerprint.eLEDBlue, 0);
  }

  // If fingerprint was not placed on sensor correctly, let the user know
  else {
    Serial.println();
    Serial.println("Fingerprint capturing failed. Try again.");  
  }

  delay(500);
}
