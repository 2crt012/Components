/*   Author: PLACITECH. DIY and Funny videos!
 *   
 *   Tiktok: @placitech
 *   Instagram: @placitech_
 *   YouTube: PLACITECH
 *   
 *  Use this code to learn the bascis of Joystick modules! In this example
 *  you will print the position of the joystick on the Serial monitor by
 *  reading axis data as well as the switch button value.
 *  
 *  The microcontroller I used for this example is an Arduino Nano,
 *  but you can use any Micro that you have, like the Arduino UNO or MEGA.
*/

#define x_axis A3
#define y_axis A4
#define button 4

int x_val;
int y_val;
int b_val;


// Function used to get the axis readings
void get_readings(){
  x_val = analogRead(x_axis);
  y_val = analogRead(y_axis);
  b_val = digitalRead(button);
  delay(10);
}



void setup() {
  Serial.begin(9600);
  pinMode(x_axis, INPUT);
  pinMode(y_axis, INPUT);
  pinMode(button, INPUT_PULLUP);
}



void loop() {
  get_readings();

  // Show "Center" when button is pressed
  if (b_val == 0){
    Serial.println("Center");
    while (b_val == 0){
      get_readings();
    }
    Serial.println();
  }

  // If button is not pressed, show the current position of the joystick
  else if (x_val > 800){
    Serial.println("Up");
    while (x_val > 800){
      get_readings();
    }
    Serial.println();
  }

  else if (x_val < 100){
    Serial.println("Down");
    while (x_val < 100){
      get_readings();
    }
    Serial.println();
  }

  else if (y_val > 800){
    Serial.println("Right");
    while (y_val > 800){
      get_readings();
    }
    Serial.println();
  }

  else if (y_val < 100){
    Serial.println("Left");
    while (y_val < 100){
      get_readings();
    }
    Serial.println();
  }
}
