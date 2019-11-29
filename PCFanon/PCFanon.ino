int PlusPin = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(PlusPin, OUTPUT); //set LEDPin to be an OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
 analogWrite(PlusPin, 255);
}
