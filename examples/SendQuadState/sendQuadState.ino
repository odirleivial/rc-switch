#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  Serial.println("Ready...");
  mySwitch.enableTransmit(10);
  mySwitch.setProtocol(4);
}

void loop() {
  //down
  Serial.println("Down...");
  mySwitch.sendQuadState("0F0F0100QQ0F100F0101");
  mySwitch.sendQuadState("0F0F0100QQ0F100F0110");
  
  delay(5000);
  
  //stop
  Serial.println("Stop...");
  mySwitch.sendQuadState("0F0F0100QQ0F100FFFFF");
  
  delay(1000);
  
  //up
  Serial.println("Up...");
  mySwitch.sendQuadState("0F0F0100QQ0F100F0F0F");
  mySwitch.sendQuadState("0F0F0100QQ0F100F0F1Q");
  
  delay(5000);
  
  //stop
  Serial.println("Stop...");
  mySwitch.sendQuadState("0F0F0100QQ0F100FFFFF");
  
  delay(1000);
}