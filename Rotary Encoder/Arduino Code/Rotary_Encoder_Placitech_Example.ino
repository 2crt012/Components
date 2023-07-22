/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of rotary encoders. In this
 *  example you'll use the Serial Monitor to check whether the encoder
 *  is being rotated Clockwise or Counterclockwise.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

// Pins
#define clk 4
#define dt 5

// Variables
byte clk_1;
byte dt_1;
byte clk_2;



void setup() {
  Serial.begin(9600);
  pinMode(clk, INPUT);
  pinMode(dt, INPUT);

  clk_1 = digitalRead(clk);
  dt_1 = digitalRead(dt);

  clk_2 = clk_1;
}



void loop() {
  // Wait for the encoder's output to change (means it's being rotated)
  while (clk_1 == clk_2){
    clk_1 = digitalRead(clk);
    dt_1 = digitalRead(dt);
    delay(1);
  }

  while(digitalRead(clk_1) != digitalRead(dt_1)){
    delay(1);
  }

  // If CLK is equal to DT as soon as it is rotated, it means
  // it's going Counterclockwise
  if (clk_1 == dt_1){
    Serial.println("CCW");
  }

  // If CLK is not equal to DT as soon as it is rotated, it means
  // it's going Clockwise
  else{
    Serial.println("CW");
  }

  Serial.println();
  clk_2 = clk_1;
}
