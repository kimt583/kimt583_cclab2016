
#include <SoftwareSerial.h>
#include <JsonParser.h>
//#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>

#include "RGB.h"

using namespace ArduinoJson::Parser;


//#define SSID "Taeyonii" // insert SSID
//#define PASS "30743241" // insert password

//#define SSID "TG1672GA2"; // insert SSID
//#define PASS "TG1672G6F2DA2"; // insert password
//#define LOCATIONID "5128581"; // location id
//#define DST_IP "api.openweathermap.org"; //api.openweathermap.org

SoftwareSerial dbgSerial(2, 3); // RX, TX for debugging
JsonParser<32> parser;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 6,
                            NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                            NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
                            NEO_GRB            + NEO_KHZ800);


void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(10000);
  dbgSerial.begin(9600); // for debuging
  dbgSerial.println(F("Init"));
  Serial.println(F("AT+RST")); // restet and test if module is redy
  delay(1000);
  matrix.begin();
  matrix.setBrightness(30);
  matrix.setTextColor( matrix.Color(20, 100, 200) );
  matrix.setTextWrap(false);

  if (Serial.find("ready")) {
    dbgSerial.println(F("WiFi - Module is ready"));
    //    tone(7, NOTE_G7, 200);
    //    tone(7, NOTE_E7, 400);

  } else {
    dbgSerial.println(F("Module dosn't respond."));
    //    tone(7, NOTE_C8, 200);
    //    tone(7, NOTE_C8, 500);
    while (1);
  }
  delay(1000);
  // try to connect to wifi
  boolean connected = false;
  for (int i = 0; i < 5; i++) {
    if (connectWiFi()) {
      connected = true;
      dbgSerial.println(F("Connected to WiFi..."));
      //      tone(7, NOTE_C7, 100);
      //      delay(100);
      //      tone(7, NOTE_E7, 100);
      //      delay(100);
      //      tone(7, NOTE_G7, 200);
      delay(200);
      break;
    }
  }
  if (!connected) {
    dbgSerial.println(F("Couldn't connect to WiFi."));
    //    tone(7, NOTE_E7, 200);
    //    tone(7, NOTE_C7, 400);
    while (1);
  }
  delay(5000);
  Serial.println(F("AT+CIPMUX=0")); // set to single connection mode
  //  noTone(7);

  clearSky();
  fadeOut(120, 0);
    delay(800);
  fewClouds();
  fadeOut(120, 0);
    delay(800);
  brokenClouds();
  fadeOut(120, 0);
    delay(800);
  showerRain();
  fadeOut(120, 0);
    delay(800);


}
void loop()
{

  Serial.println(F("AT+CIPSTART=\"TCP\",\"api.openweathermap.org\",80"));
  if (Serial.find("Error")) return;

  Serial.println(F("AT+CIPSEND=115"));
  if (Serial.find(">")) {
    dbgSerial.print(">");
  } else {
    Serial.println(F("AT+CIPCLOSE"));
    dbgSerial.println(F("connection timeout"));;
    delay(1000);
    return;
  }
  Serial.print(F("GET /data/2.5/weather/?id=5128581&APPID=2b02e72204a6cc252f68a99b2ec9ef1d HTTP/1.1\r\nHost: api.openweathermap.org\r\n\r\n"));
  unsigned int i = 0; //timeout counter
  int n = 1; // char counter
  char json[100] = "{";
  while (!Serial.find("\"weather\":[{")) {} // find the part we are interested in.
  while (i < 60000) {
    if (Serial.available()) {
      char c = Serial.read();
      json[n] = c;
      if (c == '}') break;
      n++;
      i = 0;
    }
    i++;
  }

  //  dbgSerial.println(json);
  JsonObject root = parser.parse(json);
  char* main = root["main"];
  char* description = root["description"];
  char* icon = root["icon"];
  //  temp -= 273.15; // from kelvin to degree celsius
  int icon_num = atoi(icon);
  dbgSerial.println(main);
  dbgSerial.println(description);
  dbgSerial.println(icon_num);
  //  dbgSerial.println(F("===="));
  for (int i = 0; i < 6000; i++) {
    switch (icon_num) {
      case 1 :
        clearSky();
        break;
      case 2 :
        fewClouds();
        break;
      case 3 :
        brokenClouds();
        break;
      case 4 :
        brokenClouds();
        break;
      case 9 :
        showerRain();
        break;
      case 10 :
        showerRain();
        break;
      case 11 :
        thunderstorm();
        break;
        //      case 13 :
        //        snow();
        //        break;
    }
    fadeOut(120, 0);
    delay(800);
    scrollText(description);
  }

  matrix.show();
}


