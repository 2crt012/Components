/*   Author: PLACITECH. DIY and Funny videos!
 *   
 *   Tiktok: @placitech
 *   Instagram: @placitech_
 *   YouTube: PLACITECH
 *   
 *  Use this code to learn the basics of Real-Time Clock modules. In this example
 *  you will set the Date and Time of the DS3231 and then read it on the Serial
 *  Monitor. Note that the code was designed so information is only written on the 
 *  chip when it loses power (the battery was removed or no battery had been inserted
 *  before.
 *  
 *  The microcontroller I used for this example is an Arduino Nano, 
 *  but you can use any Micro that you have, like the Arduino UNO or MEGA.
 *  
*/
// Make sure to have this library installed
#include "RTClib.h"


// Declare module
RTC_DS3231 rtc;


// Create lists containing the name of days and months
String week_day[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
String month_of_year[12] = {"January", "February", "March", "April", "May", "June", "July", "August", 
                            "September", "October", "November", "December"};



void setup () {
  Serial.begin(9600);
  
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  delay(100);

  // This line is only executed if the modules loses power. Else, the date and time
  // shown will be the ones that have passed since it was first programmed.
  if (rtc.lostPower()) {
    Serial.println("The battery of the RTC Module was removed. Setting date and time");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Set the RTC to the date and time this sketch was compiled
  }
}



void loop () {
  // Get current information
  DateTime now = rtc.now();

  // Store it in variables
  int month_ = now.month();
  int day_ = now.day();
  int year_ = now.year();

  String month_name = month_of_year[month_-1];
  String day_of_week = week_day[now.dayOfTheWeek()];

  int hour_= now.hour();
  int min_ = now.minute();
  int sec_ = now.second();

  // Print information on the serial monitor
  Serial.print("It's " + day_of_week + ", " + month_name + " " + String(day_) + ", " + String(year_));
  Serial.println(" (" + String(month_) + "/" + String(day_) + "/" + String(year_) + ")");
  Serial.println("The time is: " + String(hour_) + ":" + String(min_) + ":" + String(sec_));
  Serial.println();

  // Wait 2 seconds (You can change this delay to whatever you need it to be)
  delay(2000);
}
