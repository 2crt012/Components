/*   Author: PLACITECH. DIY and Funny videos!
 *   
 *   Tiktok: @placitech
 *   Instagram: @placitech_
 *   YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of microphone modules. In this example
 *  you will control an LED by clapping! Using an Arduino, you will read the 
 *  microphone output and determine when a 2 loud sounds are produced consecutively
 *  in order to change the status of the LED.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, 
 *  but you can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/
// Define variables and pins
#define mic A5
#define led 2
byte stat = 0;



void setup() {
  Serial.begin(9600);

  pinMode(mic, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}



void loop() {
  beg:

  // Read the value of the microphone output
  int val = analogRead(mic);

  // If the value if higher than 800, it means the user has clapped once
  if (val > 800){
    delay(10);
    Serial.println("First clap detected");
    
    // Wait 100 ms and read the microphone output again
    delay(100);
    val = analogRead(mic);

    // If the user hasn't clapped a second time, keep reading the 
    // microphone output for about 2 more seconds. If no clap is detected,
    // reset the loop
    int time1 = millis();
    while (val < 800){
      delay(1);
      if (millis() - time1 >= 2000){
        Serial.println();
        goto beg;
      }
      val = analogRead(mic);
    }

    // If a second clap is detected, change the LED status (If OFF, turn ON and viceversa)
    Serial.println("Second clap detected. Changing LED status.");
    Serial.println();
    stat = !stat;
    digitalWrite(led, stat);
    delay(500);
  }
  
  delay(1);
}
