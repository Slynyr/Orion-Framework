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
    void setVerbose(bool state);
    bool isConnected();
private:
    bool _isConnected;
    bool _verbose; 
    int _maxAttempts;
    String _apiAddress;
    void logVerbose(String text);
};

#endif