/*   Author: PLACITECH. DIY and Funny videos!
 *   
 *   Tiktok: @placitech
 *   Instagram: @placitech_
 *   YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of accelerometers. In this example
 *  you will determine the value of the acceleration due to gravity on
 *  all 3 axes of this sensor and display it on the Serial Monitor.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, 
 *  but you can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

// Make sure to have these libraries installed
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// Declare accelerometer
Adafruit_MPU6050 Acc;


void setup(void) {
  Serial.begin(9600);

  if (!Acc.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  // Standard setting for MPU6050
  Acc.setAccelerometerRange(MPU6050_RANGE_8_G); 
  Acc.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
}



void loop() {
  // Get info from accelerometer
  sensors_event_t a, g, temp;
  Acc.getEvent(&a, &g, &temp);

  // Save the values in variables
  float x_axis = a.acceleration.x;
  float y_axis = a.acceleration.y;
  float z_axis = a.acceleration.z;

  // Display the values
  Serial.println("X axis: " + String(x_axis) + " |  Y axis: "
  + String(y_axis) + " |  Z axis: " + String(z_axis) + " -- m/s^2");
  Serial.println();

  delay(100);
}
