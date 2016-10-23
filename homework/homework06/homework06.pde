import processing.serial.*;

import cc.arduino.*;

Arduino arduino;

boolean led_status=false;

void setup() {
  size(512, 200);

  // Prints out the available serial ports.
  println(Arduino.list());

  arduino = new Arduino(this, "/dev/tty.usbmodem1421", 57600);
  for (int i = 0; i <= 13; i++)
    arduino.pinMode(i, Arduino.OUTPUT);
}

void draw() {
  background(constrain(mouseX / 2, 0, 255));
  int divider=0;
 
  if (mouseX>=0 && mouseX<=100)
    divider=8;
  if (mouseX>100 && mouseX<=200)
    divider=9;
  if (mouseX>200 && mouseX<=300)
    divider=10;
  if (mouseX>300 && mouseX<=400)
    divider=12;
  if (mouseX>400 && mouseX<=512)
    divider=13;



  if (led_status==false)
  {
    arduino.digitalWrite(divider, Arduino.HIGH);
    led_status=true;
  }
  if (led_status==true)
  {
    arduino.digitalWrite(divider, Arduino.LOW);
    led_status=false;
  }
}