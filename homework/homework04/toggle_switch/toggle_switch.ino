int ledPin = 13;
int buttonPin = 2;

boolean buttonStatus;
int oneTimeFlag;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
//  digitalWrite(buttonPin, HIGH);

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

  int sensorVal = digitalRead(buttonPin);
  Serial.println(sensorVal);

  if (digitalRead(buttonPin) == LOW)
  {
    if (oneTimeFlag == 0)
    {
      oneTimeFlag = 1;
      buttonStatus = !buttonStatus;
    }
  }
  else
  {
    oneTimeFlag = 0;
  }
  digitalWrite(ledPin, buttonStatus);

}
