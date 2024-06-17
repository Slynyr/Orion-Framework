#include <Arduino.h>
#include "orionFramework.h"

OrionFramework orion; 

void setup() {
  orion.initialize("MY_WIFI", "password123", "10.0.2.68"); 
  orion.setMaxAttempts(3); // The maximum amount of times a request is resent if unsuccessful 
  orion.setVerbose(true); // Set to false if you dont want serial printouts
}

void loop() {
  orion.sendTrigger("device/lamp1/toggle"); // Sending a request to https://10.0.2.68/device/lamp1/toggle
}