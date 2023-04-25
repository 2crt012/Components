/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of N-Channel MOSFETs. In this example
 *  you will turn an LED on and off by setting a digital pin HIGH (5V) and
 *  LOW (GND) respectively. The LED is just an example of a load you could
 *  connect to the MOSFET. You could also turn on motors, electromagnets,
 *  strip lights, etc. 
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

#define gate = 5;

void setup() {
  Serial.begin(9600);
  pinMode(gate, OUTPUT);
}

void loop() {
  digitalWrite(gate, HIGH);
  Serial.println("N-Channel MOSFET ON")
  delay(3000);
  
  digitalWrite(gate, LOW);
  Serial.println("N-Channel MOSFET OFF")
  delay(3000);
}
