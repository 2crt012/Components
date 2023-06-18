/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of PIR Sensors. In this example
 *  you will read the digital output of the sensor to show when a person
 *  is detected and let the user knowby turning on an LED.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/
#define sensor 5
#define led 2


void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}



void loop() {
  // Check if person was detected
  if (digitalRead(sensor) == HIGH){
    // Print message on serial monitor
    Serial.println("Person detected!");
    Serial.println();
    digitalWrite(led, HIGH); // Turn On LED

    // Wait until the sensor's timer ends
    while (digitalRead(sensor) == HIGH){
      delay(100);
    }

    digitalWrite(led, LOW); // Turn Off LED
  }

  delay(100);
}
