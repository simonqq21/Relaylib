#include <Arduino.h>
#include "Relay.h"

Relay rl1(5);
String cmd; 

void setup() {
  Serial.begin(115200);
  rl1.begin();
}

void loop() {
  if (Serial.available()) {
    cmd = Serial.readStringUntil('\n');
    Serial.printf("cmd=%s", cmd);
    if (cmd == "1") {
      rl1.set(true);
    }
    else if (cmd == "2") {
      Serial.printf("rl1 state = %d\n", rl1.readState());
    }
    else {
      rl1.set(false);
    }
  }
}
