/*
  Author: 

  Learning Intention:
  The students will learn to break their code into reusable chunks called functions
  
  Success Criteria:
    1. I understand how a function is called
    2. I can break a simple program like LED blick into functions that I can be re-use
    3. I know the computation term 'abstraction.'
    4. I can create separate my functions into functions.ino files to make my code more manageable
    5. I can return values from a function and use the value in my code
    6. I can pass values into my functions to make them more secure
    7. I know the computation term encapsulation

  Student Notes:
    
  Documentation: 
    https://www.youtube.com/watch?v=mHa1mUd1Kmg

  Schematic:
      
*/
// Includes for the OLED screen
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

//include for sensors
#include "Arduino_SensorKit.h"

// configure OLED screen
U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED(U8G2_R0, SCL, U8X8_PIN_NONE);

static unsigned int buzzerPin = 5;

void setup() {
Serial.begin(9600);
Serial.println("baud = 9600");
Serial.println("------------------");
OLED.begin();
Pressure.begin();
}

void loop() {
  OLEDScreen();
  PressureSensor();
  delay(200);
}

