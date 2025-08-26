/*
  Author:

  Learning Intention:
  The students will learn how to connect and control a servo motor.

  Success Criteria:
    1.  I understand how to connect the servo motor
    2.  I can manually write different degrees of movement to the servo
    3.  I can map a potentiometer to a servo and control its movement
    4.  I understand that a 180deg servo angle of movement is set by a
        frequency signal sent from the microcontroller

  Student Notes: 

  Documentation:
    https://www.sparkfun.com/servos
    https://github.com/arduino-libraries/Servo <-- We are still using this library

  Schematic:
    https://www.tinkercad.com/things/lQ9RyYJRoLn?sharecode=MKlN0A7R0WGodkdTRKkPJO7I8PeI5L_GCR7pCclQ0qM
    https://github.com/TempeHS/TempeHS_Ardunio_Bootcamp/blob/main/10.servoMotor/Bootcamp-servoMotor.png
*/

// Includes for the OLED screen
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

#include <Servo.h>
#include "Ultrasonic.h"

unsigned static int servoPin = 6;
unsigned static int usPin = 5;

Servo myservo; // create servo object to control a servo
Ultrasonic UltraSonicSensor(usPin);

int potpin = A1; // analog pin used to connect the potentiometer
int val; // variable to read the value from the analog pin

// configure OLED screen
U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED(U8G2_R0, SCL, U8X8_PIN_NONE);

void setup() {
  myservo.attach(servoPin); // attaches the servo on pin 6 to the servo object
  Serial.begin(9600);

  OLED.begin();
  OLED.setFont(u8g2_font_6x12_tf);
  
}

void loop() {

  unsigned long RangeInCentimeters;
  RangeInCentimeters = UltraSonicSensor.distanceRead(); // two measurements 
  Serial.print(RangeInCentimeters); // 0~400cm
  Serial.println(" cm");

  //val = analogRead(potpin);         // reads the value of the potentiometer
  val = map(RangeInCentimeters, 0, 700, 0, 300);  // scale it to use it with the servo (val)
  myservo.write(val);              // sets the servo postion according to 

  OLED.drawStr(0, 10, "------------------------ ");
  OLED.drawStr(0, 20, "------------------------");
  OLED.drawStr(0, 30, RangeInCentimeters);
  OLED.drawStr(0, 40, "------------------------");
  OLED.drawStr(0, 50, "------------------------");
  OLED.drawStr(0, 60, "------------------------");
  OLED.nextPage();
  delay(200);                    // waits for the servo to process and get there

}