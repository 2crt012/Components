/*  Author: PLACITECH. DIY and Funny videos!
 *   
 *  Tiktok: @placitech
 *  Instagram: @placitech_
 *  YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of Bend Sensors. In this example
 *  you will create a voltage divider placing a 2.2 KΩ resistor in series
 *  with the bend sensor. Since the resistance of the sensor varies depending
 *  on how much you bend it (the more pressure, the less resistance), you will
 *  use the serial monitor to check the change in voltage and turn on/off an LED
 *  depending on a certain threshold.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, but you
 *  can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/
#define read_pin A5
#define led 9

byte led_stat = 0;
int threshold = 750;

void setup() {
  Serial.begin(9600);
  pinMode(read_pin, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}



void loop() {
  // Read voltage level
  int reading = analogRead(read_pin);
  Serial.println(reading);

  // If voltage is greater than or equal to the threshold and LED is OFF, turn it ON
  if ((reading >= threshold) && (led_stat == 0)){
    Serial.println("LED On");
    digitalWrite(led, HIGH);
    led_stat = 1;
  }

  // If voltage is less than the threshold and LED is ON, turn it OFF
  else if ((reading < threshold) && (led_stat == 1)){
    Serial.println("LED Off");
    digitalWrite(led, LOW);
    led_stat = 0;
  }

  delay(100);
}
