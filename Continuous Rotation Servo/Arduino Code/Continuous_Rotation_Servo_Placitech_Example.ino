/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of continuous rotation servo motors.
 *  In this example you will rotate the motor by adjusting a potentiometers
 *  knob. When fully turned to Ground, the motor won't move, add when fully
 *  turned to 5V, the motor will go at max speed. You will also be able to 
 *  changed the direction of rotation by pressing a push button.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

#include <Servo.h>

// Declare servo motor
Servo servito;

// Pins we'll use to get the speed and direction, and control the motor
#define dir_pin 3
#define servo_pin 5
#define speed_control A5

// Variables
int spd = 0;
int old_spd = 100;
int dir = 1;


void setup() {
  Serial.begin(9600);
  
  pinMode(dir_pin, INPUT_PULLUP);
  pinMode(speed_control, INPUT);
  pinMode(servo_pin, OUTPUT);
  
  servito.attach(servo_pin);
  
  servito.write(spd);
}



void loop() {
  // If button is pressed, change direction
  if (digitalRead(dir_pin) == LOW){
    dir = -dir;
    while(digitalRead(dir_pin) == LOW){
      delay(10);
    }
    Serial.println("Direction changed");
  }

  // Get the potentiometer's voltage and map it to a value between 0 and 90
  int spd = analogRead(speed_control);
  spd = map(spd, 0, 1023, 0, 90);

  // If a change of speed or direction is detected, change the PWM signal to match
  // the changes 
  if (spd*dir != old_spd){
    // 0 means full speed CW, 90 means stopped and 180 means full speed CCW
    servito.write(90+(spd*dir)); // 
    Serial.println(spd*dir);
    old_spd = spd*dir;
  }

  // Wait 250 ms
  delay(250);
}
