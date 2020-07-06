#ifndef GSMSim_h
#define GSMSim_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class GSMSim : public SoftwareSerial {
  public:
    GSMSim(uint8_t rx, uint8_t tx);
    GSMSim(uint8_t rx, uint8_t tx, uint8_t reset);
    
    void begin(uint32_t baud);
    void reset();

    uint8_t signalQuality();

    bool testDevice();
    bool gprsConnectBearer(String apn, String user, String pwd);
    bool gprsCloseConnect();
    bool gprsIsConnect();

    String gprsGetIP();
    String gprsHTTPGet(String url, bool read = false);
    String providerName();
    String modulModel();
    String modulIEMI();

    String serialRead(uint32_t timeout = 1000);

  private:
    uint8_t _rx, _tx, _reset;
    uint32_t _baud;
  
};
#endif
