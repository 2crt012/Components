const int photoresistorPin = A0;   // Assigning the analog input pin A0 to a variable
int photoresistorValue = 0;        // Initializing the variable to store the photoresistor value

void setup() {
  Serial.begin(9600);             // Starting the serial communication at 9600 bits per second
}

void loop() {
  photoresistorValue = analogRead(photoresistorPin);   // Reading the analog value from the photoresistor pin
  Serial.print("Photoresistor value: ");              // Printing the value on the serial monitor
  Serial.println(photoresistorValue);
  delay(1000);                                        // Waiting for 1 second before repeating the loop
}
