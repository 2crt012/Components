/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of heart rate sensor. This example
 *  is basically the one that you get with the SparkFun MAX3010X library.
 *  I just modified the sample size from 4 to 8 since I believe it makes
 *  the readings more accurate, so shoutout to them! In order to read the
 *  data, you will use the serial monitor. It will take a few seconds for
 *  it to start once you place your finger on the sensor. Use the Avg BPM
 *  for the best approximation.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

// Make sure to have the SparkFun MAX3010X library installed
#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

MAX30105 hrSensor;

const byte RATE_SIZE = 8; // Increase this for more averaging. 8 is optimal. If you want it to be faster, change it to 4
byte rates[RATE_SIZE];
byte rateSpot = 0;
long lastBeat = 0; 

float beatsPerMinute;
int beatAvg;



void setup(){
  Serial.begin(9600);

  if (!hrSensor.begin(Wire, I2C_SPEED_FAST)){
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }
  
  Serial.println("Place your index finger on the sensor");
  Serial.println();

  hrSensor.setup(); //Configure sensor with default settings
  hrSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  hrSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
}



void loop(){
  long irValue = hrSensor.getIR();

  if (checkForBeat(irValue) == true){
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20){
      rates[rateSpot++] = (byte)beatsPerMinute;
      rateSpot %= RATE_SIZE;

      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
    Serial.print("IR=");
    Serial.print(irValue);
    Serial.print(", BPM=");
    Serial.print(beatsPerMinute);
    Serial.print(", Avg BPM=");
    Serial.print(beatAvg);
    Serial.println();
  }

  if (irValue < 50000){
    Serial.println("No finger?");
    delay(250);
  }
}
