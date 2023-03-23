/*   Author: PLACITECH. DIY and Funny videos!
 *   
 *   Tiktok: @placitech
 *   Instagram: @placitech_
 *   YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of ultrasonic sensors. In this example
 *  you will determine the distance between the sensor and any object by 
 *  calculating the time it takes for a sound pulse to leave the sensor and
 *  come back. Then, the duration of the pulse will be multiplied by a factor
 *  that will convert it into distance.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, 
 *  but you can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/
int dist;
int dur;
const byte trig = 10; 
const byte echo = 9;


// Function used to get the distance between an object
// and the sensor
void get_dist(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  dur = pulseIn(echo, HIGH);
  dist = dur*0.034/2;
}



void setup(){
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}


void loop(){
  get_dist();
  Serial.println("Object is " + String(dist) + " cm away");
  delay(100);
}
