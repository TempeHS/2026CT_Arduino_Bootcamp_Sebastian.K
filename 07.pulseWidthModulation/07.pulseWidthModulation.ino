
/*
  Author: 

  Learning Intention:
  The students will learn what 'pulse width modulation' is and how to use it to write
  analogue data on a digital PIN.
  
  Success Criteria:
    1.  I understand what pulse width modulation is
    2.  I can identify the PWM PINS on the Arduino Uno
    3.  I can wire an RGB LED for PWM control in TINKERCAD
    5.  I can write PWM data to multiple pins and manually change the colour of the LED

  Student Notes: 

  Documentation: 
    https://www.w3schools.com/colors/colors_rgb.aspt
    https://github.com/TempeHS/TempeHS_Ardunio_Bootcamp/blob/main/07.pulseWidthModulation/Pulse-Width-Modulation.jpg
  Schematic:
    https://www.tinkercad.com/things/drNDsMxGMIY?sharecode=D6x4_xTTRl_zGs7B-XGqfbQhG_xgjj3TVS_c-GNTK-c
    https://github.com/TempeHS/TempeHS_Ardunio_Bootcamp/blob/main/07.pulseWidthModulation/Bootcamp-PWMOutput.png
*/
static unsigned int redLED = 6;
static unsigned int onboardLED = 13;
static unsigned int buttonPIN = 4;
static unsigned int potPIN = A1;

//Debounce parameters
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 100; //milliseconds
int lastButtonState = LOW;
int buttonState = LOW;
bool onSTATE = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial Monitor Configured to 9600 Baud Rate");
  Serial.println("--------------------------------------------");
  pinMode(onboardLED, OUTPUT);
  pinMode(buttonPIN, INPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  int read = digitalRead(buttonPIN);

  // check if button changed
  if (read != buttonState) {
    lastDebounceTime = millis();
  } 

  //if enough time has pat
  if ((millis() - buttonState) > debounceDelay) {
    // if button state has changed, update debounce state
    if (read != buttonState) {
    buttonState = read;
    
      //toggle on a HIGH transition (button press)
      if (buttonState == true) {
        onSTATE = !onSTATE;
      } 
    }
  }

  lastButtonState = read; // save for next loop
  digitalWrite(onboardLED, onSTATE);
  digitalWrite(redLED, onSTATE);
  delay(100); //small delay for stability
}