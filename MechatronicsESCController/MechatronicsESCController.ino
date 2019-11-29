/*
      Arduino Brushless Motor Control
   by Dejan, https://howtomechatronics.com
*/

#include <Servo.h>
#include <LiquidCrystal.h>

Servo ESC;     // create servo object to control the ESC
LiquidCrystal lcd(10, 9, 3, 5, 6, 9);

int potIn = A0;  // value from the analog pin

  float potValue;
  float potStat;

    void setup() {
    // Attach the ESC on pin 9
    ESC.attach(11,1000,2000); // (pin, min pulse width, max pulse width in microseconds)
    Serial.begin(9600); 
    
    lcd.begin(16, 2);
    lcd.print("Fan %: ");
    }

    void loop() {
      potValue = analogRead(potIn);   // reads the value of the potentiometer (value between 0 and 1023)
      potStat = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
      ESC.write(potStat);    // Send the signal to the ESC

      int fanPrcnt = map(potStat, 0, 180, 0, 100);
      char fanBuffer[10];
      String fanStat = dtostrf(fanPrcnt, 0, 0, fanBuffer);
      Serial.println(fanStat);
      lcd.setCursor(7, 0);
      lcd.print(fanStat);
    }
