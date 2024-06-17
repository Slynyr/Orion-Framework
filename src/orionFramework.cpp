#include "orionFramework.h"

OrionFramework::OrionFramework() : _isConnected(false), _maxAttempts(3), _verbose(true) {}

void OrionFramework::initialize(String SSID, String PASSWORD, String API_ADDRESS) {
    logVerbose("[Orion] Connecting to WiFi network"); 

    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        if (_verbose) {
            Serial.print(".");
        }
        delay(100);
    }
  
    _isConnected = true; 
    this->_apiAddress = API_ADDRESS;
    logVerbose("\nSuccessfully connected to " + SSID);
}

void OrionFramework::sendTrigger(String endpoint) {
    int attemptCount = 0;

    if (WiFi.status() == WL_CONNECTED) {
        String targetAddress = String("http://") + _apiAddress + "/" + endpoint;
        logVerbose("[Orion] Sending request to: " + targetAddress);
        
        while (attemptCount < _maxAttempts){
            attemptCount++; 
            
            HTTPClient http; 
            http.begin(targetAddress);
            int httpResponse = http.GET();
            
            if (httpResponse > 0) {
                logVerbose("[Orion] Request sent successfully"); // TODO handle codes
                http.end();
                break; 
            } else {
                
                logVerbose("[Orion] Something went wrong while attempting to post request");
            }
            http.end();
        }
    } else {
        logVerbose("[Orion] Unable to send trigger. WiFi is not available");
    }
}

bool OrionFramework::isConnected() {
    return _isConnected;
}

void OrionFramework::setMaxAttempts(int maxAttempts) {
    this->_maxAttempts = maxAttempts;
}

void OrionFramework::logVerbose(String text) {
    if (_verbose){
        Serial.println(text);
    }
}

void OrionFramework::setVerbose(bool state) {
    _verbose = state; 
}