/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of solenoid. In this example
 *  you'll control the solenoid using an N-Channel MOSFET. To let
 *  current flow through the component, just press the button and
 *  the Arduino will close the circuit by sending a HIGH signal to the
 *  Gate of the transistor.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

const byte but = 5;
const byte sol = 2;



void setup() {
  Serial.begin(9600);
  pinMode(but, INPUT_PULLUP);
  pinMode(sol, OUTPUT);
  digitalWrite(sol, LOW);
}



void loop() {
  // Wait for button to be pressed
  while (digitalRead(but) == HIGH){
    delay(10);
  }

  // Let current flow
  digitalWrite(sol, HIGH):
  Serial.println("Solenoid ON");
  Serial.println();

  // Wait for button to be released
  while (digitalRead(but) == LOW){
    delay(10);
  }

  // Stop current flow
  digitalWrite(sol, LOW):
  Serial.println("Solenoid OFF");
  Serial.println();
}
