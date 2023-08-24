/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of Capacitive Soil Moisture Sensors.
 *  In this example you will read the output of the sensor using the Serial
 *  Monitor. In order to see a change in the readings, first put the sensor
 *  inside a planter that has dry soil. Write down the value and then pour water
 *  into the planter and save the reading you get. You can use those values
 *  to make a device that constantly checks your plant's moisture and tells
 *  you when you have to irrigate them.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/
#define read_pin A5


void setup() {
  Serial.begin(9600);
  pinMode(read_pin, INPUT);
}



void loop() {
  // Read voltage level
  int reading = analogRead(read_pin);
  Serial.println(reading);
  delay(100);
}
