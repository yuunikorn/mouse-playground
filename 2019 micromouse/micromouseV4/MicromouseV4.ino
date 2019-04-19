#include <bluefruit.h>
#include <Wire.h>


void setup() {
  // put your setup code here, to run once:
  BlinkSetup();
  GyroSetup();
  MotorSetup();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  BlinkCommand();
  TurnAngle(90 , 0);

  
  delay(5000);
}
