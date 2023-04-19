/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of Flame Sensors. In this example
 *  you will read the digital output of the sensor to show when fire
 *  is detected and let the user know using the serial monitor.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/
#define sensor 5


void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
}



void loop() {
  // Check if fire was detected
  if (digitalRead(sensor) == HIGH){
    // Print message on serial monitor
    Serial.println("Fire detected!");
    Serial.println();

    // Wait until fire is extiguished
    while (digitalRead(sensor) == HIGH){
      delay(100);
    }

    Serial.println("Vigilant");
    Serial.println();
  }

  delay(100);
}
