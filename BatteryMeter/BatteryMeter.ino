int potPin = A3;  //Declare potPin to be analog pin A0
int vOut = 2;
int measureOn = A0;

int toggle;
float readValue;
float writeValue; // Use this variable for writing to LED

void setup() {
  pinMode(potPin, INPUT);  //set potPin to be an input
  pinMode(vOut, OUTPUT);
  pinMode(measureOn, INPUT);
  
  digitalWrite(vOut, HIGH);
  Serial.begin(9600);      // turn on Serial Port
}
 
void loop() {
 toggle = analogRead(measureOn);
 if (toggle > 200){
  readValue = analogRead(potPin);  //Read the voltage on the Potentiometer
  writeValue = (readValue/1024*5);
  
  Serial.print("The voltage of this battery is: ");  //for debugging print your values
  Serial.println(writeValue);
  }
}
