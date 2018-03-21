int ledPin = 13;   // LED connected to digital pin 13
int upPin = 7;     // pushbutton connected to digital pin 7
int downPin =6;

//ouputs
int upOut = 12;     // pushbutton connected to digital pin 7
int downOut =11;

int valup = 0;       // variable to store the read value
int valdown = 0;       // variable to store the read value




void setup()
{
  pinMode(ledPin, OUTPUT);      // sets the digital pin 13 as output

  pinMode(upOut, OUTPUT);        // sets the digital pin 7 as input
  pinMode(downOut, OUTPUT);        // sets the digital pin 7 as input
  
  pinMode(upPin, INPUT);        // sets the digital pin 7 as input
  digitalWrite(upPin,HIGH);
  
  pinMode(downPin, INPUT);        // sets the digital pin 7 as input
  digitalWrite(downPin,HIGH);

  Serial.begin(57600);


}

void loop()
{
  valup = !digitalRead(upPin);     // read the input pin
  digitalWrite(ledPin, valup);    // sets the LED to the button's value
  digitalWrite(upOut, valup);    // sets the LED to the button's value
  Serial.print(digitalRead(upOut));

  valdown = !digitalRead(downPin);     // read the input pin
  digitalWrite(ledPin, valdown);    // sets the LED to the button's value
  digitalWrite(downOut, valdown);    // sets the LED to the button's value
  Serial.print(digitalRead(downOut));
  Serial.println();
//  Serial.printf ("down gear= %d, up gear =%d\n", valup, valdown);
}
