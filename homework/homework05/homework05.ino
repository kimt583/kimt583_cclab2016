#include "pitches.h"

#define echoPin 2 // Echo
#define trigPin 3 // Trigger
#define RPin 9
#define GPin 10
#define BPin 11
#define piezo 8

int melody[] = {
  NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5,
};

int maximumRange = 30; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

int sensorVal;

int sensorRed;
int sensorBlue;
int sensorGreen;

int sound;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);
}

void loop() {
  /* The following trigPin/echoPin cycle is used to determine the
    distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration / 58.2;


  if (distance >= maximumRange || distance <= minimumRange) {
    Serial.println("-1");
    tone(piezo, NOTE_E6 , 100);
    delay(100);
    tone(piezo, NOTE_C6 , 100);
    delay(500);
    noTone(piezo);
  }
  else {
    Serial.println(distance);

    sensorVal = distance;

    sensorRed = map(sensorVal, 0, maximumRange/2, 0, 255);
    sensorRed = constrain(sensorRed, 0, 255);
    analogWrite(RPin, sensorRed);

    sensorBlue = map(sensorVal, maximumRange/2, maximumRange, 255,0);
    sensorBlue = constrain(sensorBlue, 0, 255);
    analogWrite(BPin, sensorBlue);

    sensorGreen = map(sensorVal,0,maximumRange, 0, 255);
    sensorGreen = constrain(sensorGreen, 0, 255);
    analogWrite(GPin, sensorGreen);
    sound = map(sensorVal, 0, maximumRange, 0, 22);
    tone(piezo, melody[sound], 300);
    delay(200);
  }



  //Delay 50ms before next reading.
  delay(50);
}
