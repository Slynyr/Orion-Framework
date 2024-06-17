#include <Arduino.h>
#include "orionFramework.h"

OrionFramework orion; 

void setup() {
  orion.initialize("WIFI_SSID", "WIFI_PASSWORD", "10.0.2.68:4586"); 
  orion.setMaxAttempts(3); // The maximum amount of times a request is resent if unsuccessful 
  orion.setVerbose(true); // Set to false if you dont want serial printouts
}

void loop() {
  orion.sendTrigger("device/lamp1/toggle"); // Sending a request to https://10.0.2.68/device/lamp1/toggle
}