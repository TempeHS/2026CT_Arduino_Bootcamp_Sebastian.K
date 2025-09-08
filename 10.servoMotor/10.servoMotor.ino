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
unsigned static int redLED = 4;

Servo myservo; // create servo object to control a servo
Ultrasonic UltraSonicSensor(usPin);

int potpin = A1; // analog pin used to connect the potentiometer
int val; // variable to read the value from the analog pin

bool onSTATE = false;

// configure OLED screen
U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED(U8G2_R0, SCL, U8X8_PIN_NONE);

void setup() {
  myservo.attach(servoPin); // attaches the servo on pin 6 to the servo object
  Serial.begin(9600);
  Serial.println("baud = 9600");
  Serial.println("------------------");
  OLED.begin();
  pinMode(redLED, OUTPUT);
}

void loop() {
  
  unsigned long range_in_cm;
  range_in_cm = UltraSonicSensor.distanceRead();
  String distanceString = String(range_in_cm);
  //String servoString = String(range_in_cm);
  //set servo angle relative to ultrasonic sensor 1m = 180 3cm = 0.0000000000000
  OLED.setFont(u8g2_font_6x12_tf);
  OLED.clearDisplay();
  OLED.drawStr(0, 10, distanceString.c_str());
  //OLED.drawStr(0, 20, servoString.c_str());
  OLED.nextPage();

  int servoAngle = range_in_cm;
  map(servoAngle, 0, 1083, 0, 180);
  myservo.write(servoAngle);

  if (range_in_cm <= 50) {
    digitalWrite(redLED, !onSTATE);
  } else {
    digitalWrite(redLED, onSTATE);
  }

  Serial.print(range_in_cm);
  Serial.println(" cm");            
  
  delay(100);
}