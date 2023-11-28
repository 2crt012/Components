/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of Time-of-Flight distance sensors.
 *  In this example you will read the output of the sensor using the Serial
 *  Monitor. The way this sensor works is by sending a light pulse and
 *  determining how long it takes to get reflected. Depending on this, the 
 *  sensor will calculate the distance between any object and itself.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
*/

// Make sure you have this library installed
#include "Adafruit_VL53L0X.h"

// Declare sensor
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

// Function used to retrieve distance from sensor
void get_dist(){
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    int dist = measure.RangeMilliMeter/10.0;
  }
  
  Serial.println("Distance: " + String(dist) + " cm");
  Serial.println();
}



void setup() {
  Serial.begin(9600);

  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
}



void loop() {
  get_dist();
  delay(10);
}