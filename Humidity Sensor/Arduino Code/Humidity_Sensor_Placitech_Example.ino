/*   Author: PLACITECH. DIY and Funny videos!
 *   
 *   Tiktok: @placitech
 *   Instagram: @placitech_
 *   YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of humidity sensors. In this example
 *  you will print the ambient humidity and temperature on the Serial monitor
 *  by reading the data from the DHT11 module.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

// Make sure to have this library installed
#include "DHT.h"

#define DHTPIN 5 
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  dht.begin();
  delay(1000);
}


void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.println("Humidity: " + String(h) + "%  Temperature: " + String(t));
  Serial.println();

  delay(1000);
}
