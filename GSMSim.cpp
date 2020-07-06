#include "GSMSim.h"

GSMSim :: GSMSim(uint8_t rx, uint8_t tx) : SoftwareSerial(rx, tx) {
  _rx = rx;
  _tx = tx;
}

GSMSim :: GSMSim(uint8_t rx, uint8_t tx, uint8_t reset) : SoftwareSerial(rx, tx) {
  _rx = rx;
  _tx = tx;
  _reset = reset;
}

void GSMSim :: begin(uint32_t baud) {
  _baud = baud;
  this -> begin(baud);
}

bool GSMSim :: testDevice() {
  this -> print("AT\r");
  if (serialRead().indexOf("OK") == -1)
    return false;
  return true;
}
uint8_t GSMSim :: signalQuality();

bool GSMSim :: gprsConnectBearer(String apn, String user, String pwd);
bool GSMSim :: gprsCloseConnect();
bool GSMSim :: gprsIsConnect();

String GSMSim :: gprsGetIP();
String GSMSim :: gprsHTTPGet(String url, bool read = false);
String GSMSim :: providerName();
String GSMSim :: modulModel();
String GSMSim :: modulIEMI();

String GSMSim :: serialRead(uint32_t timeout = 1000) {
  uint32_t time = millis();
  String str = "";
  while (millis() < time + 1000);
  while (this -> available())
    if (this -> available())
      str += (char)this -> read();


  return str;
}
