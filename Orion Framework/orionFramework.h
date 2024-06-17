#ifndef ORIONFRAMEWORK_H
#define ORIONFRAMEWORK_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

class OrionFramework {
public:
    OrionFramework();
    void initialize(String SSID, String PASSWORD, String API_ADDRESS);
    void sendTrigger(String endpoint);
    void setMaxAttempts(int maxAttempts);
    bool isConnected();
private:
    bool _isConnected;
    int _maxAttempts;
    String _apiAddress;
}
#endif