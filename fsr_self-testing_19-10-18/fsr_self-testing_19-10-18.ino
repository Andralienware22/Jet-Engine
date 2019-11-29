//libraries
#include <Servo.h>

//constants
const int ledPin = 3;
const int sensorPin = A0;
const int servoPin = 5;

//variables
int f;
int e;
Servo servo1;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(servoPin);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  servo1.write(13.5);
}

void loop() {
  // put your main code here, to run repeatedly:
  f = analogRead(sensorPin);
  e = map(f, 0, 1023, 0, 255);
    float r;
    if(e >= 60){
      e = e - 60;
      r = ((e * .8153));
      Serial.println(e);
     // Serial.println(r);
      servo1.write(r);
      analogWrite(ledPin, r);
    }
    else {
      e = -(e - 60);
      r = ((e * .8153));
      Serial.println(e);
     // Serial.println(r);
      servo1.write(r);
      analogWrite(ledPin, r);
    }
    delay(16.66667);
  }
