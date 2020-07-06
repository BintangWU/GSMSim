#include "GSMSim.h"
GSMSim gsm(8, 9);

void setup() {
  Serial.begin(9600);
  gsm.begin(57600);
}

void loop() {
  Serial.println(gsm.testDevice());
}
//void loop() {
//  gsm.print("AT\r");
//  if (readSerial().indexOf("OK") == -1)
//    Serial.println("EROR");
//  else
//    Serial.println("FINIS");
//}
//
//String readSerial() {
//  uint32_t time = millis();
//  String str = "";
//  while (millis() < time + 1000);
//    while (gsm.available())
//      if (gsm.available())
//        str += (char)gsm.read();
// 
//
//  return str;
//}
