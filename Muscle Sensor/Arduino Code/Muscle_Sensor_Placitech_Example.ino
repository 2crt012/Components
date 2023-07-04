/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of muscle sensors. In this example
 *  you will read the analog output of the sensor and display it on the
 *  Serial Monitor. By doing this, you'll be able to determine the specific
 *  values read whenever you flex your muscle or when it is resting.
 *  Then, you can then use these values to control anything that your mind can 
 *  think of! For example, you can make an LED turn on whenever the output
 *  of the sensor is greater than 1.5 V and turn off when it is lower than that.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

#define sensor A4
int val;
float voltage;


void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
}

void loop() {
  // Read the sensor's output
  val = analogRead(sensor);

  // Convert it into a voltage
  voltage = (val/1023)*5;

  // Display it on Serial Monitor
  Serial.println("Value: " + String(val) + " | Voltage: " + String(voltage) + " V");
  Serial.println();
  delay(10);
}
