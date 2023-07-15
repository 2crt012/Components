/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of water pumps. In this example
 *  you'll control the water pump using an N-Channel MOSFET. To start
 *  the water flow, just press the button and the Arduino will close
 *  the circuit and turn ON the pump by sending a HIGH signal to the
 *  Gate of the transistor.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/

const byte but = 5;
const byte pump = 2;



void setup() {
  Serial.begin(9600);
  pinMode(but, INPUT_PULLUP);
  pinMode(pump, OUTPUT);
  digitalWrite(pump, LOW);
}



void loop() {
  // Wait for button to be pressed
  while (digitalRead(but) == HIGH){
    delay(10);
  }

  // Turn ON the pump
  digitalWrite(pump, HIGH);
  Serial.println("Water Pump ON");
  Serial.println();

  // Wait for button to be released
  while (digitalRead(but) == LOW){
    delay(10);
  }

  // Turn OFF the pump
  digitalWrite(pump, LOW);
  Serial.println("Water Pump OFF");
  Serial.println();
}
