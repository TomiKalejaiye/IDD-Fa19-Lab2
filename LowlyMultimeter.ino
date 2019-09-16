/*
 LowlyMultimeter

 Takes a voltage value at A0 and prints it to an LCD wired as seen in the wiring schematic
 in the README.md of this lab's folder.

 Created by Tomi Kalejaiye

 16 Sep. 2019
 
 */

#include <LiquidCrystal.h>

int sensorPin = A0;    // the input pin for the potentiometer.
float sensorValue = 0;  // variable to store the value read at the sensor pin.
float voltage = 0; //variable to store voltage calculated from sensor value.

//Creating the display object
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  //Initialize the display
  lcd.begin(16, 2);
}

void loop() {
  //start cursor at leftmost topmost cell
  lcd.setCursor(0, 0);
  //print the voltage
  lcd.print(getVoltage());
  //move cursor to one cell after the displayed number
  lcd.setCursor(5,0);
  //print V for volts
  lcd.print("V");
}

float getVoltage() {
  //read raw data from the sensor pin.
  sensorValue = analogRead(sensorPin);
  //convert raw sensor value to voltage and return it
  voltage = (sensorValue * 5) / 1024;
  return voltage;
}
