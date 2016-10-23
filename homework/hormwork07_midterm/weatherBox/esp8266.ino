boolean connectWiFi()
{
  Serial.println(F("AT+CWMODE=1"));

  dbgSerial.println(F("AT+CWJAP=\"TG1672GA2\",\"TG1672G6F2DA2\""));
  Serial.println(F("AT+CWJAP=\"TG1672GA2\",\"TG1672G6F2DA2\""));
  delay(2000);
  if (Serial.find("OK")) {
    dbgSerial.println(F("OK, Connected to WiFi."));
    return true;
  } else {
    dbgSerial.println(F("Can not connect to the WiFi."));
    return false;
  }
}

