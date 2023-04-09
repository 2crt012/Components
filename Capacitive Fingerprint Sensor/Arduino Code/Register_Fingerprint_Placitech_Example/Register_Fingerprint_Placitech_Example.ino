/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of capacitive fingerprint sensors.
 *  In this example, you will be able to register up to 80 fingerprints  
 *  in this sensor. The registration steps will be displayed on the serial monitor.
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

  fingerprint.ctrlLED(fingerprint.eBreathing, fingerprint.eLEDBlue, 0);
}


void loop(){
  // Get the next available ID for the fingerprint that will be registered.
  uint8_t fp_id = fingerprint.getEmptyID();
  Serial.println("The registered fingerprint will have the ID: " + String(fp_id));
  Serial.println();
  
  int i = 0;

  // Get samples
  while(i < 3){
    fingerprint.ctrlLED(fingerprint.eBreathing, fingerprint.eLEDBlue, 0);
    Serial.println("Fingerprint sample number: " + String(i+1));
    Serial.println("Place finger on sensor.");
    Serial.println();

    if((fingerprint.collectionFingerprint(10)) != ERR_ID809){
      Serial.println("Sampling successful.");
      fingerprint.ctrlLED(fingerprint.eKeepsOn, fingerprint.eLEDYellow, 0);
      i++;
      delay(1000);
    }
    
    else {
      Serial.println("Sampling failed.");
      fingerprint.ctrlLED(fingerprint.eKeepsOn, fingerprint.eLEDRed, 0);
      delay(1000);
    }

    Serial.println();
    Serial.println("Release your finger.");
    Serial.println();
    
    while(fingerprint.detectFinger()){
      delay(100);
    }
  }

  // Register sampled fingerprint
  if (fingerprint.storeFingerprint(fp_id) != ERR_ID809){
    Serial.println("Fingerprint succesfully registered with ID: " + String(fp_id));
    fingerprint.ctrlLED(fingerprint.eKeepsOn, fingerprint.eLEDGreen, 0);
  }
  
  else {
    Serial.println("Saving failed");
    fingerprint.ctrlLED(fingerprint.eKeepsOn, fingerprint.eLEDRed, 0);
  }

  Serial.println();
  delay(2000);
}
