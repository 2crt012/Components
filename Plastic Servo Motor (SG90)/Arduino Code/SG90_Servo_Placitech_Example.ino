/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of 180 degrees servo motors. In this
 *  example you will rotate the motor by sending the desired angle via the
 *  serial monitor. Remember that the angle must be between 0 and 180 degrees.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

// This library should already be installed with the Arduino IDE
#include <Servo.h>

// Declare servo
Servo servito;

// Create an empty list. We'll use this to store the values
// sent via the serial monitor
int ang[2] = {};


void setup() {
  Serial.begin(9600);
  servito.attach(5);
  servito.write(90); // Set the initial position of the servo to 90 degrees
}



void loop() {
  // Wait for angle
  Serial.println("Please enter an angle between 0 and 90 degrees");
  while (!Serial.available()){
    delay(10);
  }

  // Store the angle in the list. Since the serial monitor sends a "0" after the data has
  // been transfered, we'll store it in the list but we won't use it.
  int i = 0;
  while (Serial.available()){
    ang[i] = Serial.parseInt();
    i++;
    delay(10);
  }

  // Rotate servo
  servito.write(ang[0]);
  
  Serial.println("Servo set to " + String(ang[0]) + " degrees");
  Serial.println();
}