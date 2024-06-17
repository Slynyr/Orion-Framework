#include "orionFramework.h"



OrionFramework::OrionFramework() : _isConnected(false), _maxAttempts(3) {}

void OrionFramework::initialize(String SSID, String PASSWORD, String API_ADDRESS) {
    Serial.println("[Orion] Connecting to WiFi network"); 

    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }
  
    _isConnected = true; 
    this->_apiAddress = API_ADDRESS;
    Serial.println("\nSuccessfully connected to " + SSID);
}

void OrionFramework::sendTrigger(String endpoint) {
    int attemptCount = 0;

    if (WiFi.status() == WL_CONNECTED) {
        String targetAddress = String("http://") + _apiAddress + "/" + endpoint;
        
        while (attemptCount < _maxAttempts){
            attemptCount++; 
            
            HTTPClient http; 
            http.begin(targetAddress);
            int httpResponse = http.GET();
            
            if (httpResponse > 0) {
                Serial.println("[Orion] Request sent successfully"); // TODO handle codes
                http.end();
                break; 
            } else {
                Serial.println("[Orion] Something went wrong while attempting to post request");
            }
            http.end();
        }
    } else {
        Serial.println("[Orion] Unable to send trigger. WiFi is not available");
    }
}

bool OrionFramework::isConnected() {
    return _isConnected;
}

void OrionFramework::setMaxAttempts(int maxAttempts) {
    this->_maxAttempts = maxAttempts;
}